#include <iostream>
#include <matrix>
using namespace std;

int calcular_promedio(matrix<int>formula);

int main() {
	int codeq,codsist,calif;
	matrix<int>formula(10,3);
	cout<<"ingrese codigo de equipo en 0 termina"<<endl;
	cin>>codeq;
	
	while(codeq!=0){
		cout<<"ingrese sistema"<<endl;
		cin>>codsist;
		cout<<"ingrese calificaion, si no aprueba -1"<<endl;
		cin>>calif;
		
		formula[codeq-1][codsist-1]+=calif;
		cout<<"ingrese codigo de equipo en 0 termina"<<endl;
		cin>>codeq;
	}
	
	for (int i=0;i<formula.size(0);i++){
		for (int j=0;j<formula.size(1);j++){
			cout<<formula[i][j]<<"    ";
		}
		cout<<endl;
	}
	
	int suma;
	for(int i=0;i<formula.size(0);i++){
		suma=0;
		for (int j=0;j<formula.size(1);j++){
			suma+=formula[i][j];
		}
		if(suma>=3){
			cout<<"el equipo: "<<i+1<<" aprobo los 3 sistemas"<<endl;
			cout<<"con una calificacion total de: "<<suma<<endl;
		}
	}

	int sistemamayor=calcular_promedio(formula);
	if(sistemamayor==0){
		cout<<"el nombre del sistema que obtuvo mayor promedio es 'SHIELD'";}
	if(sistemamayor==1){
		cout<<"el nombre del sistema que obtuvo mayor promedio es 'HALO'";}
	if(sistemamayor==2){
		cout<<"el nombre del sistema que obtuvo mayor promedio es 'GHOST'";
	}
	return 0;
}
int calcular_promedio(matrix<int>formula){
	
	int suma,prom,nombre;
	int mayorprom=0;
	
	for(int j=0;j<formula.size(1);j++){
		suma=0;
		for (int i=0;i<formula.size(0);i++){
			suma+=formula[i][j];
		}
		prom=suma/formula.size(0);
		if(prom>mayorprom){
			mayorprom=prom;
			nombre=j;
		}
	}
	return nombre;
}
