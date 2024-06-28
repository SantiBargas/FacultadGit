#include <iostream>
#include <matrix>
#include <cstdlib>
using namespace std;

int main() {
	matrix<int>M(6,4,0); ///El tercer valor es para declarar la matriz en 0
		
		///Llenar la matriz con valores aleatorios
		///En una matriz el size(0) retorna la cantidad de filas
		///El size (1) retorna la cantidad de columnas
		for (int fila = 0;fila<M.size(0);fila++){
			for (int col= 0;col<M.size(1);col++){
				M[fila][col] = 100 + rand() % 700;
				cout<<M[fila][col]<<"   ";
			}
			cout<<endl<<endl;
		}
		
		cout<<" Elemento 2da fila 4ta columna"<<M[1][3]<<endl<<endl;
		///1 y 3 porque siempre empieza en 0 y 0
		
		cout<<" la 5ta fila es "<<endl;
		for (int col = 0;col<M.size(1);col++) {
			cout<<M[4][col]<<"    ";
		};
		cout<<endl<<endl;
		
		cout<<"la 3er columna es"<<endl;
		for (int fila = 0;fila<M.size(1);fila++) {
			cout<<M[fila][2]<<"     ";
		}
		
	return 0;
}

