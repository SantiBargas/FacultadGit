#include <iostream>
using namespace std;
class Jugador{
protected:
	string m_nombre;
public:
	Jugador(string nombre):m_nombre(nombre){}
	int virtual Jugar()=0;
	string VerNombre(){return m_nombre;}
};

class JugadorIA:public Jugador{
public:
	JugadorIA(string nombre):Jugador("HAL 9000"){}
	int Jugar()override{
		int jugada=1+rand()%3;
		return jugada;
	}
	string VerNombre(){return m_nombre;}
};

class JugadorHumano:public Jugador{
public:
	JugadorHumano(string nombre):Jugador(nombre){}
	int Jugar()override{
		int jugada;
		cout<<"ingrese jugada,1=piedra 2=papel 3 =tijeras"<<endl;
		cin>>jugada;
		return jugada;
	}
	string VerNombre(){return m_nombre;}
};

string PiedraPapelTijera(JugadorIA x ,JugadorHumano y){
	string ganador,empate="EMPATE";
	int j1=x.Jugar();
	cout<<"La computadora acaba de procesar su jugada"<<endl<<endl;
	cout<<x.Jugar()<<endl;
	cout<<"Ahora es su turno: "<<endl;
	int j2=y.Jugar();
	
	if(j1==j2){
		return empate;
	}
	if((j1==1 && j2==2) or (j1==2 && j2==3)){
		ganador=y.VerNombre();
	}else{
		if((j1==2 && j2==1) or (j1==3 && j2==2)){
			ganador=x.VerNombre();
		};
	}
	
	return ganador;
}

int main() {
	
	JugadorIA a("");
	JugadorHumano b("BARGAS");
	
	cout<<"Los jugadores son: "<<endl;
	cout<< a.VerNombre()<<" y "<<b.VerNombre()<<endl;
	
	cout<<"El ganador es: "<<PiedraPapelTijera(a,b)<<" FELICITACIONES!!!";
	
	return 0;
}

