#ifndef V_AGREGARALUMNO_H
#define V_AGREGARALUMNO_H
#include "wxfb_project.h"
#include "Jardin.h"

class V_AgregarAlumno : public MyDialog7 {
	
private:
	Jardin *m_Jardin;
protected:
	
public:
	V_AgregarAlumno(wxWindow *parent, Jardin *jardin);
	~V_AgregarAlumno();
};

#endif

