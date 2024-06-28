#include <iostream>
#include <vector>
using namespace std;

struct ficha{
	string cliente;
	int dni;
	int edad;
	char sexo;
};

int reagrupar(vector<ficha>&lista);

int main() {
	string nombre;
	cout<<"ingrese nombre (. termina)"<<endl;
	cin>>nombre;
	
	vector<ficha>lista;
	
	while(nombre!="."){
		ficha f; ///nueva instancia de una variable ficha	
		f.cliente=nombre;;
		
		cout<<"ingrese dni"<<endl;
		cin>>f.dni;
		
		cout<<"ingrese edad"<<endl;
		cin>>f.edad;
		
		cout<<"ingrese sexo"<<endl;
		cin>>f.sexo;
		
		lista.push_back(f);
		
		cout<<"ingrese nombre (. termina)"<<endl;
		cin>>nombre;
	}
	
	int mujeres = reagrupar(lista);
	
	cout<<"la cant de mujeres son: "<<mujeres<<endl;
	cout<<"el nuevo vector ordenado es: "<<endl;
	reagrupar(lista);
	
	for(int i=0;i<lista.size();i++){
		cout<<lista[i].cliente<<endl;
		cout<<lista[i].dni<<endl;
		cout<<lista[i].edad<<endl;
		cout<<lista[i].sexo<<endl;
	}
	
	
	return 0;
}

int reagrupar(vector<ficha>&lista){
	vector<ficha>aux; ///sin dimension
	int mujeres=0;
	///1er recorrido, acomodar todos los de edad >=18
	for (int i=0;i<lista.size();i++){
		if (lista[i].edad >=18){
			aux.push_back(lista[i]); ///lo agrego a aux
		}
		if (lista[i].sexo=='F'){
			mujeres++;
		}
	}
	
	///2do recorrido, acomodar todos los de edad <18
	
	for (int i=0;i<lista.size();i++){
		if (lista[i].edad < 18){
			aux.push_back(lista[i]); ///lo agrego a aux
		}
		
	}
	
	///reasigno el vector reordenado
	lista=aux;
	
	return mujeres;
}
