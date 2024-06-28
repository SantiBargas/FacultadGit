#include <iostream>
#include <matrix>
using namespace std;

float diferencia(matrix<int>humedad);
matrix<int>calcularpromedios(matrix<int>humedad);

int main() {
	
	matrix<int>humedad(10,10,0);
	
	for(int i=0;i<humedad.size(0);i++){
		for(int j=0;j<humedad.size(1);j++){
			
			humedad[i][j]=1+rand()%100;
		}
	}
	
	for(int i=0;i<humedad.size(0);i++){
		for(int j=0;j<humedad.size(1);j++){
			
			cout<<humedad[i][j]<<"     ";
		}
		cout<<endl;
	}
	
	int total=diferencia(humedad);
	cout<<"la diferencia entre la mayor y menor % de humedad es de: "<<total<<"%"<<endl;
	
	
	matrix<int>promedios=calcularpromedios(humedad);
	
	for(int i=0;i<promedios.size(0);i++){
		for(int j=0;j<promedios.size(1);j++){
			
			cout<<promedios[i][j]<<"     ";
		}
		cout<<endl;
	}
	int suma,prom;
	for (int j=0;j<humedad.size(1);j++){
		suma=0;
		for(int i=0;i<humedad.size(0);i++){
			suma+=humedad[i][j];
		}
		prom=suma/humedad.size(1);
		cout<<"el promedio de humedades de la columna "<<j+1<<" es: "<<prom<<endl;
	}
	
	return 0;
}
float diferencia(matrix<int>humedad){
	
	int mayor=0,menor=200;
	
	for(int i=0;i<humedad.size(0);i++){
		for(int j=0;j<humedad.size(1);j++){
			
			if(humedad[i][j]>mayor){
				mayor=humedad[i][j];
			}	
			if(humedad[i][j]<menor){
				menor=humedad[i][j];
			}
		}
	}
	
	float total=mayor-menor;
	return total;
}
matrix<int>calcularpromedios(matrix<int>humedad){
	matrix<int>aux(humedad.size(0)/2,humedad.size(1)/2);
	///matriz auxiliar con mitad del tamaño de la original
	
	int indfila=0,indcol=0; ///necesito variables auxiliares para indices
	int prom;
	for (int i=0;i<humedad.size(0);i=i+2){
		indcol=0;
		for (int j=0;j<humedad.size(1);j=j+2){
			prom=(humedad[i][j]+humedad[i][j+1]+humedad[i+1][j]+humedad[i+1][j+1])/4;
			aux[indfila][indcol]=prom;
			indcol++;
		}
		indfila++;
	}
	return aux; ///retornar la matriz resultante
	
	
	
	
	
	
	
}
