#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Datos{
	string nombre,apellido;
	string codigo;
	string sector;
};

class Usuario{
private:
	fstream m_f;
	vector<Datos>m_v;
	vector<string>contra;
public:
	Usuario(string nom):m_f(nom){
		if(m_f.is_open()){
			cout<<"No se pudo abrir el archivo"<<endl;
			return;
		}
		Datos a;
		string nombre_y_apellido;
		while(getline(m_f,a.apellido) && getline(m_f,a.nombre) && getline(m_f,a.codigo) && getline(m_f,a.sector)){
			
			int pos= nombre_y_apellido.find(" ",0); //busco donde esta el espacio 
			a.apellido=nombre_y_apellido.substr(pos+1); //el apellido es desde la posicion del espacio+1
			a.nombre= nombre_y_apellido.erase(pos);
			m_v.push_back(a);
			
		}
	}
	void GeneraPassword(){
		string contrasenia;
		for(size_t i=0;i<m_v.size();i++) {  
			contrasenia=m_v[i].sector+m_v[i].nombre[0]+m_v[i].apellido[0];
			contra.push_back(contrasenia);
		}
	}
	void CrearBinario(string nom){
		ofstream archi("binario.dat",ios::binary|ios::in|ios::out);
		for(size_t i=0;i<m_v.size();i++){
			char nom[30];
			char apell[30];
			char codigo[30];
			strcpy(nom,m_v[i].nombre.c_str());
			strcpy(apell,m_v[i].apellido.c_str());
			strcpy(codigo,contra[i].c_str());
			
			archi.write(reinterpret_cast<char*>(nom),sizeof(nom));
			archi.write(reinterpret_cast<char*>(apell),sizeof(apell));
			archi.write(reinterpret_cast<char*>(codigo),sizeof(codigo));
		}
	}
	
	
};

int main() {
	
//	Usuario u("Usuarios.txt");
//  u.GeneraPassword();
//	u.CrearBinario();
	
	
	
	return 0;
}

