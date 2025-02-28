#pragma once

#include <string>
#include <cstring>

namespace kanistra {
    namespace algorithm {
        
        bool contains(const std::string& str, const std::string& cont);
        bool contains(const char* str, const char* cont);

    }
}

#include "contains.cpp"