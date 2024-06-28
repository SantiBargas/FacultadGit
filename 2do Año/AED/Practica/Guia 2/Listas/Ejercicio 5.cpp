#include <iostream>
#include <list>
using namespace std;
/*Junta. Escribir una funci´on void junta(list<int> &L, int c) que, dada una lista L, agrupa de
	a c elementos, dejando su suma in place. Por ejemplo, si se le pasa como argumento la lista
	L=(1,3,2,4,5,2,2,3,5,7,4,3,2,2), despu´es de aplicar el algoritmo junta(L,3) debe quedar
	L=(6,11,10,14,4) (notar que se agrupan los ´ultimos elementos, pese a no completar los tres
	requeridos). El algoritmo debe tener un tiempo de ejecuci´on O(n).*/

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

void junta(list<int>&L, int c){
	
	auto itB= L.begin();
	
	list<int>LS;
	
	int sum=0;
	int cont=0;
	
	while(itB!=L.end()){
		
		sum+= *itB;
		itB=L.erase(itB); //Elimino el iterador y me queda apuntando al segundo elemento
		++cont;
		if(cont==c){ ///si el contador llega a c, hacemos un pushback en la list aux
			LS.push_back(sum);
			sum=0;
			cont=0;
		}
		
	}
	if(cont!=0){
		LS.push_back(sum);
	}
	L.swap(LS);
	
}

int main() {
	list<int>L={1,3,2,4,5,2,2,3,5,7,4,3,2,2};
	
	junta(L,3);
	show_list(L);
	return 0;
}

/*void junta(list<int> &L, int c){		list<int> LS;	list<int>::iterator itL1=L.begin();	list<int>::iterator itL2=L.end();		while( itL1 != L.end()){		int suma = 0;		for(int i=0;i<c;i++){			if(itL1 == itL2)				break;			suma+=(*itL1);			itL1++;		}		LS.push_back(suma);	}		L=LS;	}*/
	
