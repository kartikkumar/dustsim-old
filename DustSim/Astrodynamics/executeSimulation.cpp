/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#include <iostream>
#include <limits>
#include <utility>

#include <boost/assign/list_of.hpp>
#include <boost/bind.hpp>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

#include <TudatCore/Astrodynamics/BasicAstrodynamics/orbitalElementConversions.h>

#include <Tudat/Astrodynamics/BasicAstrodynamics/accelerationModel.h>
#include <Tudat/Astrodynamics/Gravitation/centralGravityModel.h>
#include <Tudat/Astrodynamics/StateDerivativeModels/cartesianStateDerivativeModel.h>
#include <Tudat/Astrodynamics/StateDerivativeModels/compositeStateDerivativeModel.h>
#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>
#include <Tudat/Mathematics/NumericalIntegrators/rungeKuttaCoefficients.h>
#include <Tudat/Mathematics/NumericalIntegrators/rungeKuttaVariableStepSizeIntegrator.h>

#include <Assist/Astrodynamics/body.h>

#include "DustSim/Astrodynamics/dataUpdater.h"
#include "DustSim/Astrodynamics/executeSimulation.h"
#include "DustSim/Mathematics/basicMathematics.h"

namespace dustsim
{
namespace astrodynamics
{

//! Execute a single dust particle simulation.
boost::shared_ptr< input_output::OutputData > executeSimulation( 
    const input_output::CaseDataPointer caseData )
{
    ///////////////////////////////////////////////////////////////////////////

    // Set using statements.
    using std::make_pair;
    
    using boost::assign::list_of;
    using boost::bind;
    using boost::make_shared;
    using boost::shared_ptr;
    
    using namespace tudat::basic_astrodynamics;
    using namespace tudat::basic_astrodynamics::orbital_element_conversions;
    using namespace tudat::basic_mathematics;
    using namespace tudat::gravitation;
    using namespace tudat::numerical_integrators;
    using namespace tudat::state_derivative_models;    

    using namespace assist::astrodynamics;

    using namespace dustsim::input_output;
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

    // Construct data updater that updates the state and associated epoch of the dust particle.
    DataUpdaterPointer dataUpdater = make_shared< DataUpdater >( dustParticle );

    CartesianStateDerivativeModel6dPointer stateDerivative
            = make_shared< CartesianStateDerivativeModel6d >(
                accelerationList, 
                bind( &DataUpdater::updateEpochAndState, dataUpdater, _1, _2 ) );

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
                caseData->startEpoch,
                caseData->initialStateInKeplerianElements,
                caseData->numericalIntegratorMinimumStepSize,
                caseData->numericalIntegratorMaximumStepSize,
                caseData->numericalIntegratorRelativeTolerance,
                caseData->numericalIntegratorAbsoluteTolerance );

    // Set step size to initial value.
    double stepSize = caseData->numericalIntegratorInitialStepSize;

    // Declare output data struct to store state history.
    shared_ptr< OutputData > output = make_shared< OutputData >( );

    // Store initial state in state history.
    output->stateHistory[ dustParticle->getCurrentTime( ) ] = dustParticle->getCurrentState( );    

    // Execute integration until end of simulation period is reached.
    // while ( integrator->getCurrentIndependentVariable( ) 
    //         < caseData->startEpoch + caseData->maximumSimulationPeriod )
    // {
    int i = 0;
    while ( i < 1000 )
    {    
        // Execute single integration step.
        integrator->performIntegrationStep( stepSize );

        // Update step size.
        stepSize = integrator->getNextStepSize( );

        // Store current state in state history.
        output->stateHistory[ dustParticle->getCurrentTime( ) ] 
            = dustParticle->getCurrentState( );    

        i++;
    }

    ///////////////////////////////////////////////////////////////////////////            

    ///////////////////////////////////////////////////////////////////////////

    // Return output data struct.
    return output;

    ///////////////////////////////////////////////////////////////////////////
}

} // namespace astrodynamics
} // namespace dustsim