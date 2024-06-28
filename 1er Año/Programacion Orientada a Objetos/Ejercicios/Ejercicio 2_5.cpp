#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct Alumno{
	string nombre;
	float nota;
};


class Curso{
private:
	string m_nombre;
	int m_cantalu;
	vector<Alumno> m_lista;
public:
	Curso(string nombre, int cantalu){m_nombre=nombre; m_cantalu=cantalu;}
	string VerNombre(){return m_nombre;}
	int VerCant(){return m_cantalu;}
	void AgregarAlumno(string nombre,int calif);
	float PromedioCurso();
	Alumno MejorAlum();
	
};
Alumno Curso::MejorAlum(){ //funcion de tipo alumno que retorna alumno de mayor nota
	
	Alumno mejornota; ///creo una variable para guardar la mejor nota
	
	for(int i=0;i<m_lista.size();i++){
		if(m_lista[i].nota>mejornota.nota){
			mejornota.nombre=m_lista[i].nombre;
			mejornota.nota=m_lista[i].nota;
		}
	}
	return mejornota;
}

void Curso::AgregarAlumno(string nombre,int calif){
	Alumno aux; ///creo auxiliar para agregar al vector
	aux.nombre=nombre;
	aux.nota=calif;
	m_lista.push_back(aux);
}
float Curso::PromedioCurso(){
	float total=0;
	for(size_t i=0;i<m_lista.size();i++){
		total+=m_lista[i].nota;
	}
	return total/m_lista.size();
}
int main() {
	
	string nombre;
	int cantalu,calif;
	cout<<"ingrese nombre nombre del curso"<<endl;
	getline(cin,nombre);
	
	cout<<"ingrese cant alumnosdel curso"<<endl;
	cin>>cantalu;
	
	Curso c(nombre,cantalu);	
	cout<<"NOMBRE: "<<c.VerNombre()<<endl<<"ALUMNOS :"<<c.VerCant()<<endl;
	
	for(int i=0;i<cantalu;i++){
		cin.ignore();
		cout<<"Ingrese nombre del alumno: "<<endl; cin>>nombre;
		cout<<"ingrese nota del alumno: "<<endl; cin>>calif; 
		c.AgregarAlumno(nombre,calif);
	}
	
	Alumno mejornota=c.MejorAlum();
	cout<<"El alumno de mayor nota es: "<<mejornota.nombre<<" con una nota de: "<<mejornota.nota<<endl;
	cout<<"El promedio del curso :"<<c.VerNombre()<<" es: "<<c.PromedioCurso();
	return 0;
}

