#include "V_FichaMEdica.h"
#include "Jardin.h"
#include <algorithm>
#include <vector>
#include "Alumno.h"
#include <wx/msgdlg.h>
#include "Maestra.h"
#include "string_conv.h"
#include <cstring>
using namespace std;


V_FichaMEdica::V_FichaMEdica(wxWindow *parent, Jardin *jardin, long dni,vector<Alumno>V) : MyDialog3(parent), m_Jardin(jardin), m_dni(dni), m_V(V) {
	
	int m_numero=0;
	
	for(size_t i=0;i<V.size();i++) { 
		if(V[i].VerDni()==m_dni){
			m_numero=i;
		}
	}
	
	
	ficha_medica ficha;
	ficha=V[m_numero].VerFichaMedica();
	m_obrasocial->SetValue(ficha.obra_social);
	m_alergias->SetValue(ficha.alergias);
	m_gruposanguineo->SetValue(ficha.grupo_sanguineo);
	m_medico->SetValue(ficha.medico_cabecera);
	m_peso->SetValue(to_string(ficha.peso));
	m_altura->SetValue(to_string(ficha.altura));
}

V_FichaMEdica::~V_FichaMEdica() {
	
}


