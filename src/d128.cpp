#include <iostream>
#include "d128.hpp"
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdalign.h>

using namespace std;

void D128::print_2d(d128 _reg, int _base)
{
    double val[2];
    memcpy(val, &_reg, sizeof(val));

    switch (_base)
    {
        case 2:
            int a;

            printf("Binary: ");
            for(int i=0; i<2; i++)
            {
                //conversion du double en entier pour exploiter de bits
                uint64_t u;
                memcpy(&u, &val[i], sizeof(&val[i]));

                for (int j = 64; j >= 0; j--)
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
            printf("Numerical: %f  %f\n",
                   val[1] , val[0]);
            break;

        case 16:
            printf("Hexadecimal: %a %a\n",
                   val[1], val[0]);
            break;

        default:
            break;
    }
}

