#ifndef SALA_H
#define SALA_H
#include <vector>
#include "Auxiliar.h"
#include "Maestra.h"
#include "Alumno.h"
using namespace std;

class Sala {
public:
	Sala(string nombre);
	void AgregarAlumno(Alumno a);
	void EliminarAlumno(int dni);
	int Cantidad();
	void AgregarMaestra(Maestra a);
	void AgregarAuxiliar(Auxiliar a);
	void ModificarAuxiliar(Auxiliar a);
	void ModificarMaestra(Maestra a);
	string VerNombreSala();
private:
	vector<Alumno>m_alumnos;
	Maestra m;
	Auxiliar ax;
	string m_nombre;
};

#endif

