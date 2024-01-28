#ifndef _SPIRCE_SOCKET_HPP_
#define _SPIRCE_SOCKET_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

namespace net
{
    class socket
    {
    private:
        struct sockaddr_in address;
    public:
        int socketfd;
        socket();
        socket(int domain, int service, int protocol);
        int listen(int port);
        int accept(socket *newsock);
        ssize_t write(char *buf, size_t len);
        ssize_t read(char *buf, size_t len);
        int close(int how);

    };
}
#endif