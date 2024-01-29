#include <User.hpp>

User::User(net::Socket conn, std::string nickname):conn(conn),nickname(nickname)
{
}