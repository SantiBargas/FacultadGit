#include <iostream>
#include <vector>
#include <matrix>
using namespace std;

int main() {
	
	int n;
	
	vector<int> vdni(n);
	cout<<"ingrese la cantidad de alumnos"<<endl;
	cin>>n;
	
	matrix<int> m(n,5,0);
	for(size_t i=0;i<n;i++){
		int dni,nro;
		cout<<"ingrese el numero y dni del alumno"<<endl;
		cin>> nro >>dni;
		m[nro-1][0]= dni;
	}
	
	int num;
	cin>>num;
	
	while(num!=0){
		int prueba, pts;
		cin>>prueba>>pts;
		m[num-1][prueba];
		
		cin>>num;
	}
	
	for(int i=0;i<n;i++){
		m[i][4]=m[i][1]+m[i][2]+m[i][3];
	}
	
	int  pos_ganador=0, pos_segundo=1;
	if(m[1][4]>m[0][4]) swap(pos_ganador, pos_segundo);
	
	for(int i=0;i<n;i++){
		if(m[i][4]>m[pos_ganador][4]){
			pos_segundo=pos_ganador;
			pos_ganador = i;
		}
		else{
			if (m[i][4] > m[pos_segundo][4]){
				pos_segundo = i;
			}
		}
			
	}
	
	cout<<"gano el alumno con el dni"<< m[pos_ganador][0];
	cout<<"Segundo fue el alumno con el dni"<<m[pos_segundo][0];
	
	return 0;
}

