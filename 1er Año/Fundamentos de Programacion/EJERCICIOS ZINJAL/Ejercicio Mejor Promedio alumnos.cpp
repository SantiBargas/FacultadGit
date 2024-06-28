#include <iostream>
#include <matrix>
#include <tuple>
using namespace std;

using namespace std;
tuple<float,int>GetMejorPromedio(matrix<int>notas);
tuple<float,int>MenorPromedio(matrix<int>notas); 

int main() {
	matrix<int>notas(200,35,0);
	int codalumno,codmat,nota,codalu;
	
	///esto se tendria que hacer
	/*
	for(int i=0;i<7000;i++){
	cout<<"ingrese cod alumno"<<endl;
	cin>>codalu;
	cout<<"ingrese cod materia"<<endl;
	cin>>codmateria;
	cout<<"ingrese nota alumno"<<endl;
	cin>>nota;
	}*/
	
	for(int i=0;i<notas.size(0);i++){
		for(int j=0;j<notas.size(1);j++){
			notas[i][j]= 6+rand()%5;
		}
	}
	
	///codificar una funcion que retorne una tupla con el mejor promedio
	///de la carrera y el numero de alumno
	float a, mayor;
	tie(a,mayor) = GetMejorPromedio(notas);
	cout<<"El mejor promedio de la  carrera es: "<<mayor<<" del alumno "<<a<<endl ;
	
	float menorprom;
	int menornum;
	tie(menorprom,menornum)= MenorPromedio(notas);
	cout<<"el menor promedio es "<<menorprom<<" de la carrera "<<menornum<<endl;
	
	cout<<"la nota del alumno "<<a<<" del mejor promedio en la materia mas dificil es "<<notas[a][menornum];
	
	return 0;
}
tuple<float,int>GetMejorPromedio(matrix<int>notas){
	float promedio=0;
	float suma=0;
	float mayor = 0;
	int a;
	for (int i = 0;i<notas.size(0);i++){
		for (int j = 0 ;j<notas.size(1);j++){
			suma +=notas[i][j];
		}
		promedio = suma/35;
		if (promedio>mayor){
			mayor=promedio;
			a = i;
		}
		suma = 0;
	}
	return make_tuple(a,mayor);
}
tuple<float,int>MenorPromedio(matrix<int>notas) {
	int menornum;
	float prome,suma;
	float menorprom=10000;
	for(int j=0;j<notas.size(1);j++){
		suma=0;
		for(int i=0;i<notas.size(0);i++){
			suma+=notas[i][j];
		}
		prome=suma/notas.size(0);
		if(prome<menorprom){
			menorprom=prome;
			menornum=j;
		}
	}
	return make_tuple(menorprom,menornum);
}
