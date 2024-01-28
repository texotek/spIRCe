#include <iostream>

#include <Server.hpp>

Server *sp;

// void signal_handler(int signal)  {

//     exit(0);
// }

int main(int argc, char** argv) {

    Server s = Server(argc, argv);
    sp = &s;

    if (s.init() < 0) {
        std::cerr << "Initialization failed" << std::endl;
        return -1;
    }

    s.loop();
}