#include <iostream>
#include <list>
using namespace std;
 /*Concatena. Escriba procedimientos para concatenar: a) dos listas L1 y L2 usando insert; b) una
	lista LL de n sublistas usando insert; c) una lista LL de n sublistas usando splice. Cada
	procedimiento debe retornar el resultado en una lista nueva.*/


void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

list<int> concatenarA(list<int>& L1, list<int>& L2){
	list<int>L=L1;
	L.insert(L.end(),L2.begin(),L2.end());
	return L;
}

void concatenarB(list<list<int>>&LL, list<int>&L){
	
	L.clear();
	list<list<int>>::iterator itB=LL.begin();
	while(itB!=LL.end()){
		L.insert(L.end(),itB->begin(),itB->end());
		itB++;
	}
}
	
void concatenarC(list<list<int>>&LL, list<int>&L){
	L.clear();
	list<list<int>>::iterator itB=LL.begin();
	
	while(itB!=LL.end()){
		L.splice(L.end(),*itB);
		itB++;
	}
	show_list(L);
}

int main() {
	
	list<int>L1{1,2,3,4,5};
	list<int>L2{6,7,8,9,10};
	
	list<int>L=concatenarA(L1,L2);
	
	show_list(L);
	
	list<list<int>>L3 {{1,2,3},{7,8,9},{4,5,6}};
	concatenarC(L3,L1);
	return 0;
}

