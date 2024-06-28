#include <iostream>
using namespace std;

///	Utilizando notación de punteros, generar un arreglo dinámico y lineal de N
///	elementos numéricos enteros, con valores aleatorios entre 1000 y 1500, y muestre
///	en pantalla la dirección de memoria del mayor elemento. N es un dato ingresado
///	por el usuario.

int *buscar(int *v, int n ,int val){
	for(int i=0;i<n;i++){
		if(v[i]==val){
			return v+i;
			// return &(v[i]);
		}
	}
	return nullptr;
}
int main() {
	
	int N;
 	cout<<"ingrese cant de elementos"<<endl;
	cin>>N;
	
	int *p= new int[N];
	
	for(int i=0;i<N;i++){
		*(p+i) = 1000+rand()%501;	///sabiendo la direccion del 1ero sumandole i, va al siguiente
		/* p[i] = 1000+rand()%501; */	///cualq de las dos es valida
	}
	
	cout<<" El arreglo empieza en "<<p<<endl;
	for(int i=0;i<N;i++){
		cout<< i <<" = "<<*(p+i)<<endl;
	}

	
	int may =0, *dir;
	
	for(int i=0;i<N;i++){
		if(p[i]>may){
			may= p[i]; ///guardo el valor mayor
			dir= p+i;  ///guardo la direccion del mayor
		}
	}
	cout<<"el mayor se encuentra en la direccion: "<<dir<<endl;
	
	int val;
	cout<<"ingrese valor a buscar"<<endl;
	cin>>val;
	int *d=buscar(p,N,val);
	if(d==nullptr){
		cout<<" valor buscado no se encuentra";
	}else{
		cout<<"La direccion del valor buscado es: "<<d;
		
	}
	
	delete [] p; ///se borra todos los elementos del arreglo, se ponen corchetes
	return 0;
}

