#include <iostream>
#include <matrix>
using namespace std;

int main() {
	matrix<int>Aportes(7,12,0); /// 7 cursos, 12 meses y puesta a 0
	
	int Curso,Mes,Importe;
	
	cout<<"ingrese curso, 1 a 7 (0 termina)"<<endl;
	cin>>Curso;
	
	while (Curso != 0){
		cout<<"Ingrese mes (1 a 12)"<<endl;
		cin>>Mes;
		cout<<"Ingrese Importe"<<endl;
		cin>>Importe;
		
		Aportes[Curso-1][Mes-1] += Importe;
		
		cout<<"ingrese curso 1 a 7 (0 termina"<<endl;
		cin>>Curso;
	}
	
	for (int Curso=0;Curso<Aportes.size(0); Curso++){
		cout<<"el curso "<<Curso<<endl;
		for(int Mes=0;Mes<Aportes.size(1); Mes++){
			cout<<"en el mes"<<Mes<<" aporto "<<Aportes[Curso][Mes]<<endl;
		}
	}
	
	int TotalJunio=0;
	for(Curso=0; Curso<Aportes.size(0);Curso++){
		TotalJunio+=Aportes[Curso][5];
	}
	cout<<"Total aportado en junio $ "<<TotalJunio<<endl;
	
	return 0;
}
 
