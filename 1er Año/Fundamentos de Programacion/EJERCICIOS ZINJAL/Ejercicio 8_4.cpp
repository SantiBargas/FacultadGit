#include <iostream>
using namespace std;


int mayor(int a, int b, int c){
	int ElMayor=0;
	if (a>b and a>c){
		ElMayor= a;}
	else{
		if(b>a and b>c){
			ElMayor = b;}
		else{
			ElMayor=c;
		}
	}
	return ElMayor;
}
int main() {
	int x,y,z;
	cout<<"ingrese 3 valores"<<endl;
	cin>>x>>y>>z;
	
	cout<<"el mayor es "<<mayor(x,y,z);
	return 0;
}

