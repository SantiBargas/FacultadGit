#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> CrearVector(int CantElementos, int ValorInicial=0);
void LlenarVector(vector<int>&lista);
int main() {
	int p,m;
	
	vector<int>lista = CrearVector(20,0);
	LlenarVector(lista);
	for(int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	
	cout<<"ingrese la posicion a insertar"<<endl;
	cin>>p;
	cout<<"ingrese el valor a insertar"<<endl;
	cin>>m;
	
	lista.resize(lista.size()+1);
	
	for(int i=lista.size();i>p-1;i--){
		lista[i]=lista[i-1];
		
	}
	
	lista[p-1]=m;
	
	for(int i=0;i<lista.size();i++){
		
		cout<<lista[i]<<endl;
	}
	return 0;
}

vector<int> CrearVector(int CantElementos, int ValorInicial){
	vector<int>aux(CantElementos,ValorInicial);
	return aux;
}

void LlenarVector(vector<int>&lista){
	for(int i=0;i<lista.size();i++){
		lista[i]= 100+rand()%51;
	}
}
