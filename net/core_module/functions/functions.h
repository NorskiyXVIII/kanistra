#pragma once

#include "../share.h"
#include "../core.h"

namespace kanistra {
    namespace net {
        bool is_bigend();
        type::u16 htons(type::u16 val);

        type::socketd create_socket(net::ip_type domain, net::sntype type, net::snproto proto);

        
    }
}

#include "functions.cpp"