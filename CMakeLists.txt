
cmake_minimum_required(VERSION 3.16)
project(mocap_logger VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)

# Find requirements
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)



add_subdirectory(lib)
add_subdirectory(app)
add_subdirectory(tests)