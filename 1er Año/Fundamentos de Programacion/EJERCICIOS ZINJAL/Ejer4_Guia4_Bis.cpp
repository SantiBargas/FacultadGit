#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<string>lista(10);
	int i,posicion;
	
	lista[0] = "GOMEZ";
	lista[1] = "ALVAREZ";
	lista[2] = "PERALTA";
	lista[3] = "RODRIGUEZ";
	lista[4] = "BELTRAME";
	lista[5] = "GARCIA";
	lista[6] = "FERNANDEZ";
	lista[7] = "FARIAS";
	lista[8] = "LOPEZ";
	lista[9] = "GIMENEZ";
	
	posicion = -1;
	/// 1er paso : Buscar el apellido
	for (i=0;i<lista.size();i++){
		if (lista[i] == "GARCIA"){
			posicion = i; /// me quedo con la posicion
			break; /// interrumpe el for
		}
	}
	
	/// 2do paso, hago el corrimiento de todos 1 a la izquierda
	if (posicion != -1){
		for(i=posicion;i<lista.size()-1;i++){
			lista[i] = lista[i+1]; 
		}
	else{
			cout<<"NO SE ENCUENTRA EL APELLIDO GARCIA"<<endl;
		}
	}
	
	
	/// 3er paso, quitar el elemento sobrante de la lista
	if (posicion != -1){
		int cant = lista.size();
		lista.resize(cant-1); /// achico la lista en 1
	}
	
	cout<<endl<<endl;
	for (i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
		
	return 0;
}

