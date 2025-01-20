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

#if __cplusplus
extern "C" {
#endif


void kansock_close(int sock);

#if __cplusplus
}
#endif

#endif