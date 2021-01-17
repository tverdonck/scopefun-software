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
#ifndef __OsciloskopTools__
#define __OsciloskopTools__

/**
@file
Subclass of Connection, which is generated by wxFormBuilder.
*/

#include "osc.h"

//// end generated include

#include "OsciloskopOsciloskop.h"

#define TIMER_ID 2001

// extern
extern wxLocale* pLocalization;

// on Windows: if you install in program files folder and run as non-admin your write is restricted there
bool  isFileWritable();
int   loadLanguageFromConfig();
void  saveLanguageToConfig(int id);
void  setLocalization(int id);
void  setColors(wxWindow* pWindow);
void  recreateGUI(int initial = 0);
int   checkAgree();
float rangeToSeconds(float range);
void  LoadSlot(int slot, const char* file);
void  SaveSlot(int slot, const char* file);
void  _setYDisplay(float& volt, uint& unit, VoltageCapture selected);
void  SetupUI(WndMain& window);

wxFileName GetOscDataFolder();
wxFileName GetOscLangFolder();

extern "C" {
    extern char* xpm16_xpm[];
    extern char* xpm32_xpm[];
    extern char* xpm64_xpm[];
    extern char* xpm96_xpm[];
    extern char* xpm128_xpm[];
    extern char* xpm256_xpm[];
    extern char* xpm512_xpm[];
};

class wxLanguageUserData : public wxObject
{
    wxDECLARE_ABSTRACT_CLASS(wxLanguageUserData);
public:
    wxLanguage data;
};

void setMask(int idx, bool value);
void setMaskNoTr(int idx, bool value);
void setPattern(int idx, wxChoice* comboBox);
void setPatternNoTr(int idx, wxChoice* comboBox);
void maximizeOscWindow();
void maximizeOglWindow(int& outW, int& outH);
int SDLCALL PopulateFunction(void* data);
void SetupUI(WndMain& window);

#endif // __OsciloskopConnection__
