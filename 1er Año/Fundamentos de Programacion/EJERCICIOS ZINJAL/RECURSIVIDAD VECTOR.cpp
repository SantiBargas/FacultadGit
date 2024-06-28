#include <iostream>
#include <vector>
using namespace std;

int buscarpos(vector<int>lista, int indice, int nrobuscar);

int main() {
	vector<int>lista(10);
	int nrobuscar;
	for(int i=0;i<lista.size();i++){
		lista[i]=rand()%20;
		cout<<lista[i]<<"   ";
	}
	cout<<endl<<endl<<"ingrese numero a buscar"<<endl;
	cin>>nrobuscar;
	
	int indice;
	int pos=buscarpos(lista,0,nrobuscar);
	
	if(pos==-1){
		cout<<"el numero no se encuentra en la lista"<<endl;
	}else{
		cout<<"el numero se encuentra en la posicion: "<<pos+1;
	}
	return 0;
}
int buscarpos(vector<int>lista, int indice, int nrobuscar){
	
	
	if(indice==lista.size()){
		return -1; ///No encontre el numero ya que el indice recorrio todos los lugares
	}
	if(lista[indice]==nrobuscar){
		return indice;
	}else{
		return buscarpos(lista,indice+1,nrobuscar);
	}
	
	
	
}
