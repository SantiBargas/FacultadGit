#include <iostream>
#include <vector>
using namespace std;

struct persona{
	string nombre;
	int dni;
	int edad;
	string email;
};

int main() {
	persona p;
	vector<persona>lista(3);
	
	for (int i=0;i<lista.size();i++){
		cout<<"ingrese nombre"<<endl;
		cin>>lista[i].nombre;
		cout<<"ingrese dni"<<endl;
		cin>>lista[i].dni;
		cout<<"ingrese edad"<<endl;
		cin>>lista[i].edad;
		cout<<"ingrese email"<<endl;
		cin>>lista[i].email;
	}
	
	for (int i=0;i<lista.size();i++){
		cout<<"nombre: "<<lista[i].nombre<<endl;;
		
		cout<<"dni:  "<<lista[i].dni<<endl;
		
		cout<<"edad: "<<lista[i].edad<<endl;
		
		cout<<"email: "<<lista[i].email<<endl;
		
		cout<<"--------------------------------------------------------------------------------------"<<endl;
	}
	return 0;
}

