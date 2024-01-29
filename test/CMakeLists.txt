add_executable(socket_test SocketTest.cpp)

add_test(NAME socket_test COMMAND $<TARGET_FILE:socket_test>)