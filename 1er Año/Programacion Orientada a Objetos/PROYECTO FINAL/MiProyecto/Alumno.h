#ifndef ALUMNO_H
#define ALUMNO_H
#include "ficha_medica.h"
#include <string>
using namespace std;

class Alumno{
protected:
	string m_nombreyape, m_nombretutor, m_direccion,m_fechanac;
	int m_edad, m_dni, m_tel;
	ficha_medica m_ficha_medica;
	bool m_pago;
public:
	
	Alumno( string nombreyape, string nombretutor, string direccion,string fechanac, int edad, int dni, int tel,  ficha_medica a,bool pago=false);
	int VerDniAlumno();
	string VerNombreAlumno();
	string VerNombreTutorAlumno();
	string VerDireccionAlumno();
	string VerFechaNacAlumno();
	int VerEdadAlumno();
	int VerTelAlumno();
	ficha_medica VerFichaMedAlumno();
	void AgregarFicha( ficha_medica a);
};


#endif

