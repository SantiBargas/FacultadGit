#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int x;
	float y;
	
	ofstream archi("Ejercicio 6_1.dat",ios::binary); ///aclaramos q trabajamos en binario
	
	for(int i=0;i<200;i++){
		x=rand()%101;
		y= rand()%101/100.0;
		cout<<"Par "<<i<<": "<<x<<", "<<y<<endl;
		
		archi.write(reinterpret_cast<char*>(&x),(sizeof(x)));  ///sizeof es para saber cuanto mide la variable
		archi.write(reinterpret_cast<char*>(&y),(sizeof(y))); ///sizeof es para saber cuanto mide la variable
	}
	///para verificar que el ejercicio esta bien, nos podemos fijar
	///cuanto pesa el archivo, en este caso;
	///200 int(4bytes) + 200 float(4bytes)= 1600 bytes
	
	return 0;
}
///otra alternativa
/*
struct Par{
	int x;
	float y;
};

for(int i=0;i<200;i++){
	Par p {rand()%101 ,rand()%101/100.0};
	cout<<"Par "<<i<<": "<<p.x<<", "<<p.y<<endl;

	archi.write(reinterpret_cast<char*>(&p),(sizeof(p)));  
	
}*/
