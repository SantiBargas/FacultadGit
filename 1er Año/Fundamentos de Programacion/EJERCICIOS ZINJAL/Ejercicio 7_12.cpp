#include <iostream>
using namespace std;

int main() {
	///INGRESAR UN NUMERO Y DETERMINAR SI ES PRIMO
	
	
	cout<<"2"<<endl; ///escribimos el dos pq ya sabemos q es primo		int N=3; ///arrancamos a contar desde el 3
	
	do{
		int	contador=0;
		for( int i=2; i<N; i++){
			if( N%i==0){
				contador++;
				break;
			}
		}
		
		if (contador==0){
			cout<<N<<endl;
		}
		
		N+=2;
		
	}while(N<=1000);
	
	return 0;
}

