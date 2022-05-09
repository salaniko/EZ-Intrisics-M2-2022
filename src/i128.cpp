#include <iostream>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include "i128.hpp"


using namespace std;


void I128::print_16b(i128 _reg, int _base)
{
    uint8_t val[16];
    memcpy(val, &_reg, sizeof(val));

    switch (_base)
    {
        case 10:
            printf("Numerical: %i %i %i %i | %i %i %i %i | %i %i %i %i | %i %i %i %i\n",
                val[0], val[1], val[2], val[3], val[4], val[5], val[6], val[7], 
                val[8], val[9], val[10], val[11], val[12], val[13], val[14], val[15]);
            break;
        
        case 16:
            printf("Hexadecimal: %#x %#x %#x %#x | %#x %#x %#x %#x | %#x %#x %#x %#x | %#x %#x %#x %#x\n",
                val[0], val[1], val[2], val[3], val[4], val[5], val[6], val[7], 
                val[8], val[9], val[10], val[11], val[12], val[13], val[14], val[15]);
            break;
        
        default:
            break;
    }
}

void I128::print_8w(i128 _reg, int _base)
{
    uint16_t val[8];
    memcpy(val, &_reg, sizeof(val));

    switch (_base)
    {
        case 10:
            printf("Numerical: %i %i %i %i %i %i %i %i\n",
                val[0], val[1], val[2], val[3], val[4], val[5], val[6], val[7]);
            break;
        
        case 16:
            printf("Hexadecimal: %#x %#x %#x %#x %#x %#x %#x %#x\n",
                val[0], val[1], val[2], val[3], val[4], val[5], val[6], val[7]);
            break;
        
        default:
            break;
    }
}

void I128::print_4d(i128 _reg, int _base)
{
    uint32_t val[4];
    memcpy(val, &_reg, sizeof(val));

    switch (_base)
    {
        case 10:
            printf("Numerical: %i %i %i %i\n",
                val[0], val[1], val[2], val[3]);
            break;
        
        case 16:
            printf("Hexadecimal: %#x %#x %#x %#x\n",
                val[0], val[1], val[2], val[3]);
            break;
        
        default:
            break;
    }
}
        
void I128::print_2q(i128 _reg, int _base)
{
    uint64_t val[2];
    memcpy(val, &_reg, sizeof(val));

    switch (_base)
    {
        case 10:
            printf("Numerical: %i %i\n",
                val[0], val[1]);
            break;
        
        case 16:
            printf("Hexadecimal: %#x %#x\n",
                val[0], val[1]);
            break;
        
        default:
            break;
    }    
}
