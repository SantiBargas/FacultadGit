#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*3) Profundidad. Escribir una funci´on 
int cant_nodos_prof(btree<int> &A, int prof) que
retorna el n´umero de nodos de un ´arbol binario 
A que est´an a profundidad prof o mayor*/


//CANTIDAD DE NODOS EN UNA PROFUNDIDAD DETERMINADA
int cant_nodos_prof(btree<int> &A,btree<int>::iterator n, int prof){

	if(n==A.end()) return 0;
	if(prof==0) return 1;
	int count = 0;
	count += cant_nodos_prof(A,n.left(),prof-1);
	count += cant_nodos_prof(A,n.right(),prof-1);
	return count;
	
}

int cant_nodos_prof(btree<int> &A, int prof){
	
	return cant_nodos_prof(A,A.begin(),prof);
	
}
	
//CANTIDAD DE NODOS EN UNA PROFUNDIDAD Y MAYOR
int cant_nodos_prof2(btree<int> &A,btree<int>::iterator n, int prof){

	if(n==A.end()) return 0;
	
	return (prof<=0) + cant_nodos_prof2(A,n.left(),prof-1) + cant_nodos_prof2(A,n.right(),prof-1);
	//prof retorna verdadero cuando ya estoy debajo de la linea de flotacion
}

int cant_nodos_prof2(btree<int> &A, int prof){
	
	return cant_nodos_prof2(A,A.begin(),prof);
	
}
	
//CANTIDAD DE NODOS EN UNA PROFUNDIDAD Y MENOR
int cant_nodos_prof2(btree<int> &A,btree<int>::iterator n, int prof){

	if(n==A.end()) return 0;

	return (prof>=0) + cant_nodos_prof2(A,n.left(),prof-1) + cant_nodos_prof2(A,n.right(),prof-1);
	//prof retorna verdadero cuando estoY arriba de la linea de flotacion
}

int cant_nodos_prof2(btree<int> &A, int prof){
	
	return cant_nodos_prof2(A,A.begin(),prof);
	
}

int main() {
	
	btree<int> T;
	lisp2btree("(1 2 (3 4 (5 6)))",T);	btree2dot(T);
	
	for(int prof=0;prof<10;prof++){
		cout<<"cant_nodos_prof(T,prof)" <<" "<<prof <<" "<< cant_nodos_prof(T,prof)<<endl;
	}cout<<endl<<endl;
	
	for(int prof=0;prof<10;prof++){
		cout<<"cant_nodos_prof(T,prof)" <<" "<<prof <<" "<< cant_nodos_prof2(T,prof)<<endl;
	}
	
	return 0;
}







