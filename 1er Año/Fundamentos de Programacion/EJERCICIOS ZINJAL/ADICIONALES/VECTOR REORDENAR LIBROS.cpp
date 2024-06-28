#include <iostream>
#include <vector>
using namespace std;

struct libro{
	string titulo;
	string autor;
	string editorial;
	int anio;
	string isbn;
	string genero;
	int ejemplares;
};

string eliminar_edicion(vector<libro>lista, string tituloborrar, string autorborrar, int anioborrar );
int pos_libro (vector<libro>lista, string librobuscar, string autorbuscar);
int stock_libro(vector<libro>lista, string cantlibro , string cantautor);

int main() {
	int N;
	cout<<"ingrese cant de libros"<<endl;
	cin>>N;
	vector<libro>lista(N);
	
	for (int i=0;i<lista.size();i++){
		libro l;
		cout<<"ingrese titulo"<<endl;
		cin>>l.titulo;
		cout<<"ingrese autor"<<endl;
		cin>>l.autor;
		cout<<"ingrese editorial"<<endl;
		cin>>l.editorial;
		cout<<"año: "<<endl;
		cin>>l.anio;
		cout<<"isbn: "<<endl;
		cin>>l.isbn;
		cout<<"genero: "<<endl;
		cin>>l.genero;
		cout<<"ejemplares: "<<endl;
		cin>>l.ejemplares;
		
		lista[i]=l;
	}
	
	string tituloborrar,autorborrar,librobuscar,autorbuscar;
	int anioborrar;
	
	cout<<"que titulo desea borrar?"<<endl;
	cin>>tituloborrar;
	cout<<"ingrese autor que desa borrar"<<endl;
	cin>>autorborrar;
	cout<<"ingrese año"<<endl;
	cin>>anioborrar;
	
	cout<<"se borro el libro con isbn: "<<eliminar_edicion(lista,tituloborrar,autorborrar,anioborrar)<<endl;
	
	cout<<"que libro desea buscar?"<<endl;
	cin>>librobuscar;
	cout<<"de que autor es?"<<endl;
	cin>>autorbuscar;
	
	
	int pos = pos_libro(lista,librobuscar,autorbuscar);
	if(pos==-1){
		cout<<"el libro que ingreso no se encuentra"<<endl;
	}else{
		cout<<"el libro que ingreso se encuentra en la posicion: "<<pos+1<<endl;
	}
	
	string cantlibro,cantautor;
	cout<<"ingrese libro que desea saber cant de ejemplares"<<endl;
	cin>>cantlibro;
	cout<<"ingrese autor que desea saber cant de ejemplares"<<endl;
	cin>>cantautor;
	
	cout<<"la cantidad de ejemplares del libro "<<cantlibro<<" del autor: "<<cantautor<<" son: "<<stock_libro(lista,cantlibro,cantautor);
	
	return 0;
}
string eliminar_edicion(vector<libro>lista, string tituloborrar, string autorborrar, int anioborrar ){
	
	int numborrar=-1;
	for (int i=0;i<lista.size();i++){
		if(tituloborrar==lista[i].titulo){
			numborrar=i;
		}
	}
	
	for (int i=numborrar;i<lista.size();i++){
		lista[i-1]=lista[i];
	}
	lista.resize(lista.size()-1);
	
	return lista[numborrar].isbn;
	
}
int pos_libro (vector<libro>lista, string librobuscar, string autorbuscar){

	for (int i=0;i<lista.size();i++){
		
		if(lista[i].titulo==librobuscar){
			return i;
		}
	}
	
	return -1;
}
	
int stock_libro(vector<libro>lista, string cantlibro , string cantautor){
	
	int cantejemplares=0;
	
	for (int i=0;i<lista.size();i++){
		if(cantlibro==lista[i].titulo){
			cantejemplares+=lista[i].ejemplares;
		}
	}

	return cantejemplares;
	
}
	
	

