////////////////////////////////////////////////////////////////////////////////
//    ScopeFun Oscilloscope ( http://www.scopefun.com )
//    Copyright (C) 2016 - 2021 David Košenina
//
//    This file is part of ScopeFun Oscilloscope.
//
//    ScopeFun Oscilloscope is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    ScopeFun Oscilloscope is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this ScopeFun Oscilloscope.  If not, see <http://www.gnu.org/licenses/>.
//
////////////////////////////////////////////////////////////////////////////////
enuSelection( wxCommandEvent& event );
		void m_menuItem20OnMenuSelection( wxCommandEvent& event );
		void m_menuItem21OnMenuSelection( wxCommandEvent& event );
		void m_menuItem22OnMenuSelection( wxCommandEvent& event );
		void m_menuItem23OnMenuSelection( wxCommandEvent& event );
		void m_menuItem6OnMenuSelection( wxCommandEvent& event );
		void m_menuItem8OnMenuSelection( wxCommandEvent& event );
		void m_menuItem9OnMenuSelection( wxCommandEvent& event );
		void m_menuItemSoftwareOnMenuSelection( wxCommandEvent& event );
		void m_menuItem11OnMenuSelection( wxCommandEvent& event );
		void m_menuItemReadEEPROMOnMenuSelection( wxCommandEvent& event );
		void m_menuItemWriteEEPROMOnMenuSelection( wxCommandEvent& event );
		void m_menuItem12OnMenuSelection( wxCommandEvent& event );
		void m_menuItemWriteCallibrateOnMenuSelection( wxCommandEvent& event );
		void m_menuItemReadCallibrateOnMenuSelection( wxCommandEvent& event );
		void m_menuItemWriteCertificateOnMenuSelection( wxCommandEvent& event );
		void m_menuItemReadCertificateOnMenuSelection( wxCommandEvent& event );
		void m_menuItemLockCertificateOnMenuSelection( wxCommandEvent& event );
		void m_menuItemResetEEPROMOnMenuSelection( wxCommandEvent& event );
		void m_menuItem15OnMenuSelection( wxCommandEvent& event );
		void m_menuItemDebugOnMenuSelection( wxCommandEvent& event );
		void m_menuItemInfoOnMenuSelection( wxCommandEvent& event );
		void m_buttonConnectOnButtonClick( wxCommandEvent& event );
		void m_buttonDisconnectOnButtonClick( wxCommandEvent& event );
		void m_buttonUndoOnButtonClick( wxCommandEvent& event );
		void m_buttonRedoOnButtonClick( wxCommandEvent& event );
		void m_comboBoxTimeControlOnCombobox( wxCommandEvent& event );
		void m_comboBoxTimeCaptureOnCombobox( wxCommandEvent& event );
		void m_checkBoxETSOnCheckBox( wxCommandEvent& event );
		void m_checkBoxFullOnCheckBox( wxCommandEvent& event );
		void m_textCtrlTimePositionOnTextEnter( wxCommandEvent& event );
		void m_spinBtnXPosOnSpinDown( wxSpinEvent& event );
		void m_spinBtnXPosOnSpinUp( wxSpinEvent& event );
		void m_sliderTimePositionOnScroll( wxScrollEvent& event );
		void m_textCtrlTimeFrameOnTextEnter( wxCommandEvent& event );
		void m_spinBtnFrameHistoryOnSpinDown( wxSpinEvent& event );
		void m_spinBtnFrameHistoryOnSpinUp( wxSpinEvent& event );
		void m_sliderTimeFrameOnScroll( wxScrollEvent& event );
		void m_buttonPlayOnButtonClick( wxCommandEvent& event );
		void m_buttonPauseOnButtonClick( wxCommandEvent& event );
		void m_buttonCaptureOnButtonClick( wxCommandEvent& event );
		void m_buttonSimulateOnButtonClick( wxCommandEvent& event );
		void m_buttonClearOnButtonClick( wxCommandEvent& event );
		void m_textCtrlTimeFrameSizeOnTextEnter( wxCommandEvent& event );
		void m_textCtrlTimeFFTSizeOnTextEnter( wxCommandEvent& event );
		void m_comboBoxCh0CaptureOnCombobox( wxCommandEvent& event );
		void m_textCtrlCh0ScaleOnTextEnter( wxCommandEvent& event );
		void m_choiceCh0ACDCOnChoice( wxCommandEvent& event );
		void m_checkBoxCh0InvertOnCheckBox( wxCommandEvent& event );
		void m_checkBoxCh0GroundOnCheckBox( wxCommandEvent& event );
		void m_checkBoxSignal1OnCheckBox( wxCommandEvent& event );
		void m_checkBoxFFT1OnCheckBox( wxCommandEvent& event );
		void m_checkBoxAvg01OnCheckBox( wxCommandEvent& event );
		void m_textCtrlCh0PositionOnTextEnter( wxCommandEvent& event );
		void m_spinBtnCh0YPosOnSpinDown( wxSpinEvent& event );
		void m_spinBtnCh0YPosOnSpinUp( wxSpinEvent& event );
		void m_sliderCh0PositionOnScroll( wxScrollEvent& event );
		void m_comboBoxCh1CaptureOnCombobox( wxCommandEvent& event );
		void m_textCtrlCh1ScaleOnTextEnter( wxCommandEvent& event );
		void m_choiceCh1ACDCOnChoice( wxCommandEvent& event );
		void m_checkBoxCh1InvertOnCheckBox( wxCommandEvent& event );
		void m_checkBoxCh1GroundOnCheckBox( wxCommandEvent& event );
		void m_checkBoxSignal2OnCheckBox( wxCommandEvent& event );
		void m_checkBoxFFT2OnCheckBox( wxCommandEvent& event );
		void m_checkBoxAvg02OnCheckBox( wxCommandEvent& event );
		void m_textCtrlCh1PositionOnTextEnter( wxCommandEvent& event );
		void m_spinBtnCh1YPosOnSpinDown( wxSpinEvent& event );
		void m_spinBtnCh1YPosOnSpinUp( wxSpinEvent& event );
		void m_sliderCh1PositionOnScroll( wxScrollEvent& event );
		void m_comboBoxFunctionTypeOnChoice( wxCommandEvent& event );
		void m_checkBoxXYVoltageGraphOnCheckBox( wxCommandEvent& event );
		void m_checkBoxSignalFOnCheckBox( wxCommandEvent& event );
		void m_checkBoxFFTFOnCheckBox( wxCommandEvent& event );
		void m_choiceDOnOff815OnChoice( wxCommandEvent& event );
		void m_choiceDOnOff70OnChoice( wxCommandEvent& event );
		void m_checkBox12OnCheckBox( wxCommandEvent& event );
		void m_checkBox10OnCheckBox( wxCommandEvent& event );
		void m_checkBox8OnCheckBox( wxCommandEvent& event );
		void m_checkBox11OnCheckBox( wxCommandEvent& event );
		void m_checkBox9OnCheckBox( wxCommandEvent& event );
		void m_checkBox7OnCheckBox( wxCommandEvent& event );
		void m_checkBox6OnCheckBox( wxCommandEvent& event );
		void m_checkBox4OnCheckBox( wxCommandEvent& event );
		void m_checkBox2OnCheckBox( wxCommandEvent& event );
		void m_checkBox5OnCheckBox( wxCommandEvent& event );
		void m_checkBox3OnCheckBox( wxCommandEvent& event );
		void m_checkBox1OnCheckBox( wxCommandEvent& event );
		void m_choiceDS815OnChoice( wxCommandEvent& event );
		void m_choiceInputOutputOnChoice( wxCommandEvent& event );
		void m_choiceBit11OnChoice( wxCommandEvent& event );
		void m_choiceBit9OnChoice( wxCommandEvent& event );
		void m_choiceBit7OnChoice( wxCommandEvent& event );
		void m_choiceBit10OnChoice( wxCommandEvent& event );
		void m_choiceBit8OnChoice( wxCommandEvent& event );
		void m_choiceBit6OnChoice( wxCommandEvent& event );
		void m_choiceInputOutput1OnChoice( wxCommandEvent& event );
		void m_choiceDS70OnChoice( wxCommandEvent& event );
		void m_choiceBit5OnChoice( wxCommandEvent& event );
		void m_choiceBit3OnChoice( wxCommandEvent& event );
		void m_choiceBit1OnChoice( wxCommandEvent& event );
		void m_choiceBit4OnChoice( wxCommandEvent& event );
		void m_choiceBit2OnChoice( wxCommandEvent& event );
		void m_choiceBit0OnChoice( wxCommandEvent& event );
		void m_filePicker1OnFileChanged( wxFileDirPickerEvent& event );
		void m_buttonCustomFileOnButtonClick( wxCommandEvent& event );
		void m_textCtrlDigitalVoltageOnTextEnter( wxCommandEvent& event );
		void m_spinBtnDigVoltageOnSpinDown( wxSpinEvent& event );
		void m_spinBtnDigVoltageOnSpinUp( wxSpinEvent& event );
		void m_textCtrlFreqDividerOnTextEnter( wxCommandEvent& event );
		void m_buttonReArmOnButtonClick( wxCommandEvent& event );
		void m_comboBoxTriggerOnCombobox( wxCommandEvent& event );
		void m_comboBoxTriggerSourceOnCombobox( wxCommandEvent& event );
		void m_comboBoxTriggerSlopeOnCombobox( wxCommandEvent& event );
		void m_textCtrlTriggerLevelOnTextEnter( wxCommandEvent& event );
		void m_spinBtnTrigLevelOnSpinDown( wxSpinEvent& event );
		void m_spinBtnTrigLevelOnSpinUp( wxSpinEvent& event );
		void m_sliderTriggerLevelOnScroll( wxScrollEvent& event );
		void m_textCtrlTriggerHisteresisOnTextEnter( wxCommandEvent& event );
		void m_spinBtnTrigHisOnSpinDown( wxSpinEvent& event );
		void m_spinBtnTrigHisOnSpinUp( wxSpinEvent& event );
		void m_sliderTriggerHisteresisOnScroll( wxScrollEvent& event );
		void m_textCtrlTriggerPreOnTextEnter( wxCommandEvent& event );
		void m_spinBtnTrigPreOnSpinDown( wxSpinEvent& event );
		void m_spinBtnTrigPreOnSpinUp( wxSpinEvent& event );
		void m_sliderTriggerPreOnScroll( wxScrollEvent& event );
		void m_textCtrlTriggerHoldoffOnTextEnter( wxCommandEvent& event );
		void m_spinBtnTrigHoldoffOnSpinDown( wxSpinEvent& event );
		void m_spinBtnTrigHoldoffOnSpinUp( wxSpinEvent& event );
		void m_sliderTriggerHoldoffOnScroll( wxScrollEvent& event );
		void m_comboBoxDigitalStageOnCombobox( wxCommandEvent& event );
		void m_textCtrDigitallDelayOnTextEnter( wxCommandEvent& event );
		void m_comboBoxDigitalStageStartOnCombobox( wxCommandEvent& event );
		void m_comboBoxDigitalModeOnCombobox( wxCommandEvent& event );
		void m_comboBoxDigitalSerialChannelOnCombobox( wxCommandEvent& event );
		void m_choiceBit158OnChoice( wxCommandEvent& event );
		void m_choiceBit70OnChoice( wxCommandEvent& event );
		void m_comboBoxBit11OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit9OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit6OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit10OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit8OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit7OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit5OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit3OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit1OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit4OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit2OnCombobox( wxCommandEvent& event );
		void m_comboBoxBit0OnCombobox( wxCommandEvent& event );
	public:
		/** Constructor */
		OsciloskopOsciloskop( wxWindow* parent );
	//// end generated class members
public:
    ~OsciloskopOsciloskop();
public:
    void MenuScriptSelection(wxCommandEvent& event);
    void OnInit();
public:
    int  getCurrentSlot();
    void SaveOldSlotLoadNewSlot(int newSlot);
    void loadWindow(int slot);
    void loadSlot(WndMain& slot);
    void setupUI(WndMain window);
    void setupWindow();
    void RecalculateTriggerPosition(double oldTriggerVoltagePerStep, double newTriggerVoltagePerStep);
    void setTimeMode(int);
    void setCompatibility();
    void SetButtonColors();
    void SetDigital13To16(bool enable);
    void DigitalMiddlePinMaxVoltText(float voltageMax);
public:
    OsciloskopStorage*    pStorage;
    OsciloskopConnection* pConnection;
    OsciloskopMeasure*    pMeasure;
    OsciloskopDebug*      pDebug;
    OsciloskopInfo*       pInfo;
    OsciloskopDisplay*    pDisplay;
    OsciloskopThermal*    pThermal;
    OsciloskopSoftwareGenerator* pSoftwareGenerator;
    OsciloskopHardwareGenerator* pHardwareGenerator;
public:
    double timer;
    int once;
    int pulse;
    int userinterfaceupdate;
};

#endif // __OsciloskopOsciloskop__
