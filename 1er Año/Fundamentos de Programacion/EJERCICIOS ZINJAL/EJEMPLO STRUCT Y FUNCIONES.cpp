#include <iostream>
#include <vector>
using namespace std;

///INGRESE LISTA DE PERSONAS HASTA QUE EL NOMBRE SEA "ZZZ"

struct persona{
	string nombre;
	int dni;
	int edad;
	string email;
};
int getindicepersona(vector<persona>lista, string nombre);
int getindicepersona(vector<persona>lista, int dni);

int main() {
	vector<persona>lista;
	string nombre;
	int indice;
	
	cout<<"ingrese nombre (ZZZ termina)"<<endl;
	cin>>nombre;
	while (nombre!= "ZZZ"){
		persona p;
		p.nombre = nombre;
		cout<<"Ingrese dni"<<endl;
		cin>>p.dni;
		
		indice=getindicepersona(lista,p.dni)
		while(indice!=-1){
			cout<<"dni ya existe reingrese dni"<<endl;
			cin>>p.dni;
			indice=getindicepersona(lista,p.dni)
		}
		
		
		cout<<"ingrese edad"<<endl;
		cin>>p.edad;
		cout<<"ingrese email"<<endl;
		cin>>p.email;
		lista.push_back(p);
		
		cout<<"ingrese nombre (ZZZ termina)"<<endl;
		cin>>nombre;
	}
	
	
	cout<<"ingrese nombre a buscar"<<endl;
	cin>>nombre;
	cout<<" el nombre "<<nombre<<"se encuentra en la posicion "<<getindicepersona(lista, nombre);
	return 0;
}
int getindicepersona(vector<persona>lista, string nombre){
	
	
	for (int i=0;i<lista.size();i++){
		if(lista[i].nombre == nombre){
			return i;
		}
	}
	return -1;
}
	
int getindicepersona(vector<persona>lista, int dni){	
	for (int i=0;i<lista.size();i++){
		if(lista[i].dni == dni){
			return i;
		}
	}
	return -1;
}
