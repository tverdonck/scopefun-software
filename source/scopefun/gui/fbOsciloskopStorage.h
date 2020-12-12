#ifndef __fbOsciloskopStorage__
#define __fbOsciloskopStorage__

/**
@file
Subclass of Storage, which is generated by wxFormBuilder.
*/

#include "osc.h"

//// end generated include

/** Implementing Storage */
class OsciloskopStorage : public Storage
{
	protected:
		// Handlers for Storage events.
		void m_choiceStorageOnChoice( wxCommandEvent& event );
		void m_textCtrlStorageOnTextEnter( wxCommandEvent& event );
		void m_choicePacketSizeOnChoice( wxCommandEvent& event );
		void m_buttonOkOnButtonClick( wxCommandEvent& event );
		void m_buttonDefaultOnButtonClick( wxCommandEvent& event );
		void m_buttonCancelOnButtonClick( wxCommandEvent& event );
	public:
		/** Constructor */
		OsciloskopStorage( wxWindow* parent );
	//// end generated class members

};

#endif // __fbOsciloskopStorage__