#ifndef _SPIRCE_CONNECTION_HPP_
#define _SPIRCE_CONNECTION_HPP_

#include <Socket.hpp>
#include <Server.hpp>

class Connection {
    private:
        Server *server;
        net::Socket socket;
    public:
        Connection(Server *server,net::Socket sock);
        void main_loop();
        void close();
        void handle_nick(std::vector<std::string>& args);
};

#endif