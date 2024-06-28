#ifndef DIRECTORA_H
#define DIRECTORA_H
#include <string>
using namespace std;

class Directora {
public:
	Directora(string nombre,int telefono);
	Directora(){};
	string VerNombreDirectora();
private:
	string m_nombre;
	int m_telefono;
};

#endif

