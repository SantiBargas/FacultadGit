#include <iostream>
#include <vector>
using namespace std;
/// En una bolsa de trabajo,se desea organizar la información disponible, para
/// ello, por cada persona, se carga Nombre,Dni, Telefono
///,Nivel estudios ( P -> Primario    S -> Secundario    T > Terciario  U -> Universitario
/// y el oficio o profesión.
///
/// Escriba un programa C++ que permita ingresar datos de personas hasta que el
/// nombre sea "ZZZ"
/// Codifique una función que retorne un vector con las personas que tengan el
/// oficio o profesion que se ingresa como parámetro
/// Codifique una función que determine si un dni existe ya en la lista.
/// Utilice esa función para controlar el ingreso de datos, la carga de Dni debe
/// ser repetitiva hasta que se ingrese un dni correctamente


struct persona{
	string nombre;
	int dni;
	string telefono;
	char estudios;
	string oficio;
};
bool existedocumento(vector<persona>lista, int dnibuscar);

vector<persona>GetListaPorOficio(vector<persona>lista, string oficiobuscar);

int main() {
	vector<persona>lista;
	string nombre;
	bool indice;
	
	cout<<"ingrese nombre"<<endl;
	cin>>nombre;
	
	
	while(nombre!="ZZZ"){
		persona p;
		p.nombre=nombre;
		
		
		cout<<"ingrese dni"<<endl;
		cin>>p.dni;
		indice=existedocumento(lista,p.dni);
		
		while(indice==true){
			cout<<"dni ya ingresado"<<endl;
			cin>>p.dni;
			indice=existedocumento(lista,p.dni);
		}
		
		cout<<"ingrese telefono"<<endl;
		cin>>p.telefono;
		
		cout<<"ingrese estudios (P-S-T-U)"<<endl;
		cin>>p.estudios;
		
		cout<<"ingrese oficio"<<endl;
		cin>>p.oficio;
		
		///agregar p a la lista
		
		lista.push_back(p);
		
		cout<<"ingrese nombre"<<endl;
		cin>>nombre;
		
	}
	
	cout<<"ingrese oficio a buscar"<<endl;
	string oficiobuscar;
	cin>>oficiobuscar;
	
	vector<persona>sublista=GetListaPorOficio(lista,oficiobuscar);
	if (sublista.size()==0){
		cout<<"no se encuentran personas con el oficio "<<oficiobuscar<<endl;
	}
	else{
		cout<<"Personas con el oficio "<<oficiobuscar<<endl;
		for (int i=0;i<sublista.size();i++){
			cout<<sublista[i].nombre<<endl;
		}
	}
		
	
	return 0;
}
vector<persona>GetListaPorOficio(vector<persona>lista, string oficiobuscar){
	
	vector<persona>aux;
	for (int i=0;i<lista.size();i++){
		if(lista[i].oficio==oficiobuscar){
			aux.push_back(lista[i]);
		}
	}
	
	return aux;
}
bool existedocumento(vector<persona>lista, int dnibuscar){
	
	for (int i=0;i<lista.size();i++){
		
		if(lista[i].dni==dnibuscar){
			return true;
		}
		
	}
	return false;
}

	

