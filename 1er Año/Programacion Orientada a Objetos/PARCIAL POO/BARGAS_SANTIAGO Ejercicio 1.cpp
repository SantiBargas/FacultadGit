#include <iostream>
#include <list>
using namespace std;

struct Racional{
	int num,den;
};
bool operator< (Racional a,Racional b){
	return (a.num*b.den<b.num*a.den);
}
template<typename T> list<T> funcion(list<T>l, int num){
	
	list<T>auxiliar;
	for(auto it=l.begin();it!=l.end();it++){
		if(*it<num){
			auxiliar.push_back(*it);
		}
	}
	
	return auxiliar;
	
}

int main() {
	
	
	list<int>l{10,2,5,7,12,15,5};
	
	cout<<"INGRESE NUMERO PARA ORDENAR CON VALORES MENORES: "<<endl;
	int num;cin>>num;
	
	list<int>aux=funcion(l,num);
	
	for(auto it=aux.begin();it!=aux.end();it++){
		cout<<*it<<"  ";
	}
	
	return 0;
}

