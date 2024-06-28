#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct postulante{
	string alumno;
	int cod_alum;
	int dni;
	int cant_aprob;
	int cant_insuf;
	float prom;
};

void alumnoreemplazar(vector<postulante>&lista,int codigonuevo);
int buscarpos(vector<postulante>lista,int codigo);
tuple<int,int> buscarmayores(vector<postulante>lista);
int buscaralumno(vector<postulante>lista,int dni,int inicio);

int main() {
	int N,E;
	cout<<"cuantos alumnos hay?"<<endl;
	cin>>N;
	vector<postulante>lista(N);
	
	for(int i=0;i<lista.size();i++){
		cout<<"ingrese nombre y apellido de alumno"<<endl;
		cin.ignore();
		getline(cin,lista[i].alumno);
		cout<<"ingrese cod(numero entre 1 y "<<N<<endl;
		cin>>lista[i].cod_alum;
		cout<<"ingrese dni"<<endl;
		cin>>lista[i].dni;
		cout<<"ingrese cant apro"<<endl;
		cin>>lista[i].cant_aprob;
		cout<<"ingrese cant insuf"<<endl;
		cin>>lista[i].cant_insuf;
		cout<<"ingrese prom"<<endl;
		cin>>lista[i].prom;
	}
	
	cout<<"cuantos examenes se realizaron?"<<endl;
	cin>>E;

	int cont=0,codigo,indice,nota;
	while(cont<E){
		cout<<"ingrese codigo del alumno"<<endl;
		cin>>codigo;
		
		indice=buscarpos(lista,codigo);
		
		cout<<"ingrese nota obtenida"<<endl;
		cin>>nota;
		
		if(nota>=6){
			float prom=(lista[indice].prom*lista[indice].cant_aprob+nota)/(lista[indice].cant_aprob+1);
			lista[indice].cant_aprob+1;
			lista[indice].prom=prom;
		}else{
			lista[indice].cant_insuf+1;
		}
		cont++;
	}

	int codigonuevo;
	cout<<"ingrse codigo del alumno a reemplazar"<<endl;
	cin>>codigonuevo;
	alumnoreemplazar(lista,codigonuevo);
	
	int indice1,indice2;
	tie(indice1,indice2)=buscarmayores(lista);
	
	cout<<lista[indice1].prom<<" mejor promedio"<<endl<<lista[indice2].prom<<" 2do mejor promedio"<<endl;
	
	int dni;
	cout<<"ingrese dni del alumno a buscar"<<endl;
	cin>>dni;
	
	int inicio=buscaralumno(lista,dni,0);
	if(inicio==-1){
		cout<<"no se encontro alumno con ese dni"<<endl;
	}else{
		cout<<"el alumno con el dni: "<<dni<<" se encuentra en la posicion: "<<inicio+1;
	}
	return 0;
}
int buscarpos(vector<postulante>lista,int codigo){
	
	for(int i=0;i<lista.size();i++){
		if(lista[i].cod_alum==codigo){
			return i;
		}
	}
	return -1;
}
	
void alumnoreemplazar(vector<postulante>&lista,int codigonuevo){
	
	int indice=buscarpos(lista,codigonuevo);
	cout<<"ingrese nombre y apellido de alumno"<<endl;
	cin.ignore();
	getline(cin,lista[indice].alumno);
	cout<<"ingrese cod(numero entre 1 y "<<endl;
	cin>>lista[indice].cod_alum;
	cout<<"ingrese dni"<<endl;
	cin>>lista[indice].dni;
	cout<<"ingrese cant apro"<<endl;
	cin>>lista[indice].cant_aprob;
	cout<<"ingrese cant insuf"<<endl;
	cin>>lista[indice].cant_insuf;
	cout<<"ingrese prom"<<endl;
	cin>>lista[indice].prom;
}

tuple<int,int> buscarmayores(vector<postulante>lista){
	float mayor1=0,mayor2=0;
	int indice1=0,indice2=0;
	
	for(int i=0;i<lista.size();i++){
		if(lista[i].cant_insuf<=1){
			if(lista[i].prom>mayor1){
				mayor2=mayor1;
				indice2=indice1;
				
				lista[i].prom=mayor1;
				indice1=i;
			}else{
				if(lista[i].prom>mayor2){
					lista[i].prom=mayor2;
					indice2=i;
				}
			}
		}
	}
	
	return make_tuple(indice1,indice2);
}

int buscaralumno(vector<postulante>lista,int dni,int inicio){
	
	if(lista[inicio].dni==dni){
		return inicio;
	}else{
		return buscaralumno(lista,dni,inicio+1);
	}
	
	return -1;
	
}
