/*    
 * Copyright (c) 2010-2014, Delft University of Technology
 * Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 * Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 * All rights reserved.
 * See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_CASE_DATA_H
#define DUSTSIM_CASE_DATA_H

// #include <iostream>
#include <string>

#include <boost/shared_ptr.hpp>

#include <Eigen/Core>

// #include <SQLiteC++.h> 

#include <Tudat/Mathematics/BasicMathematics/linearAlgebraTypes.h>

namespace dustsim
{
namespace input_output
{

// enum NumericalIntegratorType { DOPRI853, RKF78 };   

//! Data struct that contains all of the case information for a dust particle simulation.
/*!
 * This data struct contains all of the case information for a dust particle simulation. The data * stored is, in essence, metadata for the simulation.
 */
struct CaseData
{
public:

    // Set Eigen macro to correctly align class with fixed-size vectorizable types.
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

    //! Constructor taking all case data as input.
    CaseData(const int aCaseId,
             const std::string& aCaseName,
             const double aMaximumSimulationPeriod,
             const double aStartEpoch,
             const tudat::basic_mathematics::Vector6d anInitialStateInKeplerianElements,
             const double aCentralBodyGravitationalParameter,
             const std::string& aNumericalIntegratorType,
             const double aNumericalIntegratorInitialStepSize,
             const double aNumericalIntegratorMinimumStepSize,
             const double aNumericalIntegratorMaximumStepSize,             
             const double aNumericalIntegratorRelativeTolerance,
             const double aNumericalIntegratorAbsoluteTolerance );
             // ,
             // // Optional parameters.
             // const double aCentralBodyGravitationalParameter,
             // const double aCentralBodyEquatorialRadius, 
             // const double aSynodicPeriodMaximum,
             // const double aStartUpIntegrationPeriod,
             // const double aCentralBodyJ2GravityCoefficient,
             // const double aConjunctionEventDetectionDistance,
             // const double anOppositionEventDetectionDistance,
             // const double anEccentricityDistributionMean,
             // const double anEccentricityDistributionFullWidthHalfMaximum,
             // const double anInclinationDistributionMean,
             // const double anInclinationDistributionFullWidthHalfMaximum,
             // const std::string& aNumericalIntegratorType,
             // const double aNumericalIntegratorInitialStepSize,
             // const double aNumericalIntegratorRelativeTolerance,
             // const double aNumericalIntegratorAbsoluteTolerance );

    //! Case ID.
    const int caseId;
    
    //! Case name.
    const std::string caseName;

    //! Maximum simulation period [s].
    const double maximumSimulationPeriod;

    //! Start epoch [s].
    const double startEpoch;
    
    //! Initial state of dust particle in Keplerian elements.
    const tudat::basic_mathematics::Vector6d initialStateInKeplerianElements;

    //! Central body gravitational parameter [m^3 s^-2].
    const double centralBodyGravitationalParameter;

    //! Numerical integrator type.
    const std::string numericalIntegratorType;

    //! Numerical integrator initial step size [s].
    const double numericalIntegratorInitialStepSize;

    //! Numerical integrator minimum step size [s].
    const double numericalIntegratorMinimumStepSize;    

    //! Numerical integrator maximum step size [s].
    const double numericalIntegratorMaximumStepSize;    

    //! Numerical integrator relative tolerance [-].
    const double numericalIntegratorRelativeTolerance;

    //! Numerical integrator absolute tolerance [km].
    const double numericalIntegratorAbsoluteTolerance;

//     //! Perturbed body radius [m].
//     const double perturbedBodyRadius;

//     //! Perturbed body bulk density [kg m^-3].
//     const double perturbedBodyBulkDensity;

//     //! Perturbed body state in Keplerian elements at T0.
//     const tudat::basic_mathematics::Vector6d perturbedBodyStateInKeplerianElementsAtT0;

//     //! Limits on maximum semi-major axis values wrt perturbed body [m].
//     const double semiMajorAxisDistributionLimit;

//     // Optional parameters.

//     //! Maximum synodic period permitted [s].
//     const double synodicPeriodMaximum;

//     //! Startup integration period [s].
//     const double startUpIntegrationPeriod;

//     //! Central body J2 gravity field coefficient.
//     const double centralBodyJ2GravityCoefficient;

//     //! Central body equatorial radius [m].
//     const double centralBodyEquatorialRadius;

//     //! Mutual distance used to detect start and end of conjunction events [m].
//     const double conjunctionEventDetectionDistance;

//     //! Distance used to detect start and end of opposition events [m].
//     const double oppositionEventDetectionDistance;

//     //! Mean eccentricity value for distribution.
//     const double eccentricityDistributionMean;

//     //! FWHM eccentricity value for distribution.
//     const double eccentricityDistributionFullWidthHalfMaximum;

//     //! Mean inclination value for distribution [rad].
//     const double inclinationDistributionMean;

//     //! FWHM inclination value for distribution [rad].
//     const double inclinationDistributionFullWidthHalfMaximum;

//     //! Numerical integrator type.
//     NumericalIntegratorType numericalIntegratorType;

//     //! Initial step size for numerical integrator.
//     const double numericalIntegratorInitialStepSize;

//     //! Relative tolerance for numerical integrator.
//     const double numericalIntegratorRelativeTolerance;

//     //! Absolute tolerance for numerical integrator.
//     const double numericalIntegratorAbsoluteTolerance;

protected:
private:
};

//! Typedef for shared-pointer to CaseData object.
typedef boost::shared_ptr< CaseData > CaseDataPointer;

// // Define all of the operator overloads as non-member functions (sbi, 2010).

//! Overload == operator.
bool operator==( const CaseData& caseData1, CaseData& caseData2 );

//! Overload < operator.
bool operator<( const CaseData& caseData1, const CaseData& caseData2 );

//! Overload << operator.
std::ostream& operator<<( std::ostream& outputStream, const CaseData& caseData );

} // namespace input_output
} // namespace dustsim

#endif // DUSTSIM_CASE_DATA_H

/*
 *    References
 *      sbi. C++ Operator Overloading, Stack Overflow,
 *          http://stackoverflow.com/questions/4421706/operator-overloading, 2010, last accessed:
 *          9th March, 2013.
 */
