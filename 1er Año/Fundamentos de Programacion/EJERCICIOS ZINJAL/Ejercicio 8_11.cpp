#include <iostream>
using namespace std;


int fibo(int i){
	if (i<2) return i; ///si el numero es 0 o 1 retorno el numero
					   ///si es mayor aplico la funcion de sumar los dos anteriores y retornar el numero
	else return fibo(i-1) + fibo(i-2);
}



int main() {

	for (int i=0; i<15; i++){
		cout<<fibo(i)<<endl;
	}	
	return 0;
}

