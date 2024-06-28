#include <iostream>
#include <btree.hpp>
#include <list>
#include <make_random.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
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

void prefijo(btree<int>&T,list<int>&L,btree<int>::iterator it){
	if(it!=T.end()){
		L.push_back(*it);
	}else{
		return;
	}
	prefijo(T,L,it.left());
	prefijo(T,L,it.right());	
}
void prefijo(btree<int>&T,list<int>&L){
	prefijo(T,L,T.begin());
}
	
	
void postfijo(btree<int>&T,list<int>&L,btree<int>::iterator it){
	if(it==T.end()) return;
	postfijo(T,L,it.left());
	postfijo(T,L,it.right());
	L.push_back(*it);
}
void postfijo(btree<int>&T,list<int>&L){	
	postfijo(T,L,T.begin());
}
	
	
void infijo(btree<int>&T,list<int>&L,btree<int>::iterator it){
	if(it==T.end()){
		return;
	}
	
	infijo(T,L,it.left());
	
	L.push_back(*it);
	
	infijo(T,L,it.right());
}
void infijo(btree<int>&T,list<int>&L){
	infijo(T,L,T.begin());
}

int main() {
	
	btree<int> T;	lisp2btree("(1 2 (2 1 (2 3 4)))",T);
	list<int>L;
	
	prefijo(T,L);
	show_list(L);
	btree2dot(T);

	L.clear();
	postfijo(T,L);
	show_list(L);
	btree2dot(T);

	L.clear();
	infijo(T,L);
	show_list(L);
	btree2dot(T);
	return 0;
}







