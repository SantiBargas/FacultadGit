#include <iostream>
#include <vector>
using namespace std;
struct ciclista{
	string apellido;
	string nombre;
	int num;
	int h1,m1,s1;
};

int ganador(vector<ciclista>lista);

int main() {
	
	vector<ciclista>lista(3);
	
	for(int i=0;i<3;i++){
		
		cout<<"ingrese apellido"<<endl;
		cin.ignore();
		getline(cin,lista[i].apellido);
		cout<<"ingrese nombre"<<endl;
		getline(cin,lista[i].nombre);
		cout<<"ingrese num atleta"<<endl;
		cin>>lista[i].num;
		cout<<"ingrese tiempo en horas,seg y min"<<endl;
		cin>>lista[i].h1>>lista[i].m1>>lista[i].s1;
	}
	
	int mayorciclista=ganador(lista);
	cout<<"el ganador es:------------------------------"
	cout<<"apellido: "<<lista[mayorciclista].apellido<<endl;
	cout<<"nombre: "<<lista[mayorciclista].nombre<<endl;
	cout<<"num atleta: "<<lista[mayorciclista].num<<endl;
	cout<<"horas: "<<lista[mayorciclista].h1<<endl;
	cout<<"minutos: "<<lista[mayorciclista].m1<<endl;
	cout<<"seg: "<<lista[mayorciclista].s1<<endl;
	
	for(int i=0;i<lista.size();i++){
		if(lista[i].h1!=0 and lista[i].m1!=0 and lista[i].s1!=0){
			cout<<"apellido: "<<lista[i].apellido<<endl;
			cout<<"nombre: "<<lista[i].nombre<<endl;
			cout<<"num atleta: "<<lista[i].num<<endl;
			cout<<"horas: "<<lista[i].h1<<endl;
			cout<<"minutos: "<<lista[i].m1<<endl;
			cout<<"seg: "<<lista[i].s1<<endl;
		}
	}
	
	return 0;
}
int ganador(vector<ciclista>lista){
	
	int suma,hora,min,mayorsuma=0,mayorciclista=0;
	
	for(int i=0;i<lista.size();i++){
		suma=1000000000000;
		hora=lista[i].h1*3600;
		min=lista[i].m1*60;
		suma=hora+min+lista[i].s1;
		if(suma<mayorsuma){
			suma=mayorsuma;
			mayorciclista=i;
		}
		
	}
	return mayorciclista;
}
