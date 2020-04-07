cmake_minimum_required(VERSION 3.12.0)
project( gtest_helpers )

set(REPO_ROOT "..")

# The target
add_library( gtest_helpers gtest_helpers.cpp )

target_include_directories( gtest_helpers PRIVATE   ..
                                                    ${REPO_ROOT}/fff )

target_link_libraries( gtest_helpers libgtest.so libgtest_main.so libpthread.so )
