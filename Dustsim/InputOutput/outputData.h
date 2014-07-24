/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_OUTPUT_DATA_H
#define DUSTSIM_OUTPUT_DATA_H

#include <Eigen/Core>

#include <Assist/Basics/commonTypedefs.h>

namespace dustsim
{
namespace input_output
{

//! Data struct that contains all of the output information for a dust particle simulation.
/*!
 * This data struct contains all of the output information for a dust particle simulation.
 */
struct OutputData
{
public:

    // Set Eigen macro to correctly align class with fixed-size vectorizable types.
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    //! Constructor taking all case data as input.
    OutputData( ) { }

    //! State history (key=epoch, value=Cartesian state).
    assist::basics::DoubleKeyVector6dValueMap stateHistory;

    //! State history in Keplerian elements (key=epoch, value=Keplerian state).
    assist::basics::DoubleKeyVector6dValueMap stateHistoryInKeplerianElements;
    
protected:
private:
};

} // namespace input_output
} // namespace dustsim

#endif // DUSTSIM_OUTPUT_DATA_H

/*
 *    References
 *      sbi. C++ Operator Overloading, Stack Overflow,
 *          http://stackoverflow.com/questions/4421706/operator-overloading, 2010, last accessed:
 *          9th March, 2013.
 */
