#include "Maestra.h"

Maestra::Maestra(string nombreyape,int edad,int antiguedad,int dni,int telefono):m_nombreyape(nombreyape),m_edad(edad),
m_antiguedad(antiguedad),m_dni(dni),m_telefono(telefono){}

string Maestra::VerNombreMaestra(){
	return m_nombreyape;
}
