#include <iostream>
#include <set>
#include <list>
using namespace std;
template<typename T>
void set_difference(set<T> &A,set<T> &B,set<T> &C){
	
	auto itA=A.begin();
	
	while(itA!=A.end()){
		if(B.find(*itA)==B.end()){
			C.insert(*itA);
		}
		itA++;
	}
}
template<typename T>	void show_set(const set<T> &A) {	for(T x:A) cout << x << " ";}

/*3) DiferenciaSim´etrica. Dada una lista de conjuntos de
enteros list< set<int> > l escribir una
funci´on void diffsym(list< set<int> > &L, set<int> &ad) que
retorna en ad el conjunto de los elementos que pertenecen a uno y s´olo 
uno de los conjuntos de L. Por ejemplo, si L = ({1,2,3},{2,4,5},{4,6})
entonces ad = {1,3,5,6}. Notar que si el n´umero de conjuntos
en L es 2 y los llamamos A y B, entonces debe retornar ad = (A-B) ?(B-A).*/

void diffsym(list<set<int>> &L, set<int> &ad){
	
	auto it1=L.begin();
	while(it1!=L.end()){
		
		set<int>C=*it1;
		
		auto it2=L.begin();
		while(it2!=L.end()){
			
			if(it2!=it1){
				set<int>D;
				set_difference(C,*it2,D);
				C=D;
			}
			it2++;
		}
		
		ad.insert(C.begin(),C.end());
		
		it1++;
	}
	
}

int main() {
	list<set<int>> L = {{1,2,3},{2,4,5},{4,6}};
	set<int>ad;

	diffsym(L,ad);
	show_set(ad);
	return 0;
}







