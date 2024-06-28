#include <iostream>
using namespace std;

int main() {
	
	int **m = new int *[10];
	
	///Por cada puntero, reservamos memoria para 6 lugares
	for (int i=0;i<10;i++){
		m[i]= new int[6];
	}
	
	///llenando la matriz
	for (int i=0;i<10;i++){
		for(int j=0;j<6;j++){
			*(m[i] + j)=10+rand()%50;
		}
	}
	
	int fila;
	int suma=0;
	cout<<"ingrese fila a promediar"<<endl;
	cin>>fila;
	
	for(int i=0;i<6;i++){
		suma+= *(m[fila]+i);
	}
	cout<<"la suma es "<<suma<<" el promedio"<<suma/6<<endl;
	
	
	for(int j=0;j<6;j++){
		suma=0;
		for(int i=0;i<10;i++){
			suma+=*(m[i]+j);
		}
		cout<<" la suma de la columa "<<j+1<<" es: "<<suma<<endl;
	}
	
	
	///liberar la memoria
	for(int i=0;i<10;i++){
		delete []m[i];
	}
	
	return 0;
}

