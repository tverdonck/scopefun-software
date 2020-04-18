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
#ifndef __OsciloskopMeasure__
#define __OsciloskopMeasure__

/**
@file
Subclass of Measure, which is generated by wxFormBuilder.
*/

#include "osc.h"

//// end generated include

/** Implementing Measure */
class OsciloskopMeasure : public Measure
{
protected:
    // Handlers for Measure events.
    void DisplayOnInitDialog(wxInitDialogEvent& event);
    void m_SelectionChanged1(wxDataViewEvent& event);
    void m_SelectionChanged2(wxDataViewEvent& event);
    void m_checkBoxAutoClearOnCheckBox(wxCommandEvent& event);
    void m_checkBoxAutoClearTriggerOnCheckBox(wxCommandEvent& event);
    void m_buttonHistoryClearOnButtonClick(wxCommandEvent& event);
    void m_buttonCopyOnButtonClick(wxCommandEvent& event);
    void m_buttonCopy2OnButtonClick(wxCommandEvent& event);
    void m_buttonClearXOnButtonClick(wxCommandEvent& event);
    void m_buttonClearYOnButtonClick(wxCommandEvent& event);
    void m_buttonClearFFTOnButtonClick(wxCommandEvent& event);
    void m_buttonPickX0OnButtonClick(wxCommandEvent& event);
    void m_textCtrlX0OnTextEnter(wxCommandEvent& event);
    void m_spinBtnX0OnSpinDown(wxSpinEvent& event);
    void m_spinBtnX0OnSpinUp(wxSpinEvent& event);
    void m_sliderX0OnScroll(wxScrollEvent& event);
    void m_buttonPickX1OnButtonClick(wxCommandEvent& event);
    void m_textCtrlX1OnTextEnter(wxCommandEvent& event);
    void m_spinBtnX1OnSpinDown(wxSpinEvent& event);
    void m_spinBtnX1OnSpinUp(wxSpinEvent& event);
    void m_sliderX1OnScroll(wxScrollEvent& event);
    void m_buttonPickY0OnButtonClick(wxCommandEvent& event);
    void m_textCtrlY0OnTextEnter(wxCommandEvent& event);
    void m_choiceY0OnChoice(wxCommandEvent& event);
    void m_spinBtnY0OnSpinDown(wxSpinEvent& event);
    void m_spinBtnY0OnSpinUp(wxSpinEvent& event);
    void m_sliderY0OnScroll(wxScrollEvent& event);
    void m_buttonPickY1OnButtonClick(wxCommandEvent& event);
    void m_textCtrlY1OnTextEnter(wxCommandEvent& event);
    void m_choiceY1OnChoice(wxCommandEvent& event);
    void m_spinBtnY1OnSpinDown(wxSpinEvent& event);
    void m_spinBtnY1OnSpinUp(wxSpinEvent& event);
    void m_sliderY1OnScroll(wxScrollEvent& event);
    void m_buttonPickFFT0OnButtonClick(wxCommandEvent& event);
    void m_textCtrlFFT0OnTextEnter(wxCommandEvent& event);
    void m_spinBtnFFT0OnSpinDown(wxSpinEvent& event);
    void m_spinBtnFFT0OnSpinUp(wxSpinEvent& event);
    void m_sliderFFT0OnScroll(wxScrollEvent& event);
    void m_buttonPickFFT1OnButtonClick(wxCommandEvent& event);
    void m_textCtrlFFT1OnTextEnter(wxCommandEvent& event);
    void m_spinBtnFFT1OnSpinDown(wxSpinEvent& event);
    void m_spinBtnFFT1OnSpinUp(wxSpinEvent& event);
    void m_sliderFFT1OnScroll(wxScrollEvent& event);
    void m_buttonOkOnButtonClick(wxCommandEvent& event);
    void m_buttonDefaultOnButtonClick(wxCommandEvent& event);
    void m_buttonCancelOnButtonClick(wxCommandEvent& event);
public:
    /** Constructor */
    OsciloskopMeasure(wxWindow* parent);
    //// end generated class members
public:
    void EnableDisableFrameTextBox(bool enable = false);
    void setTextCtrlX(wxTextCtrl* ctr, wxChoice* choice, double value);
    void setTextCtrlY(wxTextCtrl* ctr, double value);
    void setTextCtrlFreq(wxTextCtrl* ctr, wxChoice* choice, double value);
    void PopulateWithData();
public:
    void CopyToClipBoard(wxDataViewListCtrl* list);
    void insertRow1(int row, int i);
    void insertRow2(int row, int i);
    void removeRow1(int i);
    void removeRow2(int i);
    void setCell1(int row, int i, MeasureHistory his);
    void setCell2(int row, int i, int column);
    void setHistory(MeasureHistory type);
    int HideRow1(int selected, int rowID, int count);
    int ShowRow1(int selected, int rowID, int count);
    int HideRow2(int selected, int rowID, int count);
    int ShowRow2(int selected, int rowID, int count);
public:
    wxString aStringR[Last1];
    wxString aStringC[Last1];
public:
    void onScrollWinMeasure(wxScrollWinEvent& evt);
};

#endif // __OsciloskopMeasure__
