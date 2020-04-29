cmake_minimum_required(VERSION 3.12.0)
project( fff_helpers )

set(REPO_ROOT "../..")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
find_package(OpenCV REQUIRED)

# The target
add_library( fff_helpers fff_helpers.cpp )

target_include_directories( fff_helpers PRIVATE ${REPO_ROOT}/fff )

target_link_libraries( fff_helpers libgtest.so libgtest_main.so libpthread.so )
