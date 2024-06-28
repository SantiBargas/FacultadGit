#include "Maestra.h"
#include <cstring>
using namespace std;

bool Maestra::operator== (Maestra c2){
	return m_dni==c2.m_dni;
}

Maestra::Maestra(int dni, std::string nombre, std::string direccion, std::string fechanac, int edad, int tel, std::string tipo_doc, std::string sala):
	m_nombreyape(nombre),m_dni(dni),m_direccion(direccion),m_fechanac(fechanac),m_edad(edad),m_tel(tel),m_tipo_doc(tipo_doc),m_sala(sala){};

Maestra::Maestra(){};

Maestra::Maestra(int dni):m_dni(dni){};

Maestra::Maestra(StMaestra a){
	
	
	m_dni=a.dni;
	m_nombreyape=a.nombreyape;
	m_direccion=a.direccion;
	m_fechanac=a.fechanac;
	m_edad=a.edad;
	m_tel=a.tel;
	m_tipo_doc=a.tipo_doc;
	m_sala=a.sala;
	
}

int Maestra::VerDni(){return m_dni;}
std::string Maestra::VerNombre(){return m_nombreyape;}
std::string Maestra::VerDireccion(){return m_direccion;}
std::string Maestra::VerFechaNac(){return m_fechanac;}
int Maestra::VerEdad(){	return m_edad;}
int Maestra::VerTel(){return m_tel;}
std::string Maestra::VerTipo(){return m_tipo_doc;}
std::string Maestra::VerSala(){return m_sala;}

StMaestra Maestra::ConvertirAStruct(){
	
	StMaestra b;
	
	b.dni=m_dni;
	strcpy(b.nombreyape,m_nombreyape.c_str());
	strcpy(b.direccion,m_direccion.c_str());
	strcpy(b.fechanac,m_fechanac.c_str());
	b.edad=m_edad;
	b.tel=m_tel;
	strcpy(b.tipo_doc,m_tipo_doc.c_str());
	strcpy(b.sala,m_sala.c_str());
	
	return b;
	
}

