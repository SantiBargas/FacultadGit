#include <iostream>
#include <lisp.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

int main() {
	
	btree<int>T;
	lisp2btree("(4 1 7)",T);
	btree2dot(T);
	return 0;
}







