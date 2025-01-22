#include "socket.h"

size_t getIndex(const char* str, const char sym) {
    int i = 0;
    while (str[i] != sym) i++;

    return i;
}

#define get(BUFFER) fgets(BUFFER, sizeof(BUFFER), stdin); \
BUFFER[getIndex(BUFFER, '\n')] = '\0';

void kansock_close(int sock) {
    #ifdef linux
        close(sock);
    #else
        closesocket(sock);
    #endif
}
