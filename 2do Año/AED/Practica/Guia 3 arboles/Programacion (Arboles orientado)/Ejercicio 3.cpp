#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*3) Level Escribir una funci´on void count_level(tree<int> &T, int l), que cuente cuantos nodos
hay en el nivel l del ´arbol T.*/

int count_level(tree<int> &arbol,tree<int>::iterator p, int &n, int l){
	int nnodes=0; //numero de nodos
	
	if(p==arbol.end()) return 0;
	
	if(n==l){ //si estoy en la profundidad que quiero
		--n;
		return 1;
	}
	auto c=p.lchild();
	while(c!=arbol.end()){
		nnodes+=count_level(arbol,c++,++n,l);
	}
	--n;
	return nnodes;
	
}
	
int count_level(tree<int>&arbol,int l){
	int n=0; //variable para ir determinando en que profundidad estoy;
	
	return count_level(arbol,arbol.begin(),n,l);
}
	
int count_level2(tree<int> &T, int l){
	
	auto p=T.begin();
	if(p==T.end()) return 0;
	auto c=p.lchild();
	while(c!=T.end()){
		l++;
		c++;
	}
	return l;
	
}
	
int count_level2(tree<int>&arbol){
	int l=0;
	l=count_level2(arbol,l);
	return l;
}
	
int main() {
	string s_arbol1("(2 3 (4 5 (6 7 8))(9 10) (22 12 (13 14 15))");
	tree<int> arbol1;
	lisp2tree(s_arbol1,arbol1);
	tree2dot(arbol1);
	
	cout<<"La cantidad de nodos en el nivel 1 son: "<<count_level(arbol1,2);
	return 0;
}







