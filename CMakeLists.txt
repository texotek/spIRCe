cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(spIRCe)


include_directories(include)
add_executable(spirce src/main.cpp src/socket.cpp src/utils.cpp src/irc.cpp)
# contains an "external" library we will link to
#add_subdirectory(lib)

# enable testing and define tests
enable_testing()
add_subdirectory(test)


