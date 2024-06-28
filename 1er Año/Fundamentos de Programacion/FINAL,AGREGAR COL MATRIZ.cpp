#include <iostream>
#include <matrix>
#include <tuple>
using namespace std;

void amplia(matrix<int>&ventas);
tuple<int,int> mayor(matrix<int>ventas);
int cantidad(matrix<int>ventas);
int creciente(matrix<int>ventas);

int main() {
	
	int cod_pais,mes,dia,monto;
	
	matrix<int> ventas(15,12);
	cout<<"ingrese pais"<<endl;
	cin>>cod_pais;
	
	while (cod_pais!=0){
		
		cout<<"ingrese mes"<<endl;
		cin>>mes;
		cout<<"ingrese dia"<<endl;
		cin>>dia;
		cout<<"ingrese monto"<<endl;
		cin>>monto;
		
		ventas[cod_pais-1][mes-1]+=monto;
		
		cout<<"ingrese pais"<<endl;
		cin>>cod_pais;
		
	}
	
	for(int i=0;i<ventas.size(0);i++){
		for(int j=0;j<ventas.size(1);j++){
			cout<<ventas[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
	
	amplia(ventas);
	for(int i=0;i<ventas.size(0);i++){
		for(int j=0;j<ventas.size(1);j++){
			cout<<ventas[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl;
	
	int mayormes,mayorventa;
	tie(mayormes,mayorventa)=mayor(ventas);
	cout<<"la mayor venta es de "<<mayorventa<<" en el mes: "<<mayormes+1<<endl;
	
	int cant;
	cant=cantidad(ventas);
	cout<<"la cantidad de paises que no superan las ventas de 50.000$ son "<<cant<<endl;
	
	int mescorte=creciente(ventas);
	
	if(mescorte!=0){
		cout<<"la cadena creciente se corto en el mes "<<mescorte+1<<endl;
	}else{
		cout<<"es creciente";
	}
	
	return 0;
}
void amplia(matrix<int>&ventas){
	
	int suma;
	ventas.resize(ventas.size(0),ventas.size(1)+1);
	
	for(int i=0;i<ventas.size(0);i++){
		suma=0;
		for(int j=0;j<ventas.size(1)-1;j++){
			suma+=ventas[i][j];
		}
		ventas[i][ventas.size(1)-1]=suma;
	}
	
}

tuple<int,int> mayor(matrix<int>ventas){
	int mayormes,mayorventa=0;
	
	int suma;
	for(int j=0;j<ventas.size(1)-1;j++){
		suma=0;
		for(int i=0;i<ventas.size(0);i++){
			suma+=ventas[i][j];
		}
		if(suma>mayorventa){
			mayorventa=suma;
			mayormes=j;
		}
	}
	return make_tuple(mayormes,mayorventa);
}
int cantidad(matrix<int>ventas){
	int cant=0,suma;
	for(int i=0;i<ventas.size(0);i++){
		suma=0;
		for(int j=0;j<ventas.size(1)-1;j++){
			suma+=ventas[i][j];
		}
		if(suma<50000){
			cant++;
		}
	}
	return cant;
}
int creciente(matrix<int>ventas){
	int mescorte=0;
	for(int j=0;j<ventas.size(1)-1;j++){
		if(ventas[3][j+1]<=ventas[3][j]){
			mescorte=j+1;
			break;
		}
	}
	return mescorte;
}
