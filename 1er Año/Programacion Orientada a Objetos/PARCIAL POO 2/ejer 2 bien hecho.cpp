#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


struct Datos{
	int dni,nota1,nota2,nota3;
	char nombre [64];
	char apellido [64];
};

class Curso{
private:
	vector<Datos>m_v;
public:
	Curso(){
		fstream archi("ALUMNOS.DAT",ios::binary|ios::app);
		
		size_t tam=archi.tellg()/sizeof(Datos);
		
		archi.seekg(0);
		for(size_t i=0;i<tam;i++){
			Datos d;
			archi.read(reinterpret_cast<char*>(&d),sizeof(d));
			m_v.push_back(d);
		}
	}
	
	void EliminaRepetidos(){
		auto it = unique(m_v.begin(),m_v.end());
		m_v.erase(it,m_v.end());
	}
	
	void Guardar(string nom){
		
		ofstream arch(nom);
		
		for(size_t i=0;i<m_v.size();i++){
			
			string nomb=m_v[i].nombre;
			string ape=m_v[i].apellido;
			float prom=(m_v[i].nota1+m_v[i].nota2+m_v[i].nota3)/3;
			
			string iniciales;
			
			for(size_t i=0;i<m_v.size();i++){
				
				if(nomb[i]>='A' and nomb[i]<='Z'){//como esta en mayusc se guarda la primer letra del nombre
					
					iniciales +=nomb[i];
					iniciales +=". ";
				}
			}
			arch<<m_v[i].apellido<<"  "<<iniciales<<" "<<m_v[i].dni<<" "<<prom;
		}
		
	}
	
};

bool operator==(Datos a, Datos b){
	return a.dni==b.dni ;
}

int main() {
	
	return 0;
}

