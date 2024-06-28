#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template<typename T> vector<T> lista_a_vector(list<T>L){
	
	L.sort();
	auto it=unique(L.begin(),L.end());
	L.erase(it,L.end());
	
	vector<int>aux(L.size());
	copy(L.begin(),L.end(),aux.begin());
	
	return aux;
	
	
}

int main() {
	
	list<int>L;
	
	for(int i=0;i<15;i++){
		L.push_back(1+rand()%10);
	}
	
	cout<<"LISTA: "<<endl;
	for(int x:L) cout<<x<<"  ";
	cout<<endl<<endl;
	
	cout<<"VECTOR: "<<endl;
	vector<int>V=lista_a_vector(L);
	
	for(int x:V)cout<<x<<"  ";
	
	return 0;
}

