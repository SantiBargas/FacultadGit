#include <iostream>
#include <stack>
#include <queue>
using namespace std;
/*6) PancakeSort. Dada una pila de n´umeros S, implementar la funci´on
	void pancake_sort(stack<int>&S) la cual ordena la pila solo haciendo operaciones en las cuales
	se invierte un rango contiguo de elementos en el tope de la pila.*/


void show_stack(stack<int>S){
	while(!S.empty()){
		cout<<S.top()<<endl;
		S.pop();
	}
}

int busca_mayor(stack<int>S,int n){	//int n es hasta q elemento buscar	
	int mayor=S.top();
	int imayor=0;

	for(int i=0;i<n;i++){
		if(mayor<S.top()){
			mayor = S.top();
			imayor = i;
			
		}
		S.pop();
	}
	return imayor;
	
	
}
void invertir(stack<int>&S,int n){
	
	//[1,2,3] == [3,1,2] esto tiene q ghacer el algoritmo
	
	queue<int>Q;           
	
	for(int i=0;i<n;++i){
		Q.push(S.top());
		S.pop();
	}				//hasta aca estamos en Q=[1,2] y S=[3]
	
	for(int i=0;i<n;++i){
		S.push(Q.front());
		Q.pop();        // ahi nos queda S=[2,1,3]
	}
	
}
	
void pancake_sort(stack<int>&S){ ///detectar cual es el mayor
								///invertir toda la pila en el mayor	
								///invertir toda la pila desordenada

	int N= S.size();
	for(int i=0;i<N;i++) { 
		///elementos por ordenar
		int n=N-i;
		///detectar cual es el mayor
		int iMax=busca_mayor(S,n);
		
		///invertir el rango desde el tope hasta el mayor
		invertir(S,iMax+1);
		
		///invertir toda la pila desordenada
		invertir(S,n);  //segun en q iteracion voy, se cuantos elementos hay ordenados
		
		
	}
	
}
int main() {
	
	stack<int> P;	P.push(6);P.push(3);P.push(1);P.push(4);P.push(5);P.push(2);
	pancake_sort(P);
	show_stack(P);
	return 0;
}







