#include <iostream>
using namespace std;



float NotaTotal(float Mat, float prom, float PlantT, float SabeIngles){
	
	
	float Total=((Mat*2)+(10*(prom-7))+(5*(PlantT-6)));
	if(SabeIngles==1){
		Total=Total+8;
		return Total;
	}
	return Total;
	
}


bool requisitos(float Mat, float prom, float planT){
	
	bool requisitos=false;
	if(Mat>15 and prom>=7 and planT>6){
		
		return true;
	}
	return false;
}



int main() {
	float N,MatAprobadas,Promedio,PlanTrabajo,SabeIngles;
	int NotaTotal;
	string Nombre;
	string NombreMayorNota;
	string NombreSegundaMayorNota;
	int NotaMayor=0;
	int SegundaNotaMayor=0;
	
	cout<<"ingrese la cantidad de estudiantes"<<endl;
	cin>>N;
	
	int contador=0;
	while (contador < N){
		cout<<"ingrese nombre del estudiante"<<endl;
		cin>>Nombre;
		
		cout<<"ingrese cant de materias aprobadas"<<endl;
		cin>>MatAprobadas;
		
		cout<<"ingrese promedio"<<endl;
		cin>>Promedio;
		
		cout<<"ingrese puntaje del plan de trabajo"<<endl;
		cin>>PlanTrabajo;
		
		
		if (requisitos(MatAprobadas,Promedio,PlanTrabajo)){
			cout<<"cumple con los requisitos"<<endl;
			
			cout<<"el alumno sabe ingles?(INGRESAR 1 si sabe)"<<endl;
			cin>>SabeIngles;
			
			cout<<"el puntaje total de "<<Nombre<<" es "<<NotaTotal;
		}
		
		if (NotaTotal>NotaMayor){
			SegundaNotaMayor=NotaMayor;
			NombreSegundaMayorNota=NombreMayorNota;
			
			NotaMayor=NotaTotal;
			NombreMayorNota=Nombre;
		}
		else{
			if(NotaTotal>SegundaNotaMayor){
				SegundaNotaMayor=NotaTotal;
				NombreSegundaMayorNota=Nombre;
			}
		}
		
		contador=contador+1;
		
	}
	
	cout<<"El mayor promedio es de "<<NombreMayorNota<<" : "<<NotaMayor<<endl;
	cout<<"El segundo mayor promedio es de "<<NombreSegundaMayorNota<<" : "<<SegundaNotaMayor<<endl;
	return 0;
}

