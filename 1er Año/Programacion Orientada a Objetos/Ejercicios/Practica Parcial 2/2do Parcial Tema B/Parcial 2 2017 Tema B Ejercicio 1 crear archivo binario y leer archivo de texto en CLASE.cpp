#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

struct Persona{
	string dni;
	string nombre,apellido;
};

class Trabajo{
private:
	fstream m_f;
	vector<Persona>datos;
	vector<string>email;
public:
	Trabajo(string nom):m_f(nom){
		if(m_f.is_open()){
			cout<<"No se pudo abrir el archivo"<<endl;
			return;
		}
		Persona a;
		string nombre_y_apellido;
		while(getline(m_f,a.apellido) && getline(m_f,a.nombre) && getline(m_f,a.dni)){
			
			int pos= nombre_y_apellido.find(" ",0);
			a.apellido=nombre_y_apellido.substr(pos+1);
			a.nombre=nombre_y_apellido.erase(pos);
			datos.push_back(a);
			
		}
	}
	void GeneraEmail(){
		string em;
		for(size_t i=0;i<datos.size();i++){
			em=datos[i].nombre[0]+datos[i].apellido+"@gmail.com";
			email.push_back(em);
		}
	}
	void CreaBinario(string nom){
		ofstream archi("binario.dat",ios::binary|ios::in|ios::out);
		for(size_t i=0;i<datos.size();i++){
			char nom[30];
			char ape[30];
			char dni[30];
			char email[50];
			strcpy(nom,datos[i].nombre.c_str());
			strcpy(ape,datos[i].apellido.c_str());
			strcpy(dni,datos[i].dni.c_str());
			strcpy(email,email[i].c_str());
			
			
			archi.write(reinterpret_cast<char*>(nom),sizeof(nom));
			archi.write(reinterpret_cast<char*>(ape),sizeof(ape));
			archi.write(reinterpret_cast<char*>(dni),sizeof(dni));
			archi.write(reinterpret_cast<char*>(email),sizeof(email));
		}
		
	}
	
};

int main() {
	
	Trabajo t("Trabajo.txt");
	
	return 0;
}

/*
43538588
Bargas Santiago*/
