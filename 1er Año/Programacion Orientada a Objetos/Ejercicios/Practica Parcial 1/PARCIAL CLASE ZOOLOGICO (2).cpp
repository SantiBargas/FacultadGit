#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Animal{
protected:
	string m_tipo;
	string m_especie;
public:
	Animal(string tipo,string especie):m_tipo(tipo),m_especie(especie){}
	string VerTipo(){return m_tipo;}
	string VerEspecie(){return m_especie;}
	virtual string desplazarse()=0;
	virtual string tipo()=0;
};

class Mamifero:public Animal{
public:
	Mamifero(string tipo,string especie):Animal(tipo,especie){}
	string desplazarse()override{
		stringstream sss;
		sss<<"el animal "<<m_tipo<<" camina"<<endl;
		return sss.str();
	}
	string tipo()override{return "Mamifero";}
	
};
class Ave:public Animal{
public:
	Ave(string tipo,string especie):Animal(tipo,especie){}
	string desplazarse()override{
		stringstream sss;
		sss<<"el animal "<<m_tipo<<" VUELA"<<endl;
		return sss.str();
	}
	string tipo()override{return "Ave";}
};
class Pez:public Animal{
public:	
	Pez(string tipo,string especie):Animal(tipo,especie){}
	string desplazarse()override{
		stringstream sss;
		sss<<"el animal "<<m_tipo<<" nada"<<endl;
		return sss.str();
	}
	string tipo()override{return "Pez";}
};
int main() {
	int num;
	string tipo,especie;
	vector<Animal*>Parque;
	
	for(size_t i=0;i<2;i++){
		cout<<"1=MAMIFERO 2=AVE 3=PEZ"<<endl;
		cin>>num;
		cout<<"ingrese tipo "<<endl;
		cin>>tipo;
		
		if(num==1){
			Parque.push_back(new Mamifero(tipo,"MAMIFERO"));
		}else{
			if(num==2){Parque.push_back(new Ave(tipo,"AVE"));
		}
		else{Parque.push_back(new Pez(tipo,"PEZ"));}}
	}
	
	for(size_t i=0;i<Parque.size();i++){
		cout<<Parque[i]->VerTipo()<<"   "<<Parque[i]->VerEspecie()<<endl;
		cout<<Parque[i]->desplazarse()<<endl;
	}
	
	for(size_t i=0;i<Parque.size();i++){
		delete Parque[i];
	}
	
	return 0;
}

