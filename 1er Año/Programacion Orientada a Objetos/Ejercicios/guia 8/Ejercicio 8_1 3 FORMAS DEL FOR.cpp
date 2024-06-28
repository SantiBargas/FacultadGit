#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	
	cout<<"ingrese 15 valores"<<endl;
	int x;
	vector<int>v;
	for(int i=0;i<15;i++) { 
		cin>>x;
		v.push_back(x);
	}
	
	for(size_t i=0;i<v.size();i++) { 
		cout<<v[i]<<"  ";
	}cout<<endl<<endl;
	
	for(int x : v)	cout<<x<<"  ";
	cout<<endl<<endl;
	
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<"  ";
	}cout<<endl<<endl;
	
	auto it_max=max_element(v.begin(),v.end());
	cout<<"El maximo es: "<<*it_max<<endl;
	auto it_min=min_element(v.begin(),v.end());
	cout<<"El minimo es: "<<*it_min<<endl;
	
	int suma=accumulate(v.begin(),v.end(),0);
	cout<<"La suma es: "<<suma<<endl;
	cout<<"El promedio es:"<<suma/v.size()<<endl;
	
	sort(v.begin(),v.end()); //ordeno para sacar el valor del medio
	int medio=v.size()/2;
	cout<<"El elemento del medio es: "<<v[medio]<<endl;
	
	cout<<"ingrese valor a buscar en el arreglo"<<endl;
	int valor;cin>>valor;
	
	auto it=find(v.begin(),v.end(),valor);
	if(it!=v.end()){
		cout<<"el valor esta en la posicion: "<<distance(v.begin(),it);
	}
	
	return 0;
}

