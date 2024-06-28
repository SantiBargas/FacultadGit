#include <iostream>
#include <matrix>
using namespace std;


int getpromediofila(matrix<int>M,int fila); ///fila es lo que se va a promediar
void reemplazarfila(matrix<int>&M, int fila);

int main() {
	matrix<int>M(5,12);
	
	for (int i = 0;i<M.size(0);i++){
		for (int j = 0;j<M.size(1);j++){
			M[i][j]= -5 + rand()%20;
			cout<<M[i][j]<<"   ";
		}
		cout<<endl<<endl;
	}
	
	for (int fila = 0;fila<M.size(0);fila++){
		reemplazarfila(M,fila);
	}
	cout<<endl<<endl;
	
	for (int i = 0;i<M.size(0);i++){
		for (int j = 0;j<M.size(1);j++){
			cout<<M[i][j]<<"   ";
		}
		cout<<endl<<endl;
	}
	cout<<endl<<endl;
	
	M.resize(M.size(0),M.size(1)+1);
	
	int prom=0;
	for (int i=0;i<M.size(0);i++){
		int suma=0;
		for(int j=0;j<M.size(1)-1;j++){
			suma+=M[i][j];
			
		}
		M[i][M.size(1)-1]=(suma/12);
	}
	
	for (int i = 0;i<M.size(0);i++){
		for (int j = 0;j<M.size(1);j++){
			cout<<M[i][j]<<"   ";
		}
		cout<<endl<<endl;
	}
	return 0;
}

int getpromediofila(matrix<int>M,int fila){
	///sumar y contar valor positivos de la fila
	int suma=0;
	int conteo=0;
	
	for (int col=0; col<M.size(1);col++){
		if(M[fila][col]>=0){
			suma+=M[fila][col];
			conteo ++; ///para sacar promedio
		}
	}
	return (suma/conteo);
}

void reemplazarfila(matrix<int>&M, int fila){
	int prom;
	for(int i=0;i<M.size(1);i++){
		if (M[fila][i]<0){
			///llamar a la funcion de la fila
			prom = getpromediofila(M,fila);
			M[fila][i]=prom;
		}
	}
	
	
}
