#include <iostream>
#include <matrix>
using namespace std;

int main() {
	
	matrix<int>lista(200,35,0);
	
	for (int i=0;i<lista.size(0);i++){
		cout<<"ingrese nota del alumno: "<<i+1<<endl;
		for (int j=0;j<lista.size(1);j++){
			cout<<" de la materia: "<<j+1<<endl;
			cin>>lista[i][j];
		}	
	}
	
	float suma=0,prom,mejorprom=0,mejoralum;
	for (int i=0;i<lista.size(0);i++){
		
		for (int j=0;j<lista.size(1);j++){
			suma+=lista[i][j];
		}
		prom=suma/35;
		if(prom>mejorprom){
			mejorprom=prom;
			mejoralum=i;
		}
		suma=0;
	}
	cout<<"el mejor promedio es de"<<mejorprom<<" del alumno "<<mejoralum+1<<endl;
	
	float sum=0,prome,menorprom=1000,menormat;
	
	for (int j=0;j<lista.size(1);j++){
		for (int i=0;i<lista.size(0);i++){
			sum+=lista[i][j];
		}
		prome=sum/200;
		if(prome<menorprom){
			menorprom=prome;
			menormat=j;
		}
		suma=0;
	}
	
	cout<<"el menor promedio es de "<<menorprom<<" de la materia "<<menormat+1<<endl;
	
	for (int i=0;i<lista.size(0);i++){
		for (int j=0;j<lista.size(1);j++){
			cout<<lista[i][j]<<"   ";
		}
		cout<<endl;
	}
	

	return 0;
}

