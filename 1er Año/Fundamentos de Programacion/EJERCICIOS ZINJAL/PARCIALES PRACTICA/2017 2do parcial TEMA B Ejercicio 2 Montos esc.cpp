#include <iostream>
#include <matrix>
using namespace std;

int main() {
	matrix<int>Escuela(10,12,100000);
	
	int codesc,mes,dia,anio,monto;
	cout<<"ingrese el codigo de la escuela 1 a 10, en 0 termina"<<endl;
	cin>>codesc;
	
	while(codesc!=0){
		cout<<"ingrese mes (1 a 12) dia y año"<<endl;
		cin>>mes>>dia>>anio;
		
		cout<<"ingrese monto"<<endl;
		cin>>monto;
		
		Escuela[codesc-1][mes-1]-=monto;
		
		cout<<"ingrese el codigo de la escuela 1 a 10, en 0 termina"<<endl;
		cin>>codesc;
	}
	
	for (int i=0;i<Escuela.size(0);i++){
		for (int j=0;j<Escuela.size(1);j++){
			cout<<Escuela[i][j]<<"   ";
		}
		cout<<endl;
	}
	
	int total;
	for (int i=0;i<Escuela.size(0);i++){
		total=0;
		for (int j=0;j<Escuela.size(1);j++){
			total+=Escuela[i][j];
		}
		cout<<"a la escuela "<<i<<" le sobraron "<<total<<" pesos"<<endl;
	}
	
	int cant=0;
	for (int i=0;i<Escuela.size(0);i++){
		if(Escuela[i][1]==0){
			cant++;
		}
	}
	cout<<cant<<" de escuelas gastaron todo en febrero"<<endl;
	
	int menosgasto=999999999999;
	int escmenos=0;
	for (int i=0;i<Escuela.size(0);i++){
		if(Escuela[i][9]<menosgasto){
			menosgasto=Escuela[i][9];
			escmenos=i;
		}
	}
	cout<<"la escuela q menos gasto en oct es "<<escmenos<<" con un monto de"<<menosgasto<<endl;
	
	return 0;
}

