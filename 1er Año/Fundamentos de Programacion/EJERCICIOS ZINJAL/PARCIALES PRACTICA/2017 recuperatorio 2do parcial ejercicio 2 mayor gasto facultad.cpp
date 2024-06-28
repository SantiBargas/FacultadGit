#include <iostream>
#include <matrix>
#include <tuple>
using namespace std;

void gastos(matrix<int> escuela);
int deficit(matrix<int> escuela);
tuple<int,int> mayor(matrix<int>escuela);

int main() {
	matrix<int>escuela(10,12,500);
	
	int cod_facultad,mes,monto;
	
	cout<<"ingrese codigo facultad -1 termina"<<endl;
	cin>>cod_facultad;
	while (cod_facultad!=-1){
		
		cout<<"ingrese mes 1 a 12"<<endl;
		cin>>mes;
		
		cout<<"ingrese monto gastado"<<endl;
		cin>>monto;
		
		escuela[cod_facultad-1][mes]-=monto;
		cout<<"ingrese codigo facultad -1 termina"<<endl;
		cin>>cod_facultad;
		
	}
	
	for(int i=0;i<escuela.size(0);i++){
		for(int j=0;j<escuela.size(1);j++){
			cout<<escuela[i][j]<<"    "; 
		}
		cout<<endl;
	}
	
	gastos(escuela);
	cout<<"la cantidad de escuelas que finalizaron el año con deficit son"<<deficit(escuela)<<endl;
	
	int mayorgasto,nummayor;
	tie(nummayor,mayorgasto)=mayor(escuela);
	cout<<"la facultad q mas gasto es "<<nummayor<<" con un monto de "<<mayorgasto;
	return 0;
}

void gastos(matrix<int> escuela) {
	int suma=0;
		for(int i=0;i<escuela.size(0);i++){
		for (int j=0;j<escuela.size(1);j++){
			suma+=escuela[i][j];
		}
		cout<<"A la facultad "<<i+1<<" le quedo sin gastar"<<suma<<endl;
		suma=0;
	}
}
int deficit(matrix<int> escuela){
	int cont=0;
	int suma=0;
	for(int i=0;i<escuela.size(0);i++){
		for (int j=0;j<escuela.size(1);j++){
			suma+=escuela[i][j];
		}
		if(suma<0){
			cont++;
		}
		suma=0;
	}	
	return cont;
}
tuple<int,int> mayor(matrix<int>escuela){
	int mayorgasto=6000,nummayor,suma=0;
	
	
	for(int i=0;i<escuela.size(0);i++){
		for (int j=0;j<escuela.size(1);j++){
			suma+=escuela[i][j];
		}
		if(suma<mayorgasto){
			mayorgasto=suma;
			nummayor=i+1;
		}
	}
	return	make_tuple(nummayor,mayorgasto);
	
}
