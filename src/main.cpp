#include <iostream>
#include <socket.hpp>

int main() {

    Socket s{AF_INET, INADDR_ANY, 2000};

    if (s.create(AF_INET, SOCK_STREAM) < 0) {
        std::cerr << "Socket error, exiting...." << std::endl;
        return 1;
    }

    if(s.sbind() < 0) {
        std::cerr << "Bind error, exiting...." << std::endl;
        return 1;
    }
    
    if(s.slisten() < 0) {
        std::cerr << "Listen error, exiting...." << std::endl;
        return 1;
    }

    char recv_buf[65536];
    memset(recv_buf, 0, sizeof(recv_buf));

    while(1) {
        struct sockaddr_in client_addr;

        socklen_t length = sizeof(client_addr);
        int conn = accept(s.socketfd, (struct sockaddr*)&client_addr, &length);

        if(conn < 0) {
            std::cout << "Error while receiving connection" << std::endl;
            return 1;
        }

        std::cout << "Accepted new client" << std::endl;
        char client_ip[INET_ADDRSTRLEN] = "";
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        while(recv(conn, recv_buf, sizeof(recv_buf), 0) > 0) {
            std::cout << "Received " << recv_buf << "from client " << client_ip << ":" << client_addr.sin_port << std::endl;
            memset(recv_buf, 0, sizeof(recv_buf));
            break;
        }

    }

}