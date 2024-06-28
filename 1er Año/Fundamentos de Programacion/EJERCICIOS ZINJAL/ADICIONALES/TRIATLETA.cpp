#include <iostream>
#include <vector>
using namespace std;

struct triatleta{
	int fecha;
	int minnatacion;
	int segnatacion;
	int minciclismo;
	int segciclismo;
	int minpedestrismo;
	int segpedestrismo;
	float tiemponat;
	float tiempocic;
	float tiempopedest;
	
};
	
int main() {
	int N;
	cout<<"cuantos grupos son"<<endl;
	cin>>N;
	vector<triatleta>lista(N);
	
	int cont=0;
	while(cont<N){
		cout<<"ingrese fecha del entrenamiento"<<endl;
		cin>>lista[cont].fecha;
		
		cout<<"ingrese min de natacion"<<endl;
		cin>>lista[cont].minnatacion;
		cout<<"ingrese seg de natacion"<<endl;
		cin>>lista[cont].segnatacion;
		
		lista[cont].tiemponat=(lista[cont].minnatacion*60)+lista[cont].segnatacion;
		
		cout<<"ingrese min de ciclismo"<<endl;
		cin>>lista[cont].minciclismo;
		cout<<"ingrese seg de natacion"<<endl;
		cin>>lista[cont].segciclismo;
		
		lista[cont].tiempocic=(lista[cont].minciclismo*60)+lista[cont].segciclismo;
		
		cout<<"ingrese min de pedestrismo"<<endl;
		cin>>lista[cont].minpedestrismo;
		cout<<"ingrese seg de pedestrismo"<<endl;
		cin>>lista[cont].segpedestrismo;
		
		lista[cont].tiempopedest=(lista[cont].minpedestrismo*60)+lista[cont].segpedestrismo;
		cont++;
	}
	
	int mejornat=100000000,mejorcic=100000000,mejorpedest=100000000;
	int fechanat,fechacic,fechapedest;
	
	for(int i=0;i<lista.size();i++){
		if(lista[i].tiemponat<mejornat){
			mejornat=lista[i].tiemponat;
			fechanat=lista[i].fecha;
		}
		if(lista[i].tiemponat<mejorcic){
			mejorcic=lista[i].tiempocic;
			fechacic=lista[i].fecha;
		}
		if(lista[i].tiemponat<mejorpedest){
			mejorpedest=lista[i].tiempopedest;
			fechapedest=lista[i].fecha;
		}
	}
	int anionat,dianat,mesnat,aniocic,diacic,mescic,aniopedest,mespedest,diapedest;
	
	anionat=fechanat/1000;
	mesnat=(fechanat%10000)/100;
	dianat=fechanat%100;
	
	aniocic=fechacic/1000;
	mescic=(fechacic%10000)/100;
	diacic=fechacic%100;
	
	aniopedest=fechapedest/1000;
	mespedest=(fechapedest%10000)/100;
	diapedest=fechapedest%100;
	
	
	cout<<"el mejor tiempo logrado de natacion es: "<<mejornat<<"segundos"<<endl;
	cout<<"en el año"<<anionat<<" mes "<<mesnat<<" dia "<<dianat<<endl;
	
	cout<<"el mejor tiempo logrado de ciclismo es: "<<mejorcic<<"segundos"<<endl;
	cout<<"en el año"<<aniocic<<" mes "<<mescic<<" dia "<<diacic<<endl;
	
	cout<<"el mejor tiempo logrado de pedestrismo es: "<<mejorpedest<<"segundos"<<endl;
	cout<<"en el año"<<aniopedest<<" mes "<<mespedest<<" dia "<<diapedest<<endl;
	
	int suma=0,prom;
	for(int i=0;i<lista.size();i++){
		suma+=(lista[i].tiemponat+lista[i].tiempocic+lista[i].tiempopedest);
	}
	prom=suma/lista.size();
	cout<<"el promedio entre los tiempos de los tres tipos es de: "<<prom<<endl;
	
	int total,fechamejor,fecha2mejor;
	int mejortiempo=1000000000,mejor2tiempo=100000000;
	for(int i=0;i<lista.size();i++){
		total=lista[i].tiemponat+lista[i].tiempocic+lista[i].tiempopedest;
		if(total>mejortiempo){
			mejor2tiempo=mejortiempo;
			fecha2mejor=fechamejor;
			mejortiempo=total;
			fechamejor=lista[i].fecha;
		}else{
			if(total>mejor2tiempo){
				mejor2tiempo=total;
				fecha2mejor=lista[i].fecha;
			}
		}
		total=0;
	}
	
	int aniomejor,mesmejor,diamejor,anio2mejor,mes2mejor,dia2mejor;
	
	aniomejor=fechamejor/10000;
	mesmejor=(fechamejor%1000)/100;
	diamejor=fechamejor%100;
	
	anio2mejor=fecha2mejor/10000;
	mes2mejor=(fecha2mejor%1000)/100;
	dia2mejor=fecha2mejor%100;
	
	
	cout<<"el mejor tiempo total es: "<<mejortiempo<<endl;
	cout<<"el año "<<aniomejor<<" el mes "<<mesmejor<<" el dia "<<diamejor<<endl;
	cout<<"el segundo mejor tiempo total es: "<<mejor2tiempo<<endl;
	cout<<"el año "<<anio2mejor<<" el mes "<<mes2mejor<<" el dia "<<dia2mejor<<endl;
	return 0;
}

