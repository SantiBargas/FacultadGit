#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T> list<T> vector_a_lista(vector<T>v){
	
	list<T>aux;
	sort(v.begin(),v.end());
	auto it=unique(v.begin(),v.end());
	v.erase(it,v.end());
	
	for(size_t i=0;i<v.size();i++) { 
		aux.push_back(v[i]);
	}
	
	return aux;
	
}
int rand25(){return rand()%15;}
int main() {
	
	vector<int>v(20);
	generate(v.begin(),v.end(),rand25);
	cout<<"Vector: "<<endl;
	for(int x:v) cout<<x<<"  ";
	cout<<endl;
	
	list<int>l;
	l=vector_a_lista(v);
	cout<<"Lista: "<<endl;
	for(int x:l)cout<<x<<"  ";
	
	
	return 0;
}

