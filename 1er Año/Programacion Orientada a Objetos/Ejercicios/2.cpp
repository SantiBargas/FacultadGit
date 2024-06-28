#include <iostream>
#include <vector>
using namespace std;

class Persona{
	string nya;
	int dni, fn;        //   aaaammdd
	char ec;             //s c v d
public:
	Persona(string anya, int adni, int afn, char aec):
		nya(anya),dni(adni),fn(afn),ec(aec){}//  {cout<<"se creo una persona\n";}
    void CargarDatos(string anya, int adni, int afn, char aec){
		nya=anya;dni=adni;fn=afn;ec=aec;
	}
	string VerNya(){return nya;}
	int VerFn(){return fn;}
	int VerDni(){return dni;}
	char VerEc(){return ec;}
	int Edad(int afa){return (afa-fn)/10000;}
};

class Alumno: public Persona{
	float prom;
	int ma;
public:
	Alumno():Persona("",0,0,' '){}
	Alumno(Persona x, float aprom, int ama):Persona(x),prom(aprom),ma(ama){}
	Alumno(string anya, int adni, int afn, char aec, float aprom, int ama):
		Persona(anya,adni,afn,aec),prom(aprom),ma(ama){}
	void CargarDatos(string anya, int adni, int afn, char aec, float aprom, int ama){
		 Persona::CargarDatos(anya,adni,afn,aec);
		 prom=aprom;
		 ma=ama;}
	float VerProm(){return prom;}
	float MeritoAcademico(){return prom*ma;}
};

class Docente: public Persona{
	int fi;
public:
	Docente(Persona x, int afi):Persona(x),fi(afi){}
	Docente(string anya, int adni, int afn, char aec, int afi):
		Persona(anya,adni,afn,aec),fi(afi){}
	int Antiguedad(int afa){return (afa-fi)/10000;}
};

class Curso{
	string materia;
	Docente doc;
	vector<Alumno> v;
public:
	Curso(string mat, Docente d):materia(mat),doc(d){}
	string VerMateria(){return materia;}
	void AgregarAlumno(Alumno x){
		v.push_back(x);
	}
	Alumno VerAlumno(int x){return v[x];}
	int CantAlumnos(){return v.size();}
	Alumno MejorPromedio(){
		int pm=0,mayor=0; 
		for(int i=0;i<v.size();i++) { 
			if (v[i].VerProm()>mayor){
				mayor=v[i].VerProm();
				pm=i;
			}
		}
		return v[pm];
	}
		
};

int main(int argc, char *argv[]) {
	Curso c("POO",Docente("Jorge",20176484,19990614,'c',19930801));
	string nom;
	int n,fech,dni,matap;
	char estc;
	float pro;
	cout<<"Cantindad de alumnos: ";
	cin>>n;
	for(int i=0;i<n;i++) { 
		cout<<"ingrese: nombre, dni, fecha nac, est.civil, promedio y cant. materias:\n"; 
		cin>>nom>>dni>>fech>>estc>>pro>>matap;
		c.AgregarAlumno(Alumno(nom,dni,fech,estc,pro,matap));
	}
	cout<<"\n\nlistado:\n";
	for(int i=0;i<c.CantAlumnos();i++) {
		//Alumno aux=c.VerAlumno(i);
		cout<<c.VerAlumno(i).VerNya()<<"  "<<c.VerAlumno(i).VerProm()<<endl;
	}
	cout<<"\nMejor: "<<c.MejorPromedio().VerNya();
	
	return 0;
}

