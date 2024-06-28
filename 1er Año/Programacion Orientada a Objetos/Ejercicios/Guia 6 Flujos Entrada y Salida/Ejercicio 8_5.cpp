#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct FichaMedico{
	string nombre;
	vector<int>pacientes;
};

bool operator==(FichaMedico f, string nom ){
	return f.nombre==nom;
}

class Clinica{
private:
	vector<FichaMedico> m_fichas_med;
public:
	void AgregarMedico(string nombre){
		FichaMedico f;
		f.nombre=nombre;
		m_fichas_med.push_back(f);
	}
	void AgregarPaciente(int nro_medico,int dni_paciente){
		m_fichas_med[nro_medico].pacientes.push_back(dni_paciente);
	}
	void EliminarPaciente(int dni_paciente){
		for(FichaMedico& f: m_fichas_med){
			/*auto* o*/ vector<int>::iterator it=find(f.pacientes.begin(),f.pacientes.end(),dni_paciente); //busco el dni en TODAS las fichas
			//devuelve un iterador que apunta a ese paciente	
			if(it!=f.pacientes.end()){
				f.pacientes.erase(it); 	
			}
			//si no esta en el vector,sigo con otra ficha por eso pongo f.pacientes.end, para saber si se salio del rango de busqueda
		}
	}
	int BuscarMedico(string nombre){
		for(size_t i=0;i<m_fichas_med.size();i++) { 
			if(m_fichas_med[i].nombre==nombre){
				return i;
			}
		}
		return -1;
	}
	int CantMedicos() const{return m_fichas_med.size();}
	const FichaMedico &VerFicha(int i) const{ //& evitar copia, const asegurarme que no me modifique nada
		return m_fichas_med[i];
	}
	
	
};

int main() { 
	
	Clinica c;
	
	int pos_dr_mengano=c.BuscarMedico("Mengano");
	if(pos_dr_mengano==-1){
		cout<<" ese doctor no esta registrado en la clinica";
	}else{
		c.EliminarPaciente(pos_dr_mengano,436731220);
	}
	
	return 0;
}

