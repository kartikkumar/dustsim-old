/*    
 * Copyright (c) 2010-2014, Delft University of Technology
 * Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 * See http://bit.ly/12SHPLR for license details.
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include <boost/algorithm/string/predicate.hpp>

#include <Assist/InputOutput/basicInputOutput.h>

#include <Tudat/InputOutput/dictionaryTools.h>
#include <Tudat/InputOutput/fieldType.h>
#include <Tudat/InputOutput/separatedParser.h>
#include <Tudat/InputOutput/parsedDataVectorUtilities.h>

// #include "Dustsim/ApplicationModes/randomWalkDatabaseGenerator.h"
// #include "Dustsim/ApplicationModes/randomWalkSimulator.h" 
// #include "Dustsim/ApplicationModes/testParticleDatabaseGenerator.h"
// #include "Dustsim/ApplicationModes/testParticleSimulator.h"
// #include "Dustsim/InputOutput/dictionaries.h"

//! Execute Dustsim.
int main( const int numberOfInputs, const char* inputArguments[ ] )
{
    // ///////////////////////////////////////////////////////////////////////////

    // // Declare using-statements.
    // using std::cout;
    // using std::endl;
    // using std::string;

    // using boost::iequals;

    // using namespace assist::input_output;

    // using namespace tudat::input_output;
    // using namespace tudat::input_output::dictionary;
    // using namespace tudat::input_output::field_types::general;
    // using namespace tudat::input_output::parsed_data_vector_utilities;

    // using namespace dustsim::application_modes;
    // using namespace dustsim::input_output;

    // ///////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////

    // // Set up input deck.

    // // Check number of input parameters is correct (the numberOfInputs variable includes the
    // // application itself, so one is subtracted from this number).
    // checkNumberOfInputArguments( numberOfInputs - 1 );

    // // Read and filter input stream (this can't be declared const because the parser's parse
    // // function is not const-correct at the moment).
    // string filteredInput = readAndFilterInputFile( inputArguments[ 1 ] );

    // // Declare a separated parser.
    // SeparatedParser parser( string( ": " ), 2, parameterName, parameterValue );

    // // Parse filtered data.
    // const ParsedDataVectorPtr parsedData = parser.parse( filteredInput );

    // // Get general parameters dictionary.
    // DictionaryPointer dictionary = getGeneralParametersDictionary( );

    // // Extract application mode.
    // const string applicationMode = extractParameterValue< string >(
    //             parsedData->begin( ), parsedData->end( ), findEntry( dictionary, "MODE" ) );

    // const string databasePath = extractParameterValue< string >(
    //             parsedData->begin( ), parsedData->end( ), 
    //             findEntry( dictionary, "DATABASEPATH" ) );

    // ///////////////////////////////////////////////////////////////////////////

    // ///////////////////////////////////////////////////////////////////////////

    // // Call selected application mode.
    // cout << endl;
    // cout << "Application mode                                          ";

    // if ( iequals( applicationMode, "TPDB" ) )
    // {
    //     cout << "TEST PARTICLE DATABASE GENERATOR" << endl;
    //     executeTestParticleDatabaseGenerator( databasePath, parsedData );
    // }    

    // else if ( iequals( applicationMode, "TPSIM" ) )
    // {
    //     cout << "TEST PARTICLE SIMULATOR" << endl;
    //     executeTestParticleSimulator( databasePath, parsedData );             
    // } 

    // else if ( iequals( applicationMode, "RWDB" ) )
    // {
    //     cout << "RANDOM WALK DATABASE GENERATOR" << endl;
    //     executeRandomWalkDatabaseGenerator( databasePath, parsedData );        
    // }    

    // else if ( iequals( applicationMode, "RWSIM" ) )
    // {
    //     cout << "RANDOM WALK SIMULATOR" << endl;
    //     executeRandomWalkSimulator( databasePath, parsedData );             
    // }    

    // cout << endl;

    // ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////

    // If program is successfully completed, return 0.
    return EXIT_SUCCESS;

    ///////////////////////////////////////////////////////////////////////////
}
