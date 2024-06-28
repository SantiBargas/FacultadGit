#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<string>corredores(65,""); ///vector de 65 corredores con espacio en blanco
	vector<int>tiempos(65,0);    ///vector de 65 tiempos
	
	
	int num,tiempo,th,tm,ts,tiempototal;
	string corredor;
	
	/// tiempo = th*3600 + tm *60 + ts
	
	cout<<" ingrese numero de corredor"<<endl;
	cin>> num;
	
	while (num !=0){
		
		cout<<"ingrese nombre y apellido del corredor"<<endl;
		cin>>corredor;	
		
		cout<<"ingrese tiempo en horas, minutos y segundos del corredor"<<endl;
		cin>>th;
		cin>>tm;
		cin>>ts;
		
		tiempo= th*3600 +tm *60+ts;
		
		corredores[num-1]=corredor;
		tiempos[num-1]=tiempo;
		
		cout<<" ingrese numero de corredor en 0 termina"<<endl;
		cin>> num;
	}
	
	
	///Inciso A   Mostrar los dos ganadores
	int ganador1= 100000;
	int ganador2=1000000;
	int numgana1,numgana2;
	
	for (int i=0; i<65;i++){
		if (tiempos[i]!=0){
			if (tiempos[i]<ganador1){
				numgana2=numgana1;
				ganador2=ganador1;
				///ahora si se toma el nuevo ganador1
				numgana1= i;
				ganador1=tiempos[i];
			}	
			else{
				if (tiempos[i]<ganador2){
					numgana2=i;
					ganador2=tiempos[i];
				}
			}	
		}
		
	}
	
	cout<<" el ganador es"<<corredores[numgana1]<<" con "<<ganador1<<" segundos "<<endl;
	cout<<" el 2do es "<<corredores[numgana2]<<" con "<<ganador2<<" segundos"<<endl;
	
	return 0;
}

