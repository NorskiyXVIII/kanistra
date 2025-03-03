#include "ip.h"
#include <iostream>

kanistra::net::ip_type::ip_type(const std::string& ip_addr) {
    if (kanistra::algorithm::contains(ip_addr, "::")) type = ip_enum_type::V6;
    else type = ip_enum_type::V4;
}
kanistra::net::ip_type::ip_type(const ip_type& ip_addr) {
    type = ip_addr.type;
}
kanistra::net::ip_type::ip_type(const int family) {
    *this = family;
}
kanistra::net::ip_type::ip_type(const char* family) {
    *this = family;
}

kanistra::net::ip_type kanistra::net::ip_type::operator=(const int family) {
    type = (kanistra::net::ip_enum_type)family;
    return *this;
}

kanistra::net::ip_type kanistra::net::ip_type::operator=(const ip_type& ip_addr) {
    type = ip_addr.type;
    return *this;
}

kanistra::net::ip_type kanistra::net::ip_type::operator=(const std::string& ip_addr) {
    if (kanistra::algorithm::contains(ip_addr, "::")) type = ip_enum_type::V6;
    else type = ip_enum_type::V4;
    return *this;
}

kanistra::net::ip_type kanistra::net::ip_type::operator=(const char* ip_addr) {
    this->operator=(std::string(ip_addr));
    return *this;
}


kanistra::net::ip_type::operator std::string() {
    if (type == ip_enum_type::V4) return "IPv4";
    else return "IPv6";
}

kanistra::net::ip_type::operator int() {
    return (int)type;
}

kanistra::net::ip::ip(const in_addr& ip_addr) {
    this->set_ip(ip_addr);
}
kanistra::net::ip::ip(const ip& ip_addr) {
    this->set_ip(ip_addr);
}
kanistra::net::ip::ip(const std::string& ip_addr) {
    this->set_ip(ip_addr);
}
kanistra::net::ip::ip(const char* ip_addr) {
    this->set_ip(ip_addr);
}

void kanistra::net::ip::set_ip(const in_addr& ip_addr) {
    this->ip_addr = ip_addr;
}
void kanistra::net::ip::set_ip(const ip& ip_addr) {
    this->ip_addr = ip_addr.ip_addr;
}
void kanistra::net::ip::set_ip(const std::string& ip_addr) {
    if (kanistra::algorithm::contains(ip_addr, "::")) family = AF_INET;
    else family = AF_INET6;
    inet_pton(family, ip_addr.c_str(), &(this->ip_addr));
}

void kanistra::net::ip::set_ip(const char* ip_addr) {
    set_ip(std::string(ip_addr));
}

kanistra::net::ip_type kanistra::net::ip::get_family() const {
    return this->family;
}

in_addr kanistra::net::ip::get_ip() const {
    return this->ip_addr;
}

kanistra::net::ip::operator in_addr() {
    return this->ip_addr;
}

kanistra::net::ip kanistra::net::ip::operator=(const in_addr& ip_addr) {
    this->set_ip(ip_addr);
    return *this;
}
kanistra::net::ip kanistra::net::ip::operator=(const kanistra::net::ip& ip_addr) {
    this->set_ip(ip_addr);
    return *this;
}
kanistra::net::ip kanistra::net::ip::operator=(const std::string& ip_addr) {
    this->set_ip(ip_addr);
    return *this;
}
kanistra::net::ip kanistra::net::ip::operator=(const char* ip_addr) {
    this->set_ip(ip_addr);
    return *this;
}