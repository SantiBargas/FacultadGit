#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Persona{
private:
	string m_nom;
public:
	Persona(string nom):m_nom(nom){}
	string virtual Saludar()=0;
	string VerNombre(){return m_nom;}
	~Persona(){};
};

class Alumno:public Persona{
private:
	string m_carrera;
public:
	Alumno(string nom,string carrera):Persona(nom),m_carrera(carrera){}
	string Saludar()override{
		stringstream sss;
		sss<<"Mi nombre es: "<<VerNombre()<<" y pertenezco a la carrera "<<m_carrera;
		
		return sss.str();
	}
	~Alumno(){};
};

class Docente:public Persona{
private:
	string m_materia;
public:
	Docente(string nom, string materia):Persona(nom),m_materia(materia){}
	string Saludar()override{
		stringstream sss;
		sss<<"Mi nombre es: "<<VerNombre()<<" y dicto "<<m_materia;
		
		return sss.str();
	}
	~Docente(){};
	
};

int main() {
	string nom,carrera;
	
	vector<Persona*>lista;
	
	lista.push_back(new Docente ("Pablo Novara","Fundamentos y Programacion orientada a objetos"));
	
	for(int i=0;i<3;i++){
		cout<<"ingrese nombre del alumno y carrera que cursa"<<endl<<endl;
		
		getline(cin,nom);
		getline(cin,carrera);
		lista.push_back(new Alumno(nom,carrera));
	}
	for(size_t i=0;i<lista.size();i++){
		cout<<lista[i]->Saludar()<<endl<<endl;
	}
	
	for(size_t i=0;i<lista.size();i++){
		delete lista[i];
	}
	
	return 0;
}

