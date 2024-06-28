#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Datos{
	char nombre[30];
	char apellido[30];
	int dni;
	float saldo;
};

class Facturas{
private:
	string nomarchi;
	vector<Datos>m_v;
public:
	Facturas(string nom){ //guardar los datos
		ifstream archi(nom,ios::binary|ios::ate);
		nomarchi=nom;
		int size = archi.tellg()/sizeof(Datos);
		archi.seekg(0);
		
		for(int i=0;i<size;i++){
			Datos c;
			archi.read(reinterpret_cast<char*>(&c),sizeof(c));
			m_v.push_back(c);
		}
		
	}
	int Cantidad() const { return m_v.size();}
	Datos Ver(int i) const {return m_v[i];}
	
	void GuardarDatos(){
		ofstream archi(nomarchi,ios::binary|ios::trunc);
		
		for(size_t i=0;i<m_v.size();i++){
			archi.write(reinterpret_cast<char*>(&m_v[i]),sizeof(Datos));
		}
		/* for(Cliente &c: m_v){
				archi.write(reinterpret_cast<char*>(&c),sizeof(c));
			}
		*/
	}
	
	void AgregarCliente(Datos c){
		m_v.push_back(c);
	}
	void EliminarCliente(int dni){
		auto it=find(m_v.begin(),m_v.end(),dni);
		if(it==m_v.end()) cout<<"No se encontro"<<endl;
		else{
			m_v.erase(it);
		}
		
	}
	
};

ostream& operator<<(ostream &o,Datos d){
	o<<d.dni<<"  "<<d.apellido<<"  "<<d.nombre<<"  "<<d.saldo;
	return o;
}

bool operator==(Datos c, int dni){ return c.dni==dni;}

int main() {
	
	return 0;
}

