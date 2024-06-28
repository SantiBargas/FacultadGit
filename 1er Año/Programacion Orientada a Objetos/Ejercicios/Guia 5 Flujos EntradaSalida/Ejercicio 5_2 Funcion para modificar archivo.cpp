#include <iostream>
#include <vector>
#include <fstream>
///La funcion consta de 3 partes: Cargar los datos, encontrar al alumno q quiero modificar
///y guardar los datos
#include <iomanip>
using namespace std;

struct Alumno{
	string nombre;
	int n1,n2;
};

vector<Alumno> cargardatos(){
	vector<Alumno> v;	
	ifstream archi_in("Ejercicio 5_2.txt");
	
	Alumno a;
	while(getline(archi_in,a.nombre) && archi_in>> a.n1 >> a.n2){   ///Ponemos las acciones de lecturas como condicion
		archi_in.ignore();
		v.push_back(a);
	}
	return v;
}

int buscar(vector<Alumno> &v,string nom){
	for(size_t i=0;i<v.size();i++){
		if(v[i].nombre==nom){
			return i;
		}
	}
	return -1;
}
	
void guardardatos(const vector<Alumno>&v){
	ofstream archi_out("Ejercicio 5_2.txt",ios::trunc);
	for(Alumno a:v){
		archi_out<<a.nombre <<endl<<a.n1<<" "<<a.n2<<endl;
	}
}
	
bool modificarNota(string nom,int i1,int i2){
	vector<Alumno> v = cargardatos();	//1ra parte
	
	int pos=buscar(v,nom);//2da parte busco al alumno
	if(pos==-1) return false;
	v[pos].n1=i1; 
	v[pos].n2=i2;   //modifico la nota

	guardardatos(v); //3er paso guardar los datos
	return true;
}

void generarPromedios(){
	ofstream archi_out("Ejercicio 5_2 promedios");
	
	vector<Alumno>v=cargardatos();
	for(Alumno a : v){
		float prom=(a.n1+a.n2)/2.0;
		string cond="Libre";
		if(prom>=70 and a.n1>=60 and a.n2>=60) cond ="promocionado";
		else if(a.n1>=40 and a.n2>=40) cond ="regular";
		archi_out<<setw(25)<<left<<a.nombre
			<<setw(7)<<right<<fixed<<setprecision(2)<<prom
			<<setw(14)<<right<<cond<<endl;
	}
}
	
int main() {
	
	if(modificarNota("Lopez Javier",100,100)){
		cout<<"Notas modificadas"<<endl<<endl;
	}else{
		cout<<"No se encontro alumno"<<endl;
	}
	generarPromedios(); 
	
	return 0;
}

