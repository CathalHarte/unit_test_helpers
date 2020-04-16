/******************************************************************************/
/*!
 * @file  gtest_helpers.h
 * @brief 
 * 
 * 
 * @author Cathal Harte <cathal.harte@protonmail.com>
 */

#ifndef _GTEST_HELPERS_H
#define _GTEST_HELPERS_H

/*******************************************************************************
* Includes
******************************************************************************/

#include <fff.h>

/*! @defgroup gtest_helpers Gtest_helpers.
 *
 * @addtogroup gtest_helpers
 * @{
 * @brief 
 */
/*******************************************************************************
* Definitions and types
*******************************************************************************/

// Use this macro to write to the GTEST output (properly formatted) regardless of success/fail conditions
// Use sparingly, we don't want to generate lots of noise
#define GTEST_COUT std::cerr << "[          ] [ INFO ] "
// Use it in this manner GTEST_COUT << "something to communicate" << std::endl

#define IN_CALL_HISTORY(function)    gtest_helpers::in_call_history(&fff, (void *)function);

#define IS_CALLED_AFTER(function, prerequisite_functions)  gtest_helpers::is_called_after( \
                                                    &fff, \
                                                    (void *)function, \
                                                    prerequisite_functions, \
                                                    sizeof(prerequisite_functions)/sizeof(void *));

#define TEST_NAME ::testing::UnitTest::GetInstance()->current_test_info()->name()
/*******************************************************************************
* Data
*******************************************************************************/

/*******************************************************************************
* Function prototypes
*******************************************************************************/

namespace gtest_helpers
{

void in_call_history(fff_globals_t * fff, void * function);

void is_called_after(fff_globals_t * fff, void * function, void ** prerequisite_functions, int32_t num_prerequisite_functions);

}
/*! @}
 */

#endif  // _GTEST_HELPERS_H
