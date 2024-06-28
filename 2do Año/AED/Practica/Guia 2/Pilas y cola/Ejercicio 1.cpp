#include <iostream>
#include <stack>
using namespace std;


/*1) Varios. Utilizando las operaciones del contenedor stack<> de STL, construir una serie de
procedimientos que realicen cada una de las actividades siguientes en una pila:
a) Asignar i al segundo elemento desde la parte superior de la pila, dejando la pila sin sus dos
elementos de la parte superior.
b) Asignar i al segundo elemento desde la parte superior de la pila, sin modificarla
c) Dado un entero n, asignar i al elemento n-´esimo desde la parte superior de la pila, dejando la
pila sin sus n elementos superiores.
d) Asignar i al elemento del fondo de la pila, dejando la pila vac´ia.
e) Asignar i al elemento del fondo de la pila, dejando la pila sin modificar.*/



int main() {	
	stack<int> P;	P.push(1);P.push(2);P.push(3);P.push(4);P.push(5);P.push(6);
	stack<int> R;	R.push(1);R.push(2);R.push(3);R.push(4);R.push(5);R.push(6);
	stack<int> Q;	Q.push(1);Q.push(2);Q.push(3);Q.push(4);Q.push(5);Q.push(6);
	stack<int> T;	T.push(1);T.push(2);T.push(3);T.push(4);T.push(5);T.push(6);
	stack<int> F;	F.push(1);F.push(2);F.push(3);F.push(4);F.push(5);F.push(6);
	
	
	
	
	///A)
	int i=10;
	P.pop();
	P.pop();
	P.push(i);
	
	while (!P.empty()){
		cout<<P.top()<<endl;
		P.pop();
	}cout<<endl<<endl;
	
	///B)
	i=5;
	int aux1;
	aux1=R.top();
	R.pop();
	R.pop();
	R.push(i);
	R.push(aux1);
	
	while (!R.empty()){
		cout<<R.top()<<endl;
		R.pop();
	}cout<<endl<<endl;
	
	///C
	i=10;
	int n=3;
	if(Q.size() >= n ){
		for(int i=0;i<n;i++) {
			Q.pop();
		}
		Q.push(i);
	}
	
	while (!Q.empty()){
		cout<<Q.top()<<endl;
		Q.pop();
	}cout<<endl<<endl;
	
	///D
	while(!T.empty()){
		T.pop();
	}
	T.push(i);
	
	
	///E
	stack<int>Saux;
	
	while(!F.empty()){
		Saux.push(F.top()); // pasamos todos los elementos de F a la lista aux y queda invertida
		F.pop();
	}
	
	F.push(i);
	
	while(!Saux.empty()){
		F.push(Saux.top());
		Saux.pop();
	}
	
	
	
	return 0;
}

