#include <iostream>
#include <vector>
using namespace std;

class Alumno{
private:
	string m_nombre;
	int m_dni;
	int m_cantapro;
	vector<float>notasalum;
public:
	Alumno(string nombre,int dni,int cantapro):m_nombre(nombre),m_dni(dni),m_cantapro(cantapro){}
	string ver_nombre(){return m_nombre;}
	int ver_dni(){return m_dni;}
	float calcularprom(){
		float sum=0;
		for(size_t i=0;i<notasalum.size();i++) { 
			sum=sum+notasalum[i];
		}
		sum=sum/notasalum.size();
		return sum;
	}
	void agregarnota(float nota){
		notasalum.push_back(nota);
	}
	int cantidad_de_notas(){
		return notasalum.size();
	}
	int operator[](int x){
		return notasalum[x];
	}
};

bool operator > (Alumno a, Alumno b){
	return (a.calcularprom()>b.calcularprom());
}

void mostar_alumno(Alumno a){
	cout<<"Nombre: "<<a.ver_nombre()<<endl;
	cout<<"DNI: "<<a.ver_dni()<<endl;
	cout<<"Notas: ";
	for(int i=0;i<a.cantidad_de_notas();i++){
		cout<<a[i]<<"  ";
	}
}

int main() {
	int n,x,y;
	cout<<"cant de materias aprobadas alum 1: "<<endl;cin>>x;
	cout<<"cant de materias aprobadas alum 2: "<<endl;cin>>y;
	Alumno a1("Jorge Nail",42374290,x);
	Alumno a2("Clemente Olmedo",41234763,y);
	
	cout<<"ingrese notas del alumno 1: "<<endl;
	for(int i=0;i<x;i++){
		cin>>n;
		a1.agregarnota(n);
	}
	cout<<"ingrese notas del alumno 2: "<<endl;
	for(int i=0;i<y;i++){
		cin>>n;
		a1.agregarnota(n);
	}
	
	cout<<"El alumno con mejor promedio es: "<<endl;
	if(a1>a2) mostar_alumno(a1);
	else 	 mostar_alumno(a2);	
	
	return 0;
}

