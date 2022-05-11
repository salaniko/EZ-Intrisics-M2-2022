#include <iostream>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <vector>

#include "i128.hpp"
#include "f128.hpp"
#include "d128.hpp"

using namespace std;


void test_i128()
{
    srand48(0);
    int32_t *a, *b, *c;
    int32_t *pA, *pB, *pC;
    i128 rA, rB, rC;

    const int vector_size = 1000000;

    a = (int32_t*) _mm_malloc (vector_size*sizeof(int32_t), 32);
    b = (int32_t*) _mm_malloc (vector_size*sizeof(int32_t), 32);
    c = (int32_t*) _mm_malloc (vector_size*sizeof(int32_t), 32);

    for (int i=0; i<vector_size; i++)
    {
        a[i] = fabs(mrand48());
        b[i] = fabs(mrand48());
    }

    pA = a; pB = b, pC = c;

    for (int i=0; i<vector_size; i+=4)
    {
        rA = i128_lda(pA);
        rB = i128_lda(pB);
        rC = i128_add_d(rA, rB);
        i128_storea(pC, rC);
        pA += 4;
        pB += 4;
        pC += 4;
    }
}

void test_f128()
{

}

void test_d128()
{

}

int main(int argc, char const *argv[])
{   
    test_i128();

    return 0;
}
