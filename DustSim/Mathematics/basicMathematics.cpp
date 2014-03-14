/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#include <iostream>
#include <stdexcept>

#include <boost/algorithm/string/predicate.hpp>

#include "DustSim/Mathematics/basicMathematics.h"

namespace dustsim
{
namespace mathematics
{

using namespace tudat::numerical_integrators;

tudat::numerical_integrators::RungeKuttaCoefficients getRungeKuttaCoefficients( 
    const std::string& coefficientSet )
{
   // Declare Runge-Kutta coefficients.
    RungeKuttaCoefficients rungeKuttaCoefficients;

    // Set output message.
    std::cout << "Runge-Kutta coefficient set                               ";

    if ( boost::iequals( coefficientSet, "DOPRI853" ) )
    {
        rungeKuttaCoefficients = RungeKuttaCoefficients::get(
                    RungeKuttaCoefficients::rungeKutta87DormandPrince );
        std::cout << "Dormand Prince 8(7)" << std::endl;
    }

    else if ( boost::iequals( coefficientSet, "RKF78" ) )
    {
        rungeKuttaCoefficients = RungeKuttaCoefficients::get(
                    RungeKuttaCoefficients::rungeKuttaFehlberg78 );
        std::cout << "Runge-Kutta-Fehlberg 7(8)" << std::endl;
    }

    else
    {
        throw std::runtime_error( "Invalid coefficient set specified for numerical integrator." );
    }

    return rungeKuttaCoefficients;    
}

} // namespace input_output
} // namespace dustsim

/*
 *    Unit tests need to be added.
 */