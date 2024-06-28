#include <iostream>
using namespace std;
/*3) Profundidad. Escribir una funci´on 
int cant_nodos_prof(btree<int> &A, int prof) que
retorna el n´umero de nodos de un ´arbol binario 
A que est´an a profundidad prof o mayor*/

bool func_prof(int x){	return x==0;}	int count_level(btree<int> &A, btree<int>::iterator itA, bool(*f)(int),int prof){	if(itA == A.end()) return 0;	return (f(prof) + count_level(A,itA.left(),f,prof-1) + count_level(A,itA.right(),f,prof-1));}	int count_level(btree<int> &A,bool(*f)(int),int prof){	if(A.begin() == A.end()) return 0;	return count_level(A,A.begin(),f,prof);}
		

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
					






