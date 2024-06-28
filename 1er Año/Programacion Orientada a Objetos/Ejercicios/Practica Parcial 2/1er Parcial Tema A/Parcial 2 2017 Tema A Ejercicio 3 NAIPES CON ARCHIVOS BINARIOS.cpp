#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <list>
using namespace std;

struct Carta{
	string palo;
	int num;
};

bool operator==(Carta c1, Carta c2){
	if(c1.palo==c2.palo && c1.num==c2.num){
		return true;
	}
	else return false;
}

class Mazo{
private:
	vector<Carta>m_v;
public:
	void generar(){
		for(size_t i=0;i<12;i++) { 
			Carta x;
			x.palo="Basto";
			x.num=i;
			m_v.push_back(x);
		}	
		for(size_t i=0;i<12;i++) { 
			Carta x;
			x.palo="Oro";
			x.num=i;
			m_v.push_back(x);
		}	
		for(size_t i=0;i<12;i++) { 
			Carta x;
			x.palo="Copa";
			x.num=i;
			m_v.push_back(x);
		}	
		for(size_t i=0;i<12;i++) { 
			Carta x;
			x.palo="Espada";
			x.num=i;
			m_v.push_back(x);
		}	
	}
	void GuardarDatos(){
		ofstream archi("Mazo de cartas.txt",ios::binary|ios::trunc);
		
		char palo[15];
		for(size_t i=0;i<m_v.size();i++){
			
			strcpy(palo,m_v[i].palo.c_str());
			archi.write(reinterpret_cast<char*>(palo),sizeof(palo));
			archi.write(reinterpret_cast<char*>(&m_v[i].num),sizeof(m_v[i].num));
		}
	}
	void Eliminar(string p,int n){
		Carta c1;
		c1.num=n;
		c1.palo=p;
		auto it=find(m_v.begin(),m_v.end(),c1);
		if(it!=m_v.end()) m_v.erase(it);
	}
	void AgregarCarta(string p,int n){
		Carta c1;
		c1.num=n;
		c1.palo=p;
		
		for(size_t i=0;i<m_v.size();i++) { 
			if(m_v[i].num == c1.num and m_v[i].palo == c1.palo){
				cout<<"Carta repetida"<<endl;
				break;
			}
		}
		m_v.push_back(c1);
		
	}
	Carta VerCarta(int x){
		return m_v[x];
	}
	
	bool CargarDatos(){
		ifstream archi("binario.dat",ios::binary|ios::in|ios::out);
		if(!archi.is_open())return false;
		m_v.clear();
		int size= archi.tellg()/sizeof(Carta);
		archi.seekg(0);
		
		int n;
		char palo[30];
		for(int i=0;i<size;i++) { 
			
			archi.read(reinterpret_cast<char*>(&n),sizeof(n));
			archi.read(reinterpret_cast<char*>(palo),sizeof(palo));
			Carta c1;
			c1.num=n;
			c1.palo=palo;
			m_v.push_back(c1);
		}
	}
};



int main() {
	
	return 0;
}

