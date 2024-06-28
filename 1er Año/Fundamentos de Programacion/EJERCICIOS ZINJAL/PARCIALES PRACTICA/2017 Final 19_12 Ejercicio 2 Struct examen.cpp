#include <iostream>
#include <vector>
using namespace std;

struct ejercicio{
	string nombre;
	string texto;
	float puntaje;
	int dificultad;
};

int buscarejer(vector<ejercicio>lista, string buscar);

int main() {
	int N;
	cout<<"cuantos ejercicios hay?"<<endl;
	cin>>N;
	vector<ejercicio>lista(N);
	
	for(int i=0;i<lista.size();i++){
		cout<<"ingrese nombre del ejercicio"<<endl;
		cin.ignore();
		getline(cin, lista[i].nombre);
		
		cout<<"ingrese texto"<<endl;
		cin.ignore();
		getline(cin,lista[i].texto);
		
		cout<<"ingrese puntaje que otorga"<<endl;
		cin>>lista[i].puntaje;
		
		cout<<"ingrese dificultad"<<endl;
		cin>>lista[i].dificultad;
		
	}
	
	string buscar;
	cout<<"ingrese ejercicio a buscar"<<endl;
	cin>>buscar;
	
	int pos=buscarejer(lista,buscar);
	if(pos==-1){
		cout<<"no se encuentran ejercicios con ese nombre"<<endl;}
	else{cout<<"el ejercicio se encuentra en la posicion "<<pos+1<<endl;}
	
	string nuevoexam;
	cout<<"ingrese nombre del ejercicio para confeccionar un nuevo examen"<<endl;
	cin>>nuevoexam;
	
	int nuevo;
	vector<ejercicio>examen;
	while(nuevoexam!="A"){
		nuevo=buscarejer(lista,buscar);
		if(nuevo==-1){
			cout<<"no se encuentran ejercicios con ese nombre"<<endl;}
		examen.push_back(lista[nuevo+1]);
		cout<<"ingrese nombre del ejercicio para confeccionar un nuevo examen"<<endl;
		cin>>nuevoexam;
		
	}
	
	
	cout<<endl<<endl;
	cout<<"el examen esta compuesto por"<<endl;
	for(int i=0;i<examen.size();i++){
		cout<<examen[i].nombre<<endl;
		cout<<examen[i].texto<<endl;
		cout<<examen[i].puntaje<<endl;
		cout<<examen[i].dificultad<<endl;
	}
	
	int suma=0;
	float total=0;
	for(int i=0;i<examen.size();i++){
		suma+=examen[i].dificultad;
		total+=examen[i].puntaje;
	}
	int prom=suma/examen.size();
	cout<<"la dificultad promedio del examen es de: "<<prom<<endl;
	if(total<100){
		cout<<"los puntajes seleccionados no suman 100"<<endl;
	}
	
	return 0;
}

int buscarejer(vector<ejercicio>lista, string buscar){
	
	for (int i=0;i<lista.size();i++){
		if(lista[i].nombre==buscar){
			return i;
		}
	}
	return -1;
}
