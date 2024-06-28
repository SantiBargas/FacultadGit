#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
	
	
	vector<int> v(20);
	for(size_t i=0;i<v.size();i++){
		v[i]= rand()%100;
	}
	sort(v.begin(),v.end());
	
	ofstream archi("Ejercicio 6_3.dat",ios::binary);
	for(size_t i=0;i<v.size();i++){
		archi.write(reinterpret_cast<char*>(&v),sizeof(v));
	}
	
	for(size_t i=0;i<v.size();i++)cout<<v[i]<<"  ";
	return 0;
}

