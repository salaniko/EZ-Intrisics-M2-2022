// i128.h
#include <emmintrin.h>

// Redéfinition du type i128 vecteur SSE de 128 bits contenant des entiers
#define i128 __m128i

// Redéfinition des fonctions de chargement de vecteur
#define i128_lda(x)   _mm_load_si128 ((__m128i *) x)
#define i128_ldu(x)   _mm_loadu_si128((__m128i *) x)

// Redéfinition des fonctions de stockage dans un vecteur
#define i128_storea( x, y ) _mm_store_si128( (__m128i *) x, (__m128i) y )
#define i128_storeu( x, y ) _mm_storeu_si128( (__m128i *) x, (__m128i) y )

// Redéfinition des fonctions d'initialisation de vecteur 
#define i128_set_b( i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15 ) \
    _mm_set_epi8((char) i0, (char) i1, (char) i2, (char) i3, (char) i4, (char) i5, (char) i6, (char) i7, \
                 (char) i8, (char) i9, (char) i10, (char) i11, (char) i12, (char) i13, (char) i14, (char) i15)
#define i128_set_w( i0, i1, i2, i3, i4, i5, i6, i7 ) \
    _mm_set_epi16((short) i0, (short) i1, (short) i2, (short) i3, (short) i4, (short) i5, (short) i6, (short) i7)
#define i128_set_d( i0, i1, i2, i3 ) _mm_set_epi32( (int) i0, (int) i1, (int) i2, (int) i3 )
#define i128_set_q( i0, i1 ) _mm_set_epi64( (__m64) i0, (__m64) i1 )

// Redéfinition des fonctions d'addition parallèle de vecteurs
#define i128_add_b( x, y ) _mm_add_epi8 ( (__m128i) x, (__m128i) y )
#define i128_add_w( x, y ) _mm_add_epi16 ( (__m128i) x, (__m128i) y )
#define i128_add_d( x, y ) _mm_add_epi32 ( (__m128i) x, (__m128i) y )
#define i128_add_q( x, y ) _mm_add_epi64 ( (__m128i) x, (__m128i) y )

class I128
{
    public:
        static void print_16b(i128 _reg, int _base);
        static void print_8w(i128 _reg, int _base);
        static void print_4d(i128 _reg, int _base);
        static void print_2q(i128 _reg, int base);
};
