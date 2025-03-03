#include <iostream>
#include "../core.h"

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    using namespace kanistra;
    net::sockinfo sck{"127.0.0.1", 8391};
    std::cout << sck.get_family() << " | " << sck.get_port() << std::endl;
    std::cout << sck.as_sockaddrin().sin_family << " + " << sck.as_sockaddrin().sin_port << std::endl;
    sck.set_addr(net::ip({"::1", 80}));
    std::cout << sck.get_family() << " | " << sck.get_port() << std::endl;
    std::cout << sck.as_sockaddrin().sin_family << " + " << sck.as_sockaddrin().sin_port << std::endl;

    WSACleanup();
}