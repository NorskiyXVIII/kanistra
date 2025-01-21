#ifndef __KANISTRE__SOCK__BASE__C__
#define __KANISTRE__SOCK__BASE__C__


#ifdef linux
        #include <sys/socket.h>
        #include <netinet/in.h>
        #include <arpa/inet.h>
        #include <unistd.h>
        #include <netdb.h>
#else
        #include <winsock2.h>
        #include <ws2tcpip.h>
#endif

size_t getIndex(const char* str, const char sym) {
    int i = 0;
    while (str[i] != sym) i++;

    return i;
}

#define get(BUFFER) fgets(BUFFER, sizeof(BUFFER), stdin); \
BUFFER[getIndex(BUFFER, '\n')] = '\0';



#if __cplusplus
extern "C" {
#endif


void kansock_close(int sock);

void printf_ip(struct in_addr ip, char ind) { printf("%d%c%d%c%d%c%d", ip.S_un.S_un_b.s_b1, ind, ip.S_un.S_un_b.s_b2, ind, ip.S_un.S_un_b.s_b3, ind, ip.S_un.S_un_b.s_b4); }
void printfn_ip(struct in_addr ip, char ind) { printf_ip(ip, ind); printf("\n"); }
void print_ip(struct in_addr ip) { printf_ip(ip, '.'); }
void printn_ip(struct in_addr ip) { printfn_ip(ip, '.'); }

void printf_port(int port, char ind) { printf("%c%d", ind, htons(port)); }
void printfn_port(int port, char ind) { printf_port(port, ind); printf("\n"); }
void print_port(int port) { printf_port(port, ':'); }
void printn_port(int port) { printfn_port(port, ':'); }

void printf_ip_port(struct in_addr ip, char ind1, int port, char ind2) { printf_ip(ip, ind1); printf_port(port, ind2); }
void printfn_ip_port(struct in_addr ip, char ind1, int port, char ind2) { printf_ip(ip, ind1); printf_port(port, ind2); printf("\n"); }
void print_ip_port(struct in_addr ip, int port) { print_ip(ip); print_port(port); }
void printn_ip_port(struct in_addr ip, int port) { print_ip(ip); printn_port(port); }

#ifdef __cplusplus
}
#endif

#endif