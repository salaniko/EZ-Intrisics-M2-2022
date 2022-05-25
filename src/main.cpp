#include <iostream>
#include <stdint.h>
#include <emmintrin.h>
#include <immintrin.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <sys/time.h>
#include "i128.hpp"
#include "f128.hpp"
#include "d128.hpp"

using namespace std;

void test_printing()
{
    printf("Vecteur SSE - 4 words (entiers)\n");
    i128 regA = i128_set_d(1000, 2000, 3000, 4000);
    I128::print_4d(regA, 2);
    I128::print_4d(regA, 10);
    I128::print_4d(regA, 16);

    printf("\nVecteur SSE - 2 doubles (flotants double précision)\n");
    d128 regB = d128_set_2d(3.14, 12345.6789);
    D128::print_2d(regB, 2);
    D128::print_2d(regB, 10);
    D128::print_2d(regB, 16);
}

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
        rA = i128_loada(pA);
        rB = i128_loada(pB);
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
        rA = _mm_load_si128((const __m128i*)&pA[i]);
        rB = _mm_load_si128((const __m128i*)&pB[i]);
        rC = _mm_add_epi32(rA, rB);
        _mm_store_si128((__m128i*)&pC, rC);
        pA += 4;
        pB += 4;
        pC += 4;
    }
    e = getCurrentTime();

    cout << "Test i128 old: " << (e-s)*1000 << " ms\n";

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
        rA   = f128_loada(pA);
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

void test_f128_old(int vector_size)
{
    srand48(0);
    double e, s;
    float *a, *b;
    float *pA, *pB;
    f128 rA, rB;

    a = (float*) _mm_malloc(vector_size*sizeof(float), 32);
    b = (float*) _mm_malloc(vector_size*sizeof(float), 32);

    for (int i=0; i<vector_size; i++)
    {
        a[i] = fabs(drand48());
    }

    pA = a; pB = b;

    s = getCurrentTime();
    for (int i=0; i<vector_size; i+=4)
    {
        rA   = _mm_load_ps(pA);
        rB   = _mm_sqrt_ps(_mm_sqrt_ps(_mm_sqrt_ps(rA)));
        _mm_store_ps(pB,rB);
        pA += 4;
        pB += 4;
    }
    e = getCurrentTime();

    cout << "Test f128: " << (e-s)*1000 << " ms\n";

    _mm_free(a);
    _mm_free(b);
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
        rA   = d128_loada(pA);
        rB   = d128_loada(pB);
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

void test_d128_old(int vector_size)
{
    srand48(0);
    double e, s;
    double *a, *b, *c;
    double *pA, *pB, *pC;
    d128 rA, rB, rC;

    a = (double*) _mm_malloc(vector_size*sizeof(double), 64);
    b = (double*) _mm_malloc(vector_size*sizeof(double), 64);
    c = (double*) _mm_malloc(vector_size*sizeof(double), 64);

    for (int i=0; i<vector_size; i++)
    {
        a[i] = fabs(drand48());
        b[i] = fabs(drand48());
    }

    pA = a; pB = b; pC = c;

    s = getCurrentTime();

    for (int i=0; i<vector_size; i+=2)
    {
        rA   = _mm_load_pd(pA);
        rB   = _mm_load_pd(pB);
        rC   = _mm_div_pd(rA, rB);
        _mm_store_pd(pC,rC);
        pA += 2;
        pB += 2;
    }
    e = getCurrentTime();

    cout << "Test d128: " << (e-s)*1000 << " ms\n";

    _mm_free(a);
    _mm_free(b);
    _mm_free(c);
}

int main(int argc, char const *argv[])
{
    printf("Tests fonctions d'affichage des vecteurs :\n\n");

    test_printing();

    const int vector_size = 10000000;

    printf("\nTests redéfinitions intrinsics : \n\n");

    printf("TEST SUR LES ENTIERS :\n");
    test_i128(vector_size);

    //printf("TEST SUR LES ENTIERS OLD :\n");
    //test_i128_old(vector_size);

    printf("TEST SUR LES FLOTTANTS :\n");
    test_f128(vector_size);

    printf("TEST SUR LES FLOTTANTS OLD:\n");
    test_f128_old(vector_size);

    printf("TEST SUR LES DOUBLES :\n");
    test_d128(vector_size);

    printf("TEST SUR LES DOUBLES OLD:\n");
    test_d128_old(vector_size);

    return 0;
}