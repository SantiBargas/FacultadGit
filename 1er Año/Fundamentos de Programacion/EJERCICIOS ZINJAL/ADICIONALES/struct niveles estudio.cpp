#include <iostream>
#include <vector>
using namespace std;

struct bolsa{
	string nombre;
	int dni;
	int edad;
	string nivel;
	string profesion;
};

vector<bolsa>buscarnivel(vector<bolsa>lista, string nivelbus);
int buscardni(vector<bolsa>lista, int dni);
void ordenar(vector<bolsa>&lista);


int main() {
	vector<bolsa>lista;
	int indice;
	string nombre;
	cout<<"ingrese nombre(ZZZ termina)"<<endl;
	cin.ignore();
	getline(cin,nombre);
	
	while(nombre!="ZZZ"){
		bolsa b;
		
		b.nombre=nombre;
		cout<<"ingrese dni"<<endl;
		cin>>b.dni;
		
		indice=buscardni(lista,b.dni);
		if(indice!=-1){
			cout<<"el dni ya existe"<<endl<<"reingrese el dni"<<endl;
			cin>>b.dni;
		}
		
		cout<<"ingrese edad"<<endl;
		cin>>b.edad;
		cout<<"ingrese nivel: primario secundario terciario o universitario"<<endl;
		cin>>b.nivel;
		cout<<"ingrese profesion"<<endl;
		cin>>b.profesion;
		
		lista.push_back(b);
		
		cout<<"ingrese nombre(ZZZ termina)"<<endl;
		cin.ignore();
		getline(cin,nombre);
	}
	
	
	string nivelbus;
	cout<<endl<<"ingrese nivel de estudio que desa buscar"<<endl;
	cin>>nivelbus;
	
	vector<bolsa>aux=buscarnivel(lista,nivelbus);
	
	for(int i=0;i<aux.size();i++){
		cout<<aux[i].nombre<<endl<<aux[i].edad<<endl<<aux[i].nivel<<endl<<aux[i].profesion<<endl;
		cout<<"--------------------------------------------------"<<endl;
	}
	
	cout<<endl<<endl<<"EL VECTOR ORDENADO POR NIVELES ES :"<<endl<<endl;
	ordenar(lista);
	for(int i=0;i<lista.size();i++){
		cout<<lista[i].nombre<<endl<<lista[i].edad<<endl<<lista[i].nivel<<endl<<lista[i].profesion<<endl;
		cout<<"--------------------------------------------------"<<endl;
	}
	
	return 0;
}
vector<bolsa>buscarnivel(vector<bolsa>lista, string nivelbus){
	
	vector<bolsa>aux;
	for(int i=0;i<lista.size();i++){
		if(lista[i].nivel==nivelbus){
			aux.push_back(lista[i]);
		}
	}
	
	return aux;
}
int buscardni(vector<bolsa>lista, int dni){
	
	for(int i=0;i<lista.size();i++){
		if(lista[i].dni==dni){
			return i;
		}
	}
	return -1;
}
void ordenar(vector<bolsa>&lista){
	
	vector<bolsa>ordenado;
	
	for(int i=0;i<lista.size();i++){
		if(lista[i].nivel=="PRIMARIO"){
			ordenado.push_back(lista[i]);
		}
	}
	for(int i=0;i<lista.size();i++){
		if(lista[i].nivel=="SECUNDARIO"){
			ordenado.push_back(lista[i]);
		}
	}
	for(int i=0;i<lista.size();i++){
		if(lista[i].nivel=="TERCIARIO"){
			ordenado.push_back(lista[i]);
		}
	}
	for(int i=0;i<lista.size();i++){
		if(lista[i].nivel=="UNIVERSITARIO"){
			ordenado.push_back(lista[i]);
		}
	}
	lista=ordenado;
}
