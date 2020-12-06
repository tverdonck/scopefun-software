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
#include "OsciloskopDebug.h"
#include "OsciloskopOsciloskop.h"

OsciloskopDebug::OsciloskopDebug( wxWindow* parent )
:
Debug( parent )
{
    m_script = 0;
    m_Redirect = new wxStreamToTextRedirector(m_textCtrl41);
    wxFont font(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Courier New");
    m_textCtrl41->SetFont(font);
    //m_textCtrl41->GetScrollHelper()->ShowScrollbars(wxScrollbarVisibility::wxSHOW_SB_NEVER, wxScrollbarVisibility::wxSHOW_SB_ALWAYS);
    SetSize(500, 500);
    SetTitle("Script");
   // SetWindowStyleFlag(wxRESIZE_BORDER|wxCAPTION|wxCLOSE);
   // m_scrollHelp = new wxScrollHelper( m_textCtrl41->GetMainWindowOfCompositeControl() );
   // m_scrollHelp->ShowScrollbars(wxScrollbarVisibility::wxSHOW_SB_DEFAULT, wxScrollbarVisibility::wxSHOW_SB_DEFAULT);
   // SetScrollHelper(m_scrollHelp);
    wxColour black((unsigned long)RGB(64, 64, 64));
    wxColour white( RGB(255, 255, 255) );
    m_textCtrl41->SetBackgroundColour(black);
    m_textCtrl41->SetForegroundColour(white);
    SetBackgroundColour(black);
    SetForegroundColour(white);
    Connect(wxEVT_CLOSE_WINDOW, wxActivateEventHandler(OsciloskopDebug::OnDestroy));
}

void OsciloskopDebug::ThermalOnActivate( wxActivateEvent& event )
{
    // TODO: Implement ThermalOnActivate
}


void OsciloskopDebug::OnDestroy(wxActivateEvent& event)
{
   // TODO: Implement ThermalOnActivate
   if (m_script)
   {
      m_script->Stop();
      m_script->ClrPrint();
   }
   if( m_script )
      ((OsciloskopOsciloskop*)this->GetParent())->GetMenuBar()->GetMenu(6)->GetMenuItems()[m_script->GetArrayIdx()]->Check(false);
   Hide();
}

void OsciloskopDebug::m_button561OnButtonClick(wxCommandEvent& event)
{
   if (m_script)
      m_script->Reload();
   event.Skip();
}

void OsciloskopDebug::m_button56OnButtonClick(wxCommandEvent& event)
{
   if (m_script)
      m_script->Run();
   event.Skip();
}
void OsciloskopDebug::m_button562OnButtonClick(wxCommandEvent& event)
{
   if (m_script)
      m_script->Stop();
   event.Skip();
}
void OsciloskopDebug::m_button5621OnButtonClick(wxCommandEvent& event)
{
   Close();
   event.Skip();
}


void OsciloskopDebug::SetText(std::string str)
{
    m_textCtrl41->SetValue(str.c_str());
}

void OsciloskopDebug::Clear()
{
    #if defined(PLATFORM_MINGW)
    system("cls");
    #else
    system("clear");
    #endif
    m_textCtrl41->Clear();
}

OsciloskopDebug::~OsciloskopDebug()
{
  // delete m_scrollHelp;
   delete m_Redirect;
}

void OsciloskopDebug::AppendText(const char* str)
{
    std::cout << str;
}