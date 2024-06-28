#include "Jardin.h"
#include <fstream>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

bool operator <(Alumno c1, Alumno c2){
	return c1.VerNombre()<c2.VerNombre();
}

bool operator <(Maestra c1, Maestra c2){
	return c1.VerNombre()<c2.VerNombre();
}

Jardin::Jardin() {}

void Jardin::AgregarAlumno(Alumno a){
	vector<Alumno>V = LeerDelArchivoAlumnos();
	V.push_back(a);
	VAlumnos=V;
	GuardarVectorAlumnos();
}
void Jardin::AgregarMaestra(Maestra a){
	vector<Maestra>V = LeerDelArchivoMaestras();
	V.push_back(a);
	VMaestras=V;
	GuardarVectorMaestras();
}

void Jardin::GuardarVectorAlumnos(){
	StAlumno b;
	
	ofstream archi("Alumnos.dat",ios::binary|ios::trunc);
	
	sort(VAlumnos.begin(),VAlumnos.end());
	
	for(size_t i=0;i<VAlumnos.size();i++) { 
		b=VAlumnos[i].ConvertirAStruct();
		archi.write(reinterpret_cast<char*>(&b),sizeof(b));
	}	
}
void Jardin::GuardarVectorMaestras(){
	StMaestra b;
	
	ofstream archi("Maestras.dat",ios::binary|ios::trunc);
	
	sort(VMaestras.begin(),VMaestras.end());
	
	for(size_t i=0;i<VMaestras.size();i++) { 
		b=VMaestras[i].ConvertirAStruct();
		archi.write(reinterpret_cast<char*>(&b),sizeof(b));
	}	
}
void Jardin::Inicializar(){
	
	ficha_medica aa{("IOSE"),("MANI"),("B-"),("Paola Mestre"),(30),(1.15)};
	ficha_medica bb{("OSUNER"),("MIEL"),("0+"),("Mario Ruberto"),(29),(1.25)};
	ficha_medica cc{("IOSPER"),("ABEJAS"),("A-"),("Edgar Manlsilla"),(25),(1.10)};
	ficha_medica zz{("OSDE"),("LACTOSA"),("0-"),("Gabriel Elias Braccogollo"),(19),(1.00)};
	Alumno a(43538588,"Bargas Santiago","Marcelo Bargas","Confederacion arg 664","06/11/2015",4,1231233,"Sala 1",aa);
	Alumno b(44548588,"Molas Tomas","Jose Tomas Molas","Hilario Lagos 876","06/11/2015",2,1231233,"Sala 1",bb);
	Alumno c(45548588,"Vukonic Augusto","Martin Vokunic","Mitre 697","06/11/2015",5,1231233,"Sala 2",cc);
	Alumno h(46538588,"Reina Maia","Juan Reina","San martin 135","09/11/2001",4,1231233,"Sala 2",zz);
	Alumno i(47548588,"Abud Matias Agustin","Ramon Abud","Ramirez 934","09/11/2003",2,1231233,"Sala 3",aa);
	Alumno l(48548588,"Giavon Julieta","Ramiro Giavon ","Rivadavia 286","09/11/2003",2,1231233,"Sala 3",bb);
	Alumno m(49548588,"Sole Candela","Santino Sole","Malvinas 347","09/11/2018",2,1231233,"Sala 3",cc);
	Alumno n(50548588,"Lopez Brisa","Carlos Lopez","Italia 179","09/11/2013",2,1231233,"Sala 4",zz);
	Alumno o(51548588,"Epelbaum Simon","Roman Apelnas","Tucuman 467","09/11/2016",2,1231233,"Sala 4",aa);
	Alumno p(52548588,"CARRIZO JULIAN","Pablo Carrizzo","Ramirez 321","09/11/2019",2,1231233,"Sala 4",bb);
	Alumno s(64548588,"Suarez Laureano","Joaquin Suarez","Carbo 457","06/11/2019",5,1231233,"Sala 1",cc);
	Alumno u(61548588,"Peralta Francisco","Cesar Peralta","Hilario de la quintana 621","06/11/2015",5,1231233,"Sala 1",zz);
	Alumno t(594518588,"Zanardi Juan Francisco","Hector Zanardi","Alem 258","06/11/2015",5,1231233,"Sala 2",zz);
	Alumno t1(5818588,"Messi Juan Francisco","Hector Messi","Alem 258","06/11/2015",5,1231233,"Sala 3",zz);
	Alumno t2(57418588,"Cavenaghi Francisco","Andrea Risso","Alem 258","06/11/2015",5,1231233,"Sala 5",cc);
	Alumno t3(56418588,"Crespo Hernan","Monica Risso","Alem 202","06/11/2015",5,1231233,"Sala 5",cc);
	Alumno t4(55418588,"Saviola Hernan","Marisa Rivero","Alem 202","06/11/2015",5,1231233,"Sala 5",cc);
	Alumno t5(54418588,"Saviola Matias","Marta Retamal","Alem 202","2003/06/11",5,1231233,"Sala 6",aa);
	Alumno t6(43538500,"Bargas Simon","Luciano Bargas","Confederacion arg 664","06/11/2018",4,1231233,"Sala 6",aa);
	Alumno t7(44548501,"Molas Agustin","Gustavo Molas","Hilario Lagos 876","06/11/2019",2,1231233,"Sala 6",bb);
	Alumno t8(45548502,"Vukonic Santiago","Martin Vokunic","Mitre 697","01/01/2020",5,1231233,"Sala 7",cc);
	Alumno t9(47548503,"Abud Tiago","Ramon Abud","Ramirez 934","01/01/2020",2,1231233,"Sala 7",aa);
	Alumno t10(48548504,"Giavon Camila","Ramiro Giavon ","Rivadavia 286","01/01/2020",2,1231233,"Sala 7",bb);
	Alumno t11(49548505,"Sole Fernanda","Santino Sole","Malvinas 347","01/01/2020",2,1231233,"Sala 8",cc);
	Alumno t12(51548506,"Epelbaum Francisco","Roman Apelnas","Tucuman 467","01/01/2020",2,1231233,"Sala 8",aa);
	Alumno t13(52548507,"Carrizo Eitan","Pablo Carrizzo","Ramirez 321","01/01/2020",2,1231233,"Sala 8",bb);
	
	Maestra d(11111111,"Tundis Mirta","Laurencena 844","07/08/1980",48,4270890,"Maestra","Sala 1");
	Maestra e(22222222,"Herrera Adriana","Alem 457","09/10/1887",45,4270890,"Auxiliar","Sala 1");
	Maestra f(33333333,"Juarez Gabriela","Soler 465","07/08/1790",65,4270890,"Maestra","Sala 2");
	Maestra g(44444444,"Fernandez Soledad","Av Belgramo 345","07/08/1950",57,4270890,"Auxiliar","Sala 2");
	Maestra j(55555555,"Beron Priscilla","Montiel 745","07/08/1950",42,4270890,"Maestra","Sala 3");
	Maestra k(66666666,"Scetta Gabriela","Santiago del estero 481","07/08/1950",39,4270890,"Auxiliar","Sala 3");
	Maestra q(77777777,"Benitez Isabel","Nux 9547","07/08/1950",29,4270890,"Maestra","Sala 4");
	Maestra r(88888888,"Ubal Florentina","Mexico 86","07/08/1950",40,4270890,"Auxiliar","Sala 4");
	
	Maestra d1(99999999,"Tundis Mirta","Laurencena 844","07/08/1980",48,4270890,"Maestra","Sala 5");
	Maestra d2(10101010,"Benitez Adriana","Alem 457","09/10/1887",45,4270890,"Auxiliar","Sala 5");
	Maestra d3(12121212,"Alvarez Gabriela","Soler 465","07/08/1790",65,4270890,"Maestra","Sala 6");
	Maestra d4(13131313,"Girotti Soledad","Av Belgramo 345","07/08/1950",57,4270890,"Auxiliar","Sala 6");
	Maestra d5(14141414,"Armani Priscilla","Montiel 745","07/08/1950",42,4270890,"Maestra","Sala 7");
	Maestra d6(15151515,"Lux Gabriela","Santiago del estero 481","07/08/1950",39,4270890,"Auxiliar","Sala 7");
	Maestra d7(16161616,"Hysel Isabel","Nux 9547","07/08/1950",29,4270890,"Maestra","Sala 8");
	Maestra d8(17171717,"Laxam Florentina","Mexico 86","07/08/1950",40,4270890,"Auxiliar","Sala 8");
	
	VAlumnos.push_back(a);	VAlumnos.push_back(b);	VAlumnos.push_back(c);VAlumnos.push_back(h);VAlumnos.push_back(i);VAlumnos.push_back(l);VAlumnos.push_back(m);VAlumnos.push_back(n);
	VAlumnos.push_back(o);VAlumnos.push_back(p);VAlumnos.push_back(s);VAlumnos.push_back(t);VAlumnos.push_back(u);VAlumnos.push_back(t1);VAlumnos.push_back(t2);
	VAlumnos.push_back(t3);VAlumnos.push_back(t4);VAlumnos.push_back(t5);VAlumnos.push_back(t6);VAlumnos.push_back(t7);VAlumnos.push_back(t8);
	VAlumnos.push_back(t9);VAlumnos.push_back(t10);VAlumnos.push_back(t11);VAlumnos.push_back(t12);VAlumnos.push_back(t13);
	
	VMaestras.push_back(r);
	VMaestras.push_back(d1);VMaestras.push_back(d2);VMaestras.push_back(d3);VMaestras.push_back(d4);VMaestras.push_back(d5);VMaestras.push_back(d6);
	VMaestras.push_back(d7);VMaestras.push_back(d8);VMaestras.push_back(d);VMaestras.push_back(e);VMaestras.push_back(f);VMaestras.push_back(g);VMaestras.push_back(j);VMaestras.push_back(k);VMaestras.push_back(q);
	
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

	vector<Maestra>V = LeerDelArchivoMaestras();
	VMaestras=V;
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
	
	vector<Alumno>V = LeerDelArchivoAlumnos();
	VAlumnos=V;
	
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

bool Jardin::ModificarAlumno(Alumno a,long dni){
	vector<Alumno>V = LeerDelArchivoAlumnos();
	VAlumnos=V;
	auto it = find(VAlumnos.begin(),VAlumnos.end(),dni);
	
	if ( it == VAlumnos.end()){
		return false;
	}else{
		replace(VAlumnos.begin(),VAlumnos.end(),*it,a);
		GuardarVectorAlumnos();
		return true;
	}
}

bool Jardin::ModificarMaestra(Maestra a, long dni){
	vector<Maestra>VM = LeerDelArchivoMaestras();
	
	auto it = find(VM.begin(),VM.end(),dni);
	
	if ( it == VM.end()){
		return false;
	}else{
		VMaestras = VM;
		replace(VMaestras.begin(),VMaestras.end(),*it,a);
		GuardarVectorMaestras();
		return true;
	}
}


