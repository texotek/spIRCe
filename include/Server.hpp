#pragma once

#include <Socket.hpp>
#include <Connection.hpp>

class Server
{
private:
    net::Socket listener;
    std::vector<Connection*> connections;
public:
    int port;
    Server(int port);
    int init();
    void accept_new_connection();
    bool check_nickname_used(std::string nick);
};