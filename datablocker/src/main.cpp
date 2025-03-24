#include "server.hpp"
#include <boost/asio.hpp>
#include <iostream>

int main() {
    try {
        boost::asio::io_context io_context;
        Server server(io_context, 8080);  //默认为8080端口
        std::cout << "Server started on port 8080\n";
        io_context.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
