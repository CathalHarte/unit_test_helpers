/******************************************************************************/
/*!
 * @file  fff_helpers.h
 * @brief 
 * 
 * @author Cathal Harte <cathal.harte@protonmail.com>
 */
#ifndef _FFF_HELPERS_H
#define _FFF_HELPERS_H

/*******************************************************************************
* Includes
******************************************************************************/

#include <fff.h>

/*! @defgroup fff_helpers FFF_helpers.
 *
 * @addtogroup fff_helpers
 * @{
 * @brief 
 */
/*******************************************************************************
* Definitions and types
*******************************************************************************/

#define IN_CALL_HISTORY(function)    gtest_helpers::in_call_history(&fff, (void *)function);

#define IS_CALLED_AFTER(function, prerequisite_functions)  gtest_helpers::is_called_after( \
                                                    &fff, \
                                                    (void *)function, \
                                                    prerequisite_functions, \
                                                    sizeof(prerequisite_functions)/sizeof(void *));

/*******************************************************************************
* Data
*******************************************************************************/

/*******************************************************************************
* Class prototypes
*******************************************************************************/

/*******************************************************************************
* Function prototypes
*******************************************************************************/

namespace fff_helpers
{

void in_call_history(fff_globals_t * fff, void * function);

void is_called_after(fff_globals_t * fff, void * function, void ** prerequisite_functions, int32_t num_prerequisite_functions);

}

/*! @}
 */

#endif  // _FFF_HELPERS_H
