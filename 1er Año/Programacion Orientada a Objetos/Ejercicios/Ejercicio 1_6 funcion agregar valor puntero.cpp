#include <iostream>
using namespace std;
///Amplíe el programa anterior para que, luego de generar el arreglo aleatoriamente,
///	permita ingresar un valor M que debe ser insertado en la posición P de dicho
///	arreglo y muestre el vector modificado. Para la inserción, implemente una función
///	insertar() utilizando notación de punteros.

void insertar(int *v, int N, int valor, int pos){
	
	for(int i=N;i>pos-1;i--){
		v[i]=v[i-1];
	}
	v[pos-1]=valor;
}

int main() {
	
	int N=5;
	int *p= new int[N+1]; ///sobredimensionar para agregar valor
	
	for(int i=0;i<N;i++){
		*(p+i) = 1000+rand()%501;	///sabiendo la direccion del 1ero sumandole i, va al siguiente
		/* p[i] = 1000+rand()%501; */	///cualq de las dos es valida
	}
	
	cout<<" El arreglo inicial es: "<<p<<endl;
	for(int i=0;i<N;i++){
		cout<<" "<<*(p+i)<<endl;
	}
	cout<<endl;
	
	insertar(p,N,42,2); ///Insertar valor 42 en la posicion 2
	
	cout<<" El arreglo final es: "<<p<<endl;
	for(int i=0;i<N+1;i++){
		cout<<" "<<*(p+i)<<endl;
	}
	cout<<endl;
	
	
	return 0;
}

