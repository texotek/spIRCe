#include <iostream>
#include <thread>

#include <Server.hpp>
#include <numerics.hpp>
#include <Connection.hpp>

#include <fmt/core.h>

Server::Server(int port) : port(port) {}

int Server::init()
{
    listener = {AF_INET, SOCK_STREAM, IPPROTO_TCP};
    if (listener.listen(port) < 0)
    {
        return -1;
    };
    return 0;
}

void Server::accept_new_connection()
{
    net::Socket socket;
    if (listener.accept(&socket) < 0)
    {
        fmt::println(stderr, "Failed to accept connection");
        return;
    }

    Connection con{this, socket};
    std::thread(&Connection::main_loop, con).detach();
    connections.push_back(&con);
}

bool Server::check_nickname_used(std::string nick)
{
    for(Connection *con : connections) {
        if(nick == con->get_nickname()) return true;
    }
    return false;
}
