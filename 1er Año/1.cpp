#include <iostream>
#include <vector>
using namespace std;

class Persona{
	string nya;
	int dni, fn;        //   aaaammdd
	char ec;             //s c v d
public:
	Persona(string anya, int adni, int afn, char aec):
		nya(anya),dni(adni),fn(afn),ec(aec){}//{cout<<"se creo una persona\n";}
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
	int VerMa(){return ma;}
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


int main(int argc, char *argv[]) {
	Docente d("Jorge",20176484,19990614,'c',19930801);
	vector<Alumno> a;
	string nom;
	int n,fech,dni,matap;
	char estc;
	float pro;
	cout<<"Cantindad de alumnos: ";
	cin>>n;
	for(int i=0;i<n;i++) { 
		cout<<"ingrese: nombre, dni, fecha nac, est.civil, promedio y cant. materias:\n"; 
		cin>>nom>>dni>>fech>>estc>>pro>>matap;
		a.push_back(Alumno(nom,dni,fech,estc,pro,matap));
	}
	
	cout<<"listado:\n";
	for(int i=0;i<a.size();i++) { 
		cout<<a[i].VerNya()<<"   "<<a[i].VerDni()<<"   "<<a[i].VerFn()<<"   "<<a[i].VerEc()<<
			"   "<<a[i].VerProm()<<"   "<<a[i].VerMa()<<"   Edad: "<<a[i].Edad(20200918)<<"  Merito: "<<a[i].MeritoAcademico()<<endl;
	}
	
	cout<<"\nAntigüedad docente:"<<d.Antiguedad(20200918)<<endl;
	
	
	return 0;
}

