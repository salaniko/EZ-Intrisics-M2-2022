#include <iostream>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <sys/time.h>

#include "i128.hpp"
#include "f128.hpp"
#include "d128.hpp"
#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

double getCurrentTime(){
  struct timeval curr;
  struct timezone tz;
  gettimeofday(&curr, &tz);
  double tmp = static_cast<double>(curr.tv_sec) * static_cast<double>(1000000)
             + static_cast<double>(curr.tv_usec);
  return tmp*1e-6;
}

void test_i128()
{
    srand48(0);
    double e, s;
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

    s = getCurrentTime();
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
    e = getCurrentTime();

    cout << "Test i128: " << (e-s)*1000 << " ms\n";

    _mm_free(a);
    _mm_free(b);
    _mm_free(c);

}

void test_f128()
{
    srand48(0);
    double e, s;
    float *a, *b;
    float *pA, *pB;
    f128 rA, rB;

    const int vector_size = 1000000;

    a = (float*) _mm_malloc (vector_size*sizeof(float), 32);
    b = (float*) _mm_malloc (vector_size*sizeof(float), 32);

    for (int i=0; i<vector_size; i++)
    {
        a[i] = fabs(drand48());
    }

    pA = a; pB = b;

    s = getCurrentTime();
    for (int i=0; i<vector_size; i+=4)
    {
        rA   = f128_lda(pA);
        rB   = _mm_sqrt_ps(_mm_sqrt_ps(_mm_sqrt_ps(rA)));
        f128_storea(pB,rB);
        pA += 4;
        pB += 4;
    }
    e = getCurrentTime();

    cout << "Test f128: " << (e-s)*1000 << " ms\n";

    _mm_free(a);
    _mm_free(b);

}

void test_d128()
{

}

int main(int argc, char const *argv[])
{   
    test_i128();
    test_f128();

    /*
    //Registre avec 2 doubles (64 bits)
    d128 regD;
    regD = d128_set_2d(1.5, 0.8);

    D128::print_2d(regD,2);
    D128::print_2d(regD,10);
    D128::print_2d(regD,16);

    //Registre avec 4 floats (32 bits)
    f128 regF;
    regF = f128_set_4f(0.8f, 0.5f, 0.5f, 0.5f);

    F128::print_4f(regF,2);
    F128::print_4f(regF,10);
    F128::print_4f(regF,16);*/

    return 0;
}