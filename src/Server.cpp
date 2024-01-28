#include <Server.hpp>

#include <iostream>

void handle_client(net::Socket client) {
    size_t recv_len;
    char recv_buf[65536];
    std::cout << "Got client" << std::endl;

    while((recv_len = client.read(recv_buf, sizeof(recv_buf))) > 0) {

        std::cout << "Got message" << std::endl;

        std::string raw_message{recv_buf, recv_len};

        std::cout << "raw message:" << std::endl;
        std::cout << raw_message;

        std::vector<std::string> commands = utils::split_string(raw_message, "\r\n");

        std::cout << "commands size: " << commands.size() << std::endl;
        for(std::string s : commands) {
            std::vector tokens = utils::split_string(s, " ");

            std::cout << "tokens size: " << tokens.size() << std::endl;
        }
        std::memset(recv_buf, 0, sizeof(recv_buf));
    }

   client.close(0);
}

Server::Server(int argc, char **argv)
{
    if(argc < 2) {
        std::cout << "Not enough arguments specified" << std::endl;
        std::cout << "Expected " << argv[0] << " <port>" << std::endl;
        exit(EXIT_FAILURE);
    }
    port = atoi(argv[1]);
}
int Server::init()
{
    listener = {AF_INET, SOCK_STREAM, IPPROTO_TCP};
    if (listener.listen(port) < 0) {
        return -1;
    };
    return 0;
}

void Server::loop()
{
    while(1) {
        net::Socket client;
        if(listener.accept(&client) < 0) {
            break;
        }
        threads.push_back(std::thread(handle_client, client));
    }

    for (size_t i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
}
