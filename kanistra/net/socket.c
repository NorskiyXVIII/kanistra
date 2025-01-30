#include "socket.h"

size_t kansock_getIndex(const char* str, const char sym) {
    int i = 0;
    while (str[i] != sym) i++;

    return i;
}


void kansock_close(int sock) {
    #ifdef _WIN32
        closesocket(sock);
    #else
        close(sock);
    #endif
}



void kansock_printf_ip(struct in_addr ip, char ind) { printf("%d%c%d%c%d%c%d", ip.S_un.S_un_b.s_b1, ind, ip.S_un.S_un_b.s_b2, ind, ip.S_un.S_un_b.s_b3, ind, ip.S_un.S_un_b.s_b4); }
void kansock_printfn_ip(struct in_addr ip, char ind) { kansock_printf_ip(ip, ind); printf("\n"); }
void kansock_print_ip(struct in_addr ip) { kansock_printf_ip(ip, '.'); }
void kansock_printn_ip(struct in_addr ip) { kansock_printfn_ip(ip, '.'); }

void kansock_printf_port(int port, char ind) { printf("%c%d", ind, htons(port)); }
void kansock_printfn_port(int port, char ind) { kansock_printf_port(port, ind); printf("\n"); }
void kansock_print_port(int port) { kansock_printf_port(port, ':'); }
void kansock_printn_port(int port) { kansock_printfn_port(port, ':'); }

void kansock_printf_ip_port(struct in_addr ip, char ind1, int port, char ind2) { kansock_printf_ip(ip, ind1); kansock_printf_port(port, ind2); }
void kansock_printfn_ip_port(struct in_addr ip, char ind1, int port, char ind2) { kansock_printf_ip(ip, ind1); kansock_printf_port(port, ind2); printf("\n"); }
typedef void (kansock_fn_print_two_args)(struct in_addr, int);
void kansock_print_ip_port(struct in_addr ip, int port) { kansock_print_ip(ip); kansock_print_port(port); }
void kansock_printn_ip_port(struct in_addr ip, int port) { kansock_print_ip(ip); kansock_printn_port(port); }


int kansock_lconnect(int conn, struct addrinfo* remote_addr, kansock_fn_print_two_args print_ip_and_port) {
    struct sockaddr* remote_sockaddr = remote_addr->ai_addr;
    int error;

    while (1) {
        error = connect(conn, remote_sockaddr, sizeof(struct sockaddr));
        printf("trying connect to addr[");
        struct sockaddr_in* rem = (struct sockaddr*)remote_sockaddr;
        print_ip_and_port(rem->sin_addr, rem->sin_port);
        printf("]\n");

        if (error == 0) return 0;
        
        remote_addr = remote_addr->ai_next;
        if (remote_addr == NULL) return 1;

        remote_sockaddr = remote_addr->ai_addr;
    }
}

int kansock_connect(int conn, struct addrinfo* remote_addr) {
    struct sockaddr* remote_sockaddr = remote_addr->ai_addr;
    int error;

    while (1) {
        error = connect(conn, remote_sockaddr, sizeof(struct sockaddr));

        if (error == 0) return 0;
        
        remote_addr = remote_addr->ai_next;
        if (remote_addr == NULL) return 1;

        remote_sockaddr = remote_addr->ai_addr;
    }
}
