#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
using namespace std;

struct Datos{
	string nombre,apellido;
	string codigo;
	string sector;
	string password;
};

class Usuario{
private:
	vector<Datos>m_v;
public:
	Usuario(string nom):m_f(nom){
		ifstream archi(nom);
		
		Datos a;
		
		while(archi >> a.apellido >>a.codigo>>a.nombre>>a.sector){
			
			int pos= nombre_y_apellido.find(" ",0); //busco donde esta el espacio 
			a.apellido=nombre_y_apellido.substr(pos+1); //el apellido es desde la posicion del espacio+1
			a.nombre= nombre_y_apellido.erase(pos);
			m_v.push_back(a);
			
		}
	}
	void GeneraPassword(){
		
		for(Datos &d:m_v) {  
			
			d.password = sector+nombre[0]+apellido[0];
			
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

