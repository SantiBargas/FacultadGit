#include <iostream>
#include <fstream>
#include <list>
using namespace std;

list<string> ListarIncludes(string nom){
	fstream f(nom);
	list<string>l;
	if(!f.is_open()){
		cout << "no se encontro" <<endl ;
	}
	string s;
	while(getline(f,s)){
		size_t pos=s.find("#include",0);
		if(pos!=string::npos){
			s = s.substr(pos); //extraigo desde el 8 hacia adelante
			l.push_back(s);
		}
	}
	return l;
}

int main() {
	
	list<string>l;
	l=ListarIncludes("Include.txt");
	
	for(string x:l)cout<<x<<"  ";
	return 0;
}

