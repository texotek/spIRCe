#ifndef _SPIRCE_SERVER_HPP_
#define _SPIRCE_SERVER_HPP_

#include <vector>
#include <thread>
#include <unordered_map>

#include <utils.hpp>
#include <Socket.hpp>
#include <User.hpp>

class Server
{
private:
    int port;
    net::Socket listener;
    std::vector<std::thread> threads;
    std::vector<User> users;
public:
    Server(int port);
    int init();
    void loop();
    void handle_new(net::Socket client);
    void register_new_user(net::Socket client, std::vector<std::string>& args);
};

#endif