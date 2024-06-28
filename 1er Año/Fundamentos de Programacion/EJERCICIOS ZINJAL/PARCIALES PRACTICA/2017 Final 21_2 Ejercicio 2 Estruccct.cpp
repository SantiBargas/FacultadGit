#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct Evento{
	string tipo;
	int jugador;
};
tuple<int,int,int,int,int> resumen_partido(vector<Evento>lista , int num);
int main() {
	int cant_eventos;
	cout<<"ingrese cant eventos"<<endl;
	cin>>cant_eventos;
	vector<Evento>lista(cant_eventos);
	
	for(int i=0;i<cant_eventos;i++){
		Evento e;
		cout<<"ingrese tipo de jugador"<<endl;
		cin>>lista[i].jugador;
		
		cout<<"ingrese jugada"<<endl;
		cin.ignore();
		getline(cin, lista[i].tipo);
		
		lista.push_back(e);
	}
	int num;
	int	ace,enf,tig,dfa,qui;
	
	cout<<"ingrese jugador que desea saber"<<endl;
	cin>>num;
	tie(ace,enf,tig,dfa,qui)=resumen_partido(lista,num);

	
	cout<<"el jugador "<<num<<endl;
	cout<<"ace: "<<ace<<endl<<"enf: "<<enf<<endl<<"tig1:"<<tig<<endl<<"dfa "<<dfa<<endl<<"qui: "<<qui;
	
	return 0;
}

tuple<int,int,int,int,int> resumen_partido(vector<Evento>lista , int num){
	int ace=0,enf=0,tig=0,dfa=0,qui=0;
	for(int i=0;i<lista.size();i++){	
		if(lista[i].jugador==num){
			if (lista[i].tipo == "ace") 
				ace++;
			if (lista[i].tipo == "error no forzado")
				enf++;
			if (lista[i].tipo == "tiro ganador")
				tig++;
			if (lista[i].tipo == "doble falta")	
				dfa++;
			if (lista[i].tipo == "quiebre")
				qui++;
		}
	}	
return	make_tuple(ace,enf,tig,dfa,qui);
}

