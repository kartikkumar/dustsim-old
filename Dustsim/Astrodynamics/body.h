/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_BODY_H
#define DUSTSIM_BODY_H

#include <boost/shared_ptr.hpp>

#include <Eigen/Core>

#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>

namespace dustsim
{

namespace astrodynamics
{

//! Body class.
class Body
{
public:

    // Set Eigen macro to correctly align class with fixed-size vectorizable types.
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    //! Constructor taking a state and an epoch.
    /*!
     * Constructor taking an input state and epoch. The input state is used internally to
     * set the current position (taken as a segment of the input state given by the indices
     * (0, 3)) and the current velocity (taken as a segment of the input state given by the indices
     * (3, 3).
     * \param aState An input state vector.
     * \param anEpoch An input epoch (default = 0.0) [s].
     */
    Body( const tudat::basic_mathematics::Vector6d& aState, const double anEpoch = 0.0 )
        : currentState( aState ),
          currentPosition( aState.segment( 0, 3 ) ),
          currentVelocity( aState.segment( 3, 3 ) ),
          currentEpoch( anEpoch )
    { }

    //! Set current epoch and state.
    /*!
     * Sets the current epoch, position and current velocity internally based on the input
     * arguments. The current position is taken as a segment of the input state given by the
     * indices (0, 3)), and the current velocity is taken as a segment of the input state given by
     * the indices (3, 3).
     * \param anEpoch An input epoch [s].
     * \param aState An input state vector.
     */
    void setCurrentEpochAndState( const double anEpoch,
                                  const tudat::basic_mathematics::Vector6d& aState )
    {
        currentEpoch = anEpoch;
        currentState = aState;
        currentPosition = aState.segment( 0, 3 );
        currentVelocity = aState.segment( 3, 3 );
    }

    //! Get current state.
    /*!
     * Returns the internally stored current state vector.
     * \return Current state.
     */
    tudat::basic_mathematics::Vector6d getCurrentState( ) { return currentState; }

    //! Get current position.
    /*!
     * Returns the internally stored current position vector.
     * \return Current position.
     */
    Eigen::Vector3d getCurrentPosition( ) { return currentPosition; }

    //! Get current velocity.
    /*!
     * Returns the internally stored current velocity vector.
     * \return Current velocity.
     */
    Eigen::Vector3d getCurrentVelocity( ) { return currentVelocity; }

    //! Get current epoch.
    /*!
     * Returns the internally stored current epoch.
     * \return Current epoch.
     */
    double getCurrentEpoch( ) { return currentEpoch; }

protected:

private:

    //! Current state.
    tudat::basic_mathematics::Vector6d currentState;

    //! Current position.
    Eigen::Vector3d currentPosition;

    //! Current position.
    Eigen::Vector3d currentVelocity;

    //! Current epoch.
    double currentEpoch;
};

//! Typedef for shared-pointer to body.
typedef boost::shared_ptr< Body > BodyPointer; 

} // astrodynamics
} // namespace dustsim

#endif // DUSTSIM_BODY_H
