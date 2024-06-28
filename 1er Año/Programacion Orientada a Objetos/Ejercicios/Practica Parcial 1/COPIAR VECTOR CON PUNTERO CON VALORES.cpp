#include <iostream>
using namespace std;
/*a) Escriba una función que reciba 3 punteros de tipo float, el primero y segundo
	indican el comienzo y final de los elementos que deben ser copiados de un arreglo hacia otro. El
	comienzo del vector destino es apuntado por el tercer puntero recibido. b) Haga uso de la función desde
	un programa cliente.*/

void copiar (float *p_desde, float *p_hasta, float *p_destino){
	
	int n= p_hasta-p_desde;  //el tamaño del vector que es 5, cant de posiciones
	
	
	for (int i=0;i<n;i++){
		p_destino[i]=p_desde[i]; //p_desde representa v1
								//p_destino representa v2
	}
}
int main() {
	float *v1 = new float[5];
	
	for(int i=0;i<5;i++){
		v1[i]=10*(1+i); //10;20;30;40;50
	}
	
	float *v2=new float[5];
	copiar(v1,v1+5,v2);   // desde donde empieza v1,hasta 5 posiciones mas,se locopio a v2
						 // v1+5 es la direccion donde termina el vector
	
	for(int i=0;i<5;i++){
		cout<<v2[i]<<endl;
	}
	
	delete [] v1;
	delete [] v2;
	return 0;
}

