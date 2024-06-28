#include <iostream>
using namespace std;

int potencia(int x, int exp);

int main() {
	int x,exp;
	cout<<"ingrese numero"<<endl;
	cin>>x;
	cout<<"ingrese exponente"<<endl;
	cin>>exp;
	
	cout<<"el resultado es: "<<potencia(x,exp);
	
	return 0;
}
int potencia(int x, int exp){
	
	if(exp==1){
		return x;
	}else{
		return x*potencia(x,exp-1);
	}
}
