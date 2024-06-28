#include <iostream>
using namespace std;

int main() {
	
	int fecha1, fecha2;
	string nombre1,nombre2;
	
	/// /division
	/// %resto de la division
	
	cout<<"ingrese nombre 1"<<endl;	
	cin>>nombre1;
	cout<<"ingrese fecha 1"<<endl;
	cin>>fecha1;
	
	cout<<"ingrese nombre 2"<<endl;	
	cin>>nombre2;
	cout<<"ingrese fecha 2"<<endl;
	cin>>fecha2;
	
int anio1 = fecha1 / 10000;	
int resto1 = fecha1 % 10000;
int mes1 = resto1/ 100;
int dia1 = resto1 % 100;

int anio2 = fecha2 / 10000;	
int resto2 = fecha2 % 10000;
int mes2 = resto2/ 100;
int dia2 = resto2 % 100;

cout<<nombre1<< " nacio el año "<<anio1<<" del mes "<<mes1<<" del dia "<<dia1<<endl; 
cout<<nombre2<< " nacio el año "<<anio2<<" del mes "<<mes2<<" del dia "<<dia2<<endl; 

	
	
	
	
	
	return 0;
}

