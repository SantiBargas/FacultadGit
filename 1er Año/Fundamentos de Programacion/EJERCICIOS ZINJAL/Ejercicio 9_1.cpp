#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cout<<"ingrese la cantidad de alumnos"<<endl;
	cin>>N;
	vector<int> notas(N);
	
	for (int i=0;i<notas.size();i++){
		cout<<"ingrese la nota del alumno"<<endl;
		cin>>notas[i];
	}
	
	int suma=0;
	for (int i=0;i<notas.size();i++){
		suma+=notas[i];
	}
	
	float promedio= suma/double(notas.size());
	int contador=0;
	for (int i=0;i<notas.size();i++){
		if(notas[i]>promedio){
			contador++;
		}
	}
	
	cout<<"la cantidad encima del promedio es "<<contador;
	return 0;
}

