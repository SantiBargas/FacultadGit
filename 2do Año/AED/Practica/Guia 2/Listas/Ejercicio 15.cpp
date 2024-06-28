#include <iostream>
#include <list>
using namespace std;
/*MergeSort. Programar una funci´on void mergesort(list<int> &L) que reciba una lista L
	desordenada y la ordene en forma ascendente mediante la siguiente estrategia recursiva: Si la lista
	est´a vac´ia o tiene un s´olo elemento ya est´a ordenada. Sino se parte la lista en dos sublistas y se las
	ordena a cada una de forma recursiva. Luego se mezclan (fusionan) cada una de las sublistas ya
	ordenadas. Para partir una lista puede utilizarse el m´etodo de la clase list
	void list::splice (iterator position, list& x, iterator first, iterator last) el
	cual transfiere los elementos desde la lista x al contenedor que realiza la llamada en la posici´on
	position. Se sugiere utilizar la funci´on merge(..) implementada en el punto anterior.*/
void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

void mergesort(list<int> &L){
	
	
	if(L.empty()){
		cout<<"La lista esta vacia";return;
	}
	
	int cont=0;
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cont++;
	}
	if(cont==1){
		cout<<"la lista tiene 1 elemento, ya esta ordenada";return;
	}
	
	
}


int main() {
	list<int>L{4};
	
	
	mergesort(L);
	return 0;
}







