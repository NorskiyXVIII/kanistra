#include "../../core.h"
#include <iostream>

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    using namespace kanistra;

    net::ip ip_addr{"127.0.0.1"};
    std::cout << ip_addr.get_family() << std::endl;
    ip_addr = "::1";
    std::cout << ip_addr.get_family() << std::endl;


    WSACleanup();
    return 0;
}