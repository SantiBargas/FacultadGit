#include <iostream>
#include <vector>
using namespace std;

struct persona{
	int codalumno;
	int dni;
	string nombre;
	int nota;
};


void LeerDatos(vector<persona>&lista);
void foo(vector<persona> lista, int mostrar);






void foo(vector<persona> lista, int mostrar) {
	cout<<"el cod alumno es: "<<lista[mostrar-1].codalumno<<endl;
	cout<<"el dni es: "<<lista[mostrar-1].dni<<endl;
	cout<<"el nombre es: "<<lista[mostrar-1].nombre<<endl;
	cout<<"la nota es: "<<lista[mostrar-1].nota<<endl;
}

int main() {
	persona p;
	int mostrar;
	vector<persona>lista(3);
	
	foo(lista);
	
	cout<<"ingrese el cod alumno que desea saber"<<endl;
	cin>>mostrar;
	
	foo(lista,mostrar);
	
	
	return 0;
}

void foo(vector<persona>&lista) {
	for(int i=0;i<lista.size();i++){
		cout<<"ingrese cod alumno"<<endl;
		cin>>lista[i].codalumno;
		
		cout<<"ingrese dni"<<endl;
		cin>>lista[i].dni;
		
		cout<<"ingrese nombre"<<endl;
		cin>>lista[i].nombre;
		
		cout<<"ingrese nota"<<endl;
		cin>>lista[i].nota;
	}
}


