#include "V_ModificarAlumno.h"
#include "Jardin.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
#include <vector>
#include <algorithm>
using namespace std;
int CalcularEdadAlum( wxDateTime fecha, Alumno x){
	
	int dia=fecha.GetDay();
	int mes=(fecha.GetMonth()+1)*100;
	int anio=fecha.GetYear()*10000;
	
	int fecha1=anio+mes+dia;
	
	string edad=x.VerFechaNac();
	int a=edad.find("/");
	int b=edad.find("/" ,a+1);
	int c = edad.size();
	
	int e=(b-a)-1;
	int d=(c-b)-1;
	
	string s1=edad.substr(0,a);
	string s2=edad.substr(a+1,e);
	string s3=edad.substr(b+1,d);
	
	int dia2=stoi(s1);
	int mes2=stoi(s2);
	int anio2=stoi(s3);
	
	mes2=mes2*100;
	anio2=anio2*10000;
	int fecha2=anio2+mes2+dia2;
	
	int total=fecha1-fecha2;
	return total/10000;
	
	return 0;
}
V_ModificarAlumno::V_ModificarAlumno(wxWindow *parent, Jardin *jardin,long dni,vector<Alumno>V,wxDateTime fecha) : MyDialog9(parent), m_Jardin(jardin),m_dni(dni), m_V(V), M_Fecha(fecha) {
	int m_numero=0;
	
	for(size_t i=0;i<V.size();i++) { 
		if(V[i].VerDni()==m_dni){
			m_numero=i;
		}
	}

	m_NombYApe->SetValue(std_to_wx(m_V[m_numero].VerNombre()));
	m_Tutor->SetValue(std_to_wx(m_V[m_numero].VerNombreTutor()));
	m_Direccion->SetValue(std_to_wx(m_V[m_numero].VerDireccion()));
	m_FechNac->SetValue(std_to_wx(m_V[m_numero].VerFechaNac()));
	m_Tel->SetValue(std_to_wx(to_string(m_V[m_numero].VerTel())));
	m_Sala->SetValue(std_to_wx(m_V[m_numero].VerSala()));
	m_Dni->SetValue(std_to_wx(to_string(m_V[m_numero].VerDni())));
	
	ficha_medica ficha;
	ficha=V[m_numero].VerFichaMedica();
	m_obrasocial->SetValue(ficha.obra_social);
	m_alergias->SetValue(ficha.alergias);
	m_gruposanguineo->SetValue(ficha.grupo_sanguineo);
	m_medico->SetValue(ficha.medico_cabecera);
	m_peso->SetValue(to_string(ficha.peso));
	m_altura->SetValue(to_string(ficha.altura));
}

void V_ModificarAlumno::ClickAceptar( wxCommandEvent& event )  {
	std::string nombre=wx_to_std((m_NombYApe->GetValue()));
	std::string nombretutor=wx_to_std(m_Tutor->GetValue());
	std::string direccion=wx_to_std(m_Direccion->GetValue());
	std::string fechanac=wx_to_std(m_FechNac->GetValue());
	std::string tel=wx_to_std(m_Tel->GetValue());
	std::string sala=wx_to_std(m_Sala->GetValue());
	std::string dni=wx_to_std(m_Dni->GetValue());
	
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
	
	if(dni.size()==0){
		wxMessageBox( wxT("EL DNI NO PUEDE ESTAR VACIO!"), wxT("Error ID card number!"), wxICON_ERROR);
	}else{
		int dnivalidar=stoi(wx_to_std(m_Dni->GetValue()));
		Alumno j(m_dni);
		auto ita = find(V.begin(),V.end(),j);
		auto itb = remove(V.begin(),V.end(),*ita);
		V.erase(itb,V.end());
		
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
				m_Jardin->ModificarAlumno(b,m_dni);
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

V_ModificarAlumno::~V_ModificarAlumno() {}

