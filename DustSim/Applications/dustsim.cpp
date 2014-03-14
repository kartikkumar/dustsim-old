/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include <boost/make_shared.hpp>

#include <TudatCore/Astrodynamics/BasicAstrodynamics/astrodynamicsFunctions.h>
#include <TudatCore/Astrodynamics/BasicAstrodynamics/orbitalElementConversions.h>
#include <TudatCore/Astrodynamics/BasicAstrodynamics/unitConversions.h>
#include <TudatCore/Mathematics/BasicMathematics/mathematicalConstants.h>

#include <Tudat/InputOutput/dictionaryTools.h>
#include <Tudat/InputOutput/fieldType.h>
#include <Tudat/InputOutput/separatedParser.h>
#include <Tudat/InputOutput/parsedDataVectorUtilities.h>
#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>
#include <Tudat/Mathematics/NumericalIntegrators/rungeKuttaCoefficients.h>

#include <Assist/Astrodynamics/unitConversions.h>
#include <Assist/InputOutput/basicInputOutput.h>

#include "DustSim/Astrodynamics/executeSimulation.h"
#include "DustSim/Database/caseData.h"
#include "DustSim/InputOutput/dictionaries.h"
#include "DustSim/Mathematics/basicMathematics.h"

//! Execute dust particle simulations.
int main( const int numberOfInputs, const char* inputArguments[ ] )
{
    ///////////////////////////////////////////////////////////////////////////

    // Declare using-statements.
    using std::cout;
    using std::endl;
    using std::scientific;
    using std::setprecision;
    using std::string;
    using std::stringstream;

    using boost::make_shared;

    using namespace tudat::basic_astrodynamics;
    using namespace tudat::basic_astrodynamics::orbital_element_conversions;
    using namespace tudat::basic_astrodynamics::unit_conversions;
    using namespace tudat::basic_mathematics;
    using namespace tudat::basic_mathematics::mathematical_constants;
    using namespace tudat::input_output;
    using namespace tudat::input_output::dictionary;
    using namespace tudat::input_output::field_types::general;
    using namespace tudat::input_output::parsed_data_vector_utilities;
    using namespace tudat::numerical_integrators;

    using namespace assist::astrodynamics;
    using namespace assist::input_output;

    using namespace dustsim::astrodynamics;
    using namespace dustsim::database;
    using namespace dustsim::input_output;    
    using namespace dustsim::mathematics;        

    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////

    // Set up input deck.

    // Check number of input parameters is correct (the numberOfInputs variable includes the
    // application itself, so one is subtracted from this number).
    checkNumberOfInputArguments( numberOfInputs - 1 );

    // Read and filter input stream.
    string filteredInput = readAndFilterInputFile( inputArguments[ 1 ] );

    // Declare a separated parser.
    SeparatedParser parser( string( ": " ), 2, parameterName, parameterValue );

    // Parse filtered data.
    const ParsedDataVectorPtr parsedData = parser.parse( filteredInput ); 

    cout << endl;
    cout << "****************************************************************************" << endl;
    cout << "Input parameters" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;

    // Extract input parameters.

    // Get dictionary of general parameters.
    const DictionaryPointer generalParametersDictionary = getGeneralParametersDictionary( );

    // Extract general parameters.
    const string caseName = extractParameterValue< string >(
                parsedData->begin( ), parsedData->end( ), 
                findEntry( generalParametersDictionary, "CASE" ) );
    cout << "Case                                                      " << caseName << endl;

    const double maximumSimulationPeriod = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( generalParametersDictionary, "MAXIMUMSIMULATIONPERIOD" ),
                TUDAT_NAN, &convertJulianYearsToSeconds );
    cout << "Maximum simulation period                                 " 
         << convertSecondsToJulianYears( maximumSimulationPeriod ) << " yrs" << endl;   

    // Check that all general parameters have been set.
    checkRequiredParameters( generalParametersDictionary );

    // Get dictionary of initial Keplerian elements.
    const DictionaryPointer keplerianElementsDictionary = getKeplerianElementsDictionary( );

    // Extract initial Keplerian elements.

    // Declare vector of initial Keplerian elements.
    Vector6d initialStateInKeplerianElements( 6 );
  
    initialStateInKeplerianElements( semiMajorAxisIndex ) = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( keplerianElementsDictionary, "INITIALSEMIMAJORAXIS" ), TUDAT_NAN,
                &convertKilometersToMeters< double > );
    cout << "Initial semi-major axis                                   "
         << convertMetersToKilometers( 
                initialStateInKeplerianElements( semiMajorAxisIndex ) ) << " km" << endl;         

    initialStateInKeplerianElements( eccentricityIndex ) = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( keplerianElementsDictionary, "INITIALECCENTRICITY" ) );
    cout << "Initial eccentricity                                      "
         << initialStateInKeplerianElements( eccentricityIndex ) << endl;         

    initialStateInKeplerianElements( inclinationIndex ) = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( keplerianElementsDictionary, "INITIALINCLINATION" ), TUDAT_NAN, 
                &convertDegreesToRadians< double > );
    cout << "Initial inclination                                       "
         << convertRadiansToDegrees( 
                initialStateInKeplerianElements( inclinationIndex ) ) << " deg" << endl;         

    initialStateInKeplerianElements( argumentOfPeriapsisIndex ) = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( keplerianElementsDictionary, "INITIALARGUMENTOFPERIAPSIS" ), TUDAT_NAN, 
                &convertDegreesToRadians< double > );
    cout << "Initial argument of periapsis                             "
         << convertRadiansToDegrees( initialStateInKeplerianElements( argumentOfPeriapsisIndex ) ) 
         << " deg" << endl;         

    initialStateInKeplerianElements( longitudeOfAscendingNodeIndex ) 
        = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( keplerianElementsDictionary, "INITIALLONGITUDEOFASCENDINGNODE" ), TUDAT_NAN, 
                &convertDegreesToRadians< double > );
    cout << "Initial longitude of ascending node                       "
         << convertRadiansToDegrees( 
                initialStateInKeplerianElements( longitudeOfAscendingNodeIndex ) ) 
         << " deg" << endl;            

    initialStateInKeplerianElements( trueAnomalyIndex ) = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( keplerianElementsDictionary, "INITIALTRUEANOMALY" ), TUDAT_NAN, 
                &convertDegreesToRadians< double > );
    cout << "Initial true anomaly                                      "
         << convertRadiansToDegrees( 
                initialStateInKeplerianElements( trueAnomalyIndex ) ) << " deg" << endl;     

    // Check that all initial Keplerian elements have been set.
    checkRequiredParameters( keplerianElementsDictionary );

    // Get dictionary of gravity force model parameters.
    const DictionaryPointer gravityForceModelDictionary = getGravityForceModelDictionary( );

    // Extract central gravitational parameter.
    const double centralBodyGravitationalParameter = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( gravityForceModelDictionary, "CENTRALBODYGRAVITATIONALPARAMETER" ) );
    cout << "Central body gravitational parameter                      " 
         << centralBodyGravitationalParameter << " m^3 s^-2" << endl;  

    // Check that all gravity force model parameters have been set.
    checkRequiredParameters( gravityForceModelDictionary );

    // Get dictionary of numerical integrator settings.
    const DictionaryPointer numericalIntegratorSettingsDictionary 
        = getNumericalIntegratorSettingsDictionary( );

    // Extract numerical integrator settings.
    const string numericalIntegratorType = extractParameterValue< string >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( numericalIntegratorSettingsDictionary, 
                           "NUMERICALINTEGRATORTYPE" ), "DOPRI853" );
    cout << "Numerical integrator type                                 "
         << numericalIntegratorType << endl;

    // Compute orbital period for nominal semi-major axis.
    const double initialOrbitalPeriod = computeKeplerOrbitalPeriod( 
        initialStateInKeplerianElements( semiMajorAxisIndex ), 
        centralBodyGravitationalParameter );         

    const double numericalIntegratorInitialStepSize = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( numericalIntegratorSettingsDictionary, "INITIALSTEPSIZE" ), 
                1.0e-3 * initialOrbitalPeriod );
    cout << "Initial step size                                         " 
         << numericalIntegratorInitialStepSize << " s" << endl;

    const double numericalIntegratorRelativeTolerance = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( numericalIntegratorSettingsDictionary, "RELATIVEERRORTOLERANCE" ), 
                1.0e-12 );
    cout << "Numerical integrator relative tolerance                   " 
         << numericalIntegratorRelativeTolerance << endl;

    // Compute absolute tolerance with margin and round off.
    const double absoluteTolerance 
        = initialStateInKeplerianElements( semiMajorAxisIndex ) * 1.0e-15;
    stringstream absoluteToleranceRoundedBuffer;
    absoluteToleranceRoundedBuffer << setprecision( 0 ) << scientific << absoluteTolerance;
    double absoluteToleranceRounded = TUDAT_NAN;
    absoluteToleranceRoundedBuffer >> absoluteToleranceRounded;

    const double numericalIntegratorAbsoluteTolerance = extractParameterValue< double >(
                parsedData->begin( ), parsedData->end( ),
                findEntry( numericalIntegratorSettingsDictionary, "ABSOLUTEERRORTOLERANCE" ), 
                absoluteToleranceRounded );
    cout << "Numerical integrator absolute tolerance                   " 
         << numericalIntegratorAbsoluteTolerance << endl;

    // Check that all numerical integrator have been set.
    checkRequiredParameters( numericalIntegratorSettingsDictionary );
    
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////

    // Compute derived parameters.

    cout << endl;
    cout << "****************************************************************************" << endl;
    cout << "Derived parameters" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;

    // Set coefficient set selected for numerical integrator.
    RungeKuttaCoefficients rungeKuttaCoefficients 
        = getRungeKuttaCoefficients( numericalIntegratorType );

    // Store data in case data structure.
    CaseDataPointer caseData = make_shared< CaseData >( 1, 
                                                        caseName, 
                                                        maximumSimulationPeriod,
                                                        initialStateInKeplerianElements,
                                                        centralBodyGravitationalParameter,
                                                        numericalIntegratorType );
        
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////

    cout << endl;
    cout << "****************************************************************************" << endl;
    cout << "Simulation" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;

    // Execute simulation.
    cout << "Starting simulation ... " << endl;
    cout << endl;

    // Call function to execute simulation.
    executeSimulation( caseData );

    ///////////////////////////////////////////////////////////////////////////

    // If program is successfully completed, return 0.
    return EXIT_SUCCESS;    
}