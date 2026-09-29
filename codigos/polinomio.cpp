#include <time.h>
#include <memory>
#include "iostream"
extern "C"
{
#include <immintrin.h>
}

using namespace std;

// COUNTER TYPE //
typedef unsigned long long bench_t;


static bench_t before;
static bench_t after;

// ASKS FOR THE TIME STAMP COUNTER (= WHAT TIME IS IT PLEASE ?)//
static inline bench_t cycles(void) {
	unsigned int hi, lo;
	__asm__ __volatile__ ("rdtsc\n\t":"=a" (lo), "=d"(hi));
	return ((bench_t) lo) | (((bench_t) hi) << 32);
}


double horner(double X,double *coef,long size){
	double ACC=0.0;
	int i;
	for(i=0;i<size;i++){
		ACC=(ACC+coef[i])*X;
	}
	return ACC;	
}

double horner_intrinsic(double X,double *coef,long size){
	double *R,P;
	int i;
	__m256d *ymm0,X256,Y;	
	
	ymm0 = (__m256d*)coef; 
	
	
	X256 = _mm256_set1_pd(X*X*X*X);
	Y = _mm256_set1_pd(0.0);
    
	for(i=0;i<size/4-1;i++){;
		Y = _mm256_add_pd(Y,ymm0[i]);
		Y = _mm256_mul_pd(Y,X256);
	}
	
	Y = _mm256_add_pd(Y,ymm0[i]);
	
	R = (double *)(&Y);
	
	P  = R[3]*X;
	P += R[2]*X*X;
	P += R[1]*X*X*X;
	P += R[0]*X*X*X*X;

	return P;
}

int main(){
	alignas(32) double coef[4000];
	double X=1.1;
	double R;
	int i,num_trails = 100000;
	
	clock_t t1, t2;
	
	srand(time(NULL));	

	double *coeficientes;
	int j;
	coeficientes = (double *)_mm_malloc(10000*sizeof(double), 32);

	for(j=0;j<1;j++){
		
		for(i=0;i<10000;i++){
			coeficientes[i]=(double)(rand()%1000)/1000;
			if(i<10)
				cout<< coeficientes[i] <<endl;
		}
		R=horner(X,coeficientes,10000);
		cout<< R <<endl;
		R=horner_intrinsic(X,coeficientes,10000);
		cout<< R <<endl;		
	}
	
	t1 = clock();
	for(j=0;j<num_trails;j++)	
		R=horner(X,coeficientes,10000);
	t2 = clock();
  	float diff = (((float)t2 - (float)t1) / CLOCKS_PER_SEC );
  	cout<<"Time taken: "<<diff<<endl;
	

	t1 = clock();
	for(j=0;j<num_trails;j++)	
		R=horner_intrinsic(X,coeficientes,10000);
	t2 = clock();
  	diff = (((float)t2 - (float)t1) / CLOCKS_PER_SEC );
  	cout<<"Time taken: "<<diff<<endl;

	
		
	_mm_free(coeficientes);

}
