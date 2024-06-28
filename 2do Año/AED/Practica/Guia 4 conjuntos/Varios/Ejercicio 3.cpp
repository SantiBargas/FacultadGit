#include <iostream>
#include <btree.hpp>
using namespace aed;
using namespace std;
/*3) eliminaABB. Programe una funci´on void elimina_ABB(btree<int> &BT, int v) que elimina,
si existe, el valor v del ´arbol binario BT de tal manera de preservar el ordenamiento del mismo*/
btree<int>::iterator findABB(btree<int>&BT,int v){
	btree<int>::iterator it = BT.begin();
	while(true){
		if(it==BT.end()){
			return it;
		}
		if(v<*it){
			it = it.left();
		}else if(v>*it){
			it = it.right();
		}else{
			return it;
		}
	}
}
void elimina_ABB(btree<int> &BT, int v){
	btree<int>::iterator pos = findABB(BT,v);
	
	///Si el valor v no esta en el arbol, no hace nada
	///Si el valor v esta en el arbol, dependera de la cantidad de hijos que tenga

	///Si tiene un solo hijo "subir todo el subarbol de dicho hijo a la posicion del padre
	///Si tiene dos hijos se busca un valor cualquiera de las ramas para eliminarlo y reemplazar por la posicion del valor v
	///Tiene que ser el minimo valor de la rama derecha, o el maximo valor de la rama izquierda
	
	if(pos!=BT.end()){
		if(pos.left()==BT.end() && pos.right() ==BT.end()){///No tiene hijos
			BT.erase(pos);
			
		}else if(pos.right() ==BT.end()){ ///Solo tiene hijo izquierdo
			
			btree<int>temp;
			temp.splice(temp.begin(),pos.left());
			pos = BT.erase(pos);
			
			BT.splice(pos,temp.begin());
			
		}
		else if(pos.left() ==BT.end()){ ///Solo tiene hijo izquierdo
			
			btree<int>temp;
			
			temp.splice(temp.begin(),pos.right());
			pos = BT.erase(pos);
			temp.splice(
			BT.splice(pos,temp.begin());
			
		}else{ ///Si tiene ambos hijos, elegir una estrategia ("minimo de los maximos")
			
			btree<int>::iterator minR=pos.right();
			while(minR.left() != BT.end()){
				minR=minR.left();
			}
			int valorTemp = *minR;
			BT.erase(minR);
			*pos=valorTemp;
		}
	}
}

int main() {
	
	return 0;
}







