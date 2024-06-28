#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
// VariosAB. Escribir procedimientos para:
//a)Determinar si dos ´arboles tienen la misma estructura.
bool estructura(btree<int>&A,btree<int>&B,btree<int>::iterator itA,btree<int>::iterator itB){

	if(itA==A.end() && itB==B.end()){
		return true;
	}
	
	if( (itA!=A.end() && itB==B.end()) || (itA==A.end() && itB!=B.end()) ){
		return false;
	}
	
	if ( !estructura(A,B,itA.left(),itB.left() ) ) return false;
	if ( !estructura(A,B,itA.right(),itB.right() ) ) return false;
	
	return true;
	
}

bool estructura(btree<int>&A,btree<int>&B){
	return estructura(A,B,A.begin(),B.begin());
}

//b)Determinar si la estructura de un ´arbol es la espejada de otro.

bool espejado(btree<int>&A,btree<int>&B,btree<int>::iterator itA,btree<int>::iterator itB){
	
	btree<int>::iterator la=itA.left();
	btree<int>::iterator ra=itA.right();
	btree<int>::iterator lb=itB.left();
	btree<int>::iterator rb=itB.right();
	
	if(la==A.end() && rb==A.end()) return true;
	if(ra==A.end() && lb==A.end()) return true;
	
	if(( la!=A.end() && rb==A.end()) || (la==A.end() && rb!=B.end())) return false;
	if(( ra!=A.end() && lb==A.end()) || (ra==A.end() && lb!=B.end())) return false;
	
	return true;
	
}
	
bool espejado(btree<int>&A,btree<int>&B){
	return espejado(A,B,A.begin(),B.begin());
}

//c)Determina si dos ´arboles son iguales, en estructura y contenido.

bool chk_estructura_contenido(btree<int>&A,btree<int>&B,btree<int>::iterator itA,btree<int>::iterator itB){
	
	if(itA==A.end() && itB==B.end()){
		return true;
	}
	
	if(itA==A.end() xor itB==B.end()){  //es verdadero cuando uno es verdadero y el otro falso
		return false;
	}
	/*if( (itA!=A.end() && itB==B.end()) || (itA==A.end() && itB!=B.end()) ){
		return false;
	} es lo mismo q el anterior if*/
	
	if(*itA!=*itB){
		return false;
	}
	
	if ( !chk_estructura_contenido(A,B,itA.left(),itB.left() ) ) return false;
	if ( !chk_estructura_contenido(A,B,itA.right(),itB.right() ) ) return false;
	
	return true;
	
}

bool chk_estructura_contenido(btree<int>&A,btree<int>&B){
	return chk_estructura_contenido(A,B,A.begin(),B.begin());
}
//d)Copiar un ´arbol en otro en forma espejada
	
void clone_espejo(btree<int>&A,btree<int>&B,btree<int>::iterator itA,btree<int>::iterator itB){
	
	btree<int>::iterator la=itA.left();
	btree<int>::iterator ra=itA.right();
	
	if(la!=A.end()){
		B.insert(itB.right(),*la);
		clone_espejo(A,B,itA.left(),itB.right());
	}
	
	if(ra!=A.end()){
		B.insert(itB.left(),*ra);
		clone_espejo(A,B,itA.right(),itB.left());
	}
	
	return;
	
}
	
void clone_espejo(btree<int>&A,btree<int>&B){
	auto it=A.begin();
	B.insert(B.begin(),*it);
	
	clone_espejo(A,B,A.begin(),B.begin());
}

int main() {
	
//	btree<int> T;//	//lisp2btree("(1 2 (3 4 (5 6)))",T);//	//btree2dot(T);//	btree<int> T2;//	//lisp2btree("(4 5 (6 7 (9 10 3)))", T2);//	//btree2dot(T2);//	//bool a=estructura(T,T2);
//	
//	//if(a==1)cout<<"Verdadero";
//	//else cout<<"FalsO";
//	
////	a=espejado(T,T2);//	//if(a==1)cout<<"Verdadero";
//	//else cout<<"FalsO";//	
//	//	lisp2btree("(1 2 (3 4 (5 6)))",T);//	btree2dot(T);//	lisp2btree("(1 2 (3 4 (5 6)))", T2);//	btree2dot(T2);
//	
//	if(chk_estructura_contenido(T,T2)==1)cout<<"Verdadero";
//	else cout<<"FalsO";
	
	btree<int>B;
	lisp2btree("(0(10 (4 9) (17 (15  16) )))",B);
	btree2dot(B);
	
	return 0;
}







