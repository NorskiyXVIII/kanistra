#ifndef __KANISTRE__SOCK__BASE__C__
#define __KANISTRE__SOCK__BASE__C__

#include <stdio.h>


#ifdef _WIN32
        #include <winsock2.h>
        #include <ws2tcpip.h>
#elif defined(__linux__)
        #include <sys/socket.h>
        #include <netinet/in.h>
        #include <arpa/inet.h>
        #include <unistd.h>
        #include <netdb.h>
#endif

size_t kansock_getIndex(const char* str, const char sym);

#if __cplusplus
extern "C" {
#endif


void kansock_close(int sock);


void kansock_printf_ip(struct in_addr ip, char ind); 
void kansock_printfn_ip(struct in_addr ip, char ind);
void kansock_print_ip(struct in_addr ip);
void kansock_printn_ip(struct in_addr ip);

void kansock_printf_port(int port, char ind);
void kansock_printfn_port(int port, char ind);
void kansock_print_port(int port);
void kansock_printn_port(int port);

void kansock_printf_ip_port(struct in_addr ip, char ind1, int port, char ind2);
void kansock_printfn_ip_port(struct in_addr ip, char ind1, int port, char ind2);
void kansock_print_ip_port(struct in_addr ip, int port);
void kansock_printn_ip_port(struct in_addr ip, int port);

#ifdef __cplusplus
}
#endif

#define kansock_get(BUFFER) fgets(BUFFER, sizeof(BUFFER), stdin); \
BUFFER[kansock_getIndex(BUFFER, '\n')] = '\0';

#define kansock_getsz(BUFFER, SZ) fgets(BUFFER, SZ, stdin); \
BUFFER[kansock_getIndex(BUFFER, '\n')] = '\0';

int kansock_lconnect(int conn, struct addrinfo* remote_addr, void(*print_ip_and_port)(struct in_addr, int));
int kansock_connect(int conn, struct addrinfo* remote_addr);

//@ getnetaddr
//@ void* ip - получаем ip адрес
//@ void* mask - маска подсети
//@ void* net_addr - в net_addr получаем ip адрес подсети
void kansock_getnetaddr(void* ip, void* mask, void* net_addr);

//@ gethostaddr
//@ void* ip - получаем ip адрес0
//@ void* mask - маска подсети
//@ void* net_addr - в net_addr получаем ip адрес узла
void kansock_gethostaddr(void* ip, void* mask, void* host_addr);

//@ isvalidmask
//@ возвращает 0, если маска невалидна
//@ иначе возвращает 1
int kansock_isvalidmask(void* val);

//@ netbits
//@ возвращает число бит, которые побитово слияются с маской
int kansock_netbits(void* val);

int kansock_create_socket(int domain, int type, int protocol);
int kansock_create_socketIPv4(int type, int protocol);
int kansock_create_socketIPv6(int type, int protocol);

#include "socket.c"

#endif
