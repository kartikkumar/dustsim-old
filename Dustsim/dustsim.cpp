/*    
 * Copyright (c) 2010-2014, Delft University of Technology
 * Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 * See http://bit.ly/12SHPLR for license details.
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

#include <boost/algorithm/string/predicate.hpp>
#include <boost/timer/timer.hpp>

#include <Assist/InputOutput/basicInputOutput.h>

#include <Tudat/InputOutput/dictionaryTools.h>
#include <Tudat/InputOutput/fieldType.h>
#include <Tudat/InputOutput/separatedParser.h>
#include <Tudat/InputOutput/parsedDataVectorUtilities.h>

#include "Dustsim/ApplicationModes/singleParticleSimulator.h"
#include "Dustsim/InputOutput/dictionaries.h"

//! Execute Dustsim.
int main( const int numberOfInputs, const char* inputArguments[ ] )
{
    ///////////////////////////////////////////////////////////////////////////

    // Start timer. Timer automatically ends when this object goes out of scope.
    boost::timer::auto_cpu_timer timer;

    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////

    // Declare using-statements.

    using std::cout;
    using std::endl;
    using std::runtime_error;
    using std::string;

    using boost::iequals;

    using namespace assist::input_output;

    using namespace tudat::input_output;
    using namespace tudat::input_output::dictionary;
    using namespace tudat::input_output::field_types::general;
    using namespace tudat::input_output::parsed_data_vector_utilities;

    using namespace dustsim::application_modes;
    using namespace dustsim::input_output;

    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////

    // Set up input deck.

    // Check number of input parameters is correct (the numberOfInputs variable includes the
    // application itself, so one is subtracted from this number).
    checkNumberOfInputArguments( numberOfInputs - 1 );

    // Read and filter input stream (this can't be declared const because the parser's parse
    // function is not const-correct at the moment).
    string filteredInput = readAndFilterInputFile( inputArguments[ 1 ] );

    // Declare a separated parser.
    SeparatedParser parser( string( ": " ), 2, parameterName, parameterValue );

    // Parse filtered data.
    const ParsedDataVectorPtr parsedData = parser.parse( filteredInput );

    // Get general parameters dictionary.
    DictionaryPointer dictionary = getGeneralParametersDictionary( );

    // Extract application mode.
    const string applicationMode = extractParameterValue< string >(
                parsedData->begin( ), parsedData->end( ), findEntry( dictionary, "MODE" ) );

    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////

    // Call selected application mode.
    cout << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "                                   DUSTSIM                                  " << endl;
    cout << "                                    2.0.0                                   " << endl;
    cout << endl;
    cout << "          Copyright (c) 2010-2014, Delft University of Technology           " << endl;
    cout << "           Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)           " << endl;
    cout << "         Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)         " << endl;
    cout << endl;
    cout << "                 https://www.github.com/kartikkumar/dustsim                 " << endl;
    cout << endl;    
    cout << "----------------------------------------------------------------------------" << endl;

    cout << endl;
    cout << "****************************************************************************" << endl;
    cout << "Input parameters" << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;

    cout << "Application mode:          ";

    if ( iequals( applicationMode, "SPS" ) )
    {
        cout << "SINGLE PARTICLE SIMULATOR" << endl;
        executeSingleParticleSimulator( parsedData );
    }    

    else if ( iequals( applicationMode, "BPS" ) )
    {
        cout << "BULK PARTICLE SIMULATOR" << endl;
        // executeBulkParticleSimulator( parsedData );
    } 

    else if ( iequals( applicationMode, "BPDG" ) )
    {
        cout << "BULK PARTICLE DATABASE GENERATOR" << endl;
        // executeBulkParticleDatabaseGenerator( parsedData );        
    }    

    else
    {
        throw runtime_error( "ERROR: Application mode not recognized!" );             
    }    

    cout << endl;
    cout << "****************************************************************************" << endl;
    cout << endl;

    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////

    // Print timing information.
    cout << "Timing information: ";

    // If program is successfully completed, return 0.
    return EXIT_SUCCESS;

    ///////////////////////////////////////////////////////////////////////////
}
