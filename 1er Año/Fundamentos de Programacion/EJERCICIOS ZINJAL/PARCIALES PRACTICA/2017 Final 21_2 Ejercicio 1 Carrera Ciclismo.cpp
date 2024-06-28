#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct ciclista{
	string nombre;
	vector<int>tiempos;
};
tuple<int,int>convertirtiempo(int tiempo);
ciclista getganador(vector<ciclista>lista);	
int main() {
	int Cant,m,s,tiempo;
	
	cout<<"ingrese cantidad de competidores"<<endl;
	cin>>Cant;
	vector<ciclista>lista(Cant);
	
	///Ingresar los competidores y sus 3 tiempos
	for (int i=0;i<Cant;i++){
		ciclista c;
		cout<<"ingrese nombre del competidor"<<endl;
		cin>>c.nombre;
		c.tiempos.resize(3);
		///Leer 3 tiempos
		
		for (int j=0;j<3;j++){
			cout<<"ingrese los minutos"<<endl;
			cin>>m;
			cout<<"ingrese los segundos"<<endl;
			cin>>s;
			tiempo=m*60+s;
			
			c.tiempos[j]=tiempo;
			
		}
		lista.push_back(c); ///agrego el competidor a la lista
	}

	
	
	return 0;
}
tuple<int,int>convertirtiempo(int tiempo){
	int m,s;
	m=tiempo/60;
	s=tiempo-(m*60);
	
return make_tuple(m,s);
}
ciclista getganador(vector<ciclista>lista){
	int menortiempo=1000000000;
	ciclista aux;
	
	
	for (int i=0;i<lista.size();i++){
		int suma=0;
		for (int j=0;j<lista[i].tiempos.size();j++){
			suma+=lista[i].tiempos[j];
		}
		if(suma<menortiempo){
			aux=lista[i];
		}
	}
	return aux;
}
