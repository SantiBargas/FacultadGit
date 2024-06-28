#ifndef MAESTRA_H
#define MAESTRA_H
#include <string>
using namespace std;

class Maestra {
public:
	Maestra(string nombreyape,int edad,int antiguedad,int dni,int telefono);
	Maestra(){};
	string VerNombreMaestra();
private:
	string m_nombreyape;
	int m_edad, m_antiguedad,m_dni,m_telefono;
};

#endif

