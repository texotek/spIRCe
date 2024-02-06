#pragma once

#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace net
{
    class Socket
    {
    private:
        struct sockaddr_in address;
    public:
        int socketfd;
        Socket();
        Socket(int domain, int service, int protocol);
        int listen(int port);
        int accept(Socket *newsock);
        ssize_t write(char *buf, size_t len);
        ssize_t write(std::string buf);
        ssize_t read(char *buf, size_t len);
        int close(int how);
    };
}