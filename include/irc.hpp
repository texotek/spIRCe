#pragma once

#include <vector>
#include <string>

namespace irc {
    class user {
    private:
        std::string nickname;
    public:
        user(std::string nickname);
    };

    class server {
    private:
        std::vector<user> users;
    public:
        server(/* args */);
    };
}