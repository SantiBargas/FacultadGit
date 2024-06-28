#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;
/*5) SortQueue. Escribir una funci´on void sort(list<int> &L), que ordena los elementos de L de
	menor a mayor. Para ello utilizar el siguiente algoritmo simple, utilizando una cola auxiliar C: ir
	tomando el menor elemento de L, eliminarlo de L e insertarlo en C hasta que L este vac´ia. Luego
	insertar los elementos de C en L*/


void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

void sort(list<int> &L){
	
	queue<int>C;
	
	list<int>::iterator it=L.begin();
	
	while(it!=L.end()){
		it=min_element(L.begin(),L.end());
		C.push(*it);
		it=L.erase(it);
	}
	while(!C.empty()){
		L.push_back(C.front());
		C.pop();
	}
}
int main() {
	
	
	list<int>L{1,5,8,3,2,9,10};
	sort(L);
	show_list(L);
	return 0;
}







