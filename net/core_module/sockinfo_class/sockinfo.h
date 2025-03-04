#pragma once

#include "../share.h"
#include "../core.h"

namespace kanistra {
    namespace net {
        class sockinfo {
        private:
            ip           addr;
            type::u16    port;
            ip_type      family;
        public:
            sockinfo(ip addr, type::u16 port, ip_type family);
            sockinfo(ip addr, type::u16 port);
            sockinfo() {}

            bool operator==(const sockaddr_in& addr);

            ip        get_addr();
            type::u16 get_port();
            ip_type   get_family();

            void set_addr(const ip& addr);
            void set_port(const type::u16 port);
            void set_family(const ip_type& family);

            sockaddr    as_sockaddr();
            sockaddr_in as_sockaddrin();

            operator sockaddr();
            operator sockaddr_in();
        };
    }
}

#include "sockinfo.cpp"