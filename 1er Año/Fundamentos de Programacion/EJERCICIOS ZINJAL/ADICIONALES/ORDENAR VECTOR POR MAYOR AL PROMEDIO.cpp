#include <iostream>
#include <vector>
using namespace std;

int getpromedio(vector<int>lista);
int reacomodardatos(vector<int>&lista);

int main() {
	vector<int>lista;
	int valor;
	
	cout<<"ingrese valor (en 0 termina)"<<endl;
	cin>>valor;
	
	while(valor!=0){
		lista.push_back(valor);
		cout<<"ingrese valor (en 0 termina)"<<endl;
		cin>>valor;
	}
	cout<<endl<<"VECTOR ORIGINAL"<<endl;
	
	for(int i=0;i<lista.size();i++){
		cout<<lista[i]<<"    ";
	}
	
	reacomodardatos(lista);
	cout<<"VECTOR ORDENADO"<<endl;
	
	for(int i=0;i<lista.size();i++){
		cout<<lista[i]<<"    ";
	}
	
	
	return 0;
}

int reacomodardatos(vector<int>&lista){
	int promedio= getpromedio(lista);
	vector<int>aux;
	int cantsupera=0;
	
	///busco los que esten por encima del promedio)
	for (int i=0;i<lista.size();i++){
		if(lista[i]>promedio){
			cantsupera++;
			aux.push_back(lista[i]);
		}
	}
	
	for (int i=0;i<lista.size();i++){
		if(lista[i]<=promedio){
			aux.push_back(lista[i]);
		}
	}
	
	
	lista=aux;
	
	return cantsupera;
}
int getpromedio(vector<int>lista){
	int suma=0;
	for (int i=0;i<lista.size();i++){
		suma+=lista[i];
	}
	return suma/lista.size();
}
