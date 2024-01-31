#include <Server.hpp>

#include <iostream>
#include <fmt/core.h>

#include <Connection.hpp>

Server::Server(int port):port(port) {

    //commands["NICK"] = &Server::command_nick;

}


int Server::init()
{
    listener = {AF_INET, SOCK_STREAM, IPPROTO_TCP};
    if (listener.listen(port) < 0) {
        return -1;
    };
    return 0;
}

void Server::accept_new_connection()
{
    net::Socket socket;
    if(listener.accept(&socket) < 0) {
        fmt::println(stderr, "Failed to accept connection");
        return;
    }

    Connection con{socket};

    std::thread(&Server::handle_new, this, socket).detach();
}

void Server::handle_new(net::Socket socket) {
    size_t recv_len;
    char recv_buf[512];

    fmt::println("Got new client");
    while((recv_len = socket.read(recv_buf, sizeof(recv_buf))) > 0) {
        std::string raw_message{recv_buf, recv_len};
        std::vector<std::string> commands = utils::split_string(raw_message, "\r\n");

        for(std::string s : commands) {
            std::vector tokens = utils::split_string(s, " ");
            for(std::string t : tokens) {
                std::cout << t << std::endl;
            }
            if(tokens[0] == "NICK") {

            }
        }
        std::memset(recv_buf, 0, sizeof(recv_buf));
    }
   socket.close(0);
}
