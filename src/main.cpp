#include "i128.hpp"
#include "f128.hpp"
#include "d128.hpp"


int main(int argc, char const *argv[])
{   
    // Registre avec 16 Bytes (Octets) d'entiers
    i128 reg_b;
    reg_b = i128_set_b(0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);

    I128::print_16b(reg_b, 2);
    I128::print_16b(reg_b, 10);
    I128::print_16b(reg_b, 16);

    // Registre avec 4 double word (32 bits) d'entiers
    i128 reg_d1;
    reg_d1 = i128_set_d(100, 200, 300, 400);

    I128::print_4d(reg_d1, 2);
    I128::print_4d(reg_d1, 10);
    I128::print_4d(reg_d1, 16);

    i128 reg_d2;
    reg_d2 = i128_set_d(10, 10, 10, 10);

    i128 reg_add = i128_add_d( reg_d1, reg_d2 );
    I128::print_4d(reg_add, 10);

    return 0;
}
