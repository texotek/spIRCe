#include <iostream>
#include <socket.hpp>
#include <thread>

#define info(msg) std::cerr << "(+) " << msg << std::endl;
#define err(msg) std::cerr << msg << std::endl

void handle_client(net::socket client) {
    char receivingbuffer[65536];
    while(client.read(receivingbuffer, sizeof(receivingbuffer)) > 0) {
        std::cout << receivingbuffer;
        std::memset(receivingbuffer, 0, sizeof(receivingbuffer));
    }
    client.close(0);
}

int main(int argc, char** argv) {

    if(argc < 2) {
        err("Not enough arguments specified");
        err("Expected " << argv[0] << " <port>");
        return -1;
    }

    net::socket server_sock{AF_INET, SOCK_STREAM, IPPROTO_TCP};
    server_sock.listen(std::atoi(argv[1]));
    info("Started listening")

    char recv_buf[65536];
    std::memset(recv_buf, 0, sizeof(recv_buf));

    while(1) {
        net::socket client{};
        if(server_sock.accept(&client) < 0) {
            err("Error while accepting client");
            break;
        }
        try
        {
            std::thread(handle_client, client);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

}