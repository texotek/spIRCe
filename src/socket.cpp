#include <Socket.hpp>

#include <iostream>

net::Socket::Socket() {}

net::Socket::Socket(int domain, int service, int protocol)
{
    // Define address structure
    address.sin_family = domain;
    address.sin_addr.s_addr = INADDR_ANY;
    socketfd = ::socket(domain, service, protocol);
}

int net::Socket::listen(int port)
{
    address.sin_port = htons(port);
    if(::bind(socketfd, (sockaddr*)&address, sizeof(address)) < 0) {
        return -1; // socket binding error
    }
    if(::listen(socketfd, 20) < 0) {
        return -2; // socket listening error
    }
    return 0;
}

int net::Socket::accept(net::Socket *new_sock)
{
    
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    int clientfd;
    
    if((clientfd = ::accept(socketfd, (sockaddr*)&client_addr, &length)) < 0) {
        return -1;
    }

    new_sock->socketfd = clientfd;
    new_sock->address = client_addr;

    return 0;
}

ssize_t net::Socket::write(char *buf, size_t len)
{
    return ::send(socketfd, buf, len, 0);
}

ssize_t net::Socket::write(std::string buf)
{
    
    return ::send(socketfd, buf.c_str(), buf.length(), 0);
}

ssize_t net::Socket::read(char *buf, size_t len)
{
    return ::recv(socketfd, buf, len, 0);
}

int net::Socket::close(int how)
{
    return ::shutdown(socketfd, how);
}
