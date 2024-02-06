#ifndef _SPIRCE_SERVER_HPP_
#define _SPIRCE_SERVER_HPP_

#include <Socket.hpp>

#include <vector>

class Server
{
private:
    net::Socket listener;
public:
    int port;
    Server(int port);
    int init();
    void accept_new_connection();
};

#endif