/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */
 
#include <boost/assign/list_of.hpp>
#include <boost/make_shared.hpp>

#include "Dustsim/InputOutput/dictionaries.h"

namespace dustsim
{
namespace input_output
{

using namespace tudat::input_output::dictionary;
using boost::assign::list_of;
using boost::make_shared;

//! Get dictionary of general parameters.
DictionaryPointer getGeneralParametersDictionary( )
{
    // Create new dictionary.
    DictionaryPointer dictionary = make_shared< Dictionary >( );

    // Add parameters.
    addEntry( dictionary, "MODE",                                  1, 0 );  
    addEntry( dictionary, "CASE",                                  0, 0 );
    addEntry( dictionary, "MAXIMUMSIMULATIONPERIOD",               0, 0, list_of( "PMAX" ) );  
    addEntry( dictionary, "STARTEPOCH",                            0, 0, list_of( "TSTART" ) );
    addEntry( dictionary, "FILEOUTPUTDIRECTORY",                   0, 0, 
                list_of( "FILEOUTPUTDIR" ) );
    
    return dictionary;  
}

//! Get dictionary of initial Keplerian elements.
DictionaryPointer getKeplerianElementsDictionary( )
{
    // Create new dictionary.
    DictionaryPointer dictionary = make_shared< Dictionary >( );

    // Add parameters.
    addEntry( dictionary, "INITIALSEMIMAJORAXIS",                  1, 0, list_of( "SMA0" ) );
    addEntry( dictionary, "INITIALECCENTRICITY",                   1, 0, list_of( "ECC0" ) );
    addEntry( dictionary, "INITIALINCLINATION",                    1, 0, list_of( "INC0" ) );
    addEntry( dictionary, "INITIALARGUMENTOFPERIAPSIS",            1, 0, list_of( "AOP0" ) );
    addEntry( dictionary, "INITIALLONGITUDEOFASCENDINGNODE",       1, 0, list_of( "LAN0" ) );
    addEntry( dictionary, "INITIALTRUEANOMALY",                    1, 0, list_of( "TAN0" ) );

    return dictionary;  
}

//! Get dictionary of gravity force model parameters.
DictionaryPointer getGravityForceModelDictionary( )
{
    // Create new dictionary.
    DictionaryPointer dictionary = make_shared< Dictionary >( );

    // Add parameters.
    addEntry( dictionary, "CENTRALBODYGRAVITATIONALPARAMETER",     1, 0, list_of( "GRAVPARAM" ) );

    return dictionary;  
}


//! Get dictionary of numerical integrator settings.
DictionaryPointer getNumericalIntegratorSettingsDictionary( )
{
    // Create new dictionary.
    DictionaryPointer dictionary = make_shared< Dictionary >( );

    // Add parameters.
    addEntry( dictionary, "NUMERICALINTEGRATORTYPE",               0, 0, list_of( "INTEGRATOR" ) );
    addEntry( dictionary, "INITIALSTEPSIZE",                       0, 0, list_of( "STEPSIZE0" ) );
    addEntry( dictionary, "MINIMUMSTEPSIZE",                       0, 0, 
                list_of( "STEPSIZEMIN" ) );
    addEntry( dictionary, "MAXIMUMSTEPSIZE",                       0, 0, 
                list_of( "STEPSIZEMIN" ) );
    addEntry( dictionary, "RELATIVEERRORTOLERANCE",                0, 0, list_of( "RELTOL" ) );
    addEntry( dictionary, "ABSOLUTEERRORTOLERANCE",                0, 0, list_of( "ABSTOL" ) );

    return dictionary;
}


    // // Add optional parameters.
    // addEntry( dictionary, "NUMBEROFTHREADS",                       0, 0, list_of( "THREADS" ) );
    // addEntry( dictionary, "FILEOUTPUTDIRECTORY",                   0, 0, 
    //             list_of( "FILEOUTPUTDIR" ) );
    // addEntry( dictionary, "OUTPUTINTERVAL",                        0, 0, list_of( "TOUTPUT" ) ); 
    // addEntry( dictionary, "CENTRALBODYEQUATORIALRADIUS",           1, 0, list_of( "RCENTRAL" ) ); 


    // addEntry( dictionary, "CASE",                                  1, 0 );
    // addEntry( dictionary, "DATABASE",                              1, 0, list_of( "DB" ) );

    // // // Add optional parameters.
    // addEntry( dictionary, "NUMBEROFTHREADS",                       0, 0, list_of( "THREADS" ) );
    // addEntry( dictionary, "OUTPUTMODE",                            0, 0, list_of( "OUTPUT" ) );
    // addEntry( dictionary, "FILEOUTPUTDIRECTORY",                   0, 0, 
    //             list_of( "FILEOUTPUTDIR" ) );
    // addEntry( dictionary, "OUTPUTINTERVAL",                        0, 0, list_of( "TOUTPUT" ) );  
    // addEntry( dictionary, "SIMULATIONSTOEXECUTE",                  0, 0, 
    //             list_of( "SIMULATIONS" ) );
    
    // addEntry( dictionary, "TESTPARTICLECASETABLENAME",             0, 0 );
    // addEntry( dictionary, "TESTPARTICLEINPUTTABLENAME",            0, 0 );
    // addEntry( dictionary, "TESTPARTICLEKICKTABLENAME",             0, 0 );
    // addEntry( dictionary, "RANDOMWALKSIMULATIONPERIOD",            0, 0 ); 
    // addEntry( dictionary, "PERTURBEDBODYRADIUS",                   0, 0, list_of( "RPERTURBED") );
    // addEntry( dictionary, "PERTURBEDBODYBULKDENSITY",              0, 0, 
    //             list_of( "RHOPERTURBED" ) );
    // addEntry( dictionary, "PERTURBEDBODYSEMIMAJORAXISATT0",        0, 0, list_of( "SMA0" ) );
    // addEntry( dictionary, "PERTURBEDBODYECCENTRICITYATT0",         0, 0, list_of( "ECC0" ) );
    // addEntry( dictionary, "PERTURBEDBODYINCLINATIONATT0",          0, 0, list_of( "INC0" ) );
    // addEntry( dictionary, "PERTURBEDBODYARGUMENTOFPERIAPSISATT0",  0, 0, list_of( "AOP0" ) );
    // addEntry( dictionary, "PERTURBEDBODYLONGITUDEOFASCENDINGNODEATT0",
    //             0, 0, list_of( "LAN0" ) );
    // addEntry( dictionary, "PERTURBEDBODYTRUEANOMALYATT0",          0, 0, list_of( "TRAN0" ) ); 
    // addEntry( dictionary, "SYNODICPERIODMAXIMUM",                  0, 0, 
    //             list_of( "TSYNODICMAX" ) );
    // addEntry( dictionary, "STARTUPINTEGRATIONPERIOD",              0, 0, list_of( "TSTARTUP" ) );
    // addEntry( dictionary, "CENTRALBODYJ2GRAVITYCOEFFICIENT",       0, 0, list_of( "J2" ) );
    // addEntry( dictionary, "CONJUNCTIONEVENTDETECTIONDISTANCE",     0, 0, 
    //             list_of( "DCONJUNCTION") );
    // addEntry( dictionary, "OPPOSITIONEVENTDETECTIONDISTANCE",      0, 0,
    //             list_of( "DOPPOSITION") );


//     return dictionary;
// }

//! Get dictionary for dust particle database generator application.
DictionaryPointer getDatabaseGeneratorDictionary( )
{
    DictionaryPointer dictionary = make_shared< Dictionary >( );

    // Add required parameters.
    addEntry( dictionary, "DATABASEPATH",                          1, 0, 
                list_of( "DATABASE" )( "DB" ) );    
    addEntry( dictionary, "CASE",                                  1, 0 );
    addEntry( dictionary, "NUMBEROFSIMULATIONS",                   1, 0, list_of( "POPULATION" ) );
    addEntry( dictionary, "MAXIMUMSIMULATIONPERIOD",               1, 0, list_of( "TMAX" ) );
    addEntry( dictionary, "CENTRALBODYGRAVITATIONALPARAMETER",     1, 0, list_of( "GRAVPARAM" ) );
    addEntry( dictionary, "CENTRALBODYEQUATORIALRADIUS",           1, 0, list_of( "RCENTRAL" ) );
    addEntry( dictionary, "SEMIMAJORAXISNOMINAL",                  1, 0, list_of( "SMANOMINAL" ) );
    addEntry( dictionary, "SEMIMAJORAXISDISTRIBUTIONLIMIT",        1, 0, list_of( "SMALIMIT" ) );

    // Add optional parameters.
    addEntry( dictionary, "ECCENTRICITYDISTRIBUTIONMEAN",          0, 0, list_of( "ECCMEAN" ) );
    addEntry( dictionary, "ECCENTRICITYDISTRIBUTIONFULLWIDTHHALFMAXIMUM", 
                0, 0, list_of( "ECCFWHM" ) );
    addEntry( dictionary, "INCLINATIONDISTRIBUTIONMEAN",           0, 0, list_of( "INCMEAN" ) );
    addEntry( dictionary, "INCLINATIONDISTRIBUTIONFULLWIDTHHALFMAXIMUM",                       
                0, 0, list_of( "INCFWHM" ) );
    addEntry( dictionary, "NUMERICALINTEGRATORTYPE",               0, 0, list_of( "INTEGRATOR" ) );    
    addEntry( dictionary, "CASETABLENAME",                         0, 0, list_of( "CASETABLE" ) );  
    addEntry( dictionary, "INPUTTABLENAME",                        0, 0, list_of( "INPUTTABLE" ) );
    addEntry( dictionary, "OUTPUTTABLENAME",                       0, 0, list_of( "OUTPUTTABLE" ) );      
    addEntry( dictionary, "INITIALSTEPSIZE",                       0, 0, list_of( "STEPSIZE0" ) );
    addEntry( dictionary, "RELATIVEERRORTOLERANCE",                0, 0, list_of( "RELTOL" ) );
    addEntry( dictionary, "ABSOLUTEERRORTOLERANCE",                0, 0, list_of( "ABSTOL" ) );

    // addEntry( dictionary, "SYNODICPERIODMAXIMUM",                  0, 0, 
    //     list_of( "TSYNODICMAX" ) );
    // addEntry( dictionary, "STARTUPINTEGRATIONPERIOD",              0, 0, list_of( "TSTARTUP" ) );
    // addEntry( dictionary, "CENTRALBODYJ2GRAVITYCOEFFICIENT",       0, 0, list_of( "J2" ) );
    // addEntry( dictionary, "CENTRALBODYEQUATORIALRADIUS",           0, 0, list_of( "RCENTRAL" ) );
    // addEntry( dictionary, "CONJUNCTIONEVENTDETECTIONDISTANCE",     0, 0, 
    //             list_of( "DCONJUNCTION ") );
    // addEntry( dictionary, "OPPOSITIONEVENTDETECTIONDISTANCE",      0, 0,
    //             list_of( "DOPPOSITION ") );

    return dictionary;
}

//! Get dictionary for dust particle Monte Carlo simulator application.
DictionaryPointer getMonteCarloSimulatorDictionary( )
{
    // Retrieve dictionary for test particle simulator.
    DictionaryPointer dictionary = make_shared< Dictionary >( );

    // Add required parameters.
    addEntry( dictionary, "CASE",                                  1, 0 );
    addEntry( dictionary, "DATABASE",                              1, 0, list_of( "DB" ) );

    // // Add optional parameters.
    addEntry( dictionary, "NUMBEROFTHREADS",                       0, 0, list_of( "THREADS" ) );
    addEntry( dictionary, "OUTPUTMODE",                            0, 0, list_of( "OUTPUT" ) );
    addEntry( dictionary, "FILEOUTPUTDIRECTORY",                   0, 0, 
                list_of( "FILEOUTPUTDIR" ) );
    addEntry( dictionary, "OUTPUTINTERVAL",                        0, 0, list_of( "TOUTPUT" ) );  
    addEntry( dictionary, "SIMULATIONSTOEXECUTE",                  0, 0, 
                list_of( "SIMULATIONS" ) );
    
    // addEntry( dictionary, "TESTPARTICLECASETABLENAME",             0, 0 );
    // addEntry( dictionary, "TESTPARTICLEINPUTTABLENAME",            0, 0 );
    // addEntry( dictionary, "TESTPARTICLEKICKTABLENAME",             0, 0 );
    // addEntry( dictionary, "RANDOMWALKSIMULATIONPERIOD",            0, 0 ); 
    // addEntry( dictionary, "CENTRALBODYGRAVITATIONALPARAMETER",     0, 0, list_of( "GRAVPARAM" ) );
    // addEntry( dictionary, "PERTURBEDBODYRADIUS",                   0, 0, list_of( "RPERTURBED") );
    // addEntry( dictionary, "PERTURBEDBODYBULKDENSITY",              0, 0, 
    //             list_of( "RHOPERTURBED" ) );
    // addEntry( dictionary, "PERTURBEDBODYSEMIMAJORAXISATT0",        0, 0, list_of( "SMA0" ) );
    // addEntry( dictionary, "PERTURBEDBODYECCENTRICITYATT0",         0, 0, list_of( "ECC0" ) );
    // addEntry( dictionary, "PERTURBEDBODYINCLINATIONATT0",          0, 0, list_of( "INC0" ) );
    // addEntry( dictionary, "PERTURBEDBODYARGUMENTOFPERIAPSISATT0",  0, 0, list_of( "AOP0" ) );
    // addEntry( dictionary, "PERTURBEDBODYLONGITUDEOFASCENDINGNODEATT0",
    //             0, 0, list_of( "LAN0" ) );
    // addEntry( dictionary, "PERTURBEDBODYTRUEANOMALYATT0",          0, 0, list_of( "TRAN0" ) ); 
    // addEntry( dictionary, "SYNODICPERIODMAXIMUM",                  0, 0, 
    //             list_of( "TSYNODICMAX" ) );
    // addEntry( dictionary, "STARTUPINTEGRATIONPERIOD",              0, 0, list_of( "TSTARTUP" ) );
    // addEntry( dictionary, "CENTRALBODYJ2GRAVITYCOEFFICIENT",       0, 0, list_of( "J2" ) );
    // addEntry( dictionary, "CENTRALBODYEQUATORIALRADIUS",           0, 0, list_of( "RCENTRAL" ) );
    // addEntry( dictionary, "CONJUNCTIONEVENTDETECTIONDISTANCE",     0, 0, 
    //             list_of( "DCONJUNCTION") );
    // addEntry( dictionary, "OPPOSITIONEVENTDETECTIONDISTANCE",      0, 0,
    //             list_of( "DOPPOSITION") );
    // addEntry( dictionary, "NUMERICALINTEGRATORTYPE",               0, 0, list_of( "INTEGRATOR" ) );
    // addEntry( dictionary, "INITIALSTEPSIZE",                       0, 0, list_of( "STEPSIZE0" ) );
    // addEntry( dictionary, "RUNGEKUTTARELATIVEERRORTOLERANCE",      0, 0, list_of( "RELTOL" ) );
    // addEntry( dictionary, "RUNGEKUTTAABSOLUTEERRORTOLERANCE",      0, 0, list_of( "ABSTOL" ) );

    return dictionary;
}

} // namespace input_output
} // namespace dustsim
