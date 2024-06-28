#include <iostream>
#include <list>
using namespace std;
/*9) Camale´on. Implemente los predicados bool menor(int x, int y), bool mayor(int x, int y)
y bool dist(int x, int y) que retornen verdadero si x es menor, mayor o menor en valor
absoluto que y respectivamente. Luego implemente una funci´on
ordena(list<int> &L, bool (*f)(int,int)) que ordene la lista L dependiendo de la funci´on
f pasada c´omo par´ametro.*/
void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")"<<endl;
}
bool menor(int x, int y){
	return (x<y);
} 
bool mayor(int x, int y){
	return (x>y);
}
	
bool dist(int x, int y){
	return (abs(x) < abs(y));
}

void ordena(list<int> &L, bool (*f)(int,int)){ //F es un puntero a la funcion real
	list<int> L2;
	//Lista auxiliar L2
	
	while(!L.empty()){
		//tomar el sig elemento de L a ubicar,
		list<int>::iterator it=L.begin();
		list<int>::iterator itNext=L.begin();
		
		while (it!=L.end()){
			if(f(*it,*itNext)){
				itNext=it; //encontrar un nuevo minimo 
			}
			it++;
		}
		L2.push_back(*itNext);
		L.erase(itNext); 
	}
	L=L2;
}
	
int main() {
	
	list<int>L2= {1,2,-3,5,2,1,2,5,-7,9,21};
	
	ordena(L2,menor);
	show_list(L2);
	
	ordena(L2,mayor);
	show_list(L2);
	
	ordena(L2,dist);
	show_list(L2);
	
	return 0;
}

