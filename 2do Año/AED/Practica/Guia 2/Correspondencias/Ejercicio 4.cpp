#include <iostream>
using namespace std;
/*4) mergeMap. Dadas dos correspondencias A y B, que asocian enteros con listas ordenadas de enteros,
	escribir una funci´on void merge_map(map<int, list<int>> &A, map<int, list<int>> &B,
	map<int, list<int>> &C) que devuelve en C una correspondencia que asigna al elemento x la
	fusi´on ordenada de las dos listas A[x] y B[x]. Si x no es clave de A, entonces C[x] debe ser B[x] y
	viceversa. Sugerencia: utilice la funci´on merge implementada en uno de los ejercicios anteriores*/

//x = {x1,x2,x3,x4...xn} //claves   A[x]
//y = {y1,y2,y3,y4...yk} //claves	B[y]
//w = {x1,x2,x3,x4...xn} union {y1,y2,y3,y4...yk} claves de c

// i=x2, i=y3 merge(A[i],B[i])

void merge_map(map<int, list<int>> &A, map<int, list<int>> &B,
			   map<int, list<int>> &C){
	
	map<int,list<int>>::iterator itA = A.begin();
	map<int,list<int>>::iterator itB = B.begin();
	
	map<int,list<int>>::iterator it;
	list<int>L;
	
	while(itA != A.end() || itB!=B.end()){
		
		if(itA !=A.end()){
			it = B.find(itA->first);
			if(it!=B.end()){
				merge(itA->second,it->second,L);
				C[itA->first] = L;
			}else{
				C[itA->first]=itA->second;
			}
			++itA;
		}
		
		
		if(itB!= B.end()){
			
			it = A.find(itB->first);
			
			if(it == A.end()){
				
				C[itB->first]= itB->second;
				
			}
			++itB;
		}
		
		
	}
	
}

int main() {
	
	return 0;
}







