#include <iostream>
#include <btree.hpp>
#include <map>
using namespace aed;
using namespace std;

/*9) Huffman. Escribir una funci´on btree<char> make_huffman_tree(map<char,float> &A) que
dados un alfabeto A donde las clave son los caracteres a codificar, y los con valores las
probabilidades de ocurrencia de cada uno, construya y retorna el ´arbol de la codificaci´on de
Huffman.*/

struct huffman_tree{
	btree<char>T;
	float p;
};

btree<char> make_huffman_tree(map<char,float> &A){
	
	///lista de arboles d huffman
	list<huffman_tree> bosque;
	
	///Paso 1: crear los arboles iniciales
	map<char,float>::iterator itA=A.begin();
	for(int i=0;i<A.size();i++){
		
		///Inserta un arbol de huffman vacio
		list<huffman_tree>::iterator it = bosque.insert(bosque.begin(),huffman_tree());
		
		///agregar caracter a la raiz del arbol
		it->T.insert(it->T.begin() , itA->first);
		///Asocia la probabilidad al arbol
		it->p = itA->second;
		
		///Avanza el itA
		++itA;
	}
	
	///Paso 2: construccion de los arboles por metodo de huffman
	btree<char>temp;
	
	while(bosque.size() > 1){
		///Inserta un valor de control en el arbol temporal
		temp.insert(temp.begin(),'.');
		///Probabilidad asociada
		float temp_p = 0.0;
		
		///Construicr el arbol binario con los arboles de huffman_tree
		///de menor probabilidad asociada
		
		for(int j=0;j<2;j++){
			///Buscar el arbol de huffman de menor probabilidad en el bosque
			list<huffman_tree>::iterator it = bosque.begin(), itMin=it;
			
			while(it!=bosque.end()){
				if(it->p < itMin->p){
					itMin=it;
				}
				++it;
			}
			
			///Asignar el arbol de probabilidad minima encontrada 
			///al hijo correspondiente
			///Si j==0, va por el hijo izquierdo
			///Si j== 1 va por el hijo derecho
			btree<char>::iterator nodo=temp.begin();
			
			if(j==0){///hijo izq
				nodo=nodo.left();
			}else{///hijo derecho
				nodo=nodo.right();
			}
			
			///Traslada todo el arbol de probabilidad minima al nodo correspondiente
			temp.splice(nodo,itMin->T.begin());
			
			///Acumular la probabilidad minima
			temp_p+=itMin->p;
			
			///Elimina el arbol de huffmand de probabilidad minima
			bosque.erase(itMin);
		}
		
		///Insertar el nuevo arbol acumulado en el bosque
		list<huffman_tree>::iterator it = bosque.insert(bosque.begin(),huffman_tree());
		
		///Trasladar el arbol temporal al nuevo arbol insertado
		it->T.splice(it->T.begin(),temp.begin());
		
		///Asocia la posibilidad acumulada al nuevo arbol insertado
		it->p=temp_p;
	}
	
	///Retorna arbol de huffman
	
	return bosque.begin()->T;
	
}

int main() {
	
	map<char,float> A ={
		{'P',0.05},
		{'A',0.2},
		{'F',0.1},
		{'R',0.05},
		{'I',0.2},
		{'T',0.15},
		{'Q',0.15},
		{'S',0.1},
		
	};
	
	btree<char> T = make_huffman_tree(A);
	
	
	return 0;
}







