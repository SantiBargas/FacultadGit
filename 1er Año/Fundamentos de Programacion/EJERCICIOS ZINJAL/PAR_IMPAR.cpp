#include <iostream>
using namespace std;

int main() {
	///ingrese un numero y diga si es par o no	
	
	int nro;
	cout<<"ingrese numero"<<endl;
	cin>>nro;
	
	/*
	== igual que
	!distinto
	*/
	
	if (nro % 2 == 0) {
		cout<<nro<<" es par";}
	else {
		cout<<nro<<" es impar";
	}
		
	
	return 0;
}

