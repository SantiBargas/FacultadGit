#include <iostream>
using namespace std;

int *find_if_even(int *start, int *end){
	
	for(int *i = start ; i<end ; i++){
		if(*i%2==0){
			return i;
		}
	}
	return nullptr;
}

int main() {
	
	int tamanio=10;
	
	int *arreglo=new int[tamanio];
	
	for(int i=0;i<tamanio;i++){
		arreglo[i]=rand()%100;
		
		cout<<"v ["<<i<<"]"<<" "<<arreglo[i]<<endl;
	}
	
	int *encontrar=find_if_even(arreglo, arreglo+tamanio); //le paso la primer direccion del arreglo y la ultima sumandole el tamaño
	
	if(encontrar==nullptr){
		cout<<"No se encontraron valores par en el arreglo"<<endl;
	}else{
		cout<<"El primer valor par que aparece es: "<<*encontrar<<" y se encuentra en la direccion: "<<encontrar;
	}
	
	delete []arreglo;
	return 0;
}

