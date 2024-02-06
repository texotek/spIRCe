#pragma once

#include <Socket.hpp>

class Server;
class Connection {
    private:
        Server *server;
        net::Socket socket;
        std::string nickname;
        bool isRegistered;
    public:
        Connection(Server *server, net::Socket sock);
        void main_loop();
        void close();
        std::string get_nickname();

        void handle_nick(std::vector<std::string>& args);
        void handle_user(std::vector<std::string>& args);
};