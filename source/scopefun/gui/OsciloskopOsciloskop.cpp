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
#include "OsciloskopOsciloskop.h"

OsciloskopOsciloskop::OsciloskopOsciloskop(wxWindow* parent) 
: 
Osciloskop(parent)
{

}

void OsciloskopOsciloskop::onActivate(wxActivateEvent& event)
{
    if(once)
    {
        once = 0;

        #ifndef _DEBUG
            m_menu4->Remove(m_menu4->FindItem("Software Simulator"));
        #endif   

        m_spinBtnDigVoltage->SetRange(-1024*1024, 1024*1024);
        m_spinBtnDigVoltage->SetValue(0);
        m_textCtrlDigitalVoltage->SetValue("1.238");

        if (!isFileWritable())
        {
           wxMessageDialog msgBox(this, "Some features will be disabled. You must run ScopeFun.exe as administrator or install it out of 'Progream Files' folder.", wxT("Warning"), wxOK | wxCENTRE);
           int ret = msgBox.ShowModal();
        }

        wxMenu* menu = new wxMenu();
        GetMenuBar()->Insert(6, menu, "Script");
#if defined(PLATFORM_MAC) || defined(PLATFORM_LINUX) 
        String scriptPath = GetOscDataFolder().GetFullPath().data().AsChar();
#else
        String scriptPath = GetOscDataFolder().GetCwd().data().AsChar();
#endif
        String helpPath  = scriptPath;
               helpPath += "/script/scopefunapi.help";
        scriptPath += "/script/*.lua";
        wxString f = wxFindFirstFile(scriptPath.asChar());
        for(int i = 0; i < SCOPEFUN_MAX_SCRIPT; i++)
        {
            if(f.empty())
            { break; }
            pOsciloscope->m_callback.Add(f.data().AsChar());
            String fileName = f.data().AsChar();
            int pos = fileName.pos("/Script/");
            fileName.remove(0, pos + 1);
            wxMenu* menu = GetMenuBar()->GetMenu(6);
            wxMenuItem* menuItem = menu->AppendCheckItem(wxID_ANY, fileName.asChar(), wxEmptyString);
            Connect(menuItem->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(OsciloskopOsciloskop::MenuScriptSelection), (wxObject*)pOsciloscope->m_callback.Get(i), this);
            f = wxFindNextFile();
        }
        pOsciloscope->m_callback.SetHelp(helpPath);

        pTimer->init(TIMER_MAIN_THREAD);
        ////////////////////////////////////////////////////////////////////////////////////////
        // version
        ////////////////////////////////////////////////////////////////////////////////////////
        wxCommandEvent version2;
        SetDigital13To16(false);
        sfSetDefault(getHw());
        m_comboBoxTimeCapture->Clear();
        for (int i = 0; i < t2cLast; i++)
        {
           m_comboBoxTimeCapture->Append(captureTimeToStr(i));
        }
        m_comboBoxTimeCapture->SetSelection(sfGetXRange(getHw()));
        ////////////////////////////////////////////////////////////////////////////////////////
        // colors
        ////////////////////////////////////////////////////////////////////////////////////////
        setColors(this);
        setColors(pStorage);
        setColors(pConnection);
        setColors(pMeasure);
        setColors(pDebug);
        setColors(pInfo);
        setColors(pDisplay);
        setColors(pThermal);
        setColors(pThermal);
        setColors(pSoftwareGenerator);
        setColors(pHardwareGenerator);
        pTimer->init(TIMER_USERINTERFACE);
        if(pOsciloscope->settings.getSettings()->windowDebug == 0)
        {
            m_menu7->Remove(m_menuItemDebug);
        }
        ////////////////////////////////////////////////////////////////////////////////////////
        // license
        ////////////////////////////////////////////////////////////////////////////////////////
        int agree = checkAgree();
        if(!agree)
        {
            wxCommandEvent nullEvent;
            m_menuItemInfoOnMenuSelection(nullEvent);
        }
        ////////////////////////////////////////////////////////////////////////////////////////
        // icon
        ////////////////////////////////////////////////////////////////////////////////////////
        wxIconBundle icoBundle;
        wxIcon icon16(xpm16_xpm);
        wxIcon icon32(xpm32_xpm);
        wxIcon icon64(xpm64_xpm);
        wxIcon icon96(xpm96_xpm);
        wxIcon icon128(xpm128_xpm);
        wxIcon icon256(xpm256_xpm);
        wxIcon icon512(xpm512_xpm);
        icoBundle.AddIcon(icon16);
        icoBundle.AddIcon(icon32);
        icoBundle.AddIcon(icon64);
        icoBundle.AddIcon(icon96);
        icoBundle.AddIcon(icon128);
        icoBundle.AddIcon(icon512);
        SetIcons(icoBundle);
        m_textCtrlFreqDividerOnTextEnter(version2);
        m_comboBoxTimeCaptureOnCombobox(version2);
        wxCommandEvent evt;
        m_textCtrlTimeFrameSize->SetValue(pFormat->integerToString(10000));
       
        uint sampleSize = atoi(m_textCtrlTimeFrameSize->GetValue().ToAscii().data());
        sfSetSampleSize(getHw(), sampleSize);
        pOsciloscope->window.horizontal.FrameSize = sfGetSampleSize(getHw());
        SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_frameSize, sampleSize*4 + SCOPEFUN_FRAME_HEADER);
    
        m_textCtrlTimeFrameSize->SetValue(wxString::FromAscii(pFormat->integerToString(sfGetSampleSize(getHw()))));

        bool writeOk = isFileWritable();
        if(!writeOk)
        {
            wxMenuItem* item3 = m_menu5->FindItemByPosition(3);
            if(item3)
            { item3->Enable(false); }
            wxMenuItem* item5 = m_menu5->FindItemByPosition(5);
            if(item5)
            { item5->Enable(false); }
            wxMenuItem* item6 = m_menu5->FindItemByPosition(6);
            if(item6)
            { item6->Enable(false); }
        }
        if(pOsciloscope->settings.getSettings()->windowDebug != 2)
        {
            wxMenuItem* item8 = m_menu5->FindItemByPosition(8);
            if(item8)
            { item8->Enable(false); }
            wxMenuItem* item10 = m_menu5->FindItemByPosition(10);
            if(item10)
            { item10->Enable(false); }
        }
    }
}

void OsciloskopOsciloskop::onActivateApp(wxActivateEvent& event)
{
   // TODO: Implement onActivateApp
}

void OsciloskopOsciloskop::onClose(wxCloseEvent& event)
{
    // threds exit
    pOsciloscope->exitThreads();

    // exit
    Destroy();
}

void OsciloskopOsciloskop::OnIdle(wxIdleEvent& event)
{
    ////////////////////////////////////////////////////////////////////////////////
    // timer
    ////////////////////////////////////////////////////////////////////////////////
    pTimer->deltaTime(TIMER_USERINTERFACE);
    timer += pTimer->getDelta(TIMER_USERINTERFACE);
   
    ////////////////////////////////////////////////////////////////////////////////
    // user interface
    ////////////////////////////////////////////////////////////////////////////////
    if(timer > 0.1)
    {   
        double idleTimer = timer;
        timer = 0;

        ////////////////////////////////////////////////////////////////////////////////
        // redirect
        ////////////////////////////////////////////////////////////////////////////////
        for(int i=0;i<pOsciloscope->m_callback.Count();i++)
        {
          OsciloskopDebug* pDebug = (OsciloskopDebug*)pOsciloscope->m_callback.Get(i)->GetUserData();
          if (pDebug)
             pDebug->Redirect();
        }

        ////////////////////////////////////////////////////////////////////////////////
        // undo / redo
        ////////////////////////////////////////////////////////////////////////////////
        m_buttonRedo->Enable(pOsciloscope->isRedoActive());
        m_buttonUndo->Enable(pOsciloscope->isUndoActive());
        ////////////////////////////////////////////////////////////////////////////////
        // reset gui
        ////////////////////////////////////////////////////////////////////////////////
        if(SDL_AtomicGet(&pOsciloscope->callibrate.resetUI) > 0)
        {
            // frame
            pOsciloscope->window.horizontal.Frame = 0;
            SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_frameIndex, 0);
            // mode
            pOsciloscope->window.horizontal.Mode = SIGNAL_MODE_PAUSE;
            SDL_AtomicSet(&pOsciloscope->signalMode, SIGNAL_MODE_PAUSE);
            // clear render target
            SDL_AtomicSet(&pOsciloscope->clearRenderTarget, 1);
            // user interface
            setupUI(pOsciloscope->window);
            // transfer
            pOsciloscope->transferData();
            // exit
            SDL_AtomicSet(&pOsciloscope->callibrate.resetUI, 0);
        }
        ////////////////////////////////////////////////////////////////////////////////
        // message box
        ////////////////////////////////////////////////////////////////////////////////
        if(pOsciloscope->callibrate.active)
        {
            switch(pOsciloscope->callibrate.messageBox)
            {
                case acmbStart:
                case acmbChannel00:
                case acmbChannel01:
                case acmbChannel10:
                case acmbChannel11:
                case acmbEnd:
                    {
                        wxString message;
                        if(pOsciloscope->callibrate.messageBox == acmbChannel00)
                        {
                            message = wxT("Cable connect generator 1(awg1) with channel 1(ch1). Then click OK to proceed.");
                        }
                        if(pOsciloscope->callibrate.messageBox == acmbChannel01)
                        {
                            message = wxT("Cable connect generator 1(awg1) with channel 2(ch2). Then click OK to proceed.");
                        }
                        if(pOsciloscope->callibrate.messageBox == acmbChannel10)
                        {
                            message = wxT("Cable connect generator 2(awg2) with channel 1(ch1). Then click OK to proceed.");
                        }
                        if(pOsciloscope->callibrate.messageBox == acmbChannel11)
                        {
                            message = wxT("Cable connect generator 2(awg2) with channel 2(ch2). Then click OK to proceed.");
                        }
                        if(pOsciloscope->callibrate.messageBox == acmbStart)
                        {
                            message = wxT("This action will start automatic callibration. Disconnect all channels and generators. Click OK to proceed or Cancel to abort.");
                        }
                        if(pOsciloscope->callibrate.messageBox == acmbEnd)
                        {
                            message = wxT("Automatic callibration was successfull. Click OK to save callibration data.");
                        }
                        pOsciloscope->callibrate.messageBox = acmbNone;
                        wxMessageDialog msgBox(this, message, wxT("Automatic Callibration"), wxCANCEL | wxOK | wxCENTRE);
                        int ret = msgBox.ShowModal();
                        if(ret == wxID_OK)
                        {
                            pOsciloscope->callibrate.messageBox = acmbOk;
                        }
                        if(ret == wxID_CANCEL)
                        {
                            pOsciloscope->callibrate.messageBox = acmbCancel;
                        }
                    }
                    break;
            };
        }
        ////////////////////////////////////////////////////////////////////////////////
        // usb
        ////////////////////////////////////////////////////////////////////////////////
        int usb = pOsciloscope->thread.isOpen();
        m_checkBox26->SetValue(usb);

        static int open = 0;
        int isFpga   = pOsciloscope->thread.isFpga();
        int isOpen   = pOsciloscope->thread.isOpen();
        if (isOpen && isFpga)
           open = 1;
        if (open == 1 && isOpen && !isFpga)
        {
           open = 0;
           pOsciloscope->thread.function(EThreadApiFunction::afCloseUsb);
           pOsciloscope->thread.wait();
        }

        m_buttonCapture->Enable();
        //else
        {
           // startup ... try to connect
           static double usbTimer   = 0.0;
                         usbTimer  += idleTimer;

           // query ... fpga and usb
           if (usbTimer > 2.0 )
           {
              pOsciloscope->thread.function(EThreadApiFunction::afIsOpened);
              pOsciloscope->thread.wait();

              pOsciloscope->thread.function(EThreadApiFunction::afReadFpgaStatus);
              pOsciloscope->thread.wait();

              // usb
              if (!pOsciloscope->thread.isOpen())
              {
                 pOsciloscope->thread.openUSB(pOsciloscope->settings.getHardware());             
              }
              else // fpga
              {
                 if (!pOsciloscope->thread.isFpga())
                 {
                    pOsciloscope->thread.uploadFpga( pOsciloscope->settings.getHardware() );
                    pOsciloscope->thread.function(EThreadApiFunction::afReadFpgaStatus);
                    pOsciloscope->thread.wait();
                    if (pOsciloscope->thread.isFpga())
                    {
                       pOsciloscope->thread.useEepromCallibration(pOsciloscope->settings.getHardware());
                       pOsciloscope->thread.hardwareControlFunction(getHw());
                       pOsciloscope->thread.wait();
                       wxCommandEvent event;
                       m_comboBoxCh0CaptureOnCombobox(event);
                       m_comboBoxCh1CaptureOnCombobox(event);
                       pOsciloscope->transferData();
                    }
                 }
              }
              usbTimer = 0;
           }

        /*   m_buttonCapture->Disable();*/
        }

        ////////////////////////////////////////////////////////////////////////////////
        // trigger LED
        ////////////////////////////////////////////////////////////////////////////////
        if(pOsciloscope->display.attr.getCount())
        {
            if(pOsciloscope->display.attr.getCount())
            {
                byte attr = pOsciloscope->display.attr[0];
                if(attr & FRAME_ATTRIBUTE_TRIGGERED_LED)
                {
                    m_radioBtnTriggered->SetValue(true);
                }
                else
                {
                    m_radioBtnTriggered->SetValue(false);
                }
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        // frame index
        ////////////////////////////////////////////////////////////////////////////////
        SignalMode mode = (SignalMode)SDL_AtomicGet(&pOsciloscope->signalMode);
        if(mode == SIGNAL_MODE_CAPTURE || mode == SIGNAL_MODE_SIMULATE || mode == SIGNAL_MODE_PLAY)
        {
            int frameIndex = SDL_AtomicGet(&pOsciloscope->m_captureBuffer.m_frameIndex);
            int frameCount = SDL_AtomicGet(&pOsciloscope->m_captureBuffer.m_frameCount);
            m_sliderTimeFrame->SetMax(frameCount);
            m_sliderTimeFrame->SetValue(frameIndex);
            m_textCtrlTimeFrame->SetValue(wxString::FromAscii(pFormat->integerToString(frameIndex)));
        }
        ////////////////////////////////////////////////////////////////////////////////
        // measure
        ////////////////////////////////////////////////////////////////////////////////
        pTimer->deltaTime(TIMER_MEASURE);
        if(pMeasure && pMeasure->IsShown() && pOsciloscope->scrollThread == false)
        {
            pMeasure->PopulateWithData();
        }
        if(pMeasure && pMeasure->IsShown())
        {
            if(pOsciloscope->window.measure.data.pickX0.updateUI)
            {
                pOsciloscope->window.measure.data.pickX0.updateUI = false;
                pMeasure->setTextCtrlX(pMeasure->m_textCtrlX0, pMeasure->m_choiceX0, pOsciloscope->window.measure.data.pickX0.position.getXTime());
            }
            if(pOsciloscope->window.measure.data.pickX1.updateUI)
            {
                pOsciloscope->window.measure.data.pickX1.updateUI = false;
                pMeasure->setTextCtrlX(pMeasure->m_textCtrlX1, pMeasure->m_choiceX1, pOsciloscope->window.measure.data.pickX1.position.getXTime());
            }
            if(pOsciloscope->window.measure.data.pickY0.updateUI)
            {
                pOsciloscope->window.measure.data.pickY0.updateUI = false;
                pMeasure->setTextCtrlY(pMeasure->m_textCtrlY0, pOsciloscope->window.measure.data.pickY0.position.getYVolt(pMeasure->m_choiceY0->GetSelection()));
            }
            if(pOsciloscope->window.measure.data.pickY1.updateUI)
            {
                pOsciloscope->window.measure.data.pickY1.updateUI = false;
                pMeasure->setTextCtrlY(pMeasure->m_textCtrlY1, pOsciloscope->window.measure.data.pickY1.position.getYVolt(pMeasure->m_choiceY1->GetSelection()));
            }
            if(pOsciloscope->window.measure.data.pickFFT0.updateUI)
            {
                pOsciloscope->window.measure.data.pickFFT0.updateUI = false;
                pMeasure->setTextCtrlFreq(pMeasure->m_textCtrlFFT0, pMeasure->m_choiceFFT0, pOsciloscope->window.measure.data.pickFFT0.position.getXFreq());
            }
            if(pOsciloscope->window.measure.data.pickFFT1.updateUI)
            {
                pOsciloscope->window.measure.data.pickFFT1.updateUI = false;
                pMeasure->setTextCtrlFreq(pMeasure->m_textCtrlFFT1, pMeasure->m_choiceFFT1, pOsciloscope->window.measure.data.pickFFT1.position.getXFreq());
            }
        }
        ////////////////////////////////////////////////////////////////////////////////
        // debug
        ////////////////////////////////////////////////////////////////////////////////
        if(pDebug && pDebug->IsShown())
        {
            if(SDL_AtomicGet(&pOsciloscope->signalMode) != SIGNAL_MODE_PAUSE)
            {
                pDebug->Clear();
                int count = min(32, pOsciloscope->display.debug.getCount());
                FORMAT_BUFFER();
                for(int i = 0; i < count / 2; i++)
                {
                    ushort wordToPrint = (ushort(pOsciloscope->display.debug[2 * i]) << 8) | pOsciloscope->display.debug[2 * i + 1];
                    FORMAT("%d HEX:%04x DEC:%04d \n", i, wordToPrint, wordToPrint);
                    pDebug->AppendText(formatBuffer);
                }
            }
        }
    }
    ////////////////////////////////////////////////////////////////////////////////
    // update script text
    ////////////////////////////////////////////////////////////////////////////////
    for(int i = 0; i < pOsciloscope->m_callback.Count(); i++)
    {
        OsciloscopeScript* script = pOsciloscope->m_callback.Get(i);
        script->GetPrint();
        OsciloskopDebug* debug = (OsciloskopDebug*)script->GetUserData();
        if(debug)
        {
            pDebug->AppendText(script->GetPrint());
            script->ClrPrint();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // render
    ////////////////////////////////////////////////////////////////////////////////
    pOsciloscope->Render();
    
    ////////////////////////////////////////////////////////////////////////////////
    // continue loop
    ////////////////////////////////////////////////////////////////////////////////
    event.Skip();
    event.RequestMore();
}

void OsciloskopOsciloskop::OnSetFocus(wxFocusEvent& event)
{
// TODO: Implement OnSetFocus
}

void OsciloskopOsciloskop::OnSize(wxSizeEvent& event)
{
    this->SetSize(event.GetSize().GetX(), event.GetSize().GetY());
    this->Layout();
    this->Refresh();
}

void OsciloskopOsciloskop::m_menuItem1OnMenuSelection(wxCommandEvent& event)
{
    wxFileDialog* LoadDialog = new wxFileDialog(this, _("Load File As _?"), wxEmptyString, wxEmptyString,
                                                _("*.osc"),
                                                wxFD_OPEN | wxFD_FILE_MUST_EXIST, wxDefaultPosition);
    // Creates a Save Dialog with 4 file types
    int show = LoadDialog->ShowModal();
    if(show == wxID_OK)   // If the user clicked "OK"
    {
        // file
        String file = LoadDialog->GetPath().ToAscii().data();
        LoadDialog->Destroy();
        // show dialog
        wxProgressDialog progressDlg(_("Loading File"), _("in progress..."), 100, this, wxPD_APP_MODAL | wxPD_AUTO_HIDE | wxPD_CAN_ABORT);
        progressDlg.ShowModal();
        // run thread
        pOsciloscope->loadFromFile(file.asChar());
        // loop
        int active = 1;
        while(active)
        {
            int progress = pOsciloscope->m_captureBuffer.getProgress();
            active = pOsciloscope->m_captureBuffer.isActive();
            progressDlg.Update(progress);
            if(progressDlg.WasCancelled())
            { pOsciloscope->m_captureBuffer.disable(); }

            pOsciloscope->Render();
        }
        // destroy
        progressDlg.Destroy();
    }
    else
    {
        LoadDialog->Destroy();
    }
}

void OsciloskopOsciloskop::m_menuItem2OnMenuSelection(wxCommandEvent& event)
{
    wxFileDialog* SaveDialog = new wxFileDialog(this, _("Save File As _?"), wxEmptyString, wxEmptyString,
                                                _("*.osc"),
                                                wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);
    // Creates a Save Dialog with 4 file types
    int show = SaveDialog->ShowModal();
    if(show == wxID_OK)   // If the user clicked "OK"
    {
        // file
        String file = SaveDialog->GetPath().ToAscii().data();
        SaveDialog->Destroy();
        // show dialog
        wxProgressDialog progressDlg(_("Saving File"), _("in progress..."), 100, this, wxPD_APP_MODAL | wxPD_AUTO_HIDE | wxPD_CAN_ABORT);
        progressDlg.ShowModal();
        // run thread
        pOsciloscope->saveToFile(file.asChar());
        // loop
        int active = 1;
        while(active)
        {
            int progress = pOsciloscope->m_captureBuffer.getProgress();
            active = pOsciloscope->m_captureBuffer.isActive();
            progressDlg.Update(progress);
            if(progressDlg.WasCancelled())
            { pOsciloscope->m_captureBuffer.disable(); }

            pOsciloscope->Render();
        }
        // destroy
        progressDlg.Destroy();
    }
    else
    {
        SaveDialog->Destroy();
    }
}

void OsciloskopOsciloskop::m_menuItem3OnMenuSelection(wxCommandEvent& event)
{
    Close(true);
}

void OsciloskopOsciloskop::m_menuItem20OnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->window.fftDigital.raise(VIEW_SELECT_OSC_3D);
    pOsciloscope->window.fftDigital.lower(VIEW_SELECT_OSC_2D);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(0)->Check(1);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(1)->Check(0);
    pOsciloscope->oscCameraSetup(1);
}

void OsciloskopOsciloskop::m_menuItem21OnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->window.fftDigital.lower(VIEW_SELECT_OSC_3D);
    pOsciloscope->window.fftDigital.raise(VIEW_SELECT_OSC_2D);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(0)->Check(0);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(1)->Check(1);
    pOsciloscope->oscCameraSetup(0);
}

void OsciloskopOsciloskop::m_menuItem22OnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->window.fftDigital.raise(VIEW_SELECT_FFT_3D);
    pOsciloscope->window.fftDigital.lower(VIEW_SELECT_FFT_2D);
    pOsciloscope->window.fftDigital.lower(VIEW_SELECT_DIGITAL);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(2)->Check(1);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(3)->Check(0);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(4)->Check(0);
    pOsciloscope->fftCameraSetup(1);
}

void OsciloskopOsciloskop::m_menuItem23OnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->window.fftDigital.lower(VIEW_SELECT_FFT_3D);
    pOsciloscope->window.fftDigital.raise(VIEW_SELECT_FFT_2D);
    pOsciloscope->window.fftDigital.lower(VIEW_SELECT_DIGITAL);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(2)->Check(0);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(3)->Check(1);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(4)->Check(0);
    pOsciloscope->fftCameraSetup(0);
}

void OsciloskopOsciloskop::m_menuItem6OnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->window.fftDigital.lower(VIEW_SELECT_FFT_3D);
    pOsciloscope->window.fftDigital.lower(VIEW_SELECT_FFT_2D);
    pOsciloscope->window.fftDigital.raise(VIEW_SELECT_DIGITAL);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(2)->Check(0);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(3)->Check(0);
    GetMenuBar()->GetMenu(1)->FindItemByPosition(4)->Check(1);
    pOsciloscope->fftCameraSetup(0);
}

void OsciloskopOsciloskop::m_menuItem8OnMenuSelection(wxCommandEvent& event)
{
    if(!pDisplay)
    {
        pDisplay = new OsciloskopDisplay(this);
    }
    pDisplay->Show();
}

void OsciloskopOsciloskop::m_menuItem9OnMenuSelection(wxCommandEvent& event)
{
    if(!pThermal)
    {
        pThermal = new OsciloskopThermal(this);
    }
    pThermal->Show();
}

void OsciloskopOsciloskop::m_menuItemSoftwareOnMenuSelection(wxCommandEvent& event)
{
    if(!pSoftwareGenerator)
    {
        pSoftwareGenerator = new OsciloskopSoftwareGenerator(this);
    }
    pSoftwareGenerator->Show();
}

void OsciloskopOsciloskop::m_menuItem11OnMenuSelection(wxCommandEvent& event)
{
    if(!pHardwareGenerator)
    {
        pHardwareGenerator = new OsciloskopHardwareGenerator(this);
    }
    pHardwareGenerator->Show();
}

void OsciloskopOsciloskop::m_menuItemReadEEPROMOnMenuSelection(wxCommandEvent& event)
{
    // pause
    wxCommandEvent evt;
    m_buttonPauseOnButtonClick(evt);
    // firmware id
    String  ID;
    SEeprom eeprom;
    int     size   = 0;
    int     offset = 0;
    memset(eeprom.data.bytes, 0x00, sizeof(SEeprom));
    pOsciloscope->thread.readFirmwareIDFromEEPROM(pOsciloscope->settings.getHardware());
    pOsciloscope->thread.getEEPROM(&eeprom, &size, &offset);
    ID = (char*)&eeprom.data.bytes[0];
    // data
    memset(eeprom.data.bytes, 0x00, sizeof(SEeprom));
    pOsciloscope->thread.readUsbFromEEPROM(pOsciloscope->settings.getHardware(), (16 * EEPROM_BYTE_COUNT));
    pOsciloscope->thread.getEEPROM(&eeprom, &size, &offset);
    // debug
    wxCommandEvent et;
    m_menuItemDebugOnMenuSelection(et);
    if(pDebug && pDebug->IsShown())
    {
        pDebug->Clear();
        FORMAT_BUFFER();
        FORMAT("%s \n", (char*)ID.asChar());
        pDebug->AppendText(wxString::FromAscii(formatBuffer));
        int count = min(16, size / EEPROM_BYTE_COUNT);
        for(int i = 0; i < count; i++)
        {
            for(int j = 0; j < EEPROM_BYTE_COUNT; j++)
            {
                byte byteToPrint = eeprom.data.bytes[i * EEPROM_BYTE_COUNT + j];
                FORMAT("%02x ", byteToPrint);
                pDebug->AppendText(wxString::FromAscii(formatBuffer));
            }
            pDebug->AppendText(wxString::FromAscii("\n"));
        }
    }
}

void OsciloskopOsciloskop::m_menuItemWriteEEPROMOnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->thread.writeUsbToEEPROM(pOsciloscope->settings.getHardware());
}

void OsciloskopOsciloskop::m_menuItem12OnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->AutoCallibrate();
}

void OsciloskopOsciloskop::m_menuItemWriteCallibrateOnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->settings.load();
    pOsciloscope->thread.writeCallibrateSettingsToEEPROM(pOsciloscope->settings.getHardware());
}

void OsciloskopOsciloskop::m_menuItemReadCallibrateOnMenuSelection(wxCommandEvent& event)
{
    // pause
    wxCommandEvent evt;
    m_buttonPauseOnButtonClick(evt);
    // read
    SEeprom eeprom;
    int     size = 0;
    int     offset = 0;
    memset(eeprom.data.bytes, 0xdd, sizeof(SEeprom));
    if (pOsciloscope->thread.readCallibrateSettingsFromEEPROM(pOsciloscope->settings.getHardware())== SCOPEFUN_SUCCESS)
    {
       pOsciloscope->thread.getEEPROM(&eeprom, &size, &offset);

       // save
       OscHardware* save = pOsciloscope->settings.getHardware();
       cJSON* json = save->json;
       save->load();
       SDL_memcpy(save, &eeprom, size);
       save->json = json;
       save->save();

       // debug
       wxCommandEvent et;
       m_menuItemDebugOnMenuSelection(et);
       if (pDebug && pDebug->IsShown())
       {
          pDebug->Clear();
          FORMAT_BUFFER();
          int count = min(16, size / EEPROM_BYTE_COUNT);
          for (int i = 0; i < count; i++)
          {
             for (int j = 0; j < EEPROM_BYTE_COUNT; j++)
             {
                byte byteToPrint = eeprom.data.bytes[i * EEPROM_BYTE_COUNT + j];
                FORMAT("%02x ", byteToPrint);
                pDebug->AppendText(wxString::FromAscii(formatBuffer));
             }
             pDebug->AppendText(wxString::FromAscii("\n"));
          }
       }
    }
}

void OsciloskopOsciloskop::m_menuItemWriteCertificateOnMenuSelection(wxCommandEvent& event)
{
    m_buttonConnectOnButtonClick(event);
    pOsciloscope->thread.wait();
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Clipboard data will be written to EEPROM.", "Please copy data to clipboard before proceeding.", 0);
    if(wxTheClipboard->Open())
    {
        if(wxTheClipboard->IsSupported(wxDF_TEXT))
        {
            wxTextDataObject data;
            if(wxTheClipboard->GetData(data))
            {
                wxString string = data.GetText();
                char* src = (char*)string.To8BitData().data();
                cJSON_Minify(src);
                size_t size = SDL_strlen(src);
                if(size > 256)
                {
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Clipboard data is too large.", " Max. 256 bytes can be written.", 0);
                }
                else
                {
                    cJSON* json = cJSON_Parse(src);
                    bool isValid = json && json->child && json->child[0].next;
                    if(isValid && SDL_memcmp(json->child[0].next->valuestring, ((UsbContext*)getCtx()->usb)->serialBuffer, ((UsbContext*)getCtx()->usb)->serialBufferSize) == 0)
                    {
                        char zeroAll[256] = { 0 };
                        int ret = usbFx3WriteLockableEEPROM((UsbContext*)getCtx()->usb, (unsigned char*)zeroAll, 256, 0);
                        if(ret == PUREUSB_SUCCESS)
                        {
                            int ret = usbFx3WriteLockableEEPROM((UsbContext*)getCtx()->usb, (unsigned char*)src, size, 0);
                            if(ret == PUREUSB_SUCCESS)
                            {
                                char verify[256] = { 0 };
                                ret = usbFx3ReadLockableEEPROM((UsbContext*)getCtx()->usb, (unsigned char*)verify, size, 0);
                                if(ret == PUREUSB_SUCCESS)
                                {
                                    if(SDL_memcmp((unsigned char*)src, verify, size) == 0)
                                    {
                                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Clipboard data written and verifyed tha all written bits match original.", verify, 0);
                                    }
                                    else
                                    {
                                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Verifing written bits failed.", verify, 0);
                                    }
                                }
                                else
                                {
                                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Reading written bits failed.", "failed", 0);
                                }
                            }
                            else
                            {
                                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Writting bits failed.", "failed", 0);
                            }
                        }
                    }
                    else
                    {
                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Clipboard data serial id does not match usb.", "Serial id is incorrect.", 0);
                    }
                }
            }
        }
    }
}

void OsciloskopOsciloskop::m_menuItemReadCertificateOnMenuSelection(wxCommandEvent& event)
{
    m_buttonConnectOnButtonClick(event);
    pOsciloscope->thread.wait();
    char verify[257] = { 0 };
    int ret = usbFx3ReadLockableEEPROM((UsbContext*)getCtx()->usb, (unsigned char*)verify, 256, 0);
    if(ret == PUREUSB_SUCCESS)
    {
        if(wxTheClipboard->Open())
        {
            wxString string = wxString::From8BitData(verify);
            wxTextDataObject* data = new wxTextDataObject(string);
            wxTheClipboard->SetData(data);
            wxTheClipboard->Flush();
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Certificate data was read and written to clipboard.", string.data().AsChar(), 0);
        }
    }
}

void OsciloskopOsciloskop::m_menuItemLockCertificateOnMenuSelection(wxCommandEvent& event)
{
    const SDL_MessageBoxButtonData buttons[] =
    {
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "no" },
        { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "yes" },
    };
    const SDL_MessageBoxColorScheme colorScheme =
    {
        { /* .colors (.r, .g, .b) */
            /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
            { 255,   0,   0 },
            /* [SDL_MESSAGEBOX_COLOR_TEXT] */
            {   0, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
            { 255, 255,   0 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
            {   0,   0, 255 },
            /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
            { 255,   0, 255 }
        }
    };
    const SDL_MessageBoxData messageboxdata =
    {
        SDL_MESSAGEBOX_INFORMATION, /* .flags */
        NULL, /* .window */
        "Data will be locked permanently.", /* .title */
        "This action cannot be undone.", /* .message */
        SDL_arraysize(buttons), /* .numbuttons */
        buttons, /* .buttons */
        &colorScheme /* .colorScheme */
    };
    int buttonid = 0;
    int ret = SDL_ShowMessageBox(&messageboxdata, &buttonid);
    if(buttonid == SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT)
    {
        m_buttonConnectOnButtonClick(event);
        pOsciloscope->thread.wait();
        int ret = usbFx3LockLockableEEPROM((UsbContext*)getCtx()->usb);
        if(ret == PUREUSB_SUCCESS)
        {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Data locked.", "permanently", 0);
        }
    }
}

void OsciloskopOsciloskop::m_menuItemResetEEPROMOnMenuSelection(wxCommandEvent& event)
{
    pOsciloscope->thread.eraseEEPROM(pOsciloscope->settings.getHardware());
}

void OsciloskopOsciloskop::m_menuItem15OnMenuSelection(wxCommandEvent& event)
{
    if(!pMeasure)
    {
        pMeasure = new OsciloskopMeasure(this);
    }
    pMeasure->Show();
}

void OsciloskopOsciloskop::m_menuItemDebugOnMenuSelection(wxCommandEvent& event)
{
    if(!pDebug)
    {
        pDebug = new OsciloskopDebug(this);
    }
    pDebug->Show();
}

void OsciloskopOsciloskop::m_menuItemInfoOnMenuSelection(wxCommandEvent& event)
{
    if(!pInfo)
    {
        pInfo = new OsciloskopInfo(this);
    }
    pInfo->Show();
}

void OsciloskopOsciloskop::m_buttonConnectOnButtonClick(wxCommandEvent& event)
{
    pOsciloscope->thread.openUSB(pOsciloscope->settings.getHardware());
    pOsciloscope->thread.useEepromCallibration(pOsciloscope->settings.getHardware());
    if(!pOsciloscope->thread.isFpga())
    { pOsciloscope->thread.writeFpgaToArtix7(getHw(), pOsciloscope->settings.getHardware()); }
    m_comboBoxCh0CaptureOnCombobox(event);
    m_comboBoxCh1CaptureOnCombobox(event);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_buttonDisconnectOnButtonClick(wxCommandEvent& event)
{
    pOsciloscope->thread.function(afCloseUsb);
    SDL_AtomicSet(&pOsciloscope->signalMode, SIGNAL_MODE_PAUSE);
    pOsciloscope->window.horizontal.Mode = SIGNAL_MODE_PAUSE;
    // must sync close button usbClose and usbCapture thread
    // currrent fix is that we just wait a second which should be enought for the capture thread to exit capture state in most cases
    SDL_Delay(1000);
    m_buttonPauseOnButtonClick(event);
}

void OsciloskopOsciloskop::m_buttonUndoOnButtonClick(wxCommandEvent& event)
{
    pOsciloscope->transferUndo();
    event.Skip();
}

void OsciloskopOsciloskop::m_buttonRedoOnButtonClick(wxCommandEvent& event)
{
    pOsciloscope->transferRedo();
    event.Skip();
}

void OsciloskopOsciloskop::m_comboBoxTimeControlOnCombobox(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.Control = m_comboBoxTimeControl->GetSelection();
    sfSetControl(getHw(), pOsciloscope->window.horizontal.Control);
    pOsciloscope->transferData();
    if(sfGetControl(getHw()) == 3)
    {
        usbFx3Reset((UsbContext*)pOsciloscope->ctx->sf.usb);
    }
}

void OsciloskopOsciloskop::m_comboBoxTimeCaptureOnCombobox(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.Capture = captureTimeFromEnum(m_comboBoxTimeCapture->GetSelection());
    SDL_AtomicSet(&pOsciloscope->threadCapture, m_comboBoxTimeCapture->GetSelection());
    if(captureTimeFromValue(pOsciloscope->window.horizontal.Capture) == t2c2ns)
    {
        // 500 Mhz help
        m_comboBoxCh1Capture->SetSelection(m_comboBoxCh0Capture->GetSelection());
        double oldTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
        pOsciloscope->window.channel02.Capture = captureVoltFromEnum(m_comboBoxCh0Capture->GetSelection());
        pOsciloscope->window.channel02.Scale = pFormat->stringToFloat(m_textCtrlCh0Scale->GetValue().ToAscii().data());
        pOsciloscope->window.channel02.Display = pOsciloscope->window.channel02.Capture;
        uint capture0 = m_comboBoxCh0Capture->GetSelection();
        sfSetYRangeScaleB(getHw(), pOsciloscope->getAttr(capture0), pOsciloscope->getGain(1, capture0));
        // steps
        float    time = pOsciloscope->window.horizontal.Capture;
        float capture = pOsciloscope->window.channel01.Capture;
        pOsciloscope->window.channel01.YPosition = double(m_sliderCh0Position->GetValue()) * pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, capture);
        pOsciloscope->window.channel02.YPosition = double(m_sliderCh0Position->GetValue()) * pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, capture);
        double stepsA = double(pOsciloscope->window.channel01.YPosition) / pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, capture);
        double stepsB = double(pOsciloscope->window.channel02.YPosition) / pOsciloscope->settings.getHardware()->getAnalogStep(time, 1, capture);
        sfSetYPositionA(getHw(), stepsA + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 0, capture));
        sfSetYPositionB(getHw(), stepsB + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 1, capture));
        m_sliderCh0Position->SetValue(stepsA);
        m_textCtrlCh0Position->SetValue(pFormat->doubleToString(pOsciloscope->window.channel01.YPosition));
        m_sliderCh1Position->SetValue(stepsB);
        m_textCtrlCh1Position->SetValue(pFormat->doubleToString(pOsciloscope->window.channel02.YPosition));
        float volt;
        uint  unit;
        _setYDisplay(volt, unit, (VoltageCapture)m_comboBoxCh1Capture->GetSelection());
        //
        double newTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
        RecalculateTriggerPosition(oldTriggerVoltagePerStep, newTriggerVoltagePerStep);
    }
    sfSetXRange(getHw(), m_comboBoxTimeCapture->GetSelection());
    pOsciloscope->transferData();
    //
    pOsciloscope->window.horizontal.Display = pOsciloscope->window.horizontal.Capture;
    uint  multiEnum = multiplyerFromValue(pOsciloscope->window.horizontal.Display);
    float multiFloat = multiplyerFromEnum(multiEnum);
    pOsciloscope->window.measure.ClearCapture();
    if(captureTimeFromValue(pOsciloscope->window.horizontal.Capture) == t2c2ns)
    {
        m_comboBoxCh0CaptureOnCombobox(event);
    }
}

void OsciloskopOsciloskop::m_checkBoxETSOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.ETS = m_checkBoxETS->GetValue() ? 1 : 0;
    sfSetEts(getHw(), pOsciloscope->window.horizontal.ETS);
    pOsciloscope->transferData();
    SDL_AtomicSet(&pOsciloscope->clearRenderTarget,1);
    // pOsciloscope->clearEts(pOsciloscope->window.horizontal.ETS);
    // pOsciloscope->clearRenderTarget = !pOsciloscope->window.horizontal.ETS;
    //  pOsciloscope->sim = pOsciloscope->GetServerSim();
    // pOsciloscope->thread.setSimulateData(&pOsciloscope->sim);
    // pOsciloscope->thread.function(afSetSimulateData);
}

void OsciloskopOsciloskop::m_checkBoxFullOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.Full = m_checkBoxFull->GetValue();
}

void OsciloskopOsciloskop::m_textCtrlTimePositionOnTextEnter(wxCommandEvent& event)
{
    SDL_AtomicSet(&pOsciloscope->clearThermal, 1);
    pOsciloscope->window.horizontal.Position = pFormat->stringToFloat(m_textCtrlTimePosition->GetValue().ToAscii().data());
    m_sliderTimePosition->SetValue(pOsciloscope->window.horizontal.Position);
}

void OsciloskopOsciloskop::m_spinBtnXPosOnSpinDown(wxSpinEvent& event)
{
    m_sliderTimePosition->SetValue(m_sliderTimePosition->GetValue() - 1);
    wxScrollEvent e;
    m_sliderTimePositionOnScroll(e);
}

void OsciloskopOsciloskop::m_spinBtnXPosOnSpinUp(wxSpinEvent& event)
{
    m_sliderTimePosition->SetValue(m_sliderTimePosition->GetValue() + 1);
    wxScrollEvent e;
    m_sliderTimePositionOnScroll(e);
}

void OsciloskopOsciloskop::m_sliderTimePositionOnScroll(wxScrollEvent& event)
{
    SDL_AtomicSet(&pOsciloscope->clearThermal, 1);
    pOsciloscope->window.horizontal.Position = m_sliderTimePosition->GetValue();
    m_textCtrlTimePosition->SetValue(wxString::FromAscii(pFormat->floatToString(pOsciloscope->window.horizontal.Position)));
}

void OsciloskopOsciloskop::m_textCtrlTimeFrameOnTextEnter(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.Frame = pFormat->stringToFloat(m_textCtrlTimeFrame->GetValue().ToAscii().data());
    m_sliderTimeFrame->SetValue(pOsciloscope->window.horizontal.Frame);
    SDL_AtomicSet(&pOsciloscope->clearRenderTarget, 1);
}

void OsciloskopOsciloskop::m_spinBtnFrameHistoryOnSpinDown(wxSpinEvent& event)
{
    m_sliderTimeFrame->SetValue(m_sliderTimeFrame->GetValue() - 1);
    wxScrollEvent e;
    m_sliderTimeFrameOnScroll(e);
}

void OsciloskopOsciloskop::m_spinBtnFrameHistoryOnSpinUp(wxSpinEvent& event)
{
    m_sliderTimeFrame->SetValue(m_sliderTimeFrame->GetValue() + 1);
    wxScrollEvent e;
    m_sliderTimeFrameOnScroll(e);
}

void OsciloskopOsciloskop::m_sliderTimeFrameOnScroll(wxScrollEvent& event)
{
    pOsciloscope->window.horizontal.Frame = m_sliderTimeFrame->GetValue();
    SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_frameIndex,  pOsciloscope->window.horizontal.Frame);
    //SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_playIndex,   pOsciloscope->window.horizontal.Frame);
    //SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_pauseIndex,  pOsciloscope->window.horizontal.Frame);
    m_textCtrlTimeFrame->SetValue(wxString::FromAscii(pFormat->floatToString(pOsciloscope->window.horizontal.Frame)));
    pOsciloscope->window.horizontal.Frame = pOsciloscope->window.horizontal.Frame;
    SDL_AtomicSet(&pOsciloscope->clearRenderTarget, 1);
}

void OsciloskopOsciloskop::m_buttonPlayOnButtonClick(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.Mode = SIGNAL_MODE_PLAY;
    SDL_AtomicSet(&pOsciloscope->signalMode, SIGNAL_MODE_PLAY);
    pOsciloscope->simOnOff(0);
    if(!pOsciloscope->settings.getColors()->windowDefault)
    {
        SetButtonColors();
        m_buttonPlay->SetBackgroundColour(pOsciloscope->settings.getColors()->windowFront);
        m_buttonPlay->SetForegroundColour(pOsciloscope->settings.getColors()->windowBack);
    }
    if(event.GetClientData() == 0)
    { pOsciloscope->transferData(); }
    m_buttonPause->Enable();
    m_buttonPlay->Disable();
    m_buttonCapture->Enable();
    m_buttonSimulate->Enable();
    m_buttonClear->Enable();
}

void OsciloskopOsciloskop::m_buttonPauseOnButtonClick(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.Mode = SIGNAL_MODE_PAUSE;
    SDL_AtomicSet(&pOsciloscope->signalMode, SIGNAL_MODE_PAUSE);
    pOsciloscope->simOnOff(0);
    if(!pOsciloscope->settings.getColors()->windowDefault)
    {
        SetButtonColors();
        m_buttonPause->SetBackgroundColour(pOsciloscope->settings.getColors()->windowFront);
        m_buttonPause->SetForegroundColour(pOsciloscope->settings.getColors()->windowBack);
    }
    if(event.GetClientData() == 0)
    { pOsciloscope->transferData(); }
    m_buttonPause->Disable();
    m_buttonPlay->Enable();
    m_buttonCapture->Enable();
    m_buttonSimulate->Enable();
    m_buttonClear->Enable();
}

void OsciloskopOsciloskop::m_buttonCaptureOnButtonClick(wxCommandEvent& event)
{
    int isFpga = pOsciloscope->thread.isFpga();
    int isOpen = pOsciloscope->thread.isOpen();
    if (isOpen && isFpga)
    {
       pOsciloscope->window.horizontal.Mode = SIGNAL_MODE_CAPTURE;
       SDL_AtomicSet(&pOsciloscope->signalMode, SIGNAL_MODE_CAPTURE);
       pOsciloscope->simOnOff(0);
       if (!pOsciloscope->settings.getColors()->windowDefault)
       {
          SetButtonColors();
          m_buttonCapture->SetBackgroundColour(pOsciloscope->settings.getColors()->windowFront);
          m_buttonCapture->SetForegroundColour(pOsciloscope->settings.getColors()->windowBack);
       }
       if (event.GetClientData() == 0)
       {
          pOsciloscope->transferData();
       }
       m_buttonPause->Enable();
       m_buttonPlay->Enable();
       m_buttonCapture->Disable();
       m_buttonSimulate->Enable();
       m_buttonClear->Enable();
    }
}

void OsciloskopOsciloskop::m_buttonSimulateOnButtonClick(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.Mode = SIGNAL_MODE_SIMULATE;
    SDL_AtomicSet(&pOsciloscope->signalMode, SIGNAL_MODE_SIMULATE);
    pOsciloscope->simOnOff(1);
    if(!pOsciloscope->settings.getColors()->windowDefault)
    {
        SetButtonColors();
        m_buttonSimulate->SetBackgroundColour(pOsciloscope->settings.getColors()->windowFront);
        m_buttonSimulate->SetForegroundColour(pOsciloscope->settings.getColors()->windowBack);
    }
    if(event.GetClientData() == 0)
    { pOsciloscope->transferData(); }
    m_buttonPause->Enable();
    m_buttonPlay->Enable();
    m_buttonCapture->Enable();
    m_buttonSimulate->Disable();
    m_buttonClear->Enable();
}

void OsciloskopOsciloskop::m_buttonClearOnButtonClick(wxCommandEvent& event)
{
    pOsciloscope->window.horizontal.Mode = SIGNAL_MODE_CLEAR;
    SDL_AtomicSet(&pOsciloscope->signalMode, SIGNAL_MODE_CLEAR);
    SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_frameClear, 1);
    pOsciloscope->simOnOff(0);
    if(!pOsciloscope->settings.getColors()->windowDefault)
    {
        SetButtonColors();
        m_buttonClear->SetBackgroundColour(pOsciloscope->settings.getColors()->windowFront);
        m_buttonClear->SetForegroundColour(pOsciloscope->settings.getColors()->windowBack);
    }
    if(event.GetClientData() == 0)
    { pOsciloscope->transferData(); }
    m_buttonPause->Enable();
    m_buttonPlay->Enable();
    m_buttonCapture->Enable();
    m_buttonSimulate->Enable();
    m_buttonClear->Disable();
}

void OsciloskopOsciloskop::m_textCtrlTimeFrameSizeOnTextEnter(wxCommandEvent& event)
{
    int version = 0;
    int header  = 0;
    int data    = 0;
    int packet  = 0;
    uint frameSize = 0;
    frameSize = atoi(m_textCtrlTimeFrameSize->GetValue().ToAscii().data());
    if(version == 1)
    {
        sfSetSampleSize(getHw(), frameSize);
        sfSetTriggerPre(getHw(), pOsciloscope->window.trigger.Percent);
        pOsciloscope->window.horizontal.FrameSize = sfGetSampleSize(getHw());
        data = pOsciloscope->window.horizontal.FrameSize * 6;
    }
    else
    {
        SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_frameSize,  frameSize + SCOPEFUN_FRAME_HEADER);
        SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_frameCount, max<ularge>(1,pOsciloscope->m_captureBuffer.m_dataMax / ularge(frameSize + SCOPEFUN_FRAME_HEADER) ) );

        sfSetSampleSize(getHw(), frameSize);
        sfSetTriggerPre(getHw(), pOsciloscope->window.trigger.Percent);
        pOsciloscope->window.horizontal.FrameSize = sfGetSampleSize(getHw());
        data = pOsciloscope->window.horizontal.FrameSize * 4;
        SDL_AtomicSet(&pOsciloscope->m_captureBuffer.m_frameSize, frameSize + SCOPEFUN_FRAME_HEADER);
    }
    m_textCtrlTimeFrameSize->SetValue(wxString::FromAscii(pFormat->integerToString(sfGetSampleSize(getHw()))));
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_textCtrlTimeFFTSizeOnTextEnter(wxCommandEvent& event)
{
    iint fftsize = atoi(m_textCtrlTimeFFTSize->GetValue().ToAscii().data());
    fftsize = min(fftsize, NUM_FFT);
    pOsciloscope->window.horizontal.FFTSize = fftsize;
    m_textCtrlTimeFFTSize->SetValue(wxString::FromAscii(pFormat->integerToString(fftsize)));
}

void OsciloskopOsciloskop::m_comboBoxCh0CaptureOnCombobox(wxCommandEvent& event)
{
    if(captureTimeFromValue(pOsciloscope->window.horizontal.Capture) == t2c2ns)
    {
        // 500 Mhz help
        m_comboBoxCh1Capture->SetSelection(m_comboBoxCh0Capture->GetSelection());
        double oldTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
        //pOsciloscope->window.channel02.Capture = captureVoltFromEnum(m_comboBoxCh0Capture->GetSelection());
        //pOsciloscope->window.channel02.Scale = pFormat->stringToFloat(m_textCtrlCh0Scale->GetValue().ToAscii().data());
        //pOsciloscope->window.channel02.Display = pOsciloscope->window.channel02.Capture;
        //pOsciloscope->control.setYRangeScaleB(m_comboBoxCh0Capture->GetSelection(), pOsciloscope->window.channel02.Scale);
        m_comboBoxCh1CaptureOnCombobox(event);
        //
        float volt;
        uint  unit;
        _setYDisplay(volt, unit, (VoltageCapture)m_comboBoxCh1Capture->GetSelection());
        //
        double newTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
        RecalculateTriggerPosition(oldTriggerVoltagePerStep, newTriggerVoltagePerStep);
    }
    float time = pOsciloscope->window.horizontal.Capture;
    float captureOld = pOsciloscope->window.channel01.Capture;
    double oldTriggerVoltagePerSteps = pOsciloscope->getTriggerVoltagePerStep();
    pOsciloscope->window.channel01.Capture = captureVoltFromEnum(m_comboBoxCh0Capture->GetSelection());
    pOsciloscope->window.channel01.Scale   = pFormat->stringToFloat(m_textCtrlCh0Scale->GetValue().ToAscii().data());
    pOsciloscope->window.channel01.Display = pOsciloscope->window.channel01.Capture;
    uint capture0 = m_comboBoxCh0Capture->GetSelection();
    sfSetYRangeScaleA(getHw(), pOsciloscope->getAttr(capture0), pOsciloscope->getGain(0, capture0));
    // yposition fix
    float captureNew       = pOsciloscope->window.channel01.Capture;
    double slidePos        = m_sliderCh0Position->GetValue();
    double slidePosOffset  = -slidePos + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 0, captureNew);
    pOsciloscope->window.channel01.YPosition = -slidePos * pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, captureNew);
    m_textCtrlCh0Position->SetValue(pFormat->floatToString(pOsciloscope->window.channel01.YPosition));
    sfSetYPositionA(getHw(), slidePosOffset);
    float volt;
    uint  unit;
    _setYDisplay(volt, unit, (VoltageCapture)m_comboBoxCh0Capture->GetSelection());
    double newTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
    RecalculateTriggerPosition(oldTriggerVoltagePerSteps, newTriggerVoltagePerStep);
    // transfer
    pOsciloscope->transferData();
    pOsciloscope->window.measure.ClearCapture();
}

void OsciloskopOsciloskop::m_textCtrlCh0ScaleOnTextEnter(wxCommandEvent& event)
{
    pOsciloscope->window.channel01.Scale = pFormat->stringToFloat(m_textCtrlCh0Scale->GetValue().ToAscii().data());
    uint capture0 = m_comboBoxCh0Capture->GetSelection();
    sfSetYRangeScaleA(getHw(), pOsciloscope->getAttr(capture0), pOsciloscope->getGain(0, capture0));
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceCh0ACDCOnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.channel01.AcDc = m_choiceCh0ACDC->GetSelection();
    sfSetAnalogSwitchBit(getHw(), CHANNEL_A_ACDC, m_choiceCh0ACDC->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_checkBoxCh0InvertOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.channel01.Invert = m_checkBoxCh0Invert->GetValue();
}

void OsciloskopOsciloskop::m_checkBoxCh0GroundOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.channel01.Ground = m_checkBoxCh0Ground->GetValue();
    sfSetAnalogSwitchBit(getHw(), CHANNEL_A_GROUND, m_checkBoxCh0Ground->GetValue());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_checkBoxSignal1OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.channel01.OscOnOff = m_checkBoxSignal1->IsChecked() ? 1 : 0;
}

void OsciloskopOsciloskop::m_checkBoxFFT1OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.channel01.FFTOnOff = m_checkBoxFFT1->IsChecked() ? 1 : 0;
}

void OsciloskopOsciloskop::m_checkBoxAvg01OnCheckBox(wxCommandEvent& event)
{
    int avg = sfGetAverage(getHw());
    if(m_checkBoxAvg01->IsChecked()) { avg |=  512; }
    else                               { avg &= ~512; }
    sfSetAverage(getHw(), avg);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_textCtrlCh0PositionOnTextEnter(wxCommandEvent& event)
{
    if(captureTimeFromValue(pOsciloscope->window.horizontal.Capture) == t2c2ns)
    {
        // 500 Mhz help
        m_textCtrlCh1Position->SetValue(m_textCtrlCh0Position->GetValue());
        float time = pOsciloscope->window.horizontal.Capture;
        float capture = pOsciloscope->window.channel02.Capture;
        // voltage
        pOsciloscope->window.channel02.YPosition = pFormat->stringToDouble(m_textCtrlCh1Position->GetValue().ToAscii().data());
        // step
        double steps = double(pOsciloscope->window.channel02.YPosition) / pOsciloscope->settings.getHardware()->getAnalogStep(time, 1, capture);
        sfSetYPositionB(getHw(), steps + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 1, capture));
        m_sliderCh1Position->SetValue(-steps);
    }
    float time = pOsciloscope->window.horizontal.Capture;
    float capture = pOsciloscope->window.channel01.Capture;
    // voltage
    pOsciloscope->window.channel01.YPosition = pFormat->stringToDouble(m_textCtrlCh0Position->GetValue().ToAscii().data());
    // step
    double steps = double(pOsciloscope->window.channel01.YPosition) / pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, capture);
    sfSetYPositionA(getHw(), steps + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 0, capture));
    m_sliderCh0Position->SetValue(-steps);
    // transfer
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_spinBtnCh0YPosOnSpinDown(wxSpinEvent& event)
{
    if(captureTimeFromValue(pOsciloscope->window.horizontal.Capture) == t2c2ns)
    {
        // 500 Mhz help
        m_spinBtnCh1YPosOnSpinDown(event);
    }
    // position
    int ypos = sfGetYPositionA(getHw());
    sfSetYPositionA(getHw(), ypos + 1);
    pOsciloscope->transferData();
    // ypos, step and offset
    ypos = sfGetYPositionA(getHw());
    float  time    = pOsciloscope->window.horizontal.Capture;
    float  capture = pOsciloscope->window.channel01.Capture;
    double step    = pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, capture);
    int    offset  = pOsciloscope->settings.getHardware()->getAnalogOffset(time, 0, capture);
    // update ui
    m_sliderCh0Position->SetValue(-(ypos - offset));
    m_textCtrlCh0Position->SetValue(pFormat->doubleToString(step * double(ypos - offset)));
}

void OsciloskopOsciloskop::m_spinBtnCh0YPosOnSpinUp(wxSpinEvent& event)
{
    if(captureTimeFromValue(pOsciloscope->window.horizontal.Capture) == t2c2ns)
    {
        // 500 Mhz help
        m_spinBtnCh1YPosOnSpinUp(event);
    }
    // position
    int ypos = sfGetYPositionA(getHw());
    sfSetYPositionA(getHw(), ypos - 1);
    pOsciloscope->transferData();
    // ypos, step and offset
    ypos = sfGetYPositionA(getHw());
    float  time    = pOsciloscope->window.horizontal.Capture;
    float  capture = pOsciloscope->window.channel01.Capture;
    double step    = pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, capture);
    int    offset  = pOsciloscope->settings.getHardware()->getAnalogOffset(time, 0, capture);
    // update ui
    m_sliderCh0Position->SetValue(-(ypos - offset));
    m_textCtrlCh0Position->SetValue(pFormat->doubleToString(step * double(ypos - offset)));
}

void OsciloskopOsciloskop::m_sliderCh0PositionOnScroll(wxScrollEvent& event)
{
    if(captureTimeFromValue(pOsciloscope->window.horizontal.Capture) == t2c2ns)
    {
        // 500 Mhz help
        float time    = pOsciloscope->window.horizontal.Capture;
        float capture = pOsciloscope->window.channel01.Capture;
        // voltage
        pOsciloscope->window.channel02.YPosition = double(-m_sliderCh0Position->GetValue()) * pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, capture);
        // step
        double steps = double(pOsciloscope->window.channel02.YPosition) / pOsciloscope->settings.getHardware()->getAnalogStep(time, 1, capture);
        sfSetYPositionB(getHw(), steps + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 1, capture));
        m_sliderCh1Position->SetValue(-steps);
        m_textCtrlCh1Position->SetValue(pFormat->doubleToString(pOsciloscope->window.channel02.YPosition));
    }
    float time    = pOsciloscope->window.horizontal.Capture;
    float capture = pOsciloscope->window.channel01.Capture;
    // steps
    sfSetYPositionA(getHw(), -m_sliderCh0Position->GetValue() + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 0, capture));
    pOsciloscope->transferData();
    // voltage
    pOsciloscope->window.channel01.YPosition = double(-m_sliderCh0Position->GetValue()) * pOsciloscope->settings.getHardware()->getAnalogStep(time, 0, capture);
    m_textCtrlCh0Position->SetValue(pFormat->doubleToString(pOsciloscope->window.channel01.YPosition));
}

void OsciloskopOsciloskop::m_comboBoxCh1CaptureOnCombobox(wxCommandEvent& event)
{
    float captureOld = pOsciloscope->window.channel02.Capture;
    float time = pOsciloscope->window.horizontal.Capture;
    double oldTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
    pOsciloscope->window.channel02.Capture = captureVoltFromEnum(m_comboBoxCh1Capture->GetSelection());
    pOsciloscope->window.channel02.Scale   = pFormat->stringToFloat(m_textCtrlCh1Scale->GetValue().ToAscii().data());
    pOsciloscope->window.channel02.Display = pOsciloscope->window.channel02.Capture;
    uint capture1 = m_comboBoxCh1Capture->GetSelection();
    sfSetYRangeScaleB(getHw(), pOsciloscope->getAttr(capture1), pOsciloscope->getGain(1, capture1));
    //
    float volt;
    uint  unit;
    _setYDisplay(volt, unit, (VoltageCapture)m_comboBoxCh1Capture->GetSelection());
    // yposition fix
    float captureNew = pOsciloscope->window.channel02.Capture;
    double slidePos = m_sliderCh1Position->GetValue();
    double slidePosOffset = -slidePos + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 1, captureNew);
    pOsciloscope->window.channel02.YPosition = -slidePos * pOsciloscope->settings.getHardware()->getAnalogStep(time, 1, captureNew);
    m_textCtrlCh1Position->SetValue(pFormat->floatToString(pOsciloscope->window.channel02.YPosition));
    sfSetYPositionB(getHw(), slidePosOffset);
    //
    double newTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
    RecalculateTriggerPosition(oldTriggerVoltagePerStep, newTriggerVoltagePerStep);
    pOsciloscope->transferData();
    pOsciloscope->window.measure.ClearCapture();
}

void OsciloskopOsciloskop::m_textCtrlCh1ScaleOnTextEnter(wxCommandEvent& event)
{
    pOsciloscope->window.channel02.Scale = pFormat->stringToFloat(m_textCtrlCh1Scale->GetValue().ToAscii().data());
    uint capture1 = m_comboBoxCh1Capture->GetSelection();
    sfSetYRangeScaleB(getHw(), pOsciloscope->getAttr(capture1), pOsciloscope->getGain(1, capture1));
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceCh1ACDCOnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.channel02.AcDc = m_choiceCh1ACDC->GetSelection();
    sfSetAnalogSwitchBit(getHw(), CHANNEL_B_ACDC, m_choiceCh1ACDC->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_checkBoxCh1InvertOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.channel02.Invert = m_checkBoxCh1Invert->GetValue();
}

void OsciloskopOsciloskop::m_checkBoxCh1GroundOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.channel02.Ground = m_checkBoxCh1Ground->GetValue();
    sfSetAnalogSwitchBit(getHw(), CHANNEL_B_GROUND, m_checkBoxCh1Ground->GetValue());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_checkBoxSignal2OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.channel02.OscOnOff = m_checkBoxSignal2->IsChecked() ? 1 : 0;
}

void OsciloskopOsciloskop::m_checkBoxFFT2OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.channel02.FFTOnOff = m_checkBoxFFT2->IsChecked() ? 1 : 0;
}

void OsciloskopOsciloskop::m_checkBoxAvg02OnCheckBox(wxCommandEvent& event)
{
    int avg = sfGetAverage(getHw());
    if(m_checkBoxAvg02->IsChecked()) { avg |=  256; }
    else                               { avg &= ~256; }
    sfSetAverage(getHw(), avg);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_textCtrlCh1PositionOnTextEnter(wxCommandEvent& event)
{
    float time = pOsciloscope->window.horizontal.Capture;
    float capture = pOsciloscope->window.channel02.Capture;
    // voltage
    pOsciloscope->window.channel02.YPosition = pFormat->stringToDouble(m_textCtrlCh1Position->GetValue().ToAscii().data());
    // step
    double steps = double(pOsciloscope->window.channel02.YPosition) / pOsciloscope->settings.getHardware()->getAnalogStep(time, 1, capture);
    sfSetYPositionB(getHw(), steps + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 1, capture));
    m_sliderCh1Position->SetValue(-steps);
    // transfer
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_spinBtnCh1YPosOnSpinDown(wxSpinEvent& event)
{
    // position
    int ypos = sfGetYPositionB(getHw());
    sfSetYPositionB(getHw(), ypos + 1);
    pOsciloscope->transferData();
    // ypos, step and offset
    ypos = sfGetYPositionB(getHw());
    float  time    = pOsciloscope->window.horizontal.Capture;
    float  capture = pOsciloscope->window.channel02.Capture;
    double step    = pOsciloscope->settings.getHardware()->getAnalogStep(time, 1, capture);
    int    offset  = pOsciloscope->settings.getHardware()->getAnalogOffset(time, 1, capture);
    // update ui
    m_sliderCh1Position->SetValue(-(ypos - offset));
    m_textCtrlCh1Position->SetValue(pFormat->doubleToString(step * double(ypos - offset)));
}

void OsciloskopOsciloskop::m_spinBtnCh1YPosOnSpinUp(wxSpinEvent& event)
{
    // position
    int ypos = sfGetYPositionB(getHw());
    sfSetYPositionB(getHw(), ypos - 1);
    pOsciloscope->transferData();
    // ypos, step and offset
    ypos = sfGetYPositionB(getHw());
    float  time    = pOsciloscope->window.horizontal.Capture;
    float  capture = pOsciloscope->window.channel02.Capture;
    double step    = pOsciloscope->settings.getHardware()->getAnalogStep(time, 1, capture);
    int    offset  = pOsciloscope->settings.getHardware()->getAnalogOffset(time, 1, capture);
    // update ui
    m_sliderCh1Position->SetValue(-(ypos - offset));
    m_textCtrlCh1Position->SetValue(pFormat->doubleToString(step * double(ypos - offset)));
}

void OsciloskopOsciloskop::m_sliderCh1PositionOnScroll(wxScrollEvent& event)
{
    float time = pOsciloscope->window.horizontal.Capture;
    float capture = pOsciloscope->window.channel02.Capture;
    // steps
    sfSetYPositionB(getHw(), -m_sliderCh1Position->GetValue() + pOsciloscope->settings.getHardware()->getAnalogOffset(time, 1, capture));
    pOsciloscope->transferData();
    // voltage
    pOsciloscope->window.channel02.YPosition = double(-m_sliderCh1Position->GetValue()) * pOsciloscope->settings.getHardware()->getAnalogStep(time, 1, capture);
    m_textCtrlCh1Position->SetValue(pFormat->doubleToString(pOsciloscope->window.channel02.YPosition));
}

void OsciloskopOsciloskop::m_comboBoxFunctionTypeOnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.function.Type = m_comboBoxFunction->GetSelection();
}

void OsciloskopOsciloskop::m_checkBoxXYVoltageGraphOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.function.xyGraph = m_checkBoxXYVoltageGraph->IsChecked() ? 1 : 0;
}

void OsciloskopOsciloskop::m_checkBoxSignalFOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.function.OscOnOff = m_checkBoxSignalF->IsChecked() ? 1 : 0;
}

void OsciloskopOsciloskop::m_checkBoxFFTFOnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.function.FFTOnOff = m_checkBoxFFTF->IsChecked() ? 1 : 0;
}

void OsciloskopOsciloskop::m_choiceDOnOff815OnChoice(wxCommandEvent& event)
{
    int version = pOsciloscope->thread.getVersion();
    switch(m_choiceDOnOff815->GetSelection())
    {
        case 0:
            break;
        case 1:
            m_checkBox7->SetValue(false);
            m_checkBox8->SetValue(false);
            m_checkBox9->SetValue(false);
            m_checkBox10->SetValue(false);
            m_checkBox11->SetValue(false);
            m_checkBox12->SetValue(false);
          
            break;
        case 2:
            m_checkBox7->SetValue(true);
            m_checkBox8->SetValue(true);
            m_checkBox9->SetValue(true);
            m_checkBox10->SetValue(true);
            m_checkBox11->SetValue(true);
            m_checkBox12->SetValue(true);
            break;
    };
    pOsciloscope->window.digital.digital[6] = m_checkBox7->GetValue();
    pOsciloscope->window.digital.digital[7] = m_checkBox8->GetValue();
    pOsciloscope->window.digital.digital[8]  = m_checkBox9->GetValue();
    pOsciloscope->window.digital.digital[9]  = m_checkBox10->GetValue();
    pOsciloscope->window.digital.digital[10] = m_checkBox11->GetValue();
    pOsciloscope->window.digital.digital[11] = m_checkBox12->GetValue();
}

void OsciloskopOsciloskop::m_choiceDOnOff70OnChoice(wxCommandEvent& event)
{
    int version = pOsciloscope->thread.getVersion();
    switch(m_choiceDOnOff70->GetSelection())
    {
        case 0:
            break;
        case 1:
            m_checkBox1->SetValue(false);
            m_checkBox2->SetValue(false);
            m_checkBox3->SetValue(false);
            m_checkBox4->SetValue(false);
            m_checkBox5->SetValue(false);
            m_checkBox6->SetValue(false);
            break;
        case 2:
            m_checkBox1->SetValue(true);
            m_checkBox2->SetValue(true);
            m_checkBox3->SetValue(true);
            m_checkBox4->SetValue(true);
            m_checkBox5->SetValue(true);
            m_checkBox6->SetValue(true);
            break;
    };
    pOsciloscope->window.digital.digital[0] = m_checkBox1->GetValue();
    pOsciloscope->window.digital.digital[1] = m_checkBox2->GetValue();
    pOsciloscope->window.digital.digital[2] = m_checkBox3->GetValue();
    pOsciloscope->window.digital.digital[3] = m_checkBox4->GetValue();
    pOsciloscope->window.digital.digital[4] = m_checkBox5->GetValue();
    pOsciloscope->window.digital.digital[5] = m_checkBox6->GetValue();
}

void OsciloskopOsciloskop::m_checkBox12OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[11] = m_checkBox12->GetValue();
}

void OsciloskopOsciloskop::m_checkBox10OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[9] = m_checkBox10->GetValue();
}

void OsciloskopOsciloskop::m_checkBox8OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[7] = m_checkBox8->GetValue();
}

void OsciloskopOsciloskop::m_checkBox11OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[10] = m_checkBox11->GetValue();
}

void OsciloskopOsciloskop::m_checkBox9OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[8] = m_checkBox9->GetValue();
}

void OsciloskopOsciloskop::m_checkBox7OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[6] = m_checkBox7->GetValue();
}

void OsciloskopOsciloskop::m_checkBox6OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[5] = m_checkBox6->GetValue();
}

void OsciloskopOsciloskop::m_checkBox4OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[3] = m_checkBox4->GetValue();
}

void OsciloskopOsciloskop::m_checkBox2OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[1] = m_checkBox2->GetValue();
}

void OsciloskopOsciloskop::m_checkBox5OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[4] = m_checkBox5->GetValue();
}

void OsciloskopOsciloskop::m_checkBox3OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[2] = m_checkBox3->GetValue();
}

void OsciloskopOsciloskop::m_checkBox1OnCheckBox(wxCommandEvent& event)
{
    pOsciloscope->window.digital.digital[0] = m_checkBox1->GetValue();
}

void OsciloskopOsciloskop::m_choiceDS815OnChoice(wxCommandEvent& event)
{
    int version = pOsciloscope->thread.getVersion();
    switch(m_choiceDS815->GetSelection())
    {
        case 0:
            break;
        case 1:
            m_choiceBit6->SetSelection(0);
            m_choiceBit7->SetSelection(0);
            m_choiceBit8->SetSelection(0);
            m_choiceBit9->SetSelection(0);
            m_choiceBit10->SetSelection(0);
            m_choiceBit11->SetSelection(0);
            break;
        case 2:
            m_choiceBit6->SetSelection(1);
            m_choiceBit7->SetSelection(1);
            m_choiceBit8->SetSelection(1);
            m_choiceBit9->SetSelection(1);
            m_choiceBit10->SetSelection(1);
            m_choiceBit11->SetSelection(1);
            break;
    };
    sfSetDigitalOutputBit(getHw(), 6, m_choiceBit6->GetSelection());
    sfSetDigitalOutputBit(getHw(), 7, m_choiceBit7->GetSelection());
    sfSetDigitalOutputBit(getHw(), 8,  m_choiceBit8->GetSelection());
    sfSetDigitalOutputBit(getHw(), 9,  m_choiceBit9->GetSelection());
    sfSetDigitalOutputBit(getHw(), 10, m_choiceBit10->GetSelection());
    sfSetDigitalOutputBit(getHw(), 11, m_choiceBit11->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceInputOutputOnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digitalSetup.inputOutput15 = m_choiceInputOutput->GetSelection();
    sfSetDigitalInputOutput(getHw(), pOsciloscope->window.digitalSetup.inputOutput15, pOsciloscope->window.digitalSetup.inputOutput7);
    pOsciloscope->transferData();
    pOsciloscope->window.hardwareGenerator.uploadDigital();
    int version = pOsciloscope->thread.getVersion();
    if(m_choiceInputOutput->GetSelection() == 1)
    {
        m_choiceBit6->Disable();
        m_choiceBit7->Disable();
        m_choiceBit8->Disable();
        m_choiceBit9->Disable();
        m_choiceBit10->Disable();
        m_choiceBit11->Disable();
    }
    else
    {
        m_choiceBit6->Enable();
        m_choiceBit7->Enable();
        m_choiceBit8->Enable();
        m_choiceBit9->Enable();
        m_choiceBit10->Enable();
        m_choiceBit11->Enable();
    }
}

void OsciloskopOsciloskop::m_choiceBit11OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[11] = m_choiceBit11->GetSelection();
    sfSetDigitalOutputBit(getHw(), 11, m_choiceBit11->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit9OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[9] = m_choiceBit9->GetSelection();
    sfSetDigitalOutputBit(getHw(), 9, m_choiceBit9->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit7OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[7] = m_choiceBit7->GetSelection();
    sfSetDigitalOutputBit(getHw(), 7, m_choiceBit7->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit10OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[10] = m_choiceBit10->GetSelection();
    sfSetDigitalOutputBit(getHw(), 10, m_choiceBit10->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit8OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[8] = m_choiceBit8->GetSelection();
    sfSetDigitalOutputBit(getHw(), 8, m_choiceBit8->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit6OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[6] = m_choiceBit6->GetSelection();
    sfSetDigitalOutputBit(getHw(), 6, m_choiceBit6->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceInputOutput1OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digitalSetup.inputOutput7 = m_choiceInputOutput1->GetSelection();
    sfSetDigitalInputOutput(getHw(), pOsciloscope->window.digitalSetup.inputOutput15, pOsciloscope->window.digitalSetup.inputOutput7);
    pOsciloscope->transferData();
    pOsciloscope->window.hardwareGenerator.uploadDigital();
    int version = pOsciloscope->thread.getVersion();
    if(m_choiceInputOutput1->GetSelection() == 1)
    {
        m_choiceBit0->Disable();
        m_choiceBit1->Disable();
        m_choiceBit2->Disable();
        m_choiceBit3->Disable();
        m_choiceBit4->Disable();
        m_choiceBit5->Disable();
    }
    else
    {
        m_choiceBit0->Enable();
        m_choiceBit1->Enable();
        m_choiceBit2->Enable();
        m_choiceBit3->Enable();
        m_choiceBit4->Enable();
        m_choiceBit5->Enable();
    }
}

void OsciloskopOsciloskop::m_choiceDS70OnChoice(wxCommandEvent& event)
{
    int version = pOsciloscope->thread.getVersion();
    switch(m_choiceDS70->GetSelection())
    {
        case 0:
            break;
        case 1:
            m_choiceBit0->SetSelection(0);
            m_choiceBit1->SetSelection(0);
            m_choiceBit2->SetSelection(0);
            m_choiceBit3->SetSelection(0);
            m_choiceBit4->SetSelection(0);
            m_choiceBit5->SetSelection(0);
            break;
        case 2:
            m_choiceBit0->SetSelection(1);
            m_choiceBit1->SetSelection(1);
            m_choiceBit2->SetSelection(1);
            m_choiceBit3->SetSelection(1);
            m_choiceBit4->SetSelection(1);
            m_choiceBit5->SetSelection(1);
            break;
    };
    sfSetDigitalOutputBit(getHw(), 0, m_choiceBit0->GetSelection());
    sfSetDigitalOutputBit(getHw(), 1, m_choiceBit1->GetSelection());
    sfSetDigitalOutputBit(getHw(), 2, m_choiceBit2->GetSelection());
    sfSetDigitalOutputBit(getHw(), 3, m_choiceBit3->GetSelection());
    sfSetDigitalOutputBit(getHw(), 4, m_choiceBit4->GetSelection());
    sfSetDigitalOutputBit(getHw(), 5, m_choiceBit5->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit5OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[5] = m_choiceBit5->GetSelection();
    sfSetDigitalOutputBit(getHw(), 5, m_choiceBit5->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit3OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[3] = m_choiceBit3->GetSelection();
    sfSetDigitalOutputBit(getHw(), 3, m_choiceBit3->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit1OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[1] = m_choiceBit1->GetSelection();
    sfSetDigitalOutputBit(getHw(), 1, m_choiceBit1->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit4OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[4] = m_choiceBit4->GetSelection();
    sfSetDigitalOutputBit(getHw(), 4, m_choiceBit4->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit2OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[2] = m_choiceBit2->GetSelection();
    sfSetDigitalOutputBit(getHw(), 2, m_choiceBit2->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit0OnChoice(wxCommandEvent& event)
{
    pOsciloscope->window.digital.output[0] = m_choiceBit0->GetSelection();
    sfSetDigitalOutputBit(getHw(), 0, m_choiceBit0->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_filePicker1OnFileChanged(wxFileDirPickerEvent& event)
{
   pOsciloscope->window.hardwareGenerator.loadCustomDigital(m_filePicker1->GetFileName().GetFullPath().ToAscii().data());
}

void OsciloskopOsciloskop::m_buttonCustomFileOnButtonClick(wxCommandEvent& event)
{
   pOsciloscope->window.hardwareGenerator.uploadDigital();
   pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_textCtrlDigitalVoltageOnTextEnter(wxCommandEvent& event)
{
    double kDigital = pOsciloscope->settings.getHardware()->digitalVoltageCoeficient;
    pOsciloscope->window.digitalSetup.voltage = pFormat->stringToDouble(m_textCtrlDigitalVoltage->GetValue().ToAscii().data());
    pOsciloscope->window.digitalSetup.voltage = clamp(pOsciloscope->window.digitalSetup.voltage, 1.238, 3.305);
    sfSetDigitalVoltage(getHw(), pOsciloscope->window.digitalSetup.voltage, kDigital);
    pOsciloscope->transferData();
    const char* voltageStr = pFormat->doubleToString(pOsciloscope->window.digitalSetup.voltage);
    m_textCtrlDigitalVoltage->SetValue(voltageStr);
    DigitalMiddlePinMaxVoltText(pOsciloscope->window.digitalSetup.voltage);
}

void OsciloskopOsciloskop::m_spinBtnDigVoltageOnSpinDown(wxSpinEvent& event)
{
    double kDigital = pOsciloscope->settings.getHardware()->digitalVoltageCoeficient;
    double Vstep = 8.104/1000.0;
    double value = pFormat->stringToDouble(m_textCtrlDigitalVoltage->GetValue()) - Vstep;
    value = clamp(value, 1.238, 3.305);
    m_textCtrlDigitalVoltage->SetValue(pFormat->doubleToString(value));
    pOsciloscope->window.digitalSetup.voltage = value;
    sfSetDigitalVoltage(getHw(), value, kDigital);
    pOsciloscope->transferData();
    DigitalMiddlePinMaxVoltText(value);
}

void OsciloskopOsciloskop::m_spinBtnDigVoltageOnSpinUp(wxSpinEvent& event)
{
    double kDigital = pOsciloscope->settings.getHardware()->digitalVoltageCoeficient;
    double Vstep = 8.104 / 1000.0;
    double value = pFormat->stringToDouble(m_textCtrlDigitalVoltage->GetValue()) + Vstep;
    value = clamp(value, 1.238, 3.305);
    m_textCtrlDigitalVoltage->SetValue(pFormat->doubleToString(value));
    pOsciloscope->window.digitalSetup.voltage = value;
    sfSetDigitalVoltage(getHw(), value, kDigital);
    pOsciloscope->transferData();
    DigitalMiddlePinMaxVoltText(value);
}

void OsciloskopOsciloskop::m_textCtrlFreqDividerOnTextEnter(wxCommandEvent& event)
{
    uint  divider = pFormat->stringToInteger(m_textCtrlFreqDivider->GetValue().ToAscii().data());
    pOsciloscope->window.digitalSetup.divider = divider;
    double freq = 250000000.0 / (double(divider) + 1.0);
    m_staticTextMhz->SetLabel(wxString(pFormat->doubleToString(freq)).append(wxT(" Hz")));
    sfSetDigitalClockDivide(getHw(), divider);
    pOsciloscope->transferData();
}


void OsciloskopOsciloskop::m_comboBoxTriggerOnCombobox(wxCommandEvent& event)
{
    pOsciloscope->window.trigger.Mode = m_comboBoxTrigger->GetSelection();
    sfSetTriggerMode(getHw(), m_comboBoxTrigger->GetSelection());
    if(m_comboBoxTrigger->GetSelection() == 3)
    {
        pOsciloscope->window.trigger.Percent  = 0.f;
        sfSetTriggerPre(getHw(), pOsciloscope->window.trigger.Percent);
        m_textCtrlTriggerPre->SetValue(wxString::FromAscii(pFormat->floatToString(pOsciloscope->window.trigger.Percent)));
        m_sliderTriggerPre->SetValue(pOsciloscope->window.trigger.Percent);
        m_textCtrlTriggerPre->Disable();
        m_sliderTriggerPre->Disable();
    }
    else
    {
        m_textCtrlTriggerPre->Enable();
        m_sliderTriggerPre->Enable();
    }
    pOsciloscope->transferData();

    if (pOsciloscope->window.trigger.Mode == 2)
       m_buttonReArm->Enable();
    else
       m_buttonReArm->Disable();
}

void OsciloskopOsciloskop::m_comboBoxTriggerSourceOnCombobox(wxCommandEvent& event)
{
    double oldTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
    pOsciloscope->window.trigger.Source = m_comboBoxTriggerSource->GetSelection();
    sfSetTriggerSource(getHw(), m_comboBoxTriggerSource->GetSelection());
    double newTriggerVoltagePerStep = pOsciloscope->getTriggerVoltagePerStep();
    RecalculateTriggerPosition(oldTriggerVoltagePerStep, newTriggerVoltagePerStep);
    pOsciloscope->transferData();

    if (pOsciloscope->window.trigger.Source == 4)
       m_comboBoxDigitalStageStart->Enable();
    else
       m_comboBoxDigitalStageStart->Disable();
}

void OsciloskopOsciloskop::m_comboBoxTriggerSlopeOnCombobox(wxCommandEvent& event)
{
    pOsciloscope->window.trigger.Slope = m_comboBoxTriggerSlope->GetSelection();
    sfSetTriggerSlope(getHw(), m_comboBoxTriggerSlope->GetSelection());
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_buttonReArmOnButtonClick(wxCommandEvent& event)
{
    sfSetTriggerReArm(getHw(), true);
    pOsciloscope->transferData();
    sfSetTriggerReArm(getHw(), false);
}

void OsciloskopOsciloskop::m_textCtrlTriggerLevelOnTextEnter(wxCommandEvent& event)
{
    double  triggerLevel = pFormat->stringToDouble(m_textCtrlTriggerLevel->GetValue().ToAscii().data());
    int    numberOfSteps = int(triggerLevel / pOsciloscope->getTriggerVoltagePerStep());
    pOsciloscope->window.trigger.Level = numberOfSteps;
    sfSetTriggerLevel(getHw(), numberOfSteps);
    pOsciloscope->transferData();
    m_sliderTriggerLevel->SetValue(numberOfSteps);
}

void OsciloskopOsciloskop::m_spinBtnTrigLevelOnSpinDown(wxSpinEvent& event)
{
    double  triggerLevel = pFormat->stringToDouble(m_textCtrlTriggerLevel->GetValue().ToAscii().data());
    triggerLevel = triggerLevel - pOsciloscope->getTriggerVoltagePerStep();
    m_textCtrlTriggerLevel->SetValue(pFormat->doubleToString(triggerLevel));
    int    numberOfSteps = int(triggerLevel / pOsciloscope->getTriggerVoltagePerStep());
    pOsciloscope->window.trigger.Level = numberOfSteps;
    sfSetTriggerLevel(getHw(), numberOfSteps);
    pOsciloscope->transferData();
    m_sliderTriggerLevel->SetValue(numberOfSteps);
}

void OsciloskopOsciloskop::m_spinBtnTrigLevelOnSpinUp(wxSpinEvent& event)
{
    double  triggerLevel = pFormat->stringToDouble(m_textCtrlTriggerLevel->GetValue().ToAscii().data());
    triggerLevel = triggerLevel + pOsciloscope->getTriggerVoltagePerStep();
    m_textCtrlTriggerLevel->SetValue(pFormat->doubleToString(triggerLevel));
    int    numberOfSteps = int(triggerLevel / pOsciloscope->getTriggerVoltagePerStep());
    pOsciloscope->window.trigger.Level = numberOfSteps;
    sfSetTriggerLevel(getHw(), numberOfSteps);
    pOsciloscope->transferData();
    m_sliderTriggerLevel->SetValue(numberOfSteps);
}

void OsciloskopOsciloskop::m_sliderTriggerLevelOnScroll(wxScrollEvent& event)
{
    pOsciloscope->window.trigger.Level = m_sliderTriggerLevel->GetValue();
    sfSetTriggerLevel(getHw(), m_sliderTriggerLevel->GetValue());
    pOsciloscope->transferData();
    double triggerLevel = pOsciloscope->getTriggerVoltagePerStep() * double(pOsciloscope->window.trigger.Level);
    m_textCtrlTriggerLevel->SetValue(wxString::FromAscii(pFormat->doubleToString(triggerLevel)));
}

void OsciloskopOsciloskop::m_textCtrlTriggerHisteresisOnTextEnter(wxCommandEvent& event)
{
    double  hisLevel = pFormat->stringToDouble(m_textCtrlTriggerHisteresis->GetValue().ToAscii().data());
    int    numberOfSteps = int(hisLevel / pOsciloscope->getTriggerVoltagePerStep());
    pOsciloscope->window.trigger.His = numberOfSteps;
    sfSetTriggerHis(getHw(), numberOfSteps);
    pOsciloscope->transferData();
    //
    m_sliderTriggerHisteresis->SetValue(numberOfSteps);
}

void OsciloskopOsciloskop::m_spinBtnTrigHisOnSpinDown(wxSpinEvent& event)
{
    double  hisLevel = pFormat->stringToDouble(m_textCtrlTriggerHisteresis->GetValue().ToAscii().data());
    hisLevel = hisLevel - pOsciloscope->getTriggerVoltagePerStep();
    m_textCtrlTriggerHisteresis->SetValue(pFormat->doubleToString(hisLevel));
    int    numberOfSteps = int(hisLevel / pOsciloscope->getTriggerVoltagePerStep());
    pOsciloscope->window.trigger.His = numberOfSteps;
    sfSetTriggerHis(getHw(), numberOfSteps);
    pOsciloscope->transferData();
    //
    m_sliderTriggerHisteresis->SetValue(numberOfSteps);
}

void OsciloskopOsciloskop::m_spinBtnTrigHisOnSpinUp(wxSpinEvent& event)
{
    double  hisLevel = pFormat->stringToDouble(m_textCtrlTriggerHisteresis->GetValue().ToAscii().data());
    hisLevel = hisLevel + pOsciloscope->getTriggerVoltagePerStep();
    m_textCtrlTriggerHisteresis->SetValue(pFormat->doubleToString(hisLevel));
    int    numberOfSteps = int(hisLevel / pOsciloscope->getTriggerVoltagePerStep());
    pOsciloscope->window.trigger.His = numberOfSteps;
    sfSetTriggerHis(getHw(), numberOfSteps);
    pOsciloscope->transferData();
    //
    m_sliderTriggerHisteresis->SetValue(numberOfSteps);
}

void OsciloskopOsciloskop::m_sliderTriggerHisteresisOnScroll(wxScrollEvent& event)
{
    pOsciloscope->window.trigger.His = m_sliderTriggerHisteresis->GetValue();
    sfSetTriggerHis(getHw(), m_sliderTriggerHisteresis->GetValue());
    pOsciloscope->transferData();
    double hisLevel = pOsciloscope->getTriggerVoltagePerStep() * double(pOsciloscope->window.trigger.His);
    m_textCtrlTriggerHisteresis->SetValue(wxString::FromAscii(pFormat->doubleToString(hisLevel)));
}

void OsciloskopOsciloskop::m_textCtrlTriggerPreOnTextEnter(wxCommandEvent& event)
{
    double preTrigger = max(pFormat->stringToFloat(m_textCtrlTriggerPre->GetValue().ToAscii().data()), 0.f);
    preTrigger = min(preTrigger, 99.0);
    pOsciloscope->window.trigger.Percent = preTrigger;
    sfSetTriggerPre(getHw(), preTrigger);
    pOsciloscope->transferData();
    pOsciloscope->window.measure.data.pickX0.updateUI = true;
    pOsciloscope->window.measure.data.pickX1.updateUI = true;
    m_sliderTriggerPre->SetValue(pOsciloscope->window.trigger.Percent);
    m_textCtrlTriggerPre->SetValue(wxString::FromDouble(preTrigger));
}

void OsciloskopOsciloskop::m_spinBtnTrigPreOnSpinDown(wxSpinEvent& event)
{
    pOsciloscope->window.trigger.Percent = max(pFormat->stringToFloat(m_textCtrlTriggerPre->GetValue().ToAscii().data()) - 1.0f, 0.f);
    pOsciloscope->window.trigger.Percent = min(pOsciloscope->window.trigger.Percent, 99.0);
    sfSetTriggerPre(getHw(), pFormat->stringToFloat(m_textCtrlTriggerPre->GetValue().ToAscii().data()));
    pOsciloscope->transferData();
    m_sliderTriggerPre->SetValue(pOsciloscope->window.trigger.Percent);
    m_textCtrlTriggerPre->SetValue(pFormat->floatToString(pOsciloscope->window.trigger.Percent));
}

void OsciloskopOsciloskop::m_spinBtnTrigPreOnSpinUp(wxSpinEvent& event)
{
    pOsciloscope->window.trigger.Percent = max(pFormat->stringToFloat(m_textCtrlTriggerPre->GetValue().ToAscii().data()) + 1.0f, 0.f);
    pOsciloscope->window.trigger.Percent = min(pOsciloscope->window.trigger.Percent, 99.0);
    sfSetTriggerPre(getHw(), pFormat->stringToFloat(m_textCtrlTriggerPre->GetValue().ToAscii().data()));
    pOsciloscope->transferData();
    m_sliderTriggerPre->SetValue(pOsciloscope->window.trigger.Percent);
    m_textCtrlTriggerPre->SetValue(pFormat->floatToString(pOsciloscope->window.trigger.Percent));
}

void OsciloskopOsciloskop::m_sliderTriggerPreOnScroll(wxScrollEvent& event)
{
    pOsciloscope->window.trigger.Percent = max<int>(m_sliderTriggerPre->GetValue(), 0);
    sfSetTriggerPre(getHw(), m_sliderTriggerPre->GetValue());
    pOsciloscope->transferData();
    pOsciloscope->window.measure.data.pickX0.updateUI = true;
    pOsciloscope->window.measure.data.pickX1.updateUI = true;
    m_textCtrlTriggerPre->SetValue(wxString::FromAscii(pFormat->floatToString(pOsciloscope->window.trigger.Percent)));
}

void OsciloskopOsciloskop::m_textCtrlTriggerHoldoffOnTextEnter(wxCommandEvent& event)
{
    uint newHoldOff = max<int>(0, pFormat->stringToInteger(m_textCtrlTriggerHoldoff->GetValue().ToAscii().data()));
    sfSetHoldoff(getHw(), newHoldOff);
    newHoldOff = sfGetHoldoff(getHw());
    pOsciloscope->window.trigger.Holdoff = newHoldOff;
    pOsciloscope->transferData();
    m_sliderTriggerHoldoff->SetValue(newHoldOff);
    m_textCtrlTriggerHoldoff->SetValue(wxString::FromAscii(pFormat->integerToString(newHoldOff)));
}

void OsciloskopOsciloskop::m_spinBtnTrigHoldoffOnSpinDown(wxSpinEvent& event)
{
    uint newHoldOff = max<int>(0, sfGetHoldoff(getHw()) - 1);
    sfSetHoldoff(getHw(), newHoldOff);
    newHoldOff = sfGetHoldoff(getHw());
    pOsciloscope->window.trigger.Holdoff = newHoldOff;
    pOsciloscope->transferData();
    m_sliderTriggerHoldoff->SetValue(newHoldOff);
    m_textCtrlTriggerHoldoff->SetValue(pFormat->integerToString(newHoldOff));
}

void OsciloskopOsciloskop::m_spinBtnTrigHoldoffOnSpinUp(wxSpinEvent& event)
{
    uint newHoldOff = max<int>(0, sfGetHoldoff(getHw()) + 1);
    sfSetHoldoff(getHw(), newHoldOff);
    newHoldOff = sfGetHoldoff(getHw());
    pOsciloscope->window.trigger.Holdoff = newHoldOff;
    pOsciloscope->transferData();
    m_sliderTriggerHoldoff->SetValue(newHoldOff);
    m_textCtrlTriggerHoldoff->SetValue(pFormat->integerToString(newHoldOff));
}

void OsciloskopOsciloskop::m_sliderTriggerHoldoffOnScroll(wxScrollEvent& event)
{
    uint newHoldOff = max(0, m_sliderTriggerHoldoff->GetValue());
    sfSetHoldoff(getHw(), newHoldOff);
    newHoldOff = sfGetHoldoff(getHw());
    pOsciloscope->window.trigger.Holdoff = newHoldOff;
    pOsciloscope->transferData();
    m_sliderTriggerHoldoff->SetValue(newHoldOff);
    m_textCtrlTriggerHoldoff->SetValue(wxString::FromAscii(pFormat->integerToString(newHoldOff)));
}

void OsciloskopOsciloskop::m_comboBoxDigitalStageOnCombobox(wxCommandEvent& event)
{
    int stage = m_comboBoxDigitalStage->GetSelection();
    pOsciloscope->window.trigger.stage = stage;
    ushort delay = pOsciloscope->window.trigger.delay[stage];
    m_textCtrDigitallDelay->SetValue(wxString::FromAscii(pFormat->integerToString(delay)));
    m_comboBoxBit0->SetSelection(pOsciloscope->window.trigger.pattern[stage][0]);
    m_comboBoxBit1->SetSelection(pOsciloscope->window.trigger.pattern[stage][1]);
    m_comboBoxBit2->SetSelection(pOsciloscope->window.trigger.pattern[stage][2]);
    m_comboBoxBit3->SetSelection(pOsciloscope->window.trigger.pattern[stage][3]);
    m_comboBoxBit4->SetSelection(pOsciloscope->window.trigger.pattern[stage][4]);
    m_comboBoxBit5->SetSelection(pOsciloscope->window.trigger.pattern[stage][5]);
    m_comboBoxBit6->SetSelection(pOsciloscope->window.trigger.pattern[stage][6]);
    m_comboBoxBit7->SetSelection(pOsciloscope->window.trigger.pattern[stage][7]);
    m_comboBoxBit8->SetSelection(pOsciloscope->window.trigger.pattern[stage][8]);
    m_comboBoxBit9->SetSelection(pOsciloscope->window.trigger.pattern[stage][9]);
    m_comboBoxBit10->SetSelection(pOsciloscope->window.trigger.pattern[stage][10]);
    m_comboBoxBit11->SetSelection(pOsciloscope->window.trigger.pattern[stage][11]);
    if(!pOsciloscope->window.trigger.mask[stage][0])
    {
        m_comboBoxBit0->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][1])
    {
        m_comboBoxBit1->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][2])
    {
        m_comboBoxBit2->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][3])
    {
        m_comboBoxBit3->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][4])
    {
        m_comboBoxBit4->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][5])
    {
        m_comboBoxBit5->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][6])
    {
        m_comboBoxBit6->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][7])
    {
        m_comboBoxBit7->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][8])
    {
        m_comboBoxBit8->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][9])
    {
        m_comboBoxBit9->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][10])
    {
        m_comboBoxBit10->SetSelection(4);
    }
    if(!pOsciloscope->window.trigger.mask[stage][11])
    {
        m_comboBoxBit11->SetSelection(4);
    }
}

void OsciloskopOsciloskop::m_textCtrDigitallDelayOnTextEnter(wxCommandEvent& event)
{
    int stage = pOsciloscope->window.trigger.stage;
    ushort delay = clamp((uint)pFormat->stringToInteger(m_textCtrDigitallDelay->GetValue().ToAscii().data()), 0U, 0xffffU);
    m_textCtrDigitallDelay->SetValue(wxString::FromAscii(pFormat->integerToString(delay)));
    pOsciloscope->window.trigger.delay[stage] = delay;
    sfSetDigitalDelay(getHw(), (DigitalStage)stage, delay);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_comboBoxDigitalStageStartOnCombobox(wxCommandEvent& event)
{
    pOsciloscope->window.trigger.stageStart = m_comboBoxDigitalStageStart->GetSelection();
    sfSetDigitalStart(getHw(), pOsciloscope->window.trigger.stageStart);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_comboBoxDigitalModeOnCombobox(wxCommandEvent& event)
{
    pOsciloscope->window.trigger.stageMode = m_comboBoxDigitalMode->GetSelection();
    sfSetDigitalMode(getHw(), pOsciloscope->window.trigger.stageMode);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_comboBoxDigitalSerialChannelOnCombobox(wxCommandEvent& event)
{
    pOsciloscope->window.trigger.stageChannel = m_comboBoxDigitalSerialChannel->GetSelection();
    sfSetDigitalChannel(getHw(), pOsciloscope->window.trigger.stageChannel);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit158OnChoice(wxCommandEvent& event)
{
    switch(m_choiceBit158->GetSelection())
    {
        case 0:
            break;
        case 1:
            m_comboBoxBit11->SetSelection(0);
            m_comboBoxBit10->SetSelection(0);
            m_comboBoxBit9->SetSelection(0);
            m_comboBoxBit8->SetSelection(0);
            m_comboBoxBit7->SetSelection(0);
            m_comboBoxBit6->SetSelection(0);
            break;
        case 2:
            m_comboBoxBit11->SetSelection(1);
            m_comboBoxBit10->SetSelection(1);
            m_comboBoxBit9->SetSelection(1);
            m_comboBoxBit8->SetSelection(1);
            m_comboBoxBit7->SetSelection(1);
            m_comboBoxBit6->SetSelection(1);
            break;
        case 3:
            m_comboBoxBit11->SetSelection(4);
            m_comboBoxBit10->SetSelection(4);
            m_comboBoxBit9->SetSelection(4);
            m_comboBoxBit8->SetSelection(4);
            m_comboBoxBit6->SetSelection(4);
            m_comboBoxBit7->SetSelection(4);
            break;
    };
    setPatternNoTr(11, m_comboBoxBit11);
    setPatternNoTr(10, m_comboBoxBit10);
    setPatternNoTr(9, m_comboBoxBit9);
    setPatternNoTr(8, m_comboBoxBit8);
    setPatternNoTr(6, m_comboBoxBit6);
    setPatternNoTr(7, m_comboBoxBit7);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_choiceBit70OnChoice(wxCommandEvent& event)
{
    switch(m_choiceBit70->GetSelection())
    {
        case 0:
            break;
        case 1:
            m_comboBoxBit5->SetSelection(0);
            m_comboBoxBit4->SetSelection(0);
            m_comboBoxBit3->SetSelection(0);
            m_comboBoxBit2->SetSelection(0);
            m_comboBoxBit1->SetSelection(0);
            m_comboBoxBit0->SetSelection(0);
            break;
        case 2:       
            m_comboBoxBit5->SetSelection(1);
            m_comboBoxBit4->SetSelection(1);
            m_comboBoxBit3->SetSelection(1);
            m_comboBoxBit2->SetSelection(1);
            m_comboBoxBit1->SetSelection(1);
            m_comboBoxBit0->SetSelection(1);
            break;
        case 3:   
            m_comboBoxBit5->SetSelection(4);
            m_comboBoxBit4->SetSelection(4);
            m_comboBoxBit3->SetSelection(4);
            m_comboBoxBit2->SetSelection(4);
            m_comboBoxBit1->SetSelection(4);
            m_comboBoxBit0->SetSelection(4);
            break;
    };  
    setPatternNoTr(5, m_comboBoxBit5);
    setPatternNoTr(4, m_comboBoxBit4);
    setPatternNoTr(3, m_comboBoxBit3);
    setPatternNoTr(2, m_comboBoxBit2);
    setPatternNoTr(1, m_comboBoxBit1);
    setPatternNoTr(0, m_comboBoxBit0);
    pOsciloscope->transferData();
}

void OsciloskopOsciloskop::m_comboBoxBit11OnCombobox(wxCommandEvent& event)
{
    setPattern(11, m_comboBoxBit11);
}

void OsciloskopOsciloskop::m_comboBoxBit9OnCombobox(wxCommandEvent& event)
{
    setPattern(9, m_comboBoxBit9);
}

void OsciloskopOsciloskop::m_comboBoxBit6OnCombobox(wxCommandEvent& event)
{
    setPattern(6, m_comboBoxBit6);
}

void OsciloskopOsciloskop::m_comboBoxBit10OnCombobox(wxCommandEvent& event)
{
    setPattern(10, m_comboBoxBit10);
}

void OsciloskopOsciloskop::m_comboBoxBit8OnCombobox(wxCommandEvent& event)
{
    setPattern(8, m_comboBoxBit8);
}

void OsciloskopOsciloskop::m_comboBoxBit7OnCombobox(wxCommandEvent& event)
{
    setPattern(7, m_comboBoxBit7);
}

void OsciloskopOsciloskop::m_comboBoxBit5OnCombobox(wxCommandEvent& event)
{
    setPattern(5, m_comboBoxBit5);
}

void OsciloskopOsciloskop::m_comboBoxBit3OnCombobox(wxCommandEvent& event)
{
    setPattern(3, m_comboBoxBit3);
}

void OsciloskopOsciloskop::m_comboBoxBit1OnCombobox(wxCommandEvent& event)
{
    setPattern(1, m_comboBoxBit1);
}

void OsciloskopOsciloskop::m_comboBoxBit4OnCombobox(wxCommandEvent& event)
{
    setPattern(4, m_comboBoxBit4);
}

void OsciloskopOsciloskop::m_comboBoxBit2OnCombobox(wxCommandEvent& event)
{
    setPattern(2, m_comboBoxBit2);
}

void OsciloskopOsciloskop::m_comboBoxBit0OnCombobox(wxCommandEvent& event)
{
    setPattern(0, m_comboBoxBit0);
}
