#include <iostream>
#include <tree.hpp>
#include <btree.hpp>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;
/*5) ord2bin. Escribir la funci´on inversa void ord2bin(tree<int> &T, btree<int> &B) que dado un
AOO (que supuestamente fue generado por bin2ord) lo convierte de nuevo a AB. (Deber´ia ser
siempre B=ord2bin(bin2ord(B))).*/

void ord2bin(tree<int> &T,tree<int>::iterator it, btree<int> &B, btree<int>::iterator itb){
	
	if (it == T.end() or *it == -1) return;
	
	itb = B.insert(itb,*it);
	
	if (it.lchild() != T.end()){
		ord2bin(T,it.lchild(),B,itb.left());
		ord2bin(T,it.lchild().right(),B,itb.right());
	}
}
void ord2bin(tree<int> &T, btree<int> &B){
	
	
//	if(T.begin()==T.end()) return;
//	
//	B.insert(B.begin(),*T.begin());
	ord2bin(T,T.begin(),B,B.begin());
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







