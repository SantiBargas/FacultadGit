///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

wxfbExample::wxfbExample( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText64 = new wxStaticText( this, wxID_ANY, wxT("Fecha Actual:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	m_staticText64->SetFont( wxFont( 11, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer102->Add( m_staticText64, 0, wxALL, 5 );

	m_CuadroFecha = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer102->Add( m_CuadroFecha, 0, wxALL, 5 );


	bSizer34->Add( bSizer102, 0, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Mis Primeros Pasos"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	m_staticText24->SetFont( wxFont( 26, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer35->Add( m_staticText24, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer34->Add( bSizer35, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer311;
	bSizer311 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText211 = new wxStaticText( this, wxID_ANY, wxT("Lista Salas:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText211->Wrap( -1 );
	m_staticText211->SetFont( wxFont( 16, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer101->Add( m_staticText211, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND|wxALIGN_BOTTOM, 5 );


	bSizer311->Add( bSizer101, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxHORIZONTAL );

	m_Buscar = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	m_Buscar->ShowSearchButton( true );
	#endif
	m_Buscar->ShowCancelButton( false );
	bSizer63->Add( m_Buscar, 1, wxALL|wxEXPAND, 5 );

	m_button11 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( m_button11, 0, wxALL, 5 );

	m_Filtrar = new wxComboBox( this, wxID_ANY, wxT("Todo"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	m_Filtrar->Append( wxT("Todo") );
	m_Filtrar->Append( wxT("Alumno") );
	m_Filtrar->Append( wxT("Maestra") );
	m_Filtrar->Append( wxT("Auxiliar") );
	m_Filtrar->Append( wxEmptyString );
	m_Filtrar->SetSelection( 0 );
	bSizer63->Add( m_Filtrar, 0, wxALL, 5 );


	bSizer311->Add( bSizer63, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxVERTICAL );

	GrillaSala = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	GrillaSala->CreateGrid( 1, 10 );
	GrillaSala->EnableEditing( true );
	GrillaSala->EnableGridLines( true );
	GrillaSala->SetGridLineColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	GrillaSala->EnableDragGridSize( false );
	GrillaSala->SetMargins( 0, 0 );

	// Columns
	GrillaSala->SetColSize( 0, 103 );
	GrillaSala->SetColSize( 1, 139 );
	GrillaSala->SetColSize( 2, 93 );
	GrillaSala->SetColSize( 3, 145 );
	GrillaSala->SetColSize( 4, 81 );
	GrillaSala->SetColSize( 5, 101 );
	GrillaSala->SetColSize( 6, 145 );
	GrillaSala->SetColSize( 7, 137 );
	GrillaSala->SetColSize( 8, 94 );
	GrillaSala->SetColSize( 9, 108 );
	GrillaSala->EnableDragColMove( false );
	GrillaSala->EnableDragColSize( true );
	GrillaSala->SetColLabelSize( 30 );
	GrillaSala->SetColLabelValue( 0, wxT("Sala") );
	GrillaSala->SetColLabelValue( 1, wxT("Nombre y Apellido") );
	GrillaSala->SetColLabelValue( 2, wxT("Tipo") );
	GrillaSala->SetColLabelValue( 3, wxT("DNI") );
	GrillaSala->SetColLabelValue( 4, wxT("Edad") );
	GrillaSala->SetColLabelValue( 5, wxT("Nombre tutor") );
	GrillaSala->SetColLabelValue( 6, wxT("Direccion") );
	GrillaSala->SetColLabelValue( 7, wxT("Fecha de Nacimiento") );
	GrillaSala->SetColLabelValue( 8, wxT("Telefono") );
	GrillaSala->SetColLabelValue( 9, wxT("Ficha Medica") );
	GrillaSala->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	GrillaSala->EnableDragRowSize( true );
	GrillaSala->SetRowLabelSize( 0 );
	GrillaSala->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance
	GrillaSala->SetLabelBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_SCROLLBAR ) );
	GrillaSala->SetLabelTextColour( wxSystemSettings::GetColour( wxSYS_COLOUR_CAPTIONTEXT ) );

	// Cell Defaults
	GrillaSala->SetDefaultCellBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	GrillaSala->SetDefaultCellAlignment( wxALIGN_CENTER, wxALIGN_CENTER );
	GrillaSala->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	GrillaSala->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );

	bSizer131->Add( GrillaSala, 1, wxEXPAND|wxALL, 5 );


	bSizer311->Add( bSizer131, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	AddButton = new wxButton( this, wxID_ANY, wxT("Agregar Maestra"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( AddButton, 0, wxALL, 5 );

	m_button5 = new wxButton( this, wxID_ANY, wxT("Eliminar  Maestra"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button5, 0, wxALL, 5 );

	DeleteButton = new wxButton( this, wxID_ANY, wxT("Agregar Alumno"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( DeleteButton, 0, wxALL, 5 );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Eliminar Alumno"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_button6, 0, wxALL, 5 );


	bSizer311->Add( bSizer8, 0, wxALIGN_RIGHT, 5 );


	bSizer20->Add( bSizer311, 1, wxEXPAND, 5 );


	bSizer34->Add( bSizer20, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer34 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::ClickBuscar ), NULL, this );
	m_Filtrar->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( wxfbExample::ClickFiltrar ), NULL, this );
	GrillaSala->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxfbExample::Modificar ), NULL, this );
	GrillaSala->Connect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( wxfbExample::Ficha ), NULL, this );
	AddButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::ClickBotonAgregarMaestra ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::EliminarMaestra ), NULL, this );
	DeleteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::ClickBotonAgregarAlumno ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::EliminarAlumno ), NULL, this );
}

wxfbExample::~wxfbExample()
{
	// Disconnect Events
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::ClickBuscar ), NULL, this );
	m_Filtrar->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( wxfbExample::ClickFiltrar ), NULL, this );
	GrillaSala->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( wxfbExample::Modificar ), NULL, this );
	GrillaSala->Disconnect( wxEVT_GRID_CELL_RIGHT_CLICK, wxGridEventHandler( wxfbExample::Ficha ), NULL, this );
	AddButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::ClickBotonAgregarMaestra ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::EliminarMaestra ), NULL, this );
	DeleteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::ClickBotonAgregarAlumno ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( wxfbExample::EliminarAlumno ), NULL, this );

}

MyDialog1::MyDialog1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INACTIVEBORDER ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("\nIngrese DNI de la Maestra a eliminar :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetFont( wxFont( 16, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );
	m_staticText4->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOTEXT ) );
	m_staticText4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer9->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	IngresoDni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( IngresoDni, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bSizer8->Add( bSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	Aceptar_Eliminar = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( Aceptar_Eliminar, 0, wxALL|wxALIGN_BOTTOM, 5 );

	Cancelar_Elimiar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( Cancelar_Elimiar, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer8->Add( bSizer10, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MyDialog1::Eliminar ) );
	Aceptar_Eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickAceptar ), NULL, this );
	Cancelar_Elimiar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickCancelar ), NULL, this );
}

MyDialog1::~MyDialog1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MyDialog1::Eliminar ) );
	Aceptar_Eliminar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickAceptar ), NULL, this );
	Cancelar_Elimiar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::ClickCancelar ), NULL, this );

}

MyDialog2::MyDialog2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("\nIngrese DNI del Alumno a eliminar :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	m_staticText4->SetFont( wxFont( 16, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer12->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	IngresoDni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( IngresoDni, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bSizer11->Add( bSizer12, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_button7 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_button7, 0, wxALL|wxALIGN_BOTTOM, 5 );

	m_button8 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_button8, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer11->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer11 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MyDialog2::Eliminar ) );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::ClickAceptar ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::ClickCancelar ), NULL, this );
}

MyDialog2::~MyDialog2()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( MyDialog2::Eliminar ) );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::ClickAceptar ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::ClickCancelar ), NULL, this );

}

MyDialog3::MyDialog3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("FICHA MEDICA"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetFont( wxFont( 18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer29->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer14->Add( bSizer29, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Obra Social:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15->Add( m_staticText5, 0, wxALL, 5 );

	m_obrasocial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_obrasocial->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15->Add( m_obrasocial, 1, wxALL, 5 );


	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Alergias:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	m_staticText51->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer151->Add( m_staticText51, 0, wxALL, 5 );

	m_alergias = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_alergias->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer151->Add( m_alergias, 1, wxALL, 5 );


	bSizer14->Add( bSizer151, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("Grupo Sanguineo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer152->Add( m_staticText52, 0, wxALL, 5 );

	m_gruposanguineo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_gruposanguineo->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer152->Add( m_gruposanguineo, 1, wxALL, 5 );


	bSizer14->Add( bSizer152, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer153;
	bSizer153 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("Medico Cabecera:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer153->Add( m_staticText53, 0, wxALL, 5 );

	m_medico = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_medico->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer153->Add( m_medico, 1, wxALL, 5 );


	bSizer14->Add( bSizer153, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer154;
	bSizer154 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Peso:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	m_staticText54->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer154->Add( m_staticText54, 0, wxALL, 5 );

	m_peso = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_peso->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer154->Add( m_peso, 1, wxALL, 5 );


	bSizer14->Add( bSizer154, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55 = new wxStaticText( this, wxID_ANY, wxT("Altura:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	m_staticText55->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer155->Add( m_staticText55, 0, wxALL, 5 );

	m_altura = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_altura->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer155->Add( m_altura, 1, wxALL, 5 );


	bSizer14->Add( bSizer155, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );


	bSizer14->Add( bSizer43, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer14 );
	this->Layout();

	this->Centre( wxBOTH );
}

MyDialog3::~MyDialog3()
{
}

MyDialog6::MyDialog6( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Agregar Maestra"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetFont( wxFont( 18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer29->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer14->Add( bSizer29, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Nombre y apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15->Add( m_staticText5, 0, wxALL, 5 );

	m_NombYApe = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_NombYApe->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15->Add( m_NombYApe, 1, wxALL, 5 );


	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Tipo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	m_staticText51->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer151->Add( m_staticText51, 0, wxALL, 5 );

	m_Tipo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Tipo->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer151->Add( m_Tipo, 1, wxALL, 5 );


	bSizer14->Add( bSizer151, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("Direccion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer152->Add( m_staticText52, 0, wxALL, 5 );

	m_Direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Direccion->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer152->Add( m_Direccion, 1, wxALL, 5 );


	bSizer14->Add( bSizer152, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer153;
	bSizer153 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer153->Add( m_staticText53, 0, wxALL, 5 );

	m_Dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Dni->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer153->Add( m_Dni, 1, wxALL, 5 );


	bSizer14->Add( bSizer153, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer154;
	bSizer154 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Fecha de Nac :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	m_staticText54->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer154->Add( m_staticText54, 0, wxALL, 5 );

	m_FechNac = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_FechNac->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer154->Add( m_FechNac, 1, wxALL, 5 );


	bSizer14->Add( bSizer154, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55 = new wxStaticText( this, wxID_ANY, wxT("Telefono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	m_staticText55->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer155->Add( m_staticText55, 0, wxALL, 5 );

	m_Tel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Tel->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer155->Add( m_Tel, 1, wxALL, 5 );


	bSizer14->Add( bSizer155, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1551;
	bSizer1551 = new wxBoxSizer( wxHORIZONTAL );


	bSizer14->Add( bSizer1551, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15511;
	bSizer15511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5511 = new wxStaticText( this, wxID_ANY, wxT("Sala:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5511->Wrap( -1 );
	m_staticText5511->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15511->Add( m_staticText5511, 0, wxALL, 5 );

	m_Sala = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Sala->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15511->Add( m_Sala, 1, wxALL, 5 );


	bSizer14->Add( bSizer15511, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );

	m_button9 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( m_button9, 0, wxALL, 5 );


	bSizer14->Add( bSizer43, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer14 );
	this->Layout();
	bSizer14->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog6::ClickAceptar ), NULL, this );
}

MyDialog6::~MyDialog6()
{
	// Disconnect Events
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog6::ClickAceptar ), NULL, this );

}

MyDialog7::MyDialog7( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	wxBoxSizer* bSizer160;
	bSizer160 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxVERTICAL );

	m_staticText110 = new wxStaticText( this, wxID_ANY, wxT("Agregar Alumno"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText110->Wrap( -1 );
	m_staticText110->SetFont( wxFont( 24, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer162->Add( m_staticText110, 0, wxALL, 5 );


	bSizer160->Add( bSizer162, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer163;
	bSizer163 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );


	bSizer141->Add( bSizer75, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer291;
	bSizer291 = new wxBoxSizer( wxVERTICAL );

	m_staticText131 = new wxStaticText( this, wxID_ANY, wxT("Datos alumno:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	m_staticText131->SetFont( wxFont( 18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer291->Add( m_staticText131, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer141->Add( bSizer291, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText56 = new wxStaticText( this, wxID_ANY, wxT("Nombre y apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText56->Wrap( -1 );
	m_staticText56->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer156->Add( m_staticText56, 0, wxALL, 5 );

	m_NombYApe = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_NombYApe->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer156->Add( m_NombYApe, 1, wxALL, 5 );


	bSizer141->Add( bSizer156, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1511;
	bSizer1511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText511 = new wxStaticText( this, wxID_ANY, wxT("Tutor:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText511->Wrap( -1 );
	m_staticText511->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1511->Add( m_staticText511, 0, wxALL, 5 );

	m_Tutor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Tutor->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1511->Add( m_Tutor, 1, wxALL, 5 );


	bSizer141->Add( bSizer1511, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1521;
	bSizer1521 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText521 = new wxStaticText( this, wxID_ANY, wxT("Direccion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText521->Wrap( -1 );
	m_staticText521->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1521->Add( m_staticText521, 0, wxALL, 5 );

	m_Direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Direccion->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1521->Add( m_Direccion, 1, wxALL, 5 );


	bSizer141->Add( bSizer1521, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1531;
	bSizer1531 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText531 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText531->Wrap( -1 );
	m_staticText531->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1531->Add( m_staticText531, 0, wxALL, 5 );

	m_Dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Dni->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1531->Add( m_Dni, 1, wxALL, 5 );


	bSizer141->Add( bSizer1531, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1541;
	bSizer1541 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText541 = new wxStaticText( this, wxID_ANY, wxT("Fecha de Nac :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText541->Wrap( -1 );
	m_staticText541->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1541->Add( m_staticText541, 0, wxALL, 5 );

	m_FechNac = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_FechNac->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1541->Add( m_FechNac, 1, wxALL, 5 );


	bSizer141->Add( bSizer1541, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1552;
	bSizer1552 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText552 = new wxStaticText( this, wxID_ANY, wxT("Telefono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText552->Wrap( -1 );
	m_staticText552->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1552->Add( m_staticText552, 0, wxALL, 5 );

	m_Tel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Tel->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1552->Add( m_Tel, 1, wxALL, 5 );


	bSizer141->Add( bSizer1552, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15511;
	bSizer15511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5511 = new wxStaticText( this, wxID_ANY, wxT("Sala:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5511->Wrap( -1 );
	m_staticText5511->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15511->Add( m_staticText5511, 0, wxALL, 5 );

	m_Sala = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Sala->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15511->Add( m_Sala, 1, wxALL, 5 );


	bSizer141->Add( bSizer15511, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer431;
	bSizer431 = new wxBoxSizer( wxHORIZONTAL );


	bSizer141->Add( bSizer431, 0, wxALIGN_RIGHT, 5 );


	bSizer164->Add( bSizer141, 1, wxEXPAND, 5 );


	bSizer163->Add( bSizer164, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer165;
	bSizer165 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Ficha medica:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetFont( wxFont( 18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer29->Add( m_staticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer14->Add( bSizer29, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Obra Social:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15->Add( m_staticText5, 0, wxALL, 5 );

	m_obrasocial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_obrasocial->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15->Add( m_obrasocial, 1, wxALL, 5 );


	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Alergias:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	m_staticText51->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer151->Add( m_staticText51, 0, wxALL, 5 );

	m_alergias = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_alergias->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer151->Add( m_alergias, 1, wxALL, 5 );


	bSizer14->Add( bSizer151, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("Grupo Sanguineo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer152->Add( m_staticText52, 0, wxALL, 5 );

	m_gruposanguineo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_gruposanguineo->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer152->Add( m_gruposanguineo, 1, wxALL, 5 );


	bSizer14->Add( bSizer152, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer153;
	bSizer153 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("Medico Cabecera:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer153->Add( m_staticText53, 0, wxALL, 5 );

	m_medico = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_medico->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer153->Add( m_medico, 1, wxALL, 5 );


	bSizer14->Add( bSizer153, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer154;
	bSizer154 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Peso:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	m_staticText54->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer154->Add( m_staticText54, 0, wxALL, 5 );

	m_peso = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_peso->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer154->Add( m_peso, 1, wxALL, 5 );


	bSizer14->Add( bSizer154, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55 = new wxStaticText( this, wxID_ANY, wxT("Altura:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	m_staticText55->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer155->Add( m_staticText55, 0, wxALL, 5 );

	m_altura = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_altura->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer155->Add( m_altura, 1, wxALL, 5 );


	bSizer14->Add( bSizer155, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );


	bSizer14->Add( bSizer43, 0, wxALIGN_RIGHT, 5 );

	wxBoxSizer* bSizer210;
	bSizer210 = new wxBoxSizer( wxVERTICAL );


	bSizer14->Add( bSizer210, 1, wxEXPAND, 5 );


	bSizer165->Add( bSizer14, 1, wxEXPAND, 5 );


	bSizer163->Add( bSizer165, 1, wxEXPAND, 5 );


	bSizer160->Add( bSizer163, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxVERTICAL );

	m_button35 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( m_button35, 0, wxALL, 5 );


	bSizer160->Add( bSizer211, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer160 );
	this->Layout();
	bSizer160->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button35->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog7::ClickAceptar ), NULL, this );
}

MyDialog7::~MyDialog7()
{
	// Disconnect Events
	m_button35->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog7::ClickAceptar ), NULL, this );

}

MyDialog8::MyDialog8( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNTEXT ) );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Modificar Maestra"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetFont( wxFont( 18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer29->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer14->Add( bSizer29, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Nombre y apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15->Add( m_staticText5, 0, wxALL, 5 );

	m_NombYApe = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_NombYApe->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15->Add( m_NombYApe, 1, wxALL, 5 );


	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Tipo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	m_staticText51->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer151->Add( m_staticText51, 0, wxALL, 5 );

	m_Tipo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Tipo->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer151->Add( m_Tipo, 1, wxALL, 5 );


	bSizer14->Add( bSizer151, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("Direccion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer152->Add( m_staticText52, 0, wxALL, 5 );

	m_Direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Direccion->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer152->Add( m_Direccion, 1, wxALL, 5 );


	bSizer14->Add( bSizer152, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer153;
	bSizer153 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer153->Add( m_staticText53, 0, wxALL, 5 );

	m_Dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Dni->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer153->Add( m_Dni, 1, wxALL, 5 );


	bSizer14->Add( bSizer153, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer154;
	bSizer154 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Fecha de Nac :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	m_staticText54->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer154->Add( m_staticText54, 0, wxALL, 5 );

	m_FechNac = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_FechNac->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer154->Add( m_FechNac, 1, wxALL, 5 );


	bSizer14->Add( bSizer154, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55 = new wxStaticText( this, wxID_ANY, wxT("Telefono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	m_staticText55->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer155->Add( m_staticText55, 0, wxALL, 5 );

	m_Tel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Tel->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer155->Add( m_Tel, 1, wxALL, 5 );


	bSizer14->Add( bSizer155, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15511;
	bSizer15511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5511 = new wxStaticText( this, wxID_ANY, wxT("Sala:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5511->Wrap( -1 );
	m_staticText5511->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15511->Add( m_staticText5511, 0, wxALL, 5 );

	m_Sala = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Sala->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15511->Add( m_Sala, 1, wxALL, 5 );


	bSizer14->Add( bSizer15511, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );

	m_button9 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer43->Add( m_button9, 0, wxALL, 5 );


	bSizer14->Add( bSizer43, 0, wxALIGN_RIGHT, 5 );


	bSizer74->Add( bSizer14, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer74 );
	this->Layout();
	bSizer74->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog8::ClickAceptar ), NULL, this );
}

MyDialog8::~MyDialog8()
{
	// Disconnect Events
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog8::ClickAceptar ), NULL, this );

}

MyDialog9::MyDialog9( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer160;
	bSizer160 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxVERTICAL );

	m_staticText110 = new wxStaticText( this, wxID_ANY, wxT("Modificar Alumno"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText110->Wrap( -1 );
	m_staticText110->SetFont( wxFont( 24, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer162->Add( m_staticText110, 0, wxALL, 5 );


	bSizer160->Add( bSizer162, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer163;
	bSizer163 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxVERTICAL );


	bSizer141->Add( bSizer75, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer291;
	bSizer291 = new wxBoxSizer( wxVERTICAL );

	m_staticText131 = new wxStaticText( this, wxID_ANY, wxT("Datos alumno:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText131->Wrap( -1 );
	m_staticText131->SetFont( wxFont( 18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer291->Add( m_staticText131, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer141->Add( bSizer291, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText56 = new wxStaticText( this, wxID_ANY, wxT("Nombre y apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText56->Wrap( -1 );
	m_staticText56->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer156->Add( m_staticText56, 0, wxALL, 5 );

	m_NombYApe = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_NombYApe->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer156->Add( m_NombYApe, 1, wxALL, 5 );


	bSizer141->Add( bSizer156, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1511;
	bSizer1511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText511 = new wxStaticText( this, wxID_ANY, wxT("Tutor:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText511->Wrap( -1 );
	m_staticText511->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1511->Add( m_staticText511, 0, wxALL, 5 );

	m_Tutor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Tutor->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1511->Add( m_Tutor, 1, wxALL, 5 );


	bSizer141->Add( bSizer1511, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1521;
	bSizer1521 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText521 = new wxStaticText( this, wxID_ANY, wxT("Direccion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText521->Wrap( -1 );
	m_staticText521->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1521->Add( m_staticText521, 0, wxALL, 5 );

	m_Direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Direccion->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1521->Add( m_Direccion, 1, wxALL, 5 );


	bSizer141->Add( bSizer1521, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1531;
	bSizer1531 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText531 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText531->Wrap( -1 );
	m_staticText531->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1531->Add( m_staticText531, 0, wxALL, 5 );

	m_Dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Dni->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1531->Add( m_Dni, 1, wxALL, 5 );


	bSizer141->Add( bSizer1531, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1541;
	bSizer1541 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText541 = new wxStaticText( this, wxID_ANY, wxT("Fecha de Nac :"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText541->Wrap( -1 );
	m_staticText541->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1541->Add( m_staticText541, 0, wxALL, 5 );

	m_FechNac = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_FechNac->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1541->Add( m_FechNac, 1, wxALL, 5 );


	bSizer141->Add( bSizer1541, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1552;
	bSizer1552 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText552 = new wxStaticText( this, wxID_ANY, wxT("Telefono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText552->Wrap( -1 );
	m_staticText552->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer1552->Add( m_staticText552, 0, wxALL, 5 );

	m_Tel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Tel->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1552->Add( m_Tel, 1, wxALL, 5 );


	bSizer141->Add( bSizer1552, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer15511;
	bSizer15511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5511 = new wxStaticText( this, wxID_ANY, wxT("Sala:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5511->Wrap( -1 );
	m_staticText5511->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15511->Add( m_staticText5511, 0, wxALL, 5 );

	m_Sala = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_Sala->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15511->Add( m_Sala, 1, wxALL, 5 );


	bSizer141->Add( bSizer15511, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer431;
	bSizer431 = new wxBoxSizer( wxHORIZONTAL );


	bSizer141->Add( bSizer431, 0, wxALIGN_RIGHT, 5 );


	bSizer164->Add( bSizer141, 1, wxEXPAND, 5 );


	bSizer163->Add( bSizer164, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer165;
	bSizer165 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Ficha medica:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetFont( wxFont( 18, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, true, wxT("Comic Sans MS") ) );

	bSizer29->Add( m_staticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer14->Add( bSizer29, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5 = new wxStaticText( this, wxID_ANY, wxT("Obra Social:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	m_staticText5->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer15->Add( m_staticText5, 0, wxALL, 5 );

	m_obrasocial = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_obrasocial->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer15->Add( m_obrasocial, 1, wxALL, 5 );


	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Alergias:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	m_staticText51->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer151->Add( m_staticText51, 0, wxALL, 5 );

	m_alergias = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_alergias->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer151->Add( m_alergias, 1, wxALL, 5 );


	bSizer14->Add( bSizer151, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, wxT("Grupo Sanguineo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer152->Add( m_staticText52, 0, wxALL, 5 );

	m_gruposanguineo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_gruposanguineo->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer152->Add( m_gruposanguineo, 1, wxALL, 5 );


	bSizer14->Add( bSizer152, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer153;
	bSizer153 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("Medico Cabecera:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer153->Add( m_staticText53, 0, wxALL, 5 );

	m_medico = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_medico->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer153->Add( m_medico, 1, wxALL, 5 );


	bSizer14->Add( bSizer153, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer154;
	bSizer154 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Peso:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	m_staticText54->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer154->Add( m_staticText54, 0, wxALL, 5 );

	m_peso = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_peso->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer154->Add( m_peso, 1, wxALL, 5 );


	bSizer14->Add( bSizer154, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55 = new wxStaticText( this, wxID_ANY, wxT("Altura:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	m_staticText55->SetFont( wxFont( 14, wxFONTFAMILY_SCRIPT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Comic Sans MS") ) );

	bSizer155->Add( m_staticText55, 0, wxALL, 5 );

	m_altura = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_altura->SetFont( wxFont( 10, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer155->Add( m_altura, 1, wxALL, 5 );


	bSizer14->Add( bSizer155, 1, wxEXPAND, 5 );


	bSizer165->Add( bSizer14, 1, wxEXPAND, 5 );


	bSizer163->Add( bSizer165, 1, wxEXPAND, 5 );


	bSizer160->Add( bSizer163, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxVERTICAL );

	m_button35 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( m_button35, 0, wxALL, 5 );


	bSizer160->Add( bSizer211, 0, wxALIGN_RIGHT, 5 );


	bSizer87->Add( bSizer160, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer87 );
	this->Layout();
	bSizer87->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button35->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::ClickAceptar ), NULL, this );
}

MyDialog9::~MyDialog9()
{
	// Disconnect Events
	m_button35->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::ClickAceptar ), NULL, this );

}
