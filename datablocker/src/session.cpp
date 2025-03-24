#include "session.hpp"
#include <iostream>

const size_t TRAFFIC_THRESHOLD = 1024 * 1024; // 1MB 自定义限制数据流大小

Session::Session(tcp::socket socket) : socket_(std::move(socket)) {}

void Session::start() {
    read();
}

void Session::read() {
    auto self(shared_from_this());
    socket_.async_read_some(boost::asio::buffer(data_, max_length),
        [this, self](boost::system::error_code ec, size_t length) {
            if (!ec) {
                total_received_ += length;
                
                if (total_received_ > TRAFFIC_THRESHOLD) {
                    std::cout << "Connection exceeded traffic limit. Closing...\n";
                    socket_.close();
                    return;
                }
                
                read();
            } else {
                socket_.close();
            }
        });
}
