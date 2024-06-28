#include <iostream>
#include <cmath>
using namespace std;

bool es_primo(int N){
	
	bool es=true;
	for( int i=2; i<=sqrt(N); i++){
		if( N%i==0){
			return false;
			break;
		}
	}
	return true;
}
	
	
	
	int main() {
		int N=2;
		
		do{
			if(es_primo(N)){
				cout<<N<<endl;}	
			N++;
		}while(N<1000);
		return 0;
		


	
	return 0;
}

