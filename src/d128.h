// d128.h
#include <emmintrin.h>

// Redéfinition du type i128 vecteur SSE de 128 bits contenant 2 doubles
#define d128 __m128d

class d128
{
    public:
        static int base;
        static void setBase(int base);
        static void print_2d(d128 reg);
};
