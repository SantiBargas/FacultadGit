#include "V_AgregarAlumno.h"
#include "Jardin.h"
#include "Alumno.h"
#include <cstring>
#include "string_conv.h"
#include <wx/msgdlg.h>
#include <vector>
#include "Maestra.h"
#include <algorithm>
using namespace std;

V_AgregarAlumno::V_AgregarAlumno(wxWindow *parent, Jardin *jardin) : MyDialog7(parent), m_Jardin(jardin)  {}

V_AgregarAlumno::~V_AgregarAlumno() {}

void V_AgregarAlumno::ClickAceptar( wxCommandEvent& event )  {
	
	
	std::string nombre=wx_to_std((m_NombYApe->GetValue()));
	std::string nombretutor=wx_to_std(m_Tutor->GetValue());
	std::string direccion=wx_to_std(m_Direccion->GetValue());
	std::string fechanac=wx_to_std(m_FechNac->GetValue());
	std::string tel=wx_to_std(m_Tel->GetValue());
	std::string sala=wx_to_std(m_Sala->GetValue());
	std::string dni=wx_to_std(m_Dni->GetValue());
	int dnivalidar=stoi(wx_to_std(m_Dni->GetValue()));
	
	std::string obrasocial=wx_to_std(m_obrasocial->GetValue());
	std::string alergias=wx_to_std(m_alergias->GetValue());
	std::string gruposanguineo=wx_to_std(m_gruposanguineo->GetValue());
	std::string medico=wx_to_std(m_medico->GetValue());
	std::string altura=wx_to_std(m_peso->GetValue());
	std::string peso=wx_to_std(m_altura->GetValue());
	
	std::string errores;
	if (nombre=="") errores+="El nombre y apellido no puede estar vacio\n";
	if (nombre.size()>64) errores+="El nombre y apellido es demasiado largo\n";
	if (nombretutor=="") errores+="El nombre y apellido del tutor no puede estar vacio\n";
	if (nombretutor.size()>64) errores+="El nombre y apellido del tutor es demasiado largo\n";
	if (direccion=="") errores+="La direccion no puede estar vacia\n";
	if (direccion.size()>64) errores+="La direccion es demasiada larga\n";
	if (fechanac=="") errores+="La fecha de nacimiento no puede estar vacia\n";
	if (tel=="") errores+="El telefono no puede estar vacio\n";
	if (sala != "Sala 1" and sala != "Sala 2" and sala != "Sala 3" and sala != "Sala 4" and sala != "Sala 5" and sala != "Sala 6" and sala != "Sala 7" and sala != "Sala 8") errores+="La sala no existe\n";
	if (sala=="") errores+="La sala no puede estar vacia\n";
	if (dni=="") errores+="El dni no puede estar vacia\n";
	
	if (obrasocial=="") errores+="La obra social no puede estar vacia\n";
	if (obrasocial.size()>64) errores+="La obra social es demasiada larga\n";
	if (alergias=="") errores+="La obra social no puede estar vacia\n";
	if (alergias.size()>64) errores+="La obra social es demasiada larga\n";
	if (gruposanguineo=="") errores+="El grupo sanguineo no puede estar vacio\n";
	if (gruposanguineo.size()>64) errores+="El grupo sanguineo es demasiado largo\n";
	if (medico=="") errores+="El nombre y apellido del medico no puede estar vacio\n";
	if (medico.size()>64) errores+="El nombre y apellido del medico es demasiado largo\n";
	if (peso=="") errores+="El peso no puede estar vacio\n";
	if (altura=="") errores+="La altura del medico no puede estar vacio\n";
	
	vector<Alumno>V = m_Jardin->LeerDelArchivoAlumnos();
	vector<Maestra>VM = m_Jardin->LeerDelArchivoMaestras();
	
	Alumno k(dnivalidar);
	auto itc = find(V.begin(),V.end(),k);
	Maestra h(dnivalidar);
	auto itd = find(VM.begin(),VM.end(),h);
	
	if(itc == V.end() and itd == VM.end()){
		if(errores.empty()){
			StAlumno a; ficha_medica ficha;
			a.dni=stoi(dni);
			strcpy(a.nombreyape,nombre.c_str());
			strcpy(a.nombretutor,nombretutor.c_str());
			strcpy(a.direccion,direccion.c_str());
			strcpy(a.fechanac,fechanac.c_str());
			a.tel=stoi(tel);
			strcpy(a.sala,sala.c_str());
			
			strcpy(ficha.obra_social,obrasocial.c_str());
			strcpy(ficha.alergias,alergias.c_str());
			strcpy(ficha.grupo_sanguineo,gruposanguineo.c_str());
			strcpy(ficha.medico_cabecera,medico.c_str());
			ficha.peso=stof(peso);
			ficha.altura=stof(altura);
			
			a.ficha=ficha;
			
			Alumno b(a);
			m_Jardin->AgregarAlumno(b);
			EndModal(1);
		}else{
			wxMessageBox(errores);
		}
	}
	else{
		wxMessageBox( wxT("Este dni ya existe."), wxT("Error ID card number!"), wxICON_ERROR);
	}
}

