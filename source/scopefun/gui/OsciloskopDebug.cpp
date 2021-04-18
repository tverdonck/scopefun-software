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
#include "OsciloskopDebug.h"


OsciloskopDebug::OsciloskopDebug(wxWindow* parent)
    :
    Debug(parent)
{
    m_script = 0;
    SetSize(500, 500);
    SetTitle("Script");

    m_Lua->SetLexer(wxSTC_LEX_LUA);
    m_Lua->SetIndent(4);

    wxFont font;
    font.SetFaceName(L"Courier New");
    m_Lua->StyleSetFont(wxSTC_STYLE_DEFAULT, font);

    m_Lua->StyleSetItalic(wxSTC_LUA_DEFAULT, true);
    m_Lua->StyleSetItalic(wxSTC_LUA_COMMENT, true);
    m_Lua->StyleSetItalic(wxSTC_LUA_COMMENTLINE, true);
    m_Lua->StyleSetItalic(wxSTC_LUA_COMMENTDOC, true);
    m_Lua->StyleSetForeground(wxSTC_LUA_DEFAULT, wxColour(0, 128, 0));
    m_Lua->StyleSetForeground(wxSTC_LUA_COMMENT, wxColour(0, 128, 0));
    m_Lua->StyleSetForeground(wxSTC_LUA_COMMENTLINE, wxColour(0, 128, 0));
    m_Lua->StyleSetForeground(wxSTC_LUA_COMMENTDOC, wxColour(0, 128, 0));

    m_Lua->StyleSetForeground(wxSTC_LUA_STRING, wxColour(64, 64, 0));
    m_Lua->StyleSetForeground(wxSTC_LUA_CHARACTER, wxColour(64, 64, 0));
    m_Lua->StyleSetForeground(wxSTC_LUA_LITERALSTRING, wxColour(64, 64, 0));
    m_Lua->StyleSetForeground(wxSTC_LUA_STRINGEOL, wxColour(64, 64, 0));

    m_Lua->StyleSetForeground(wxSTC_LUA_NUMBER, wxColour(0, 0, 0));
    m_Lua->StyleSetForeground(wxSTC_LUA_PREPROCESSOR, wxColour(64, 64, 64));
    m_Lua->StyleSetForeground(wxSTC_LUA_OPERATOR, wxColour(128, 0, 0));
    m_Lua->StyleSetForeground(wxSTC_LUA_IDENTIFIER, wxColour(128, 128, 128));

    m_Lua->StyleSetForeground(wxSTC_LUA_WORD, wxColour(0, 0, 128));
    m_Lua->StyleSetForeground(wxSTC_LUA_WORD2, wxColour(0, 0, 128));
    m_Lua->StyleSetForeground(wxSTC_LUA_WORD3, wxColour(0, 0, 128));
    m_Lua->StyleSetForeground(wxSTC_LUA_WORD4, wxColour(0, 0, 128));
    m_Lua->StyleSetForeground(wxSTC_LUA_WORD5, wxColour(0, 0, 128));
    m_Lua->StyleSetForeground(wxSTC_LUA_WORD6, wxColour(0, 0, 128));
    m_Lua->StyleSetForeground(wxSTC_LUA_WORD7, wxColour(0, 0, 128));
    m_Lua->StyleSetForeground(wxSTC_LUA_WORD8, wxColour(0, 0, 128));
    m_Lua->StyleSetForeground(wxSTC_LUA_LABEL, wxColour(0, 0, 128));

    m_Lua->SetKeyWords(wxSTC_LUA_WORD, L"for do if while end function");


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
      SDL_CreateThread(LuaStopScript, "LuaStopScript", this);
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

void OsciloskopDebug::ThreadStop()
{
   m_script->Stop();
   m_buttonStart->Enable();
   m_buttonStop->Disable();
   m_buttonUpload->Disable();
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


OsciloskopDebug::~OsciloskopDebug()
{

}

void OsciloskopDebug::AppendText(const char* str)
{
   m_textCtrlOutput->AppendText(str);
}
