#include <iostream>
using namespace std;

class Persona{
private:
	string m_nya;
	int m_dni,m_fecha;
	char m_estado;
public:
	Persona(string nya,int dni, int fecha, char estado){
		m_nya=nya; m_dni=dni; m_fecha=fecha; m_estado=estado;
	}
	int Edad(int fechaactual){
		int edad=(fechaactual/10000)-(m_fecha/10000);
		return edad;
	}
	string VerNombre(){return m_nya;}
};

class Alumno: public Persona{
private:
	int m_cant;
	float m_prom;
public:
	Alumno(string nya,int dni, int fecha, char estado,int cant, float prom):Persona(nya,dni,fecha,estado){
		m_cant=cant; m_prom=prom;
	}
	int MeritoAcademico(){
		return m_cant*m_prom;
	}
};

class Docente: public Persona{
private:
	int m_fechaingreso;
public:
	Docente(string nya,int dni, int fecha, char estado, int fechaingreso):Persona(nya,dni,fecha,estado){
		m_fechaingreso=fechaingreso;
	}
	int Antiguedad(int fechaactual){
		return (fechaactual/10000)-(m_fechaingreso/10000);
	}
};

int main() {
	int fechaactual=20200929;
	
	Alumno a("Tuto Molas",43538588,20010803,'S',10,10);
	cout<<a.Edad(fechaactual)<<" "<<a.VerNombre()<<" "<<a.MeritoAcademico()<<endl;
	
	Docente d("Gabriel 'El loco' Bracco",20283219,19922897,'S',20070919);
	cout<<d.Edad(fechaactual)<<" "<<d.VerNombre()<<" "<<"ANTIGUEDAD: "<<d.Antiguedad(fechaactual);
	
	return 0;
}

