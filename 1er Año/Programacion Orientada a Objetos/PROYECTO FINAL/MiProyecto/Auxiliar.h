#ifndef AUXILIAR_H
#define AUXILIAR_H
#include <string>
#include "Auxiliar.h"
using namespace std;

class Auxiliar {
public:
	Auxiliar(string nombreyape, int edad,int antiguedad, int dni,int telefono);
	Auxiliar(){};
	string VerNombreAuxiliar();
private:
	string m_nombreyape;
	int m_edad, m_antiguedad,m_dni,m_telefono;
};

#endif

