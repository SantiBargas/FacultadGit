#include <iostream>
using namespace std;

bool requisitos(int matapro,int prom, int plant);
float puntaje(int matapro,int prom, int plant,int notaingles);

int main() {
	int N;
	cout<<"cuantos estudiantes hay?"<<endl;
	cin>>N;
	int cont=0;
	
	string nombre,mayornombre,mayor2nombre;
	int matapro,plant,ingles,notaingles;
	float prom,mayortotal,mayor2total,total;
	
	while(cont<N){
		
		cout<<"ingrese nombre del alumno"<<endl;
		cin>>nombre;
		cout<<"ingrese cant de materias aprobadas"<<endl;
		cin>>matapro;
		cout<<"ingrese promedio"<<endl;
		cin>>prom;
		cout<<"ingrese puntaje del plan de trabajo"<<endl;
		cin>>plant;
		
		ingles=requisitos(matapro,prom,plant);
		if(ingles==true){
			cout<<"ingrese nota de ingles"<<endl;
			cin>>notaingles;
			
			total=puntaje(matapro,prom,plant,notaingles);
			if(total>mayortotal){
				mayor2nombre=mayornombre;
				mayor2total=mayortotal;
				mayortotal=total;
				mayornombre=nombre;
			}
			if(total>mayor2total){
				mayor2total=total;
				mayor2nombre=nombre;
			}
		}else{cout<<"no cumple con los requisitos"<<endl;}
		cont++;
	}
	cout<<endl<<endl<<endl;
	cout<<"el alumno con mayor nota es: "<<mayornombre<<" con un total de: "<<mayortotal<<endl;
	cout<<"el alumno con segundamayor nota es: "<<mayor2nombre<<" con un total de: "<<mayor2total<<endl;
	return 0;
}

bool requisitos(int matapro,int prom, int plant){
	if(matapro>=15 && prom>=7 && plant>=6){
		return true;
	}
	return false;
}
float puntaje(int matapro,int prom, int plant,int notaingles){
	
	int total;
	total=(matapro*2)+((prom-7)*10)+((plant-6)*5);
	if(requisitos(matapro,prom,plant)==true){
		total+8;
	}
	return total;
}
