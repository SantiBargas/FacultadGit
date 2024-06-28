#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
/* BasicSort. Escribir una funci´on void basic_sort(list<int> &L), que ordena los elementos de L
	de menor a mayor. Para ello emplear el siguiente algoritmo simple: utilizando una lista auxiliar L2,
	tomar el menor elemento de L, eliminarlo de L e insertarlo al final de L2 hasta que L este vac´ia.
	Luego insertar los elementos de L2 en L.*/

void basic_sort(list<int> &L){
	list<int>L2;
	
	while(!L.empty()){
		//tomar el menor elemento de L,
		list<int>::iterator it= min_element(L.begin(),L.end());
		//insertarlo al final de L2 
		L2.push_back(*it);
		//eliminarlo de L 
		it=L.erase(it);
	}
	L=L2;
}
int main() {
	
	list<int>L={1,42,12,-7,41,78,100};
	basic_sort(L);
	
	list<int>::iterator pos=L.begin();
	
	
	while(pos!=L.end()){
		cout<<*pos<<"    ";
		pos++;
	}
	
	return 0;
}

