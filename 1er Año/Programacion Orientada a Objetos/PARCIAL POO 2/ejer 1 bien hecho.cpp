#include <iostream>
#include <list>
using namespace std;

struct Racional{
	int num,den;
};
bool operator< (Racional a,Racional b){
	return (a.num*b.den<b.num*a.den);
}
template<typename T> list<T> funcion(list<T>l, T num){
	
	list<T>auxiliar;
	for(auto it=l.begin();it!=l.end();next(l.begin(),2)){
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
	cout<<endl<<endl;
	
	
	
	list<string>l2{"Hola","Casa","Arbol","Duende"};
	
	cout<<"INGRESE PALABRAS PARA ORDENAR CON VALORES MENORES: "<<endl;
	string p;cin>>p;
	list<string>aux2=funcion(l2,string("hola"));
	
	for(auto it=aux2.begin();it!=aux2.end();it++){
		cout<<*it<<"  ";
	}
	cout<<endl<<endl;
	
	
	
	list<float>l3{10.1,2.6,5.1,7.3,12.6,15.0,5.2};
	
	cout<<"INGRESE FLOTANTE PARA ORDENAR CON VALORES MENORES: "<<endl;
	float f;cin>>f;
	list<float>aux3=funcion(l3,f);
	
	for(auto it=aux3.begin();it!=aux3.end();it++){
		cout<<*it<<"  ";
	}
	cout<<endl<<endl;
	
	list<Racional>l4{{10,20},{12,6},{2,6}};
	
	cout<<"INGRESE RACIONAL PARA ORDENAR CON VALORES MENORES: "<<endl;
	Racional r;cin>>r.den>>r.num;
	auto aux4=funcion(l4,{10,25});
	
	for(auto it=aux4.begin();it!=aux4.end();it++){
		
		cout<<"NUMERADOR:" <<it->num<<"  ";
		cout<<"DENOMINADOR: "<<it->den<<"  ";
		cout<<endl;
	}
	cout<<endl<<endl;
	
	
	
	
	return 0;
}

