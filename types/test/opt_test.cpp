#include <iostream>
#include "../types.h"

int main() {
    using namespace kanistra;
    //int z[3] = {10, 20, 30}; 
    type::opt<int[2]> x;
    x.set_val({10, 29});
    std::cout << "START TEST" << std::endl;
    //std::cout << x[0] << " " << x[1] << std::endl;
    std::cout << x[0] << std::endl;
    std::cout << "END TEST" << std::endl;
    return 0;
}
