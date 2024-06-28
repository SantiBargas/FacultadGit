#include <iostream>
#include <vector>
using namespace std;


int main() {
	cout<<"ingrese cuantos atletas participan de la carrera"<<endl;
	int n;
	cin>>n;
	int cont=0;
	string Nombre;
	int tiempo;

	vector<int>Atleta(n);
	vector<string>Nombres(n);
	
	int mejortiempo=1000000,sdotiempo=1000000;
	string nombremejor,sdonombremejor;
	do{
		cout<<"ingrese nombre del atleta"<<endl;
		cin>>Nombre;
		Nombres[cont]=Nombre;
		
		cout<<"ingrese tiempo del atleta en segundos"<<endl;
		cin>>tiempo;
		Atleta[cont]=tiempo;
		
		if(Atleta[cont]<mejortiempo){
			mejortiempo=sdotiempo;
			nombremejor=sdonombremejor;
			
			mejortiempo=Atleta[cont];
			nombremejor=Nombres[cont];
		}
		else{
			if(Atleta[cont]<sdotiempo){
				sdotiempo=Atleta[cont];
				sdonombremejor=Nombres[cont];
			}
		}
		cont++;
		
		
	} while(cont<n);
	
	cout<<"el mejor corredor es "<<nombremejor<<" con un tiempo de "<<mejortiempo<<endl;
	cout<<"el 2do mejor corredor es "<<sdonombremejor<<" con un tiempo de "<<sdotiempo<<endl;
	
	int conta=0;
	for (size_t i=0;i<Atleta.size();i++){
		if(Atleta[i]<=(sdotiempo+5)){
			if (Atleta[i]>sdotiempo){
				conta++;
			}
		}
	}
	cout<<"la cantidad de atletas que estuvieron a 5 segundos o menos de obtener el segundo lugar son "<<conta;
	
	return 0;
}

