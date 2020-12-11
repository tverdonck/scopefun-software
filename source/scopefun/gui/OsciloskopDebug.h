////////////////////////////////////////////////////////////////////////////////
//    ScopeFun Oscilloscope ( http://www.scopefun.com )
//    Copyright (C) 2016 - 2020 David Ko�enina
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
#ifndef __OsciloskopDebug__
#define __OsciloskopDebug__

/**
@file
Subclass of Debug, which is generated by wxFormBuilder.
*/

#include "osc.h"

//// end generated include

#include "OsciloskopOsciloskop.h"

/** Implementing Debug */
class OsciloskopDebug : public Debug
{
protected:
    // Handlers for Debug events.
    void ThermalOnActivate(wxActivateEvent& event);
public:
    /** Constructor */
    OsciloskopDebug(wxWindow* parent);
    ~OsciloskopDebug();
    //// end generated class members
private:
    void SetText(std::string str);
private:
    wxScrollHelper*           m_scrollHelp;
    wxStreamToTextRedirector* m_Redirect;
    OsciloscopeScript*        m_script;
public:
    virtual void m_button561OnButtonClick(wxCommandEvent& event);
    virtual void m_button56OnButtonClick(wxCommandEvent& event);
    virtual void m_button562OnButtonClick(wxCommandEvent& event);
    virtual void m_button5621OnButtonClick(wxCommandEvent& event);

    void OnDestroy(wxActivateEvent& event);
public:
    void Clear();
    void AppendText(const char* str);
    void AssignScript(OsciloscopeScript* script) { m_script = script; }

};

#endif // __OsciloskopDebug__
