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

#include <Server.hpp>

#include <fmt/core.h>

int main(int argc, char** argv) {

    if(argc < 2) {
        fmt::println(stderr, "No port is specified");
        fmt::println(stderr, "Expected {} <port>", argv[0]);
        return EXIT_FAILURE;
    }

    int port = std::atoi(argv[1]);

    fmt::println("Provided port: {}", port);
    Server s = Server{port};

    if (s.init() < 0) {
        std::cerr << "Initialization failed" << std::endl;
        return EXIT_FAILURE;
    }

    while (true)
        s.accept_new_connection();

    return EXIT_SUCCESS;
}