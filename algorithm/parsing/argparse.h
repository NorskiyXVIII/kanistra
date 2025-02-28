#pragma once

#include <vector>
#include <string>
#include <iostream>

namespace kanistra {
    namespace algorithm {
        std::vector<std::string> parse(int argc, char **argv);
    
        void print(const int argc, const char **argv);
    }
}

#include "argparse.cpp"