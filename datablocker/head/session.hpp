#ifndef SESSION_HPP
#define SESSION_HPP

#include <boost/asio.hpp>
#include <memory>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket);
    void start();

private:
    void read();
    
    tcp::socket socket_;
    enum { max_length = 4096 };
    char data_[max_length];
    size_t total_received_ = 0;
};

#endif
