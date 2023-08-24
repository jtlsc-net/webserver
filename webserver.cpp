#include <iostream>
#include <boost/asio.hpp>
#include <unistd.h>

// https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio/overview/core/basics.html
// https://www.bogotobogo.com/cplusplus/sockets_server_client.php
int main() {

    std::cout << "HI" << std::endl;

    boost::asio::io_service ios;
    boost::asio::ip::tcp::acceptor acceptor(ios); 
    boost::asio::ip::tcp::endpoint local_end(boost::asio::ip::address::from_string("127.0.0.1"), 80);
    boost::system::error_code ec;
    acceptor.open(local_end.protocol());
    acceptor.bind(local_end, ec);
    if (ec) std::cout << ec << std::endl;
    else std::cout << "worked" << std::endl;
    acceptor.listen(30);
    boost::asio::ip::tcp::socket sock(ios);
    acceptor.accept(sock);
    return 0;
}
