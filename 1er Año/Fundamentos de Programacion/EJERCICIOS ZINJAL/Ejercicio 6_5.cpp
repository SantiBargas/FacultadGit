#include <iostream>
using namespace std;

int main() {
	///convertir pies en metros
	///1 pie - 0.3048
	
	float nro;	
	cout<<"INgrese valor en pies "<<endl;
	cin>>nro;
	
	float valor;
	valor = nro * 0.3048;
	
	cout<<endl;
	cout<<nro<<" pies equivale a "<<valor<<" metros"<<endl; 
	return 0;
}

