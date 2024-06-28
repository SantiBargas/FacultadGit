#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Datos{
	int dni,nota1,nota2,nota3;
	char apellido[64];
	char nombre[64];
};

class Curso{
private:
	vector<Datos>m_v;
public:
	Curso(){
		fstream archi("ALUMNOS.DAT",ios::binary|ios::in|ios::out|ios::ate);
		
		size_t size=archi.tellg()/sizeof(Datos);
		archi.seekg(0);
		
		for(size_t i=0;i<size;i++){
			Datos c;
			archi.read(reinterpret_cast<char*>(&c),sizeof(c));
			m_v.push_back(c);
		}
	}
	
	void EliminaRepetidos(){
		auto it=unique(m_v.begin(),m_v.end());
		if(it==m_v.end()){
			cout<<"No hay repetidos"<<endl;
		}else{
			m_v.erase(it,m_v.end());
		}
	}
	
	void GeneraTexto(string nom){
		ofstream fout(nom,ios::trunc);
		
		for(size_t i=0;i<m_v.size();i++){
			string nomb=m_v[i].nombre;
			string apel=m_v[i].apellido;
			float prom=(m_v[i].nota1+m_v[i].nota2+m_v[i].nota3)/3;
			
			string escribirarchi= apel+" "+nomb[0];
			
			int pos=nomb.find(" ",0);
			if(pos!=-1){
				string escribirarchi=apel + " "+ nomb[0]+"."+nomb[pos+1];
			}
			fout<<escribirarchi<<" "<<m_v[i].dni<<" "<<prom<<endl;
		}
		fout.close();
	}
};

bool operator==(Datos a, Datos b){
	return a.dni==b.dni;
}

int main() {
	
	return 0;
}

