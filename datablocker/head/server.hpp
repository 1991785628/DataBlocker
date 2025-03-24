#ifndef SERVER_HPP
#define SERVER_HPP

#include <boost/asio.hpp>
#include <atomic>

using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_context& io_context, short port);

private:
    void accept();
    
    tcp::acceptor acceptor_;
    std::atomic<int> current_connections_{0};
};

#endif
