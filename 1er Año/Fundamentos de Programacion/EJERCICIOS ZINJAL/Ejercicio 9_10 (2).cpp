#include <iostream>
#include <matrix>
using namespace std;

int Promediofila(matrix<int>M, int fila);
void Reemplazarfila(matrix<int>&M, int fila);

int main() {
	matrix<int> M(3,5,0);
	
	for (int i=0;i<M.size(0);i++){
		for(int j=0;j<M.size(1);j++){
			M[i][j]= -10 + rand()%50;
			cout<<M[i][j]<<"   ";
		}
		cout<<endl;
	}
	
	for (int fila=0;fila<M.size(0);fila++){
		Reemplazarfila(M,fila);
	}
	cout<<endl;
	
	for (int i=0;i<M.size(0);i++){
		for(int j=0;j<M.size(1);j++){
			
			cout<<M[i][j]<<"   ";
		}
		cout<<endl;
	}
	
	
	cout<<endl; 
	M.resize(M.size(0),M.size(1)+1);
	
	for(int fila=0;fila<M.size(0);fila++){
		int suma=0;
		for(int col=0;col<M.size(1)-1;col++){
			suma+=M[fila][col];
		}
		M[fila][M.size(1)-1]=suma;
	}
	
	for (int i=0;i<M.size(0);i++){
		for(int j=0;j<M.size(1);j++){
			
			cout<<M[i][j]<<"   "<<"    ";
		}
		cout<<endl;
	}
	
	return 0;
}

int Promediofila(matrix<int>M, int fila){
	
	int suma=0, conteo=0;
	
	for (int col=0;col<M.size(1);col++){
		if (M[fila][col]>=0){
			suma+=M[fila][col];
			conteo++;
		}
	}
	return suma/conteo;
}

void Reemplazarfila(matrix<int>&M, int fila){
	int prom;
	for (int col=0;col<M.size(1);col++){
			if(M[fila][col]<0){
				prom=Promediofila(M,fila);
				M[fila][col]=prom;
			}
		}
	}
	
	

