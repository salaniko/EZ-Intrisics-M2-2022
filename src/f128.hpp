// f128.h
#include <emmintrin.h>

// Redéfinition du type f128 vecteur SSE de 128 bits contenant 4 flottants
#define f128 __m128

// Redéfinition des fonctions de chargement de vecteur
#define f128_lda(x)   _mm_load_ps   ((__m128 *) x)
#define f128_ldu(x)   _mm_loadu_ps  ((__m128 *) x)

// Redéfinition des fonctions d'initialisation de vecteur
#define f128_set( i0, i1, i2, i3 ) _mm_set_ps  ((float) i0, (float) i1, (float) i2, (float) i3)    //normal
#define f128_setr(i0, i1, i2, i3 ) _mm_setr_ps ((float) i0, (float) i1, (float) i2, (float) i3)    //reverse
#define f128_setzero() _mm_setzero_ps()                                                            //empty

// Redéfinition des fonctions d'addition parallèle de vecteurs
#define f128_add( x, y )    _mm_add_ps    ( (__m128) x, (__m128) y )
#define f128_addsub( x, y ) _mm_addsub_ps ( (__m128) x, (__m128) y )

// Redéfinition des fonctions de soustraction
#define f128_sub( x, y ) _mm_sub_ps ( (__m128) x, (__m128) y )

// Redéfinition des fonctions de division
#define f128_div( x, y ) _mm_div_ps ( (__m128) x, (__m128) y )

// Redéfinition des fonctions de multiplication
#define f128_mul( x, y ) _mm_mul_ps ( (__m128) x, (__m128) y )

// Redéfinition des fonctions logiques
#define f128_and( x, y ) _mm_and_ps ( (__m128) x, (__m128) y )
#define f128_andnot( x, y ) _mm_andnot_ps ( (__m128) x, (__m128) y )
#define f128_or( x, y ) _mm_or_pd ( (__m128) x, (__m128) y )
#define f128_xor( x, y ) _mm_xor_pd ( (__m128) x, (__m128) y )

class F128
{
    public:
        static void print_4f(f128 reg, int base = 16);
};
