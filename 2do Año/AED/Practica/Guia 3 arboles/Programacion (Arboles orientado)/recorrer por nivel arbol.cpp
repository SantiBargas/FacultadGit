#include <iostream>
#include <tree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

void imprimir(tree<int>&T,tree<int>::iterator p, int nivel,int cont){
	
	if(p==T.end()) return;
	if(nivel==0){
		cout<<*T.begin();
		return;
	}
	
	auto c=p.lchild();
	cont++;
	
	while(c!=T.end()){
		
		if(cont==nivel){
			while(c!=T.end()){
				cout<<*c<<"  ";
				c++;
			}
			return;
		}
		
		
		imprimir(T,c++,nivel,cont);
		
	}
	
	
}

int main() {
	tree<int> T;
	lisp2tree("(0 3 (8 3) (9 4) )",T);
	tree2dot(T);
	
	imprimir(T,T.begin(),1,0);
	return 0;
}







