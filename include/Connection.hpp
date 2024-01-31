#ifndef _SPIRCE_CONNECTION_HPP_
#define _SPIRCE_CONNECTION_HPP_

#include <Socket.hpp>

class Connection {
    private:
        net::Socket socket;
    public:
        Connection(net::Socket sock);
};

#endif