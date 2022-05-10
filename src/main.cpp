#include "i128.hpp"
#include "d128.hpp"
#include <iostream>
#include <stdint.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /*
    i128 reg;
    reg = i128_set_b(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);

    I128::print_16b(reg, 10);
    I128::print_16b(reg, 16);*/

    //Creation d'un objet
    D128 reg_double;

    d128 reg2;
    reg2 = d128_set(1.5, 0.8);

    reg_double.print_2d(reg2,16);

    return 0;
}
