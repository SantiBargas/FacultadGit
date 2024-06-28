#include <iostream>
#include <list>
using namespace std;
/*ReemplazaSecuencia. Dada una lista de enteros L y dos listas SEQ y REEMP, posiblemente de
	distintas longitudes, escribir una funci´on void reemplaza(list<int> &L, list<int>& SEQ,
   list<int> &REEMP), que busca todas las secuencias de SEQ en L y las reemplaza por REEMP. Por
	ejemplo, si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5), SEQ=(4,5,1) y REEMP=(9,7,3), entonces
	despu´es de llamar a reemplaza(L,SEQ,REEMP), debe quedar
	L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). Para implementar este algoritmo primero buscar desde el
	principio la secuencia SEQ, al encontrarla, reemplazar por REEMP, luego seguir buscando a partir
	del siguiente elemento al ´ultimo de REEMP.*/

void show_list(list<int>& L) {
	cout<<"(";
	for(list<int>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}

void reemplaza(list<int>&L ,list<int> &SEQ ,list<int> &REEMP){
	list<int>::iterator it=L.begin();
	list<int>::iterator itSEQ=SEQ.begin();
	
	while(it!=L.end()){
		
		list<int>::iterator itini= it;
		
		while(itSEQ !=SEQ.end() && it!=L.end()){
			if(*it==*itSEQ){ ///comparo y si son el mismo dato voy avanzando para obtener la cadena completa
				itSEQ++;
				it++;	
			}else{
				///si el elemento de la lista no coincide con el de la secuencia incrementamos el iterador
				it++;
				itSEQ=SEQ.begin();
				itini = it;
				//refrescamos la lista de busqyeda
			}
		}
		if(itSEQ==SEQ.end()){ //hacemos el reemplazo solo si el iterador seq llego al final, si el while sale pq termino la lista no se hace reemplazo
			
			it=L.erase(itini,it);///eliminamos el rango q coincidio para poder reemplazarlo
			
			for(int x:REEMP){
				it=L.insert(it,x);
				it++;
			}
			itSEQ = SEQ.begin(); ///volvemos a buscar desde el principio de la secuencia
		}
		
		
	}
	
}
int main() {
	list<int>L={1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};
	list<int>SEQ={4,5,1};
	list<int>REEMP={9,7,3};
	
	reemplaza(L,SEQ,REEMP);
	
	show_list(L);
	return 0;
}

