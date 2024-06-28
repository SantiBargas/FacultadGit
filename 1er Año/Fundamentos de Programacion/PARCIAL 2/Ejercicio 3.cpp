#include <iostream>
#include <matrix>
using namespace std;

int main() {
	matrix<int> ventas(10,12,0);
	int cod_filial,mes,monto,leerfilial;
	
	cout<<"ingrese filial"<<endl;
	cin>>cod_filial;
	
	while(cod_filial!=-1){
		
		cout<<"ingrese mes"<<endl;
		cin>>mes;
		
		cout<<"ingrese monto"<<endl;
		cin>>monto;
		
		ventas[cod_filial-1][mes-1]+=monto;
		
		cout<<"ingrese filial"<<endl;
		cin>>cod_filial;
	}
	
	for(int i=0;i<ventas.size(0);i++){
		for(int j=0;j<ventas.size(1);j++){
			cout<<ventas[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<"de que filial desea saber los montos totales?"<<endl;
	cin>>leerfilial;
	
	cout<<"el total de marzo de esa filial es "<<ventas[leerfilial-1][2];
	cout<<"el total de abirl de esa filial es "<<ventas[leerfilial-1][3];
	cout<<"el total de agosto de esa filial es "<<ventas[leerfilial-1][7];
	
	int mayorfilial,mayormes,mayormonto=0;
	for(int i=0;i<ventas.size(0);i++){
		
		for(int j=0;j<ventas.size(1);j++){
			if(ventas[i][j]>mayormonto){
				mayormonto=ventas[i][j];
				mayormes=j;
				mayorfilial=i;
			}
		}
	}
	
	cout<<"el mayor monto es de "<<mayormonto+1<<" de la filial "<<mayorfilial+1<<" del mes "<<mayormes;
	
	return 0;
}

