#include <socket.hpp>

Socket::Socket(sa_family_t family, in_addr_t inaddr, uint16_t port)
{
    insocket_addr.sin_family=family;
    insocket_addr.sin_addr.s_addr=inaddr;
    insocket_addr.sin_port = htons(port);
}
/**
 * param3
*/
int Socket::create(int ADDR_TYPE, int STREAM_TYPE) {
    return this->socketfd = socket(ADDR_TYPE, STREAM_TYPE, 0);
}

int Socket::sbind() {
    return bind(this->socketfd, (const sockaddr*)&this->insocket_addr, sizeof(insocket_addr));
}

int Socket::slisten() {
    return listen(this->socketfd, 20);
}