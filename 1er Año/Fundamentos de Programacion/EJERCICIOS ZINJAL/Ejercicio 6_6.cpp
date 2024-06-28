#include <iostream>
#include <cmath>
using namespace std;

int main() {
	///calcule el area de un circulo ingresando como dato el radio	
	float radio;	
	
	float M_PI;
	
	cout<<" ingrese el radio"<<endl;
	cin>>radio;
	
	float area = M_PI * pow(radio,2);
	
	cout<<"el area del circulo es"<<area<<endl;	
	
	float perimetro = radio * M_PI * 2;
		
	cout<<" el perimetro del circulo es "<<perimetro;	
	return 0;
}

