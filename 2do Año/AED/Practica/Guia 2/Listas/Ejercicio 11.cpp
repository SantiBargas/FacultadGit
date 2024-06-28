#include <iostream>
#include <list>
#include <cstring>
using namespace std;
/*Palindromo. Escribir un predicado bool is_palindromo(char* S), que reciba como par´ametro
	una cadena de texto S y determine si ´esta es un pal´indromo, ignorando los espacios entre palabras.
	Un pal´indromo es una secuencia de caracteres que se lee igual hacia adelante que hacia atr´as, por
	ejemplo: alli si maria avisa y asi va a ir a mi silla. Recordar que un string puede indexarse como
	un vector. Con el fin de utilizar la estructura <list>, primero deben pasarse los elementos del
	string a una lista y solo utilizar ´esta en el algoritmo.*/

bool is_palindromo(char* S){
	
	list<char> L;
	
	int f= strlen(S);
	
	for(int i;i<f;i++){ //strlen devuelve el valor de la longitud
		if(S[i]!=' '){
			L.push_back(S[i]);
		}
	}
	list<char>::iterator it1=L.begin();
	list<char>::iterator it2=L.end();
	list<char>::iterator itt=L.end();
	--it2;
	
	while(it1!=it2 && it1!=itt){
		--itt;
		if(*it1!=*it2) return false;
		++it1;
		--it2;
	}

	return true;
}


int main() {
	
	if(is_palindromo( (char*)"ardar")){
		cout<<"es palindromo";
	}else{
		cout<<"no es palindromo";
	}
	
	return 0;
}

