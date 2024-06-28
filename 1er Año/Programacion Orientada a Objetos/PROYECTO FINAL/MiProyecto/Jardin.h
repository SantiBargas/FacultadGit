#ifndef JARDIN_H
#define JARDIN_H
#include <vector>
#include "Sala.h"
#include "Directora.h"
using namespace std;

class Jardin {
public:
	Jardin(string nombre);
	void AgregarSala(Sala a);
	string VerNombreJardin();
private:
	vector<Sala>m_sala;
	string m_nombre;
	Directora a;
};

#endif

