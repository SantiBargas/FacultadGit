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

string eliminar_edicion(vector<libro>&lista,string titulo,string autor,int anio);
int pos_libro(vector<libro>lista,string titulo, string autor);
int stock_libro(vector<libro>lista,string titulo, string autor);

int main() {
	int N;
	cout<<"Ingrese la cantidad de libros"<<endl;
	cin>>N;
	vector<libro>lista(N);
	
	for(int i = 0;i<N;i++){
		libro l;  /// nueva instancia de tipo libro 
		cout<<"Titulo :"<<endl;
		cin>>l.titulo;
		cout<<"Autor :"<<endl;
		cin>>l.autor;
		cout<<"Editorial :"<<endl;
		cin>>l.editorial;
		cout<<"Año de edición :"<<endl;
		cin>>l.anio;
		cout<<"ISBN :"<<endl;
		cin>>l.isbn;
		cout<<"Genero :"<<endl;
		cin>>l.genero;
		cout<<"Cant. ejemplares :"<<endl;
		cin>>l.ejemplares;
		lista[i] = l;
	}
	
	string autorbuscar,isbnbuscar,titulobuscar;
	int aniobuscar;
	cout<<"ingrese titulo a eliminar"<<endl;
	cin>>titulobuscar;								///INCISO B
	cout<<"ingrese autor a elimiar"<<endl;
	cin>>autorbuscar;
	isbnbuscar=eliminar_edicion(lista,titulobuscar,autorbuscar,aniobuscar);
	if(isbnbuscar==""){
		cout<<"el libro no se encuentra"<<endl;
	}else{
		cout<<"El ISBN del libro que se elimino es"<<isbnbuscar<<endl;
	}
	
	string autorpos,titulopos;
	cout<<"de que libro desea saber la posicion?"<<endl;
	cin>>titulopos;
	cout<<"de que autor desea saber la posicion?"<<endl;
	cin>>autorpos;
	
	int pos=pos_libro(lista,titulopos,autorpos);
	if(pos==-1){
		cout<<"no se encontro libro"<<endl;
	}else{
		cout<<"el libro esta en la pos"<<pos<<endl;
	}
	
	string titulostock,autorstock;
	cout<<"de que libro desea saber el stock?"<<endl;
	cin>>titulostock;
	cout<<"de que autor desea saber el stock?"<<endl;
	cin>>autorstock;
	
	int stock==stock_libro(lista,titulo,autor);
	if( stock==0){
		cout<<"no hay stock"<<endl;
	}else{
		cout<<"stock del libro: "<<stock<<endl;
	}
	
	return 0;
}

string eliminar_edicion(vector<libro>&lista,string titulo,string autor,int anio){
	int posicion=-1;
	
	for(int i=0;i<lista.size();i++){
		if(lista[i].titulo==titulo and lista[i].autor==autor and lista[i].anio==anio){
			posicion=i;
		}
	}
	if (posicion==-1){
		return "no se encontro libro";
	}
	string isbn=lista[posicion].isbn; ///antes de eliminarlo obtengo el isbn
	
	for(int i=posicion;i<lista.size()-1;i++){
		lista[i]=lista[i+1];
	}
	
	lista.resize(lista.size()-1);
	
	return isbn;
}
int pos_libro(vector<libro>lista,string titulo, string autor){
	int aniomayor=0;
	int posicion=-1;
	
	for(int i=0;i<lista.size();i++){
		if(lista[i].titulo==titulo and lista[i].autor==autor){
			if(lista[i].anio>aniomayor){
				posicion=i;
				aniomayor=lista[i].anio;
			}
		}
	}
	
	return posicion;
}
int stock_libro(vector<libro>lista,string titulo, string autor){
	int stock=0;
	for(int i=0;i<lista.size();i++){
		if(lista[i].titulo==titulo and lista[i].autor==autor){
			stock+=lista[i].ejemplares;
		}
	}
	return stock;
	
}
