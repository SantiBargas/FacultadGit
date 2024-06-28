#include <iostream>
#include <btree.hpp>
#include <tree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;


void bin2ord(btree<int>&B, tree<int>&T,btree<int>::iterator itB,tree<int>::iterator itT){
	
	btree<int>::iterator itl = itB.left();
	btree<int>::iterator itr = itB.right();
	
	
	if(itl==B.end() and itr==B.end()){
		return;
	}
	
	tree<int>::iterator it2=itT.lchild();
	if(itl==B.end()){
		
		it2 = T.insert(it2,-1);
		++it2;
		it2 = T.insert(it2,*itr);
		bin2ord(B,T,itr,it2);
		
	}else{
		
		it2 = T.insert(it2,*itl);
		bin2ord(B,T,itl,it2); //para continuar por el lado izquierdo
		++it2; //incremento para moverme al hermano
		//si el hermano es end en el arbol T inserto un -1
		
		if(itr == B.end()){
			it2 = T.insert(it2,-1);
		}else{
			it2=T.insert(it2,*itr);
			bin2ord(B,T,itr,it2);  //volvemos a llamar la recursividad pq si estamos en el else
			//Nunca usamos recursividad por el lado derecho
		}
		
	}
	
	
	
	
}
void bin2ord(btree<int>&B, tree<int>&T){
	
	T.insert(T.begin(),*B.begin());
	bin2ord(B,T,B.begin(),T.begin());
	
}


void ord2bin(tree<int> &T, btree<int> &B,tree<int>::iterator itT,btree<int>::iterator itB){

	
	auto c= itT.lchild();
	if(c==T.end()) return;
	
	if(*c!=-1){
		btree<int>::iterator itL=itB.left();
		itL=B.insert(itL,*c);
		ord2bin(T,B,c,itL);
	}
	c++;
	if(*c!=-1){
		btree<int>::iterator itR=itR.right();
		itR=B.insert(itR,*c);
		ord2bin(T,B,c,itR);
	}
}

void ord2bin(tree<int> &T, btree<int> &B){
	
	
	if(T.begin()==T.end()) return;
	
	B.insert(B.begin(),*T.begin());
	ord2bin(T,B,T.begin(),B.begin());
}

int main() {
	tree<int> T;
	lisp2tree("(6 (8 10 (3 8 -1 )) (4 -1 (4 -1 (4 2 3 ))))",T);
	tree2dot(T);
	btree<int> B;
	ord2bin(T,B);
	btree2dot(B);
	
	return 0;
}







