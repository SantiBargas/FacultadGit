#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
/*Escriba una función que reciba un arreglo de enteros (y su tamaño), y busque
	elementos repetidos dentro del mismo. La función debe retornar un struct con dos
	punteros apuntando a dos elementos del arreglo que tengan el mismo valor. Si hay
	más de dos elementos repetidos, la función puede retornar cualquier par de ellos.
	Si no hay elementos repetidos, la función debe retornar NULL en ambos punteros.*/


struct Punteros{
	float *p=nullptr;
	float *a=nullptr;
};

struct Punteros DevolverPunteros(vector<float >&b){
	
	
	Punteros pun;
	
	for(float i=0;i<b.size();i++){
		for(int j=j+1;j<b.size();j++){
			if(b[i]==b[j]){
				pun.p=&b[i];
				pun.a=&b[j];
				return pun;
			}
		}
		
	}
	pun.a=nullptr;
	pun.p=nullptr;
	return pun;
}


int main() {
	
	vector<float >lista(10);
	
	for(int i=0;i<lista.size();i++){
		lista[i]=rand()%8;
		cout<<lista[i]<<"   ";
	}
	cout<<endl;
	
	
	
	Punteros p;
	p = DevolverPunteros(lista);
	
	if(p.p!=nullptr){
		cout<<"El numero que se repite es: "<<*p.a<<"    "<<"en las direcciones :"<<p.a<<" "<<p.p;
	}

	
	return 0;
}

