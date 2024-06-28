#include "Auxiliar.h"

Auxiliar::Auxiliar(string nombreyape,int edad,int antiguedad,int dni,int telefono):m_nombreyape(nombreyape),m_edad(edad),
	m_antiguedad(antiguedad),m_dni(dni),m_telefono(telefono){}; 

string Auxiliar::VerNombreAuxiliar(){
	return m_nombreyape;
}
