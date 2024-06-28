#include "V_ModificarMaestra.h"
#include "Maestra.h"
#include "Jardin.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
#include <algorithm>
using namespace std;

V_ModificarMaestra::V_ModificarMaestra(wxWindow *parent, Jardin *jardin,long dni,vector<Maestra>V) : MyDialog8(parent),m_Jardin(jardin),m_dni(dni), m_V(V) {
	int m_numero=0;
	
	for(size_t i=0;i<V.size();i++) { 
		if(V[i].VerDni()==m_dni){
			m_numero=i;
		}
	}
	
	m_NombYApe->SetValue(std_to_wx(m_V[m_numero].VerNombre()));
	m_Tipo->SetValue(std_to_wx(m_V[m_numero].VerTipo()));
	m_Direccion->SetValue(std_to_wx(m_V[m_numero].VerDireccion()));
	m_FechNac->SetValue(std_to_wx(m_V[m_numero].VerFechaNac()));
	m_Tel->SetValue(std_to_wx(to_string(m_V[m_numero].VerTel())));
	m_Sala->SetValue(std_to_wx(m_V[m_numero].VerSala()));
	m_Dni->SetValue(std_to_wx(to_string(m_V[m_numero].VerDni())));
}

void V_ModificarMaestra::ClickAceptar( wxCommandEvent& event )  {
	std::string nombre=wx_to_std((m_NombYApe->GetValue()));
	std::string tipo=wx_to_std(m_Tipo->GetValue());
	std::string direccion=wx_to_std(m_Direccion->GetValue());
	std::string fechanac=wx_to_std(m_FechNac->GetValue());
	std::string tel=wx_to_std(m_Tel->GetValue());
	std::string sala=wx_to_std(m_Sala->GetValue());
	std::string dni=wx_to_std(m_Dni->GetValue());
	

	std::string errores;
	if (nombre=="") errores+="El nombre y apellido no puede estar vacio\n";
	if (nombre.size()>64) errores+="El nombre y apellido es demasiado largo\n";
	if (tipo=="") errores+="El tipo no puede estar vacio\n";
	if (tipo!="Maestra" and tipo!="Auxiliar") errores+="El tipo no existe\n";
	if (direccion=="") errores+="La direccion no puede estar vacia\n";
	if (direccion.size()>64) errores+="La direccion es demasiada larga\n";
	if (dni=="") errores+="El dni no puede estar vacia\n";
	if (fechanac=="") errores+="La fecha de nacimiento no puede estar vacia\n";
	if (tel=="") errores+="El telefono no puede estar vacio\n";
	if (sala != "Sala 1" and sala != "Sala 2" and sala != "Sala 3" and sala != "Sala 4" and sala != "Sala 5" and sala != "Sala 6" and sala != "Sala 7" and sala != "Sala 8") errores+="La sala no existe\n";
	if (sala=="") errores+="La sala no puede estar vacia\n";
	
	vector<Maestra>V = m_Jardin->LeerDelArchivoMaestras();
	vector<Alumno>VA = m_Jardin->LeerDelArchivoAlumnos();
	
	if(dni.size()==0){
		wxMessageBox( wxT("EL DNI NO PUEDE ESTAR VACIO!"), wxT("Error ID card number!"), wxICON_ERROR);
	}else{
		
		int dnivalidar=stoi(wx_to_std(m_Dni->GetValue()));
		
		Maestra j(m_dni);
		auto ita = find(V.begin(),V.end(),j);
		auto itb = remove(V.begin(),V.end(),*ita);
		V.erase(itb,V.end());
		
		Maestra k(dnivalidar);
		auto itc = find(V.begin(),V.end(),k);
		Alumno h(dnivalidar);
		auto itd = find(VA.begin(),VA.end(),h);
		
		if(itc == V.end() and itd == VA.end()){
			if(errores.empty()){
				StMaestra a; ficha_medica ficha;
				a.dni=stoi(dni);
				strcpy(a.nombreyape,nombre.c_str());
				strcpy(a.tipo_doc,tipo.c_str());
				strcpy(a.direccion,direccion.c_str());
				strcpy(a.fechanac,fechanac.c_str());
				a.tel=stoi(tel);
				strcpy(a.sala,sala.c_str());
				
				Maestra b(a);
				m_Jardin->ModificarMaestra(b,m_dni);
				EndModal(0);
			}else{
				wxMessageBox(errores);
			}
		}
		else{
			wxMessageBox( wxT("Este dni ya existe."), wxT("Error ID card number!"), wxICON_ERROR);
		}
	}
	
	
	
}

V_ModificarMaestra::~V_ModificarMaestra() {}

