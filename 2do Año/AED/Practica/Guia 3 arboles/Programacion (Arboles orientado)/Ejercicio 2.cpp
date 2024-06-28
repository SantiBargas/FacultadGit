#include <iostream>
#include <list>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}
/*2) VariosAOO. Escribir procedimientos para:
a) Calcular la altura de un AOO.
b) Contar el n´umero de hojas.
c) Obtener la m´axima etiqueta de todo el ´arbol.
d) Obtener la m´axima etiqueta par del ´arbol.
e) Obtener la m´axima etiqueta de s´olo las hojas.
f) Obtener la suma de todas las etiquetas.
g) Eliminar todas las etiquetas impares y sus sub´arboles.*/

///A
template<typename T>
void altura(tree<T>&arbol,typename tree<T>::iterator p,int &n,int &nmax){
	if(p==arbol.end()) return;
	auto c=p.lchild();
	while(c!=arbol.end()){
		altura(arbol,c++,++n,nmax);
	}
	
	///cuando llego a un C que es end, comparo si n>nmax y decrecemos
	///n en 1 porque cuando C llega a un end suma un camino de mas
	if(n>nmax){
		nmax=n;
	}
	--n;
}
template<typename T>
int altura(tree<T>&arbol){
	int n=0; int nmax=0;
	altura(arbol,arbol.begin(),n,nmax);
	return nmax;
}
///b) Contar el n´umero de hojas.	
template<typename T>
void hojas(tree<T>&arbol,typename tree<T>::iterator p,int &n){
	if(p==arbol.end()) return;
	
	auto c=p.lchild();
	if(c==arbol.end()){n++;	}
	
	while(c!=arbol.end()){
		hojas(arbol,c++,n);
	}
}
template<typename T>
int hojas(tree<T>&arbol){
	int n=0;
	hojas (arbol,arbol.begin(),n);
	return n;
}
///c) Obtener la m´axima etiqueta de todo el ´arbol.
template<typename T>
void etiquetamaxima(tree<T>&arbol,typename tree<T>::iterator p,int &max){
	if(p==arbol.end()) return;
	if(*p>max) max=*p;
	
	auto c=p.lchild();
	while(c!=arbol.end()){
		etiquetamaxima(arbol,c++,max);
	}
}
template<typename T>
int etiquetamaxima(tree<T>&arbol){
	int max;
	if(arbol.begin()!=arbol.end()){
		max=*(arbol.begin());
	}
	etiquetamaxima(arbol,arbol.begin(),max);
	return max;
}
///d) Obtener la m´axima etiqueta par del ´arbol.
template <typename T>
void etiquetamaximapar(tree<T>&arbol,typename tree<T>::iterator p,int &max){
	if(p==arbol.end()) return;
	if(*p>max && *p%2==0) max=*p;
	
	auto c=p.lchild();
	while(c!=arbol.end()){
		etiquetamaximapar(arbol,c++,max);
	}
}
	
template<typename T>
int etiquetamaximapar(tree<T>&arbol){
	int max;
	if(arbol.begin()!=arbol.end()){
		max=-1;
	}	
	etiquetamaxima(arbol,arbol.begin(),max);
	return max;
}
	
///e) Obtener la m´axima etiqueta de s´olo las hojas.
template<typename T>
void hojasmax(tree<T>&arbol,typename tree<T>::iterator p,int &max){
	if(p==arbol.end()) return;
	
	int aux=*p;
	auto c=p.lchild();
	
	if(c==arbol.end()){
		if(aux>max) max=aux;	
	}
	
	while(c!=arbol.end()){
		hojasmax(arbol,c++,max);
	}
}
template<typename T>
int hojasmax(tree<T>&arbol){
	int max=0;
	hojasmax(arbol,arbol.begin(),max);
	return max;
}

///f) Obtener la suma de todas las etiquetas.
template<typename T>
void sumaetiquetas(tree<T>&arbol,typename tree<T>::iterator p,int &max){
	if(p==arbol.end()) return;
	
	max+=*p;
	auto c=p.lchild();
	while(c!=arbol.end()){
		sumaetiquetas(arbol,c++,max);
	}
}
	
template<typename T>
int sumaetiquetas(tree<T>&arbol){
	int suma=0;
	sumaetiquetas(arbol,arbol.begin(),suma);
	return suma;
}
	
///g) Eliminar todas las etiquetas impares y sus sub´arboles.
template<typename T>
typename tree<T>::iterator  eliminar(tree<T>&arbol,typename tree<T>::iterator p){
	
	if(p==arbol.end()) return p;
	if(*p%2!=0){
		p=arbol.erase(p); //si el nodo es impar borramos ese nodo y toda su desendencia y pasamos al hermano derecho
	}
	else{
		//si no es impar vamos al hijo mas izquierdo, si no es landa llamamos recursivamente
		auto c=p.lchild();
		while(c!=arbol.end()){
			c=eliminar(arbol,c); //no aumentamos c pq ya lo actualizamos antes
		}
		///cuando deja de cumplirse la condicion del while tenemos que pasar al hermano derecho de ese nodo
		++p;
	}
	return p;
}


int main() {
	string s_arbol1("(2 3 (4 5 (6 7 8))(9 10) (22 12 (13 14 15))");
	tree<int> arbol1;
	lisp2tree(s_arbol1,arbol1);
	
	cout<<"La altura del arbol es: "<<altura(arbol1);
	tree2dot(arbol1);
	cout<<"Las hojas del arbol son: "<<hojas(arbol1)<<endl;
	cout<<"La etiqueta maxima del arbol es: "<<etiquetamaxima(arbol1)<<endl;
	cout<<"La etiqueta maxima par del arbol es: "<<etiquetamaximapar(arbol1)<<endl;
	cout<<"Las hoja maxima del arbol es: "<<hojasmax(arbol1)<<endl;
	cout<<"La suma de todas las etiquetas del arbol es: "<<sumaetiquetas(arbol1)<<endl;
	cout<<"Borramos los nodos impares y todos sus subarbol "<<endl;
	eliminar(arbol1,arbol1.begin());
	tree2dot(arbol1);
	
	return 0;
}







