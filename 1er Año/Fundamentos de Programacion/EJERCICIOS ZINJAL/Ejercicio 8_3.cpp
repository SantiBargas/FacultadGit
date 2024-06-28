#include <iostream>
using namespace std;

int calculoedad(int fecha1, int fecha2); /// prototipo

int main() {
	int actual= 20210215; ///fijamos fecha actual
	int nacimiento;
	int fechanac;
	cout<<"Ingrese fecha de nacimiento AAAAMMDD"<<endl;
	cin>>fechanac;
	
	int edad =calculoedad(actual, fechanac);
	cout<<"la edad es "<<edad<<" años"<< endl;
	return 0;
}
int calculoedad(int fecha1, int fecha2){
	return (fecha2 - fecha1) / 10000;
}
