#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct alumnos{
	string nombre;
	string localidad;
	int fecha;
};

tuple<int,int> mayormenor(vector<alumnos>lista);
void nuevovector(vector<alumnos>&lista,string localidadbuscar);

int main() {
	int N;
	cout<<"cuantos alumnos hay?"<<endl;
	cin>>N;
	vector<alumnos>lista(N);
	
	for (int i=0;i<lista.size();i++){
		alumnos a;
		
		cout<<"ingrese fecha del alumno en 0 termina"<<endl;
		cin>>a.fecha;
		if(a.fecha==0){
			break;
		}
		cout<<"ingrese nombre del alumno"<<endl;
		cin>>a.nombre;
		cout<<"ingrese localidad del alumno"<<endl;
		cin>>a.localidad;
		
		lista[i]=a;
	}
	
	
	int mayor,menor;
	tie(mayor,menor)=mayormenor(lista);
	cout<<"la persona mayor es: "<<lista[mayor+1].nombre<<"  "<<lista[mayor+1].localidad<<"  "<<lista[mayor+1].fecha<<endl;
	cout<<"la persona menor es: "<<lista[menor+1].nombre<<"  "<<lista[menor+1].localidad<<"  "<<lista[menor+1].fecha<<endl;
	
	cout<<"que localidad desea buscar"<<endl;
	string localidadbuscar;
	cin>>localidadbuscar;
	
	nuevovector(lista,localidadbuscar);
	
	for (int i=0;i<lista.size();i++){
		cout<<lista[i].nombre<<"  "<<lista[i].localidad<<"  "<<lista[i].fecha<<endl;
	}
	
	
	
	return 0;
}

tuple<int,int> mayormenor(vector<alumnos>lista){
	
	int mayor=0,menor=1000000000;
	
	for (int i=0;i<lista.size();i++){
		if(lista[i].fecha>mayor){
			mayor=i;
		}else{
			if(lista[i].fecha<menor){
				menor=i;
			}
		}
	}
	
	return make_tuple(mayor,menor);
}
	
void nuevovector(vector<alumnos>&lista,string localidadbuscar){
	vector<alumnos>aux;
	
	for (int i=0;i<lista.size();i++){
		if(lista[i].localidad==localidadbuscar){
			aux.push_back(lista[i]);
		}
	}
	lista=aux;
	
}
