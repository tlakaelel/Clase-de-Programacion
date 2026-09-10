#include <stdio.h>
#include <emmintrin.h>
#include <immintrin.h>

void print_m128i(__m128i *v){
	unsigned long long *k;
	k=(unsigned long long *)v;
	printf("%016llx%016llx",k[1],k[0]);
}

void print_m256i(__m256i *v){
	unsigned long long *k;
	k=(unsigned long long *)v;
	printf("%016llx%016llx%016llx%016llx",k[3],k[2],k[1],k[0]);
}

int main(){
	unsigned char a[256];
	unsigned char *iter;
	unsigned int *p;
	unsigned long long *q;
	__m128i *v128;
	__m256i *v256;
	unsigned int i;
	
	for(i=0;i<256;i++)
		a[i]=i;
		
	printf("\n\n\n");	
	for(i=0;i<256;i++)
		printf("%x ",a[i]);
	
	printf("\n\n\n");	
	p=(unsigned int *)a;
	for(i=0;i<64;i++)
		printf("%p %p %x \n",&p,p+i,*(p+i));
	
	q=(unsigned long long *)a;
	printf("\n\n\n");	
	for(i=0;i<32;i++)
		printf("%p %llx \n",q+i,*(q+i));

	v128=(__m128i *)a;
	printf("\n\n\n");	
	for(i=0;i<16;i++){
		printf("%p ",v128+i);
		print_m128i(v128+i);
		printf("\n");
		}

	v256=(__m256i *)a;
	printf("\n\n\n");	
	for(i=0;i<8;i++){
		printf("%p ",v256+i);
		print_m256i(v256+i);
		printf("\n");
		
	}
	
	printf("\n\n\n");	
	//iter=a;
	//for(i=0;i<256;i++)
	//	printf("%x ",*(iter++));
		
	for(iter=a;iter!=(a+256);iter++)
		printf("%x ",*iter);
	return 1;
	
}
