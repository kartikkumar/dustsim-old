/*    
 * Copyright (c) 2010-2014, Delft University of Technology
 * Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 * All rights reserved.
 * See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_SINGLE_PARTICLE_SIMULATOR_H
#define DUSTSIM_SINGLE_PARTICLE_SIMULATOR_H

#include <string>

#include <Tudat/InputOutput/parsedDataVectorUtilities.h>

namespace dustsim
{
namespace application_modes
{

//! Execute single particle simulator application mode.
/*!
 * Executes single particle simulator application mode.
 * \param parsedData Pointer to vector of data parsed from configuration file provided by user.
 */
void executeSingleParticleSimulator( 
    const tudat::input_output::parsed_data_vector_utilities::ParsedDataVectorPtr parsedData );

} // namespace application_modes
} // namespace dustsim

#endif // DUSTSIM_SINGLE_PARTICLE_SIMULATOR_H
