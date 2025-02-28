#include "stringparse.h"

#include <iostream>

bool kanistra::algorithm::contains(const std::string& str, const std::string& cont) {
    if (cont.size() > str.size()) return false;
    int str_sz = str.size() - 1;
    int cont_sz = cont.size();

    for (int i = 0; i < str_sz; i++) {
        if (str[i] == cont[0]) {
            int cont_chars = 0;
            while(str[i + cont_chars] == cont[cont_chars] && cont_chars < cont_sz) cont_chars++;

            if (cont_chars == cont_sz) return true;
        }
    }
    return false;
}
bool kanistra::algorithm::contains(const char* str, const char* cont) {
    for (int i = 0; i < strlen(str); i++) if (str[i] == ':' && str[i + 1] == ':') return true;
    return false;
}