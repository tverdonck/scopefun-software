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
#include "OsciloskopTools.h"


static wxLocale* pLocalization = 0;

wxIMPLEMENT_ABSTRACT_CLASS(wxLanguageUserData, wxObject);

// on Windows: if you install in program files folder and run as non-admin your write is restricted there
bool isFileWritable()
{
   FORMAT_BUFFER();
   FORMAT_PATH("data/startup/write.ok");
   const char* writeOk = "write ok";
   int ret = fileSaveString(formatBuffer, writeOk);
   return ret == 0 ? true : false;
}

int loadLanguageFromConfig()
{
   wxConfig config(wxApp::GetInstance()->GetAppName());
   long language = wxLANGUAGE_UNKNOWN;
   if (!config.Read(wxT("wxTranslation_Language"), &language, wxLANGUAGE_UNKNOWN))
   {
      language = wxLANGUAGE_ENGLISH;
   }
   return language;
}

void saveLanguageToConfig(int id)
{
   wxConfig config(wxApp::GetInstance()->GetAppName());
   config.Write(wxT("wxTranslation_Language"), id);
   config.Flush();
}

void setLocalization(int id)
{
   if (pLocalization)
   {
      wxDELETE(pLocalization);
   }
   pLocalization = new wxLocale;
   pLocalization->Init(id, wxLOCALE_DONT_LOAD_DEFAULT);
   wxFileName fn = GetOscLangFolder();
   wxLocale::AddCatalogLookupPathPrefix(fn.GetPath());
   bool ret = pLocalization->AddCatalog(_T("oscilloscope"));
}

void setColors(wxWindow* pWindow)
{
   if (pOsciloscope->settings.getColors()->windowDefault)
   {
      return;
   }
   int frontRGBA = pOsciloscope->settings.getColors()->windowFront;
   int backRGBA = pOsciloscope->settings.getColors()->windowBack;
   wxColour frontColor;
   frontColor.SetRGBA(frontRGBA);
   wxColour backColor;
   backColor.SetRGBA(backRGBA);
   pWindow->SetForegroundColour(frontColor);
   pWindow->SetBackgroundColour(backColor);
   wxWindowList list = pWindow->GetChildren();
   for (int i = 0; i < list.GetCount(); i++)
   {
      wxWindowListNode* node = list.Item(i);
      node->GetData()->SetForegroundColour(frontColor);
      node->GetData()->SetBackgroundColour(backColor);
      setColors(node->GetData());
   }
}

void recreateGUI(int initial)
{
   // destroy current top level window
   wxApp* pApp = (wxApp*)wxApp::GetInstance();
   wxWindow* topwindow = pApp->GetTopWindow();
   /*if (topwindow)
   {
      wxArrayString list = wxTranslations::Get()->GetAvailableTranslations(_T("oscilloscope"));
      for (uint i = 0; i < (uint)list.Count(); i++)
      {
         wxLanguageInfo* info = (wxLanguageInfo*)wxLocale::FindLanguageInfo(list.Item(i));
         if (!info)
         {
            continue;
         }
         wxMenuItem* item = ((OsciloskopOsciloskop*)topwindow)->m_menu6->FindItemByPosition(i);
         ((OsciloskopOsciloskop*)topwindow)->Disconnect(item->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(OsciloskopOsciloskop::MenuLanguageSelection), 0, topwindow);
      }
      pApp->SetTopWindow(NULL);
      topwindow->Destroy();
   }*/
   // create new top level frame
   OsciloskopOsciloskop* frame = new OsciloskopOsciloskop(0);
   pApp->SetTopWindow(frame);
   frame->OnInit();

   // localization
   /*frame->m_menu6->GetMenuItems().empty();
   wxArrayString list = wxTranslations::Get()->GetAvailableTranslations(_T("oscilloscope"));
   for (uint i = 0; i < (uint)list.Count(); i++)
   {
      wxLanguageInfo* info = (wxLanguageInfo*)wxLocale::FindLanguageInfo(list.Item(i));
      if (!info)
      {
         continue;
      }
      wxMenuItem* menuItem = new wxMenuItem(frame->m_menu6, wxID_ANY, info->Description, wxEmptyString, wxITEM_NORMAL);
      frame->m_menu6->Append(menuItem);
      wxLanguageUserData* userData = new wxLanguageUserData();
      userData->data = (wxLanguage)info->Language;
      frame->Connect(menuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(OsciloskopOsciloskop::MenuLanguageSelection), (wxObject*)userData, frame);
   }*/

   // set clinet size for proper border calculation
   int sx = wxSystemSettings::GetMetric(wxSYS_SCREEN_X);
   int sy = wxSystemSettings::GetMetric(wxSYS_SCREEN_Y);
   frame->SetClientSize(45 * sx / 80, 7 * sy / 8);
   // border
   wxRect rect3 = frame->GetClientRect();
   wxRect rect4 = frame->GetScreenRect();
   int  borderX = (rect4.width - rect3.width) / 2;
   int  borderY = (rect4.height - rect3.height) / 2;
   wxPoint pt(35 * sx / 80, sy / 16);
   if (initial)
   {
      pt.x -= borderX;
#ifdef MAC
      pt.y -= 2 * borderY;
#endif
#ifdef _WINDOWS
      pt.y -= borderY;
#endif
   }
   // proper client size
#ifdef _WINDOWS
   frame->SetClientSize(45 * sx / 80, 7 * sy / 8 - borderY + borderX);
#endif
   // position
   frame->SetPosition(pt);
   // show window
   frame->Show(true);
   frame->Layout();
}

void LoadSlot(int slot, const char* file)
{
   slot = clamp(slot, 0, 3);
   SDL_RWops* ctx = SDL_RWFromFile(file, "rb");
   if (ctx)
   {
      SDL_RWread(ctx, &pOsciloscope->windowState[slot], 1, sizeof(WndMain));
      SDL_RWclose(ctx);
   }
}

void SaveSlot(int slot, const char* file)
{
   slot = clamp(slot, 0, 3);
   SDL_RWops* ctx = SDL_RWFromFile(file, "wb+");
   if (ctx)
   {
      SDL_RWwrite(ctx, &pOsciloscope->windowState[slot], 1, sizeof(WndMain));
      SDL_RWclose(ctx);
   }
}

wxFileName GetOscDataFolder()
{
   wxFileName fn;
#if defined(PLATFORM_WIN) || defined(PLATFORM_MINGW)
   fn = wxStandardPaths::Get().GetExecutablePath();
#endif
#ifdef PLATFORM_MAC
   fn = wxStandardPaths::Get().GetResourcesDir();
   fn.AppendDir("Resources");
#endif
#ifdef PLATFORM_LINUX
   fn = "/usr/lib/oscilloscope";
#endif
   return fn;
}

wxFileName GetOscLangFolder()
{
   wxFileName fn;
#if defined(PLATFORM_WIN) || defined(PLATFORM_MINGW)
   fn = wxStandardPaths::Get().GetExecutablePath();
   fn.AppendDir("locale");
#endif
#ifdef PLATFORM_MAC
   fn = wxStandardPaths::Get().GetResourcesDir();
   fn.AppendDir("Resources");
   fn.AppendDir("locale");
#endif
#ifdef PLATFORM_LINUX
   fn = "/usr/share/locale/";
#endif
   return fn;
}


//class sfRenderTimer : public wxTimer
//{
//public:
//   void Notify()
//   {
//      wxWakeUpIdle();
//   }
//};
//
//wxBEGIN_EVENT_TABLE(OsciloskopOsciloskop, wxFrame)
//EVT_TIMER(TIMER_ID, OsciloskopOsciloskop::OnTimer)
//wxEND_EVENT_TABLE()


void _setYDisplay(float& volt, uint& unit, VoltageCapture selected)
{
   switch (selected)
   {
   case  vc2Volt:
      volt = 2.f;
      unit = (uint)vVolt;
      break;
   case  vc1Volt:
      volt = 1.f;
      unit = (uint)vVolt;
      break;
   case  vc500Mili:
      volt = 500.f;
      unit = (uint)vMili;
      break;
   case  vc200Mili:
      volt = 200.f;
      unit = (uint)vMili;
      break;
   case  vc100Mili:
      volt = 100.f;
      unit = (uint)vMili;
      break;
   case  vc50Mili:
      volt = 50.f;
      unit = (uint)vMili;
      break;
   case  vc20Mili:
      volt = 20.f;
      unit = (uint)vMili;
      break;
   case  vc10Mili:
      volt = 10.f;
      unit = (uint)vMili;
      break;
   default:
      CORE_ERROR("invalid volt value", 0);
   };
}

void setMask(int idx, bool value)
{
   int stage = pOsciloscope->window.trigger.stage;
   pOsciloscope->window.trigger.mask[stage][idx] = value;
   sfSetDigitalMask(getHw(), (DigitalStage)stage, (DigitalBit)idx, (DigitalPattern)pOsciloscope->window.trigger.mask[stage][idx]);
   pOsciloscope->transferData();
}

void setMaskNoTr(int idx, bool value)
{
   int stage = pOsciloscope->window.trigger.stage;
   pOsciloscope->window.trigger.mask[stage][idx] = value;
   sfSetDigitalMask(getHw(), (DigitalStage)stage, (DigitalBit)idx, (DigitalPattern)pOsciloscope->window.trigger.mask[stage][idx]);
}

void setPattern(int idx, wxChoice* comboBox)
{
   if (comboBox->GetSelection() == 4)
   {
      setMask(idx, false);
   }
   else
   {
      setMaskNoTr(idx, true);
      int stage = pOsciloscope->window.trigger.stage;
      pOsciloscope->window.trigger.pattern[stage][idx] = comboBox->GetSelection();
      sfSetDigitalPattern(getHw(), (DigitalStage)stage, (DigitalBit)idx, (DigitalPattern)pOsciloscope->window.trigger.pattern[stage][idx]);
      pOsciloscope->transferData();
   }
}

void setPatternNoTr(int idx, wxChoice* comboBox)
{
   if (comboBox->GetSelection() == 4)
   {
      setMaskNoTr(idx, false);
   }
   else
   {
      setMaskNoTr(idx, true);
      int stage = pOsciloscope->window.trigger.stage;
      pOsciloscope->window.trigger.pattern[stage][idx] = comboBox->GetSelection();
      sfSetDigitalPattern(getHw(), (DigitalStage)stage, (DigitalBit)idx, (DigitalPattern)pOsciloscope->window.trigger.pattern[stage][idx]);
   }
}

void maximizeOscWindow()
{
   // get top level window
   wxApp* pApp = (wxApp*)wxApp::GetInstance();
   wxFrame* topwindow = (wxFrame*)pApp->GetTopWindow();
   // window width & height
   int displayWidth = 0;
   int displayHeight = 0;
   wxDisplaySize(&displayWidth, &displayHeight);
   float osc = float(displayWidth) / (1.5f);
   float ogl = osc * 0.5f;
   // border
   wxRect rect3 = topwindow->GetClientRect();
   wxRect rect4 = topwindow->GetScreenRect();
   int  borderX = (rect4.width - rect3.width) / 2;
   int  borderY = (rect4.height - rect3.height) / 2;
   // size & pos
   topwindow->SetSize(wxSize(osc - borderX, displayHeight));
   topwindow->SetPosition(wxPoint(ogl + borderX, 0));
}

void maximizeOglWindow(int& outW, int& outH)
{
   // get top level window
   wxApp* pApp = (wxApp*)wxApp::GetInstance();
   wxFrame* topwindow = (wxFrame*)pApp->GetTopWindow();
   // size
   int displayWidth = 0;
   int displayHeight = 0;
   wxDisplaySize(&displayWidth, &displayHeight);
   float osc = float(displayWidth) / (1.5f);
   float ogl = osc * 0.5f;
   // border
   wxRect rect3 = topwindow->GetClientRect();
   wxRect rect4 = topwindow->GetScreenRect();
   int  borderX = (rect4.width - rect3.width) / 2;
   int  borderY = (rect4.height - rect3.height) / 2;
   // ogl
   outW = ogl - borderX;
   outH = displayHeight - borderY - borderX;
   SDL_SetWindowSize(pOsciloscope->sdlWindow, ogl - borderX, displayHeight - borderY - borderX);
   SDL_SetWindowPosition(pOsciloscope->sdlWindow, borderX, borderY);
}

int SDLCALL PopulateFunction(void* data)
{
   ((OsciloskopMeasure*)data)->PopulateWithData();
   return 0;
}

void SetupUI(WndMain& window)
{
   wxApp*         pApp = (wxApp*)wxApp::GetInstance();
   wxWindow* topwindow = pApp->GetTopWindow();
   OsciloskopOsciloskop* pOsc = (OsciloskopOsciloskop*)topwindow;
   pOsc->setupUI(window);
}