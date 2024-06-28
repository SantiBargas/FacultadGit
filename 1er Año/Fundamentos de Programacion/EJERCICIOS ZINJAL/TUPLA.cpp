#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
using namespace std;

int getcantmultiplos(vector<int>lista,int divisor);
tuple<int,int>getpromedio(vector<int>lista);
int N;
int promedio;
int mayoralpromedio;
int main() {
	
	cout<<"ingrese cantidad de valores"<<endl;
	cin>>N;
	
	vector<int>lista(N);
	
	for (int i=0;i<lista.size();i++){
		lista[i] = 100 + rand()%800;
	}
	
	int cant= getcantmultiplos(lista,6);
	cout<<" hay "<<cant<<" multiplos de 6"<<endl;
	
	tie(promedio,mayoralpromedio) = getpromedio(lista);
	cout<<"el promedio es "<<promedio<<endl;
	cout<<"los mayores al promedio son "<<mayoralpromedio<<endl;
	return 0;
}


	
	
int getcantmultiplos(vector<int>lista,int divisor){
	int cantmultimplos=0;
	for (int i=0;i<lista.size();i++){
		if(lista[i] % divisor ==0){
			cantmultimplos++;
		}
	}
	return cantmultimplos;
}




tuple<int,int>getpromedio(vector<int>lista){
	int totalnum=0;
	for(int i=0;i<lista.size();i++){
		totalnum += lista[i];
	}
	
	promedio = totalnum/lista.size(); 
	
	for(int i=0;i<lista.size();i++){
		if(lista[i]>promedio){
			mayoralpromedio++;
		}
	}
	return make_tuple(promedio,mayoralpromedio);
}
