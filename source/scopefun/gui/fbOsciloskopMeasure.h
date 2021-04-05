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
erX0OnScroll( wxScrollEvent& event );
		void m_buttonPickX1OnButtonClick( wxCommandEvent& event );
		void m_textCtrlX1OnTextEnter( wxCommandEvent& event );
		void m_spinBtnX1OnSpinDown( wxSpinEvent& event );
		void m_spinBtnX1OnSpinUp( wxSpinEvent& event );
		void m_sliderX1OnScroll( wxScrollEvent& event );
		void m_buttonPickY0OnButtonClick( wxCommandEvent& event );
		void m_textCtrlY0OnTextEnter( wxCommandEvent& event );
		void m_choiceY0OnChoice( wxCommandEvent& event );
		void m_spinBtnY0OnSpinDown( wxSpinEvent& event );
		void m_spinBtnY0OnSpinUp( wxSpinEvent& event );
		void m_sliderY0OnScroll( wxScrollEvent& event );
		void m_buttonPickY1OnButtonClick( wxCommandEvent& event );
		void m_textCtrlY1OnTextEnter( wxCommandEvent& event );
		void m_choiceY1OnChoice( wxCommandEvent& event );
		void m_spinBtnY1OnSpinDown( wxSpinEvent& event );
		void m_spinBtnY1OnSpinUp( wxSpinEvent& event );
		void m_sliderY1OnScroll( wxScrollEvent& event );
		void m_buttonPickFFT0OnButtonClick( wxCommandEvent& event );
		void m_textCtrlFFT0OnTextEnter( wxCommandEvent& event );
		void m_spinBtnFFT0OnSpinDown( wxSpinEvent& event );
		void m_spinBtnFFT0OnSpinUp( wxSpinEvent& event );
		void m_sliderFFT0OnScroll( wxScrollEvent& event );
		void m_buttonPickFFT1OnButtonClick( wxCommandEvent& event );
		void m_textCtrlFFT1OnTextEnter( wxCommandEvent& event );
		void m_spinBtnFFT1OnSpinDown( wxSpinEvent& event );
		void m_spinBtnFFT1OnSpinUp( wxSpinEvent& event );
		void m_sliderFFT1OnScroll( wxScrollEvent& event );
		void m_ItemActivated( wxDataViewEvent& event );
		void m_ItemStartEditing( wxDataViewEvent& event );
		void m_SelectionChanged1( wxDataViewEvent& event );
		void m_OnLeftDown( wxMouseEvent& event );
		void m_dataViewListCtrl1OnMouseEvents( wxMouseEvent& event );
		void m_buttonOkOnButtonClick( wxCommandEvent& event );
		void m_buttonDefaultOnButtonClick( wxCommandEvent& event );
		void m_buttonCancelOnButtonClick( wxCommandEvent& event );
	public:
		/** Constructor */
		OsciloskopMeasure( wxWindow* parent );
	//// end generated class members


};

#endif // __fbOsciloskopMeasure__
