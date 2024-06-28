#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


struct datos{
	string nombre,apellido;
};

class Archivo{
private:
	vector<datos>m_v;
	string nomarchi;
public:
	Archivo(string nom){
		ifstream archi(nom);
		nomarchi=nom;
		if(!archi.is_open()){
			cerr<<"No se pudo abrir el archivo";
			return;
		}
		
		string linea;
		size_t ini,tam;   //inicio y fin del apellido
		size_t ini2, tam2; //inicio y fin del nombre
		while (getline(archi,linea)){
		
			///busco el apellido
			for(size_t i=0;i<linea.size();i++){
				char c=linea[i];
				if(c<= 'Z' && c>='A'){//si es mayuscula es el apellido
					ini=i;
					break;
				}
			}
			for(size_t i=ini;i<linea.size();i++){     //ahora cuento del inicio al final cuantas mayuscuals hay
				char c=linea[i];
				if(c> 'Z' or c<'A'){ //cuando termina las mayusculas salgo
					tam=i+1;
					break;
				}
			}
			///busco el nombre
			for(size_t i=0;i<linea.size();i++){
				char c = linea[i];
				if(c<= 'z' && c>='a'){//si es miniscula es el nombre
					ini2=i;
					break;
				}
			}
			for(size_t i=ini2;i<linea.size();i++){     //ahora cuento del inicio al final cuantas minusculas hay
				char c=linea[i];
				if(c> 'z' or c<'a'){ //cuando termina las minisculas salgo
					tam=i+1;
					break;
				}
			}
			
			datos d;
			d.apellido=linea.substr(ini,tam-1);
			d.nombre= linea.substr(ini2,tam2-1);
			m_v.push_back(d);
			
		}
		
	}
	void ordenar(){
		sort(m_v.begin(),m_v.end());
		auto it=unique(m_v.begin(),m_v.end());
		m_v.erase(it,m_v.end());
	}
	void guardar(){
		ofstream archi(nomarchi);
		datos d;
		char nom[30];
		char ape[30];
		for(size_t i=0;i<m_v.size();i++){
			strcpy(nom,m_v[i].nombre.c_str());
			strcpy(ape,m_v[i].apellido.c_str());
			archi.write(reinterpret_cast<char*>(nom),sizeof(nom));
			archi.write(reinterpret_cast<char*>(ape),sizeof(ape));
			
		}
	}
	void mostrar(){
		for(size_t i=0;i<m_v.size();i++){
			cout<<m_v[i].apellido<<"  "<<m_v[i].nombre<<endl;
		}
	}
};


bool operator ==(datos a, datos b){
	if(a.apellido==b.apellido && a.nombre==b.nombre){
		return true;
	}
	return false;
}
bool operator < (datos a, datos b){
		return (a.apellido<b.apellido);
	}

int main() {
	
	Archivo a("apellidos.txt");
	a.mostrar();
	return 0;
}

/* BARGAS santiago
	MOLAS tomas
	clemente OLMEDO
	ALARIO pipa*/
