///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/spinbutt.h>
#include <wx/slider.h>
#include <wx/notebook.h>
#include <wx/filepicker.h>
#include <wx/radiobut.h>
#include <wx/statline.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/dataview.h>
#include <wx/scrolwin.h>
#include <wx/statbmp.h>
#include <wx/stc/stc.h>

#include "guiheader.h"

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Osciloskop
///////////////////////////////////////////////////////////////////////////////
class Osciloskop : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu2;
		wxMenu* m_menu3;
		wxMenu* m_menu4;
		wxMenu* m_menu5;
		wxMenu* m_menu8;
		wxMenu* m_menu7;
		wxPanel* m_panel26;
		wxCheckBox* m_checkBox26;
		wxButton* m_buttonConnect;
		wxButton* m_buttonDisconnect;
		wxButton* m_buttonUndo;
		wxButton* m_buttonRedo;
		wxStaticText* m_staticText19;
		wxChoice* m_comboBoxTimeControl;
		wxNotebook* m_notebook7;
		wxPanel* m_panel251;
		wxStaticText* m_staticText141;
		wxChoice* m_comboBoxTimeCapture;
		wxCheckBox* m_checkBoxETS;
		wxCheckBox* m_checkBoxFull;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textCtrlTimePosition;
		wxSpinButton* m_spinBtnXPos;
		wxSlider* m_sliderTimePosition;
		wxStaticText* m_staticText122;
		wxTextCtrl* m_textCtrlTimeFrame;
		wxSpinButton* m_spinBtnFrameHistory;
		wxSlider* m_sliderTimeFrame;
		wxButton* m_buttonPlay;
		wxButton* m_buttonPause;
		wxButton* m_buttonCapture;
		wxButton* m_buttonSimulate;
		wxButton* m_buttonClear;
		wxStaticText* m_staticText181;
		wxTextCtrl* m_textCtrlTimeFrameSize;
		wxStaticText* m_staticText1811;
		wxTextCtrl* m_textCtrlTimeFFTSize;
		wxNotebook* m_notebook4;
		wxPanel* m_panel15;
		wxStaticText* m_staticText34;
		wxChoice* m_comboBoxCh0Capture;
		wxStaticText* m_staticTextCh0Scale;
		wxTextCtrl* m_textCtrlCh0Scale;
		wxChoice* m_choiceCh0ACDC;
		wxCheckBox* m_checkBoxCh0Invert;
		wxCheckBox* m_checkBoxCh0Ground;
		wxCheckBox* m_checkBoxSignal1;
		wxCheckBox* m_checkBoxFFT1;
		wxCheckBox* m_checkBoxAvg01;
		wxStaticText* m_staticText1221;
		wxTextCtrl* m_textCtrlCh0Position;
		wxSpinButton* m_spinBtnCh0YPos;
		wxSlider* m_sliderCh0Position;
		wxPanel* m_panel16;
		wxStaticText* m_staticText341;
		wxChoice* m_comboBoxCh1Capture;
		wxStaticText* m_staticTextCh1Scale;
		wxTextCtrl* m_textCtrlCh1Scale;
		wxChoice* m_choiceCh1ACDC;
		wxCheckBox* m_checkBoxCh1Invert;
		wxCheckBox* m_checkBoxCh1Ground;
		wxCheckBox* m_checkBoxSignal2;
		wxCheckBox* m_checkBoxFFT2;
		wxCheckBox* m_checkBoxAvg02;
		wxStaticText* m_staticText12211;
		wxTextCtrl* m_textCtrlCh1Position;
		wxSpinButton* m_spinBtnCh1YPos;
		wxSlider* m_sliderCh1Position;
		wxPanel* m_panel161;
		wxStaticText* m_staticTextFunction;
		wxChoice* m_comboBoxFunction;
		wxCheckBox* m_checkBoxXYVoltageGraph;
		wxCheckBox* m_checkBoxSignalF;
		wxCheckBox* m_checkBoxFFTF;
		wxStaticText* m_staticText116;
		wxTextCtrl* m_textCtrlFuncCustom;
		wxPanel* m_panel9;
		wxStaticText* m_staticText1232;
		wxChoice* m_choiceDOnOff815;
		wxChoice* m_choiceDOnOff70;
		wxStaticText* m_staticText1242;
		wxCheckBox* m_checkBox12;
		wxCheckBox* m_checkBox10;
		wxCheckBox* m_checkBox8;
		wxCheckBox* m_checkBox11;
		wxCheckBox* m_checkBox9;
		wxCheckBox* m_checkBox7;
		wxStaticText* m_staticText109;
		wxStaticText* m_staticText110;
		wxCheckBox* m_checkBox6;
		wxCheckBox* m_checkBox4;
		wxCheckBox* m_checkBox2;
		wxCheckBox* m_checkBox5;
		wxCheckBox* m_checkBox3;
		wxCheckBox* m_checkBox1;
		wxPanel* m_panel91;
		wxStaticText* m_staticText1251;
		wxChoice* m_choiceDS815;
		wxChoice* m_choiceInputOutput;
		wxStaticText* m_staticText91;
		wxChoice* m_choiceBit11;
		wxStaticText* m_staticText92;
		wxChoice* m_choiceBit9;
		wxStaticText* m_staticText971;
		wxChoice* m_choiceBit7;
		wxStaticText* m_staticText95;
		wxChoice* m_choiceBit10;
		wxStaticText* m_staticText96;
		wxChoice* m_choiceBit8;
		wxStaticText* m_staticText101;
		wxChoice* m_choiceBit6;
		wxStaticText* m_staticText126;
		wxStaticText* m_staticText125;
		wxChoice* m_choiceInputOutput1;
		wxChoice* m_choiceDS70;
		wxStaticText* m_staticText135;
		wxStaticText* m_staticText98;
		wxChoice* m_choiceBit5;
		wxStaticText* m_staticText99;
		wxChoice* m_choiceBit3;
		wxStaticText* m_staticText100;
		wxChoice* m_choiceBit1;
		wxStaticText* m_staticText102;
		wxChoice* m_choiceBit4;
		wxStaticText* m_staticText103;
		wxChoice* m_choiceBit2;
		wxStaticText* m_staticText104;
		wxChoice* m_choiceBit0;
		wxPanel* m_panel25;
		wxStaticText* m_staticText821;
		wxFilePickerCtrl* m_filePicker1;
		wxButton* m_buttonCustomFile;
		wxStaticText* m_staticText80;
		wxTextCtrl* m_textCtrlDigitalVoltage;
		wxSpinButton* m_spinBtnDigVoltage;
		wxStaticText* m_staticText108;
		wxTextCtrl* m_textCtrlFreqDivider;
		wxStaticText* m_staticText97;
		wxStaticText* m_staticTextMhz;
		wxNotebook* m_notebook3;
		wxPanel* m_panel3;
		wxStaticText* m_staticText47;
		wxChoice* m_comboBoxTrigger;
		wxStaticText* m_staticText45;
		wxChoice* m_comboBoxTriggerSource;
		wxStaticText* m_staticText46;
		wxChoice* m_comboBoxTriggerSlope;
		wxButton* m_buttonReArm;
		wxRadioButton* m_radioBtnTriggered;
		wxStaticLine* m_staticline11;
		wxStaticText* m_staticText1222;
		wxTextCtrl* m_textCtrlTriggerLevel;
		wxSpinButton* m_spinBtnTrigLevel;
		wxSlider* m_sliderTriggerLevel;
		wxStaticText* m_staticText12221;
		wxTextCtrl* m_textCtrlTriggerHisteresis;
		wxSpinButton* m_spinBtnTrigHis;
		wxSlider* m_sliderTriggerHisteresis;
		wxStaticText* m_staticText12222;
		wxTextCtrl* m_textCtrlTriggerPre;
		wxSpinButton* m_spinBtnTrigPre;
		wxSlider* m_sliderTriggerPre;
		wxStaticText* m_staticText55;
		wxTextCtrl* m_textCtrlTriggerHoldoff;
		wxSpinButton* m_spinBtnTrigHoldoff;
		wxSlider* m_sliderTriggerHoldoff;
		wxPanel* m_panel13;
		wxStaticText* m_staticText1231;
		wxChoice* m_choiceBit158;
		wxChoice* m_choiceBit70;
		wxStaticText* m_staticText1241;
		wxStaticText* m_staticTextBit11;
		wxChoice* m_comboBoxBit11;
		wxStaticText* m_staticTextBit9;
		wxChoice* m_comboBoxBit9;
		wxStaticText* m_staticTextBit6;
		wxChoice* m_comboBoxBit6;
		wxStaticText* m_staticTextBit10;
		wxChoice* m_comboBoxBit10;
		wxStaticText* m_staticTextBit8;
		wxChoice* m_comboBoxBit8;
		wxStaticText* m_staticTextBit7;
		wxChoice* m_comboBoxBit7;
		wxStaticText* m_staticText123;
		wxStaticText* m_staticText124;
		wxStaticText* m_staticTextBit5;
		wxChoice* m_comboBoxBit5;
		wxStaticText* m_staticTextBit3;
		wxChoice* m_comboBoxBit3;
		wxStaticText* m_staticTextBit1;
		wxChoice* m_comboBoxBit1;
		wxStaticText* m_staticTextBit4;
		wxChoice* m_comboBoxBit4;
		wxStaticText* m_staticTextBit2;
		wxChoice* m_comboBoxBit2;
		wxStaticText* m_staticTextBit0;
		wxChoice* m_comboBoxBit0;
		wxPanel* m_panel27;
		wxStaticText* m_staticText63;
		wxChoice* m_comboBoxDigitalStage;
		wxStaticText* m_staticText64;
		wxTextCtrl* m_textCtrDigitallDelay;
		wxStaticText* m_staticText65;
		wxChoice* m_comboBoxDigitalStageStart;
		wxStaticText* m_staticText66;
		wxChoice* m_comboBoxDigitalMode;
		wxStaticText* m_staticText68;
		wxChoice* m_comboBoxDigitalSerialChannel;

		// Virtual event handlers, overide them in your derived class
		virtual void onActivate( wxActivateEvent& event ) { event.Skip(); }
		virtual void onActivateApp( wxActivateEvent& event ) { event.Skip(); }
		virtual void onClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnIdle( wxIdleEvent& event ) { event.Skip(); }
		virtual void OnSetFocus( wxFocusEvent& event ) { event.Skip(); }
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void m_menuItem1OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem2OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem3OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem20OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem21OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem22OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem23OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem6OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem8OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem9OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemSoftwareOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem11OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemReadEEPROMOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemWriteEEPROMOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem12OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemWriteCallibrateOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemReadCallibrateOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemWriteCertificateOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemReadCertificateOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemLockCertificateOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemResetEEPROMOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem15OnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemDebugOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItemInfoOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonConnectOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDisconnectOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonUndoOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonRedoOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxTimeControlOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxTimeCaptureOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxETSOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxFullOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlTimePositionOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnXPosOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnXPosOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderTimePositionOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlTimeFrameOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnFrameHistoryOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnFrameHistoryOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderTimeFrameOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_buttonPlayOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonPauseOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCaptureOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonSimulateOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonClearOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlTimeFrameSizeOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlTimeFFTSizeOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxCh0CaptureOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlCh0ScaleOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceCh0ACDCOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxCh0InvertOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxCh0GroundOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxSignal1OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxFFT1OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxAvg01OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlCh0PositionOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh0YPosOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh0YPosOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderCh0PositionOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_comboBoxCh1CaptureOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlCh1ScaleOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceCh1ACDCOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxCh1InvertOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxCh1GroundOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxSignal2OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxFFT2OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxAvg02OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlCh1PositionOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh1YPosOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh1YPosOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderCh1PositionOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_comboBoxFunctionTypeOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxXYVoltageGraphOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxSignalFOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxFFTFOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlFuncCustomOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceDOnOff815OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceDOnOff70OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox12OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox10OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox8OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox11OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox9OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox7OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox6OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox4OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox2OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox5OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox3OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox1OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceDS815OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceInputOutputOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit11OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit9OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit7OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit10OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit8OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit6OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceInputOutput1OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceDS70OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit5OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit3OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit1OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit4OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit2OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit0OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_filePicker1OnFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void m_buttonCustomFileOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlDigitalVoltageOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnDigVoltageOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnDigVoltageOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_textCtrlFreqDividerOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxTriggerOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxTriggerSourceOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxTriggerSlopeOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonReArmOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlTriggerLevelOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnTrigLevelOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnTrigLevelOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderTriggerLevelOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlTriggerHisteresisOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnTrigHisOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnTrigHisOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderTriggerHisteresisOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlTriggerPreOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnTrigPreOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnTrigPreOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderTriggerPreOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlTriggerHoldoffOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnTrigHoldoffOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnTrigHoldoffOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderTriggerHoldoffOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_choiceBit158OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceBit70OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit11OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit9OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit6OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit10OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit8OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit7OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit5OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit3OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit1OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit4OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit2OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxBit0OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxDigitalStageOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrDigitallDelayOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxDigitalStageStartOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxDigitalModeOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxDigitalSerialChannelOnCombobox( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxMenuItem* m_menuItemDebug;

		Osciloskop( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Oscilloscope"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Osciloskop();

};

///////////////////////////////////////////////////////////////////////////////
/// Class SoftwareGenerator
///////////////////////////////////////////////////////////////////////////////
class SoftwareGenerator : public wxDialog
{
	private:

	protected:
		wxNotebook* m_notebook3;
		wxPanel* m_panel14;
		wxStaticText* m_staticText3911;
		wxChoice* m_comboBoxType0;
		wxStaticText* m_staticText4021;
		wxTextCtrl* m_textCtrlPeriod0;
		wxChoice* m_comboBoxPeriod0;
		wxStaticText* m_staticText40121;
		wxTextCtrl* m_textCtrlPeek0;
		wxChoice* m_comboBoxPeek0;
		wxStaticText* m_staticText401121;
		wxTextCtrl* m_textCtrlSpeed0;
		wxStaticText* m_staticText4011111;
		wxTextCtrl* m_textCtrlAvery0;
		wxButton* m_buttonOn0;
		wxButton* m_buttonOff0;
		wxPanel* m_panel15;
		wxStaticText* m_staticText39111;
		wxChoice* m_comboBoxType1;
		wxStaticText* m_staticText40211;
		wxTextCtrl* m_textCtrlPeriod1;
		wxChoice* m_comboBoxPeriod1;
		wxStaticText* m_staticText401211;
		wxTextCtrl* m_textCtrlPeek1;
		wxChoice* m_comboBoxPeek1;
		wxStaticText* m_staticText4011211;
		wxTextCtrl* m_textCtrlSpeed1;
		wxStaticText* m_staticText40111111;
		wxTextCtrl* m_textCtrlAvery1;
		wxButton* m_buttonOn1;
		wxButton* m_buttonOff1;
		wxButton* m_buttonOk;
		wxButton* m_buttonDefault;
		wxButton* m_buttonCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void SoftwareGeneratorOnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void m_comboBoxType0OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlPeriod0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxPeriod0OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlPeek0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxPeek0OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlSpeed0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlAvery0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOn0OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOff0OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxType1OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlPeriod1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxPeriod1OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlPeek1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxPeek1OnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlSpeed1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlAvery1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOn1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOff1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDefaultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCancelOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		SoftwareGenerator( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("SoftwareGenerator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~SoftwareGenerator();

};

///////////////////////////////////////////////////////////////////////////////
/// Class HardwareGenerator
///////////////////////////////////////////////////////////////////////////////
class HardwareGenerator : public wxDialog
{
	private:

	protected:
		wxNotebook* m_notebook3;
		wxPanel* m_panel14;
		wxStaticText* m_staticText54;
		wxChoice* m_comboBoxType;
		wxStaticText* m_staticText55;
		wxTextCtrl* m_textCtrlFrequency;
		wxStaticText* m_staticText551;
		wxTextCtrl* m_textCtrlVoltage0;
		wxSpinButton* m_spinBtnCh0Volt;
		wxSlider* m_sliderVoltage;
		wxStaticText* m_staticText5511;
		wxTextCtrl* m_textCtrlOffset0;
		wxSpinButton* m_spinBtnCh0Offset;
		wxSlider* m_sliderOffset;
		wxStaticText* m_staticText55111;
		wxTextCtrl* m_textCtrlSquareDuty0;
		wxSpinButton* m_spinBtnGen0SqrDuty;
		wxSlider* m_sliderSquareDuty;
		wxStaticText* m_staticText551111;
		wxCheckBox* m_checkBoxSawSlope;
		wxFilePickerCtrl* m_filePicker1;
		wxButton* m_buttonCustomFile;
		wxButton* m_buttonOn0;
		wxButton* m_buttonOff0;
		wxPanel* m_panel15;
		wxStaticText* m_staticText541;
		wxChoice* m_comboBoxType1;
		wxStaticText* m_staticText552;
		wxTextCtrl* m_textCtrlFrequency1;
		wxStaticText* m_staticText5512;
		wxTextCtrl* m_textCtrlVoltage1;
		wxSpinButton* m_spinBtnCh1Volt;
		wxSlider* m_sliderVoltage1;
		wxStaticText* m_staticText55112;
		wxTextCtrl* m_textCtrlOffset1;
		wxSpinButton* m_spinBtnCh1Offset;
		wxSlider* m_sliderOffset1;
		wxStaticText* m_staticText551112;
		wxTextCtrl* m_textCtrlSquareDuty1;
		wxSpinButton* m_spinBtnGen1SqrDuty;
		wxSlider* m_sliderSquareDuty1;
		wxStaticText* m_staticText5511111;
		wxCheckBox* m_checkBoxSawSlope1;
		wxFilePickerCtrl* m_filePicker11;
		wxButton* m_buttonCustomFile1;
		wxButton* m_buttonOn1;
		wxButton* m_buttonOff1;
		wxButton* m_buttonOk;
		wxButton* m_buttonDefault;
		wxButton* m_buttonCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void HardwareGeneratorOnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void m_comboBoxTypeOnCombobox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlFrequencyOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlVoltage0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh0VoltOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh0VoltOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderVoltageOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlOffset0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh0OffsetOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh0OffsetOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderOffsetOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlSquareDuty0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnGen0SqrDutyOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnGen0SqrDutyOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderSquareDutyOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_checkBoxSawSlopeOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_filePicker1OnFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void m_buttonCustomFileOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOn0OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOff0OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_comboBoxType1OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlFrequency1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlVoltage1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh1VoltOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh1VoltOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderVoltage1OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlOffset1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh1OffsetOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCh1OffsetOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderOffset1OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlSquareDuty1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnGen1SqrDutyOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnGen1SqrDutyOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderSquareDuty1OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_checkBoxSawSlope1OnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_filePicker11OnFileChanged( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void m_buttonCustomFile1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOn1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOff1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDefaultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCancelOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		HardwareGenerator( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("HardwareGenerator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~HardwareGenerator();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Thermal
///////////////////////////////////////////////////////////////////////////////
class Thermal : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText52;
		wxTextCtrl* m_textCtrlHeating;
		wxSpinButton* m_spinBtnHeating;
		wxSlider* m_sliderHeat;
		wxStaticText* m_staticText53;
		wxTextCtrl* m_textCtrlCooling;
		wxSpinButton* m_spinBtnCooling;
		wxSlider* m_sliderCool;
		wxCheckBox* m_checkBoxEnabled;
		wxStaticLine* m_staticline5;
		wxButton* m_buttonOk;
		wxButton* m_buttonDefault;
		wxButton* m_buttonCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void ThermalOnActivate( wxActivateEvent& event ) { event.Skip(); }
		virtual void m_textCtrlHeatingOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnHeatingOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnHeatingOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderHeatOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrlCoolingOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCoolingOnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnCoolingOnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderCoolOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_checkBoxEnabledOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDefaultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCancelOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		Thermal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Thermal"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Thermal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Display
///////////////////////////////////////////////////////////////////////////////
class Display : public wxDialog
{
	private:

	protected:
		wxCheckBox* m_checkBoxUnits;
		wxCheckBox* m_checkBoxAxis;
		wxCheckBox* m_checkBoxGrid;
		wxCheckBox* m_checkBoxFFTUnit;
		wxCheckBox* m_checkBoxFFTAxis;
		wxCheckBox* m_checkBoxFFTGrid;
		wxCheckBox* m_checkBoxDigitalUnit;
		wxCheckBox* m_checkBoxDigitalAxis;
		wxCheckBox* m_checkBoxDigitalGrid;
		wxStaticText* m_staticText78;
		wxChoice* m_choiceSignal;
		wxStaticText* m_staticText38;
		wxTextCtrl* m_textCtrlSignal;
		wxSlider* m_sliderSignal;
		wxStaticText* m_staticText79;
		wxChoice* m_choiceFFT;
		wxStaticText* m_staticText39;
		wxTextCtrl* m_textCtrlFFT;
		wxSlider* m_sliderFFT;
		wxStaticText* m_staticText391;
		wxChoice* m_choiceFFTY;
		wxStaticText* m_staticText3911;
		wxChoice* m_choiceFFTX;
		wxStaticLine* m_staticline9;
		wxCheckBox* m_checkBox3dSolid;
		wxCheckBox* m_checkBox3dLight;
		wxCheckBox* m_checkBox3dDepthTest;
		wxStaticText* m_staticText962;
		wxTextCtrl* m_textCtrl3dAlphaCh0;
		wxStaticText* m_staticText992;
		wxSlider* m_slider3dAlphaCh0;
		wxStaticText* m_staticText1002;
		wxStaticText* m_staticText9621;
		wxTextCtrl* m_textCtrl3dAlphaCh1;
		wxStaticText* m_staticText9921;
		wxSlider* m_slider3dAlphaCh1;
		wxStaticText* m_staticText10021;
		wxStaticText* m_staticText96211;
		wxTextCtrl* m_textCtrl3dAlphaFun;
		wxStaticText* m_staticText99211;
		wxSlider* m_slider3dAlphaFun;
		wxStaticText* m_staticText100211;
		wxStaticLine* m_staticline10;
		wxStaticText* m_staticText96;
		wxTextCtrl* m_textCtrl3dTessalation;
		wxStaticText* m_staticText99;
		wxSlider* m_slider3dTessalation;
		wxStaticText* m_staticText100;
		wxStaticText* m_staticText961;
		wxTextCtrl* m_textCtrl2dTessalation;
		wxStaticText* m_staticText991;
		wxSlider* m_slider2dTessalation;
		wxStaticText* m_staticText1001;
		wxStaticLine* m_staticline4;
		wxButton* m_buttonOk;
		wxButton* m_buttonDefault;
		wxButton* m_buttonCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void DisplayOnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void m_checkBoxUnitsOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxAxisOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxGridOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxFFTUnitOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxFFTAxisOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxFFTGridOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxDigitalUnitOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxDigitalAxisOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxDigitalGridOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceSignalOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlSignalOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_sliderSignalOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_choiceFFTOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlFFTOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_sliderFFTOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_choiceFFTYOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceFFTXOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox3dSolidOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox3dLightOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBox3dDepthTestOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrl3dAlphaCh0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider3dAlphaCh0OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrl3dAlphaCh1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider3dAlphaCh1OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrl3dAlphaFunOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider3dAlphaFunOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrl3dTessalationOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider3dTessalationOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_textCtrl2dTessalationOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_slider2dTessalationOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_buttonOkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDefaultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCancelOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		Display( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Display"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Display();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Measure
///////////////////////////////////////////////////////////////////////////////
class Measure : public wxDialog
{
	private:

	protected:
		wxCheckBox* m_checkBoxAutoClear;
		wxCheckBox* m_checkBoxAutoClearTrigger;
		wxButton* m_buttonHistoryClear;
		wxButton* m_buttonClearX;
		wxButton* m_buttonClearY;
		wxButton* m_buttonClearFFT;
		wxButton* m_buttonCopy;
		wxButton* m_buttonPickX0;
		wxSpinButton* m_spinBtnX0;
		wxButton* m_buttonPickX1;
		wxSpinButton* m_spinBtnX1;
		wxButton* m_buttonPickY0;
		wxSpinButton* m_spinBtnY0;
		wxButton* m_buttonPickY1;
		wxSpinButton* m_spinBtnY1;
		wxButton* m_buttonPickFFT0;
		wxSpinButton* m_spinBtnFFT0;
		wxButton* m_buttonPickFFT1;
		wxSpinButton* m_spinBtnFFT1;
		wxScrolledWindow* m_scrolledWindow1;
		wxDataViewListCtrl* m_dataViewListCtrl1;
		wxButton* m_buttonOk;
		wxButton* m_buttonDefault;
		wxButton* m_buttonCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void DisplayOnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void m_checkBoxAutoClearOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxAutoClearTriggerOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonHistoryClearOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonClearXOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonClearYOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonClearFFTOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCopyOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonPickX0OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlX0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnX0OnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnX0OnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderX0OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_buttonPickX1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlX1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnX1OnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnX1OnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderX1OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_buttonPickY0OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlY0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceY0OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnY0OnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnY0OnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderY0OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_buttonPickY1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlY1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choiceY1OnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnY1OnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnY1OnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderY1OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_buttonPickFFT0OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlFFT0OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnFFT0OnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnFFT0OnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderFFT0OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_buttonPickFFT1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlFFT1OnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_spinBtnFFT1OnSpinDown( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_spinBtnFFT1OnSpinUp( wxSpinEvent& event ) { event.Skip(); }
		virtual void m_sliderFFT1OnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_SelectionChanged1( wxDataViewEvent& event ) { event.Skip(); }
		virtual void m_OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_dataViewListCtrl1OnMouseEvents( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_buttonOkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDefaultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCancelOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxTextCtrl* m_textCtrlX0;
		wxChoice* m_choiceX0;
		wxSlider* m_sliderX0;
		wxTextCtrl* m_textCtrlX1;
		wxChoice* m_choiceX1;
		wxSlider* m_sliderX1;
		wxTextCtrl* m_textCtrlY0;
		wxChoice* m_choiceY0;
		wxSlider* m_sliderY0;
		wxTextCtrl* m_textCtrlY1;
		wxChoice* m_choiceY1;
		wxSlider* m_sliderY1;
		wxTextCtrl* m_textCtrlFFT0;
		wxChoice* m_choiceFFT0;
		wxSlider* m_sliderFFT0;
		wxTextCtrl* m_textCtrlFFT1;
		wxChoice* m_choiceFFT1;
		wxSlider* m_sliderFFT1;

		Measure( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Measure"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE );
		~Measure();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Info
///////////////////////////////////////////////////////////////////////////////
class Info : public wxDialog
{
	private:

	protected:
		wxNotebook* m_notebook5;
		wxPanel* m_panel11;
		wxStaticBitmap* m_gplLogo;
		wxTextCtrl* m_textCtrlLicense;
		wxPanel* m_panel12;
		wxTextCtrl* m_textCtrlInfo;
		wxPanel* m_panel13;
		wxStaticText* m_staticText99;
		wxNotebook* m_notebook7;
		wxPanel* m_panel22;
		wxTextCtrl* m_textCtrlGlew;
		wxPanel* m_panel23;
		wxTextCtrl* m_textCtrlKissFFT;
		wxPanel* m_panel231;
		wxTextCtrl* m_textCtrlwxWidgets;
		wxPanel* m_panel2311;
		wxTextCtrl* m_textCtrlSDL2;
		wxPanel* m_panel23111;
		wxTextCtrl* m_textCtrlCJSON;
		wxPanel* m_panel231111;
		wxTextCtrl* m_textCtrlLibUSB;
		wxPanel* m_panel232;
		wxTextCtrl* m_textCtrlPThreads;
		wxPanel* m_panel28;
		wxTextCtrl* m_textCtrlLibPython;
		wxPanel* m_panel17;
		wxTextCtrl* m_textCtrlVersion;
		wxTextCtrl* m_textCtrlDateTime;
		wxStaticBitmap* m_bitmapLogo;
		wxButton* m_buttonOk;

		// Virtual event handlers, overide them in your derived class
		virtual void ThermalOnActivate( wxActivateEvent& event ) { event.Skip(); }
		virtual void InfoOnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void m_textCtrlGlewOnTextURL( wxTextUrlEvent& event ) { event.Skip(); }
		virtual void m_buttonOkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		Info( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxSTAY_ON_TOP );
		~Info();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Debug
///////////////////////////////////////////////////////////////////////////////
class Debug : public wxDialog
{
	private:

	protected:
		wxStyledTextCtrl* m_scintilla1;
		wxButton* m_buttonStart;
		wxButton* m_buttonStop;
		wxButton* m_buttonSave;
		wxButton* m_buttonLua;
		wxButton* m_buttonHelp;

		// Virtual event handlers, overide them in your derived class
		virtual void ThermalOnActivate( wxActivateEvent& event ) { event.Skip(); }
		virtual void m_buttonStartOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonStopOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonSaveOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonLuaOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonHelpOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:
		wxTextCtrl* m_textCtrlOutput;

		Debug( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Debug"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 877,700 ), long style = wxCAPTION|wxCLOSE_BOX|wxRESIZE_BORDER );
		~Debug();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Storage
///////////////////////////////////////////////////////////////////////////////
class Storage : public wxDialog
{
	private:

	protected:
		wxStaticLine* m_staticline21;
		wxStaticText* m_staticText112;
		wxChoice* m_choiceStorage;
		wxStaticText* m_staticText113;
		wxTextCtrl* m_textCtrlStorage;
		wxStaticText* m_staticText114;
		wxStaticText* m_staticText119;
		wxChoice* m_choicePacketSize;
		wxStaticText* m_staticText120;
		wxStaticLine* m_staticline20;
		wxButton* m_buttonOk;
		wxButton* m_buttonDefault;
		wxButton* m_buttonCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void m_choiceStorageOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlStorageOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_choicePacketSizeOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDefaultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCancelOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		Storage( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Storage"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~Storage();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Connection
///////////////////////////////////////////////////////////////////////////////
class Connection : public wxDialog
{
	private:

	protected:
		wxStaticLine* m_staticline20;
		wxStaticText* m_staticText111;
		wxChoice* m_choiceConnection;
		wxStaticLine* m_staticline21;
		wxStaticText* m_staticText122;
		wxTextCtrl* m_textCtrlIP;
		wxStaticText* m_staticText123;
		wxTextCtrl* m_textCtrlPort;
		wxCheckBox* m_checkBoxConnected;
		wxButton* m_buttonConnect;
		wxButton* m_buttonDisconnect;
		wxStaticLine* m_staticline22;
		wxButton* m_buttonOk;
		wxButton* m_buttonDefault;
		wxButton* m_buttonCancel;

		// Virtual event handlers, overide them in your derived class
		virtual void m_choiceConnectionOnChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlIPOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_textCtrlPortOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_checkBoxConnectedOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonConnectOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDisconnectOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonOkOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonDefaultOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_buttonCancelOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		Connection( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Connection"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~Connection();

};

