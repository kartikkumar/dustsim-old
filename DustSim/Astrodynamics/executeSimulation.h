/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_EXECUTESIMULATION_H
#define DUSTSIM_EXECUTESIMULATION_H

#include <limits>
#include <utility>

#include <boost/assign/list_of.hpp>
#include <boost/bind.hpp>
#include <boost/make_shared.hpp>

#include <TudatCore/Astrodynamics/BasicAstrodynamics/orbitalElementConversions.h>

#include <Tudat/Astrodynamics/BasicAstrodynamics/accelerationModel.h>
#include <Tudat/Astrodynamics/Gravitation/centralGravityModel.h>
#include <Tudat/Astrodynamics/StateDerivativeModels/cartesianStateDerivativeModel.h>
#include <Tudat/Astrodynamics/StateDerivativeModels/compositeStateDerivativeModel.h>
#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>
#include <Tudat/Mathematics/NumericalIntegrators/rungeKuttaCoefficients.h>
#include <Tudat/Mathematics/NumericalIntegrators/rungeKuttaVariableStepSizeIntegrator.h>

#include <Assist/Astrodynamics/body.h>

#include "DustSim/Database/caseData.h"
#include "DustSim/Mathematics/basicMathematics.h"

namespace dustsim
{
namespace astrodynamics
{

//! Execute a single dust particle simulation.
/*!
 * Executes a single dust particle simulation, using case data and input values provided to the
 * function.    
 */
void executeSimulation( const database::CaseDataPointer caseData )
{
    ///////////////////////////////////////////////////////////////////////////

    // Set using statements.
    using std::make_pair;
    
    using boost::assign::list_of;
    using boost::bind;
    using boost::make_shared;
    
    using namespace tudat::basic_astrodynamics;
    using namespace tudat::basic_astrodynamics::orbital_element_conversions;
    using namespace tudat::basic_mathematics;
    using namespace tudat::gravitation;
    using namespace tudat::numerical_integrators;
    using namespace tudat::state_derivative_models;    

    using namespace assist::astrodynamics;

    using namespace dustsim::mathematics;

    ///////////////////////////////////////////////////////////////////////////

    // Create dust particle.

    // Convert test particle initial state in Keplerian elements to Cartesian elements.
    const Vector6d dustParticleInitialState
            = convertKeplerianToCartesianElements(
                caseData->initialStateInKeplerianElements,
                caseData->centralBodyGravitationalParameter );

    // Create dust particle.
    BodyPointer dustParticle = make_shared< Body >(
                "Dust particle", dustParticleInitialState );

    ///////////////////////////////////////////////////////////////////////////
 

    ///////////////////////////////////////////////////////////////////////////

    // Set up dynamics.

    // Set acceleration models for dust particle.
    AccelerationModel3dPointer centralBodyGravity
            = make_shared< CentralGravitationalAccelerationModel3d >(
                bind( &Body::getCurrentPosition, dustParticle ),
                caseData->centralBodyGravitationalParameter );

    // Create lists of acceleration models to provide to state derivative models.
    CartesianStateDerivativeModel6d::AccelerationModelPointerVector accelerationList 
        = list_of( centralBodyGravity );

    CartesianStateDerivativeModel6dPointer stateDerivative
            = make_shared< CartesianStateDerivativeModel6d >(
                accelerationList, &updateNothing< double, Vector6d > );

    ///////////////////////////////////////////////////////////////////////////    

    ///////////////////////////////////////////////////////////////////////////

    // Set up integrator and perform numerical integration. State history is saved to a map.

    // Get Runge-Kutta coefficients.
    RungeKuttaCoefficients rungeKuttaCoefficients 
        = getRungeKuttaCoefficients( caseData->numericalIntegratorType );

    // Declare Runge-Kutta, variable-stepsize, integrator.
    RungeKuttaVariableStepSizeIntegratorXdPointer integrator
            = make_shared< RungeKuttaVariableStepSizeIntegratorXd >(
                rungeKuttaCoefficients,
                bind( &CartesianStateDerivativeModel6d::computeStateDerivative,
                      stateDerivative, _1, _2 ),
                0.0,
                caseData->initialStateInKeplerianElements,
                std::numeric_limits< double >::epsilon( ),
                std::numeric_limits< double >::max( ),
                1.0e-12,
                1.0e-7 );

    // Perform integration.
    integrator->performIntegrationStep( 60.0 ); 

    ///////////////////////////////////////////////////////////////////////////            
}

} // namespace astrodynamics
} // namespace dustsim

#endif // DUSTSIM_EXECUTESIMULATION_H

/*
 *    The function contained in this file is basically the inner-loop of the simulator used for 
 *    single dust particle simulations and Monte Carlo simulations.
 *    Unit tests need to be added.
 */