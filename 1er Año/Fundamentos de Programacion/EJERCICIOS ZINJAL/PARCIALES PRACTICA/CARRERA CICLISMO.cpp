#include <iostream>
#include <vector>
using namespace std;
struct ciclista{
	string nombre;
	vector<int>tiempos;
};
int main() {
	int N,min,seg,tiempo,minutos,segundos;
	cout<<"ingrese cant de cilclistas"<<endl;
	cin>>N;
	vector<ciclista>nombres(N);
	string apellido;
	
	for (int i=0;i<N;i++){
		ciclista c;
		cout<<"ingrese nombre del competidor"<<endl;
		cin.ignore();
		getline(cin,c.nombre);
		
		cout<<"ingrese apellido del competidor"<<endl;
		cin.ignore();
		getline(cin,apellido);
		
		c.tiempos.resize(3);
		
		for(int j=0;j<3;j++){
			cout<<"ingrese los minutos"<<endl;
			cin>>min;
			cout<<"ingrese los segundos"<<endl;
			cin>>seg;
			
			tiempo=min*60+seg;
			
			c.tiempos[j]=tiempo;
		}
		
	}
	int menorcorredor,menortiempo=100000000000;
	ciclista aux;
	for(int i=0;i<nombres.size();i++){
		int suma=0;
		for(int j=0;j<nombres[i].tiempos.size();j++){
			suma+=nombres[i].tiempos[j];
		}
		if(suma<menortiempo){
			menortiempo=suma;
			menorcorredor=aux.nombre[i];
		}
	}
	
	cout<<"el corredor mas rapido es: "<<menorcorredor<<endl;
	minutos=menortiempo/60;
	segundos=tiempo-(60*minutos);
	
	cout<<"con: "<<minutos<<" minutos y "<<segundos<<" segundos"<<endl;
	
	return 0;
}

