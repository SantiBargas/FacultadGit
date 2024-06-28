#include <iostream>
using namespace std;

int main() {
	///Ingrese tres valores numericos e informe el mayor
	int A,B,C;
	cin>>A;
	cin>>B;
	cin>>C;
	cout<<endl;
	
	if (A>B and A>C) {
		cout<<" el valor "<<A<<" es el mayor"<<endl;}
	else{
		if (B>A and B>C){
			cout<<" el valor "<<B<<" es el mayor"<<endl;}
		else{
			cout<<" el valor "<<C<<" es el mayor"<<endl;
		}
			
		
	}

	return 0;
}

