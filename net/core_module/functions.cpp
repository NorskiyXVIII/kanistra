#include "functions.h"

bool kanistra::net::is_bigend() {
    kanistra::type::u16   test = 0x0102;
    kanistra::type::byte* test_ptr = (kanistra::type::byte*)&test;

    return (test_ptr[0] == 0x01);
}

kanistra::type::u16 kanistra::net::htons(kanistra::type::u16 val) {
    if (kanistra::net::is_bigend()) { std::printf("returned;"); return val; }

    return ::htons(val);
}