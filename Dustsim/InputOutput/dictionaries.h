/*    
 *    Copyright (c) 2010-2014, Delft University of Technology
 *    Copyright (c) 2010-2014, K. Kumar (me@kartikkumar.com)
 *    Copyright (c) 2013-2014, S. Hirsh (sethhirsh@berkeley.edu)
 *    All rights reserved.
 *    See http://bit.ly/12SHPLR for license details.
 */

#ifndef DUSTSIM_DICTIONARIES_H
#define DUSTSIM_DICTIONARIES_H

#include <Tudat/InputOutput/dictionaryTools.h>

namespace dustsim
{
namespace input_output
{

//! Get dictionary of general parameters.
/*!
 * Returns dictionary of general parameters for dust particle simulator application.
 * \return Shared-pointer to new dictionary with general parameters for dust particle simulator 
 *          application.
 */
tudat::input_output::dictionary::DictionaryPointer getGeneralParametersDictionary( );

//! Get dictionary of initial Keplerian elements.
/*!
 * Returns dictionary of initial Keplerian elements for dust particle simulator application.
 * \return Shared-pointer to new dictionary with initial Keplerian elements for dust particle  
 *          application simulator.
 */
tudat::input_output::dictionary::DictionaryPointer getKeplerianElementsDictionary( );

//! Get dictionary of gravity force model parameters.
/*!
 * Returns dictionary of gravity force model parameters for dust particle simulator application.
 * \return Shared-pointer to new dictionary with gravity force model parameters for dust particle  
 *          application simulator.
 */
tudat::input_output::dictionary::DictionaryPointer getGravityForceModelDictionary( );

//! Get dictionary of numerical integrator settings.
/*!
 * Returns dictionary of numerical integrator settings for dust particle simulator application.
 * \return Shared-pointer to new dictionary with numerical integrator settings for dust particle  
 *          application simulator.
 */
tudat::input_output::dictionary::DictionaryPointer getNumericalIntegratorSettingsDictionary( );

// //! Get dictionary for dust particle Monte Carlo simulator application.
// /*!
//  * Returns dictionary for dust particle Monte Carlo simulator application.
//  * \return Shared-pointer to new dictionary for dust particle Monte Carlo simulator application.
//  */
// tudat::input_output::dictionary::DictionaryPointer getMonteCarloSimulatorDictionary( );

// //! Get dictionary for dust particle database generator application.
// /*!
//  * Returns standard dictionary for dust particle database generator application.
//  * \return Shared-pointer to new dictionary for dust particle database generator application.
//  */
// tudat::input_output::dictionary::DictionaryPointer getDatabaseGeneratorDictionary( );



} // namespace input_output
} // namespace dustsim

#endif // DUSTSIM_DICTIONARIES_H

/*
 *    Unit tests need to be added to test the lexical dictionaries defined.
 */
