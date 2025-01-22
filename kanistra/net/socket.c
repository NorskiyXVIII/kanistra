#include "socket.h"


void kansock_close(int sock) {
    #ifdef linux
        close(sock);
    #else
        closesocket(sock);
    #endif
}
