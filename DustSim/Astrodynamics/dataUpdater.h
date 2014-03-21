/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_DATA_UPDATER_H
#define DUSTSIM_DATA_UPDATER_H

#include <boost/shared_ptr.hpp>

#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>

#include <Assist/Astrodynamics/body.h>

namespace dustsim
{
namespace astrodynamics
{

//! Data updater class.
/*!
 * Essentially, this class serves to provide a wrapper for an update()-function that is called by
 * the Cartesian state derivative model in Tudat. It provides an interface to update a the state 
 * of a dust particle, stored in a Body object (Assist). The current epoch associated with each 
 * state is also updated.
 * \sa CartesianStateDerivativeModel, Body.
 */
class DataUpdater
{
public:

    //! Constructor taking shared-pointer to body.
    /*!
     * Constructor taking shared-pointer to body, which is used internally to update the epochs
     * and states stored in the body. This is used in conjunction with the Cartesian state
     * derivative model in Tudat.
     * \param aBody Shared-pointer to Body object
     */
    DataUpdater( const assist::astrodynamics::BodyPointer aBody )
        : body( aBody )
    { }

    //! Update epoch and composite state.
    /*!
     * Updates the epoch and composite state information in Body object.
     * \param epoch Current epoch.
     * \param state Current state (represented as vector of 6 elements).
     */
    void updateEpochAndState( const double epoch, const tudat::basic_mathematics::Vector6d& state )
    {
        body->setCurrentTimeAndState( state, epoch );
    }

protected:
private:

    //! Shared-pointer to Body object.
    const assist::astrodynamics::BodyPointer body;
};

//! Typedef for a shared-pointer to a DataUpdater object.
typedef boost::shared_ptr< DataUpdater > DataUpdaterPointer;

} // namespace astrodynamics
} // namespace dustsim

#endif // DUSTSIM_DATA_UPDATER_H
