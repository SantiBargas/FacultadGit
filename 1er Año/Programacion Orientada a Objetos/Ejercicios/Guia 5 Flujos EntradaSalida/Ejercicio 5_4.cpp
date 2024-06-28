#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


class ConfigFile{
	struct Par{
		string clave,valor;
	};
	vector<Par> m_v;
	string m_nombre;
public:
	ConfigFile(string nombre):m_nombre(nombre){
		ifstream fin(nombre);
		string linea;
		while(getline(fin,linea)){
			if(linea=="")continue ;
			if(linea[0]=='#')continue; /*linea.find('#')==0 otra opcion*/
																									///   0123456
			size_t pos_igual = linea.find('=');   ///Con esta funcion busco cuanto mide la clave por ej: nombre=fulano, la clave mide 6 lugares
			
			if(pos_igual==string::npos){
				cerr<<"Eror leyendo"<<nombre<<endl;
				return;
			}
			
			Par p;
			p.clave = linea.substr(0,pos_igual);
			p.valor = linea.substr(pos_igual+1);
			m_v.push_back(p);
		}
		
	}
	
	string Ver(string clave)const{
		for(Par p:m_v){
			if(p.clave==clave){
				return p.valor;
			}
		}
		return "";
	}
	void Modificar(string clave, string nuevo_valor){
		for( Par &p:m_v){
			if(p.clave==clave){
				p.valor==nuevo_valor;
				return;
			}
		}
		m_v.push_back({clave,nuevo_valor}); //si no estaba la clave, la agrego al final
	}
	void Guardar() const{
		ofstream fout(m_nombre,ios::trunc);
		fout<<p.clave<<" = "<<p.valor<<endl;
	}
};


int main() {
	
	
	return 0;
}

