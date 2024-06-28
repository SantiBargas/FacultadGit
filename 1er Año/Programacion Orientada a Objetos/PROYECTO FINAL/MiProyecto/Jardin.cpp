#include "Jardin.h"

Jardin::Jardin(string nombre):m_nombre(nombre){}

void Jardin::AgregarSala(Sala a){
	m_sala.push_back(a);
}

string Jardin::VerNombreJardin(){
	return m_nombre;
}
