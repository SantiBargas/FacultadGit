#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int sumalista(vector<int>lista, int indice);
tuple<int,int>IncisoB(vector<int>lista);
int main() {
	int N;
	
	
	cout<<"ingrese cant de valores"<<endl;
	cin>>N;
	vector<int>lista(N);
	vector<int>superamedia;
	vector<int>nosuperamedia;
	
	
	
	
	for (int i=0;i<lista.size();i++){
		lista[i]= 10+rand()%200;
	}
	int suma=sumalista(lista,0);
	
	cout<<"el vector es "<<endl;
	for (int i=0;i<lista.size();i++){
		cout<<lista[i]<<endl;
	}
	cout<<" "<<endl;
	cout<<"la suma total del vector es "<<suma<<endl;
	
	
	
	int superan,por_debajo;
	tie(superan,por_debajo)= IncisoB(lista);
	cout<<superan<<" valores superan la media"<<endl;
	cout<<por_debajo<<" valores no superan la media"<<endl;
	return 0;
}

int sumalista(vector<int>lista, int indice){
	
	if(indice ==lista.size()-1){
		return lista[indice];}
	else{
		return lista[indice]+ sumalista(lista,indice+1);
	}
}	


tuple<int,int> IncisoB(vector<int>lista){
	int suma=sumalista(lista,0); ///ejecuto la sumatoria recursiva
	int promedio= suma/lista.size();
	int superan=0,por_debajo=0;
	
	
	for(int i=0;i<lista.size();i++){
		if(lista[i]>promedio){
			superan++;
		}
		if(lista[i]<promedio){
			por_debajo++;
		}
	}
	
	return make_tuple(superan,por_debajo);
}

	
	
