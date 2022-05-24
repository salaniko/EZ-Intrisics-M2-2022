// i128.h
#include <emmintrin.h>
#include <smmintrin.h>
#include <immintrin.h>

// Redéfinition du type i128 vecteur SSE de 128 bits contenant des entiers
#define i128 __m128i

// Redéfinition des fonctions de chargement de vecteur
#define i128_loada(x) _mm_load_si128  ( (__m128i *) x )
#define i128_loadu(x) _mm_loadu_si128 ( (__m128i *) x )

// Redéfinition des fonctions de stockage dans un vecteur
#define i128_storea( x, y ) _mm_store_si128  ( (__m128i *) x, (__m128i) y )
#define i128_storeu( x, y ) _mm_storeu_si128 ( (__m128i *) x, (__m128i) y )

// Redéfinition des fonctions d'initialisation de vecteur 
#define i128_set_b( i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15 ) \
    _mm_set_epi8((char) i0, (char) i1, (char) i2,  (char) i3,  (char) i4,  (char) i5,  (char) i6,  (char) i7, \
                 (char) i8, (char) i9, (char) i10, (char) i11, (char) i12, (char) i13, (char) i14, (char) i15)
#define i128_set_w( i0, i1, i2, i3, i4, i5, i6, i7 ) \
    _mm_set_epi16((short) i0, (short) i1, (short) i2, (short) i3, (short) i4, (short) i5, (short) i6, (short) i7)
#define i128_set_d( i0, i1, i2, i3 ) _mm_set_epi32     ( (int) i0, (int) i1, (int) i2, (int) i3 )
#define i128_set_q( i0, i1 )         _mm_set_epi64     ( (__m64) i0, (__m64) i1 )
#define i128_set_zero()               _mm_setzero_si128 ()

// Redéfinition des fonctions d'initialisation (reverse) de vecteur 
#define i128_setr_b( i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15 ) \
    _mm_setr_epi8((char) i0, (char) i1, (char) i2,  (char) i3,  (char) i4,  (char) i5,  (char) i6,  (char) i7, \
                  (char) i8, (char) i9, (char) i10, (char) i11, (char) i12, (char) i13, (char) i14, (char) i15)
#define i128_setr_w( i0, i1, i2, i3, i4, i5, i6, i7 ) \
    _mm_setr_epi16((short) i0, (short) i1, (short) i2, (short) i3, (short) i4, (short) i5, (short) i6, (short) i7)
#define i128_setr_d( i0, i1, i2, i3 ) _mm_setr_epi32 ( (int) i0, (int) i1, (int) i2, (int) i3 )
#define i128_setr_q( i0, i1 )         _mm_setr_epi64 ( (__m64) i0, (__m64) i1 )

// Redéfinition des fonctions d'addition parallèle de vecteurs
#define i128_add_b( x, y ) _mm_add_epi8  ( (__m128i) x, (__m128i) y )
#define i128_add_w( x, y ) _mm_add_epi16 ( (__m128i) x, (__m128i) y )
#define i128_add_d( x, y ) _mm_add_epi32 ( (__m128i) x, (__m128i) y )
#define i128_add_q( x, y ) _mm_add_epi64 ( (__m128i) x, (__m128i) y )

// Redéfinition des fonctions de soustraction parallèle de vecteurs
#define i128_sub_b( x, y ) _mm_sub_epi8  ( (__m128i) x, (__m128i) y )
#define i128_sub_w( x, y ) _mm_sub_epi16 ( (__m128i) x, (__m128i) y )
#define i128_sub_d( x, y ) _mm_sub_epi32 ( (__m128i) x, (__m128i) y )
#define i128_sub_q( x, y ) _mm_sub_epi64 ( (__m128i) x, (__m128i) y )

// Redéfinition des fonctions logiques
#define i128_and( x, y )  _mm_and_si128    ( (__m128i) x, (__m128i) y )
#define i128_nand( x, y ) _mm_andnot_si128 ( (__m128i) x, (__m128i) y )
#define i128_or( x, y )   _mm_or_si128     ( (__m128i) x, (__m128i) y )
#define i128_xor( x, y )  _mm_xor_si128    ( (__m128i) x, (__m128i) y )

// Redéfinition des fonctions mathématiques
#define i128_mins_b( x, y )   _mm_min_epi8  ( (__m128i) x, (__m128i) y )
#define i128_mins_w( x, y )   _mm_min_epi16 ( (__m128i) x, (__m128i) y )
#define i128_mins_d( x, y )   _mm_min_epi32 ( (__m128i) x, (__m128i) y )
#define i128_minu_b( x, y ) _mm_min_epu8  ( (__m128i) x, (__m128i) y )
#define i128_minu_w( x, y ) _mm_min_epu16 ( (__m128i) x, (__m128i) y )
#define i128_minu_d( x, y ) _mm_min_epu32 ( (__m128i) x, (__m128i) y )
#define i128_maxs_b( x, y )   _mm_max_epi8  ( (__m128i) x, (__m128i) y )
#define i128_maxs_w( x, y )   _mm_max_epi16 ( (__m128i) x, (__m128i) y )
#define i128_maxs_d( x, y )   _mm_max_epi32 ( (__m128i) x, (__m128i) y )
#define i128_maxu_b( x, y ) _mm_max_epu8  ( (__m128i) x, (__m128i) y )
#define i128_maxu_w( x, y ) _mm_max_epu16 ( (__m128i) x, (__m128i) y )
#define i128_maxu_d( x, y ) _mm_max_epu32 ( (__m128i) x, (__m128i) y )

// Redéfinition des fonctions pour l'allocation mémoire
#define sse_malloc( x, y ) _mm_malloc ( (size_t) x,(size_t) y )
#define sse_free( x ) _mm_free ( (void *) x )

class I128
{
    public:
        static void print_16b(i128 _reg, int _base = 16);
        static void print_8w(i128 _reg, int _base = 16);
        static void print_4d(i128 _reg, int _base = 16);
        static void print_2q(i128 _reg, int _base = 16);
};