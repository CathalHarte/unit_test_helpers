/******************************************************************************/
/*!
 * @file  gtest_helpers.cpp
 * @brief
 * 
 * @author Cathal Harte <cathal.harte@protonmail.com>
 */

/*******************************************************************************
* Includes
******************************************************************************/

#include <gtest/gtest.h>
#include <fff.h>

/*******************************************************************************
* Definitions
*******************************************************************************/


/*******************************************************************************
* Types
*******************************************************************************/


/*******************************************************************************
* Internal function prototypes
*******************************************************************************/


/*******************************************************************************
* Classes
*******************************************************************************/


/*******************************************************************************
* Functions
*******************************************************************************/
namespace gtest_helpers
{

void in_call_history(fff_globals_t * fff, void * function)
{
    bool in_call_history = false;
    for(int i = 0; i < fff->call_history_idx; i++)
    {
        if(fff->call_history[i] == function)
        {
            in_call_history = true;
        }
    }
    EXPECT_TRUE(in_call_history);
}

void is_called_after(fff_globals_t * fff, void * function, void ** prerequisite_functions, int32_t num_prerequisite_functions)
{
    int32_t call_history_loc;
    bool is_called = false;
    bool is_called_after = true;
    int curr_history_idx = 0;
    for(; curr_history_idx < fff->call_history_idx; curr_history_idx++)
    {
        if(fff->call_history[curr_history_idx] == function)
        {
            call_history_loc = curr_history_idx;
            is_called = true;
            break;
        }
    }
    EXPECT_TRUE(is_called);

    for(; curr_history_idx < fff->call_history_idx; curr_history_idx++)
    {
        for(int function_addr = 0; function_addr < num_prerequisite_functions; function_addr++)
        {
            if(fff->call_history[curr_history_idx] == prerequisite_functions[function_addr])
            {
                is_called_after = false;
            }
        }
    }
    EXPECT_TRUE(is_called_after) << "this the index " << curr_history_idx << std::endl;
}

}