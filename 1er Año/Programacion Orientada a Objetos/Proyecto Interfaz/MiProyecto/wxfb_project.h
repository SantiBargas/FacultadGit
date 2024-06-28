///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once





///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class wxfbExample
///////////////////////////////////////////////////////////////////////////////
class wxfbExample : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText211;
		wxGrid* GrillaSala;
		wxButton* AddButton;
		wxButton* m_button5;
		wxButton* DeleteButton;
		wxButton* m_button6;

		// Virtual event handlers, overide them in your derived class
		virtual void Ficha( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickBotonAgregarMaestra( wxCommandEvent& event ) { event.Skip(); }
		virtual void EliminarMaestra( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickBotonAgregarAlumno( wxCommandEvent& event ) { event.Skip(); }
		virtual void EliminarAlumno( wxCommandEvent& event ) { event.Skip(); }


	public:

		wxfbExample( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1196,653 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~wxfbExample();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText4;
		wxTextCtrl* IngresoDni;
		wxButton* Aceptar_Eliminar;
		wxButton* Cancelar_Elimiar;

		// Virtual event handlers, overide them in your derived class
		virtual void Eliminar( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void ClickAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyDialog1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 467,195 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MyDialog1();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog2
///////////////////////////////////////////////////////////////////////////////
class MyDialog2 : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText4;
		wxTextCtrl* IngresoDni;
		wxButton* m_button7;
		wxButton* m_button8;

		// Virtual event handlers, overide them in your derived class
		virtual void Eliminar( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void ClickAceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyDialog2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 465,199 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MyDialog2();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog3
///////////////////////////////////////////////////////////////////////////////
class MyDialog3 : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_obrasocial;
		wxStaticText* m_staticText51;
		wxTextCtrl* m_alergias;
		wxStaticText* m_staticText52;
		wxTextCtrl* m_gruposanguineo;
		wxStaticText* m_staticText53;
		wxTextCtrl* m_medico;
		wxStaticText* m_staticText54;
		wxTextCtrl* m_peso;
		wxStaticText* m_staticText55;
		wxTextCtrl* m_altura;

	public:

		MyDialog3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 606,528 ), long style = wxDEFAULT_DIALOG_STYLE );
		~MyDialog3();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog6
///////////////////////////////////////////////////////////////////////////////
class MyDialog6 : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_NombYApe;
		wxStaticText* m_staticText51;
		wxTextCtrl* m_Tutor;
		wxStaticText* m_staticText52;
		wxTextCtrl* m_Direccion;
		wxStaticText* m_staticText53;
		wxTextCtrl* m_Dni;
		wxStaticText* m_staticText54;
		wxTextCtrl* m_FechNac;
		wxStaticText* m_staticText55;
		wxTextCtrl* m_Tel;
		wxStaticText* m_staticText551;
		wxTextCtrl* m_Edad;
		wxStaticText* m_staticText5511;
		wxTextCtrl* m_Sala;
		wxButton* m_button9;
		wxButton* m_button10;

		// Virtual event handlers, overide them in your derived class
		virtual void ClickSiguiente( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyDialog6( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~MyDialog6();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog7
///////////////////////////////////////////////////////////////////////////////
class MyDialog7 : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText110;
		wxStaticText* m_staticText131;
		wxStaticText* m_staticText56;
		wxTextCtrl* m_NombYApe;
		wxStaticText* m_staticText511;
		wxTextCtrl* m_Tutor;
		wxStaticText* m_staticText521;
		wxTextCtrl* m_Direccion;
		wxStaticText* m_staticText531;
		wxTextCtrl* m_Dni;
		wxStaticText* m_staticText541;
		wxTextCtrl* m_FechNac;
		wxStaticText* m_staticText552;
		wxTextCtrl* m_Tel;
		wxStaticText* m_staticText551;
		wxTextCtrl* m_Edad;
		wxStaticText* m_staticText5511;
		wxTextCtrl* m_Sala;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_obrasocial;
		wxStaticText* m_staticText51;
		wxTextCtrl* m_alergias;
		wxStaticText* m_staticText52;
		wxTextCtrl* m_gruposanguineo;
		wxStaticText* m_staticText53;
		wxTextCtrl* m_medico;
		wxStaticText* m_staticText54;
		wxTextCtrl* m_peso;
		wxStaticText* m_staticText55;
		wxTextCtrl* m_altura;
		wxButton* m_button35;

	public:

		MyDialog7( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~MyDialog7();

};

