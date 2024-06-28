#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	vector<int> v(20);
	for(int &x: v) x = rand()%100;
	sort(v.begin(),v.end());
	
	ofstream archi("Ejercicio 6_3.dat",ios::binary);
	for(int x:v) archi.write(reinterpret_cast<char*>(&x),sizeof(x));
	
	for(int &i:v)cout<<i<<"  ";
	return 0;
}

