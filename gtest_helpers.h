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

#define TEST_NAME ::testing::UnitTest::GetInstance()->current_test_info()->name()

/*******************************************************************************
* Data
*******************************************************************************/

/*******************************************************************************
* Function prototypes
*******************************************************************************/

/*! @}
 */

#endif  // _GTEST_HELPERS_H
