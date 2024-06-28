#include <iostream>
using namespace std;

int *intercala(int *a,int an,int *b, int bn){
	
	int *v = new int[an+bn];
	
	int iv=0; //indice para moverse
	int n;
	if(an>bn) n=an; else n=bn;  //para saber hasta donde el for,va hasta el mas grande
	
	for(int i=0;i<n;i++){
		if(i<an){//pregunto si es valida la posicion
			*(v+iv)= *(a+i);
			iv++;
		}
		if(i<bn){
			*(v+iv)=*(b+i);
			iv++;
		}
	}
	
	return v;
}

int main() {
	
	int a[]={2,4,5,1,6,3};
	int b[]={10,20};
	
	int *v= intercala(a,6,b,2);
	for(int i=0;i<8;i++) { 
		cout<<v[i]<<" ";
	}
	
	return 0;
}

