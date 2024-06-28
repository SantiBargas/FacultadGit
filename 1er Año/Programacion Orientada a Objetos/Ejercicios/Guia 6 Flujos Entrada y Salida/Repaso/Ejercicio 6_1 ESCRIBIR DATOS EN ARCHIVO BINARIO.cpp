#include <iostream>
#include <fstream>
using namespace std;

struct Par{
	int x;
	float y;
};

int main() {
	
	ofstream archi("Ejercicio 6_1.dat",ios::binary);
	
	for(int i=0;i<200;i++) { 
		Par a;
		a.x=rand()%10;
		a.y=rand()%100/10.0;
		
		cout<<"Par: "<<i<<": "<<a.x<<" "<<a.y<<endl;
		
		archi.write(reinterpret_cast<char*>(&a),sizeof(a));
		
	}
	
	
	
	return 0;
}

