#include <iostream>
#include <vector>
using namespace std;


///Los datos terminan con nombre en cadena "zzz"
int main() {
	vector<string>Aprobados; ///Lista de aprobados
	vector<string>NoAprobados; ///Lista de No Aprobados
	string Nombre;
	int Calificacion;
	
	cout<<"Ingrese el nombre del alumno (zzz termina)"<<endl;
	cin>> Nombre;	
	
	while(Nombre != "zzz"){
		cout<<"Ingrese la calificacion del alumno"<<endl;
		cin>> Calificacion;
		
		if (Calificacion>=7){
			///agrego el nombre a la lista de aprobados
			Aprobados.push_back(Nombre);}
		else{
			///ES un no Aprobados
			NoAprobados.push_back(Nombre)	
		}
		
		cout<<"Ingrese el nombre del alumno (zzz termina)"<<endl;
		cin>> Nombre;	
	}
	
	if (Aprobados.size() > 0) {
		cout<<"LISTA DE APROBADOS"<<endl<<endl;
		for (int i=0; i< Aprobados.size() ;i++ {
			cout<<Aprobados[i]<<endl;
		}	
	}
	
	if (NoAprobados.size() > 0) {
		cout<<"LISTA DE NO APROBADOS"<<endl<<endl;
			for (int i=0; i< NoAprobados.size() ;i++ {
				cout<<NoAprobados[i]<<endl;
			}	
	}
	return 0;
}

