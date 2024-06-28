#include<iostream>
#include "Jardin.h"
#include "ficha_medica.h"
using namespace std;

int main (int argc, char *argv[]) {
	
	
	Jardin a("Mis Primeros Pasos");
	
	Sala b("Sala Roja");
	a.AgregarSala(b);
	
	Directora ae("Mariela Salazar",3212213123);
	Maestra c("Mariana solari",45,12,22543633,43538588);
	Auxiliar d("Mirtha Flores",60,17,22345543,4234246);
	
	ficha_medica e{("OSUNER"),("NADA"),("0-"),("EL TATA"),(25),(1.10)};
	Alumno g("Tomas molas","Tomas molas","Piran 1233","2001/09/3",4,4323424,4243260,e,true);
	Alumno h("Tomas molas","Tomas molas","Piran 1233","2001/09/3",4,4323424,4243260,e,true);
	Alumno i("Tomas molas","Tomas molas","Piran 1233","2001/09/3",4,4323424,4243260,e,true);
	
	b.AgregarMaestra(c);
	b.AgregarAuxiliar(d);
	b.AgregarAlumno(g);
	g.AgregarFicha(e);

	
	cout<<"El nombre del jardin es: "<<a.VerNombreJardin()<<endl<<endl<<endl;
	cout<<"y su directora es: "<<ae.VerNombreDirectora()<<endl<<endl;
	
	cout<<"El nombre de la sala es: "<<b.VerNombreSala()<<endl;
	cout<<"La maestra/maestro que la dirige es: "<<c.VerNombreMaestra()<<endl;
	cout<<"La auxiliar es: "<<d.VerNombreAuxiliar()<<endl;
	cout<<"Los datos de sus alumnos son: "<<endl<<endl;

	return 0;
}
ostream & operator<< (ostream &o, ficha_medica &a){
	o<<a.obra_social<<endl;
	o<<a.alergias<<endl;
	o<<a.altura<<endl;
	o<<a.grupo_sanguineo<<endl;
	o<<a.medico_cabecera<<endl;
	o<<a.peso<<endl;
}

ostream & operator<< (ostream &o, Alumno c){
	o<<c.VerNombreAlumno()<<endl
		<<c.VerNombreTutorAlumno()<<endl
		<<c.VerDireccionAlumno()<<endl
		<<c.VerFechaNacAlumno()<<endl
		<<c.VerEdadAlumno()<<endl
		<<c.VerDniAlumno()<<endl
		<<c.VerTelAlumno()<<endl
		<<c.VerFichaMedAlumno()<<endl;
	return o;
}
