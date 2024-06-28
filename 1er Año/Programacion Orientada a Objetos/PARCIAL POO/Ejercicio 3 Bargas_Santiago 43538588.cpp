#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

class Alumno{
private:
	string m_nombre;
	int m_dni,m_notafinal;
public:
	Alumno(string nombre,int dni,int notafinal):m_nombre(nombre),m_dni(dni),m_notafinal(notafinal){}
	char Condicion(){
		if(m_notafinal>=4){
			return 'R';
		}
		return 'L';
	}
	string VerNombre(){return m_nombre;}
	int VerDni(){return m_dni;}
	int VerNotaFinal(){return m_notafinal;}
};

class Materia{
private:
	string m_materia;
	vector<Alumno>lista;
	string m_profesor;
public:
	Materia(string materia,string profesor):m_materia(materia),m_profesor(profesor){}
	void AgregarAlumno(Alumno a){lista.push_back(a);}
	tuple<int,int> LibresYRegulares(vector<Alumno>lista){
		int regular=0,libre=0;
		
		for(int i=0;i<lista.size();i++){
			if(lista[i].Condicion()=='R'){
				regular++;
			}else{
				libre++;
			}
		}
		return make_tuple(regular,libre);
	}
};


int main() {
	
	
	
	return 0;
}

