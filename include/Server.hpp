#ifndef _SPIRCE_SERVER_HPP_
#define _SPIRCE_SERVER_HPP_

#include <vector>
#include <thread>
#include <unordered_map>

#include <utils.hpp>
#include <Socket.hpp>

class Server
{
private:
    std::unordered_map<std::string, std::function<void(const net::Socket,const std::vector<std::string>&)>> command_registry;

    int port;
    std::vector<std::thread> threads{};
    net::Socket listener;
public:

    Server(int argc, char** argv);
    int init();
    void loop();
};

#endif