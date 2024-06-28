#include <iostream>
using namespace std;

int validar_edad(int edadmin, int edadmax);

int main() {
	string nombre, nombremayor;
	int edad, edadmayor;
	int N,i;
	
	cout<<"Ingrese cantidad de asociados"<<endl;
	cin>>N;
	
	/// Iniciar los mayores
	nombremayor = "";
	edadmayor = 0;
	
	for (i = 0;i<N;i++){
		cout<<"Ingrese nombre "<<i<<endl;
		cin>>nombre;
		edad = validar_edad(12,90);
		
		if (edad > edadmayor){
			edadmayor=edad;
			nombremayor = nombre;
		}
	}
	cout<<"El socio mayor es "<<nombremayor<<" con "<<edadmayor<<" años"<<endl;
	return 0;
}

int validar_edad(int edadmin, int edadmax){
	bool terminado = false;
	int edad;
	while (terminado == false){
		cout<<"Ingrese edad (12 a 90)"<<endl;
		if (edad >= 12 and edad<=90){
			terminado = true;} ///ingreso edad correcta
		else{
			cout<<" Edad fuera de rango "<<endl;
		}
	}
	return edad;
}
