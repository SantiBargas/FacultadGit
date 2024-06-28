#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
/* Programar una clase Animal que tenga un método desplazarse() y otro método tipo(). Programe las
	clases Mamifero, Ave y Pez, que son hijas de la clase Animal. Los atributos de las clases son el tipo y
	la especie del animal, cuyos valores deben ser pasados al constructor de la clase base. Además deberá
	sobreescribir los métodos desplazarse() y tipo(), de tal manera que el primer método devuelve una
	cadena de texto indicando el tipo de desplazamiento según el tipo: “camina” para el tipo “mamífero”,
	“vuela” para el tipo “ave” y “nada” para el tipo “pez”. Escriba un programa cliente que permita modelar un
	Parque y almacene la información de los animales en un único arreglo de 30 elementos y luego emita
	un listado de los mismos describiendo el tipo y la forma de desplazamiento de cada animal. Finalmente
	responda: ¿Hay entre las clases algún método virtual puro?¿Por qué?
*/

class Animal{
protected:
	string especie_animal;
	string tipo_animal;
public:
	Animal(string esp_ani, string tip_ani):especie_animal(esp_ani),tipo_animal(tip_ani){}
	string verespecie(){return especie_animal;}
	string vertipo(){return tipo_animal;}
	
	virtual string desplazarse()=0;
	virtual string tipo()=0;
	~Animal(){};
};

class Mamifero:public Animal{
public:
	Mamifero(string esp, string tip):Animal(esp,tip){}; //constructor de la clase base
	string desplazarse()override{
		stringstream sss;
		sss<<"el animal "<<especie_animal<<" camina"<<endl;
		return sss.str();
	}
	string tipo()override{return "Mamifero";}
};

class Ave:public Animal{
public:
	Ave(string esp, string tip):Animal(esp,tip){} //constructor de la clase base
	string desplazarse()override{
		stringstream sss;
		sss<<"el animal "<<especie_animal<<" vuela"<<endl;
		return sss.str();
	}
	string tipo()override{return "Ave";}
};

class Pez:public Animal{
public:	
	Pez(string esp, string tip):Animal(esp,tip){} //constructor de la clase base
	string desplazarse()override{
		stringstream sss;
		sss<<"el animal "<<especie_animal<<" nada"<<endl;
		return sss.str();
	}
	string tipo()override{return "";}
};

int main() {
	
	vector<Animal*> Parque;
	
	int i,n;
	//creo 30 animales de tipos al azar
	for(int i=0;i<30;i++){
		n=rand()%3;
		if(n==0){
			Parque.push_back(new Mamifero("Mamifero","Pinguino")); ///new =nueva variable de mamifero
		}else{
			if(n==1){
				Parque.push_back(new Ave("Ave","Aguila"));
			}else{
				Parque.push_back(new Pez("Pez","Dorado"));
			}
		}
	}
	
	for(int i=0;i<30;i++){
		cout<<"TIPO: "<<Parque[i]->vertipo()<<" como se desplaza? "<<Parque[i]->desplazarse()<<endl;
	}
	
	return 0;
}

