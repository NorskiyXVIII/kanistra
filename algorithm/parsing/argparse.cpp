#include "argparse.h"


std::vector<std::string> kanistra::algorithm::parse(int argc, char **argv) {
    if (argc == 0) return {};
    
    std::vector<std::string> vec;
    for (int i = 1; i < argc; i++) vec.push_back(argv[i]);

    return vec;
}

void kanistra::algorithm::print(const int argc, const char **argv) {
    if (argc == 1) { 
        std::printf("ARGC == 0[%s]\n", argv[0]);
        return;
    }
    for (int i = 1; i < argc; i++) std::printf("[%d] = %s\n", i, argv[i]);
}