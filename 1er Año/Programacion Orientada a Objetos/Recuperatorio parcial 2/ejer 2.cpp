#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T> bool mayor(T x,vector<T>v){
	for(int i=0;i<v.size();i++){
		if(v[i]<x){
			return true;
		}
	}
	return false;
}

template<typename T> vector<T> sublistado(string nombre,T x){

	ifstream archi(nombre);
	if(!archi.is_open()){
		cout<<"No se pudo abrir el archivo ";
	}
	vector<T>v;
	while (archi>>x){
		v.push_back(x);
	}
	
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	remove_if(v.begin(),v.end(),mayor(x,v));
	
	
	
	return v;
	
}


int main() {
	
	sublistado("list_int.txt",42);
	
	return 0;
}

