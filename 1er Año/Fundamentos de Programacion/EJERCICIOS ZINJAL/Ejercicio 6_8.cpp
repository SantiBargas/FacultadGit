#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a,b,c;
	cout<<"ingrese los valores de a,b,c"<<endl;	
	cin>>a;
	cin>>b;
	cin>>c;	
	 
	/// 1ro veo que lo de adentro de sqrt no sea negativo
	int aux= pow(b,2) = 4*a*c;
	
	if (aux>=0) {
		float x1 = (-b + sqrt(pow(b,2) - 4*a*c))/(2*a);
		cout<<" el primer resultado es "<<x1;
		float x2 = (-b + sqrt(pow(b,2) - 4*a*c))/(2*a);
		cout<<" el segundo resultado es "<<x2; }
	else{
		cout<<"raices imaginarias";
	}
		
	return 0;
}

