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
include "OsciloskopDebug.h"


OsciloskopDebug::OsciloskopDebug(wxWindow* parent)
    :
    Debug(parent)
{
    m_script = 0;
    SetSize(500, 500);
    SetTitle("Script");

    Connect(wxEVT_CLOSE_WINDOW, wxActivateEventHandler(OsciloskopDebug::OnDestroy));

    if (!isFileWritable())
       m_buttonSave->Disable();

    m_buttonUpload->Disable();
    m_buttonStop->Disable();
    m_buttonLua->Disable();
}

void OsciloskopDebug::ThermalOnActivate(wxActivateEvent& event)
{
   if (m_script && m_script->m_luaScript)
   {
      m_script->Reload();
      m_Lua->SetValue((const char*)m_script->m_luaScript);
   }
}

void OsciloskopDebug::OnDestroy(wxActivateEvent& event)
{
    if(m_script)
    {
        m_script->Stop();
        m_script->ClrPrint();
    }
    if(m_script)
    { ((OsciloskopOsciloskop*)this->GetParent())->GetMenuBar()->GetMenu(6)->GetMenuItems()[m_script->GetArrayIdx()]->Check(false); }
    Hide();
}
void OsciloskopDebug::m_buttonStartOnButtonClick( wxCommandEvent& event )
{
   if (m_script)
   {
      m_script->Run();
      m_buttonStart->Disable();
      m_buttonStop->Enable();
      m_buttonUpload->Enable();
   }
   event.Skip();
}

void OsciloskopDebug::m_buttonStopOnButtonClick( wxCommandEvent& event )
{
   if (m_script)
   {
      m_script->Stop();
      m_buttonStart->Enable();
      m_buttonStop->Disable();
      m_buttonUpload->Disable();
   }
   event.Skip();
}

void OsciloskopDebug::m_buttonSaveOnButtonClick( wxCommandEvent& event )
{
   fileSaveString(m_script->m_fileName.asChar(), m_Lua->GetValue());
}

void OsciloskopDebug::m_buttonLuaOnButtonClick( wxCommandEvent& event )
{
   m_Lua->SetValue((const char*)m_script->m_luaScript);
   if(isFileWritable())
      m_buttonSave->Enable();
   m_buttonLua->Disable();
   m_buttonHelp->Enable();
   event.Skip();
}

void OsciloskopDebug::m_buttonHelpOnButtonClick( wxCommandEvent& event )
{
   m_Lua->SetValue(pOsciloscope->m_callback.GetHelp());
   m_buttonSave->Disable();
   m_buttonLua->Enable();
   m_buttonHelp->Disable();
   event.Skip();
}


void OsciloskopDebug::m_buttonUploadOnButtonClick(wxCommandEvent& event)
{
   m_script->OnUpload(&getCtx()->generator, &getCtx()->generatorCount);
   pOsciloscope->thread.setGeneratorData(&getCtx()->generator);
   pOsciloscope->thread.function(afUploadGenerator);
   pOsciloscope->transferData();
   event.Skip();
}

void OsciloskopDebug::SetText(std::string str)
{
   m_textCtrlOutput->SetValue(str.c_str());
}

void OsciloskopDebug::Clear()
{
    #if defined(PLATFORM_MINGW)
    system("cls");
    #else
    system("clear");
    #endif
    m_textCtrlOutput->Clear();
}

void OsciloskopDebug::Redirect()
{
   if (!m_script)
      return;
   m_textCtrlOutput->AppendText(m_script->GetPrint());
   m_script->ClrPrint();
}

OsciloskopDebug::~OsciloskopDebug()
{

}

void OsciloskopDebug::AppendText(const char* str)
{
    std::cout << str;
}
