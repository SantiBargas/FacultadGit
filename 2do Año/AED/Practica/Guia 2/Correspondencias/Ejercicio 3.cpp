#include <iostream>
#include <map>
using namespace std;
/*3) InverseMaps. Dos correspondencias M1 y M2 son inversas una de la otra si tienen el mismo n´umero
de asignaciones y para cada par de asignaci´on x->y en M1 existe el par y->x en M2. Escribir un
predicado bool areinverse(map<int,int> &M1, map<int,int> &M2); que determina si las
correspondencias M1 y M2 son inversas.*/

bool areinverse(map<int,int> &M1, map<int,int> &M2){
	
	if(M1.size() != M2.size()) return false;
	
	map<int,int>::iterator itM1= M1.begin();
	
	while(itM1!=M1.end()){
		
		//M1 x -> y
		//M2 y -> x  para que sea inversa
		
		map<int,int>::iterator it = M2.find(itM1->second); //busca el valor y de M2
		
		if(it==M2.end()) return false; //Caso del q valor q esta en M1 sea una llave de M2

		if(it->second !=itM1->first) return false;
		++itM1;
		
	}
	return true;
}


int main() {
	
	map<int,int> M1={{1,2},{2,3},{3,4}};
	map<int,int>M2={{2,1},{3,2},{4,3}};
	
	if(areinverse(M1,M2)){
		cout<<"es inversa";
	}else{cout<<"no es iversa";}
	
	return 0;
}







