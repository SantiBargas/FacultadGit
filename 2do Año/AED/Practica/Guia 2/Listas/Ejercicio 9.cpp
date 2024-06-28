#include <iostream>
using namespace std;
/*9) Camale´on. Implemente los predicados bool menor(int x, int y), bool mayor(int x, int y)
	y bool dist(int x, int y) que retornen verdadero si x es menor, mayor o menor en valor
	absoluto que y respectivamente. Luego implemente una funci´on
	ordena(list<int> &L, bool (*f)(int,int)) que ordene la lista L dependiendo de la funci´on
	f pasada c´omo par´ametro.*/

bool menor(int x, int y){
	
	
	return (x<y);
}
	
bool mayor(int x, int y){
	
	return (x>y);
	
}
	
bool dist(int x, int y){
	
	
	return (abs(x) < abs(y));
}
	
void ordena(list<int> &L, bool (*f)(int,int)){
	
	list<int>::iterator itB= L.begin();
	list<int>::iterator itE= L.end();
	--itE; //apunta al ultimo num de la lista, no al final
	
	for(;itB != itE; itB++){
		list<int>::iterator itB_Next= itB;
		++itB_Next;
		for(; itB_Next != L.end(); ++itB_Next){
			
			if(f(*itB_Next;*itB)){
				swap (*itB,*itB_Next);
			}
		}
	}
}
	
	
int main() {
	
	return 0;
}

