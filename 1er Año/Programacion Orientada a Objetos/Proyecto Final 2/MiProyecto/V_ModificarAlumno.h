#ifndef V_MODIFICARALUMNO_H
#define V_MODIFICARALUMNO_H
#include "wxfb_project.h"
#include "Jardin.h"
#include <vector>
#include "Alumno.h"
#include <wx/datetime.h>
using namespace std;

class V_ModificarAlumno : public MyDialog9 {
	
private:
	Jardin *m_Jardin;
	long m_dni;
	int m_numero;
	vector<Alumno>m_V;
	wxDateTime M_Fecha;
protected:
	void ClickAceptar( wxCommandEvent& event )  override;
	
public:
	V_ModificarAlumno(wxWindow *parent, Jardin *jardin,long dni,vector<Alumno>V,wxDateTime fecha);
	~V_ModificarAlumno();
};

#endif

