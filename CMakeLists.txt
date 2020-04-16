cmake_minimum_required(VERSION 3.12.0)
project( gtest_helpers )

set(REPO_ROOT "..")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
find_package(OpenCV REQUIRED)

# The target
add_library( gtest_helpers gtest_helpers.cpp )
add_library( cv_helpers cv_helpers.cpp)


target_include_directories( gtest_helpers PRIVATE ${REPO_ROOT}/fff )

target_link_libraries( gtest_helpers libgtest.so libgtest_main.so libpthread.so )
target_link_libraries( cv_helpers ${OpenCV_LIBS} )
