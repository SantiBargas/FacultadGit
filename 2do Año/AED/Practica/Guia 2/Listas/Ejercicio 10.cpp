#include <iostream>
#include <list>
using namespace std;
/*10) Problema de Josephus. Un grupo de soldados se haya rodeado por una fuerza enemiga. No hay
	esperanzas de victoria si no llegan refuerzos y existe solamente un caballo disponible para el
	escape. Los soldados se ponen de acuerdo en un pacto para determinar cu´al de ellos debe escapar y
	solicitar ayuda. Forman un c´irculo y se escoge un n´umero n al azar. Igualmente se escoge el
	nombre de un soldado. Comenzando por el soldado cuyo nombre se ha seleccionado, comienzan a
	contar en la direcci´on del reloj alrededor del c´irculo. Cuando la cuenta alcanza el valor n, este
	soldado es retirado del c´irculo y la cuenta comienza de nuevo, con el soldado siguiente. El proceso
	contin´ua de tal manera que cada vez que se llega al valor de n se retira un soldado. El ´ultimo
	soldado que queda es el que debe tomar el caballo y escapar. Entonces, dados un n´umero n y una
	lista de nombres, que es el ordenamiento en el sentido de las agujas del reloj de los soldados en el
	c´irculo (comenzando por aqu´el a partir del cual se inicia la cuenta), escribir un procedimiento
	list<string> josephus(list<string>& nombres, int n) que retorna una lista con los
	nombres de los soldados en el orden que han de ser eliminados y en ´ultimo lugar el nombre del
	soldado que escapa.*/


void show_list(list<string>& L) {
	cout<<"(";
	for(list<string>::iterator it=L.begin();it!=L.end();it++) {
		cout<<*it<<",";
	}
	cout<<")";
}
list<string> josephus(list<string>& nombres, int n) {
	
	list<string>::iterator itini = nombres.begin();
	list<string> borrados{};
	
	
	
	
	while(!nombres.empty()){
		for(int i=0;i<n;i++){
			itini++;
			if(itini==nombres.end()){
				itini=nombres.begin();
			}
		}
		borrados.push_back(*itini);
		itini=nombres.erase(itini);
	}
	
	
	
	return borrados;
}
int main() {

	
	list<string>nombres{"Bargas","Molas","Abud","Marinio","Solari","Macus","Talavera","Sala","Martinez"};
	
	list<string>L = josephus(nombres,10);
	
	show_list(L);

	
	return 0;
}

