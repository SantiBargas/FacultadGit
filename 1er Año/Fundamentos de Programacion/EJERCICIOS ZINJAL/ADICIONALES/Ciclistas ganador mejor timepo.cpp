#include <iostream>
#include <vector>
using namespace std;

struct ciclista{
	string apellido;
	string nombre;
	int numeroasignado;
	int h1;
	int m1;
	int s1;
};

int ganador(vector<ciclista>lista);

int main() {
	int cont=0;
	vector<ciclista>lista;
	
	while(cont<2){
		
		ciclista c;
		cout<<"ingrese numero asignado del atleta"<<endl;
		cin>>c.numeroasignado;
		
		
		
		cout<<"ingrese nombre del ciclista"<<endl;
		cin>>c.nombre;
		
		cout<<"ingrese apellido del ciclista"<<endl;
		cin>>c.apellido;
		
		cout<<"ingrese tiempo del cilista en horas minutos y segundos"<<endl;
		cout<<"si el cilista no termino la carrera ingrese  0,0,0"<<endl;
		cin>>c.h1;
		cin>>c.m1;
		cin>>c.s1;
		
		lista.push_back(c);
		cont++;
		
	} 
	
	int hola;
	hola=ganador(lista);
	cout<<"el ganador es: "<<endl;
	cout<<lista[hola].nombre<<endl;
	cout<<lista[hola].apellido<<endl;
	cout<<lista[hola].numeroasignado<<endl;
	cout<<"con un tiempo de"<<endl;
	cout<<lista[hola].h1<<" horas "<<lista[hola].m1<<" minutos "<<lista[hola].s1<<" Segundos "<<endl;
	
	cout<<"los ciclistas que terminaron la carrera son"<<endl;
	for (int i=0;i<lista.size();i++){
		if(lista[i].h1!=0 && lista[i].m1!=0 && lista[i].s1!=0){
			cout<<"nombre : "<<lista[i].nombre<<endl;
			cout<<"apellido : "<<lista[i].apellido<<endl;
			cout<<"numero asignado : "<<lista[i].numeroasignado<<endl;
			cout<<"tiempo : "<<lista[i].h1<<" "<<lista[i].m1<<" "<<lista[i].s1<<endl;
		}
		cout<<endl;
	}
	
	
	return 0;
}

int ganador(vector<ciclista>lista){
	
	int menorhora=100;
	int menormin=100;
	int menorseg=100;
	int gan;
	
	for (int i=0;i<lista.size();i++){
		
		if(lista[i].h1<menorhora and lista[i].h1!=0){
			if (lista[i].m1<menormin and lista[i].m1!=0){
				if(lista[i].s1<menorseg and lista[i].s1!=0){
					gan = i;
				}
			}
		   
		}
	}
	
	return gan;
	
}
	
