#include <iostream>
using namespace std;

float *vectornuevo(float *vec,int n,int cantprom){
	int suma=0;
	
	float *v = new float[cantprom];
	
	for(int i=0;i<n;i++) { 
		suma+=*(vec+i);
	}
	float prom=suma/n;
	
	for(int i=0;i<n;i++){
		if(*(vec+i)>prom){
			*(v+i)=*(vec+i);
		}
	}
	return v;
}

int superaprom(float *vec,int n){
	
	int suma=0;
	
	for(int i=0;i<n;i++) { 
		suma+=*(vec+i);
	}
	float prom=suma/n;
	
	int cant=0;
	for(int i=0;i<n;i++){
		if(*(vec+i)>prom) cant++;
	}
	cout<<"PROMEDIO: "<<prom<<endl;
return cant;	
}

int main() {
	int n;
	cout<<"ingrese longitud del vector"<<endl;
	cin>>n;
	
	float *vec=new float[n];
	
	for(int i=0;i<n;i++) { 
		cout<<"Ingrese datos: "<<endl;
		cin>>*(vec+i);
	}
	cout<<"LA CANT Q SUPERAN EL PROMEDIO SON:"<<superaprom(vec,n)<<endl;
	
	int cantprom=superaprom(vec,n);
	float *v=vectornuevo(vec,n,cantprom);
	
	for(int i=0;i<cantprom;i++){
		cout<<*(v+i)<<"  ";
	}
	
	return 0;
}

