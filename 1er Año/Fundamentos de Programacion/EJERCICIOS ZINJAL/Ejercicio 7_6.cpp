#include <iostream>
using namespace std;

int main() {
	
	///Ingrese un numero y determine si es par,impar y multiplo de 5 y 3
	
	int Numero;
	cout<<"Ingrese un numero "<<endl;
	cin>> Numero;
	
	if (Numero % 2==0) {
		cout<<" el numero es par"<<endl;}
	else{
		cout<<"el numero es impar"<<endl;
	}
	
	if(Numero % 5==0 and Numero % 3==0){
		cout<<"el numero es multiplo de 5 y 3"<<endl;}
	else{ 
	   cout<<"el numero NO es multiplo de 5 y 3"<<endl;
	}
	return 0;
}

