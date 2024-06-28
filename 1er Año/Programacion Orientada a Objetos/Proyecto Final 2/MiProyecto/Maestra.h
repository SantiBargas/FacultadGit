#ifndef MAESTRA_H
#define MAESTRA_H
#include <vector>
#include <string>
using namespace std;

struct StMaestra{
	int dni;
	char nombreyape[64], direccion[64],fechanac[64];
	int edad, tel;
	char tipo_doc[30];
	char sala[30];
};

class Maestra{
public:
	Maestra();
	Maestra(int dni);
	Maestra(StMaestra a);
	Maestra(int dni, std::string nombre, std::string direccion, std::string fechanac, int edad, int tel, std::string tipo, std::string sala);
	Maestra(std::string nombre);
	int VerDni();
	std::string VerNombre();
	std::string VerDireccion();
	std::string VerFechaNac();
	int VerEdad();
	int VerTel();
	std::string VerTipo();
	std::string VerSala();
	StMaestra ConvertirAStruct();
	Maestra ConvertirAClase(StMaestra a);
	bool operator== (Maestra c2);
private:
	int m_dni;
	std::string m_nombreyape, m_direccion,m_fechanac;
	int m_edad, m_tel;
	std::string m_tipo_doc, m_sala;
};

#endif

