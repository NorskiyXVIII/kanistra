#pragma once

#include "../core.hpp"
#include <cstdint>

namespace kanistra {
    namespace net {
        enum class socket_command : int32_t {
            SOCKET_DOES_NOT_EXIST = 0,
            SOCKET_IS_CLIENT = 8000,
            SOCKET_IS_SERVER = 8001
        };

        class socket {
        private:
            int sock;
        public:
            socket(int ai_family, int ai_socktype, int ai_proto) { sock = net::create_socket(ai_family, ai_socktype, ai_proto); }
            socket(const socket& sock)                           { this->sock = sock.sock; }
            socket(const int sock)                               { this->sock = sock; }

            int get_socket() {
                return sock;
            }
            
            void close() { net::close(sock); sock = (int)socket_command::SOCKET_DOES_NOT_EXIST; }
            
            ~socket() {
                if (sock == (int)socket_command::SOCKET_DOES_NOT_EXIST) {
                    return;
                }

                net::close(sock);
            }

            operator int() {
                return this->sock;
            }
        };
    }
}