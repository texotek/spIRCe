#include <iostream>
#include <thread>

#include <utils.hpp>
#include <socket.hpp>
#include <irc.hpp>

#define info(msg) std::cout << "(+) " << msg << std::endl;
#define err(msg) std::cerr << msg << std::endl

irc::server serv;

void handle_client(net::socket client) {
    size_t recv_len;
    char recv_buf[65536];

    while((recv_len = client.read(recv_buf, sizeof(recv_buf))) > 0) {

        std::string raw_message{recv_buf, recv_len};
        std::vector<std::string> messages = utils::split_string(raw_message, "\r\n");
        for(std::string s : messages) {
            std::vector tokens = utils::split_string(s, " ");
            if(tokens[0] == "NICK") {
            }
        }
        std::memset(recv_buf, 0, sizeof(recv_buf));
    }

   client.close(0);
}

int main(int argc, char** argv) {

    std::vector<std::thread> threads{};
    if(argc < 2) {
        err("Not enough arguments specified");
        err("Expected " << argv[0] << " <port>");
        return -1;
    }

    net::socket server_sock{AF_INET, SOCK_STREAM, IPPROTO_TCP};
    if (server_sock.listen(std::atoi(argv[1])) < 0) {
        err("Failed to start listening");
        return -1;
    };
    info("Started listening");

    while(1) {
        net::socket client;
        if(server_sock.accept(&client) < 0) {
            err("Error while accepting client");
            break;
        }
        threads.push_back(std::thread(handle_client, client));
    }

    for (size_t i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
    
}