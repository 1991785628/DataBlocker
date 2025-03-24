#include "server.hpp"
#include "session.hpp"
#include <iostream>

const size_t MAX_CONNECTION = 100;  //可自定义最大连接数量

Server::Server(boost::asio::io_context& io_context, short port)
    : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    accept();
}

void Server::accept() {
    acceptor_.async_accept(
        [this](boost::system::error_code ec, tcp::socket socket) {
            if (!ec) {
                if (current_connections_ < MAX_CONNECTION) {
                    std::make_shared<Session>(std::move(socket))->start();
                    current_connections_++;
                    std::cout << "New connection accepted. Total: " 
                              << current_connections_ << "\n";
                } else {
                    std::cout << "Connection refused: maximum limit reached\n";
                }
            }
            accept();
        });
}
