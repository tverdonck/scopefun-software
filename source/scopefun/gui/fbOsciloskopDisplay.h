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
id m_sliderSignalOnScroll(wxScrollEvent& event);
    void m_choiceFFTOnChoice(wxCommandEvent& event);
    void m_textCtrlFFTOnTextEnter(wxCommandEvent& event);
    void m_sliderFFTOnScroll(wxScrollEvent& event);
    void m_choiceFFTYOnChoice(wxCommandEvent& event);
    void m_choiceFFTXOnChoice(wxCommandEvent& event);
    void m_checkBox3dSolidOnCheckBox(wxCommandEvent& event);
    void m_checkBox3dLightOnCheckBox(wxCommandEvent& event);
    void m_checkBox3dDepthTestOnCheckBox(wxCommandEvent& event);
    void m_textCtrl3dAlphaCh0OnTextEnter(wxCommandEvent& event);
    void m_slider3dAlphaCh0OnScroll(wxScrollEvent& event);
    void m_textCtrl3dAlphaCh1OnTextEnter(wxCommandEvent& event);
    void m_slider3dAlphaCh1OnScroll(wxScrollEvent& event);
    void m_textCtrl3dAlphaFunOnTextEnter(wxCommandEvent& event);
    void m_slider3dAlphaFunOnScroll(wxScrollEvent& event);
    void m_textCtrl3dTessalationOnTextEnter(wxCommandEvent& event);
    void m_slider3dTessalationOnScroll(wxScrollEvent& event);
    void m_textCtrl2dTessalationOnTextEnter(wxCommandEvent& event);
    void m_slider2dTessalationOnScroll(wxScrollEvent& event);
    void m_buttonOkOnButtonClick(wxCommandEvent& event);
    void m_buttonDefaultOnButtonClick(wxCommandEvent& event);
    void m_buttonCancelOnButtonClick(wxCommandEvent& event);
public:
    /** Constructor */
    OsciloskopDisplay(wxWindow* parent);
    //// end generated class members

};

#endif // __fbOsciloskopDisplay__
