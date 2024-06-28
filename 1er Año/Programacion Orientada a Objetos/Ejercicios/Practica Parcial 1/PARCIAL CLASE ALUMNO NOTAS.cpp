#include <iostream>
#include <vector>
using namespace std;
/// Implemente una clase examen para modelar el enunciado completo de un examen, reutilizando la clase ejercicio
/// La clase examen debe tener a)un constructor que reciba el nombre de la materia y la fecha del examen
///b) Un metodo para agregar un ejercicio . C)uno o mas meotodos que dado un numero de ejercicio permita consultar
///los datos del mismo. D) un memtodo CalcularCalificacion que reciba vector<int> con las notas de un alumno y retorne su nota,
/// calculada como porcentaje sobre la suma de los puntajes maximos d todos los ejercicios


class Ejercicio{
public:
	Ejercicio (int puntaje, string enunciado,bool solo_libres);
	string VerEnunciado();
	int VerPuntajeMaximo();
	
};

class Examen{
private:
	vector<Ejercicio> m_lista;
	string m_materia;
	int m_fecha;
public:
	Examen(string materia,int fecha):m_materia(materia),m_fecha(fecha){}
	string VerMateria() {return m_materia;}
	int VerFecha() {return m_fecha;}     ///se pone const pq se supone q estos metodos no modifican, solo muestran
	void AgregarEjercicio(Ejercicio e){ m_lista.push_back(e);} ///push back del ejercicio a la lista
	int VerCantidadDeEjercicios(){return m_lista.size();}
	Ejercicio VerEjercicio(int i){return m_lista[i-1];}
	int CalcularNotaFinal(vector<int> &pts){
		int sum_al=0, sum_temario=0;
		for(int i=0;i<m_lista.size();i++){
			sum_al+=pts[i];
			sum_temario+=m_lista.VerPuntajeMaximo[i];
		}
		return (100*sum_al)/sum_temario;
	}
};

int main() {
	
	Examen parcial1("PROGRAMACION",20201006); //fecha del parcial y nombre de materia
	Examen parcial2("ALGEBRA",20201009);
	/*Ejercicio ej1(30,"Escriba un programa para...",false);  ///30 puntos, enunciado y si es libre o no
	parcial1.AgregarEjercicio(ej1);*////funcion agrega un ejercicio del parcila 1
	
	Ejercicio ej1(30,"Escriba un programa para...",false);
	parcial1.AgregarEjercicio(ej1);
	Ejercicio ej2(20,"Realice un puntero...",false);
	parcial2.AgregarEjercicio(ej2);
	
	
	
	vector <int> pts;
	for(int i=0;i<parcial1.VerCantidadDeEjercicios();i++){
		Ejercicio ej=parcial1.VerEjercicio(i);
		cout<<" Ej "<<i<<": "<<ej.VerEnunciado()<<endl;
		cout<<" Ej "<<i<<": "<<ej.VerPuntajeMaximo()<<endl;
		cout<<"ingrese puntaje del aalumno para este ejercicio"<<endl;
		int p; cin>>p; pts.push_back(p);
		
	}
	
	cout<<"NOTA FINAL DEL ALUMNO: "<<parcial1.CalcularNotaFinal();
	
	return 0;
}

