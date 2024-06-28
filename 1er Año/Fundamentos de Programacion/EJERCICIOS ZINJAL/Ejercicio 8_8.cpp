#include <iostream>
using namespace std;

int pot(int base, int exp){
	if (exp==0) 
		return 1;
	else return base * pot(base,exp-1);
}

int main() {
	int base,exp;
	cout<<"ingrese el numero que desea obtener de potencia"<<endl;
	cin>>base;
	cout<<"ingrese que potencia desea obtener"<<endl;
	cin>>exp;
	
	cout<<pot(base,exp);
	return 0;
}

