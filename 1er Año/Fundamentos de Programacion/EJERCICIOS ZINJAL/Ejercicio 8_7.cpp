#include <iostream>
using namespace std;

int validar_edad(int edadmin, int edadmax);

int main() {
	string nombre, nombremayor;
	int edad, edadmayor;
	int N,i;
	int edadminina,edadmaxima
	
	cout<<"ingrese edad minima y edad maxima"<<endl;
	cin>>edadminina>>edadmaxima<<endl;
	cout<<"Ingrese cantidad de asociados"<<endl;
	cin>>N;
	
	/// Iniciar los mayores
	nombremayor = "";
	edadmayor = 0;
	
	for (i = 0;i<N;i++){
		cout<<"Ingrese nombre "<<i<<endl;
		cin>>nombre;
		edad = validar_edad(edadminima,edadmaxima);
		
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
		cout<<"Ingrese edad ("<<edadmin<<" a "<<edadmax<<")"<<endl;
		if (edad >= edadmin and edad<=edadmax){
			terminado = true;} ///ingreso edad correcta
		else{
			cout<<" Edad fuera de rango "<<endl;
		}
	}
	return edad;
}
