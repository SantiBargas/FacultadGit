#include <iostream>
#include <vector>
using namespace std;

struct paciente{
	string apellido;
	string nombres;
	int tel;
	int dni;
	char sexo;
	string OS;
	int edad;
	
};

void agrega_un_paciente(vector<paciente>&lista, paciente nuevo_paciente);

int main() {
	int N;
	cout<<"cuantos pacientes hay?"<<endl;
	cin>>N;
	
	vector<paciente>lista(N);
	
	
	for(int i=0;i<lista.size();i++){
		
		cout<<"ingrese apellidos"<<endl;
		cin.ignore();
		getline(cin,lista[i].apellido);
		cout<<"ingrese nombres"<<endl;
		getline(cin,lista[i].nombres);
		
		
		cout<<"ingrese tel"<<endl;
		cin>>lista[i].tel;
		cout<<"ingrese dni"<<endl;
		cin>>lista[i].dni;
		cout<<"ingrese sexo"<<endl;
		cin>>lista[i].sexo;
		cout<<"ingrese OS (si no tiene --) "<<endl;
		cin.ignore();
		getline(cin,lista[i].OS);
		cout<<"ingrese edad"<<endl;
		cin>>lista[i].edad;
	}
	
	for(int i=0;i<lista.size();i++){
		cout<<lista[i].apellido<<endl<<lista[i].nombres<<endl<<lista[i].tel<<endl<<lista[i].dni<<endl<<lista[i].sexo<<endl<<lista[i].OS<<endl<<lista[i].edad<<endl;
		cout<<"----------------------------------------------------"<<endl;
		
	}
	
	cout<<"AHORA INGRESE NUEVO PACIENTE"<<endl<<endl;
	paciente nuevo_paciente;
	
	cout<<"ingrese apellidos"<<endl;
	cin.ignore();
	getline(cin,nuevo_paciente.apellido);
	cout<<"ingrese nombres"<<endl;
	getline(cin,nuevo_paciente.nombres);
	cout<<"ingrese tel"<<endl;
	cin>>nuevo_paciente.tel;
	cout<<"ingrese dni"<<endl;
	cin>>nuevo_paciente.dni;
	cout<<"ingrese sexo"<<endl;
	cin>>nuevo_paciente.sexo;
	cout<<"ingrese OS (si no tiene --) "<<endl;
	cin.ignore();
	getline(cin,nuevo_paciente.OS);
	cout<<"ingrese edad"<<endl;
	cin>>nuevo_paciente.edad;
	
	agrega_un_paciente(lista,nuevo_paciente);
	
	for(int i=0;i<lista.size();i++){
		cout<<lista[i].apellido<<endl<<lista[i].nombres<<endl<<lista[i].tel<<endl<<lista[i].dni<<endl<<lista[i].sexo<<endl<<lista[i].OS<<endl<<lista[i].edad<<endl;
		cout<<"----------------------------------------------------"<<endl;
		
	}
	
	return 0;
}

void agrega_un_paciente(vector<paciente>&lista, paciente nuevo_paciente){
	
	lista.push_back(nuevo_paciente);
	

}
