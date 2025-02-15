#include <iostream>
#include "../../core.hpp"

typedef char byteinet;
void handleClient(int conn) {
    byteinet server_buffer[1024];
    byteinet client_buffer[1024];

    while (1) {

        recv(conn, server_buffer, sizeof(server_buffer), 0);
        printf("[CLIENT]: %s\n", server_buffer);
        if (strcmp(server_buffer, "[EXIT]") == 0) {
            printf("Connection aborted from sender!\n");
            break;
        }

        printf(">>> ");
        kansock_get(client_buffer);
        send(conn, client_buffer, strlen(client_buffer), 0);
        if (strcmp(client_buffer, "[EXIT]") == 0) {
            printf("Connection aborted from reciever!\n");
            break;
        }
    }

}

int main() {
    using namespace kanistra;
    WSADATA wsa;
    WSAStartup(MAKEWORD(2,2), &wsa);


    net::socket server{AF_INET, SOCK_STREAM, IPPROTO_TCP};

    sockaddr_in sockaddrin = {};
    inet_pton(AF_INET, "127.0.0.1", &(sockaddrin.sin_addr));
    sockaddrin.sin_port = htons(8812);
    sockaddrin.sin_family = AF_INET;

    bind(server, (sockaddr*)&sockaddrin, sizeof(sockaddr));
    listen(server, SOMAXCONN);

    sockaddr* remote_addr;
    int remote_len = sizeof(sockaddr);
    net::socket conn = accept(server, remote_addr, &remote_len);

    handleClient(conn);

    net::close(conn);
    WSACleanup();
    return 0;
}