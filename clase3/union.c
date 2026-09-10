#include <stdio.h>
#include <emmintrin.h>
#include <immintrin.h>

// Definir la estructura
union MSGunion {
    unsigned char MSG[256];
    unsigned int MSGi[64];
    unsigned long long MSGll[32];
    __m128i MSG128[16];
    __m256i MSG256[8];
};

int main() {
    union MSGunion MG;
    
    printf("\nTamaño de la union %lu\n",sizeof(MG));

    unsigned int i;

    for(i=0;i<256;i++)
    	MG.MSG[i]=i;
    	
    for(i=0;i<32;i++)
    	printf(" %llx ",MG.MSGll[i]);
    	  
    printf("\n");	
    	
    for(i=0;i<64;i++)
    	printf(" %x ",MG.MSGi[i]);
    printf("\n");	
 

}
