#include <iostream>
#include <vector>
using namespace std;

void datos_ficticios (vector<float> &lista,int N);

float media(vector<float> lista);
	

int main() {
	int N;
	float temp;
	cout<<"ingrese cant de temperaturas"<<endl;
	cin>>N;
	vector<float> lista(N);
	
	
	for (int i=0;i<lista.size();i++){
		cout<<"ingrese valor de la temp"<<endl;
		cin>>temp;
		lista[i]=temp;
	}
	
	for (int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	
	datos_ficticios(lista, N);
	
	cout<<"nuevo arreglo"<<endl;
	
	for (int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	
	cout<<"El promedio de los ultimos 150 dias es"<<media(lista);
	
	return 0;
}

void datos_ficticios (vector<float> &lista, int N){
	
	for (int i=0;i<lista.size();i++){
		if(i==0){
			if(lista[i]==999){
				lista[i]==lista[i+1];
			}
		}
		
		if (i==N-1){
			if (lista[i]==999){
				lista[i]==lista[i-1];
			}	
		}
		
		if(lista[i]==999){
			if(lista[i-1]>lista[i+1]){
				lista[i]=lista[i+1];
			}else{
				lista[i]=lista[i-1];
			}
			
		}
	}
	
}

float media(vector<float> lista){	
	float suma=0;
	for (int i=0;i<150;i++){
		suma+=lista[i];
	}
	float promedio;
	promedio=suma/150;
	return promedio;
}	
