// f128.h
#include <emmintrin.h>

// Redéfinition du type i128 vecteur SSE de 128 bits contenant 2 doubles
#define f128 __m128

class f128
{
    public:
        static int base;
        static void setBase(int base);
        static void print_4s(f128 reg);
};
