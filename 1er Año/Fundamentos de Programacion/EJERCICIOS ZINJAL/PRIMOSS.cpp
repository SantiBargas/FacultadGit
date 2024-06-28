#include <iostream>
using namespace std;

int main() {
	///INGRESAR UN NUMERO Y DETERMINAR SI ES PRIMO
	
	int N;
	cin>>N;
	
	
	int	contador=0;
	for( int i=2; i<N; i++){
		if( N%i==0){
			contador++;
			break;
		}
	}
	
	if (contador==0){
		cout<<"el numero ingresado es primo"<<endl;
	}
	else{
		cout<<"el numero ingresado no es primo"<<endl;
	}


	
	
	return 0;
}

