#include <iostream>
#include "f128.hpp"

using namespace std;

void F128::print_4f(f128 _reg, int _base)
{
    uint64_t val[4];
    memcpy(val, &_reg, sizeof(val));

    switch (_base)
    {
        case 2:
            int a;
            printf("Binary: ");
            for(int i=0; i<4; i++)
            {
                for (int j = 16; j >= 0; j--)
                {
                    a = val[i] >> j;

                    if (a & 1)
                        printf("1");
                    else
                        printf("0");
                }
                printf("  ");
            }
            printf("\n");
            break;

        case 10:
            printf("Numerical: %f %f %f %f\n",
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
