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
_textCtrlSquareDuty0OnTextEnter(wxCommandEvent& event);
    void m_spinBtnGen0SqrDutyOnSpinDown(wxSpinEvent& event);
    void m_spinBtnGen0SqrDutyOnSpinUp(wxSpinEvent& event);
    void m_sliderSquareDutyOnScroll(wxScrollEvent& event);
    void m_checkBoxSawSlopeOnCheckBox(wxCommandEvent& event);
    void m_filePicker1OnFileChanged(wxFileDirPickerEvent& event);
    void m_buttonCustomFileOnButtonClick(wxCommandEvent& event);
    void m_buttonOn0OnButtonClick(wxCommandEvent& event);
    void m_buttonOff0OnButtonClick(wxCommandEvent& event);
    void m_comboBoxType1OnChoice(wxCommandEvent& event);
    void m_textCtrlFrequency1OnTextEnter(wxCommandEvent& event);
    void m_textCtrlVoltage1OnTextEnter(wxCommandEvent& event);
    void m_spinBtnCh1VoltOnSpinDown(wxSpinEvent& event);
    void m_spinBtnCh1VoltOnSpinUp(wxSpinEvent& event);
    void m_sliderVoltage1OnScroll(wxScrollEvent& event);
    void m_textCtrlOffset1OnTextEnter(wxCommandEvent& event);
    void m_spinBtnCh1OffsetOnSpinDown(wxSpinEvent& event);
    void m_spinBtnCh1OffsetOnSpinUp(wxSpinEvent& event);
    void m_sliderOffset1OnScroll(wxScrollEvent& event);
    void m_textCtrlSquareDuty1OnTextEnter(wxCommandEvent& event);
    void m_spinBtnGen1SqrDutyOnSpinDown(wxSpinEvent& event);
    void m_spinBtnGen1SqrDutyOnSpinUp(wxSpinEvent& event);
    void m_sliderSquareDuty1OnScroll(wxScrollEvent& event);
    void m_checkBoxSawSlope1OnCheckBox(wxCommandEvent& event);
    void m_filePicker11OnFileChanged(wxFileDirPickerEvent& event);
    void m_buttonCustomFile1OnButtonClick(wxCommandEvent& event);
    void m_buttonOn1OnButtonClick(wxCommandEvent& event);
    void m_buttonOff1OnButtonClick(wxCommandEvent& event);
    void m_buttonOkOnButtonClick(wxCommandEvent& event);
    void m_buttonDefaultOnButtonClick(wxCommandEvent& event);
    void m_buttonCancelOnButtonClick(wxCommandEvent& event);
public:
    /** Constructor */
    OsciloskopHardwareGenerator(wxWindow* parent);
    //// end generated class members

};

#endif // __fbOsciloskopHardwareGenerator__
