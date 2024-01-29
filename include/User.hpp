#ifndef _SPIRCE_USER_HPP_
#define _SPIRCE_USER_HPP_

#include <string>
#include <Socket.hpp>
#include <Server.hpp>

class User
{
private:
    net::Socket conn;
    std::string nickname;
public:
    User(net::Socket con);
};

#endif