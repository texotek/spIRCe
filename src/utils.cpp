#include <utils.hpp>

std::vector<std::string> utils::split_string(const std::string s, const std::string delimiter)
{
    std::regex regexz(delimiter);
    std::vector<std::string> list(std::sregex_token_iterator(s.begin(), s.end(), regexz, -1),
                                std::sregex_token_iterator());
    return list;
}
