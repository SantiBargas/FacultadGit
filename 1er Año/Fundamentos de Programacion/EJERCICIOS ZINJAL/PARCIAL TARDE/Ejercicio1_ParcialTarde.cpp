#include <iostream>
#include <matrix>
using namespace std;


/// egresadosUniv.size(0) -> retorna la cantidad de filas de una matriz
/// egresadosUniv.size(1) -> te da la cantidad de columnas de una matriz



int main() {
	matrix<int>egresadosUniv(8,10,0);
	int codUniversidad, numEgresados, anio;
	int col;
	int aniofinal= 2019;
	int anioinicial= aniofinal-9;
	int suma;
	
	cout<<"Ingrese Cod Universidad, 1 a 8 (0 Termina)"<<endl;
	cin>>codUniversidad;
	
	while (codUniversidad !=0){
		cout<<"Ingrese año"<<endl;
		cin>>anio;
		
		cout<<"Ingrese cant egresados"<<endl;
		cin>>numEgresados;
		
		col= anio - anioinicial; ///Para que la columna quede de 0 a 9
		
		egresadosUniv[codUniversidad-1][col]=+numEgresados; ///Es lo mismo anio - 2010
		
		cout<<"Ingrese Cod Universidad, 1 a 8 (0 Termina)"<<endl;
		cin>>codUniversidad;
	}
	
	///Inciso A Año con mayor cantidad de egresados	
	int anioMayorNumEgresados =0;
	int mayorEgresados =0;
	
	for (int j=0;j<10;j++){
		///por cada año sumo los egresados de las 8 universidades
		suma=0;
		for (int i=0;i<8;i++){
			suma+= egresadosUniv[i][j];
		}
		
		if (suma > mayorEgresados){
			mayorEgresados=suma;
			anioMayorNumEgresados=anioinicial+j;
		}
	}
	
	cout<<"El año con mas egresados es "<<anioMayorNumEgresados<<" con "<<mayorEgresados<<endl;

	///Inciso B
	cout<<"La cantidad de egresados de la universidad 4 año 2014 es"<<egresadosUniv[3][4]
	
	
	///Inciso C
	int cantUniv= 0

	
	for (int codUniversidad=0;codUniversidad<egresadosUniv.size[1];codUniversidad++){
			if (egresadosUniv[codUniversidad][2]<20){
				/// si tuvo menos de 20 egresados se hace el recuento
				cantUniv++;
			}
	}
	
	cout<<" hubo "<<cantUniv<<" universidades con menos de 20 egresados en 2012"<<endl;
	return 0;
}

