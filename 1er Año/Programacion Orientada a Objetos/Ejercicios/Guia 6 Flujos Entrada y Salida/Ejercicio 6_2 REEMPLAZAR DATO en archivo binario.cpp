#include <iostream>
#include <fstream>
using namespace std;
struct Par{
	int x;
	float y;
};
int main() {
	
	Par p;
	int posicion;
	cout<<"Ingrese par para reemplazar"<<endl;
	cin>>p.x>>p.y;
	cout<<"En que posicion desea reemplazarlo?"<<endl;
	cin>>posicion;
	
	fstream archi("Ejercicio 6_1.dat",ios::binary|ios::in|ios::out); //fstream se banca leer y escribir
	//ios::in pq voy a leer, ios::out pq voy a escribir, solo cuando es fstream
	//el in me permite q no se borren los datos q ya estaban, como pasaria con el trunc
	
	archi.seekp(posicion*sizeof(Par)); //la posicion que le paso tiene que ser en bytes, si pongo posicion 5, no va a ir a ese par, iria al 5 byte
	///posicion*sizeof(Par)
	///posicion  * 8 (4bytes del int + 4bytes del float)
	///Una vez parado en la posicion escribo el nuevo par

	archi.write(reinterpret_cast<char*>(&p),sizeof(p));
	
	archi.seekg(0); //vuelvo al comienzo del archivo
	for(int i=0;i<200;i++) { 
		archi.read(reinterpret_cast<char*>(&p),sizeof(p));
		cout<<"Par "<<i<<": "<<p.x<<", "<<p.y<<endl;
	}
	
	return 0;
}

