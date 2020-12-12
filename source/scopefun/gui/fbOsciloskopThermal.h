#ifndef __fbOsciloskopThermal__
#define __fbOsciloskopThermal__

/**
@file
Subclass of Thermal, which is generated by wxFormBuilder.
*/

#include "osc.h"

//// end generated include

/** Implementing Thermal */
class OsciloskopThermal : public Thermal
{
	protected:
		// Handlers for Thermal events.
		void ThermalOnActivate( wxActivateEvent& event );
		void m_textCtrlHeatingOnTextEnter( wxCommandEvent& event );
		void m_spinBtnHeatingOnSpinDown( wxSpinEvent& event );
		void m_spinBtnHeatingOnSpinUp( wxSpinEvent& event );
		void m_sliderHeatOnScroll( wxScrollEvent& event );
		void m_textCtrlCoolingOnTextEnter( wxCommandEvent& event );
		void m_spinBtnCoolingOnSpinDown( wxSpinEvent& event );
		void m_spinBtnCoolingOnSpinUp( wxSpinEvent& event );
		void m_sliderCoolOnScroll( wxScrollEvent& event );
		void m_checkBoxEnabledOnCheckBox( wxCommandEvent& event );
		void m_buttonOkOnButtonClick( wxCommandEvent& event );
		void m_buttonDefaultOnButtonClick( wxCommandEvent& event );
		void m_buttonCancelOnButtonClick( wxCommandEvent& event );
	public:
		/** Constructor */
		OsciloskopThermal( wxWindow* parent );
	//// end generated class members


};

#endif // __fbOsciloskopThermal__
