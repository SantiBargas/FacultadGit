#include <iostream>
#include <matrix>
using namespace std;


matrix<int>crearsubmatriz(matrix<int>M, int f1, int c1, int f2, int c2);
	
int main() {
	matrix<int> M(10,10);
	
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			M[i][j]= 100+rand()%800;
			cout<<M[i][j]<<"    ";
		}
		cout<<"   "<<endl;
	}
	
	int f1,c1,f2,c2;
	cout<<"ingrese valores de fila 1 y columna 1"<<endl;
	cin>>f1>>c1;
	cout<<"ingrese valores de fila 2 y columna 2"<<endl;
	cin>>f2>>c2;
	
	matrix<int>aux = crearsubmatriz(M,f1,f2,c1,c2);
	cout<<endl<<endl;
	
	for (size_t i=0;i<aux.size(0);i++){
		for (size_t j=0;j<aux.size(1);j++){
			cout<<aux[i][j]<<"    ";
		}
		cout<<"   "<<endl;
	}
	
	return 0;
}

matrix<int>crearsubmatriz(matrix<int>M, int f1, int c1, int f2, int c2){

	
	int filas= (f2-f1)+1;
	int columnas= (c2-c1)+1;
	matrix<int>aux(filas,columnas); ///se forma con la diferencia de filas y columnas q ingreso el usuario
	
	
	int filaux = 0;
	int colaux;
	
	
	for (int i=f1;i<=f2;i++){
		colaux=0;
		for(int j=c1;j<=c2;j++){
			aux[filaux][colaux] = M[i][j];
			colaux++;
		}
		filaux++;
		
	}
	
	return aux;
}
