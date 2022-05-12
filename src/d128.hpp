// d128.h
#include <emmintrin.h>
#include <xmmintrin.h>

// Redéfinition du type d128 vecteur SSE de 128 bits contenant 2 doubles
#define d128 __m128d

// Redéfinition des fonctions de chargement de vecteur
#define d128_lda   (x) _mm_load_pd  ( (__m128d *) x )
#define d128_ldu   (x) _mm_loadu_pd ( (__m128d *) x )
#define d128_ld_1d (x) _mm_load_sd  ( (__m128d *) x )

// Redéfinition des fonctions de stockage dans un vecteur
#define d128_storea   ( x, y ) _mm_store_pd  ( (double *) x, (__m128d) y )   //alignés
#define d128_storeu   ( x, y ) _mm_storeu_pd ( (double *) x, (__m128d) y )   //non alignés
#define d128_store_1d ( x, y ) _mm_store_sd  ( (double *) x, (__m128d) y )   //stockage 1d

// Redéfinition des fonctions d'initialisation de vecteur
#define d128_set_2d  ( i0, i1 ) _mm_set_pd     ( (double) i0, (double) i1 )  //set 2 doubles
#define d128_set_1d  ( i0 )     _mm_set_sd     ( (double) i0)                //set 1 double
#define d128_setr    ( i0, i1 ) _mm_setr_pd    ( (double) i0, (double) i1 )  //set en reverse
#define d128_setzero ()         _mm_setzero_pd ()                            //set vide

// Redéfinition des fonctions d'addition parallèle de vecteurs
#define d128_add_2d ( x, y ) _mm_add_pd    ( (__m128d) x, (__m128d) y )
#define d128_add_1d ( x, y ) _mm_add_sd    ( (__m128d) x, (__m128d) y )
#define d128_addsub ( x, y ) _mm_addsub_pd ( (__m128d) x, (__m128d) y )

// Redéfinition des fonctions de soustraction
#define d128_sub_2d ( x, y ) _mm_sub_pd ( (__m128d) x, (__m128d) y )
#define d128_sub_1d ( x, y ) _mm_sub_sd ( (__m128d) x, (__m128d) y )

// Redéfinition des fonctions de division
#define d128_div_2d ( x, y ) _mm_div_pd ( (__m128d) x, (__m128d) y )
#define d128_div_1d ( x, y ) _mm_div_sd ( (__m128d) x, (__m128d) y )

// Redéfinition des fonctions de multiplication
#define d128_mul_2d ( x, y ) _mm_mul_pd ( (__m128d) x, (__m128d) y )
#define d128_mul_1d ( x, y ) _mm_mul_sd ( (__m128d) x, (__m128d) y )

// Redéfinition des fonctions logiques
#define d128_and    ( x, y ) _mm_and_pd    ( (__m128d) x, (__m128d) y )
#define d128_andnot ( x, y ) _mm_andnot_pd ( (__m128d) x, (__m128d) y )
#define d128_or     ( x, y ) _mm_or_pd     ( (__m128d) x, (__m128d) y )
#define d128_xor    ( x, y ) _mm_xor_pd    ( (__m128d) x, (__m128d) y )

// Redéfinition de fonctions mathématiques
#define d128_sqrt_2d ( x )    _mm_sqrt_pd ( (__m128d) x )
#define d128_sqrt_1d ( x, y ) _mm_sqrt_sd ( (__m128d) x, (__m128d) y )

class D128
{
    public:
        static void print_2d(d128 reg, int base = 16);
};