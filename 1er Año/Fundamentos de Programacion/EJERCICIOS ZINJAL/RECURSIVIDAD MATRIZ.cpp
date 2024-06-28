#include <iostream>
#include <matrix>
#include <tuple>
using namespace std;

tuple<int,int> buscarpos(matrix<int>lista,int nrobuscar,int indfila, int indcol);

int main() {
	matrix<int>lista(5,5);
	
	for(int i=0;i<lista.size(0);i++){
		for(int j=0;j<lista.size(1);j++){
			lista[i][j]=rand()%30;
			cout<<lista[i][j]<<"     ";
		}
		cout<<endl<<endl;
	}
	
	int nrobuscar,nrobuscar2,indfila,indcol;
	cout<<"ingrese numero a buscar"<<endl;
	cin>>nrobuscar;
	
	tie(indfila,indcol)=buscarpos(lista,nrobuscar,0,0);
	
	if(indfila==-1){
		cout<<"no se encontro el numero en la matriz"<<endl;
	}else{
		cout<<"el numero esta en la fila: "<<indfila+1<<" columna: "<<indcol+1;
	}
	
	cout<<"ingrese segundo numero a buscar"<<endl;
	cin>>nrobuscar2;
	tie(indfila,indcol)=buscarpos(lista,nrobuscar2,0,0);
	if(indfila==-1){
		cout<<"no se encontro el numero en la matriz"<<endl;
	}else{
		cout<<"el numero esta en la fila: "<<indfila+1<<" columna: "<<indcol+1;
	}
	return 0;
}
tuple<int,int> buscarpos(matrix<int>lista,int nrobuscar,int indfila, int indcol){
	
	if(indfila==lista.size(1)){
		return make_tuple(-1,-1); ///no se encontro en la matriz
	}
	if(indcol==lista.size(0)){
		return buscarpos(lista,nrobuscar,indfila+1,0);
	}
	if(lista[indfila][indcol]==nrobuscar){
		return make_tuple(indfila,indcol);
	}
	else{
		return buscarpos(lista,nrobuscar,indfila,indcol+1);
	}
	
}
