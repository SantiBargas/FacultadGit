#include <iostream>
#include <vector>
using namespace std;

void datos_ficticios (vector<float> &lista,int N);

float diferencia(vector<float> lista);


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
	
	cout<<"la diferencia entre el mayor y menor de la lista es: "<<diferencia(lista);
	
	
	return 0;
}

void datos_ficticios (vector<float> &lista, int N){
	
	float promedio= (lista[0]+lista[N-1])/2;
	for (int i=0;i<lista.size();i++){
		if(lista[i]==999){
			lista[i]=promedio;
		}
	}
	
	
}
float diferencia(vector<float> lista){
	float mayorlista=0,menorlista=999;
	
	for(int i=0;i<lista.size();i++){
		if(lista[i]>mayorlista){
			mayorlista=lista[i];
		}
		if(lista[i]<menorlista){
			menorlista=lista[i];
		}
		
	}
	float total=mayorlista-menorlista;
	return total;
}
