#include <Server.hpp>

#include <iostream>


Server::Server(int port):port(port)
{
}

int Server::init()
{
    listener = {AF_INET, SOCK_STREAM, IPPROTO_TCP};
    if (listener.listen(port) < 0) {
        return -1;
    };
    return 0;
}

void Server::loop()
{
    net::Socket client;
    if(listener.accept(&client) < 0) {
        handle_new(client);
    }
}


void Server::handle_new(net::Socket client) {
    size_t recv_len;
    char recv_buf[512];

    while((recv_len = client.read(recv_buf, sizeof(recv_buf))) > 0) {
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
   client.close(0);
}
