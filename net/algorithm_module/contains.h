#pragma once
#include "../core.h"

namespace kanistra {
    namespace algorithm {
        bool contains(const std::string& str, const std::string& cont) {
            return str.find(cont) == std::string::npos;
        }
    }
}