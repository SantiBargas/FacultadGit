#include <iostream>
using namespace std;

struct arreglo{
	int *p;
	int size;
};

void redimension(arreglo &v, int new_size){
	int *new_p = new int[new_size];
	
	for(int i=0;i<v.size;i++){
		new_p[i]=v.p[i];  ///copia los valores del arreglo viejo al nuevo arreglo
	}
	for(int i=v.size;i<new_size;i++){
		new_p[i]=0; ///relleno las nuevas partes con 0
	}
	
	delete[]v.p;
	v.p= new_p; ///apunto al struct que trabaje con el nuevo arreglo
	v.size=new_size;
}

void insertar(arreglo &v,int val,int pos){
	
	redimension(v,v.size+1);
	
	for(int i=v.size;i>pos;i--){
		v.p[i]=v.p[i-1];
	}
	v.p[pos]=val;
}

int main() {
	
	arreglo v;
	
	v.p= new int[10];
	v.size= 10;
	
	cout<<"Arreglo inicial: "<<endl;
	for(int i=0;i<v.size;i++){
		v.p[i]= 1000+rand()%501;
		cout<< v.p[i] <<"  ";
	}
	cout<<endl;
	
	insertar(v,42,5);
	
	cout<<"Arreglo final: "<<endl;
	for(int i=0;i<v.size;i++){
		v.p[i]= 1000+rand()%501;
		cout<< v.p[i] <<"  ";
	}
	cout<<endl;
	
	delete [] v.p;
	
	return 0;
}
	

