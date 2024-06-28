#include "Jardin.h"
#include <fstream>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;


bool operator== (Alumno &c1, int dni){
	return c1.VerDni()==dni;
}

bool operator== (Alumno &c1, Alumno c2){
	return c1.VerDni()==c2.VerDni();
}

bool operator== (Maestra &c1, int dni){
	return c1.VerDni()==dni;
}

bool operator== (Maestra &c1, Maestra c2){
	return c1.VerDni()==c2.VerDni();
}

Jardin::Jardin() {}

void Jardin::AgregarAlumno(Alumno a){
	VAlumnos.push_back(a);
	GuardarVectorAlumnos();
	
}
void Jardin::AgregarMaestra(Maestra a){
	VMaestras.push_back(a);
	GuardarVectorMaestras();
	
}

void Jardin::GuardarVectorAlumnos(){
	StAlumno b;
	
	ofstream archi("Alumnos.dat",ios::binary|ios::trunc);
	
	for(size_t i=0;i<VAlumnos.size();i++) { 
		b=VAlumnos[i].ConvertirAStruct();
		archi.write(reinterpret_cast<char*>(&b),sizeof(b));
	}	
}
void Jardin::GuardarVectorMaestras(){
	StMaestra b;
	
	ofstream archi("Maestras.dat",ios::binary|ios::trunc);
	
	for(size_t i=0;i<VMaestras.size();i++) { 
		b=VMaestras[i].ConvertirAStruct();
		archi.write(reinterpret_cast<char*>(&b),sizeof(b));
	}	
}
void Jardin::Inicializar(){
	
	ficha_medica aa{("IOSE"),("MANI"),("B-"),("EL PRIMO"),(60),(1.80)};
	ficha_medica bb{("LA NUEVA"),("MIEL"),("0+"),("AXEL ROSE"),(50),(1.25)};
	ficha_medica cc{("IOSPER"),("ABEJAS"),("A-"),("EL TATA"),(25),(1.10)};
	Alumno a(43538588,"Santiago Bargas","Marcelo Bargas","Confederacion arg","2001/09/11",4,1231233,true,"Sala 1",aa);
	Alumno b(44548588,"Tomas Bargas","Marcelo Bargas","Confederacion arg","2003/09/11",2,1231233,false,"Sala 1",bb);
	Alumno c(45548588,"Francisco Molas","Tomas Molas","Mitre","2002/09/11",5,1231233,true,"Sala 2",cc);
	Alumno h(46538588,"Juan Pais","Marcelo cerrudo","Piran","2001/09/11",4,1231233,true,"Sala 2",aa);
	Alumno i(47548588,"Guido Abud","Moncho Bargas","Ramirez","2003/09/11",2,1231233,false,"Sala 3",bb);
	Alumno l(48548588,"Martin Palacios","Leo Messi","Rivadavia","2003/09/11",2,1231233,false,"Sala 3",cc);
	Alumno m(49548588,"Cande Suarez","Tuto Molas","Malvinas","2003/09/11",2,1231233,false,"Sala 3",aa);
	Alumno n(50548588,"Horacio Guarani","Carlos Gentille","Italia","2003/09/11",2,1231233,false,"Sala 4",bb);
	Alumno o(51548588,"Simon Epelbaum","Roman Apelnas","Tucuman","2003/09/11",2,1231233,false,"Sala 4",cc);
	Alumno p(52548588,"Pamela Sort","Novara Pablo","Ramirez","2003/09/11",2,1231233,false,"Sala 4",aa);
	
	Maestra d(11111111,"Mirta Tundis","Piran 1233","07/08/1980",48,4270890,"Maestra","Sala 1");
	Maestra e(22222222,"Adriana Herrera","Alem 457","09/10/1887",45,4270890,"Auxiliar","Sala 1");
	Maestra f(33333333,"Gabriela Juarez","Piran 1233","07/08/1790",65,4270890,"Maestra","Sala 2");
	Maestra g(44444444,"Soledad Fernandez","Av Galan","07/08/1950",57,4270890,"Auxiliar","Sala 2");
	Maestra j(55555555,"Priscilla Beron","Montiel","07/08/1950",42,4270890,"Maestra","Sala 3");
	Maestra k(66666666,"Gabriela Scetta","Santiago del estero","07/08/1950",39,4270890,"Auxiliar","Sala 3");
	Maestra q(77777777,"Isabel Fotocopia","Nux","07/08/1950",29,4270890,"Maestra","Sala 4");
	Maestra r(88888888,"Florentina Ubal","Mexico","07/08/1950",40,4270890,"Auxiliar","Sala 4");
	
	
	VAlumnos.push_back(a);	VAlumnos.push_back(b);	VAlumnos.push_back(c);VAlumnos.push_back(h);VAlumnos.push_back(i);VAlumnos.push_back(l);VAlumnos.push_back(m);VAlumnos.push_back(n);
	VAlumnos.push_back(o);VAlumnos.push_back(p);
	VMaestras.push_back(d);VMaestras.push_back(e);VMaestras.push_back(f);VMaestras.push_back(g);VMaestras.push_back(j);VMaestras.push_back(k);VMaestras.push_back(q);
	VMaestras.push_back(r);
	
	GuardarVectorAlumnos();
	GuardarVectorMaestras();
}	

vector<Alumno> Jardin::LeerDelArchivoAlumnos(){
	vector<Alumno>V;
	ifstream archi("Alumnos.dat",ios::binary|ios::ate|ios::in); 
	StAlumno a;	
	int cant = archi.tellg()/sizeof(a);
	archi.seekg(0);
	
	for(int i=0;i<cant;i++) {
		
		archi.read(reinterpret_cast<char*>(&a),sizeof(a));
		Alumno b(a);
		V.push_back(b);
	}
	return V;
}
vector<Maestra> Jardin::LeerDelArchivoMaestras(){
	vector<Maestra>V;
	ifstream archi("Maestras.dat",ios::binary|ios::ate|ios::in); 
	StMaestra a;	
	int cant = archi.tellg()/sizeof(a);
	archi.seekg(0);
	
	for(int i=0;i<cant;i++) {
		archi.read(reinterpret_cast<char*>(&a),sizeof(a));
		Maestra b(a);
		V.push_back(b);
	}
	return V;
}
tuple<vector<Maestra>,vector<Alumno>> Jardin::MostrarSala(string nombre){
	
	vector<Maestra> auxM;
	vector<Alumno> auxA;
	
	for(size_t i=0;i<VAlumnos.size();i++) { 
		if(VAlumnos[i].VerSala()==nombre){
			auxA.push_back(VAlumnos[i]);
		}
	}
	for(size_t i=0;i<VMaestras.size();i++) { 
		if(VMaestras[i].VerSala()==nombre){
			auxM.push_back(VMaestras[i]);
		}
	}
	
	return make_tuple(auxM,auxA);
}

bool Jardin::EliminarMaestra(long dni){
	auto it = find(VMaestras.begin(),VMaestras.end(),dni);
	
	if ( it == VMaestras.end()){
		return false;
	}else{
		auto ita = remove(VMaestras.begin(),VMaestras.end(),*it);
		VMaestras.erase(ita,VMaestras.end());
		GuardarVectorMaestras();
		return true;
	};
}
	
bool Jardin::EliminarAlumno(long dni){
	auto it = find(VAlumnos.begin(),VAlumnos.end(),dni);
	
	if ( it == VAlumnos.end()){
		cout<<"ESE DNI NO EXISTE"<<endl;
		return false;
	}else{
		auto ita = remove(VAlumnos.begin(),VAlumnos.end(),*it);
		VAlumnos.erase(ita,VAlumnos.end());
		GuardarVectorAlumnos();
		return true;
	}
}

void Jardin::ReemplazarFichaMedica(ficha_medica ficha,long dni){
	
	int numero=0;
	
	for(size_t i=0;i<VAlumnos.size();i++) { 
		if(VAlumnos[i].VerDni()==dni){
			numero = i;
		}
	}
	VAlumnos[numero].ReemplazarFicha(ficha);
}
