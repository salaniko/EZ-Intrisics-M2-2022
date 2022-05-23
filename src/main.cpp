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

double getCurrentTime()
{
    struct timeval curr;
    struct timezone tz;
    gettimeofday(&curr, &tz);
    double tmp = static_cast<double>(curr.tv_sec) * static_cast<double>(1000000)
             + static_cast<double>(curr.tv_usec);
    return tmp*1e-6;
}

void test_i128(int vector_size)
{
    srand48(0);
    double e, s;
    int32_t *a, *b, *c;
    int32_t *pA, *pB, *pC;
    i128 rA, rB, rC;

    a = (int32_t*) sse_malloc(vector_size*sizeof(int32_t), 32);
    b = (int32_t*) sse_malloc(vector_size*sizeof(int32_t), 32);
    c = (int32_t*) sse_malloc(vector_size*sizeof(int32_t), 32);

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

    sse_free(a);
    sse_free(b);
    sse_free(c);
}

void test_i128_old(int vector_size){
    srand48(0);
    double e, s;
    int32_t *a, *b, *c;
    int32_t *pA, *pB, *pC;
    __m128i rA, rB, rC;

    a = (int32_t*) _mm_malloc(vector_size*sizeof(int32_t), 32);
    b = (int32_t*) _mm_malloc(vector_size*sizeof(int32_t), 32);
    c = (int32_t*) _mm_malloc(vector_size*sizeof(int32_t), 32);

    for (int i=0; i<vector_size; i++)
    {
        a[i] = fabs(mrand48());
        b[i] = fabs(mrand48());
    }

    pA = a; pB = b, pC = c;

    s = getCurrentTime();
    for (int i=0; i<vector_size; i+=4)
    {
        rA = _mm_load_si128((__m128i*)&pA[i]);
        rB = _mm_load_si128((__m128i*)&pB[i]);
        rC = _mm_add_epi32(rA, rB);
        _mm_store_si128((__m128i*)&pC, rC);
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

void test_f128(int vector_size)
{
    srand48(0);
    double e, s;
    float *a, *b;
    float *pA, *pB;
    f128 rA, rB;

    a = (float*) sse_malloc(vector_size*sizeof(float), 32);
    b = (float*) sse_malloc(vector_size*sizeof(float), 32);

    for (int i=0; i<vector_size; i++)
    {
        a[i] = fabs(drand48());
    }

    pA = a; pB = b;

    s = getCurrentTime();
    for (int i=0; i<vector_size; i+=4)
    {
        rA   = f128_lda(pA);
        rB   = f128_sqrt_4f(f128_sqrt_4f(f128_sqrt_4f(rA)));
        f128_storea(pB,rB);
        pA += 4;
        pB += 4;
    }
    e = getCurrentTime();

    cout << "Test f128: " << (e-s)*1000 << " ms\n";

    sse_free(a);
    sse_free(b);
}

void test_d128(int vector_size)
{
    srand48(0);
    double e, s;
    double *a, *b, *c;
    double *pA, *pB, *pC;
    d128 rA, rB, rC;

    a = (double*) sse_malloc(vector_size*sizeof(double), 64);
    b = (double*) sse_malloc(vector_size*sizeof(double), 64);
    c = (double*) sse_malloc(vector_size*sizeof(double), 64);

    for (int i=0; i<vector_size; i++)
    {
        a[i] = fabs(drand48());
        b[i] = fabs(drand48());
    }

    pA = a; pB = b; pC = c;

    s = getCurrentTime();

    for (int i=0; i<vector_size; i+=2)
    {
        rA   = d128_lda(pA);
        rB   = d128_lda(pB);
        rC   = d128_div_2d(rA, rB);
        d128_storea(pC,rC);
        pA += 2;
        pB += 2;
    }
    e = getCurrentTime();

    cout << "Test d128: " << (e-s)*1000 << " ms\n";

    sse_free(a);
    sse_free(b);
    sse_free(c);
}

int main(int argc, char const *argv[])
{   
    const int vector_size = 10000000;

    printf("TEST SUR LES ENTIER :\n");
    test_i128(vector_size);

    printf("TEST SUR LES ENTIER OLD :\n");
    test_i128_old(vector_size);

    printf("TEST SUR LES FLOTTANTS :\n");
    test_f128(vector_size);

    printf("TEST SUR LES DOUBLES :\n");
    test_d128(vector_size);

    return 0;
}