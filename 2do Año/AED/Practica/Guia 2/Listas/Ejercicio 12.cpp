#include <iostream>
#include <list>
using namespace std;
/*12) Compacta. Escribir una funci´on void compacta(list<int> &L,list<int> &S) que toma un
elemento entero n de S y, si es positivo, saca n elementos de L y los reemplaza por su suma. Esto
ocurre con todos los elementos de S hasta que se acaben, o bien se acaben los elementos de L.*/

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}



void compacta(list<int> &L,list<int> &S){
	list<int>::iterator itl=L.begin();
	list<int>::iterator its=S.begin();
	list<int>::iterator itt=L.begin();
	
	int sum1=0;
	int c=0; //contador
	
	while(its!=S.end() and itl !=L.end()){
		
		if(*its > 0){ //tiene q ser positivo
			c=0;
			sum1=0;
			while(itl!=L.end() and c<*its){
				
				sum1 += *itl;
				++itl;
				++c; 
			}
			*itt=sum1;
			++itt;
			itt=L.erase(itt,itl);
			itl = itt;
		}
		++its;
		
		
	}
	
	
	
}
	
	
int main() {

	list<int>L={1,2,3,4,5,6};
	list<int>S={2,2,5,3,2,1,4};

	compacta(L,S);
	show_list(L);
	
	return 0;
}

