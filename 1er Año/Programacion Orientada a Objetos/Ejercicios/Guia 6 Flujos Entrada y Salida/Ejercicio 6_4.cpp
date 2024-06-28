#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
	
	for(int i=0;i<78;i++) { 
		
		fstream f("design"+to_string(i+1)+".wds",ios::binary|ios::out|ios::in); //pongo in para no perder lo q tenia
		
		char aux[]= "msw10";
		
		f.seekp(178); //me voy al byte 178
		f.write(aux,sizeof(aux));
		
		f.seekp(239);
		int x=2003; //pongo 2003 en una variable pq no puedo hacer &2003
		f.write(reinterpret_cast<char*>(&x),sizeof(x));
	}
	
	
	return 0;
}

