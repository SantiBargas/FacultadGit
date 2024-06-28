#include <iostream>
#include <vector>
using namespace std;

struct paciente{
	string apellido;
	string nombre;
	int tel;
	int dni;
	char sexo;
	string OS;
	int edad;
};

int porcentaje(vector<paciente>lista);
int menores45(vector<paciente>lista);


int main() {
	
	int N;
	cout<<"cuantos pacientes hay?"<<endl;
	cin>>N;
	vector<paciente>lista(N);
	
	for (int i=0;i<lista.size();i++){
		
		cout<<"ingrese apellido"<<endl;
		cin.ignore();
		getline(cin,lista[i].apellido);
		cout<<"ingrese nombre"<<endl;
		cin.ignore();
		getline(cin,lista[i].nombre);
		cout<<"ingrese tel"<<endl;
		cin>>lista[i].tel;
		cout<<"ingrese dni"<<endl;
		cin>>lista[i].dni;
		cout<<"ingrese sexo"<<endl;
		cin>>lista[i].sexo;
		cout<<"ingrese OS (si no posee ---)"<<endl;
		cin.ignore();
		getline(cin, lista[i].OS);
		cout<<"ingrese edad"<<endl;
		cin>>lista[i].edad;
	}
	
	cout<<"la cant de porcentaje de mujeres es: "<<porcentaje(lista)<<endl;
	cout<<"la cant de menores de 45 años son: "<<menores45(lista)<<endl;
	
	cout<<"los pacientes con obra social IAPOS son"<<endl;
	for (int i=0;i<lista.size();i++){
		if (lista[i].OS=="IAPOS"){
			cout<<"apellido: "<<lista[i].apellido<<endl<<" nombre: "<<lista[i].nombre<<endl<<"DNI: "<<lista[i].dni<<endl;
		}
	}
	return 0;
}

int porcentaje(vector<paciente>lista){
	
	int mujeres=0;
	for (int i=0;i<lista.size();i++){
		if(lista[i].sexo=='F'){
			mujeres++;
		}
	}
	
	int porcentaje=0;
	porcentaje=(mujeres*100)/lista.size();
	return porcentaje;
}
int menores45(vector<paciente>lista){
	
	int menores=0;
	for (int i=0;i<lista.size();i++){
		if(lista[i].edad<45){
			menores++;
		}
	}
	return menores;
}
