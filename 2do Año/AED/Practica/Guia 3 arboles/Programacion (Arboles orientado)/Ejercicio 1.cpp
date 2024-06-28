#include <iostream>
#include <tree.hpp>
#include <list>
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
/*1) ListarAOO. Escribir procedimientos para listar un ´arbol ordenado orientado siguiendo los ´ordenes
	prefijo y postfijo*/

template<typename T>
void prefijo(tree<T> &arbol,typename tree<T>::iterator p,list<T> &L){
	if (p == arbol.end()) return;
	L.push_back(*p);
	typename tree<T>::iterator c = p.lchild();
	while (c != arbol.end()) prefijo(arbol,c++,L);
}
template<typename T>
list<T> prefijo(tree<T> &arbol){
	list<T> pref;
	prefijo(arbol,arbol.begin(),pref);
	return pref;
}

template<typename T>
void postfijo(tree<T> &arbol,typename tree<T>::iterator p,list<T> &L){
	if(p==arbol.end()) return;
	auto c=p.lchild();
	
	while(c!=arbol.end()){
		postfijo(arbol,c++,L);
	}
	L.push_back(*p);
}
template<typename T>
list<T> postfijo(tree<T> &arbol){
	list<T> post;
	postfijo(arbol,arbol.begin(),post);
	return post;
}
	
	
int main() {
	tree<int> T;	lisp2tree("(1 2 3 (4 (5 7 8 (9 10)) 6))",T);
	
	list<int>pre=prefijo(T);
	cout<<"El listado prefijo es: "<<endl;
	show_list(pre);
	tree2dot(T,"GRAFO");
	
	list<int>post=postfijo(T);
	cout<<"El listado postfijo es: "<<endl;
	show_list(post);
	
	return 0;
}







