#include <iostream>
using namespace std;

int main() {
	int N;
	string Opcion; /// "D" Decreciente "C" Creciente 
	
	cout<<" Ingrese el valor de N "<<endl;
	cin>>N;
	
	cout<<"Ingrese Opcion (C creciente D decreciente)"<<endl;
	cin>>Opcion;
	
	
	if (Opcion == "C"){
		cout<<"los numeros pares son"<<endl;
		for (int i=2;i<N;i++) {
			if (i %2==0){
			cout<<i<<endl;
			}
		}
	}
	else{
		cout<<"los numeros pares son"<<endl;
		for (int i= N-1;i>=2;i--){
			if (i %2==0){
			cout<<i<<endl;
			}
		}
	}	
	return 0;
}

