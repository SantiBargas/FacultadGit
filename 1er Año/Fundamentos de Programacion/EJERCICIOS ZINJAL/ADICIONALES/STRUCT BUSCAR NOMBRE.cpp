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

void buscar_paciente(vector<paciente>lista, buscarapellido,buscarnombre);

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
	string buscarnombre, buscarapellido;
	cout<<"ingrese nombre q desea buscar"<<endl;
	cin>>buscarnombre;
	cout<<"ingrese apellido q desea buscar"<<endl;
	cin>>buscarapellido;
	
return 0;
void buscar_paciente(vector<paciente>lista, buscarapellido,buscarnombre){
	
	for (int i=0;i<lista.size();i++){
		if(buscarnombre==lista[i].nombre and buscarapellido==lista[i].apellido){
			cout<<lista[i].tel<<endl<<lista[i].dni<<endl<<lista[i].sexo<<endl<<lista[i].OS<<lista[i].edad<<endl;
		}
		else{
			cout<<"no se encontro paciente"<<endl;
		}
	}	
