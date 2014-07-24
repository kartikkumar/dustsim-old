/*    
 * Copyright (c) 2010-2014, Delft University of Technology
 * Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 * Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 * All rights reserved.
 * See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_MATHEMATICS_H
#define DUSTSIM_MATHEMATICS_H

#include <string>
 
#include <Tudat/Mathematics/NumericalIntegrators/rungeKuttaCoefficients.h>

namespace dustsim
{
namespace mathematics
{

//! Get Runge-Kutta integrator coefficient set.
/*!
 * Returns Runge-Kutta integrator coefficient set based on string-name provided as input. If the 
 * string-name provided cannot be located, a run-time error is thrown.
 * \param coefficientSet Runge-Kutta integrator coefficient set. Currently, the options available 
 *          are: DOPRI853, RKF78.
 * \return RungeKuttaCoefficients object with coefficient set loaded.
 */
tudat::numerical_integrators::RungeKuttaCoefficients getRungeKuttaCoefficients( 
    const std::string& coefficientSet );

} // namespace input_output
} // namespace dustsim

#endif // DUSTSIM_MATHEMATICS_H

/*
 *    Unit tests need to be added.
 */