#pragma once

#include <string>
#include <Socket.hpp>

class User
{
private:
    net::Socket conn;
    std::string nickname;
public:
    User(net::Socket con, std::string nickname);
};