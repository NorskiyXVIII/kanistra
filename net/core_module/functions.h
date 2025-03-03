#pragma once

#include "../share.h"
#include "../core.h"

namespace kanistra {
    namespace net {
        bool is_bigend();
        type::u16 htons(type::u16 val);
    }
}

#include "functions.cpp"