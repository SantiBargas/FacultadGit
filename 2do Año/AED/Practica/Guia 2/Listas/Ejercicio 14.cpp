#include <iostream>
#include <list>
using namespace std;
/*Merge. Escribir una funci´on void merge(list<int> &L1, list<int> &L2, list<int>& L) la
cual recibe dos listas ordenadas (que pueden ser de distinto tama˜no) de forma ascendente L1 y L2
y retorna una lista L, pasada como par´ametro, con los elementos de ambas ordenados tambi´en en
forma ascendente. Por ejemplo si L1=[1, 3, 6, 11] y L2=[2, 4, 6, 10], la lista L debe quedar
como L=[1, 2, 3, 4, 6, 6, 10, 11].*/

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

void merge(list<int> &L1, list<int> &L2, list<int>& L){
	
	list<int>::iterator itLini=L.begin();
	list<int>::iterator itLend=L.end();

	
	
	L.insert(itLini,L1.begin(),L1.end());
	L.insert(L.end(),L2.begin(),L2.end());
	L.sort();
}



int main(int argc, char *argv[]) {
	
	list<int>L1 {1,3,5,7,9};
	list<int>L2 {2,4,6,8,10};
	list<int>L{};
	
	merge(L1,L2,L);
	show_list(L);
	
	
	return 0;
}

