////////////////////////////////////////////////////////////////////////////////
//    ScopeFun Oscilloscope ( http://www.scopefun.com )
//    Copyright (C) 2016 - 2020 David Košenina
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
#ifndef __OsciloskopSoftwareGenerator__
#define __OsciloskopSoftwareGenerator__

/**
@file
Subclass of SoftwareGenerator, which is generated by wxFormBuilder.
*/

#include "osc.h"

//// end generated include

/** Implementing SoftwareGenerator */
class OsciloskopSoftwareGenerator : public SoftwareGenerator
{
protected:
    // Handlers for SoftwareGenerator events.
    void SoftwareGeneratorOnInitDialog(wxInitDialogEvent& event);
    void m_comboBoxType0OnCombobox(wxCommandEvent& event);
    void m_textCtrlPeriod0OnTextEnter(wxCommandEvent& event);
    void m_comboBoxPeriod0OnCombobox(wxCommandEvent& event);
    void m_textCtrlPeek0OnTextEnter(wxCommandEvent& event);
    void m_comboBoxPeek0OnCombobox(wxCommandEvent& event);
    void m_textCtrlSpeed0OnTextEnter(wxCommandEvent& event);
    void m_textCtrlAvery0OnTextEnter(wxCommandEvent& event);
    void m_radioBtnOn0OnRadioButton(wxCommandEvent& event);
    void m_radioBtnOff0OnRadioButton(wxCommandEvent& event);
    void m_comboBoxType1OnCombobox(wxCommandEvent& event);
    void m_textCtrlPeriod1OnTextEnter(wxCommandEvent& event);
    void m_comboBoxPeriod1OnCombobox(wxCommandEvent& event);
    void m_textCtrlPeek1OnTextEnter(wxCommandEvent& event);
    void m_comboBoxPeek1OnCombobox(wxCommandEvent& event);
    void m_textCtrlSpeed1OnTextEnter(wxCommandEvent& event);
    void m_textCtrlAvery1OnTextEnter(wxCommandEvent& event);
    void m_radioBtnOn1OnRadioButton(wxCommandEvent& event);
    void m_radioBtnOff1OnRadioButton(wxCommandEvent& event);
    void m_buttonOkOnButtonClick(wxCommandEvent& event);
    void m_buttonDefaultOnButtonClick(wxCommandEvent& event);
    void m_buttonCancelOnButtonClick(wxCommandEvent& event);
    void m_buttonOn0OnButtonClick(wxCommandEvent& event);
    void m_buttonOff0OnButtonClick(wxCommandEvent& event);
    void m_buttonOn1OnButtonClick(wxCommandEvent& event);
    void m_buttonOff1OnButtonClick(wxCommandEvent& event);
public:
    /** Constructor */
    OsciloskopSoftwareGenerator(wxWindow* parent);
    //// end generated class members

};

#endif // __OsciloskopSoftwareGenerator__
