#include <iostream>
#include <vector>
#include <tuple>
#include <matrix>
using namespace std;

int recur(vector<int>V ,int x, int inicio);
tuple<int,int>recur(matrix<int>M ,int x, int fila, int col);

int main() {
	vector<int>V(5);
	matrix<int>M(3,3);
	
	for(int i=0;i<V.size();i++){
		V[i]=rand()%10;
		cout<<V[i]<<"   ";
	}cout<<endl<<endl;
	
	int leer;
	cout<<"ingrese numero a saber pos"<<endl;
	cin>>leer;
	
	int pos=recur(V,leer,0);
	if(pos==-1){
		cout<<"no se encuentra el numero";
	}else{
		cout<<"el numero esta en la posicion: "<<pos+1<<endl<<endl;
	}
	
	for(int i=0;i<M.size(0);i++){
		for(int j=0;j<M.size(1);j++){
			M[i][j]=rand()%10;
			cout<<M[i][j]<<"     ";
		}
		cout<<endl;
	}
	
	int buscar,f,c;
	cout<<"ingrese numero a saber pos"<<endl;
	cin>>buscar;
	
	tie(f,c)=recur(M,buscar,0,0);
	if(f==-1){
		cout<<"no se encontro";
	}else{
		cout<<"el numero esta en la fila: "<<f+1<<endl<<" columna: "<<c+1;
	}
	
	
	return 0;
}
int recur(vector<int>V ,int x, int inicio){
	
	if(V[inicio]==x){
		return inicio;
	}else{
		return recur(V,x,inicio+1);
	}
	return -1;
	
}
tuple<int,int> recur(matrix<int>M ,int x, int fila, int col){
	
	
	if(fila==M.size(1)){
		return make_tuple(-1,-1);  ///La matriz llego al final, no se encontro numero
	}
	
	if(col==M.size(0)){
		return recur(M,x,fila+1,0); ///La columna llego al maximo,buscamos en la siguiente fila
	}
	
	if(M[fila][col]==x){
		return make_tuple(fila,col); ///Coincide se retorna los indices
	}else{
		return recur(M,x,fila,col+1); ///No coincide se busca en la sig posicion
	}
	
	
	
	
}
