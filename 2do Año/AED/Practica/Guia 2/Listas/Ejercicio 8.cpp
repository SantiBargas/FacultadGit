#include <iostream>
#include <list>
#include <vector>
using namespace std;
void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

template <class T>	void print_list_list(T list, string message = "") {	cout << message << "\n";		for(auto it_i = list.begin(); it_i != list.end(); it_i++){		cout << "[";		for(auto it_j = it_i->begin(); it_j != it_i->end(); it_j++){			cout << *it_j << " ";		}		cout << "]";	}		cout << "\n Fin impresion \n";}
	

/*8) Ascendente2. Escribir una funci´on void ascendente2(list<int> &L, vector<list<int>> &VL)
	que, dada una lista L, genera un vector de listas VL de tal forma de que cada sublista es ascendente.
*/

void ascendente2(list<int> &L, vector<list<int>> &VL){
	
	list<int>::iterator itl= L.begin();
	list<int> aux;
	list<int>::iterator itt;
	
	while(itl!=L.end()){
		aux.push_back(*itl);
		itt=itl;
		itt++;
		while(itt!=L.end() && (*itl < *itt) ){
			aux.push_back(*itt);
			++itl;
			++itt;
		}
		VL.push_back(aux);
		aux.clear();
		++itl;
	};
}
int main() {
	
	
	list<int>L={1,2,4,1,4,6,2,3,5,7,2,3,1,2};
	vector<list<int>> LL{};
	ascendente2(L,LL);
	print_list_list(LL);
	
	
	return 0;
}

