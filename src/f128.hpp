// f128.h
#include <emmintrin.h>

// Redéfinition du type f128 vecteur SSE de 128 bits contenant 4 flottants
#define f128 __m128

class F128
{
    public:
        static int base;
        static void setBase(int base);
        static void print_4s(f128 reg);
};
