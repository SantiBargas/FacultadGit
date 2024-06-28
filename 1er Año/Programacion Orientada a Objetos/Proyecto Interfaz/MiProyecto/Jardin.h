#ifndef JARDIN_H
#define JARDIN_H
#include <vector>
#include "Maestra.h"
#include "Alumno.h"
using namespace std;

class Jardin {
public:
	Jardin();
	void Inicializar();
	void GuardarVectorAlumnos();
	void GuardarVectorMaestras();
	void AgregarAlumno(Alumno a);
	void AgregarMaestra(Maestra a);
	bool EliminarMaestra(long dni);
	bool EliminarAlumno(long dni);
	void ReemplazarFichaMedica(ficha_medica ficha,long dni);
	vector<Alumno> LeerDelArchivoAlumnos();
	vector<Maestra> LeerDelArchivoMaestras();
	tuple<vector<Maestra>,vector<Alumno>> MostrarSala(string nombre);
private:
	vector<Alumno>VAlumnos;
	vector<Maestra>VMaestras;
};

#endif

