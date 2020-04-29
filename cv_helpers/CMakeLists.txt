cmake_minimum_required(VERSION 3.12.0)
project( cv_helpers )

set(REPO_ROOT "..")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
find_package(OpenCV REQUIRED)

# The target
add_library( cv_helpers cv_helpers.cpp)
target_link_libraries( cv_helpers ${OpenCV_LIBS} )
