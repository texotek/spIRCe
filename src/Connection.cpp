#include <string>
#include <vector>
#include <format>

#include <Connection.hpp>
#include <Server.hpp>
#include <numerics.hpp>
#include <utils.hpp>

#include <fmt/core.h>

Connection::Connection(Server *server, net::Socket sock) : server(server), socket(sock) {}

void Connection::main_loop()
{
    size_t recv_len;
    char recv_buf[512];
    while ((recv_len = socket.read(recv_buf, sizeof(recv_buf))) > 0)
    {
        bool isCRLF = false;
        std::string raw_message{recv_buf, recv_len};
        if (raw_message.find("\r") != std::string::npos)
            isCRLF = true;
        std::vector<std::string> commands;
        if (isCRLF)
            commands = utils::split_string(raw_message, "\r\n");
        else
            commands = utils::split_string(raw_message, "\n");

        for (std::string s : commands)
        {
            std::vector tokens = utils::split_string(s, " ");
            if (tokens.size() == 0)
                continue;

            std::string comm = tokens[0];
            std::vector<std::string> arguments{tokens.begin() + 1, tokens.end()};
            if (comm == "NICK")
                handle_nick(arguments);
            if (comm == "USER")
                handle_user(arguments);
        }
        std::memset(recv_buf, 0, sizeof(recv_buf));
    }
    this->close();
}

void Connection::close()
{
    socket.close(0);
}

std::string Connection::get_nickname() { return nickname; }

void Connection::handle_nick(std::vector<std::string> &args)
{
    if (args.empty())
    {
        socket.write(fmt::format("{} {} :No Nickname given\r\n", ERR_NONICKNAMEGIVEN, "*"));
        return;
    }
    else if (server->check_nickname_used(args[0]))
    {
        socket.write(fmt::format("{} {} :Nickname already in use\r\n", ERR_NICKNAMEINUSE, args[0]));
        return;
    }

    this->nickname = args[0];
}

void Connection::handle_user(std::vector<std::string> &args)
{
}
