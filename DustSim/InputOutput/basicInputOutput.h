/*    
 *    Copyright (c) 2010-2013, Delft University of Technology
 *    Copyright (c) 2010-2013, K. Kumar (me@kartikkumar.com)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_BASIC_INPUT_OUTPUT_H
#define DUSTSIM_BASIC_INPUT_OUTPUT_H

#include <string>

namespace dustsim
{
namespace input_output
{

//! Get root-path for DustSim application.
/*!
 * Returns root-path corresponding with root-directory of DustSim as a string with
 * trailing slash included.
 * \return DustSim root-path.
 */
static inline std::string getDustSimRootPath( )
{
#ifdef DUSTSIM_CUSTOM_ROOT_PATH
    return std::string( DUSTSIM_CUSTOM_ROOT_PATH );
#else
    // Declare file path string assigned to filePath.
    // __FILE__ only gives the absolute path in the header file!
    std::string filePath_( __FILE__ );

    // Strip filename from temporary string and return root-path string.
    return filePath_.substr( 0, filePath_.length( ) -
                                std::string( "InputOutput/basicInputOutput.h" ).length( ) );
#endif
}

} // namespace input_output
} // namespace dustsim

#endif // DUSTSIM_BASIC_INPUT_OUTPUT_H

/*
 *    Unit tests are needed for the getdustsimRootPath() and 
 *    getRungeKuttaCoefficients() functions.
 */
