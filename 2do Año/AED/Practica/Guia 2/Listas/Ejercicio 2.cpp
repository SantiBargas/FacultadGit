#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
/*SelectionSort. Escribir una funci´on void selection_sort(list<int> &L), que ordena los
	elementos de L de menor a mayor. Para ello debe tomarse el menor elemento de L e intercambiarlo
	(swap) con el primer elemento de la lista. Luego intercambiar el menor elemento de la lista
	restante, con el segundo elemento, y as´i sucesivamente. Esta funci´on debe ser IN PLACE.*/


void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

void selection_sort(list<int> &L){
	list<int>::iterator it = L.begin();
	
	while(it!=L.end()){
		// buscar menor elemento
		list<int>::iterator min = min_element(it,L.end());
		
		swap(*it,*min);
		
		it++;
	}
}
int main() {
	
	list<int>L={1,67,12,11,9,42,57};
	selection_sort(L);
	
	show_list(L);
	
	
	
	return 0;
}

