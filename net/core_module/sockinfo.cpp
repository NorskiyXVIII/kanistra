#include "sockinfo.h"

kanistra::net::sockinfo::sockinfo(kanistra::net::ip addr, kanistra::type::u16 port, kanistra::net::ip_type family) {
    this->addr   = addr;
    this->port   = htons(port);
    this->family = family;
}
kanistra::net::sockinfo::sockinfo(kanistra::net::ip addr, kanistra::type::u16 port) {
    this->addr   = addr;
    this->port   = htons(port);
    this->family = addr.get_family();
}

sockaddr    kanistra::net::sockinfo::as_sockaddr() {
    sockaddr saddr = {0};
    sockaddr_in* saddr_in = (sockaddr_in*)&saddr;
    *saddr_in = as_sockaddrin();

    return saddr;
}
sockaddr_in kanistra::net::sockinfo::as_sockaddrin() {
    sockaddr_in saddr = {0};
    saddr.sin_addr   = this->addr;
    saddr.sin_port   = this->port;
    saddr.sin_family = this->family;

    return saddr;
}

kanistra::net::sockinfo::operator sockaddr() {
    return as_sockaddr();
}
kanistra::net::sockinfo::operator sockaddr_in() {
    return as_sockaddrin();
}

kanistra::net::ip      kanistra::net::sockinfo::get_addr()   { return this->addr; }
kanistra::type::u16    kanistra::net::sockinfo::get_port()   { return this->port; }
kanistra::net::ip_type kanistra::net::sockinfo::get_family() { return this->family; }

void kanistra::net::sockinfo::set_addr(const kanistra::net::ip& addr)          { this->addr = addr; }
void kanistra::net::sockinfo::set_port(const kanistra::type::u16 port)         { this->port = port; }
void kanistra::net::sockinfo::set_family(const kanistra::net::ip_type& family) { this->family = family; }