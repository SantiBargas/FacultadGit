#include "Alumno.h"
#include <iostream>
#include <sstream>
#include "ficha_medica.h"
using namespace std;

Alumno::Alumno(string nombreyape, string nombretutor, string direccion,string  fechanac, int edad, int dni, int telefonotutor,
			   ficha_medica a,bool pago):  m_nombreyape(nombreyape), m_nombretutor(nombretutor), m_direccion(direccion),m_fechanac(fechanac),
	m_edad(edad), m_dni(dni),m_tel(telefonotutor), m_pago(pago) {}

int Alumno::VerDniAlumno(){
	return m_dni;
}

void Alumno::AgregarFicha(ficha_medica a){
	m_ficha_medica=a;
}

string Alumno::VerNombreAlumno(){
	return m_nombreyape;
}
string Alumno::VerNombreTutorAlumno(){
	return m_nombretutor;
}
string Alumno::VerDireccionAlumno(){
	return m_direccion;
}
string Alumno::VerFechaNacAlumno(){
	return m_fechanac;
}
int Alumno::VerEdadAlumno(){
	return m_edad;
}

int Alumno::VerTelAlumno(){
	return m_tel;
}

ficha_medica Alumno::VerFichaMedAlumno(){
	return m_ficha_medica;
}
