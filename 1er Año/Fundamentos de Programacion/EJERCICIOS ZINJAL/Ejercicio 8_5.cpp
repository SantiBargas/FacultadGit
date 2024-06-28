#include <iostream>
using namespace std;

void intercambia(int &a, int &b){
	int aux;
	
	aux=a;
	a=b;
	b=aux;
}
void intercambia(double &a, double &b){
	int aux;
	
	aux=a;
	a=b;
	b=aux;
}
void intercambia(string &a, string &b){
	string aux;
	
	aux=a;
	a=b;
	b=aux;
}
int main() {
	int a,b;
	cout<<"Ingrese dos valores para ser intercambiados"<<endl;
	cin>>a>>b;
	
	cout<<a<<" "<<b<<endl;
	intercambia(a,b);
	cout<<a<<" "<<b<<endl;
	
	string palabra1,palabra2;
	cout<<"Ingrese dos valores para ser intercambiados"<<endl;
	cin>>palabra1>>palabra2;
	
	cout<<palabra1<<" "<<palabra2<<endl;
	intercambia(a,b);
	cout<<palabra1<<" "<<palabra2<<endl;
	return 0;
}

