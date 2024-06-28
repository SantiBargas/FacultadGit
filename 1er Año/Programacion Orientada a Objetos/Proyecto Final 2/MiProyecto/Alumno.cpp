#include "Alumno.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool Alumno::operator== (Alumno c2){
	return m_dni == c2.m_dni;
}

operator == (StAlumno a, StAlumno b){
	return a.dni==b.dni;
}
Alumno::Alumno(){};

Alumno::Alumno(int dni):m_dni(dni){};

Alumno::Alumno(StAlumno a){
	
	m_dni=a.dni;
	m_nombreyape=a.nombreyape;
	m_nombretutor=a.nombretutor;
	m_direccion=a.direccion;
	m_fechanac=a.fechanac;
	m_edad=a.edad;
	m_tel=a.tel;
	m_sala=a.sala;
	m_ficha_medica=a.ficha;
}

Alumno::Alumno(int dni,std::string nombreyape,std::string nombretutor,std::string direccion, std::string fechanac,int edad,int tel, std::string sala,ficha_medica f):
			 m_dni(dni),m_nombreyape(nombreyape),m_nombretutor(nombretutor),m_direccion(direccion),
			 m_fechanac(fechanac),m_edad(edad),m_tel(tel),m_sala(sala),m_ficha_medica(f){}


StAlumno Alumno::ConvertirAStruct(){
	
	StAlumno b;
	
	b.dni=m_dni;
	strcpy(b.nombreyape,m_nombreyape.c_str());
	strcpy(b.nombretutor,m_nombretutor.c_str());
	strcpy(b.direccion,m_direccion.c_str());
	strcpy(b.fechanac,m_fechanac.c_str());
	b.edad=m_edad;
	b.tel=m_tel;
	
	strcpy(b.sala,m_sala.c_str());
	b.ficha=m_ficha_medica;
	
	return b;
}

void Alumno::ReemplazarFicha(ficha_medica f){m_ficha_medica=f;}	
int Alumno:: VerDni(){return m_dni;}
std::string Alumno::VerNombre(){return m_nombreyape;}
std::string Alumno::VerNombreTutor(){return m_nombretutor;}
std::string Alumno::VerDireccion(){return m_direccion;}
std::string Alumno::VerFechaNac(){return m_fechanac ;}
int Alumno::VerEdad(){return m_edad;}
int Alumno::VerTel(){return m_tel;}
std::string Alumno::VerSala(){return m_sala;}
ficha_medica Alumno::VerFichaMedica(){return m_ficha_medica;}

