/*    
 * Copyright (c) 2010-2014, Delft University of Technology
 * Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 * Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 * All rights reserved.
 * See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_EXECUTESIMULATION_H
#define DUSTSIM_EXECUTESIMULATION_H

#include "Dustsim/InputOutput/caseData.h"
#include "Dustsim/InputOutput/outputData.h"

namespace dustsim
{
namespace astrodynamics
{

//! Execute a single dust particle simulation.
/*!
 * Executes a single dust particle simulation, using case data and input values provided to the
 * function.    
 * \param caseData Struct containing all case data to run dust particle simulation.
 * \return Struct containing all the output data retrieved from dust particle simulation.
 */
boost::shared_ptr< input_output::OutputData > executeSimulation( 
    const input_output::CaseDataPointer caseData );

} // namespace astrodynamics
} // namespace dustsim

#endif // DUSTSIM_EXECUTESIMULATION_H

/*
 *    The function contained in this file is basically the inner-loop of the simulator used for 
 *    single dust particle simulations and Monte Carlo simulations.
 *    Unit tests need to be added.
 */