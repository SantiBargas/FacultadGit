#include <iostream>
using namespace std;

int factorial(int x);

int main() {
	int x;
	cout<<"ingrese numero del que quiere saber el factorial"<<endl<<endl;
	cin>>x;
	
	cout<<"el factorial es: "<<factorial(x);
	return 0;
}

int factorial(int x){
	
	if(x==0){
		return 1;
	}else{
		return x*factorial(x-1);
	}
}
