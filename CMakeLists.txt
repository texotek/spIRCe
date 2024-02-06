# set CMAKE Version 
cmake_minimum_required(VERSION 3.5.0)

# set C++ Version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name
project(spIRCe)

# Include directory
include_directories(include)

# add code sources
add_executable(spirce 
    src/main.cpp
    src/Socket.cpp 
    src/utils.cpp
    src/Server.cpp
    src/Connection.cpp
)

# add library
add_subdirectory(lib/fmt)
target_link_libraries(spirce fmt)
# contains an "external" library we will link to
#add_subdirectory(lib)

# enable testing and define tests
enable_testing()
add_subdirectory(test)


