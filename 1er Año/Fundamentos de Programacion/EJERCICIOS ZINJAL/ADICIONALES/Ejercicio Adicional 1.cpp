#include <iostream>
#include <vector>
using namespace std;
bool existenumero(vector<int>lista, int nrobuscar);
bool existenumero(vector<int>lista, int nrobuscar,int indice);
int main() {
	vector<int>lista; ///vector sin dimension
	int nro;
	bool existe;
	
	
	for (int i=0; i<500;i++){
		nro = 100 +rand()%100;
		existe= existenumero(lista,nro);
		if(existe==false){
			lista.push_back(nro);
		}
	}
	
	for (int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	
	return 0;
}

bool existenumero(vector<int>lista, int nrobuscar){
	
	for(int i=0;i<lista.size();i++){
		if(lista[i]==nrobuscar){
			return true;
		}
	}
	return false;
}

bool existenumero(vector<int>lista, int nrobuscar,int indice){
	///1er paso de la recursividad, evaluar el fin del autollamado
	
	if(indice==lista.size()){ ///fin del autollamado pq indice llega a la cantidad de la lista nomas
		return false;
	}
	
	///ver si encontro el numero
	if (lista[indice]== nrobuscar){
		///lo encontro
		return true;}
	else{
		///autollamado con el siguiente indice
		return existenumero(lista,nrobuscar,indice+1);
	}
}
