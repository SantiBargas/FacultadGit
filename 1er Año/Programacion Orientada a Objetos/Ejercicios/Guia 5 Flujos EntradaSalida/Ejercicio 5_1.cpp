#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	ifstream archi_in("Ejercicio 5_1.txt");
	
	vector<string>v;
	
	string s;
	
	while(getline(archi_in,s)){
		v.push_back(s);
	}
	
	archi_in.close();
	
	cout<<"HAY "<<v.size()<<" PALABRAS"<<endl;
	
	sort(v.begin(),v.end());
	
	ofstream archi_out("Ejercicio 5_1.txt",ios::trunc);  ///ios::trunc equivale a borrar las palabras viejas y poner las nuevas
	for(string s : v){
		archi_out << s << endl;
	}
	return 0;
}

