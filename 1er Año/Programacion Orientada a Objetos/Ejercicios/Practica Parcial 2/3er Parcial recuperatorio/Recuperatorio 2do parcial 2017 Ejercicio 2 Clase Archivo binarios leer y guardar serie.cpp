#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Serie{
	string nombre;
	int cant;
};

class AdminSeries{
private:
	vector<Serie>m_v;
	string nombre_archivo;
public:
	void Cargar(string nom){
		nombre_archivo=nom;
		fstream archi(nom,ios::binary|ios::out);
		
		if(!archi.is_open()){
			cout<<"No se pudo abrir"<<endl;
			return;
		}
		int size=archi.tellg()/sizeof(Serie);
		archi.seekg(0);
		Serie s;
		for(int i=0;i<size;i++) { 
			archi.write(reinterpret_cast<char*>(&s),sizeof(Serie));
			m_v.push_back(s);
		}	
			
	}
	void RegistrarEpisodio(string nomep){
		bool aux=false;
		for(size_t i=0;i<m_v.size();i++) { 
			if(m_v[i].nombre==nomep){
				m_v[i].cant++;
				aux=true;
			}
		}
		if(aux==false){
			Serie x;
			x.nombre=nomep;
			x.cant=1;
			m_v.push_back(x);
		}
	}
	int EpisodiosVisualizados(string nom){
		int x=0;
		for(size_t i=0;i<m_v.size();i++) { 
			if(m_v[i].nombre==nom){
				return m_v[i].cant;
			}
		}
		return x;
	}
	void Guardar(){
		ofstream archi(nombre_archivo,ios::binary|ios::trunc);
		char aux[30];
		Serie s;
		for(size_t i=0;i<m_v.size();i++){
			strcpy(aux,s.nombre.c_str());
			
			archi.write(reinterpret_cast<char*>(aux),sizeof(aux));
			archi.write(reinterpret_cast<char*>(m_v[i].cant),sizeof(int));
			
		}
	}
};

int main() {
	
	return 0;
}

