#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct evento{
	string tipo;
	int jugador;
};

tuple<int,int,int,int,int> resumen_partido(vector<evento>lista,int jug);

int main() {
	int cant;
	cout<<"ingrese cant d eventos"<<endl;
	cin>>cant;
	
	vector<evento>lista(cant);
	
	for (int i=0;i<lista.size();i++){
		cout<<"ingrese jugador"<<endl;
		cin>>lista[i].jugador;
		
		cout<<"ingrese tipo de evento: ace error no forzado tiro ganador doble falta quiebre"<<endl;
		cin.ignore();
		getline(cin,lista[i].tipo);
	}
	
	int ace,error,tiro,doble,quiebre,jug;
	cout<<"ingrese jugador que desea saber estadisticas, 1 o 2"<<endl;
	cin>>jug;
	
	tie(ace,error,tiro,doble,quiebre)=resumen_partido(lista,jug);
	
	cout<<"el jugador "<<jug<<"realizo :"<<endl;
	cout<<ace<<" tipo de jugada ace"<<endl;
	cout<<error<<" tipo de jugada error"<<endl;
	cout<<tiro<<" tipo de jugada tiro ganador"<<endl;
	cout<<doble<<" tipo de jugada doble"<<endl;
	cout<<quiebre<<" tipo de jugada quiebre"<<endl;
	
	
	return 0;
}

tuple<int,int,int,int,int> resumen_partido(vector<evento>lista, int jug){
	
	int ace=0,error=0,tiro=0,doble=0,quiebre=0;
	
	for (int i=0;i<lista.size();i++){
		if (lista[i].jugador==jug){
			if(lista[i].tipo=="ace"){
				ace++;
			}
			if(lista[i].tipo=="error no forzado"){
				error++;
			}
			if(lista[i].tipo=="tiro ganador"){
				tiro++;
			}
			if(lista[i].tipo=="doble falta"){
				doble++;
			}
			if(lista[i].tipo=="quiebre"){
				quiebre++;
			}
			
		}
	}
	return make_tuple(ace,error,tiro,doble,quiebre);
}
