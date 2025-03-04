/*
    Автор: Norskiy
    TODO:
    Сделать функцию для перевода в std::string
    Сделать кроссплатформенность
    Удалить Херобрина(Важно)

*/


#pragma once

#include "../share.h"
#include "../core.h"

namespace kanistra {
    namespace net {
        enum class ip_enum_type : int {
            V4 = AF_INET,
            V6 = AF_INET6,
            UNKNOWN = 1000
        };

        struct ip_type {
            ip_enum_type type;

            ip_type(const std::string& ip_addr);
            ip_type(const char* ip_addr);
            ip_type(const ip_type& ip_addr);
            ip_type(const int family);
            ip_type() : type{ip_enum_type::UNKNOWN} {}

            ip_type operator=(const int family);
            ip_type operator=(const ip_type& ip_addr);
            ip_type operator=(const std::string& ip_addr);
            ip_type operator=(const char* ip_addr);


            operator std::string();
            operator int();
        };

        class ip {
        private:
            in_addr ip_addr;
            ip_type family;
        public:
            ip(const in_addr& ip_addr);
            ip(const ip& ip_addr);
            ip(const std::string& ip_addr);
            ip(const char* ip_addr);
            ip() {};

            bool operator==(const in_addr& ip_addr);

            ip operator=(const in_addr& ip_addr);
            ip operator=(const ip& ip_addr);
            ip operator=(const std::string& ip_addr);
            ip operator=(const char* ip_addr);

            void set_ip(const in_addr& ip_addr);
            void set_ip(const ip& ip_addr);
            void set_ip(const std::string& ip_addr);
            void set_ip(const char* ip_addr);

            ip_type get_family() const;

            in_addr get_ip() const;

            operator in_addr();
        };
    }
}

#include "ip.cpp"
