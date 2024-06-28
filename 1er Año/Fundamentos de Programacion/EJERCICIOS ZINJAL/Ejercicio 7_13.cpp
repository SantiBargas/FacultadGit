#include <iostream>
using namespace std;

int main() {
	///Ingresar el importe por hora trabajada y las horas trabajadas 
	///de 25 empelados. Informar mayor y menor salario
	
	///ImporteHora - Salario = 40 * ImporteHora + (Horas trabajadas - 40) * Importe * 1,5

	///Para el calculo del importe a pagar
	int HorasTrabajadas;
	float ImportePorHora;
	
	///Para Mayor, menor y promedio
	float SumaSalarios = 0;
	float MayorSalario = 0;
	float MenorSalario = 1000000000000;
	int HorasExtras;
	float ImporteAPagar;

	///Leer el importe por HorasTrabajadas
	cout<<"ingrese importe a pagar por hora"<<endl;
	cin>>ImportePorHora;
	
	
	for (int i = 1;i<=25;i++) {
		cout<<"ingrese horas trabajadas"<<endl;
		cin>>HorasTrabajadas;
		
		if (HorasTrabajadas>40) {
			HorasExtras= HorasTrabajadas-40;
			HorasTrabajadas = 40;
		}	
		else{
			HorasExtras=0;	
			}
		ImporteAPagar = HorasTrabajadas * ImportePorHora + HorasExtras*ImportePorHora*1,5;
		cout<<"El empleado "<<i<<" cobrara $ "<<ImporteAPagar<<endl;
		
		///equivale a sumasalarios = sumasalarios + importe a pagar
		SumaSalarios+=ImporteAPagar;
		
		///MayorSalario
		
		
		if (ImporteAPagar> MayorSalario){
			MayorSalario=ImporteAPagar;
		}
		
		///MenorSalario
		if (ImporteAPagar<MenorSalario){
			MenorSalario=ImporteAPagar;
		}
		
		
	}
		cout<<"el mayor salario es "<<MayorSalario<<endl;
		cout<<"el menor salario es "<<MenorSalario<<endl;
	
	
	
	
	
	return 0;
}

