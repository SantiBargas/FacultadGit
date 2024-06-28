#include <iostream>
#include <vector>
using namespace std;
///Hacer una  super clase llamada himcha y luego clases hijas con
//hinchas de dist. equipos, cada uno tienen su propio grito


class hincha{

	string m_equipo,m_nombre;
public:
	hincha(string equipo,string nombre):m_equipo(equipo),m_nombre(nombre){}
	string VerEquipo(){return m_equipo;}
	string VerNombre(){return m_nombre;}
	virtual string Gritar()=0;
};

class hinchacolon:public hincha{
public:
	hinchacolon(string nombre):hincha("colon",nombre){};
	string Gritar(){return "TATENGUE PECHO FRIO";}
};
class hinchaunion:public hincha{
public:
	hinchaunion(string nombre):hincha("union",nombre){};
	string Gritar(){return "SABALERO PECHO FRIO";}
};

class hinchariver:public hincha{
public:
	hinchariver(string nombre):hincha("River",nombre){};
	string Gritar(){return "MORISTE EN MADRID";}
};


int main() {
	///no se puede hacer vector de clases de distinto tipo
	///pero si una lista de punteros
	vector<hincha*>hinchas;  ///vector de punteros q apunta a la superclase
	
	hinchas.push_back(new hinchacolon("TUTO"));
	hinchas.push_back(new hinchaunion("SOLARI"));
	hinchas.push_back(new hinchariver("BARGAS"));
	
	for(int i=0;i<hinchas.size();i++){
		cout<<hinchas[i]->Gritar()<<endl;
	}
	///cuando es puntero no se usa hinchas[i].gritar
	///se usa hinchas[i]->gritar
	
	
	for( hincha *p : hinchas)delete p;
	
	
	return 0;
}

