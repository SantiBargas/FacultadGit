#include <iostream>
#include <iomanip>
#include <btree.hpp>
#include <climits>
using namespace aed;
using namespace std;
///Para saber si un arbol binario es de busqueda
///Si es vacio es de busqueda
///El maximo del lado derecho es mayor q la raiz
///El minimo del lado izquierdo es menor q la raiz

int max(btree<int>&T,btree<int>::iterator n){
	auto c=n;
	while(c!=T.end()){
		auto cc=c.right();
		if(cc==T.end())break;
		c=cc;
	}
	return *c;
}

int max(btree<int>&T){		
	if(T.empty()) return INT_MIN;
	return max(T,T.begin());
}

int min(btree<int>&T,btree<int>::iterator n){
	auto c=n;
	while(c!=T.end()){
		auto cc=c.left();
		if(cc==T.end())break;
		c=cc;
	}
	return *c;
}

int min(btree<int>&T){		
	if(T.empty()) return INT_MIN;
	return min(T,T.begin());
}

	
bool isbst(btree<int>&T,btree<int>::iterator n){
	
	if(n==T.end()) return true;
	if(!isbst(T,n.left())) return false;
	if(!isbst(T,n.right())) return false;
	
	if(*n<=max(T,n.left())) return false;
	if(*n>=min(T,n.right())) return false;
	
	return true;
}

bool isbst(btree<int>&T){
	if(T.empty()) return true;
	return isbst(T,T.begin());
}


int main() {
	
	return 0;
}







