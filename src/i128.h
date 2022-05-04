// i128.h
#include <emmintrin.h>

// Redéfinition du type i128 vecteur SSE de 128 bits contenant des entiers
#define i128 __m128i

// Redéfinition des fonctions de chargement de vecteur
#define i128_lda(x)   _mm_load_si128 ((__m128i *) x)
#define i128_ldu(x)   _mm_loadu_si128((__m128i *) x)

// Redéfinition des fonctions d'addition parallèle de vecteurs
#define i128_add_b( x, y ) _mm_add_epi8 ( (__m128i) x, (__m128i) y )
#define i128_add_w( x, y ) _mm_add_epi16 ( (__m128i) x, (__m128i) y )
#define i128_add_d( x, y ) _mm_add_epi32 ( (__m128i) x, (__m128i) y )
#define i128_add_q( x, y ) _mm_add_epi64 ( (__m128i) x, (__m128i) y )

class i128
{
    public:
        static int base;
        static void setBase(int base);
        static void print_16b(i128 reg);
        static void print_8w(i128 reg);
        static void print_4d(i128 reg);
        static void print_2q(i128 reg);
};
