#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mostrar(string s,vector<int>v){
	cout<<s<<"  : ";
	for(int x:v) cout<<x<<"  ";
	cout<<endl<<endl;
}

int rand25(){return rand()%25;}
	
int main() {
	
	vector<int>v(30);
	
	generate(v.begin(),v.end(),rand25);
	mostrar("v",v);
	
	sort(v.begin()+10,v.begin()+21);
	mostrar("vordenado",v);
	
	vector<int>v2;
	for(size_t i=10;i<=20;i++) { 
		v2.push_back(v[i]);
	}
	mostrar("v2",v2);
	
	v.erase(v.begin()+10,v.begin()+21);
	mostrar("vborrado",v);
	
	cout<<"Ingrese valor que quiere ver cuanto se repite"<<endl;
	int valor;cin>>valor;

	cout<<valor<<" Se repite: "<<count(v.begin(),v.end(),valor)<<" Veces"<<endl;
	auto it=remove(v.begin(),v.end(),valor);
	v.erase(it,v.end());
	
	mostrar("vector final",v);
	
	return 0;
}

