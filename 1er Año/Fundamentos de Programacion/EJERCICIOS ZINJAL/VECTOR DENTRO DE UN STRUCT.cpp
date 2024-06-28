#include <iostream>
#include <vector>
using namespace std;

struct vendedor{
	string nombre;
	int dni;
	vector<int>montos;
};
int main() {
	int N;
	cout<<"CUANTOS VENDEDORES HAY?"<<endl;
	cin>>N;
	vector<vendedor>lista(N);
	vendedor v;
	
	
	for(int i=0;i<lista.size();i++){
		cout<<"ingrese nombre"<<endl;
		cin>>v.nombre;
		cout<<"ingrese dni"<<endl;
		cin>>v.dni;
		
		v.montos.resize(3);
		
		cout<<"INGRESE VALOR VENTAS"<<endl;
		for(int j=0;j<v.montos.size();j++){
			cin>>v.montos[j];
		}
		lista[i]=v;
	}
	cout<<endl<<endl<<endl<<endl;
	
	for(int i=0;i<lista.size();i++){
		
		cout<<"NOMBRE: "<<lista[i].nombre<<endl;
		cout<<"DNI: "<<lista[i].dni<<endl;
		cout<<"MONTOS: "<<endl;
		for(int j=0;j<v.montos.size();j++){
			cout<<lista[i].montos[j]<<endl;
		}
		cout<<endl<<endl;
		
	}
	
	return 0;
}

