#include <iostream>
#include <boost/asio.hpp>

// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/overview/core/basics.html
// https://www.bogotobogo.com/cplusplus/sockets_server_client.php
int main() {

    std::cout << "HI" << std::endl;

    boost::asio::io_context io_context;
    boost::asio::ip::tcp::socket socket(io_context);
    boost::system::error_code ec;
    socket.connect(server_endpoint, ec);
    std::cout << ec << std::endl;
    return 0;
}
