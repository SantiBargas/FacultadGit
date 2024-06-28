#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>
#include <vector>
using namespace std;

struct ficha_medica {
	char obra_social[64];
	char alergias[64];
	char grupo_sanguineo[64];
	char medico_cabecera[64];
	float peso,altura ;
};
struct StAlumno{
	int dni;
	char nombreyape[64], nombretutor[64], direccion[64],fechanac[64];
	int edad, tel;
	char sala[30];
	ficha_medica ficha;
};

class Alumno{
public:
	Alumno();
	Alumno(int dni);
	Alumno(int dni,std::string nombreyape,std::string nombretutor,std::string direccion, std::string fechanac,int edad,int tel, std::string sala,ficha_medica ficha);
	Alumno(StAlumno a);
	StAlumno ConvertirAStruct();
	int VerDni();
	std::string VerNombre();
	std::string VerNombreTutor();
	std::string VerDireccion();
	std::string VerFechaNac();
	int VerEdad();
	int VerTel();
	std::string VerSala();
	ficha_medica VerFichaMedica();
	void ReemplazarFicha(ficha_medica);
	bool operator== (Alumno c2);
private:
	int m_dni;
	std::string m_nombreyape, m_nombretutor, m_direccion,m_fechanac;
	int m_edad, m_tel;
	std::string m_sala;
	ficha_medica m_ficha_medica;
};

#endif

