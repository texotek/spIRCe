#ifndef _SPIRCE_SOCKET_HPP_
#define _SPIRCE_SOCKET_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class Socket
{
private:
    struct sockaddr_in insocket_addr;
public:
    int socketfd;
    Socket(sa_family_t family, in_addr_t inaddr, in_port_t inport);
    int create(int ADDR_TYPE, int STREAM_TYPE);
    int sbind();
    int slisten();
};

#endif