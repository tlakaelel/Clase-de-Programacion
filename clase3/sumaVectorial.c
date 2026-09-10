#include <stdio.h>
#include <emmintrin.h>
#include <immintrin.h>

union Vector4int {
    int Num4[4];
    __m128i Num;
};

int main() {
    union Vector4int V4_1;
    union Vector4int V4_2;
    union Vector4int V4_R;
    
    V4_1.Num4[0]=100;
    V4_1.Num4[1]=200;
    V4_1.Num4[2]=300;
    V4_1.Num4[3]=400;

    V4_2.Num4[0]=1000;
    V4_2.Num4[1]=2000;
    V4_2.Num4[2]=3000;
    V4_2.Num4[3]=4000;

    //_mm_add_epi32 (__m128i a, __m128i b)

    printf("\nTamaño de la union %lu\n",sizeof(V4_1));


    V4_R.Num = _mm_add_epi32 (V4_1.Num, V4_2.Num);
    
    

    printf("\n %d %d %d %d \n",V4_R.Num4[0],V4_R.Num4[1],V4_R.Num4[2],V4_R.Num4[3]);

}
