#include "Sala.h"
#include <algorithm>
using namespace std;

Sala::Sala(string nombre):m_nombre(nombre){}

void Sala::AgregarAlumno(Alumno a){
	m_alumnos.push_back(a);
}

void Sala::EliminarAlumno(int dni){
	auto it=find(m_alumnos.begin(),m_alumnos.end(),dni);
	m_alumnos.erase(it);
}

bool operator==(Alumno a, int dni){
	return a.VerDniAlumno()==dni;
}

int Sala::Cantidad(){
	return m_alumnos.size();
}

void Sala::AgregarMaestra(Maestra a){
	m=a;
}
void Sala::AgregarAuxiliar(Auxiliar a){
	ax=a;
}
void Sala::ModificarAuxiliar(Auxiliar a){
	ax=a;
}
void Sala::ModificarMaestra(Maestra a){
	m=a;
}

string Sala::VerNombreSala(){
	return m_nombre;
}
