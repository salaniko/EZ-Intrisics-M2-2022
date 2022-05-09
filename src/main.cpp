#include "i128.hpp"


int main(int argc, char const *argv[])
{
    i128 reg;
    reg = i128_set_b(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);

    I128::print_16b(reg, 10);
    I128::print_16b(reg, 16);

    return 0;
}
