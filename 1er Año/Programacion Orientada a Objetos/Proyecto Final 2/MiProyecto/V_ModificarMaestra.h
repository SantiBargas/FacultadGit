#ifndef V_MODIFICARMAESTRA_H
#define V_MODIFICARMAESTRA_H
#include "wxfb_project.h"
#include "Jardin.h"
#include "Maestra.h"
#include <vector>
using namespace std;

class V_ModificarMaestra : public MyDialog8 {
	
private:
	Jardin *m_Jardin;
	long m_dni;
	int m_numero;
	vector<Maestra>m_V;
protected:
	void ClickAceptar( wxCommandEvent& event )  override;
	
public:
	V_ModificarMaestra(wxWindow *parent, Jardin *jardin,long dni,vector<Maestra>V);
	~V_ModificarMaestra();
};

#endif

