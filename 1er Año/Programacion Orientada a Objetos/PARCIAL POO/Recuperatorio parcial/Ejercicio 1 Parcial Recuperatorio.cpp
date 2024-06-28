#include <iostream>
#include <tuple>
using namespace std;

tuple<int*,int> eliminaRepetidos(int* arreglo,int tam){
	
	int *aux=new int [tam];
	
	int iv=0;
	
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			if(*(aux+i)!=*(arreglo+j)){  ///recorro todo el arreglo y si es distinto lo asigno al nuevo
				*(aux+i)=*(arreglo+i);
				iv++;					///cuento cuantos agrego para el tamaño del definitivo
			}
		}
	}
	int *definitivo=new int[iv];
	
	for(int i=0;i<iv;i++){
		*(definitivo+i)=*(aux+i);
	}
	
	delete []aux;
	
	return make_tuple(definitivo,iv); //arreglo definitivo con su tamaño
	
}

int main() {
	int n;
	cout<<"ingrese longitud del vector"<<endl;
	cin>>n;
	
	int *arreglo=new int[n];
	
	for(int i=0;i<n;i++) { 
		cout<<"Ingrese datos: "<<endl;
		cin>>*(arreglo+i);
	}
	
	int tamanio;
	int *definitivo;
	tie(definitivo,tamanio)=eliminaRepetidos(arreglo,n);
	
	for(int i=0;i<tamanio;i++){
		cout<<definitivo[i]<<"  ";
	}
	
	
	delete []arreglo;
	delete []definitivo;
	
	return 0;
}

