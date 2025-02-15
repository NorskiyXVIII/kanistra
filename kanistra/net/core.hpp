#pragma once

#include "socket.h"


namespace kanistra {
    namespace net {
        extern "C" {
            void close(int sock) { kansock_close(sock); }

            void printf_ip(::in_addr ip, char ind)  { kansock_printf_ip(ip, ind); }
            void printfn_ip(::in_addr ip, char ind) { kansock_printfn_ip(ip, ind); }
            void print_ip(::in_addr ip)             { kansock_print_ip(ip); }
            void printn_ip(::in_addr ip)            { kansock_printn_ip(ip); }

            void printf_port(int port, char ind)  { kansock_printf_port(port, ind); }
            void printfn_port(int port, char ind) { kansock_printfn_port(port, ind); }
            void print_port(int port)             { kansock_print_port(port); }
            void printn_port(int port)            { kansock_printn_port(port); }

            void printf_ip_port(::in_addr ip, char ind1, int port, char ind2)  { kansock_printf_ip_port(ip, ind1, port, ind2); }
            void printfn_ip_port(::in_addr ip, char ind1, int port, char ind2) { kansock_printfn_ip_port(ip, ind1, port, ind2); }
            void print_ip_port(::in_addr ip, int port)                         { kansock_print_ip_port(ip, port); }
            void printn(::in_addr ip, int port)                                { kansock_printn_ip_port(ip, port); }

            int create_socket(int domain, int type, int protocol) { return kansock_create_socket(domain, type, protocol); }
            int create_socketIPv4(int type, int protocol)         { return kansock_create_socketIPv4(type, protocol); }
            int create_socketIPv6(int type, int protocol)         { return kansock_create_socketIPv6(type, protocol); }
        }

        

    
    }
}

#include "core_hpp/socket.hpp"