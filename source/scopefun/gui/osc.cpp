///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "osc.h"

///////////////////////////////////////////////////////////////////////////

Osciloskop::Osciloskop( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Open") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem1 );

	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem2 );

	m_menu1->AppendSeparator();

	wxMenuItem* m_menuItemConvertToText;
	m_menuItemConvertToText = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Convert To Text") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItemConvertToText );

	m_menu1->AppendSeparator();

	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("Quit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem3 );

	m_menubar1->Append( m_menu1, _("File") );

	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem20;
	m_menuItem20 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Osciloscope 3D") ) , wxEmptyString, wxITEM_CHECK );
	m_menu2->Append( m_menuItem20 );

	wxMenuItem* m_menuItem21;
	m_menuItem21 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Osciloscope 2D") ) , wxEmptyString, wxITEM_CHECK );
	m_menu2->Append( m_menuItem21 );

	wxMenuItem* m_menuItem22;
	m_menuItem22 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("FFT 3D") ) , wxEmptyString, wxITEM_CHECK );
	m_menu2->Append( m_menuItem22 );

	wxMenuItem* m_menuItem23;
	m_menuItem23 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("FFT 2D") ) , wxEmptyString, wxITEM_CHECK );
	m_menu2->Append( m_menuItem23 );

	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu2, wxID_ANY, wxString( _("Digital") ) , wxEmptyString, wxITEM_CHECK );
	m_menu2->Append( m_menuItem6 );
	m_menuItem6->Check( true );

	m_menubar1->Append( m_menu2, _("View") );

	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Display") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem8 );

	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Thermal") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem9 );

	wxMenuItem* m_menuItemStorage;
	m_menuItemStorage = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Storage") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItemStorage );

	wxMenuItem* m_menuItemConnection;
	m_menuItemConnection = new wxMenuItem( m_menu3, wxID_ANY, wxString( _("Connection") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItemConnection );

	m_menubar1->Append( m_menu3, _("Settings") );

	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItemSoftware;
	m_menuItemSoftware = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Software Simulator") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItemSoftware );

	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menu4, wxID_ANY, wxString( _("Hardware Generator") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem11 );

	m_menubar1->Append( m_menu4, _("Generator") );

	m_menu5 = new wxMenu();
	wxMenuItem* m_menuItemReadEEPROM;
	m_menuItemReadEEPROM = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Read FX3 Firmware") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItemReadEEPROM );

	wxMenuItem* m_menuItemWriteEEPROM;
	m_menuItemWriteEEPROM = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Write FX3 Firmware") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItemWriteEEPROM );

	m_menu5->AppendSeparator();

	wxMenuItem* m_menuItem12;
	m_menuItem12 = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Auto Callibrate") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItem12 );

	m_menu5->AppendSeparator();

	wxMenuItem* m_menuItemWriteCallibrate;
	m_menuItemWriteCallibrate = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Write Callibration") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItemWriteCallibrate );

	wxMenuItem* m_menuItemReadCallibrate;
	m_menuItemReadCallibrate = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Read Callibration") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItemReadCallibrate );

	m_menu5->AppendSeparator();

	wxMenuItem* m_menuItemWriteCertificate;
	m_menuItemWriteCertificate = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Write Certificate") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItemWriteCertificate );

	wxMenuItem* m_menuItemReadCertificate;
	m_menuItemReadCertificate = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Read Certificate") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItemReadCertificate );

	wxMenuItem* m_menuItemLockCertificate;
	m_menuItemLockCertificate = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Lock Certificate") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItemLockCertificate );

	m_menu5->AppendSeparator();

	wxMenuItem* m_menuItemResetEEPROM;
	m_menuItemResetEEPROM = new wxMenuItem( m_menu5, wxID_ANY, wxString( _("Erase FX3 Firmware") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItemResetEEPROM );

	m_menubar1->Append( m_menu5, _("EEPROM") );

	m_menu8 = new wxMenu();
	wxMenuItem* m_menuItem15;
	m_menuItem15 = new wxMenuItem( m_menu8, wxID_ANY, wxString( _("Analog") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu8->Append( m_menuItem15 );

	m_menubar1->Append( m_menu8, _("Measure") );

	m_menu9 = new wxMenu();
	wxMenuItem* m_menuItemSlot1;
	m_menuItemSlot1 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Slot 1") ) , wxEmptyString, wxITEM_CHECK );
	m_menu9->Append( m_menuItemSlot1 );
	m_menuItemSlot1->Check( true );

	wxMenuItem* m_menuItemSlot2;
	m_menuItemSlot2 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Slot 2") ) , wxEmptyString, wxITEM_CHECK );
	m_menu9->Append( m_menuItemSlot2 );

	wxMenuItem* m_menuItemSlot3;
	m_menuItemSlot3 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Slot 3") ) , wxEmptyString, wxITEM_CHECK );
	m_menu9->Append( m_menuItemSlot3 );

	wxMenuItem* m_menuItemSlot4;
	m_menuItemSlot4 = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Slot 4") ) , wxEmptyString, wxITEM_CHECK );
	m_menu9->Append( m_menuItemSlot4 );

	m_menu9->AppendSeparator();

	wxMenuItem* m_menuItemLoad;
	m_menuItemLoad = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Load slot from File") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu9->Append( m_menuItemLoad );

	wxMenuItem* m_menuItemSaveFile;
	m_menuItemSaveFile = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Save slot to File") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu9->Append( m_menuItemSaveFile );

	m_menu9->AppendSeparator();

	wxMenuItem* m_menuItemResetToDefault;
	m_menuItemResetToDefault = new wxMenuItem( m_menu9, wxID_ANY, wxString( _("Reset To Default") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu9->Append( m_menuItemResetToDefault );

	m_menubar1->Append( m_menu9, _("State") );

	m_menu10 = new wxMenu();
	wxMenuItem* m_menuItemClipboardCurrent;
	m_menuItemClipboardCurrent = new wxMenuItem( m_menu10, wxID_ANY, wxString( _("Current Frame") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu10->Append( m_menuItemClipboardCurrent );

	wxMenuItem* m_menuItemClipboardAll;
	m_menuItemClipboardAll = new wxMenuItem( m_menu10, wxID_ANY, wxString( _("All Frames") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu10->Append( m_menuItemClipboardAll );

	m_menubar1->Append( m_menu10, _("To Clipboard") );

	m_menu11 = new wxMenu();
	wxMenuItem* m_menuItemVersion1;
	m_menuItemVersion1 = new wxMenuItem( m_menu11, wxID_ANY, wxString( _("Version 1.0") ) , wxEmptyString, wxITEM_CHECK );
	m_menu11->Append( m_menuItemVersion1 );

	wxMenuItem* m_menuItemVersion2;
	m_menuItemVersion2 = new wxMenuItem( m_menu11, wxID_ANY, wxString( _("Version 2.0") ) , wxEmptyString, wxITEM_CHECK );
	m_menu11->Append( m_menuItemVersion2 );
	m_menuItemVersion2->Check( true );

	m_menubar1->Append( m_menu11, _("Compatibility") );

	m_menu6 = new wxMenu();
	m_menubar1->Append( m_menu6, _("Language") );

	m_menu7 = new wxMenu();
	m_menuItemDebug = new wxMenuItem( m_menu7, wxID_ANY, wxString( _("Debug") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItemDebug );

	m_menuItemTests = new wxMenuItem( m_menu7, wxID_ANY, wxString( _("RunTests") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItemTests );

	wxMenuItem* m_menuItemInfo;
	m_menuItemInfo = new wxMenuItem( m_menu7, wxID_ANY, wxString( _("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu7->Append( m_menuItemInfo );

	m_menubar1->Append( m_menu7, _("Info") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1671;
	bSizer1671 = new wxBoxSizer( wxVERTICAL );

	m_staticline17 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1671->Add( m_staticline17, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer1512;
	bSizer1512 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBox26 = new wxCheckBox( this, wxID_ANY, _("USB Open"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer1512->Add( m_checkBox26, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonConnect = new wxButton( this, wxID_ANY, _("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1512->Add( m_buttonConnect, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonDisconnect = new wxButton( this, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1512->Add( m_buttonDisconnect, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonFirmwareUpload = new wxButton( this, wxID_ANY, _("Upload Firmware"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1512->Add( m_buttonFirmwareUpload, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1512->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonUndo = new wxButton( this, wxID_ANY, _("Undo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1512->Add( m_buttonUndo, 0, wxALL, 5 );

	m_buttonRedo = new wxButton( this, wxID_ANY, _("Redo"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1512->Add( m_buttonRedo, 0, wxALL, 5 );


	bSizer1512->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText106 = new wxStaticText( this, wxID_ANY, _("Speed:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText106->Wrap( -1 );
	bSizer1512->Add( m_staticText106, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceSpeedChoices[] = { _("Automatic"), _("Low"), _("Medium"), _("High") };
	int m_choiceSpeedNChoices = sizeof( m_choiceSpeedChoices ) / sizeof( wxString );
	m_choiceSpeed = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSpeedNChoices, m_choiceSpeedChoices, 0 );
	m_choiceSpeed->SetSelection( 0 );
	bSizer1512->Add( m_choiceSpeed, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Control:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer1512->Add( m_staticText19, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxTimeControlChoices[] = { _("normal"), _("testmode"), _("shutdown"), _("reset") };
	int m_comboBoxTimeControlNChoices = sizeof( m_comboBoxTimeControlChoices ) / sizeof( wxString );
	m_comboBoxTimeControl = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxTimeControlNChoices, m_comboBoxTimeControlChoices, 0 );
	m_comboBoxTimeControl->SetSelection( 0 );
	bSizer1512->Add( m_comboBoxTimeControl, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1671->Add( bSizer1512, 1, wxEXPAND, 5 );

	m_staticline18 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1671->Add( m_staticline18, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer154;
	bSizer154 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText141 = new wxStaticText( this, wxID_ANY, _("Capture:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText141->Wrap( -1 );
	bSizer36->Add( m_staticText141, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	wxString m_comboBoxTimeCaptureChoices[] = { _("2ns"), _("4ns"), _("10ns"), _("20ns"), _("50ns"), _("100ns"), _("200ns"), _("500ns"), _("1us"), _("2us"), _("5us"), _("10us"), _("20us"), _("50us"), _("100us"), _("200us"), _("500us"), _("1ms"), _("2ms"), _("5ms"), _("10ms"), _("20ms"), _("50ms"), _("100ms"), _("200ms"), _("500ms"), _("1s") };
	int m_comboBoxTimeCaptureNChoices = sizeof( m_comboBoxTimeCaptureChoices ) / sizeof( wxString );
	m_comboBoxTimeCapture = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxTimeCaptureNChoices, m_comboBoxTimeCaptureChoices, 0 );
	m_comboBoxTimeCapture->SetSelection( 0 );
	bSizer36->Add( m_comboBoxTimeCapture, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxETS = new wxCheckBox( this, wxID_ANY, _("ETS"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer36->Add( m_checkBoxETS, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText151 = new wxStaticText( this, wxID_ANY, _("Display:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText151->Wrap( -1 );
	m_staticText151->Enable( false );
	m_staticText151->Hide();

	bSizer36->Add( m_staticText151, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTimeDisplay = new wxTextCtrl( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	m_textCtrlTimeDisplay->Enable( false );
	m_textCtrlTimeDisplay->Hide();

	bSizer36->Add( m_textCtrlTimeDisplay, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxTimeDisplayChoices[] = { _("second"), _("mili"), _("micro"), _("nano") };
	int m_comboBoxTimeDisplayNChoices = sizeof( m_comboBoxTimeDisplayChoices ) / sizeof( wxString );
	m_comboBoxTimeDisplay = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxTimeDisplayNChoices, m_comboBoxTimeDisplayChoices, 0 );
	m_comboBoxTimeDisplay->SetSelection( 0 );
	m_comboBoxTimeDisplay->Enable( false );
	m_comboBoxTimeDisplay->Hide();

	bSizer36->Add( m_comboBoxTimeDisplay, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxFull = new wxCheckBox( this, wxID_ANY, _("Full"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer36->Add( m_checkBoxFull, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer36->Add( 0, 0, 12, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( bSizer36, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, _("X Position:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText12->Wrap( -1 );
	bSizer37->Add( m_staticText12, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTimePosition = new wxTextCtrl( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer37->Add( m_textCtrlTimePosition, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_spinBtnXPos = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer37->Add( m_spinBtnXPos, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderTimePosition = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( -1,-1 ), wxSL_HORIZONTAL );
	bSizer37->Add( m_sliderTimePosition, 8, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer5->Add( bSizer37, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText122 = new wxStaticText( this, wxID_ANY, _("Frame History:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText122->Wrap( -1 );
	bSizer71->Add( m_staticText122, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTimeFrame = new wxTextCtrl( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer71->Add( m_textCtrlTimeFrame, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnFrameHistory = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer71->Add( m_spinBtnFrameHistory, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderTimeFrame = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxSize( -1,-1 ), wxSL_HORIZONTAL );
	bSizer71->Add( m_sliderTimeFrame, 8, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( bSizer71, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPlay = new wxButton( this, wxID_ANY, _("Play"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_buttonPlay, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonPause = new wxButton( this, wxID_ANY, _("Pause"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_buttonPause, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCapture = new wxButton( this, wxID_ANY, _("Capture"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_buttonCapture, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonSimulate = new wxButton( this, wxID_ANY, _("Simulate"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_buttonSimulate, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonClear = new wxButton( this, wxID_ANY, _("Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_buttonClear, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText181 = new wxStaticText( this, wxID_ANY, _("Frame Size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText181->Wrap( -1 );
	bSizer8->Add( m_staticText181, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTimeFrameSize = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer8->Add( m_textCtrlTimeFrameSize, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText1811 = new wxStaticText( this, wxID_ANY, _("FFT Size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1811->Wrap( -1 );
	bSizer8->Add( m_staticText1811, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTimeFFTSize = new wxTextCtrl( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer8->Add( m_textCtrlTimeFFTSize, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer5->Add( bSizer8, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer154->Add( bSizer5, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1671->Add( bSizer154, 12, wxEXPAND, 5 );

	m_staticline15 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1671->Add( m_staticline15, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_notebook4 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH );
	m_panel15 = new wxPanel( m_notebook4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( m_panel15, wxID_ANY, _("Capture:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText34->Wrap( -1 );
	bSizer15->Add( m_staticText34, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxCh0CaptureChoices[] = { _("2V"), _("1V"), _("500mV"), _("200mV"), _("100mV"), _("50mV"), _("20mV"), _("10mV") };
	int m_comboBoxCh0CaptureNChoices = sizeof( m_comboBoxCh0CaptureChoices ) / sizeof( wxString );
	m_comboBoxCh0Capture = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxCh0CaptureNChoices, m_comboBoxCh0CaptureChoices, 0 );
	m_comboBoxCh0Capture->SetSelection( 1 );
	bSizer15->Add( m_comboBoxCh0Capture, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer15->Add( 0, 0, 12, wxEXPAND, 5 );

	m_staticTextCh0Scale = new wxStaticText( m_panel15, wxID_ANY, _("Scale:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCh0Scale->Wrap( -1 );
	m_staticTextCh0Scale->Enable( false );
	m_staticTextCh0Scale->Hide();

	bSizer15->Add( m_staticTextCh0Scale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlCh0Scale = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrlCh0Scale->Enable( false );
	m_textCtrlCh0Scale->Hide();

	bSizer15->Add( m_textCtrlCh0Scale, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14->Add( bSizer15, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBoxCh0Invert = new wxCheckBox( m_panel15, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBoxCh0Invert, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxCh0Ground = new wxCheckBox( m_panel15, wxID_ANY, _("Ground"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBoxCh0Ground, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceCh0ACDCChoices[] = { _("AC"), _("DC") };
	int m_choiceCh0ACDCNChoices = sizeof( m_choiceCh0ACDCChoices ) / sizeof( wxString );
	m_choiceCh0ACDC = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCh0ACDCNChoices, m_choiceCh0ACDCChoices, 0 );
	m_choiceCh0ACDC->SetSelection( 0 );
	bSizer17->Add( m_choiceCh0ACDC, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText35 = new wxStaticText( m_panel15, wxID_ANY, _("Display:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText35->Wrap( -1 );
	m_staticText35->Enable( false );
	m_staticText35->Hide();

	bSizer17->Add( m_staticText35, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlCh0Display = new wxTextCtrl( m_panel15, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	m_textCtrlCh0Display->Enable( false );
	m_textCtrlCh0Display->Hide();

	bSizer17->Add( m_textCtrlCh0Display, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxCh0DisplayChoices[] = { _("volt"), _("mili"), _("micro"), _("nano") };
	int m_comboBoxCh0DisplayNChoices = sizeof( m_comboBoxCh0DisplayChoices ) / sizeof( wxString );
	m_comboBoxCh0Display = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxCh0DisplayNChoices, m_comboBoxCh0DisplayChoices, 0 );
	m_comboBoxCh0Display->SetSelection( 0 );
	m_comboBoxCh0Display->Enable( false );
	m_comboBoxCh0Display->Hide();

	bSizer17->Add( m_comboBoxCh0Display, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBoxSignal1 = new wxCheckBox( m_panel15, wxID_ANY, _("Display Signal"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBoxSignal1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxFFT1 = new wxCheckBox( m_panel15, wxID_ANY, _("Display FFT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBoxFFT1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxAvg01 = new wxCheckBox( m_panel15, wxID_ANY, _("Average"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_checkBoxAvg01, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer17->Add( 0, 0, 12, wxEXPAND, 5 );


	bSizer14->Add( bSizer17, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1221 = new wxStaticText( m_panel15, wxID_ANY, _("Y Position:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText1221->Wrap( -1 );
	bSizer18->Add( m_staticText1221, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlCh0Position = new wxTextCtrl( m_panel15, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer18->Add( m_textCtrlCh0Position, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnCh0YPos = new wxSpinButton( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer18->Add( m_spinBtnCh0YPos, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderCh0Position = new wxSlider( m_panel15, wxID_ANY, 0, -1500, 1500, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer18->Add( m_sliderCh0Position, 8, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer14->Add( bSizer18, 1, wxEXPAND, 5 );


	m_panel15->SetSizer( bSizer14 );
	m_panel15->Layout();
	bSizer14->Fit( m_panel15 );
	m_notebook4->AddPage( m_panel15, _("Channel 1"), true );
	m_panel16 = new wxPanel( m_notebook4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText341 = new wxStaticText( m_panel16, wxID_ANY, _("Capture:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText341->Wrap( -1 );
	bSizer151->Add( m_staticText341, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxCh1CaptureChoices[] = { _("2V"), _("1V"), _("500mV"), _("200mV"), _("100mV"), _("50mV"), _("20mV"), _("10mV") };
	int m_comboBoxCh1CaptureNChoices = sizeof( m_comboBoxCh1CaptureChoices ) / sizeof( wxString );
	m_comboBoxCh1Capture = new wxChoice( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxCh1CaptureNChoices, m_comboBoxCh1CaptureChoices, 0 );
	m_comboBoxCh1Capture->SetSelection( 0 );
	bSizer151->Add( m_comboBoxCh1Capture, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer151->Add( 0, 0, 12, wxEXPAND, 5 );

	m_staticTextCh1Scale = new wxStaticText( m_panel16, wxID_ANY, _("Scale:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextCh1Scale->Wrap( -1 );
	m_staticTextCh1Scale->Enable( false );
	m_staticTextCh1Scale->Hide();

	bSizer151->Add( m_staticTextCh1Scale, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlCh1Scale = new wxTextCtrl( m_panel16, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrlCh1Scale->Enable( false );
	m_textCtrlCh1Scale->Hide();

	bSizer151->Add( m_textCtrlCh1Scale, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer141->Add( bSizer151, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBoxCh1Invert = new wxCheckBox( m_panel16, wxID_ANY, _("Invert"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( m_checkBoxCh1Invert, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxCh1Ground = new wxCheckBox( m_panel16, wxID_ANY, _("Ground"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( m_checkBoxCh1Ground, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceCh1ACDCChoices[] = { _("AC"), _("DC") };
	int m_choiceCh1ACDCNChoices = sizeof( m_choiceCh1ACDCChoices ) / sizeof( wxString );
	m_choiceCh1ACDC = new wxChoice( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceCh1ACDCNChoices, m_choiceCh1ACDCChoices, 0 );
	m_choiceCh1ACDC->SetSelection( 0 );
	bSizer171->Add( m_choiceCh1ACDC, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlCh1Display = new wxTextCtrl( m_panel16, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	m_textCtrlCh1Display->Enable( false );
	m_textCtrlCh1Display->Hide();

	bSizer171->Add( m_textCtrlCh1Display, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText351 = new wxStaticText( m_panel16, wxID_ANY, _("Display:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText351->Wrap( -1 );
	m_staticText351->Enable( false );
	m_staticText351->Hide();

	bSizer171->Add( m_staticText351, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxCh1DisplayChoices[] = { _("volt"), _("mili"), _("micro"), _("nano") };
	int m_comboBoxCh1DisplayNChoices = sizeof( m_comboBoxCh1DisplayChoices ) / sizeof( wxString );
	m_comboBoxCh1Display = new wxChoice( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxCh1DisplayNChoices, m_comboBoxCh1DisplayChoices, 0 );
	m_comboBoxCh1Display->SetSelection( 0 );
	m_comboBoxCh1Display->Enable( false );
	m_comboBoxCh1Display->Hide();

	bSizer171->Add( m_comboBoxCh1Display, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer171->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBoxSignal2 = new wxCheckBox( m_panel16, wxID_ANY, _("Display Signal"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( m_checkBoxSignal2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxFFT2 = new wxCheckBox( m_panel16, wxID_ANY, _("Display FFT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( m_checkBoxFFT2, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxAvg02 = new wxCheckBox( m_panel16, wxID_ANY, _("Average"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( m_checkBoxAvg02, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer171->Add( 0, 0, 12, wxEXPAND, 5 );


	bSizer141->Add( bSizer171, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer181;
	bSizer181 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12211 = new wxStaticText( m_panel16, wxID_ANY, _("Y Position:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText12211->Wrap( -1 );
	bSizer181->Add( m_staticText12211, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlCh1Position = new wxTextCtrl( m_panel16, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer181->Add( m_textCtrlCh1Position, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnCh1YPos = new wxSpinButton( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer181->Add( m_spinBtnCh1YPos, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderCh1Position = new wxSlider( m_panel16, wxID_ANY, 0, -1500, 1500, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer181->Add( m_sliderCh1Position, 8, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer141->Add( bSizer181, 1, wxEXPAND, 5 );


	m_panel16->SetSizer( bSizer141 );
	m_panel16->Layout();
	bSizer141->Fit( m_panel16 );
	m_notebook4->AddPage( m_panel16, _("Channel 2"), false );
	m_panel161 = new wxPanel( m_notebook4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1411;
	bSizer1411 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1511;
	bSizer1511 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextFunction = new wxStaticText( m_panel161, wxID_ANY, _("Function:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticTextFunction->Wrap( -1 );
	bSizer1511->Add( m_staticTextFunction, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxFunctionChoices[] = { _("medium(ch0,ch1)"), _("sub(ch1,ch0)"), _("sub(ch0,ch1)"), _("add(ch0,ch1)"), _("min(ch0,ch1)"), _("max(ch0,ch1)"), _("Custom Function") };
	int m_comboBoxFunctionNChoices = sizeof( m_comboBoxFunctionChoices ) / sizeof( wxString );
	m_comboBoxFunction = new wxChoice( m_panel161, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxFunctionNChoices, m_comboBoxFunctionChoices, 0 );
	m_comboBoxFunction->SetSelection( 0 );
	bSizer1511->Add( m_comboBoxFunction, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1511->Add( 0, 0, 8, wxEXPAND, 5 );


	bSizer1411->Add( bSizer1511, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer1581;
	bSizer1581 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText116 = new wxStaticText( m_panel161, wxID_ANY, _("Custom Function ="), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText116->Wrap( -1 );
	bSizer1581->Add( m_staticText116, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlFuncCustom = new wxTextCtrl( m_panel161, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrlFuncCustom->SetToolTip( _("operators = + - * / %\nfunctions = min(p1,p2) max(p1,p2) sin( p1, p2 ) cos(p1,p2)\nchannels  = ch0 ch1\nconstants = 0...N\ndouble      = whole.decimal") );

	bSizer1581->Add( m_textCtrlFuncCustom, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1411->Add( bSizer1581, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1491;
	bSizer1491 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBoxXYVoltageGraph = new wxCheckBox( m_panel161, wxID_ANY, _("XY Voltage Graph"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1491->Add( m_checkBoxXYVoltageGraph, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxSignalF = new wxCheckBox( m_panel161, wxID_ANY, _("Display Signal"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1491->Add( m_checkBoxSignalF, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxFFTF = new wxCheckBox( m_panel161, wxID_ANY, _("Display FFT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1491->Add( m_checkBoxFFTF, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1411->Add( bSizer1491, 1, wxEXPAND, 5 );


	m_panel161->SetSizer( bSizer1411 );
	m_panel161->Layout();
	bSizer1411->Fit( m_panel161 );
	m_notebook4->AddPage( m_panel161, _("Function"), false );
	m_panel9 = new wxPanel( m_notebook4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer113;
	bSizer113 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1111;
	bSizer1111 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer1482;
	bSizer1482 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer148;
	bSizer148 = new wxBoxSizer( wxVERTICAL );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );

	wxString m_choiceDOnOff815Choices[] = { _("Custom"), _("All Off"), _("All On") };
	int m_choiceDOnOff815NChoices = sizeof( m_choiceDOnOff815Choices ) / sizeof( wxString );
	m_choiceDOnOff815 = new wxChoice( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDOnOff815NChoices, m_choiceDOnOff815Choices, 0 );
	m_choiceDOnOff815->SetSelection( 0 );
	bSizer148->Add( m_choiceDOnOff815, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer148->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer1482->Add( bSizer148, 0, wxEXPAND, 5 );

	wxGridSizer* gSizer7;
	gSizer7 = new wxGridSizer( 2, 4, 0, 0 );

	m_checkBox16 = new wxCheckBox( m_panel9, wxID_ANY, _("15"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer7->Add( m_checkBox16, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_checkBox14 = new wxCheckBox( m_panel9, wxID_ANY, _("13"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer7->Add( m_checkBox14, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_checkBox12 = new wxCheckBox( m_panel9, wxID_ANY, _("11"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer7->Add( m_checkBox12, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox10 = new wxCheckBox( m_panel9, wxID_ANY, _("9"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer7->Add( m_checkBox10, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox15 = new wxCheckBox( m_panel9, wxID_ANY, _("14"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer7->Add( m_checkBox15, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox13 = new wxCheckBox( m_panel9, wxID_ANY, _("12"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer7->Add( m_checkBox13, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox11 = new wxCheckBox( m_panel9, wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer7->Add( m_checkBox11, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox9 = new wxCheckBox( m_panel9, wxID_ANY, _("8"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer7->Add( m_checkBox9, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1482->Add( gSizer7, 1, wxEXPAND, 5 );


	bSizer1111->Add( bSizer1482, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer1492;
	bSizer1492 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer149;
	bSizer149 = new wxBoxSizer( wxVERTICAL );


	bSizer149->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceDOnOff70Choices[] = { _("Custom"), _("All Off"), _("All On") };
	int m_choiceDOnOff70NChoices = sizeof( m_choiceDOnOff70Choices ) / sizeof( wxString );
	m_choiceDOnOff70 = new wxChoice( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDOnOff70NChoices, m_choiceDOnOff70Choices, 0 );
	m_choiceDOnOff70->SetSelection( 0 );
	bSizer149->Add( m_choiceDOnOff70, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer149->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1492->Add( bSizer149, 0, wxEXPAND, 5 );

	wxGridSizer* gSizer13;
	gSizer13 = new wxGridSizer( 2, 4, 0, 0 );

	m_checkBox8 = new wxCheckBox( m_panel9, wxID_ANY, _("7"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer13->Add( m_checkBox8, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox6 = new wxCheckBox( m_panel9, wxID_ANY, _("5"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer13->Add( m_checkBox6, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox4 = new wxCheckBox( m_panel9, wxID_ANY, _("3"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer13->Add( m_checkBox4, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox2 = new wxCheckBox( m_panel9, wxID_ANY, _("1"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer13->Add( m_checkBox2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox7 = new wxCheckBox( m_panel9, wxID_ANY, _("6"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer13->Add( m_checkBox7, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox5 = new wxCheckBox( m_panel9, wxID_ANY, _("4"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer13->Add( m_checkBox5, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox3 = new wxCheckBox( m_panel9, wxID_ANY, _("2"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer13->Add( m_checkBox3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_checkBox1 = new wxCheckBox( m_panel9, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer13->Add( m_checkBox1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1492->Add( gSizer13, 1, wxEXPAND, 5 );


	bSizer1111->Add( bSizer1492, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer114->Add( bSizer1111, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer113->Add( bSizer114, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	m_panel9->SetSizer( bSizer113 );
	m_panel9->Layout();
	bSizer113->Fit( m_panel9 );
	m_notebook4->AddPage( m_panel9, _("Digital Channel"), false );
	m_panel91 = new wxPanel( m_notebook4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer166;
	bSizer166 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer157;
	bSizer157 = new wxBoxSizer( wxHORIZONTAL );


	bSizer157->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText89 = new wxStaticText( m_panel91, wxID_ANY, _("15"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText89->Wrap( -1 );
	bSizer157->Add( m_staticText89, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit15Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit15NChoices = sizeof( m_choiceBit15Choices ) / sizeof( wxString );
	m_choiceBit15 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit15NChoices, m_choiceBit15Choices, 0 );
	m_choiceBit15->SetSelection( 0 );
	bSizer157->Add( m_choiceBit15, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer157->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText90 = new wxStaticText( m_panel91, wxID_ANY, _("13"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText90->Wrap( -1 );
	bSizer157->Add( m_staticText90, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit13Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit13NChoices = sizeof( m_choiceBit13Choices ) / sizeof( wxString );
	m_choiceBit13 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit13NChoices, m_choiceBit13Choices, 0 );
	m_choiceBit13->SetSelection( 0 );
	bSizer157->Add( m_choiceBit13, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer157->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText91 = new wxStaticText( m_panel91, wxID_ANY, _("11"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	bSizer157->Add( m_staticText91, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit11Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit11NChoices = sizeof( m_choiceBit11Choices ) / sizeof( wxString );
	m_choiceBit11 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit11NChoices, m_choiceBit11Choices, 0 );
	m_choiceBit11->SetSelection( 0 );
	bSizer157->Add( m_choiceBit11, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer157->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText92 = new wxStaticText( m_panel91, wxID_ANY, _("9"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	bSizer157->Add( m_staticText92, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit9Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit9NChoices = sizeof( m_choiceBit9Choices ) / sizeof( wxString );
	m_choiceBit9 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit9NChoices, m_choiceBit9Choices, 0 );
	m_choiceBit9->SetSelection( 0 );
	bSizer157->Add( m_choiceBit9, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer157->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer166->Add( bSizer157, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxHORIZONTAL );


	bSizer158->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText93 = new wxStaticText( m_panel91, wxID_ANY, _("14"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText93->Wrap( -1 );
	bSizer158->Add( m_staticText93, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit14Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit14NChoices = sizeof( m_choiceBit14Choices ) / sizeof( wxString );
	m_choiceBit14 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit14NChoices, m_choiceBit14Choices, 0 );
	m_choiceBit14->SetSelection( 0 );
	bSizer158->Add( m_choiceBit14, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer158->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText94 = new wxStaticText( m_panel91, wxID_ANY, _("12"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText94->Wrap( -1 );
	bSizer158->Add( m_staticText94, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit12Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit12NChoices = sizeof( m_choiceBit12Choices ) / sizeof( wxString );
	m_choiceBit12 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit12NChoices, m_choiceBit12Choices, 0 );
	m_choiceBit12->SetSelection( 0 );
	bSizer158->Add( m_choiceBit12, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer158->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText95 = new wxStaticText( m_panel91, wxID_ANY, _("10"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText95->Wrap( -1 );
	bSizer158->Add( m_staticText95, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit10Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit10NChoices = sizeof( m_choiceBit10Choices ) / sizeof( wxString );
	m_choiceBit10 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit10NChoices, m_choiceBit10Choices, 0 );
	m_choiceBit10->SetSelection( 0 );
	bSizer158->Add( m_choiceBit10, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer158->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText96 = new wxStaticText( m_panel91, wxID_ANY, _("8"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText96->Wrap( -1 );
	bSizer158->Add( m_staticText96, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit8Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit8NChoices = sizeof( m_choiceBit8Choices ) / sizeof( wxString );
	m_choiceBit8 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit8NChoices, m_choiceBit8Choices, 0 );
	m_choiceBit8->SetSelection( 0 );
	bSizer158->Add( m_choiceBit8, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer158->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer166->Add( bSizer158, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxHORIZONTAL );


	bSizer162->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText134 = new wxStaticText( m_panel91, wxID_ANY, _("Bits:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText134->Wrap( -1 );
	m_staticText134->SetMinSize( wxSize( 50,-1 ) );

	bSizer162->Add( m_staticText134, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	wxString m_choiceDS815Choices[] = { _("Custom"), _("All Zero"), _("All One") };
	int m_choiceDS815NChoices = sizeof( m_choiceDS815Choices ) / sizeof( wxString );
	m_choiceDS815 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDS815NChoices, m_choiceDS815Choices, 0 );
	m_choiceDS815->SetSelection( 1 );
	bSizer162->Add( m_choiceDS815, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer162->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText1341 = new wxStaticText( m_panel91, wxID_ANY, _("Direction:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1341->Wrap( -1 );
	m_staticText1341->SetMinSize( wxSize( 50,-1 ) );

	bSizer162->Add( m_staticText1341, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	wxString m_choiceInputOutputChoices[] = { _("Output"), _("Input") };
	int m_choiceInputOutputNChoices = sizeof( m_choiceInputOutputChoices ) / sizeof( wxString );
	m_choiceInputOutput = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceInputOutputNChoices, m_choiceInputOutputChoices, 0 );
	m_choiceInputOutput->SetSelection( 1 );
	bSizer162->Add( m_choiceInputOutput, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer162->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer166->Add( bSizer162, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bSizer164->Add( bSizer166, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	wxBoxSizer* bSizer167;
	bSizer167 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxHORIZONTAL );


	bSizer159->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText971 = new wxStaticText( m_panel91, wxID_ANY, _("7"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText971->Wrap( -1 );
	bSizer159->Add( m_staticText971, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit7Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit7NChoices = sizeof( m_choiceBit7Choices ) / sizeof( wxString );
	m_choiceBit7 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit7NChoices, m_choiceBit7Choices, 0 );
	m_choiceBit7->SetSelection( 0 );
	bSizer159->Add( m_choiceBit7, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer159->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText98 = new wxStaticText( m_panel91, wxID_ANY, _("5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText98->Wrap( -1 );
	bSizer159->Add( m_staticText98, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit5Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit5NChoices = sizeof( m_choiceBit5Choices ) / sizeof( wxString );
	m_choiceBit5 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit5NChoices, m_choiceBit5Choices, 0 );
	m_choiceBit5->SetSelection( 2 );
	bSizer159->Add( m_choiceBit5, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer159->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText99 = new wxStaticText( m_panel91, wxID_ANY, _("3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99->Wrap( -1 );
	bSizer159->Add( m_staticText99, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit3Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit3NChoices = sizeof( m_choiceBit3Choices ) / sizeof( wxString );
	m_choiceBit3 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit3NChoices, m_choiceBit3Choices, 0 );
	m_choiceBit3->SetSelection( 0 );
	bSizer159->Add( m_choiceBit3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer159->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText100 = new wxStaticText( m_panel91, wxID_ANY, _("1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText100->Wrap( -1 );
	bSizer159->Add( m_staticText100, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit1Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit1NChoices = sizeof( m_choiceBit1Choices ) / sizeof( wxString );
	m_choiceBit1 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit1NChoices, m_choiceBit1Choices, 0 );
	m_choiceBit1->SetSelection( 0 );
	bSizer159->Add( m_choiceBit1, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer159->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer159->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer167->Add( bSizer159, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer160;
	bSizer160 = new wxBoxSizer( wxHORIZONTAL );


	bSizer160->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText101 = new wxStaticText( m_panel91, wxID_ANY, _("6"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	bSizer160->Add( m_staticText101, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit6Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit6NChoices = sizeof( m_choiceBit6Choices ) / sizeof( wxString );
	m_choiceBit6 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit6NChoices, m_choiceBit6Choices, 0 );
	m_choiceBit6->SetSelection( 2 );
	bSizer160->Add( m_choiceBit6, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer160->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText102 = new wxStaticText( m_panel91, wxID_ANY, _("4"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText102->Wrap( -1 );
	bSizer160->Add( m_staticText102, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit4Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit4NChoices = sizeof( m_choiceBit4Choices ) / sizeof( wxString );
	m_choiceBit4 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit4NChoices, m_choiceBit4Choices, 0 );
	m_choiceBit4->SetSelection( 0 );
	bSizer160->Add( m_choiceBit4, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer160->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText103 = new wxStaticText( m_panel91, wxID_ANY, _("2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText103->Wrap( -1 );
	bSizer160->Add( m_staticText103, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit2Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit2NChoices = sizeof( m_choiceBit2Choices ) / sizeof( wxString );
	m_choiceBit2 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit2NChoices, m_choiceBit2Choices, 0 );
	m_choiceBit2->SetSelection( 0 );
	bSizer160->Add( m_choiceBit2, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer160->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText104 = new wxStaticText( m_panel91, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText104->Wrap( -1 );
	bSizer160->Add( m_staticText104, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString m_choiceBit0Choices[] = { _("0"), _("1"), _("X") };
	int m_choiceBit0NChoices = sizeof( m_choiceBit0Choices ) / sizeof( wxString );
	m_choiceBit0 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit0NChoices, m_choiceBit0Choices, 0 );
	m_choiceBit0->SetSelection( 0 );
	bSizer160->Add( m_choiceBit0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer160->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer160->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer167->Add( bSizer160, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );


	bSizer161->Add( 0, 0, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText135 = new wxStaticText( m_panel91, wxID_ANY, _("Bits:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText135->Wrap( -1 );
	m_staticText135->SetMinSize( wxSize( 50,-1 ) );

	bSizer161->Add( m_staticText135, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	wxString m_choiceDS70Choices[] = { _("Custom"), _("All Zero"), _("All One") };
	int m_choiceDS70NChoices = sizeof( m_choiceDS70Choices ) / sizeof( wxString );
	m_choiceDS70 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDS70NChoices, m_choiceDS70Choices, 0 );
	m_choiceDS70->SetSelection( 2 );
	bSizer161->Add( m_choiceDS70, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer161->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText1351 = new wxStaticText( m_panel91, wxID_ANY, _("Direction:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1351->Wrap( -1 );
	m_staticText1351->SetMinSize( wxSize( 50,-1 ) );

	bSizer161->Add( m_staticText1351, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	wxString m_choiceInputOutput1Choices[] = { _("Output"), _("Input") };
	int m_choiceInputOutput1NChoices = sizeof( m_choiceInputOutput1Choices ) / sizeof( wxString );
	m_choiceInputOutput1 = new wxChoice( m_panel91, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceInputOutput1NChoices, m_choiceInputOutput1Choices, 0 );
	m_choiceInputOutput1->SetSelection( 0 );
	bSizer161->Add( m_choiceInputOutput1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer161->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer167->Add( bSizer161, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer164->Add( bSizer167, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );


	m_panel91->SetSizer( bSizer164 );
	m_panel91->Layout();
	bSizer164->Fit( m_panel91 );
	m_notebook4->AddPage( m_panel91, _("Digital Pattern"), false );
	m_panel25 = new wxPanel( m_notebook4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer112;
	bSizer112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText821 = new wxStaticText( m_panel25, wxID_ANY, _("Custom Bits From File:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText821->Wrap( -1 );
	bSizer112->Add( m_staticText821, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_filePicker1 = new wxFilePickerCtrl( m_panel25, wxID_ANY, wxEmptyString, _("./data/signal/digital.signal"), _("*.signal"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST );
	bSizer112->Add( m_filePicker1, 8, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCustomFile = new wxButton( m_panel25, wxID_ANY, _("upload"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer112->Add( m_buttonCustomFile, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer112->Add( 0, 0, 8, wxEXPAND, 5 );


	bSizer152->Add( bSizer112, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer109;
	bSizer109 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText80 = new wxStaticText( m_panel25, wxID_ANY, _("Voltage:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText80->Wrap( -1 );
	bSizer109->Add( m_staticText80, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlDigitalVoltage = new wxTextCtrl( m_panel25, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer109->Add( m_textCtrlDigitalVoltage, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnDigVoltage = new wxSpinButton( m_panel25, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer109->Add( m_spinBtnDigVoltage, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText108 = new wxStaticText( m_panel25, wxID_ANY, _("Frequency divider:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText108->Wrap( -1 );
	bSizer109->Add( m_staticText108, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlFreqDivider = new wxTextCtrl( m_panel25, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer109->Add( m_textCtrlFreqDivider, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText97 = new wxStaticText( m_panel25, wxID_ANY, _("equals"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText97->Wrap( -1 );
	bSizer109->Add( m_staticText97, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticTextMhz = new wxStaticText( m_panel25, wxID_ANY, _("100"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextMhz->Wrap( -1 );
	bSizer109->Add( m_staticTextMhz, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer109->Add( 0, 0, 4, wxEXPAND, 5 );


	bSizer152->Add( bSizer109, 1, wxEXPAND, 5 );


	m_panel25->SetSizer( bSizer152 );
	m_panel25->Layout();
	bSizer152->Fit( m_panel25 );
	m_notebook4->AddPage( m_panel25, _("Digital Setup"), false );

	bSizer155->Add( m_notebook4, 2, wxEXPAND, 5 );


	bSizer1671->Add( bSizer155, 12, wxEXPAND, 5 );

	m_staticline14 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1671->Add( m_staticline14, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxHORIZONTAL );

	m_notebook3 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH );
	m_panel3 = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText47 = new wxStaticText( m_panel3, wxID_ANY, _("Mode:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText47->Wrap( -1 );
	bSizer29->Add( m_staticText47, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxTriggerChoices[] = { _("Auto"), _("Normal"), _("Single"), _("Immediate") };
	int m_comboBoxTriggerNChoices = sizeof( m_comboBoxTriggerChoices ) / sizeof( wxString );
	m_comboBoxTrigger = new wxChoice( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxTriggerNChoices, m_comboBoxTriggerChoices, 0 );
	m_comboBoxTrigger->SetSelection( 2 );
	bSizer29->Add( m_comboBoxTrigger, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText45 = new wxStaticText( m_panel3, wxID_ANY, _("Source:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText45->Wrap( -1 );
	bSizer29->Add( m_staticText45, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxTriggerSourceChoices[] = { _("Channel 1"), _("Channel 2"), _("AWG 1"), _("AWG 2"), _("External") };
	int m_comboBoxTriggerSourceNChoices = sizeof( m_comboBoxTriggerSourceChoices ) / sizeof( wxString );
	m_comboBoxTriggerSource = new wxChoice( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxTriggerSourceNChoices, m_comboBoxTriggerSourceChoices, 0 );
	m_comboBoxTriggerSource->SetSelection( 4 );
	bSizer29->Add( m_comboBoxTriggerSource, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText46 = new wxStaticText( m_panel3, wxID_ANY, _("Slope:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	bSizer29->Add( m_staticText46, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxTriggerSlopeChoices[] = { _("Rising"), _("Falling"), _("Both") };
	int m_comboBoxTriggerSlopeNChoices = sizeof( m_comboBoxTriggerSlopeChoices ) / sizeof( wxString );
	m_comboBoxTriggerSlope = new wxChoice( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxTriggerSlopeNChoices, m_comboBoxTriggerSlopeChoices, 0 );
	m_comboBoxTriggerSlope->SetSelection( 0 );
	bSizer29->Add( m_comboBoxTriggerSlope, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonReArm = new wxButton( m_panel3, wxID_ANY, _("Re-Arm"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_buttonReArm, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_radioBtnTriggered = new wxRadioButton( m_panel3, wxID_ANY, _("Triggered"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtnTriggered->SetForegroundColour( wxColour( 0, 0, 0 ) );
	m_radioBtnTriggered->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	bSizer29->Add( m_radioBtnTriggered, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer28->Add( bSizer29, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText1222 = new wxStaticText( m_panel3, wxID_ANY, _("Level:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText1222->Wrap( -1 );
	bSizer32->Add( m_staticText1222, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTriggerLevel = new wxTextCtrl( m_panel3, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer32->Add( m_textCtrlTriggerLevel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnTrigLevel = new wxSpinButton( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer32->Add( m_spinBtnTrigLevel, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderTriggerLevel = new wxSlider( m_panel3, wxID_ANY, 0, -512, 512, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer32->Add( m_sliderTriggerLevel, 8, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer28->Add( bSizer32, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer321;
	bSizer321 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12221 = new wxStaticText( m_panel3, wxID_ANY, _("Histeresis:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText12221->Wrap( -1 );
	bSizer321->Add( m_staticText12221, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrlTriggerHisteresis = new wxTextCtrl( m_panel3, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer321->Add( m_textCtrlTriggerHisteresis, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnTrigHis = new wxSpinButton( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer321->Add( m_spinBtnTrigHis, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderTriggerHisteresis = new wxSlider( m_panel3, wxID_ANY, 512, 0, 1023, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer321->Add( m_sliderTriggerHisteresis, 8, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer28->Add( bSizer321, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer322;
	bSizer322 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText12222 = new wxStaticText( m_panel3, wxID_ANY, _("Pre-Trigger:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText12222->Wrap( -1 );
	bSizer322->Add( m_staticText12222, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTriggerPre = new wxTextCtrl( m_panel3, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer322->Add( m_textCtrlTriggerPre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnTrigPre = new wxSpinButton( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer322->Add( m_spinBtnTrigPre, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderTriggerPre = new wxSlider( m_panel3, wxID_ANY, 50, 0, 99, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer322->Add( m_sliderTriggerPre, 8, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer28->Add( bSizer322, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55 = new wxStaticText( m_panel3, wxID_ANY, _("Holdoff:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText55->Wrap( -1 );
	bSizer43->Add( m_staticText55, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlTriggerHoldoff = new wxTextCtrl( m_panel3, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer43->Add( m_textCtrlTriggerHoldoff, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnTrigHoldoff = new wxSpinButton( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer43->Add( m_spinBtnTrigHoldoff, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderTriggerHoldoff = new wxSlider( m_panel3, wxID_ANY, 0, 0, 400000000, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer43->Add( m_sliderTriggerHoldoff, 8, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer28->Add( bSizer43, 1, wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer28 );
	m_panel3->Layout();
	bSizer28->Fit( m_panel3 );
	m_notebook3->AddPage( m_panel3, _("Analog"), true );
	m_panel13 = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer78;
	bSizer78 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText63 = new wxStaticText( m_panel13, wxID_ANY, _("Stage:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText63->Wrap( -1 );
	bSizer80->Add( m_staticText63, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxDigitalStageChoices[] = { _("1"), _("2"), _("3"), _("4") };
	int m_comboBoxDigitalStageNChoices = sizeof( m_comboBoxDigitalStageChoices ) / sizeof( wxString );
	m_comboBoxDigitalStage = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxDigitalStageNChoices, m_comboBoxDigitalStageChoices, 0 );
	m_comboBoxDigitalStage->SetSelection( 0 );
	bSizer80->Add( m_comboBoxDigitalStage, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText64 = new wxStaticText( m_panel13, wxID_ANY, _("Delay:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	bSizer80->Add( m_staticText64, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrDigitallDelay = new wxTextCtrl( m_panel13, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer80->Add( m_textCtrDigitallDelay, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText65 = new wxStaticText( m_panel13, wxID_ANY, _("Stage Start:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText65->Wrap( -1 );
	bSizer80->Add( m_staticText65, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxDigitalStageStartChoices[] = { _("1"), _("2"), _("3"), _("4") };
	int m_comboBoxDigitalStageStartNChoices = sizeof( m_comboBoxDigitalStageStartChoices ) / sizeof( wxString );
	m_comboBoxDigitalStageStart = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxDigitalStageStartNChoices, m_comboBoxDigitalStageStartChoices, 0 );
	m_comboBoxDigitalStageStart->SetSelection( 0 );
	bSizer80->Add( m_comboBoxDigitalStageStart, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText66 = new wxStaticText( m_panel13, wxID_ANY, _("Mode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText66->Wrap( -1 );
	bSizer80->Add( m_staticText66, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxDigitalModeChoices[] = { _("Parallel"), _("Serial") };
	int m_comboBoxDigitalModeNChoices = sizeof( m_comboBoxDigitalModeChoices ) / sizeof( wxString );
	m_comboBoxDigitalMode = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxDigitalModeNChoices, m_comboBoxDigitalModeChoices, 0 );
	m_comboBoxDigitalMode->SetSelection( 0 );
	bSizer80->Add( m_comboBoxDigitalMode, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText68 = new wxStaticText( m_panel13, wxID_ANY, _("Serial Channel:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText68->Wrap( -1 );
	bSizer80->Add( m_staticText68, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxDigitalSerialChannelChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9"), _("10"), _("11"), _("12"), _("13"), _("14"), _("15") };
	int m_comboBoxDigitalSerialChannelNChoices = sizeof( m_comboBoxDigitalSerialChannelChoices ) / sizeof( wxString );
	m_comboBoxDigitalSerialChannel = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxDigitalSerialChannelNChoices, m_comboBoxDigitalSerialChannelChoices, 0 );
	m_comboBoxDigitalSerialChannel->SetSelection( 0 );
	bSizer80->Add( m_comboBoxDigitalSerialChannel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer78->Add( bSizer80, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer811;
	bSizer811 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer1502;
	bSizer1502 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer145;
	bSizer145 = new wxBoxSizer( wxVERTICAL );

	wxString m_choiceBit158Choices[] = { _("Custom"), _("All Zero"), _("All One"), _("All Any") };
	int m_choiceBit158NChoices = sizeof( m_choiceBit158Choices ) / sizeof( wxString );
	m_choiceBit158 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit158NChoices, m_choiceBit158Choices, 0 );
	m_choiceBit158->SetSelection( 0 );
	bSizer145->Add( m_choiceBit158, 0, wxALL, 5 );


	bSizer1502->Add( bSizer145, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxGridSizer* gSizer8;
	gSizer8 = new wxGridSizer( 2, 4, 0, 0 );

	wxString m_comboBoxBit15Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit15NChoices = sizeof( m_comboBoxBit15Choices ) / sizeof( wxString );
	m_comboBoxBit15 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit15NChoices, m_comboBoxBit15Choices, 0 );
	m_comboBoxBit15->SetSelection( 0 );
	gSizer8->Add( m_comboBoxBit15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit13Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit13NChoices = sizeof( m_comboBoxBit13Choices ) / sizeof( wxString );
	m_comboBoxBit13 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit13NChoices, m_comboBoxBit13Choices, 0 );
	m_comboBoxBit13->SetSelection( 0 );
	gSizer8->Add( m_comboBoxBit13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit11Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit11NChoices = sizeof( m_comboBoxBit11Choices ) / sizeof( wxString );
	m_comboBoxBit11 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit11NChoices, m_comboBoxBit11Choices, 0 );
	m_comboBoxBit11->SetSelection( 0 );
	gSizer8->Add( m_comboBoxBit11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit9Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit9NChoices = sizeof( m_comboBoxBit9Choices ) / sizeof( wxString );
	m_comboBoxBit9 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit9NChoices, m_comboBoxBit9Choices, 0 );
	m_comboBoxBit9->SetSelection( 0 );
	gSizer8->Add( m_comboBoxBit9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit14Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit14NChoices = sizeof( m_comboBoxBit14Choices ) / sizeof( wxString );
	m_comboBoxBit14 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit14NChoices, m_comboBoxBit14Choices, 0 );
	m_comboBoxBit14->SetSelection( 0 );
	gSizer8->Add( m_comboBoxBit14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit12Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit12NChoices = sizeof( m_comboBoxBit12Choices ) / sizeof( wxString );
	m_comboBoxBit12 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit12NChoices, m_comboBoxBit12Choices, 0 );
	m_comboBoxBit12->SetSelection( 0 );
	gSizer8->Add( m_comboBoxBit12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit10Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit10NChoices = sizeof( m_comboBoxBit10Choices ) / sizeof( wxString );
	m_comboBoxBit10 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit10NChoices, m_comboBoxBit10Choices, 0 );
	m_comboBoxBit10->SetSelection( 0 );
	gSizer8->Add( m_comboBoxBit10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit8Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit8NChoices = sizeof( m_comboBoxBit8Choices ) / sizeof( wxString );
	m_comboBoxBit8 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit8NChoices, m_comboBoxBit8Choices, 0 );
	m_comboBoxBit8->SetSelection( 1 );
	gSizer8->Add( m_comboBoxBit8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1502->Add( gSizer8, 1, wxEXPAND, 5 );


	bSizer811->Add( bSizer1502, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1513;
	bSizer1513 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer1451;
	bSizer1451 = new wxBoxSizer( wxVERTICAL );

	wxString m_choiceBit70Choices[] = { _("Custom"), _("All Zero"), _("All One"), _("All Any") };
	int m_choiceBit70NChoices = sizeof( m_choiceBit70Choices ) / sizeof( wxString );
	m_choiceBit70 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBit70NChoices, m_choiceBit70Choices, 0 );
	m_choiceBit70->SetSelection( 0 );
	bSizer1451->Add( m_choiceBit70, 0, wxALL, 5 );


	bSizer1513->Add( bSizer1451, 0, wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxGridSizer* gSizer9;
	gSizer9 = new wxGridSizer( 2, 4, 0, 0 );

	wxString m_comboBoxBit7Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit7NChoices = sizeof( m_comboBoxBit7Choices ) / sizeof( wxString );
	m_comboBoxBit7 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit7NChoices, m_comboBoxBit7Choices, 0 );
	m_comboBoxBit7->SetSelection( 0 );
	gSizer9->Add( m_comboBoxBit7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit5Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit5NChoices = sizeof( m_comboBoxBit5Choices ) / sizeof( wxString );
	m_comboBoxBit5 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit5NChoices, m_comboBoxBit5Choices, 0 );
	m_comboBoxBit5->SetSelection( 0 );
	gSizer9->Add( m_comboBoxBit5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit3Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit3NChoices = sizeof( m_comboBoxBit3Choices ) / sizeof( wxString );
	m_comboBoxBit3 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit3NChoices, m_comboBoxBit3Choices, 0 );
	m_comboBoxBit3->SetSelection( 0 );
	gSizer9->Add( m_comboBoxBit3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit1Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit1NChoices = sizeof( m_comboBoxBit1Choices ) / sizeof( wxString );
	m_comboBoxBit1 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit1NChoices, m_comboBoxBit1Choices, 0 );
	m_comboBoxBit1->SetSelection( 0 );
	gSizer9->Add( m_comboBoxBit1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit6Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit6NChoices = sizeof( m_comboBoxBit6Choices ) / sizeof( wxString );
	m_comboBoxBit6 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit6NChoices, m_comboBoxBit6Choices, 0 );
	m_comboBoxBit6->SetSelection( 0 );
	gSizer9->Add( m_comboBoxBit6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit4Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit4NChoices = sizeof( m_comboBoxBit4Choices ) / sizeof( wxString );
	m_comboBoxBit4 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit4NChoices, m_comboBoxBit4Choices, 0 );
	m_comboBoxBit4->SetSelection( 0 );
	gSizer9->Add( m_comboBoxBit4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit2Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit2NChoices = sizeof( m_comboBoxBit2Choices ) / sizeof( wxString );
	m_comboBoxBit2 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit2NChoices, m_comboBoxBit2Choices, 0 );
	m_comboBoxBit2->SetSelection( 0 );
	gSizer9->Add( m_comboBoxBit2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxBit0Choices[] = { _("0"), _("1"), _("rising"), _("falling"), _("X") };
	int m_comboBoxBit0NChoices = sizeof( m_comboBoxBit0Choices ) / sizeof( wxString );
	m_comboBoxBit0 = new wxChoice( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxBit0NChoices, m_comboBoxBit0Choices, 0 );
	m_comboBoxBit0->SetSelection( 0 );
	gSizer9->Add( m_comboBoxBit0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1513->Add( gSizer9, 1, wxEXPAND, 5 );


	bSizer811->Add( bSizer1513, 1, wxEXPAND, 5 );


	bSizer79->Add( bSizer811, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer78->Add( bSizer79, 4, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel13->SetSizer( bSizer78 );
	m_panel13->Layout();
	bSizer78->Fit( m_panel13 );
	m_notebook3->AddPage( m_panel13, _("Digital"), false );

	bSizer156->Add( m_notebook3, 4, wxEXPAND | wxALL, 5 );


	bSizer1671->Add( bSizer156, 12, wxEXPAND, 5 );

	m_staticline131 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1671->Add( m_staticline131, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer1571;
	bSizer1571 = new wxBoxSizer( wxHORIZONTAL );

	m_gauge1 = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	m_gauge1->SetValue( 0 );
	bSizer1571->Add( m_gauge1, 1, wxALIGN_CENTER_VERTICAL|wxALL|wxEXPAND, 5 );


	bSizer1671->Add( bSizer1571, 1, wxEXPAND, 5 );

	m_staticline19 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer1671->Add( m_staticline19, 0, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer1671, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	bSizer1->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( Osciloskop::onActivate ) );
	this->Connect( wxEVT_ACTIVATE_APP, wxActivateEventHandler( Osciloskop::onActivateApp ) );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Osciloskop::onClose ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( Osciloskop::OnIdle ) );
	this->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( Osciloskop::OnSetFocus ) );
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( Osciloskop::OnSize ) );
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem1OnMenuSelection ), this, m_menuItem1->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem2OnMenuSelection ), this, m_menuItem2->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemConvertToTextOnMenuSelection ), this, m_menuItemConvertToText->GetId());
	m_menu1->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem3OnMenuSelection ), this, m_menuItem3->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem20OnMenuSelection ), this, m_menuItem20->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem21OnMenuSelection ), this, m_menuItem21->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem22OnMenuSelection ), this, m_menuItem22->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem23OnMenuSelection ), this, m_menuItem23->GetId());
	m_menu2->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem6OnMenuSelection ), this, m_menuItem6->GetId());
	m_menu3->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem8OnMenuSelection ), this, m_menuItem8->GetId());
	m_menu3->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem9OnMenuSelection ), this, m_menuItem9->GetId());
	m_menu3->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemStorageOnMenuSelection ), this, m_menuItemStorage->GetId());
	m_menu3->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemConnectionOnMenuSelection ), this, m_menuItemConnection->GetId());
	m_menu4->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemSoftwareOnMenuSelection ), this, m_menuItemSoftware->GetId());
	m_menu4->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem11OnMenuSelection ), this, m_menuItem11->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemReadEEPROMOnMenuSelection ), this, m_menuItemReadEEPROM->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemWriteEEPROMOnMenuSelection ), this, m_menuItemWriteEEPROM->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem12OnMenuSelection ), this, m_menuItem12->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemWriteCallibrateOnMenuSelection ), this, m_menuItemWriteCallibrate->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemReadCallibrateOnMenuSelection ), this, m_menuItemReadCallibrate->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemWriteCertificateOnMenuSelection ), this, m_menuItemWriteCertificate->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemReadCertificateOnMenuSelection ), this, m_menuItemReadCertificate->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemLockCertificateOnMenuSelection ), this, m_menuItemLockCertificate->GetId());
	m_menu5->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemResetEEPROMOnMenuSelection ), this, m_menuItemResetEEPROM->GetId());
	m_menu8->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItem15OnMenuSelection ), this, m_menuItem15->GetId());
	m_menu9->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemSlot1OnMenuSelection ), this, m_menuItemSlot1->GetId());
	m_menu9->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemSlot2OnMenuSelection ), this, m_menuItemSlot2->GetId());
	m_menu9->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemSlot3OnMenuSelection ), this, m_menuItemSlot3->GetId());
	m_menu9->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemSlot4OnMenuSelection ), this, m_menuItemSlot4->GetId());
	m_menu9->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemLoadOnMenuSelection ), this, m_menuItemLoad->GetId());
	m_menu9->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemSaveFileOnMenuSelection ), this, m_menuItemSaveFile->GetId());
	m_menu9->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemResetToDefaultOnMenuSelection ), this, m_menuItemResetToDefault->GetId());
	m_menu10->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemClipboardCurrentOnMenuSelection ), this, m_menuItemClipboardCurrent->GetId());
	m_menu10->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemClipboardAllOnMenuSelection ), this, m_menuItemClipboardAll->GetId());
	m_menu11->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemVersion1OnMenuSelection ), this, m_menuItemVersion1->GetId());
	m_menu11->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemVersion2OnMenuSelection ), this, m_menuItemVersion2->GetId());
	m_menu7->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemDebugOnMenuSelection ), this, m_menuItemDebug->GetId());
	m_menu7->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemTestsOnMenuSelection ), this, m_menuItemTests->GetId());
	m_menu7->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Osciloskop::m_menuItemInfoOnMenuSelection ), this, m_menuItemInfo->GetId());
	m_buttonConnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonConnectOnButtonClick ), NULL, this );
	m_buttonDisconnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonDisconnectOnButtonClick ), NULL, this );
	m_buttonFirmwareUpload->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonFirmwareUploadOnButtonClick ), NULL, this );
	m_buttonUndo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonUndoOnButtonClick ), NULL, this );
	m_buttonRedo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonRedoOnButtonClick ), NULL, this );
	m_choiceSpeed->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceSpeedOnChoice ), NULL, this );
	m_comboBoxTimeControl->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTimeControlOnCombobox ), NULL, this );
	m_comboBoxTimeCapture->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTimeCaptureOnCombobox ), NULL, this );
	m_checkBoxETS->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxETSOnCheckBox ), NULL, this );
	m_textCtrlTimeDisplay->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimeDisplayOnTextEnter ), NULL, this );
	m_comboBoxTimeDisplay->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTimeDisplayOnCombobox ), NULL, this );
	m_checkBoxFull->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxFullOnCheckBox ), NULL, this );
	m_textCtrlTimePosition->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimePositionOnTextEnter ), NULL, this );
	m_spinBtnXPos->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnXPosOnSpinDown ), NULL, this );
	m_spinBtnXPos->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnXPosOnSpinUp ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_textCtrlTimeFrame->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimeFrameOnTextEnter ), NULL, this );
	m_spinBtnFrameHistory->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnFrameHistoryOnSpinDown ), NULL, this );
	m_spinBtnFrameHistory->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnFrameHistoryOnSpinUp ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_buttonPlay->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonPlayOnButtonClick ), NULL, this );
	m_buttonPause->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonPauseOnButtonClick ), NULL, this );
	m_buttonCapture->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonCaptureOnButtonClick ), NULL, this );
	m_buttonSimulate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonSimulateOnButtonClick ), NULL, this );
	m_buttonClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonClearOnButtonClick ), NULL, this );
	m_textCtrlTimeFrameSize->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimeFrameSizeOnTextEnter ), NULL, this );
	m_textCtrlTimeFFTSize->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimeFFTSizeOnTextEnter ), NULL, this );
	m_comboBoxCh0Capture->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxCh0CaptureOnCombobox ), NULL, this );
	m_textCtrlCh0Scale->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh0ScaleOnTextEnter ), NULL, this );
	m_checkBoxCh0Invert->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxCh0InvertOnCheckBox ), NULL, this );
	m_checkBoxCh0Ground->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxCh0GroundOnCheckBox ), NULL, this );
	m_choiceCh0ACDC->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceCh0ACDCOnChoice ), NULL, this );
	m_textCtrlCh0Display->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh0DisplayOnTextEnter ), NULL, this );
	m_comboBoxCh0Display->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxCh0DisplayOnCombobox ), NULL, this );
	m_checkBoxSignal1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxSignal1OnCheckBox ), NULL, this );
	m_checkBoxFFT1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxFFT1OnCheckBox ), NULL, this );
	m_checkBoxAvg01->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxAvg01OnCheckBox ), NULL, this );
	m_textCtrlCh0Position->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh0PositionOnTextEnter ), NULL, this );
	m_spinBtnCh0YPos->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnCh0YPosOnSpinDown ), NULL, this );
	m_spinBtnCh0YPos->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnCh0YPosOnSpinUp ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_comboBoxCh1Capture->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxCh1CaptureOnCombobox ), NULL, this );
	m_textCtrlCh1Scale->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh1ScaleOnTextEnter ), NULL, this );
	m_checkBoxCh1Invert->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxCh1InvertOnCheckBox ), NULL, this );
	m_checkBoxCh1Ground->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxCh1GroundOnCheckBox ), NULL, this );
	m_choiceCh1ACDC->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceCh1ACDCOnChoice ), NULL, this );
	m_textCtrlCh1Display->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh1DisplayOnTextEnter ), NULL, this );
	m_comboBoxCh1Display->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxCh1DisplayOnCombobox ), NULL, this );
	m_checkBoxSignal2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxSignal2OnCheckBox ), NULL, this );
	m_checkBoxFFT2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxFFT2OnCheckBox ), NULL, this );
	m_checkBoxAvg02->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxAvg02OnCheckBox ), NULL, this );
	m_textCtrlCh1Position->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh1PositionOnTextEnter ), NULL, this );
	m_spinBtnCh1YPos->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnCh1YPosOnSpinDown ), NULL, this );
	m_spinBtnCh1YPos->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnCh1YPosOnSpinUp ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_comboBoxFunction->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxFunctionTypeOnChoice ), NULL, this );
	m_textCtrlFuncCustom->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlFuncCustomOnTextEnter ), NULL, this );
	m_checkBoxXYVoltageGraph->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxXYVoltageGraphOnCheckBox ), NULL, this );
	m_checkBoxSignalF->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxSignalFOnCheckBox ), NULL, this );
	m_checkBoxFFTF->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxFFTFOnCheckBox ), NULL, this );
	m_choiceDOnOff815->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceDOnOff815OnChoice ), NULL, this );
	m_checkBox16->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox16OnCheckBox ), NULL, this );
	m_checkBox14->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox14OnCheckBox ), NULL, this );
	m_checkBox12->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox12OnCheckBox ), NULL, this );
	m_checkBox10->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox10OnCheckBox ), NULL, this );
	m_checkBox15->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox15OnCheckBox ), NULL, this );
	m_checkBox13->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox13OnCheckBox ), NULL, this );
	m_checkBox11->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox11OnCheckBox ), NULL, this );
	m_checkBox9->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox9OnCheckBox ), NULL, this );
	m_choiceDOnOff70->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceDOnOff70OnChoice ), NULL, this );
	m_checkBox8->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox8OnCheckBox ), NULL, this );
	m_checkBox6->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox6OnCheckBox ), NULL, this );
	m_checkBox4->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox4OnCheckBox ), NULL, this );
	m_checkBox2->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox2OnCheckBox ), NULL, this );
	m_checkBox7->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox7OnCheckBox ), NULL, this );
	m_checkBox5->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox5OnCheckBox ), NULL, this );
	m_checkBox3->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox3OnCheckBox ), NULL, this );
	m_checkBox1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox1OnCheckBox ), NULL, this );
	m_choiceBit15->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit15OnChoice ), NULL, this );
	m_choiceBit13->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit13OnChoice ), NULL, this );
	m_choiceBit11->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit11OnChoice ), NULL, this );
	m_choiceBit9->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit9OnChoice ), NULL, this );
	m_choiceBit14->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit14OnChoice ), NULL, this );
	m_choiceBit12->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit12OnChoice ), NULL, this );
	m_choiceBit10->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit10OnChoice ), NULL, this );
	m_choiceBit8->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit8OnChoice ), NULL, this );
	m_choiceDS815->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceDS815OnChoice ), NULL, this );
	m_choiceInputOutput->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceInputOutputOnChoice ), NULL, this );
	m_choiceBit7->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit7OnChoice ), NULL, this );
	m_choiceBit5->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit5OnChoice ), NULL, this );
	m_choiceBit3->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit3OnChoice ), NULL, this );
	m_choiceBit1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit1OnChoice ), NULL, this );
	m_choiceBit6->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit6OnChoice ), NULL, this );
	m_choiceBit4->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit4OnChoice ), NULL, this );
	m_choiceBit2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit2OnChoice ), NULL, this );
	m_choiceBit0->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit0OnChoice ), NULL, this );
	m_choiceDS70->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceDS70OnChoice ), NULL, this );
	m_choiceInputOutput1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceInputOutput1OnChoice ), NULL, this );
	m_filePicker1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Osciloskop::m_filePicker1OnFileChanged ), NULL, this );
	m_buttonCustomFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonCustomFileOnButtonClick ), NULL, this );
	m_textCtrlDigitalVoltage->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlDigitalVoltageOnTextEnter ), NULL, this );
	m_spinBtnDigVoltage->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnDigVoltageOnSpinDown ), NULL, this );
	m_spinBtnDigVoltage->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnDigVoltageOnSpinUp ), NULL, this );
	m_textCtrlFreqDivider->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlFreqDividerOnTextEnter ), NULL, this );
	m_comboBoxTrigger->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTriggerOnCombobox ), NULL, this );
	m_comboBoxTriggerSource->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTriggerSourceOnCombobox ), NULL, this );
	m_comboBoxTriggerSlope->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTriggerSlopeOnCombobox ), NULL, this );
	m_buttonReArm->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonReArmOnButtonClick ), NULL, this );
	m_textCtrlTriggerLevel->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTriggerLevelOnTextEnter ), NULL, this );
	m_spinBtnTrigLevel->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnTrigLevelOnSpinDown ), NULL, this );
	m_spinBtnTrigLevel->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnTrigLevelOnSpinUp ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_textCtrlTriggerHisteresis->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTriggerHisteresisOnTextEnter ), NULL, this );
	m_spinBtnTrigHis->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnTrigHisOnSpinDown ), NULL, this );
	m_spinBtnTrigHis->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnTrigHisOnSpinUp ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_textCtrlTriggerPre->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTriggerPreOnTextEnter ), NULL, this );
	m_spinBtnTrigPre->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnTrigPreOnSpinDown ), NULL, this );
	m_spinBtnTrigPre->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnTrigPreOnSpinUp ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_textCtrlTriggerHoldoff->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTriggerHoldoffOnTextEnter ), NULL, this );
	m_spinBtnTrigHoldoff->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnTrigHoldoffOnSpinDown ), NULL, this );
	m_spinBtnTrigHoldoff->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnTrigHoldoffOnSpinUp ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_comboBoxDigitalStage->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxDigitalStageOnCombobox ), NULL, this );
	m_textCtrDigitallDelay->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrDigitallDelayOnTextEnter ), NULL, this );
	m_comboBoxDigitalStageStart->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxDigitalStageStartOnCombobox ), NULL, this );
	m_comboBoxDigitalMode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxDigitalModeOnCombobox ), NULL, this );
	m_comboBoxDigitalSerialChannel->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxDigitalSerialChannelOnCombobox ), NULL, this );
	m_choiceBit158->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit158OnChoice ), NULL, this );
	m_comboBoxBit15->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit15OnCombobox ), NULL, this );
	m_comboBoxBit13->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit13OnCombobox ), NULL, this );
	m_comboBoxBit11->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit11OnCombobox ), NULL, this );
	m_comboBoxBit9->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit9OnCombobox ), NULL, this );
	m_comboBoxBit14->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit14OnCombobox ), NULL, this );
	m_comboBoxBit12->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit12OnCombobox ), NULL, this );
	m_comboBoxBit10->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit10OnCombobox ), NULL, this );
	m_comboBoxBit8->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit8OnCombobox ), NULL, this );
	m_choiceBit70->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit70OnChoice ), NULL, this );
	m_comboBoxBit7->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit7OnCombobox ), NULL, this );
	m_comboBoxBit5->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit5OnCombobox ), NULL, this );
	m_comboBoxBit3->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit3OnCombobox ), NULL, this );
	m_comboBoxBit1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit1OnCombobox ), NULL, this );
	m_comboBoxBit6->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit6OnCombobox ), NULL, this );
	m_comboBoxBit4->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit4OnCombobox ), NULL, this );
	m_comboBoxBit2->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit2OnCombobox ), NULL, this );
	m_comboBoxBit0->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit0OnCombobox ), NULL, this );
}

Osciloskop::~Osciloskop()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( Osciloskop::onActivate ) );
	this->Disconnect( wxEVT_ACTIVATE_APP, wxActivateEventHandler( Osciloskop::onActivateApp ) );
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Osciloskop::onClose ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( Osciloskop::OnIdle ) );
	this->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( Osciloskop::OnSetFocus ) );
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( Osciloskop::OnSize ) );
	m_buttonConnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonConnectOnButtonClick ), NULL, this );
	m_buttonDisconnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonDisconnectOnButtonClick ), NULL, this );
	m_buttonFirmwareUpload->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonFirmwareUploadOnButtonClick ), NULL, this );
	m_buttonUndo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonUndoOnButtonClick ), NULL, this );
	m_buttonRedo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonRedoOnButtonClick ), NULL, this );
	m_choiceSpeed->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceSpeedOnChoice ), NULL, this );
	m_comboBoxTimeControl->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTimeControlOnCombobox ), NULL, this );
	m_comboBoxTimeCapture->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTimeCaptureOnCombobox ), NULL, this );
	m_checkBoxETS->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxETSOnCheckBox ), NULL, this );
	m_textCtrlTimeDisplay->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimeDisplayOnTextEnter ), NULL, this );
	m_comboBoxTimeDisplay->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTimeDisplayOnCombobox ), NULL, this );
	m_checkBoxFull->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxFullOnCheckBox ), NULL, this );
	m_textCtrlTimePosition->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimePositionOnTextEnter ), NULL, this );
	m_spinBtnXPos->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnXPosOnSpinDown ), NULL, this );
	m_spinBtnXPos->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnXPosOnSpinUp ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_sliderTimePosition->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTimePositionOnScroll ), NULL, this );
	m_textCtrlTimeFrame->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimeFrameOnTextEnter ), NULL, this );
	m_spinBtnFrameHistory->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnFrameHistoryOnSpinDown ), NULL, this );
	m_spinBtnFrameHistory->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnFrameHistoryOnSpinUp ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_sliderTimeFrame->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTimeFrameOnScroll ), NULL, this );
	m_buttonPlay->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonPlayOnButtonClick ), NULL, this );
	m_buttonPause->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonPauseOnButtonClick ), NULL, this );
	m_buttonCapture->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonCaptureOnButtonClick ), NULL, this );
	m_buttonSimulate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonSimulateOnButtonClick ), NULL, this );
	m_buttonClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonClearOnButtonClick ), NULL, this );
	m_textCtrlTimeFrameSize->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimeFrameSizeOnTextEnter ), NULL, this );
	m_textCtrlTimeFFTSize->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTimeFFTSizeOnTextEnter ), NULL, this );
	m_comboBoxCh0Capture->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxCh0CaptureOnCombobox ), NULL, this );
	m_textCtrlCh0Scale->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh0ScaleOnTextEnter ), NULL, this );
	m_checkBoxCh0Invert->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxCh0InvertOnCheckBox ), NULL, this );
	m_checkBoxCh0Ground->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxCh0GroundOnCheckBox ), NULL, this );
	m_choiceCh0ACDC->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceCh0ACDCOnChoice ), NULL, this );
	m_textCtrlCh0Display->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh0DisplayOnTextEnter ), NULL, this );
	m_comboBoxCh0Display->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxCh0DisplayOnCombobox ), NULL, this );
	m_checkBoxSignal1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxSignal1OnCheckBox ), NULL, this );
	m_checkBoxFFT1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxFFT1OnCheckBox ), NULL, this );
	m_checkBoxAvg01->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxAvg01OnCheckBox ), NULL, this );
	m_textCtrlCh0Position->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh0PositionOnTextEnter ), NULL, this );
	m_spinBtnCh0YPos->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnCh0YPosOnSpinDown ), NULL, this );
	m_spinBtnCh0YPos->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnCh0YPosOnSpinUp ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_sliderCh0Position->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderCh0PositionOnScroll ), NULL, this );
	m_comboBoxCh1Capture->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxCh1CaptureOnCombobox ), NULL, this );
	m_textCtrlCh1Scale->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh1ScaleOnTextEnter ), NULL, this );
	m_checkBoxCh1Invert->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxCh1InvertOnCheckBox ), NULL, this );
	m_checkBoxCh1Ground->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxCh1GroundOnCheckBox ), NULL, this );
	m_choiceCh1ACDC->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceCh1ACDCOnChoice ), NULL, this );
	m_textCtrlCh1Display->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh1DisplayOnTextEnter ), NULL, this );
	m_comboBoxCh1Display->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxCh1DisplayOnCombobox ), NULL, this );
	m_checkBoxSignal2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxSignal2OnCheckBox ), NULL, this );
	m_checkBoxFFT2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxFFT2OnCheckBox ), NULL, this );
	m_checkBoxAvg02->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxAvg02OnCheckBox ), NULL, this );
	m_textCtrlCh1Position->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlCh1PositionOnTextEnter ), NULL, this );
	m_spinBtnCh1YPos->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnCh1YPosOnSpinDown ), NULL, this );
	m_spinBtnCh1YPos->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnCh1YPosOnSpinUp ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_sliderCh1Position->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderCh1PositionOnScroll ), NULL, this );
	m_comboBoxFunction->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxFunctionTypeOnChoice ), NULL, this );
	m_textCtrlFuncCustom->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlFuncCustomOnTextEnter ), NULL, this );
	m_checkBoxXYVoltageGraph->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxXYVoltageGraphOnCheckBox ), NULL, this );
	m_checkBoxSignalF->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxSignalFOnCheckBox ), NULL, this );
	m_checkBoxFFTF->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBoxFFTFOnCheckBox ), NULL, this );
	m_choiceDOnOff815->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceDOnOff815OnChoice ), NULL, this );
	m_checkBox16->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox16OnCheckBox ), NULL, this );
	m_checkBox14->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox14OnCheckBox ), NULL, this );
	m_checkBox12->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox12OnCheckBox ), NULL, this );
	m_checkBox10->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox10OnCheckBox ), NULL, this );
	m_checkBox15->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox15OnCheckBox ), NULL, this );
	m_checkBox13->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox13OnCheckBox ), NULL, this );
	m_checkBox11->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox11OnCheckBox ), NULL, this );
	m_checkBox9->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox9OnCheckBox ), NULL, this );
	m_choiceDOnOff70->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceDOnOff70OnChoice ), NULL, this );
	m_checkBox8->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox8OnCheckBox ), NULL, this );
	m_checkBox6->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox6OnCheckBox ), NULL, this );
	m_checkBox4->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox4OnCheckBox ), NULL, this );
	m_checkBox2->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox2OnCheckBox ), NULL, this );
	m_checkBox7->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox7OnCheckBox ), NULL, this );
	m_checkBox5->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox5OnCheckBox ), NULL, this );
	m_checkBox3->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox3OnCheckBox ), NULL, this );
	m_checkBox1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Osciloskop::m_checkBox1OnCheckBox ), NULL, this );
	m_choiceBit15->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit15OnChoice ), NULL, this );
	m_choiceBit13->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit13OnChoice ), NULL, this );
	m_choiceBit11->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit11OnChoice ), NULL, this );
	m_choiceBit9->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit9OnChoice ), NULL, this );
	m_choiceBit14->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit14OnChoice ), NULL, this );
	m_choiceBit12->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit12OnChoice ), NULL, this );
	m_choiceBit10->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit10OnChoice ), NULL, this );
	m_choiceBit8->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit8OnChoice ), NULL, this );
	m_choiceDS815->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceDS815OnChoice ), NULL, this );
	m_choiceInputOutput->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceInputOutputOnChoice ), NULL, this );
	m_choiceBit7->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit7OnChoice ), NULL, this );
	m_choiceBit5->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit5OnChoice ), NULL, this );
	m_choiceBit3->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit3OnChoice ), NULL, this );
	m_choiceBit1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit1OnChoice ), NULL, this );
	m_choiceBit6->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit6OnChoice ), NULL, this );
	m_choiceBit4->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit4OnChoice ), NULL, this );
	m_choiceBit2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit2OnChoice ), NULL, this );
	m_choiceBit0->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit0OnChoice ), NULL, this );
	m_choiceDS70->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceDS70OnChoice ), NULL, this );
	m_choiceInputOutput1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceInputOutput1OnChoice ), NULL, this );
	m_filePicker1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( Osciloskop::m_filePicker1OnFileChanged ), NULL, this );
	m_buttonCustomFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonCustomFileOnButtonClick ), NULL, this );
	m_textCtrlDigitalVoltage->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlDigitalVoltageOnTextEnter ), NULL, this );
	m_spinBtnDigVoltage->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnDigVoltageOnSpinDown ), NULL, this );
	m_spinBtnDigVoltage->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnDigVoltageOnSpinUp ), NULL, this );
	m_textCtrlFreqDivider->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlFreqDividerOnTextEnter ), NULL, this );
	m_comboBoxTrigger->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTriggerOnCombobox ), NULL, this );
	m_comboBoxTriggerSource->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTriggerSourceOnCombobox ), NULL, this );
	m_comboBoxTriggerSlope->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxTriggerSlopeOnCombobox ), NULL, this );
	m_buttonReArm->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Osciloskop::m_buttonReArmOnButtonClick ), NULL, this );
	m_textCtrlTriggerLevel->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTriggerLevelOnTextEnter ), NULL, this );
	m_spinBtnTrigLevel->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnTrigLevelOnSpinDown ), NULL, this );
	m_spinBtnTrigLevel->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnTrigLevelOnSpinUp ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_sliderTriggerLevel->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTriggerLevelOnScroll ), NULL, this );
	m_textCtrlTriggerHisteresis->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTriggerHisteresisOnTextEnter ), NULL, this );
	m_spinBtnTrigHis->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnTrigHisOnSpinDown ), NULL, this );
	m_spinBtnTrigHis->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnTrigHisOnSpinUp ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_sliderTriggerHisteresis->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTriggerHisteresisOnScroll ), NULL, this );
	m_textCtrlTriggerPre->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTriggerPreOnTextEnter ), NULL, this );
	m_spinBtnTrigPre->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnTrigPreOnSpinDown ), NULL, this );
	m_spinBtnTrigPre->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnTrigPreOnSpinUp ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_sliderTriggerPre->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTriggerPreOnScroll ), NULL, this );
	m_textCtrlTriggerHoldoff->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrlTriggerHoldoffOnTextEnter ), NULL, this );
	m_spinBtnTrigHoldoff->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Osciloskop::m_spinBtnTrigHoldoffOnSpinDown ), NULL, this );
	m_spinBtnTrigHoldoff->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Osciloskop::m_spinBtnTrigHoldoffOnSpinUp ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_sliderTriggerHoldoff->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Osciloskop::m_sliderTriggerHoldoffOnScroll ), NULL, this );
	m_comboBoxDigitalStage->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxDigitalStageOnCombobox ), NULL, this );
	m_textCtrDigitallDelay->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Osciloskop::m_textCtrDigitallDelayOnTextEnter ), NULL, this );
	m_comboBoxDigitalStageStart->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxDigitalStageStartOnCombobox ), NULL, this );
	m_comboBoxDigitalMode->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxDigitalModeOnCombobox ), NULL, this );
	m_comboBoxDigitalSerialChannel->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxDigitalSerialChannelOnCombobox ), NULL, this );
	m_choiceBit158->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit158OnChoice ), NULL, this );
	m_comboBoxBit15->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit15OnCombobox ), NULL, this );
	m_comboBoxBit13->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit13OnCombobox ), NULL, this );
	m_comboBoxBit11->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit11OnCombobox ), NULL, this );
	m_comboBoxBit9->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit9OnCombobox ), NULL, this );
	m_comboBoxBit14->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit14OnCombobox ), NULL, this );
	m_comboBoxBit12->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit12OnCombobox ), NULL, this );
	m_comboBoxBit10->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit10OnCombobox ), NULL, this );
	m_comboBoxBit8->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit8OnCombobox ), NULL, this );
	m_choiceBit70->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_choiceBit70OnChoice ), NULL, this );
	m_comboBoxBit7->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit7OnCombobox ), NULL, this );
	m_comboBoxBit5->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit5OnCombobox ), NULL, this );
	m_comboBoxBit3->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit3OnCombobox ), NULL, this );
	m_comboBoxBit1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit1OnCombobox ), NULL, this );
	m_comboBoxBit6->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit6OnCombobox ), NULL, this );
	m_comboBoxBit4->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit4OnCombobox ), NULL, this );
	m_comboBoxBit2->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit2OnCombobox ), NULL, this );
	m_comboBoxBit0->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Osciloskop::m_comboBoxBit0OnCombobox ), NULL, this );

}

SoftwareGenerator::SoftwareGenerator( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );

	m_notebook3 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH );
	m_panel14 = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4311;
	bSizer4311 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4411;
	bSizer4411 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3911 = new wxStaticText( m_panel14, wxID_ANY, _("Type:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText3911->Wrap( -1 );
	m_staticText3911->SetMinSize( wxSize( 100,-1 ) );

	bSizer4411->Add( m_staticText3911, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxType0Choices[] = { _("sinus"), _("cosinus"), _("increment"), _("decrement"), _("constant"), _("random"), _("square"), _("delta") };
	int m_comboBoxType0NChoices = sizeof( m_comboBoxType0Choices ) / sizeof( wxString );
	m_comboBoxType0 = new wxChoice( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxType0NChoices, m_comboBoxType0Choices, 0 );
	m_comboBoxType0->SetSelection( 0 );
	bSizer4411->Add( m_comboBoxType0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4311->Add( bSizer4411, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4521;
	bSizer4521 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4021 = new wxStaticText( m_panel14, wxID_ANY, _("Period:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText4021->Wrap( -1 );
	m_staticText4021->SetMinSize( wxSize( 100,-1 ) );

	bSizer4521->Add( m_staticText4021, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlPeriod0 = new wxTextCtrl( m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer4521->Add( m_textCtrlPeriod0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxPeriod0Choices[] = { _("second"), _("mili second"), _("micro second"), _("nano second") };
	int m_comboBoxPeriod0NChoices = sizeof( m_comboBoxPeriod0Choices ) / sizeof( wxString );
	m_comboBoxPeriod0 = new wxChoice( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxPeriod0NChoices, m_comboBoxPeriod0Choices, 0 );
	m_comboBoxPeriod0->SetSelection( 0 );
	bSizer4521->Add( m_comboBoxPeriod0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4311->Add( bSizer4521, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer45121;
	bSizer45121 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText40121 = new wxStaticText( m_panel14, wxID_ANY, _("Peek to Peak:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText40121->Wrap( -1 );
	m_staticText40121->SetMinSize( wxSize( 100,-1 ) );

	bSizer45121->Add( m_staticText40121, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlPeek0 = new wxTextCtrl( m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer45121->Add( m_textCtrlPeek0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxPeek0Choices[] = { _("volt"), _("mili volt"), _("micro volt"), _("nano volt") };
	int m_comboBoxPeek0NChoices = sizeof( m_comboBoxPeek0Choices ) / sizeof( wxString );
	m_comboBoxPeek0 = new wxChoice( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxPeek0NChoices, m_comboBoxPeek0Choices, 0 );
	m_comboBoxPeek0->SetSelection( 0 );
	bSizer45121->Add( m_comboBoxPeek0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4311->Add( bSizer45121, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer451131;
	bSizer451131 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText401121 = new wxStaticText( m_panel14, wxID_ANY, _("Speed:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText401121->Wrap( -1 );
	m_staticText401121->SetMinSize( wxSize( 100,-1 ) );

	bSizer451131->Add( m_staticText401121, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlSpeed0 = new wxTextCtrl( m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer451131->Add( m_textCtrlSpeed0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer451131->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer4311->Add( bSizer451131, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4511111;
	bSizer4511111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4011111 = new wxStaticText( m_panel14, wxID_ANY, _("Avery:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText4011111->Wrap( -1 );
	m_staticText4011111->SetMinSize( wxSize( 100,-1 ) );

	bSizer4511111->Add( m_staticText4011111, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlAvery0 = new wxTextCtrl( m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer4511111->Add( m_textCtrlAvery0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4511111->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer4311->Add( bSizer4511111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4511211;
	bSizer4511211 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOn0 = new wxButton( m_panel14, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4511211->Add( m_buttonOn0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonOff0 = new wxButton( m_panel14, wxID_ANY, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4511211->Add( m_buttonOff0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4311->Add( bSizer4511211, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel14->SetSizer( bSizer4311 );
	m_panel14->Layout();
	bSizer4311->Fit( m_panel14 );
	m_notebook3->AddPage( m_panel14, _("Channel 1"), true );
	m_panel15 = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer43111;
	bSizer43111 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer44111;
	bSizer44111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText39111 = new wxStaticText( m_panel15, wxID_ANY, _("Type:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText39111->Wrap( -1 );
	m_staticText39111->SetMinSize( wxSize( 100,-1 ) );

	bSizer44111->Add( m_staticText39111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxType1Choices[] = { _("sinus"), _("cosinus"), _("increment"), _("decrement"), _("constant"), _("random"), _("square"), _("delta") };
	int m_comboBoxType1NChoices = sizeof( m_comboBoxType1Choices ) / sizeof( wxString );
	m_comboBoxType1 = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxType1NChoices, m_comboBoxType1Choices, 0 );
	m_comboBoxType1->SetSelection( 0 );
	bSizer44111->Add( m_comboBoxType1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer43111->Add( bSizer44111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer45211;
	bSizer45211 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText40211 = new wxStaticText( m_panel15, wxID_ANY, _("Period:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText40211->Wrap( -1 );
	m_staticText40211->SetMinSize( wxSize( 100,-1 ) );

	bSizer45211->Add( m_staticText40211, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlPeriod1 = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer45211->Add( m_textCtrlPeriod1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxPeriod1Choices[] = { _("second"), _("mili second"), _("micro second"), _("nano second") };
	int m_comboBoxPeriod1NChoices = sizeof( m_comboBoxPeriod1Choices ) / sizeof( wxString );
	m_comboBoxPeriod1 = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxPeriod1NChoices, m_comboBoxPeriod1Choices, 0 );
	m_comboBoxPeriod1->SetSelection( 0 );
	bSizer45211->Add( m_comboBoxPeriod1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer43111->Add( bSizer45211, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer451211;
	bSizer451211 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText401211 = new wxStaticText( m_panel15, wxID_ANY, _("Peek to Peak:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText401211->Wrap( -1 );
	m_staticText401211->SetMinSize( wxSize( 100,-1 ) );

	bSizer451211->Add( m_staticText401211, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlPeek1 = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer451211->Add( m_textCtrlPeek1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxPeek1Choices[] = { _("volt"), _("mili volt"), _("micro volt"), _("nano volt") };
	int m_comboBoxPeek1NChoices = sizeof( m_comboBoxPeek1Choices ) / sizeof( wxString );
	m_comboBoxPeek1 = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxPeek1NChoices, m_comboBoxPeek1Choices, 0 );
	m_comboBoxPeek1->SetSelection( 0 );
	bSizer451211->Add( m_comboBoxPeek1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer43111->Add( bSizer451211, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer4511311;
	bSizer4511311 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText4011211 = new wxStaticText( m_panel15, wxID_ANY, _("Speed:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText4011211->Wrap( -1 );
	m_staticText4011211->SetMinSize( wxSize( 100,-1 ) );

	bSizer4511311->Add( m_staticText4011211, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlSpeed1 = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer4511311->Add( m_textCtrlSpeed1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4511311->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer43111->Add( bSizer4511311, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer45111111;
	bSizer45111111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText40111111 = new wxStaticText( m_panel15, wxID_ANY, _("Avery:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText40111111->Wrap( -1 );
	m_staticText40111111->SetMinSize( wxSize( 100,-1 ) );

	bSizer45111111->Add( m_staticText40111111, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlAvery1 = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer45111111->Add( m_textCtrlAvery1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer45111111->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer43111->Add( bSizer45111111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer45112111;
	bSizer45112111 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOn1 = new wxButton( m_panel15, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer45112111->Add( m_buttonOn1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonOff1 = new wxButton( m_panel15, wxID_ANY, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer45112111->Add( m_buttonOff1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer43111->Add( bSizer45112111, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel15->SetSizer( bSizer43111 );
	m_panel15->Layout();
	bSizer43111->Fit( m_panel15 );
	m_notebook3->AddPage( m_panel15, _("Channel 2"), false );

	bSizer38->Add( m_notebook3, 1, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOk = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( m_buttonOk, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonDefault = new wxButton( this, wxID_ANY, _("Default"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( m_buttonDefault, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( m_buttonCancel, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer38->Add( bSizer42, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer38 );
	this->Layout();
	bSizer38->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( SoftwareGenerator::SoftwareGeneratorOnInitDialog ) );
	m_comboBoxType0->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxType0OnCombobox ), NULL, this );
	m_textCtrlPeriod0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlPeriod0OnTextEnter ), NULL, this );
	m_comboBoxPeriod0->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxPeriod0OnCombobox ), NULL, this );
	m_textCtrlPeek0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlPeek0OnTextEnter ), NULL, this );
	m_comboBoxPeek0->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxPeek0OnCombobox ), NULL, this );
	m_textCtrlSpeed0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlSpeed0OnTextEnter ), NULL, this );
	m_textCtrlAvery0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlAvery0OnTextEnter ), NULL, this );
	m_buttonOn0->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOn0OnButtonClick ), NULL, this );
	m_buttonOff0->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOff0OnButtonClick ), NULL, this );
	m_comboBoxType1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxType1OnCombobox ), NULL, this );
	m_textCtrlPeriod1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlPeriod1OnTextEnter ), NULL, this );
	m_comboBoxPeriod1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxPeriod1OnCombobox ), NULL, this );
	m_textCtrlPeek1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlPeek1OnTextEnter ), NULL, this );
	m_comboBoxPeek1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxPeek1OnCombobox ), NULL, this );
	m_textCtrlSpeed1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlSpeed1OnTextEnter ), NULL, this );
	m_textCtrlAvery1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlAvery1OnTextEnter ), NULL, this );
	m_buttonOn1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOn1OnButtonClick ), NULL, this );
	m_buttonOff1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOff1OnButtonClick ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonCancelOnButtonClick ), NULL, this );
}

SoftwareGenerator::~SoftwareGenerator()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( SoftwareGenerator::SoftwareGeneratorOnInitDialog ) );
	m_comboBoxType0->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxType0OnCombobox ), NULL, this );
	m_textCtrlPeriod0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlPeriod0OnTextEnter ), NULL, this );
	m_comboBoxPeriod0->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxPeriod0OnCombobox ), NULL, this );
	m_textCtrlPeek0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlPeek0OnTextEnter ), NULL, this );
	m_comboBoxPeek0->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxPeek0OnCombobox ), NULL, this );
	m_textCtrlSpeed0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlSpeed0OnTextEnter ), NULL, this );
	m_textCtrlAvery0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlAvery0OnTextEnter ), NULL, this );
	m_buttonOn0->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOn0OnButtonClick ), NULL, this );
	m_buttonOff0->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOff0OnButtonClick ), NULL, this );
	m_comboBoxType1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxType1OnCombobox ), NULL, this );
	m_textCtrlPeriod1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlPeriod1OnTextEnter ), NULL, this );
	m_comboBoxPeriod1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxPeriod1OnCombobox ), NULL, this );
	m_textCtrlPeek1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlPeek1OnTextEnter ), NULL, this );
	m_comboBoxPeek1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( SoftwareGenerator::m_comboBoxPeek1OnCombobox ), NULL, this );
	m_textCtrlSpeed1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlSpeed1OnTextEnter ), NULL, this );
	m_textCtrlAvery1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( SoftwareGenerator::m_textCtrlAvery1OnTextEnter ), NULL, this );
	m_buttonOn1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOn1OnButtonClick ), NULL, this );
	m_buttonOff1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOff1OnButtonClick ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SoftwareGenerator::m_buttonCancelOnButtonClick ), NULL, this );

}

HardwareGenerator::HardwareGenerator( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );

	m_notebook3 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH );
	m_panel14 = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer64;
	bSizer64 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText54 = new wxStaticText( m_panel14, wxID_ANY, _("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	m_staticText54->SetMinSize( wxSize( 100,-1 ) );

	bSizer64->Add( m_staticText54, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxTypeChoices[] = { _("custom"), _("sin"), _("cos"), _("triangle"), _("ramp up"), _("ramp down"), _("square"), _("delta"), _("dc"), _("noise") };
	int m_comboBoxTypeNChoices = sizeof( m_comboBoxTypeChoices ) / sizeof( wxString );
	m_comboBoxType = new wxChoice( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxTypeNChoices, m_comboBoxTypeChoices, 0 );
	m_comboBoxType->SetSelection( 0 );
	bSizer64->Add( m_comboBoxType, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer121->Add( bSizer64, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55 = new wxStaticText( m_panel14, wxID_ANY, _("Frequency(Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	m_staticText55->SetMinSize( wxSize( 100,-1 ) );

	bSizer65->Add( m_staticText55, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlFrequency = new wxTextCtrl( m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer65->Add( m_textCtrlFrequency, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer121->Add( bSizer65, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer641;
	bSizer641 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText551 = new wxStaticText( m_panel14, wxID_ANY, _("Amplitude(V):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText551->Wrap( -1 );
	m_staticText551->SetMinSize( wxSize( 100,-1 ) );

	bSizer641->Add( m_staticText551, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlVoltage0 = new wxTextCtrl( m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer641->Add( m_textCtrlVoltage0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnCh0Volt = new wxSpinButton( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer641->Add( m_spinBtnCh0Volt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderVoltage = new wxSlider( m_panel14, wxID_ANY, 1024, 0, 2047, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer641->Add( m_sliderVoltage, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer121->Add( bSizer641, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6411;
	bSizer6411 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5511 = new wxStaticText( m_panel14, wxID_ANY, _("Offset(V):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5511->Wrap( -1 );
	m_staticText5511->SetMinSize( wxSize( 100,-1 ) );

	bSizer6411->Add( m_staticText5511, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlOffset0 = new wxTextCtrl( m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer6411->Add( m_textCtrlOffset0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnCh0Offset = new wxSpinButton( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer6411->Add( m_spinBtnCh0Offset, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderOffset = new wxSlider( m_panel14, wxID_ANY, 0, -2047, 2047, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer6411->Add( m_sliderOffset, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer121->Add( bSizer6411, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer64111;
	bSizer64111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55111 = new wxStaticText( m_panel14, wxID_ANY, _("SquareDuty(%):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55111->Wrap( -1 );
	m_staticText55111->SetMinSize( wxSize( 100,-1 ) );

	bSizer64111->Add( m_staticText55111, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlSquareDuty0 = new wxTextCtrl( m_panel14, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer64111->Add( m_textCtrlSquareDuty0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnGen0SqrDuty = new wxSpinButton( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer64111->Add( m_spinBtnGen0SqrDuty, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderSquareDuty = new wxSlider( m_panel14, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer64111->Add( m_sliderSquareDuty, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer121->Add( bSizer64111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer641112;
	bSizer641112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText551111 = new wxStaticText( m_panel14, wxID_ANY, _("SawSlope:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText551111->Wrap( -1 );
	m_staticText551111->Hide();
	m_staticText551111->SetMinSize( wxSize( 100,-1 ) );

	bSizer641112->Add( m_staticText551111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxSawSlope = new wxCheckBox( m_panel14, wxID_ANY, _("Saw Slope Positive"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxSawSlope->SetValue(true);
	m_checkBoxSawSlope->Hide();

	bSizer641112->Add( m_checkBoxSawSlope, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer121->Add( bSizer641112, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxHORIZONTAL );

	m_filePicker1 = new wxFilePickerCtrl( m_panel14, wxID_ANY, wxEmptyString, _("./data/signal/custom.signal"), _("*.signal"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST );
	bSizer95->Add( m_filePicker1, 4, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCustomFile = new wxButton( m_panel14, wxID_ANY, _("upload"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer95->Add( m_buttonCustomFile, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer121->Add( bSizer95, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer641111;
	bSizer641111 = new wxBoxSizer( wxHORIZONTAL );


	bSizer641111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonOn0 = new wxButton( m_panel14, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer641111->Add( m_buttonOn0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer641111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonOff0 = new wxButton( m_panel14, wxID_ANY, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer641111->Add( m_buttonOff0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer641111->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer121->Add( bSizer641111, 1, wxEXPAND, 5 );


	m_panel14->SetSizer( bSizer121 );
	m_panel14->Layout();
	bSizer121->Fit( m_panel14 );
	m_notebook3->AddPage( m_panel14, _("Generator 1"), true );
	m_panel15 = new wxPanel( m_notebook3, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1211;
	bSizer1211 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer642;
	bSizer642 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText541 = new wxStaticText( m_panel15, wxID_ANY, _("Type:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText541->Wrap( -1 );
	m_staticText541->SetMinSize( wxSize( 100,-1 ) );

	bSizer642->Add( m_staticText541, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_comboBoxType1Choices[] = { _("custom"), _("sin"), _("cos"), _("triangle"), _("ramp up"), _("ramp down"), _("square"), _("delta"), _("dc"), _("noise") };
	int m_comboBoxType1NChoices = sizeof( m_comboBoxType1Choices ) / sizeof( wxString );
	m_comboBoxType1 = new wxChoice( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_comboBoxType1NChoices, m_comboBoxType1Choices, 0 );
	m_comboBoxType1->SetSelection( 0 );
	bSizer642->Add( m_comboBoxType1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1211->Add( bSizer642, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer651;
	bSizer651 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText552 = new wxStaticText( m_panel15, wxID_ANY, _("Frequency(Hz):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText552->Wrap( -1 );
	m_staticText552->SetMinSize( wxSize( 100,-1 ) );

	bSizer651->Add( m_staticText552, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlFrequency1 = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer651->Add( m_textCtrlFrequency1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1211->Add( bSizer651, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6412;
	bSizer6412 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5512 = new wxStaticText( m_panel15, wxID_ANY, _("Amplitude(V):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5512->Wrap( -1 );
	m_staticText5512->SetMinSize( wxSize( 100,-1 ) );

	bSizer6412->Add( m_staticText5512, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlVoltage1 = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer6412->Add( m_textCtrlVoltage1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnCh1Volt = new wxSpinButton( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer6412->Add( m_spinBtnCh1Volt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderVoltage1 = new wxSlider( m_panel15, wxID_ANY, 1024, 0, 2047, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer6412->Add( m_sliderVoltage1, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1211->Add( bSizer6412, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer64112;
	bSizer64112 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText55112 = new wxStaticText( m_panel15, wxID_ANY, _("Offset(V):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55112->Wrap( -1 );
	m_staticText55112->SetMinSize( wxSize( 100,-1 ) );

	bSizer64112->Add( m_staticText55112, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlOffset1 = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer64112->Add( m_textCtrlOffset1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnCh1Offset = new wxSpinButton( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer64112->Add( m_spinBtnCh1Offset, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderOffset1 = new wxSlider( m_panel15, wxID_ANY, 0, -2047, 2047, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer64112->Add( m_sliderOffset1, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1211->Add( bSizer64112, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer641113;
	bSizer641113 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText551112 = new wxStaticText( m_panel15, wxID_ANY, _("SquareDuty(%):"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText551112->Wrap( -1 );
	m_staticText551112->SetMinSize( wxSize( 100,-1 ) );

	bSizer641113->Add( m_staticText551112, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlSquareDuty1 = new wxTextCtrl( m_panel15, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer641113->Add( m_textCtrlSquareDuty1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnGen1SqrDuty = new wxSpinButton( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer641113->Add( m_spinBtnGen1SqrDuty, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderSquareDuty1 = new wxSlider( m_panel15, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer641113->Add( m_sliderSquareDuty1, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1211->Add( bSizer641113, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6411121;
	bSizer6411121 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText5511111 = new wxStaticText( m_panel15, wxID_ANY, _("SawSlope:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5511111->Wrap( -1 );
	m_staticText5511111->Hide();
	m_staticText5511111->SetMinSize( wxSize( 100,-1 ) );

	bSizer6411121->Add( m_staticText5511111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxSawSlope1 = new wxCheckBox( m_panel15, wxID_ANY, _("Saw Slope Positive"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxSawSlope1->SetValue(true);
	m_checkBoxSawSlope1->Hide();

	bSizer6411121->Add( m_checkBoxSawSlope1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1211->Add( bSizer6411121, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer951;
	bSizer951 = new wxBoxSizer( wxHORIZONTAL );

	m_filePicker11 = new wxFilePickerCtrl( m_panel15, wxID_ANY, wxEmptyString, _("./data/signal/custom.signal"), _("*.signal"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST );
	bSizer951->Add( m_filePicker11, 4, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCustomFile1 = new wxButton( m_panel15, wxID_ANY, _("upload"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer951->Add( m_buttonCustomFile1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer1211->Add( bSizer951, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6411111;
	bSizer6411111 = new wxBoxSizer( wxHORIZONTAL );


	bSizer6411111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonOn1 = new wxButton( m_panel15, wxID_ANY, _("On"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6411111->Add( m_buttonOn1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer6411111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonOff1 = new wxButton( m_panel15, wxID_ANY, _("Off"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6411111->Add( m_buttonOff1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer6411111->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer1211->Add( bSizer6411111, 1, wxEXPAND, 5 );


	m_panel15->SetSizer( bSizer1211 );
	m_panel15->Layout();
	bSizer1211->Fit( m_panel15 );
	m_notebook3->AddPage( m_panel15, _("Generator 2"), false );

	bSizer35->Add( m_notebook3, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOk = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( m_buttonOk, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_buttonDefault = new wxButton( this, wxID_ANY, _("Default"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( m_buttonDefault, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );

	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( m_buttonCancel, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );


	bSizer35->Add( bSizer63, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer35 );
	this->Layout();
	bSizer35->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( HardwareGenerator::HardwareGeneratorOnInitDialog ) );
	m_comboBoxType->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HardwareGenerator::m_comboBoxTypeOnCombobox ), NULL, this );
	m_textCtrlFrequency->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlFrequencyOnTextEnter ), NULL, this );
	m_textCtrlVoltage0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlVoltage0OnTextEnter ), NULL, this );
	m_spinBtnCh0Volt->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh0VoltOnSpinDown ), NULL, this );
	m_spinBtnCh0Volt->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh0VoltOnSpinUp ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_textCtrlOffset0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlOffset0OnTextEnter ), NULL, this );
	m_spinBtnCh0Offset->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh0OffsetOnSpinDown ), NULL, this );
	m_spinBtnCh0Offset->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh0OffsetOnSpinUp ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_textCtrlSquareDuty0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlSquareDuty0OnTextEnter ), NULL, this );
	m_spinBtnGen0SqrDuty->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnGen0SqrDutyOnSpinDown ), NULL, this );
	m_spinBtnGen0SqrDuty->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnGen0SqrDutyOnSpinUp ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_checkBoxSawSlope->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HardwareGenerator::m_checkBoxSawSlopeOnCheckBox ), NULL, this );
	m_filePicker1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( HardwareGenerator::m_filePicker1OnFileChanged ), NULL, this );
	m_buttonCustomFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonCustomFileOnButtonClick ), NULL, this );
	m_buttonOn0->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOn0OnButtonClick ), NULL, this );
	m_buttonOff0->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOff0OnButtonClick ), NULL, this );
	m_comboBoxType1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HardwareGenerator::m_comboBoxType1OnChoice ), NULL, this );
	m_textCtrlFrequency1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlFrequency1OnTextEnter ), NULL, this );
	m_textCtrlVoltage1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlVoltage1OnTextEnter ), NULL, this );
	m_spinBtnCh1Volt->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh1VoltOnSpinDown ), NULL, this );
	m_spinBtnCh1Volt->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh1VoltOnSpinUp ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_textCtrlOffset1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlOffset1OnTextEnter ), NULL, this );
	m_spinBtnCh1Offset->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh1OffsetOnSpinDown ), NULL, this );
	m_spinBtnCh1Offset->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh1OffsetOnSpinUp ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_textCtrlSquareDuty1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlSquareDuty1OnTextEnter ), NULL, this );
	m_spinBtnGen1SqrDuty->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnGen1SqrDutyOnSpinDown ), NULL, this );
	m_spinBtnGen1SqrDuty->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnGen1SqrDutyOnSpinUp ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_checkBoxSawSlope1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HardwareGenerator::m_checkBoxSawSlope1OnCheckBox ), NULL, this );
	m_filePicker11->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( HardwareGenerator::m_filePicker11OnFileChanged ), NULL, this );
	m_buttonCustomFile1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonCustomFile1OnButtonClick ), NULL, this );
	m_buttonOn1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOn1OnButtonClick ), NULL, this );
	m_buttonOff1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOff1OnButtonClick ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonCancelOnButtonClick ), NULL, this );
}

HardwareGenerator::~HardwareGenerator()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( HardwareGenerator::HardwareGeneratorOnInitDialog ) );
	m_comboBoxType->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HardwareGenerator::m_comboBoxTypeOnCombobox ), NULL, this );
	m_textCtrlFrequency->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlFrequencyOnTextEnter ), NULL, this );
	m_textCtrlVoltage0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlVoltage0OnTextEnter ), NULL, this );
	m_spinBtnCh0Volt->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh0VoltOnSpinDown ), NULL, this );
	m_spinBtnCh0Volt->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh0VoltOnSpinUp ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_sliderVoltage->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderVoltageOnScroll ), NULL, this );
	m_textCtrlOffset0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlOffset0OnTextEnter ), NULL, this );
	m_spinBtnCh0Offset->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh0OffsetOnSpinDown ), NULL, this );
	m_spinBtnCh0Offset->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh0OffsetOnSpinUp ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_sliderOffset->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderOffsetOnScroll ), NULL, this );
	m_textCtrlSquareDuty0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlSquareDuty0OnTextEnter ), NULL, this );
	m_spinBtnGen0SqrDuty->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnGen0SqrDutyOnSpinDown ), NULL, this );
	m_spinBtnGen0SqrDuty->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnGen0SqrDutyOnSpinUp ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_sliderSquareDuty->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDutyOnScroll ), NULL, this );
	m_checkBoxSawSlope->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HardwareGenerator::m_checkBoxSawSlopeOnCheckBox ), NULL, this );
	m_filePicker1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( HardwareGenerator::m_filePicker1OnFileChanged ), NULL, this );
	m_buttonCustomFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonCustomFileOnButtonClick ), NULL, this );
	m_buttonOn0->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOn0OnButtonClick ), NULL, this );
	m_buttonOff0->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOff0OnButtonClick ), NULL, this );
	m_comboBoxType1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HardwareGenerator::m_comboBoxType1OnChoice ), NULL, this );
	m_textCtrlFrequency1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlFrequency1OnTextEnter ), NULL, this );
	m_textCtrlVoltage1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlVoltage1OnTextEnter ), NULL, this );
	m_spinBtnCh1Volt->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh1VoltOnSpinDown ), NULL, this );
	m_spinBtnCh1Volt->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh1VoltOnSpinUp ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_sliderVoltage1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderVoltage1OnScroll ), NULL, this );
	m_textCtrlOffset1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlOffset1OnTextEnter ), NULL, this );
	m_spinBtnCh1Offset->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh1OffsetOnSpinDown ), NULL, this );
	m_spinBtnCh1Offset->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnCh1OffsetOnSpinUp ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_sliderOffset1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderOffset1OnScroll ), NULL, this );
	m_textCtrlSquareDuty1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HardwareGenerator::m_textCtrlSquareDuty1OnTextEnter ), NULL, this );
	m_spinBtnGen1SqrDuty->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( HardwareGenerator::m_spinBtnGen1SqrDutyOnSpinDown ), NULL, this );
	m_spinBtnGen1SqrDuty->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( HardwareGenerator::m_spinBtnGen1SqrDutyOnSpinUp ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_sliderSquareDuty1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( HardwareGenerator::m_sliderSquareDuty1OnScroll ), NULL, this );
	m_checkBoxSawSlope1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HardwareGenerator::m_checkBoxSawSlope1OnCheckBox ), NULL, this );
	m_filePicker11->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( HardwareGenerator::m_filePicker11OnFileChanged ), NULL, this );
	m_buttonCustomFile1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonCustomFile1OnButtonClick ), NULL, this );
	m_buttonOn1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOn1OnButtonClick ), NULL, this );
	m_buttonOff1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOff1OnButtonClick ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HardwareGenerator::m_buttonCancelOnButtonClick ), NULL, this );

}

Thermal::Thermal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText52 = new wxStaticText( this, wxID_ANY, _("Heating:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetMinSize( wxSize( 100,-1 ) );

	bSizer56->Add( m_staticText52, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlHeating = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer56->Add( m_textCtrlHeating, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnHeating = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer56->Add( m_spinBtnHeating, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderHeat = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer56->Add( m_sliderHeat, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer55->Add( bSizer56, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText53 = new wxStaticText( this, wxID_ANY, _("Cooling:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetMinSize( wxSize( 100,-1 ) );

	bSizer57->Add( m_staticText53, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlCooling = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer57->Add( m_textCtrlCooling, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnCooling = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer57->Add( m_spinBtnCooling, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderCool = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer57->Add( m_sliderCool, 2, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer55->Add( bSizer57, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBoxEnabled = new wxCheckBox( this, wxID_ANY, _("Thermal rendering enabled"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( m_checkBoxEnabled, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer55->Add( bSizer58, 1, wxEXPAND, 5 );

	m_staticline5 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer55->Add( m_staticline5, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOk = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_buttonOk, 1, wxALL, 5 );

	m_buttonDefault = new wxButton( this, wxID_ANY, _("Default"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_buttonDefault, 1, wxALL, 5 );

	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_buttonCancel, 1, wxALL, 5 );


	bSizer55->Add( bSizer59, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer55 );
	this->Layout();
	bSizer55->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( Thermal::ThermalOnActivate ) );
	m_textCtrlHeating->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Thermal::m_textCtrlHeatingOnTextEnter ), NULL, this );
	m_spinBtnHeating->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Thermal::m_spinBtnHeatingOnSpinDown ), NULL, this );
	m_spinBtnHeating->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Thermal::m_spinBtnHeatingOnSpinUp ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_textCtrlCooling->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Thermal::m_textCtrlCoolingOnTextEnter ), NULL, this );
	m_spinBtnCooling->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Thermal::m_spinBtnCoolingOnSpinDown ), NULL, this );
	m_spinBtnCooling->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Thermal::m_spinBtnCoolingOnSpinUp ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_checkBoxEnabled->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Thermal::m_checkBoxEnabledOnCheckBox ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Thermal::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Thermal::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Thermal::m_buttonCancelOnButtonClick ), NULL, this );
}

Thermal::~Thermal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( Thermal::ThermalOnActivate ) );
	m_textCtrlHeating->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Thermal::m_textCtrlHeatingOnTextEnter ), NULL, this );
	m_spinBtnHeating->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Thermal::m_spinBtnHeatingOnSpinDown ), NULL, this );
	m_spinBtnHeating->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Thermal::m_spinBtnHeatingOnSpinUp ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_sliderHeat->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Thermal::m_sliderHeatOnScroll ), NULL, this );
	m_textCtrlCooling->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Thermal::m_textCtrlCoolingOnTextEnter ), NULL, this );
	m_spinBtnCooling->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Thermal::m_spinBtnCoolingOnSpinDown ), NULL, this );
	m_spinBtnCooling->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Thermal::m_spinBtnCoolingOnSpinUp ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_sliderCool->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Thermal::m_sliderCoolOnScroll ), NULL, this );
	m_checkBoxEnabled->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Thermal::m_checkBoxEnabledOnCheckBox ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Thermal::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Thermal::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Thermal::m_buttonCancelOnButtonClick ), NULL, this );

}

Display::Display( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBoxUnits = new wxCheckBox( this, wxID_ANY, _("Units"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer32->Add( m_checkBoxUnits, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_checkBoxAxis = new wxCheckBox( this, wxID_ANY, _("Axis"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer32->Add( m_checkBoxAxis, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxGrid = new wxCheckBox( this, wxID_ANY, _("Grid"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer32->Add( m_checkBoxGrid, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer33->Add( bSizer32, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBoxFFTUnit = new wxCheckBox( this, wxID_ANY, _("FFT Units"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer31->Add( m_checkBoxFFTUnit, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxFFTAxis = new wxCheckBox( this, wxID_ANY, _("FFT Axis"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer31->Add( m_checkBoxFFTAxis, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxFFTGrid = new wxCheckBox( this, wxID_ANY, _("FFT Grid"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer31->Add( m_checkBoxFFTGrid, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer33->Add( bSizer31, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBoxDigitalUnit = new wxCheckBox( this, wxID_ANY, _("Digital Units"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer30->Add( m_checkBoxDigitalUnit, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxDigitalAxis = new wxCheckBox( this, wxID_ANY, _("Digital Axis"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer30->Add( m_checkBoxDigitalAxis, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxDigitalGrid = new wxCheckBox( this, wxID_ANY, _("Digital Grid"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer30->Add( m_checkBoxDigitalGrid, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer33->Add( bSizer30, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText78 = new wxStaticText( this, wxID_ANY, _("Signal:"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_staticText78->Wrap( -1 );
	bSizer29->Add( m_staticText78, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceSignalChoices[] = { _("Line"), _("Triangle") };
	int m_choiceSignalNChoices = sizeof( m_choiceSignalChoices ) / sizeof( wxString );
	m_choiceSignal = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSignalNChoices, m_choiceSignalChoices, 0 );
	m_choiceSignal->SetSelection( 0 );
	bSizer29->Add( m_choiceSignal, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText38 = new wxStaticText( this, wxID_ANY, _("Triangle Size:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText38->Wrap( -1 );
	bSizer29->Add( m_staticText38, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlSignal = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer29->Add( m_textCtrlSignal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderSignal = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer29->Add( m_sliderSignal, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer33->Add( bSizer29, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText79 = new wxStaticText( this, wxID_ANY, _("FFT:"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT );
	m_staticText79->Wrap( -1 );
	bSizer28->Add( m_staticText79, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceFFTChoices[] = { _("Line"), _("Triangle") };
	int m_choiceFFTNChoices = sizeof( m_choiceFFTChoices ) / sizeof( wxString );
	m_choiceFFT = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceFFTNChoices, m_choiceFFTChoices, 0 );
	m_choiceFFT->SetSelection( 0 );
	bSizer28->Add( m_choiceFFT, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText39 = new wxStaticText( this, wxID_ANY, _("Triangle Size:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText39->Wrap( -1 );
	bSizer28->Add( m_staticText39, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );

	m_textCtrlFFT = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer28->Add( m_textCtrlFFT, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderFFT = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer28->Add( m_sliderFFT, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer33->Add( bSizer28, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer281;
	bSizer281 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText391 = new wxStaticText( this, wxID_ANY, _("FFT Y Axis:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText391->Wrap( -1 );
	bSizer281->Add( m_staticText391, 1, wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT|wxALL, 5 );

	wxString m_choiceFFTYChoices[] = { _("Voltage"), _("dB10"), _("dB20"), _("dB30"), _("dB40"), _("dB50"), _("dB60"), _("dB70"), _("dB80"), _("dB90"), _("dB100"), _("dB110"), _("dB120") };
	int m_choiceFFTYNChoices = sizeof( m_choiceFFTYChoices ) / sizeof( wxString );
	m_choiceFFTY = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceFFTYNChoices, m_choiceFFTYChoices, 0 );
	m_choiceFFTY->SetSelection( 10 );
	bSizer281->Add( m_choiceFFTY, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_staticText3911 = new wxStaticText( this, wxID_ANY, _("FFT X Axis:"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_staticText3911->Wrap( -1 );
	bSizer281->Add( m_staticText3911, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceFFTXChoices[] = { _("Linear"), _("Log4K") };
	int m_choiceFFTXNChoices = sizeof( m_choiceFFTXChoices ) / sizeof( wxString );
	m_choiceFFTX = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceFFTXNChoices, m_choiceFFTXChoices, 0 );
	m_choiceFFTX->SetSelection( 0 );
	bSizer281->Add( m_choiceFFTX, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer281->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer33->Add( bSizer281, 1, wxEXPAND, 5 );

	m_staticline9 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer33->Add( m_staticline9, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer2811;
	bSizer2811 = new wxBoxSizer( wxHORIZONTAL );


	bSizer2811->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBox3dSolid = new wxCheckBox( this, wxID_ANY, _("3d surface"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2811->Add( m_checkBox3dSolid, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBox3dLight = new wxCheckBox( this, wxID_ANY, _("3d light"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2811->Add( m_checkBox3dLight, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBox3dDepthTest = new wxCheckBox( this, wxID_ANY, _("3d depth"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2811->Add( m_checkBox3dDepthTest, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer2811->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer33->Add( bSizer2811, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer281112;
	bSizer281112 = new wxBoxSizer( wxHORIZONTAL );


	bSizer281112->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText962 = new wxStaticText( this, wxID_ANY, _("3d  Alpha Channel 0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText962->Wrap( -1 );
	m_staticText962->SetMinSize( wxSize( 125,-1 ) );

	bSizer281112->Add( m_staticText962, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl3dAlphaCh0 = new wxTextCtrl( this, wxID_ANY, _("64"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer281112->Add( m_textCtrl3dAlphaCh0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText992 = new wxStaticText( this, wxID_ANY, _("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText992->Wrap( -1 );
	bSizer281112->Add( m_staticText992, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider3dAlphaCh0 = new wxSlider( this, wxID_ANY, 64, 1, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider3dAlphaCh0->SetMinSize( wxSize( 250,-1 ) );

	bSizer281112->Add( m_slider3dAlphaCh0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText1002 = new wxStaticText( this, wxID_ANY, _("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1002->Wrap( -1 );
	bSizer281112->Add( m_staticText1002, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer281112->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer33->Add( bSizer281112, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer2811121;
	bSizer2811121 = new wxBoxSizer( wxHORIZONTAL );


	bSizer2811121->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText9621 = new wxStaticText( this, wxID_ANY, _("3d  Alpha Channel 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9621->Wrap( -1 );
	m_staticText9621->SetMinSize( wxSize( 125,-1 ) );

	bSizer2811121->Add( m_staticText9621, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl3dAlphaCh1 = new wxTextCtrl( this, wxID_ANY, _("64"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer2811121->Add( m_textCtrl3dAlphaCh1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText9921 = new wxStaticText( this, wxID_ANY, _("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9921->Wrap( -1 );
	bSizer2811121->Add( m_staticText9921, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider3dAlphaCh1 = new wxSlider( this, wxID_ANY, 64, 1, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider3dAlphaCh1->SetMinSize( wxSize( 250,-1 ) );

	bSizer2811121->Add( m_slider3dAlphaCh1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText10021 = new wxStaticText( this, wxID_ANY, _("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10021->Wrap( -1 );
	bSizer2811121->Add( m_staticText10021, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer2811121->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer33->Add( bSizer2811121, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer28111211;
	bSizer28111211 = new wxBoxSizer( wxHORIZONTAL );


	bSizer28111211->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText96211 = new wxStaticText( this, wxID_ANY, _("3d  Alpha Function"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText96211->Wrap( -1 );
	m_staticText96211->SetMinSize( wxSize( 125,-1 ) );

	bSizer28111211->Add( m_staticText96211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl3dAlphaFun = new wxTextCtrl( this, wxID_ANY, _("64"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer28111211->Add( m_textCtrl3dAlphaFun, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText99211 = new wxStaticText( this, wxID_ANY, _("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99211->Wrap( -1 );
	bSizer28111211->Add( m_staticText99211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider3dAlphaFun = new wxSlider( this, wxID_ANY, 64, 1, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider3dAlphaFun->SetMinSize( wxSize( 250,-1 ) );

	bSizer28111211->Add( m_slider3dAlphaFun, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText100211 = new wxStaticText( this, wxID_ANY, _("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText100211->Wrap( -1 );
	bSizer28111211->Add( m_staticText100211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer28111211->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer33->Add( bSizer28111211, 1, wxEXPAND, 5 );

	m_staticline10 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer33->Add( m_staticline10, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer28111;
	bSizer28111 = new wxBoxSizer( wxHORIZONTAL );


	bSizer28111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText96 = new wxStaticText( this, wxID_ANY, _("3d tessalation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText96->Wrap( -1 );
	m_staticText96->SetMinSize( wxSize( 125,-1 ) );

	bSizer28111->Add( m_staticText96, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl3dTessalation = new wxTextCtrl( this, wxID_ANY, _("1"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer28111->Add( m_textCtrl3dTessalation, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText99 = new wxStaticText( this, wxID_ANY, _("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText99->Wrap( -1 );
	bSizer28111->Add( m_staticText99, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider3dTessalation = new wxSlider( this, wxID_ANY, 1, 1, 1024, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider3dTessalation->SetMinSize( wxSize( 250,-1 ) );

	bSizer28111->Add( m_slider3dTessalation, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText100 = new wxStaticText( this, wxID_ANY, _("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText100->Wrap( -1 );
	bSizer28111->Add( m_staticText100, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer28111->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer33->Add( bSizer28111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer281111;
	bSizer281111 = new wxBoxSizer( wxHORIZONTAL );


	bSizer281111->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText961 = new wxStaticText( this, wxID_ANY, _("2d tessalation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText961->Wrap( -1 );
	m_staticText961->SetMinSize( wxSize( 125,-1 ) );

	bSizer281111->Add( m_staticText961, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl2dTessalation = new wxTextCtrl( this, wxID_ANY, _("1"), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer281111->Add( m_textCtrl2dTessalation, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText991 = new wxStaticText( this, wxID_ANY, _("Max"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText991->Wrap( -1 );
	bSizer281111->Add( m_staticText991, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider2dTessalation = new wxSlider( this, wxID_ANY, 1, 1, 1024, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_slider2dTessalation->SetMinSize( wxSize( 250,-1 ) );

	bSizer281111->Add( m_slider2dTessalation, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText1001 = new wxStaticText( this, wxID_ANY, _("Min"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1001->Wrap( -1 );
	bSizer281111->Add( m_staticText1001, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer281111->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer33->Add( bSizer281111, 1, wxEXPAND, 5 );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer33->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOk = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_buttonOk, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonDefault = new wxButton( this, wxID_ANY, _("Default"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_buttonDefault, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_buttonCancel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer33->Add( bSizer35, 1, wxEXPAND|wxALL, 5 );


	bSizer34->Add( bSizer33, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer34 );
	this->Layout();
	bSizer34->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( Display::DisplayOnInitDialog ) );
	m_checkBoxUnits->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxUnitsOnCheckBox ), NULL, this );
	m_checkBoxAxis->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxAxisOnCheckBox ), NULL, this );
	m_checkBoxGrid->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxGridOnCheckBox ), NULL, this );
	m_checkBoxFFTUnit->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxFFTUnitOnCheckBox ), NULL, this );
	m_checkBoxFFTAxis->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxFFTAxisOnCheckBox ), NULL, this );
	m_checkBoxFFTGrid->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxFFTGridOnCheckBox ), NULL, this );
	m_checkBoxDigitalUnit->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxDigitalUnitOnCheckBox ), NULL, this );
	m_checkBoxDigitalAxis->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxDigitalAxisOnCheckBox ), NULL, this );
	m_checkBoxDigitalGrid->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxDigitalGridOnCheckBox ), NULL, this );
	m_choiceSignal->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Display::m_choiceSignalOnChoice ), NULL, this );
	m_textCtrlSignal->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrlSignalOnTextEnter ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_choiceFFT->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Display::m_choiceFFTOnChoice ), NULL, this );
	m_textCtrlFFT->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrlFFTOnTextEnter ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_choiceFFTY->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Display::m_choiceFFTYOnChoice ), NULL, this );
	m_choiceFFTX->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Display::m_choiceFFTXOnChoice ), NULL, this );
	m_checkBox3dSolid->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBox3dSolidOnCheckBox ), NULL, this );
	m_checkBox3dLight->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBox3dLightOnCheckBox ), NULL, this );
	m_checkBox3dDepthTest->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBox3dDepthTestOnCheckBox ), NULL, this );
	m_textCtrl3dAlphaCh0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl3dAlphaCh0OnTextEnter ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_textCtrl3dAlphaCh1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl3dAlphaCh1OnTextEnter ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_textCtrl3dAlphaFun->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl3dAlphaFunOnTextEnter ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_textCtrl3dTessalation->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl3dTessalationOnTextEnter ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_textCtrl2dTessalation->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl2dTessalationOnTextEnter ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Display::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Display::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Display::m_buttonCancelOnButtonClick ), NULL, this );
}

Display::~Display()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( Display::DisplayOnInitDialog ) );
	m_checkBoxUnits->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxUnitsOnCheckBox ), NULL, this );
	m_checkBoxAxis->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxAxisOnCheckBox ), NULL, this );
	m_checkBoxGrid->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxGridOnCheckBox ), NULL, this );
	m_checkBoxFFTUnit->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxFFTUnitOnCheckBox ), NULL, this );
	m_checkBoxFFTAxis->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxFFTAxisOnCheckBox ), NULL, this );
	m_checkBoxFFTGrid->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxFFTGridOnCheckBox ), NULL, this );
	m_checkBoxDigitalUnit->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxDigitalUnitOnCheckBox ), NULL, this );
	m_checkBoxDigitalAxis->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxDigitalAxisOnCheckBox ), NULL, this );
	m_checkBoxDigitalGrid->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBoxDigitalGridOnCheckBox ), NULL, this );
	m_choiceSignal->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Display::m_choiceSignalOnChoice ), NULL, this );
	m_textCtrlSignal->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrlSignalOnTextEnter ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_sliderSignal->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_sliderSignalOnScroll ), NULL, this );
	m_choiceFFT->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Display::m_choiceFFTOnChoice ), NULL, this );
	m_textCtrlFFT->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrlFFTOnTextEnter ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_sliderFFT->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_sliderFFTOnScroll ), NULL, this );
	m_choiceFFTY->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Display::m_choiceFFTYOnChoice ), NULL, this );
	m_choiceFFTX->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Display::m_choiceFFTXOnChoice ), NULL, this );
	m_checkBox3dSolid->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBox3dSolidOnCheckBox ), NULL, this );
	m_checkBox3dLight->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBox3dLightOnCheckBox ), NULL, this );
	m_checkBox3dDepthTest->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Display::m_checkBox3dDepthTestOnCheckBox ), NULL, this );
	m_textCtrl3dAlphaCh0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl3dAlphaCh0OnTextEnter ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_slider3dAlphaCh0->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider3dAlphaCh0OnScroll ), NULL, this );
	m_textCtrl3dAlphaCh1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl3dAlphaCh1OnTextEnter ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_slider3dAlphaCh1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider3dAlphaCh1OnScroll ), NULL, this );
	m_textCtrl3dAlphaFun->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl3dAlphaFunOnTextEnter ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_slider3dAlphaFun->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider3dAlphaFunOnScroll ), NULL, this );
	m_textCtrl3dTessalation->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl3dTessalationOnTextEnter ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_slider3dTessalation->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider3dTessalationOnScroll ), NULL, this );
	m_textCtrl2dTessalation->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Display::m_textCtrl2dTessalationOnTextEnter ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_slider2dTessalation->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Display::m_slider2dTessalationOnScroll ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Display::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Display::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Display::m_buttonCancelOnButtonClick ), NULL, this );

}

Measure::Measure( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxSize( -1,-1 ) );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer127;
	bSizer127 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxHORIZONTAL );

	m_checkBoxAutoClear = new wxCheckBox( this, wxID_ANY, _("Capture Clear"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_checkBoxAutoClear, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_checkBoxAutoClearTrigger = new wxCheckBox( this, wxID_ANY, _("Trigger Clear "), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_checkBoxAutoClearTrigger, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonHistoryClear = new wxButton( this, wxID_ANY, _("Clear History"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_buttonHistoryClear, 0, wxALL, 5 );

	m_buttonClearX = new wxButton( this, wxID_ANY, _("Clear X"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_buttonClearX, 0, wxALL, 5 );

	m_buttonClearY = new wxButton( this, wxID_ANY, _("Clear Y"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_buttonClearY, 0, wxALL, 5 );

	m_buttonClearFFT = new wxButton( this, wxID_ANY, _("Clear FFT"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_buttonClearFFT, 0, wxALL, 5 );

	m_buttonCopy = new wxButton( this, wxID_ANY, _("Copy Grid To Clipboard"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer156->Add( m_buttonCopy, 0, wxALL, 5 );


	bSizer127->Add( bSizer156, 0, wxEXPAND, 5 );


	bSizer152->Add( bSizer127, 0, 0, 5 );

	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer164;
	bSizer164 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer166;
	bSizer166 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPickX0 = new wxButton( this, wxID_ANY, _("Pick X0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer166->Add( m_buttonPickX0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlX0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer166->Add( m_textCtrlX0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceX0Choices[] = { _("ks"), _("s"), _("ms"), _("us") };
	int m_choiceX0NChoices = sizeof( m_choiceX0Choices ) / sizeof( wxString );
	m_choiceX0 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceX0NChoices, m_choiceX0Choices, 0 );
	m_choiceX0->SetSelection( 1 );
	bSizer166->Add( m_choiceX0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnX0 = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer166->Add( m_spinBtnX0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderX0 = new wxSlider( this, wxID_ANY, 512, 0, 1024, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer166->Add( m_sliderX0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer159->Add( bSizer166, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer167;
	bSizer167 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPickX1 = new wxButton( this, wxID_ANY, _("Pick X1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer167->Add( m_buttonPickX1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlX1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer167->Add( m_textCtrlX1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceX1Choices[] = { _("ks"), _("s"), _("ms"), _("us") };
	int m_choiceX1NChoices = sizeof( m_choiceX1Choices ) / sizeof( wxString );
	m_choiceX1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceX1NChoices, m_choiceX1Choices, 0 );
	m_choiceX1->SetSelection( 1 );
	bSizer167->Add( m_choiceX1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnX1 = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer167->Add( m_spinBtnX1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderX1 = new wxSlider( this, wxID_ANY, 512, 0, 1024, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer167->Add( m_sliderX1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer159->Add( bSizer167, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer168;
	bSizer168 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPickY0 = new wxButton( this, wxID_ANY, _("Pick Y0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer168->Add( m_buttonPickY0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlY0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer168->Add( m_textCtrlY0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceY0Choices[] = { _("Channel 0"), _("Channel 1") };
	int m_choiceY0NChoices = sizeof( m_choiceY0Choices ) / sizeof( wxString );
	m_choiceY0 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceY0NChoices, m_choiceY0Choices, 0 );
	m_choiceY0->SetSelection( 0 );
	bSizer168->Add( m_choiceY0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnY0 = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer168->Add( m_spinBtnY0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderY0 = new wxSlider( this, wxID_ANY, 512, 0, 1024, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer168->Add( m_sliderY0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer159->Add( bSizer168, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer169;
	bSizer169 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPickY1 = new wxButton( this, wxID_ANY, _("Pick Y1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer169->Add( m_buttonPickY1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlY1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer169->Add( m_textCtrlY1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceY1Choices[] = { _("Channel 0"), _("Channel 1") };
	int m_choiceY1NChoices = sizeof( m_choiceY1Choices ) / sizeof( wxString );
	m_choiceY1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceY1NChoices, m_choiceY1Choices, 0 );
	m_choiceY1->SetSelection( 0 );
	bSizer169->Add( m_choiceY1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnY1 = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer169->Add( m_spinBtnY1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderY1 = new wxSlider( this, wxID_ANY, 512, 0, 1024, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer169->Add( m_sliderY1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer159->Add( bSizer169, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1691;
	bSizer1691 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPickFFT0 = new wxButton( this, wxID_ANY, _("Pick FFT0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1691->Add( m_buttonPickFFT0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlFFT0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer1691->Add( m_textCtrlFFT0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceFFT0Choices[] = { _("Hz"), _("KHz"), _("Mhz") };
	int m_choiceFFT0NChoices = sizeof( m_choiceFFT0Choices ) / sizeof( wxString );
	m_choiceFFT0 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceFFT0NChoices, m_choiceFFT0Choices, 0 );
	m_choiceFFT0->SetSelection( 0 );
	bSizer1691->Add( m_choiceFFT0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnFFT0 = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer1691->Add( m_spinBtnFFT0, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderFFT0 = new wxSlider( this, wxID_ANY, 512, 0, 1024, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer1691->Add( m_sliderFFT0, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer159->Add( bSizer1691, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16911;
	bSizer16911 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonPickFFT1 = new wxButton( this, wxID_ANY, _("Pick FFT1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16911->Add( m_buttonPickFFT1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlFFT1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer16911->Add( m_textCtrlFFT1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceFFT1Choices[] = { _("Hz"), _("KHz"), _("Mhz") };
	int m_choiceFFT1NChoices = sizeof( m_choiceFFT1Choices ) / sizeof( wxString );
	m_choiceFFT1 = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceFFT1NChoices, m_choiceFFT1Choices, 0 );
	m_choiceFFT1->SetSelection( 0 );
	bSizer16911->Add( m_choiceFFT1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_spinBtnFFT1 = new wxSpinButton( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_VERTICAL );
	bSizer16911->Add( m_spinBtnFFT1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_sliderFFT1 = new wxSlider( this, wxID_ANY, 512, 0, 1024, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer16911->Add( m_sliderFFT1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer159->Add( bSizer16911, 1, wxEXPAND, 5 );


	bSizer164->Add( bSizer159, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer130;
	bSizer130 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer1591;
	bSizer1591 = new wxBoxSizer( wxVERTICAL );

	m_dataViewListCtrl1 = new wxDataViewListCtrl( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxDV_HORIZ_RULES|wxDV_SINGLE|wxDV_VERT_RULES );
	m_dataViewListCtrl1->SetExtraStyle( wxWS_EX_PROCESS_IDLE|wxWS_EX_PROCESS_UI_UPDATES );

	bSizer1591->Add( m_dataViewListCtrl1, 12, wxALL|wxEXPAND, 5 );


	m_scrolledWindow1->SetSizer( bSizer1591 );
	m_scrolledWindow1->Layout();
	bSizer1591->Fit( m_scrolledWindow1 );
	bSizer130->Add( m_scrolledWindow1, 1, wxEXPAND | wxALL, 5 );


	bSizer164->Add( bSizer130, 1, wxEXPAND, 5 );


	bSizer161->Add( bSizer164, 1, wxEXPAND, 5 );


	bSizer152->Add( bSizer161, 1, wxEXPAND, 5 );


	bSizer33->Add( bSizer152, 1, wxEXPAND, 5 );


	bSizer34->Add( bSizer33, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOk = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_buttonOk, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonDefault = new wxButton( this, wxID_ANY, _("Default"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_buttonDefault, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_buttonCancel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer34->Add( bSizer35, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer34 );
	this->Layout();
	bSizer34->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( Measure::DisplayOnInitDialog ) );
	m_checkBoxAutoClear->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Measure::m_checkBoxAutoClearOnCheckBox ), NULL, this );
	m_checkBoxAutoClearTrigger->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Measure::m_checkBoxAutoClearTriggerOnCheckBox ), NULL, this );
	m_buttonHistoryClear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonHistoryClearOnButtonClick ), NULL, this );
	m_buttonClearX->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonClearXOnButtonClick ), NULL, this );
	m_buttonClearY->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonClearYOnButtonClick ), NULL, this );
	m_buttonClearFFT->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonClearFFTOnButtonClick ), NULL, this );
	m_buttonCopy->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonCopyOnButtonClick ), NULL, this );
	m_buttonPickX0->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickX0OnButtonClick ), NULL, this );
	m_textCtrlX0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlX0OnTextEnter ), NULL, this );
	m_spinBtnX0->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnX0OnSpinDown ), NULL, this );
	m_spinBtnX0->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnX0OnSpinUp ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_buttonPickX1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickX1OnButtonClick ), NULL, this );
	m_textCtrlX1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlX1OnTextEnter ), NULL, this );
	m_spinBtnX1->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnX1OnSpinDown ), NULL, this );
	m_spinBtnX1->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnX1OnSpinUp ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_buttonPickY0->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickY0OnButtonClick ), NULL, this );
	m_textCtrlY0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlY0OnTextEnter ), NULL, this );
	m_choiceY0->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Measure::m_choiceY0OnChoice ), NULL, this );
	m_spinBtnY0->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnY0OnSpinDown ), NULL, this );
	m_spinBtnY0->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnY0OnSpinUp ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_buttonPickY1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickY1OnButtonClick ), NULL, this );
	m_textCtrlY1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlY1OnTextEnter ), NULL, this );
	m_choiceY1->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Measure::m_choiceY1OnChoice ), NULL, this );
	m_spinBtnY1->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnY1OnSpinDown ), NULL, this );
	m_spinBtnY1->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnY1OnSpinUp ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_buttonPickFFT0->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickFFT0OnButtonClick ), NULL, this );
	m_textCtrlFFT0->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlFFT0OnTextEnter ), NULL, this );
	m_spinBtnFFT0->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnFFT0OnSpinDown ), NULL, this );
	m_spinBtnFFT0->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnFFT0OnSpinUp ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_buttonPickFFT1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickFFT1OnButtonClick ), NULL, this );
	m_textCtrlFFT1->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlFFT1OnTextEnter ), NULL, this );
	m_spinBtnFFT1->Connect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnFFT1OnSpinDown ), NULL, this );
	m_spinBtnFFT1->Connect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnFFT1OnSpinUp ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED, wxDataViewEventHandler( Measure::m_SelectionChanged1 ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( Measure::m_OnLeftDown ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_MIDDLE_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_RIGHT_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_AUX1_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_AUX1_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_AUX2_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_AUX1_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_MOTION, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_AUX1_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_AUX2_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonCancelOnButtonClick ), NULL, this );
}

Measure::~Measure()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( Measure::DisplayOnInitDialog ) );
	m_checkBoxAutoClear->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Measure::m_checkBoxAutoClearOnCheckBox ), NULL, this );
	m_checkBoxAutoClearTrigger->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Measure::m_checkBoxAutoClearTriggerOnCheckBox ), NULL, this );
	m_buttonHistoryClear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonHistoryClearOnButtonClick ), NULL, this );
	m_buttonClearX->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonClearXOnButtonClick ), NULL, this );
	m_buttonClearY->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonClearYOnButtonClick ), NULL, this );
	m_buttonClearFFT->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonClearFFTOnButtonClick ), NULL, this );
	m_buttonCopy->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonCopyOnButtonClick ), NULL, this );
	m_buttonPickX0->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickX0OnButtonClick ), NULL, this );
	m_textCtrlX0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlX0OnTextEnter ), NULL, this );
	m_spinBtnX0->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnX0OnSpinDown ), NULL, this );
	m_spinBtnX0->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnX0OnSpinUp ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_sliderX0->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderX0OnScroll ), NULL, this );
	m_buttonPickX1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickX1OnButtonClick ), NULL, this );
	m_textCtrlX1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlX1OnTextEnter ), NULL, this );
	m_spinBtnX1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnX1OnSpinDown ), NULL, this );
	m_spinBtnX1->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnX1OnSpinUp ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_sliderX1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderX1OnScroll ), NULL, this );
	m_buttonPickY0->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickY0OnButtonClick ), NULL, this );
	m_textCtrlY0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlY0OnTextEnter ), NULL, this );
	m_choiceY0->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Measure::m_choiceY0OnChoice ), NULL, this );
	m_spinBtnY0->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnY0OnSpinDown ), NULL, this );
	m_spinBtnY0->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnY0OnSpinUp ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_sliderY0->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderY0OnScroll ), NULL, this );
	m_buttonPickY1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickY1OnButtonClick ), NULL, this );
	m_textCtrlY1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlY1OnTextEnter ), NULL, this );
	m_choiceY1->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Measure::m_choiceY1OnChoice ), NULL, this );
	m_spinBtnY1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnY1OnSpinDown ), NULL, this );
	m_spinBtnY1->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnY1OnSpinUp ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_sliderY1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderY1OnScroll ), NULL, this );
	m_buttonPickFFT0->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickFFT0OnButtonClick ), NULL, this );
	m_textCtrlFFT0->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlFFT0OnTextEnter ), NULL, this );
	m_spinBtnFFT0->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnFFT0OnSpinDown ), NULL, this );
	m_spinBtnFFT0->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnFFT0OnSpinUp ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_sliderFFT0->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderFFT0OnScroll ), NULL, this );
	m_buttonPickFFT1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonPickFFT1OnButtonClick ), NULL, this );
	m_textCtrlFFT1->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Measure::m_textCtrlFFT1OnTextEnter ), NULL, this );
	m_spinBtnFFT1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxSpinEventHandler( Measure::m_spinBtnFFT1OnSpinDown ), NULL, this );
	m_spinBtnFFT1->Disconnect( wxEVT_SCROLL_LINEUP, wxSpinEventHandler( Measure::m_spinBtnFFT1OnSpinUp ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_sliderFFT1->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Measure::m_sliderFFT1OnScroll ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_COMMAND_DATAVIEW_SELECTION_CHANGED, wxDataViewEventHandler( Measure::m_SelectionChanged1 ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( Measure::m_OnLeftDown ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_MIDDLE_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_MIDDLE_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_RIGHT_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_AUX1_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_AUX1_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_AUX2_DOWN, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_AUX1_UP, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_MOTION, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_MIDDLE_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_RIGHT_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_AUX1_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_AUX2_DCLICK, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_LEAVE_WINDOW, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_dataViewListCtrl1->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( Measure::m_dataViewListCtrl1OnMouseEvents ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Measure::m_buttonCancelOnButtonClick ), NULL, this );

}

Info::Info( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer157;
	bSizer157 = new wxBoxSizer( wxHORIZONTAL );

	m_notebook5 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH );
	m_panel11 = new wxPanel( m_notebook5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxVERTICAL );

	m_gplLogo = new wxStaticBitmap( m_panel11, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer102->Add( m_gplLogo, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_textCtrlLicense = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_MULTILINE|wxTE_PROCESS_TAB|wxTE_READONLY|wxVSCROLL );
	bSizer102->Add( m_textCtrlLicense, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	m_panel11->SetSizer( bSizer102 );
	m_panel11->Layout();
	bSizer102->Fit( m_panel11 );
	m_notebook5->AddPage( m_panel11, _("License"), false );
	m_panel12 = new wxPanel( m_notebook5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlInfo = new wxTextCtrl( m_panel12, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY );
	bSizer101->Add( m_textCtrlInfo, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel12->SetSizer( bSizer101 );
	m_panel12->Layout();
	bSizer101->Fit( m_panel12 );
	m_notebook5->AddPage( m_panel12, _("Information"), false );
	m_panel13 = new wxPanel( m_notebook5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxVERTICAL );

	m_staticText99 = new wxStaticText( m_panel13, wxID_ANY, _("This are the libraries that were used to build this program and their licenses."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText99->Wrap( -1 );
	bSizer103->Add( m_staticText99, 1, wxALL|wxEXPAND, 5 );

	m_notebook7 = new wxNotebook( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH|wxNB_MULTILINE );
	m_panel22 = new wxPanel( m_notebook7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1031;
	bSizer1031 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlGlew = new wxTextCtrl( m_panel22, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer1031->Add( m_textCtrlGlew, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel22->SetSizer( bSizer1031 );
	m_panel22->Layout();
	bSizer1031->Fit( m_panel22 );
	m_notebook7->AddPage( m_panel22, _("GLEW"), true );
	m_panel23 = new wxPanel( m_notebook7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10311;
	bSizer10311 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlKissFFT = new wxTextCtrl( m_panel23, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer10311->Add( m_textCtrlKissFFT, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel23->SetSizer( bSizer10311 );
	m_panel23->Layout();
	bSizer10311->Fit( m_panel23 );
	m_notebook7->AddPage( m_panel23, _("KISS-FFT"), false );
	m_panel231 = new wxPanel( m_notebook7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer103111;
	bSizer103111 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlwxWidgets = new wxTextCtrl( m_panel231, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer103111->Add( m_textCtrlwxWidgets, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel231->SetSizer( bSizer103111 );
	m_panel231->Layout();
	bSizer103111->Fit( m_panel231 );
	m_notebook7->AddPage( m_panel231, _("wxWidgets"), false );
	m_panel2311 = new wxPanel( m_notebook7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1031111;
	bSizer1031111 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlSDL2 = new wxTextCtrl( m_panel2311, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer1031111->Add( m_textCtrlSDL2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel2311->SetSizer( bSizer1031111 );
	m_panel2311->Layout();
	bSizer1031111->Fit( m_panel2311 );
	m_notebook7->AddPage( m_panel2311, _("SDL2"), false );
	m_panel23111 = new wxPanel( m_notebook7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10311111;
	bSizer10311111 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlCJSON = new wxTextCtrl( m_panel23111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer10311111->Add( m_textCtrlCJSON, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel23111->SetSizer( bSizer10311111 );
	m_panel23111->Layout();
	bSizer10311111->Fit( m_panel23111 );
	m_notebook7->AddPage( m_panel23111, _("cJSON"), false );
	m_panel231111 = new wxPanel( m_notebook7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer103111111;
	bSizer103111111 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlLibUSB = new wxTextCtrl( m_panel231111, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer103111111->Add( m_textCtrlLibUSB, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel231111->SetSizer( bSizer103111111 );
	m_panel231111->Layout();
	bSizer103111111->Fit( m_panel231111 );
	m_notebook7->AddPage( m_panel231111, _("libusb"), false );
	m_panel232 = new wxPanel( m_notebook7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1031111111;
	bSizer1031111111 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlPThreads = new wxTextCtrl( m_panel232, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer1031111111->Add( m_textCtrlPThreads, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel232->SetSizer( bSizer1031111111 );
	m_panel232->Layout();
	bSizer1031111111->Fit( m_panel232 );
	m_notebook7->AddPage( m_panel232, _("winpthreads"), false );
	m_panel28 = new wxPanel( m_notebook7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlLibPython = new wxTextCtrl( m_panel28, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_AUTO_URL|wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH );
	bSizer158->Add( m_textCtrlLibPython, 1, wxALL|wxEXPAND, 5 );


	m_panel28->SetSizer( bSizer158 );
	m_panel28->Layout();
	bSizer158->Fit( m_panel28 );
	m_notebook7->AddPage( m_panel28, _("Python"), false );

	bSizer103->Add( m_notebook7, 8, wxALL|wxEXPAND, 5 );


	m_panel13->SetSizer( bSizer103 );
	m_panel13->Layout();
	bSizer103->Fit( m_panel13 );
	m_notebook5->AddPage( m_panel13, _("Documentation"), true );
	m_panel17 = new wxPanel( m_notebook5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer1021;
	bSizer1021 = new wxBoxSizer( wxVERTICAL );

	m_textCtrlVersion = new wxTextCtrl( m_panel17, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textCtrlVersion->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_textCtrlVersion->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_textCtrlVersion->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_textCtrlVersion->Enable( false );

	bSizer1021->Add( m_textCtrlVersion, 0, wxALL|wxEXPAND, 5 );

	m_textCtrlDateTime = new wxTextCtrl( m_panel17, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	m_textCtrlDateTime->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );
	m_textCtrlDateTime->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_textCtrlDateTime->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_textCtrlDateTime->Enable( false );

	bSizer1021->Add( m_textCtrlDateTime, 0, wxALL|wxEXPAND, 5 );

	m_bitmapLogo = new wxStaticBitmap( m_panel17, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1021->Add( m_bitmapLogo, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	m_panel17->SetSizer( bSizer1021 );
	m_panel17->Layout();
	bSizer1021->Fit( m_panel17 );
	m_notebook5->AddPage( m_panel17, _("Version"), false );

	bSizer157->Add( m_notebook5, 1, wxALL|wxEXPAND, 5 );


	bSizer55->Add( bSizer157, 12, wxEXPAND, 5 );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );


	bSizer59->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonOk = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( m_buttonOk, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer59->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer55->Add( bSizer59, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer55 );
	this->Layout();
	bSizer55->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( Info::ThermalOnActivate ) );
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Info::InfoOnClose ) );
	m_textCtrlGlew->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlKissFFT->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlwxWidgets->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlSDL2->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlCJSON->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlLibUSB->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlPThreads->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlLibPython->Connect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Info::m_buttonOkOnButtonClick ), NULL, this );
}

Info::~Info()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( Info::ThermalOnActivate ) );
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( Info::InfoOnClose ) );
	m_textCtrlGlew->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlKissFFT->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlwxWidgets->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlSDL2->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlCJSON->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlLibUSB->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlPThreads->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_textCtrlLibPython->Disconnect( wxEVT_COMMAND_TEXT_URL, wxTextUrlEventHandler( Info::m_textCtrlGlewOnTextURL ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Info::m_buttonOkOnButtonClick ), NULL, this );

}

Debug::Debug( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxVERTICAL );

	m_textCtrl41 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer158->Add( m_textCtrl41, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bSizer55->Add( bSizer158, 10, wxEXPAND, 5 );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxHORIZONTAL );

	m_button561 = new wxButton( this, wxID_ANY, _("Reload"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_button561, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button56 = new wxButton( this, wxID_ANY, _("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_button56, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button562 = new wxButton( this, wxID_ANY, _("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_button562, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button5621 = new wxButton( this, wxID_ANY, _("Exit"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer159->Add( m_button5621, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer55->Add( bSizer159, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer55 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_ACTIVATE, wxActivateEventHandler( Debug::ThermalOnActivate ) );
	m_button561->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Debug::m_button561OnButtonClick ), NULL, this );
	m_button56->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Debug::m_button56OnButtonClick ), NULL, this );
	m_button562->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Debug::m_button562OnButtonClick ), NULL, this );
	m_button5621->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Debug::m_button5621OnButtonClick ), NULL, this );
}

Debug::~Debug()
{
	// Disconnect Events
	this->Disconnect( wxEVT_ACTIVATE, wxActivateEventHandler( Debug::ThermalOnActivate ) );
	m_button561->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Debug::m_button561OnButtonClick ), NULL, this );
	m_button56->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Debug::m_button56OnButtonClick ), NULL, this );
	m_button562->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Debug::m_button562OnButtonClick ), NULL, this );
	m_button5621->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Debug::m_button5621OnButtonClick ), NULL, this );

}

Storage::Storage( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );

	m_staticline21 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer35->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer156;
	bSizer156 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText112 = new wxStaticText( this, wxID_ANY, _("Type:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText112->Wrap( -1 );
	bSizer144->Add( m_staticText112, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceStorageChoices[] = { _("Memory"), _("Disk") };
	int m_choiceStorageNChoices = sizeof( m_choiceStorageChoices ) / sizeof( wxString );
	m_choiceStorage = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceStorageNChoices, m_choiceStorageChoices, 0 );
	m_choiceStorage->SetSelection( 0 );
	bSizer144->Add( m_choiceStorage, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText113 = new wxStaticText( this, wxID_ANY, _("Max Size:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText113->Wrap( -1 );
	bSizer144->Add( m_staticText113, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlStorage = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER|wxTE_RIGHT );
	bSizer144->Add( m_textCtrlStorage, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText114 = new wxStaticText( this, wxID_ANY, _("MegaByte"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114->Wrap( -1 );
	bSizer144->Add( m_staticText114, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer156->Add( bSizer144, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer35->Add( bSizer156, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer159;
	bSizer159 = new wxBoxSizer( wxHORIZONTAL );


	bSizer159->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText119 = new wxStaticText( this, wxID_ANY, _("Minimum Packet Size:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText119->Wrap( -1 );
	bSizer159->Add( m_staticText119, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choicePacketSizeChoices[] = { _("automatic"), _("512"), _("16384"), _("131072"), _("1048576") };
	int m_choicePacketSizeNChoices = sizeof( m_choicePacketSizeChoices ) / sizeof( wxString );
	m_choicePacketSize = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePacketSizeNChoices, m_choicePacketSizeChoices, 0 );
	m_choicePacketSize->SetSelection( 0 );
	bSizer159->Add( m_choicePacketSize, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText120 = new wxStaticText( this, wxID_ANY, _("Byte"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText120->Wrap( -1 );
	bSizer159->Add( m_staticText120, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer35->Add( bSizer159, 1, wxEXPAND, 5 );

	m_staticline20 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer35->Add( m_staticline20, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOk = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer155->Add( m_buttonOk, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonDefault = new wxButton( this, wxID_ANY, _("Default"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer155->Add( m_buttonDefault, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer155->Add( m_buttonCancel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer35->Add( bSizer155, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer35 );
	this->Layout();
	bSizer35->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_choiceStorage->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Storage::m_choiceStorageOnChoice ), NULL, this );
	m_textCtrlStorage->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Storage::m_textCtrlStorageOnTextEnter ), NULL, this );
	m_choicePacketSize->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Storage::m_choicePacketSizeOnChoice ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Storage::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Storage::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Storage::m_buttonCancelOnButtonClick ), NULL, this );
}

Storage::~Storage()
{
	// Disconnect Events
	m_choiceStorage->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Storage::m_choiceStorageOnChoice ), NULL, this );
	m_textCtrlStorage->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Storage::m_textCtrlStorageOnTextEnter ), NULL, this );
	m_choicePacketSize->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Storage::m_choicePacketSizeOnChoice ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Storage::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Storage::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Storage::m_buttonCancelOnButtonClick ), NULL, this );

}

Connection::Connection( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );

	m_staticline20 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer35->Add( m_staticline20, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer158;
	bSizer158 = new wxBoxSizer( wxHORIZONTAL );


	bSizer158->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText111 = new wxStaticText( this, wxID_ANY, _("Mode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	bSizer158->Add( m_staticText111, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choiceConnectionChoices[] = { _("USB"), _("Client<->Server") };
	int m_choiceConnectionNChoices = sizeof( m_choiceConnectionChoices ) / sizeof( wxString );
	m_choiceConnection = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceConnectionNChoices, m_choiceConnectionChoices, 0 );
	m_choiceConnection->SetSelection( 0 );
	bSizer158->Add( m_choiceConnection, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer158->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer35->Add( bSizer158, 1, wxEXPAND, 5 );

	m_staticline21 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer35->Add( m_staticline21, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer144;
	bSizer144 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText122 = new wxStaticText( this, wxID_ANY, _("IP:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText122->Wrap( -1 );
	bSizer144->Add( m_staticText122, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlIP = new wxTextCtrl( this, wxID_ANY, _("127.0.0.1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer144->Add( m_textCtrlIP, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText123 = new wxStaticText( this, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText123->Wrap( -1 );
	bSizer144->Add( m_staticText123, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrlPort = new wxTextCtrl( this, wxID_ANY, _("42250"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer144->Add( m_textCtrlPort, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer144->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer35->Add( bSizer144, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer1581;
	bSizer1581 = new wxBoxSizer( wxHORIZONTAL );


	bSizer1581->Add( 0, 0, 1, wxEXPAND, 5 );

	m_checkBoxConnected = new wxCheckBox( this, wxID_ANY, _("Connected"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1581->Add( m_checkBoxConnected, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonConnect = new wxButton( this, wxID_ANY, _("Connect"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1581->Add( m_buttonConnect, 1, wxALL, 5 );

	m_buttonDisconnect = new wxButton( this, wxID_ANY, _("Disconnect"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1581->Add( m_buttonDisconnect, 1, wxALL, 5 );


	bSizer1581->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer35->Add( bSizer1581, 1, wxEXPAND, 5 );

	m_staticline22 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer35->Add( m_staticline22, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer155;
	bSizer155 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonOk = new wxButton( this, wxID_ANY, _("Ok"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer155->Add( m_buttonOk, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonDefault = new wxButton( this, wxID_ANY, _("Default"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer155->Add( m_buttonDefault, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_buttonCancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer155->Add( m_buttonCancel, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer35->Add( bSizer155, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer35 );
	this->Layout();
	bSizer35->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_choiceConnection->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Connection::m_choiceConnectionOnChoice ), NULL, this );
	m_textCtrlIP->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Connection::m_textCtrlIPOnTextEnter ), NULL, this );
	m_textCtrlPort->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Connection::m_textCtrlPortOnTextEnter ), NULL, this );
	m_checkBoxConnected->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Connection::m_checkBoxConnectedOnCheckBox ), NULL, this );
	m_buttonConnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonConnectOnButtonClick ), NULL, this );
	m_buttonDisconnect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonDisconnectOnButtonClick ), NULL, this );
	m_buttonOk->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonCancelOnButtonClick ), NULL, this );
}

Connection::~Connection()
{
	// Disconnect Events
	m_choiceConnection->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Connection::m_choiceConnectionOnChoice ), NULL, this );
	m_textCtrlIP->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Connection::m_textCtrlIPOnTextEnter ), NULL, this );
	m_textCtrlPort->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Connection::m_textCtrlPortOnTextEnter ), NULL, this );
	m_checkBoxConnected->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( Connection::m_checkBoxConnectedOnCheckBox ), NULL, this );
	m_buttonConnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonConnectOnButtonClick ), NULL, this );
	m_buttonDisconnect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonDisconnectOnButtonClick ), NULL, this );
	m_buttonOk->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonOkOnButtonClick ), NULL, this );
	m_buttonDefault->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonDefaultOnButtonClick ), NULL, this );
	m_buttonCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Connection::m_buttonCancelOnButtonClick ), NULL, this );

}
