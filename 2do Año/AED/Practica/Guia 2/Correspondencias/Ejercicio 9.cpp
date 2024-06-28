#include <iostream>
#include <tree.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*9) creaAOO Escribir una funci´on tree<double> crea(double M, int n) que dados un real M y un
entero n, tales que n < M crea un AOO T tal que:
a
0 La suma de las hojas es M, pero cada una de ellas es h = n.
b
0 Se satisface que para cada nodo p la suma de sus hijos es *p.
c
0 Cada nodo tiene a lo sumo g hijos, con g> 1 una constante dada.
Ayuda: El ´arbol se puede construir poniendo inicialmente M en la ra´iz, y dividiendo el contenido
*n de cada nodo en g valores iguales*/

///Funcion
void crea2(tree<double>&T,tree<double>::iterator p, double M,int n, int g){
	if(M<=n) return ;
	
	double M2=M/g;
	auto c=p.lchild();
	
	for(int j=0;j<g;j++){
		
		c=T.insert(c,M2);
		crea2(T,c,M2,n,g);
		c++;
	}
}
	
	
///Wrapper	
tree<double> crea2(double M,int n, int g){
	
	tree<double>T;
	T.insert(T.begin(),M);
	crea2(T,T.begin(),M,n,g);
	return T;
	
}

int main() {
	
	tree<double>T=crea2(10,1,2);
	
	tree2dot(T);
	
	return 0;
}







