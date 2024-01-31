/**
 * @file main.cpp
 * @author Felix Dahmen (fdahmen@proton.me)
 * @brief  
 * @version 0.1
 * @date 2024-01-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <csignal>
#include <fmt/core.h>

#include <Server.hpp>

bool isrunning = true;

// void signal_handler(int signal)  {
//     fmt::println("Received signal {}", signal);
//     isrunning = false;
// }

int main(int argc, char** argv) {
    
    // std::signal(SIGINT, signal_handler);

    if(argc < 2) {
        fmt::println(stderr, "No port is specified");
        fmt::println(stderr, "Expected {} <port>", argv[0]);
        return EXIT_FAILURE;
    }

    int port = std::atoi(argv[1]);
    if(!port) {
        fmt::println(stderr, "Invalid port: {}", port);
        return EXIT_FAILURE;
    }

    fmt::println("Provided port: {}", port);
    Server s = Server{port};

    if (s.init() < 0) {
        std::cerr << "Initialization failed" << std::endl;
        return EXIT_FAILURE;
    }

    while(isrunning)
    s.accept_new_connection();

    return EXIT_SUCCESS;
}