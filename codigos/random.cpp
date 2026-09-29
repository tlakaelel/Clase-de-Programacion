#include <time.h>
#include <memory>
#include "iostream"
extern "C"
{
#include <immintrin.h>
}

using namespace std;

int main(){
	unsigned long long N;
	int b,i;
	for(i=0;i<1000;i++){
		b=_rdrand64_step(&N);
		cout<< "   b=" << b << " N=" << N <<endl; 
	}
	cout <<endl;		
}
