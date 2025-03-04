#include <iostream>
#include "../../core.h"

void print_sockaddr(const sockaddr_in& sck) {
    std::cout << sck.sin_addr.S_un.S_addr << std::endl;
    std::cout << sck.sin_port << std::endl;
    std::cout << sck.sin_family << std::endl;
}

int main() {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    using namespace kanistra;
    net::sockinfo sck{"::1", 8391};
    sockaddr_in sc = {0};
    inet_pton(AF_INET6, "::1", &sc.sin_addr);
    sc.sin_port = htons(8391);
    sc.sin_family = AF_INET6;



    std::cout << (sck == sc) << std::endl;
    std::cout << "----------SC" << std::endl;
    print_sockaddr(sc);
    std::cout << "----------SC" << std::endl;
    print_sockaddr(sck);

    WSACleanup();
}