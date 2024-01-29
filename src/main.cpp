#include <iostream>

#include <Server.hpp>

bool isrunning = true;

void signal_handler(int signal)  {
    isrunning = false;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "No Port Specified" << std::endl;
        std::cout << argv[0] << " <port>" << std::endl;
    }

    int port = std::atoi(argv[1]);
    Server s = Server{port};

    if (s.init() < 0) {
        std::cerr << "Initialization failed" << std::endl;
        return -1;
    }
    while(isrunning) {
        s.loop();
    }
}