#include <iostream>
#include "i128.hpp"

#ifndef __cplusplus
#include <stdalign.h>   //C11 defines _Alignas().  This header defines alignas()
#endif

using namespace std;

void I128::setBase(int base) 
{
    base = base;
}

void I128::print_16b(i128 reg)
{
    switch(base)
    {
        case '16':
            printf("Registre SSE (128 bits) en HEXADECIMALE :\n"
                    "%x %x %x %x | %x %x %x %x | %x %x %x %x | %x %x %x %x\n",
                    reg[0], reg[1],  reg[2],  reg[3],  reg[4],  reg[5],  reg[6],  reg[7], reg[8], reg[9], reg[10], reg[11], reg[12], reg[13], reg[14], reg[15]);

            break;
        case '10':
            printf("Registre SSE (128 bits) en DECIMAL :");
            break;
        case '2':
            printf("Registre SSE (128 bits) en BINAIRE :");
            break;
        default:
            printf("Registre SSE (128 bits) en HEXADECIMALE par défaut :\n"
                   "%x %x %x %x | %x %x %x %x | %x %x %x %x | %x %x %x %x\n",
                   reg[0], reg[1], reg[2], reg[3], reg[4], reg[5], reg[6], reg[7], reg[8], reg[9], reg[10], reg[11], reg[12], reg[13], reg[14], reg[15]);
            break;
    }
}

void I128::print_8w(i128 reg)
{

}

void I128::print_4d(i128 reg)
{

}
        
void I128::print_2q(i128 reg)
{
            
}
