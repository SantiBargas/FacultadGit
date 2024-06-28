#include <iostream>
#include <tree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;
void altura(tree<int>&T, tree<int>::iterator p,int&n){
	if(p==T.end()) return;
	auto c=p.lchild();
	while(c!=T.end()){
		altura(T,c++,n);
	}
}
	
int altura(tree<int>&T){
	int n=0;
	altura(T,T.begin(),n);
	return n;
}
	
int main() {
	
	tree<int>T;
	lisp2tree("(0 3 (8 3) (9 4) )",T);
	tree2dot(T);
	
	cout<<"la altura es : " <<altura(T);
	
	return 0;
}







