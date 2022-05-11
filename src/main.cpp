#include <iostream>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <sys/time.h>

#include "i128.hpp"
#include "f128.hpp"
#include "d128.hpp"

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

}

void test_d128()
{

}

int main(int argc, char const *argv[])
{   
    test_i128();

    return 0;
}
