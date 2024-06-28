#include <iostream>
#include <list>
using namespace std;
///*Invierte. Escribir una funci´on void invert(list<int> &L), que invierte el orden de la lista L.
///	Este algoritmo debe implementarse in place y debe ser O(n). Restricci´on: no utilizar el m´etodo
///	size().

//O(n) significa q puede tener un solo loop

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

void invert(list<int>& L){
	
	list<int>::iterator itB= L.begin(); //iterador del principio
	list<int>::iterator itE= L.end(); 	//iterador del final
	--itE;
	
	list<int>::iterator itComp=itB;
	++itComp; //para que este un iterador adelante de itB

	
	//{1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9}
	while(itB!=itE){
		swap(*itB,*itE); //intercambio de lugar los numeros 
		if(itComp==itE)break; 	//Si el iterador de comparacion es igual al del final se corta el swap para no seguir cambiando los numeros
		
		++itB; ///avanza uno
		--itE; ///retrocede el otro
		++itComp;
	}
	
	
	
}

int main() {
	list<int>L1{1,2,3,4,5};
	
	invert(L1);
	show_list(L1);
	return 0;
}

