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
        struct sockaddr_in* rem = (struct sockaddr_in*)remote_sockaddr;
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

int kansock_netbits(void* val) {
    int mask = *(int*)val;
    int current_bit;
    int zero_bits = 0;

    for (int i = 0; i < 32; i++) {
        current_bit = (mask >> i) & 1;

        if (current_bit == 0) zero_bits++;   
    }

    return 32 - zero_bits;
}

int kansock_isvalidmask(void* val) {
    int mask = *(int*)val;

    mask = ntohl(mask); // net -> host[тип long]

    if ((mask >> 31) & 1 == 0) return 0; // крайний левый бит не может быть равен 0

    int current_bit; // текущий бит
    int prev_bit = 0; // бит справа от текущего

    for (int i = 0; i < 31; i++) {
        current_bit = (mask >> i) & 1;

        if (current_bit < prev_bit) return 0; // текщий бит не может быть меньше предыдущего
        prev_bit = current_bit;
    }

    return 1;
}

void kansock_gethostaddr(void* ip, void* mask, void* host_addr) {
    int* arg1 = (int*)ip;
    int* arg2 = (int*)mask;
    int* res  = (int*)host_addr;
    *res = (*arg1) & (~(*arg2));
}

void kansock_getnetaddr(void* ip, void* mask, void* net_addr) {
    int* arg1 = (int*)ip;
    int* arg2 = (int*)mask;
    int* res  = (int*)net_addr;
    *res = (*arg1) & (*arg2);
}

int kansock_create_socket(int domain, int type, int protocol) {
    return socket(domain, type, protocol);
}
int kansock_create_socketIPv4(int type, int protocol) {
    return socket(AF_INET, type, protocol);
}
int kansock_create_socketIPv6(int type, int protocol) {
    return socket(AF_INET6, type, protocol);
}
