#ifndef V_FICHAMEDICA_H
#define V_FICHAMEDICA_H
#include "wxfb_project.h"
#include "Jardin.h"
#include <vector>
using namespace std;

class V_FichaMEdica : public MyDialog3 {
	
private:
	Jardin *m_Jardin;
	long m_dni;
	int m_numero;
	vector<Alumno>m_V;
protected:
public:
	V_FichaMEdica(wxWindow *parent, Jardin * jardin, long dni,vector<Alumno>V);
	~V_FichaMEdica();
};

#endif

