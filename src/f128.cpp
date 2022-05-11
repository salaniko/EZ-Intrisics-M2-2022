#include <iostream>
#include "f128.hpp"
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdalign.h>

using namespace std;

void F128::print_4f(f128 _reg, int _base)
{
    float val[4];
    memcpy(val, &_reg, sizeof(val));

    switch (_base)
    {
        case 2:
            int a;
            printf("Binary: ");
            for(int i=0; i<4; i++)
            {
                // conversion float en entier
                uint64_t u;
                memcpy(&u, &val[i], sizeof(&val[i]));

                for (int j = 32; j >= 0; j--)
                {
                    a = u >> j;

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
                   val[3], val[2], val[1], val[0]);
            break;

        case 16:
            printf("Hexadecimal: %a %a %a %a\n",
                   val[3], val[2], val[1], val[0]);
            break;

        default:
            break;
    }
}
