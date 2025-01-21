#pragma once

#include "socket.h"

namespace kanistra {
    namespace net {
        void close(int sock) { kansock_close(sock); }
    }
}