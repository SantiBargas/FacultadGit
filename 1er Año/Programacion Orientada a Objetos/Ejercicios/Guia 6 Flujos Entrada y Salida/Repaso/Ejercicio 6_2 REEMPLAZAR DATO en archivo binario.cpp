#include <iostream>
#include <fstream>
using namespace std;

struct Par{
	int x;
	float y;
};

int main() {
	
	fstream archi("Ejercicio 6_1.dat",ios::binary|ios::in|ios::out);
	
	Par b;int pos;
	cout<<"ingrese un Par de un entero y un flotante"<<endl;
	cin>>b.x>>b.y;
	cout<<"ingrese la posicion que desea sobreescribir"<<endl;
	cin>>pos;
	
	archi.seekp(pos*sizeof(Par));
	archi.write(reinterpret_cast<char*>(&b),sizeof(b));
	
	archi.seekg(0);
	for(int i=0;i<200;i++) { 
		archi.read(reinterpret_cast<char*>(&b),sizeof(b));
		cout<<"Par: "<<i<<" : "<<b.x<<" "<<b.y<<endl;
	}
	return 0;
}

