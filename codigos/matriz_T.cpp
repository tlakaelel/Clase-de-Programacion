#include <iostream>
#include <locale>
#include <memory.h>
#include <time.h>


using namespace std;
template <class T>
class Matriz{
  private:
    int filas,col;
    void init(T **M);
    
  public:
    T **M;
    Matriz();
    Matriz(int filas,int col);
    Matriz(const Matriz& other);
    Matriz(T **,int filas,int col);
    void Transpuesta();
    //void Traza();
    //void prodEscalar(float K);
    void fill();
    void imprimir();
    Matriz operator+(const Matriz<T>& A2);
    Matriz& operator=(const Matriz<T>& other);
    Matriz operator-(const Matriz<T>& A2);
    //void operator=(Matriz A2);
    ~Matriz();
};
	template <class T>
	Matriz<T>::Matriz(){
		this->filas=5;
		col=5;
		int i;
		
		this->M = new T*[filas];
		for(i=0;i<filas;i++)
			this->M[i]=new T[col];
	}

	template <class T>
	Matriz<T>::Matriz(int filas,int col){
		this->filas=filas;
		this->col=col;
		int i;
		this->M = new T*[filas];
		for(i=0;i<filas;i++)
			this->M[i]=new T[col];
	}	
	
	template <class T>
	Matriz<T>::Matriz(T **N,int filas,int col){
		this->filas=filas;
		this->col=col;
		this->M=N;
	}
	
	//rule_of_three(const rule_of_three& other)
	
	template <class T>
	Matriz<T>::Matriz(const Matriz& other){
		init(other.M);
	}
	
	template <class T>
	void Matriz<T>::init(T **M){
		int i,j;
		this->M = new T*[filas];
		for(i=0;i<filas;i++)
			this->M[i]=new T[col];
			
		for(i=0;i<filas;i++)
			for(j=0;j<col;j++)
				this->M[i][j]=M[i][j];	
			
	}
	
	
	template <class T>
	void Matriz<T>::Transpuesta(){
		T **Aux;
		Aux = new T*[filas];
		int i,j;
		for(i=0;i<filas;i++)
			Aux[i]=new T[col];
		
		for(i=0;i<filas;i++)
			for(j=0;j<col;j++)	
				Aux[i][j]=this->M[j][i];
		
		for(i=0;i<filas;i++)
			for(j=0;j<col;j++)	
				this->M[i][j]=Aux[i][j];
				
		for(i=0;i<filas;i++)
			delete[] Aux[i];
		
		delete[] Aux;	
	}
	
	template <class T>
	Matriz<T> Matriz<T>::operator+(const Matriz<T>& A2){
		int i,j;
		T **Aux;
		Aux = new T*[filas];
		for(i=0;i<filas;i++)
			Aux[i]=new T[col];
		
		for(i=0;i<filas;i++)
			for(j=0;j<filas;j++)
				Aux[i][j]=this->M[i][j]+A2.M[i][j];	
	
		Matriz R(Aux,this->filas,this->col);
			
		return R;
	}
		
		template <class T>
		Matriz<T> Matriz<T>::operator-(const Matriz<T>& A2){
		int i,j;
		T **Aux;
		Aux = new T*[filas];
		for(i=0;i<filas;i++)
			Aux[i]=new T[col];
		
		for(i=0;i<filas;i++)
			for(j=0;j<filas;j++)
				Aux[i][j]=this->M[i][j]-A2.M[i][j];	
	
		Matriz R(Aux,this->filas,this->col);
			
		return R;
	}
	
	template <class T>
	Matriz<T>& Matriz<T>::operator=(const Matriz<T>& other){
		if(this != &other) {
            delete[] M;  // deallocate
            init(other.M);
        }
        return *this;
	}	
	
	template <class T>
	void Matriz<T>::fill(){
		int i,j;
		
		for(i=0;i<filas;i++)
			for(j=0;j<filas;j++)
				this->M[i][j]=rand()%10;
	} 

	template <class T>
	void Matriz<T>::imprimir(){
		int i,j;
		for(i=0;i<filas;i++){
			for(j=0;j<filas;j++)
				cout << this->M[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
	
	template <class T>
	Matriz<T>::~Matriz(){
		int i;
		for(i=0;i<filas;i++)
			delete[] this->M[i];
		
		delete[] this->M;
		//cout << "destructor " << this << endl;
		
	}

int main(){
	Matriz<double> A;
	Matriz<double> B,*D,*E;
	srand(time(NULL));
	A.fill();
	A.imprimir();
	B.fill();
	B.imprimir();

	
	Matriz<double> C; //= A + B;
	
	C = A+B;
	C.imprimir();

	C = A-B;
	C.imprimir();

    D = new Matriz<double>[5];
    E = D;
    for(int i=0;i<5;i++){
		D->fill();
		D->imprimir();
		cout << D << endl;
		D++;
	}

	return 0;
}
