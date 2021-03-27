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
#ifndef __TOOL__OSCILOSCOPE__
#define __TOOL__OSCILOSCOPE__

#define SCOPEFUN_MAX_BUFFERING 2
#define SCOPEFUN_MAX_HISTORY   16
#define SCOPEFUN_MAX_UNDO      1024

enum ETimer
{
    TIMER_MAIN_THREAD,
    TIMER_MAIN,
    TIMER_RENDER_THREAD,
    TIMER_RENDER,
    TIMER_CAPTURE,
    TIMER_GENERATE,
    TIMER_MEASURE,
    TIMER_USERINTERFACE,
    TIMER_HARDWARE,
    TIMER_UPDATE0,
    TIMER_UPDATE1,
    TIMER_UPDATE2,
    TIMER_UPDATE3,
};

////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeCamera
//
////////////////////////////////////////////////////////////////////////////////
class OsciloscopeCamera
{
public:
    float mouseStartX;
    float mouseStartY;
    float mouseEndX;
    float mouseEndY;
public:
    float  phi;
    float  theta;
    double zoom;
    Camera ortho;
public:
    OsciloscopeCamera();
};

////////////////////////////////////////////////////////////////////////////////
//
// CaptureBuffer
//
////////////////////////////////////////////////////////////////////////////////

#define PACKET_HEADER 1
#define PACKET_USED   2

class CapturePacket
{
public:
    ularge size;
    byte   data[SCOPEFUN_FRAME_PACKET];
public:
    CapturePacket()
    {
        size = 0;
        SDL_memset(data, 0, SCOPEFUN_FRAME_PACKET);
    }
};

class CaptureFrame
{
public:
    ularge version;
    ularge header;
    ularge data;
    ularge packet;
    ularge frameSize;
    ularge packetStart;
    ularge packetCount;
public:
    CaptureFrame()
    {
        version = 0;
        header = 0;
        data = 0;
        packet = 0;
        frameSize = 0;
        packetStart = 0;
        packetCount = 0;
    }
};

class PacketData
{
public:
    ularge offset;
    ularge size;
    Flag8  flag;
public:
    PacketData()
    {
        offset = 0;
        size = 0;
        flag.set(0);
    }
};

class CaptureHeader
{
public:
    uint   hwVersion;
    uint   hwHeader;
    uint   hwData;
    uint   hwPacket;
    ularge frameStart;
    ularge frameCount;
    ularge frameSize;
    ularge packetStart;
    ularge packetCount;
    ularge packetSize;
public:
    CaptureHeader()
    {
        hwVersion = 0;
        hwHeader = 0;
        hwData = 0;
        hwPacket = 0;
        frameStart = 0;
        frameCount = 0;
        frameSize = 0;
        packetStart = 0;
        packetCount = 0;
        packetSize = 0;
    }
};
/*
class CaptureInterface
{
public:
    CapturePacket transferPacket;
public:
    SDL_SpinLock        spinLock;
public:
    Ring<CaptureFrame>  ringFrame;
    Ring<PacketData>    ringPacket;
public:
    ularge       memoryMax;
    ularge       memoryCurrent;
public:
    CaptureInterface()
    {
        spinLock = 0;
    }
public:
    void lock()
    {
        SDL_AtomicLock(&spinLock);
    }
    void unlock()
    {
        SDL_AtomicUnlock(&spinLock);
    }
public:
    uint allocateFrame(ularge mem, uint packetSize);
    uint allocatePacket(ularge mem, uint packetSize);
public:
    ularge getMemory()
    {
        return memoryCurrent;
    };
    void   setMemory(ularge mem)
    {
        memoryCurrent = min(mem, memoryMax);
    };
public:
    uint intersect(ularge start, ularge end, ularge i0, ularge i1);
    uint overlap(ularge start, ularge end, ularge i0, ularge i1);
    void incRead(ularge start, ularge end);
public:
    uint writePacket(CapturePacket& packet, uint isHeader);
    uint readPacket(CapturePacket& packet);
public:
    virtual uint openRead() = 0;
    virtual uint openWrite() = 0;
    virtual uint write(ularge pos, byte* buffer, ularge size) = 0;
    virtual uint read(ularge pos, byte* buffer, ularge size) = 0;
    virtual uint closeRead() = 0;
    virtual uint closeWrite() = 0;
public:
    virtual uint resize(ularge frame, ularge data) = 0;
    virtual uint save(const char* path, uint& progress, uint& active) = 0;
    virtual uint load(const char* path, uint& progress, uint& active) = 0;
public:
    void freeInterfaceMemory();
};

class CaptureSSD : public CaptureInterface
{
public:
    SDL_RWops*          ctx;
    SDL_RWops*          ctxRead;
    SDL_RWops*          ctxWrite;
    String              fileName;
public:
    CaptureSSD() : CaptureInterface() {};
public:
    uint init(const char* fileName, ularge size, uint packetSize);
public:
    uint openRead();
    uint openWrite();
    uint write(ularge pos, byte* buffer, ularge size);
    uint read(ularge pos, byte* buffer, ularge size);
    uint closeRead();
    uint closeWrite();
public:
    uint resize(ularge frame, ularge data);
    uint save(const char* path, uint& progress, uint& active);
    uint load(const char* path, uint& progress, uint& active);
};

class CaptureMemory : public CaptureInterface
{
public:
    char*        data;
public:
    CaptureMemory() : CaptureInterface() {};
public:
    uint init(byte* mem, ularge size, uint packetSize);
public:
    virtual uint openRead()
    {
        return 0;
    };
    virtual uint openWrite()
    {
        return 0;
    };
    virtual uint write(ularge pos, byte* buffer, ularge size)
    {
        SDL_memcpy(data + pos, buffer, size);
        return 0;
    };
    virtual uint read(ularge pos, byte* buffer, ularge size)
    {
        SDL_memcpy(buffer, data + pos, size);
        return 0;
    };
    virtual uint closeRead()
    {
        return 0;
    }
    virtual uint closeWrite()
    {
        return 0;
    }
public:
    virtual uint resize(ularge frame, ularge data);
    virtual uint save(const char* path, uint& progress, uint& active);
    virtual uint load(const char* path, uint& progress, uint& active);
public:
    void freePacketMemory();
};

#define DRAWSTATE_NEW  0
#define DRAWSTATE_FILL 1
#define DRAWSTATE_DRAW 2


class CaptureBuffer
{
public:
    SDL_atomic_t        lastFrame;
    SDL_atomic_t        drawState;
    SDL_atomic_t        drawFrame;
    SFrameHeader        syncHeader;
    CapturePacket       transferPacket;
    CaptureMemory       historyMemory;
    CaptureSSD          historySSD;
    CaptureInterface*   history;
public:
    void setMemory()
    {
        history = &historyMemory;
    };
    void setSSD()
    {
        history = &historySSD;
    };
public:
    byte*    displayPtr;
    ularge   displaySize;
    ularge   displayRead;
    ularge   displayFrameSize;
public:
    byte*    rldPtr;
    ularge   rldSize;
    ularge   rldWritten;
    ularge   rldStart;
public:
    CaptureBuffer(byte* display, uint displaySize, byte* rld, uint rldSize);
public:
    SFrameHeader  getHeader1(byte* buffer, uint size);
    SFrameHeader  getHeader2(byte* buffer, uint size);
    uint          getFrameSize(byte* buffer, uint version, uint header, uint data, uint packet);
    uint          getFrameSamples(byte* buffer, uint version, uint header, uint data, uint packet);
    uint          getFrameDataSize(byte* buffer, uint version, uint header, uint data, uint packet);
    uint          getOneSampleBytes(uint version);
    uint          getCompression(byte* buffer);
public:
    uint uncompressNew();
    uint uncompress(byte* buffer, uint received, uint transfered, uint version, uint headerSize, uint data, uint packetSize, bool isHeader);
public:
    uint historyWrite(uint frameSize, uint version, uint headerSize, uint data, uint packetSize, bool isHeader);
    uint historyRead(CaptureFrame captureframe, uint version, uint headerSize, uint data, uint packetSize);
public:
    uint captureFrameLast();
    uint captureFrameCount();
    uint captureFrameSize();
    uint captureFrame(CaptureFrame& frame, uint index);
public:
    uint display(OsciloscopeFrame& displayFrame, int version, int header, int data, int packet);
public:
    void clear();
};
*/

////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeGrid
//
////////////////////////////////////////////////////////////////////////////////
class OsciloscopeGrid
{
public:
    float xCount;
    float xMax;
    float xMin;
public:
    float yCount;
    float yMax;
    float yMin;
public:
    void set(float xCount, float yCount);
};

////////////////////////////////////////////////////////////////////////////////
//
// OscFileThread
//
////////////////////////////////////////////////////////////////////////////////
class OscFileThread
{
public:
    String       file;
    SDL_Thread*  thread;
    SDL_atomic_t atomic;
public:
    OscFileThread();
public:
    int  isRunning();
};

////////////////////////////////////////////////////////////////////////////////
//
// Surface 3d
//
////////////////////////////////////////////////////////////////////////////////
struct SurfacePoint
{
public:
    Vector4 pos;
    Vector4 normal;
};

struct SurfaceFrame
{
public:
    SurfacePoint point[NUM_SAMPLES];
    int          count;
};


////////////////////////////////////////////////////////////////////////////////
//
// AutoCallibrate
//
////////////////////////////////////////////////////////////////////////////////
enum EAutoCallibrateMessageBox
{
    acmbNone,
    acmbStart,
    acmbChannel00,
    acmbChannel01,
    acmbChannel10,
    acmbChannel11,
    acmbSkip,
    acmbEnd,
    acmbOk,
    acmbCancel,
};

enum EAutoCallibrate
{
    acStartMessageBox,
    acOffsetStart,
    acOffsetSetup,
    acOffsetCapture,
    acOffsetCalculate,
    acOffsetVoltageChange,
    acOffsetEnd,
    acGeneratorStart,
    acGeneratorMessageBox,
    acGeneratorSetup,
    acGeneratorCapture,
    acGeneratorCalculate,
    acGeneratorEnd,
    acGainMsgBoxCh0,
    acGainStart,
    acGainSetup,
    acGainCapture,
    acGainCalculate,
    acGainVoltageChange,
    acGainMsgBoxCh1,
    acGainEnd,
    acStepStart,
    acStepSetup,
    acStepCapture,
    acStepCalculate,
    acStepVoltageChange,
    acStepMsgBoxCh1,
    acEndMessageBox,
    acSaveSettings,
    acEnd,
};

class AutoCallibration
{
public:
    StringBuffer              debug;
public:
    EAutoCallibrateMessageBox messageBox;
    SDL_atomic_t              resetUI;
public:
    int               active;
    int               generator;
    EAutoCallibrate   mode;
    VoltageCapture    voltage;
    int               frame;
    int               yposition;
    int               iteration;
    int               channel;
    ECallibrationType type;
    int               pass;
public:
    double            offsetMax;
    double            offsetMin;
    double            offset;
    double            offsetMeasured;
public:
    double            generatorMax;
    double            generatorMin;
    double            generatorOffset;
public:
    double            percentage;
    int               gainMin;
    int               gainMax;
    int               gainSet;
    int               gainSetPrevius;
    int               gainDepth;
    double            gainVoltageUp;
    double            gainVoltageDown;
    int               gainMode;
public:
    double             stepMin;
    double             stepMax;
    double             stepReference;
    double             stepVoltage;
    double             stepValue;
    double             stepMeasuredOffsetVoltage;
    double             stepMeasuredOffsetValue;
public:
    AutoCallibration()
    {
        clear();
    }
public:
    void clear()
    {
        debug.clear();
        SDL_AtomicSet(&resetUI, 0);
        channel = 0;
        messageBox = acmbStart;
        active = 0;
        generator = 0;
        mode = acStartMessageBox;
        voltage = vc2Volt;
        frame = 0;
        yposition = 0;
        iteration = 0;
        type = ctNormal;
        offsetMax = 0;
        offsetMin = 0;
        offset = 0;
        offsetMeasured = 0;
        generatorMax = 0;
        generatorMin = 0;
        generatorOffset = 0;
        gainMin = 0;
        gainMax = 0;
        gainVoltageUp = 0;
        gainVoltageDown = 0;
        gainMode = 0;
        stepMeasuredOffsetVoltage = 0;
        stepMeasuredOffsetValue = 0;
    }
public:
    void reset() { SDL_AtomicSet(&resetUI, 1); };
};

class OscThreadLoop
{
public:
    ThreadProduceConsume capture;
    ThreadProduceConsume update;
};

////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeRenderData
//
////////////////////////////////////////////////////////////////////////////////
class OsciloscopeRenderData
{
public:
    Flag64 flags;
public:
    GrTexture* shadowTexture;
public:
    GrShader* shadowLine3dShader;
    GrShader* shadowColorShader;
    GrShader* shadowCoolingShader;
public:
    uint width;
    uint height;
public:
    uint maxEts;
public:
    Camera cameraFFT;
    Camera cameraOsc;
    double zoomFFT;
    double zoomOsc;
    double zoomOriginalOsc;
    double zoomOriginalFFT;
public:
    float  signalPosition;
    float  signalZoom;
    float  sliderPosition;
public:
    float sliderSize;
    uint  sliderMode;
public:
    float fftScaleX;
    float fftScaleY;
    float oscScaleX;
    float oscScaleY;
public:
    double analogChannelYVoltageStep0;
    double analogChannelYVoltageStep1;
    double analogChannelOffsets0;
    double analogChannelOffsets1;
    double analogChannelPositin0;
    double analogChannelPositin1;
public:
    uint colorBackground;
    uint colorTime;
    uint colorChannel0;
    uint colorChannel1;
    uint colorFunction;
    uint colorXyGraph;
    uint colorGrid;
    uint colorBorder;
    uint colorTrigger;
    uint colorDigital;
public:
    uint bandWidth;
public:
    uint etsAttr;
};

////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeThreadData
//
////////////////////////////////////////////////////////////////////////////////
class OsciloscopeThreadData
{
public:
    WndMain               m_window;
    OsciloscopeRenderData m_render;
    double                m_pos;
    double                m_zoom;
    SDisplay              m_history[SCOPEFUN_MAX_HISTORY];
    uint                  m_historyCount;
    SDisplay              m_frame;
    SDisplay              m_etsClear;
    SHardware             m_hw;
};

////////////////////////////////////////////////////////////////////////////////
//
// RenderFlag
//
////////////////////////////////////////////////////////////////////////////////
enum RenderFlag
{
    rfClearRenderTarget = BIT(0),
};

////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeThreadRenderer
//
////////////////////////////////////////////////////////////////////////////////
class OsciloscopeThreadRenderer
{
public:
    float xMin;
    float xMax;
    float yMin;
    float yMax;
public:
    SurfaceFrame* surfaceFrame0;
    SurfaceFrame* surfaceFrame1;
    SurfaceFrame* surfaceFrameF;
public:
    ularge        cfgSize;
    byte*         cfgMem;
    kiss_fft_cpx* in;
    kiss_fft_cpx* out;
public:
    uint historyCount;
public:
    void init(uint max3dhistory)
    {
        surfaceFrame0 = (SurfaceFrame*)pMemory->allocate(sizeof(SurfaceFrame) * max3dhistory);
        surfaceFrame1 = (SurfaceFrame*)pMemory->allocate(sizeof(SurfaceFrame) * max3dhistory);
        surfaceFrameF = (SurfaceFrame*)pMemory->allocate(sizeof(SurfaceFrame) * max3dhistory);
        historyCount  = max3dhistory;
        cfgSize = 0;
        kiss_fft_alloc(NUM_FFT, 0, 0, (size_t*)&cfgSize);
        cfgMem = (byte*)pMemory->allocate(cfgSize);
        in  = (kiss_fft_cpx*)pMemory->allocate(NUM_FFT * sizeof(kiss_fft_cpx));
        out = (kiss_fft_cpx*)pMemory->allocate(NUM_FFT * sizeof(kiss_fft_cpx));
    }
    void clear()
    {
        SDL_memset(surfaceFrame0, 0, sizeof(SurfaceFrame)*historyCount);
        SDL_memset(surfaceFrame1, 0, sizeof(SurfaceFrame)*historyCount);
        SDL_memset(surfaceFrameF, 0, sizeof(SurfaceFrame)*historyCount);
    }
    void clearFast()
    {
        for(uint i = 0; i < historyCount; i++)
        {
            surfaceFrame0[i].count = 0;
            surfaceFrame1[i].count = 0;
            surfaceFrameF[i].count = 0;
        }
    }
public:
    void measureSignal(uint threadId, OsciloscopeThreadData& threadData, MeasureData& measure, OsciloscopeFFT& fft);
public:
    void preOscRender(uint threadId, OsciloscopeThreadData& threadData);
    void preFftRender(uint threadId, OsciloscopeThreadData& threadData);
    void renderFps(uint threadId, OsciloscopeThreadData& threadData);
    void renderAnalogGrid(uint threadId, OsciloscopeThreadData& threadData);
    void renderAnalogAxis(uint threadId, OsciloscopeThreadData& threadData);
    void renderAnalogUnits(uint threadid, OsciloscopeThreadData& threadData);
    void renderAnalog(uint threadId, OsciloscopeThreadData& threadData, float z, uint channelId, uint shadow, SDisplay& frame, float captureTime, float captureVolt, uint color, bool invert);
    void renderAnalog3d(uint threadid, OsciloscopeThreadData& threadData, int frameIndex, float z, uint channelId, SDisplay& frame, float captureTime, float captureVolt, uint color, bool invert);
    void renderSurface3d(uint threadId, OsciloscopeThreadData& threadData, int channelId, uint color);
    void renderAnalogFunction(uint threadid, OsciloscopeThreadData& threadData, float z, int function, SDisplay& frame, float xCapture, float yCapture0, float yCapture1, uint color, bool invert0, bool invert1);
    void renderAnalogFunctionXY(uint threadid, OsciloscopeThreadData& threadData, SDisplay& frame, float xCapture, float yCapture0, float yCapture1, uint color);
    void renderAnalogFunction3d(uint threadid, OsciloscopeThreadData& threadData, SDisplay& frame, int frameIndex, float z, uint color);
    void renderMeasure(uint threadid, OsciloscopeThreadData& threadData);
    void renderMeasureFFT(uint threadId, OsciloscopeThreadData& threadData);
    void renderFFTGrid(uint threadid, OsciloscopeThreadData& threadData);
    void renderFFTAxis(uint threadid, OsciloscopeThreadData& threadData);
    void renderFFTUnits(uint threadid, OsciloscopeThreadData& threadData);
    void renderFFT(uint threadId, OsciloscopeThreadData& threadData, MeasureData& measure, OsciloscopeFFT& fft, SDisplay& frame, bool function, float z, uint channelId, uint color);
    void renderDigitalAxis(uint threadid, OsciloscopeThreadData& threadData, uint xdiv, uint ydiv);
    void renderDigitalGrid(uint threadid, OsciloscopeThreadData& threadData, uint xdiv, uint ydiv);
    void renderDigitalUnit(uint threadid, OsciloscopeThreadData& threadData, uint xdiv, uint ydiv);
    void renderDigital(uint threadid, OsciloscopeThreadData& threadData, MeasureData& measure, uint xres, uint yres);
    void renderSlider(uint threadid, OsciloscopeThreadData& threadData);
public:
    void dftCalculate(iint n, double* inRe, double* inIm, double* outRe, double* outIm);
    void fftCalculate(uint threadId, uint backward, uint n, double* real, double* imag);
    void fftAmplitude(iint points, iint n, double* outAmpl, double* inRe, double* inIm);
};



enum ERenderMode
{
    RENDER_MODE_THERMAL,
    RENDER_MODE_COLOR_ANALOG_3D,
    RENDER_MODE_COLOR_ANALOG_2D,
    RENDER_MODE_COLOR_DIGITAL,
    RENDER_MODE_COLOR_MEASURE,
    RENDER_MODE_COLOR_FFT3D,
    RENDER_MODE_COLOR_FFT2D,
    RENDER_MODE_COLOR_SLIDER,
    RENDER_MODE_COLOR_COOLING,
    RENDER_MODE_COLOR_BLEND_IN_HEATING,
    RENDER_MODE_LAST,
};


////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeSlider
//
////////////////////////////////////////////////////////////////////////////////
class OsciloscopeSlider
{
public:
    void Rectangle(float& rectW, float& rectH, float& rectX, float& rectY, uint width, uint height, float size);
    void MinMax(float& xMinimum, float& xMaximum, uint width, uint height, float viewX, float size, float zoom);
};

enum ThreadID
{
    THREAD_ID_MAIN,
    THREAD_ID_CAPTURE,
    THREAD_ID_UPDATE,
    THREAD_ID_RENDER,
};

class DisplayFrame
{
public:
    uint    count;
    float   value[NUM_SAMPLES];
};

class OscContext
{
public:
    SDL_SpinLock lock;
    SFContext    sf;
    SSimulate    simulate;
    SDisplay     display;
    // SFrameInfo   frameInfo;
public:
    OscContext();
public:
    void setCaptureFlag(int  mode, int  wait);
    void getCaptureFlag(int* mode, int* wait);
    void setSimulate(SSimulate* sim);
    void getSimulate(SSimulate* sim);
    void setDisplay(SDisplay* sim);
    void getDisplay(SDisplay* sim);
};

enum EThreadApiFunction
{
    afInit,
    afIsOpened,
    afOpenUsb,
    afUploadFpga,
    afUploadFxx,
    afResetUsb,
    afCloseUsb,
    afEEPROMRead,
    afEEPROMReadFirmwareID,
    afEEPROMWrite,
    afEEPROMErase,
    afHardwareConfig,
    afSetSimulateData,
    afSetSimulateOnOff,
    afUploadGenerator,
    afReadFpgaStatus,
    afLast,
};

class ThreadApi
{
private:
    SDL_SpinLock                  lock;
    SDL_atomic_t                  sync;
    Array<EThreadApiFunction, 16> func;
    SDL_atomic_t                  ret[afLast];
private:
    SDL_atomic_t open;
    SDL_atomic_t fpga;
    SDL_atomic_t callibrated;
    SDL_atomic_t simulate;
    SDL_atomic_t vid;
    SDL_atomic_t pid;
    SDL_atomic_t sid;
    SDL_atomic_t version;
    SDL_atomic_t header;
    SDL_atomic_t data;
    SDL_atomic_t packet;
public:
    SUsb         usbData;
    ilarge       usbSize;
    SFx3         fx3Data;
    ilarge       fx3Size;
    SFpga        fpgaData;
    ilarge       fpgaSize;
    SEeprom      eepromData;
    ilarge       eepromSize;
    ilarge       eepromOffset;
public:
    String       ip;
    uint         port;
    uint         memory;
    uint         threadSafe;
    uint         active;
    uint         timeout;
public:
    double       simulateTimeValue;
    SSimulate    simulateData;
    SDL_atomic_t simulateOnOff;
    SDisplay     displayData;
    SGenerator   generatorData;
    SHardware    config;
public:
    ThreadApi();
public:
    // thread
    void function(EThreadApiFunction func);
    void wait();
    void update();
public:
    int  result(EThreadApiFunction func);
    void resultClear(EThreadApiFunction func);
    void resultClearAll();
public:
    // data
    int  getVersion();
    int  isOpen();
    int  isFpga();
    int  isCallibrated();
    int  isSimulate();
    void setInit(int memory, int thread, int active, int timeout);
    void setFrame(int  version, int  header, int  data, int  packet);
    void getFrame(int* version, int* header, int* data, int* packet);
    void setUSB(SUsb* usb);
    void getUSB(SUsb* usb);
    void setConfig(SHardware* config);
    void getConfig(SHardware* config);
    void setEEPROM(SEeprom* data, int  size, int  offset);
    void getEEPROM(SEeprom* data, int* size, int* offset);
    void setSimulateData(SSimulate* sim);
    void getSimulateData(SSimulate* sim);
    void setGeneratorData(SGenerator* gen);
    void getGeneratorData(SGenerator* gen);
    void setSimulateOnOff(int  onoff);
    void getSimulateOnOff(int* onoff);
    void setDisplay(SDisplay* display);
    void getDisplay(SDisplay* display);
    void setIpPort(const char* ip, uint port);
public:
    // controlThread
    int  openUSB(OscHardware* hw);
    int  uploadFpga(OscHardware* hw);
    int  useEepromCallibration(OscHardware* hw);
    int  writeFpgaToArtix7(SHardware* ctrl, OscHardware* hw);

    int  writeUsbToEEPROM(OscHardware* hw);
    int  readFirmwareIDFromEEPROM(OscHardware* hw);
    int  readUsbFromEEPROM(OscHardware* hw, int read = 0);
    int  writeCallibrateSettingsToEEPROM(OscHardware* hw);
    int  readCallibrateSettingsFromEEPROM(OscHardware* hw);
    int  eraseEEPROM(OscHardware* hw);
    int  hardwareControlFunction(SHardware* hw);
public:
    // captureThread
    int  captureFrameData(SFrameData* buffer, int toReceive, int* transfered, int type);
};

// ScopeFunCaptureBuffer

class LockFrame {
public:
   SDL_atomic_t lock;
   SDL_atomic_t offset;
   SDL_atomic_t index;
};

class ScopeFunCaptureBuffer
{
public:
    byte*                                     m_dataPtr;
    ularge                                    m_dataMax;
public:
    SDL_atomic_t                              m_progress;
    SDL_atomic_t                              m_threadCount;
    SDL_SpinLock                              m_lock;
    SDL_atomic_t                              m_active;
public:
    Array<LockFrame, SCOPEFUN_MAX_BUFFERING>    m_frameLock;
    SDL_atomic_t                                m_frameCount;
    SDL_atomic_t                                m_frameSize;
    SDL_atomic_t                                m_frameIndex;
    SDL_atomic_t                                m_frameClear;
    SDL_atomic_t                                m_frameOffset;
    SDL_atomic_t                                m_frameSamples;
    SDL_atomic_t                                m_captureIndex;
    SDL_atomic_t                                m_updateIndex;
    SDL_atomic_t                                m_screenIndex;
public:
    ScopeFunCaptureBuffer()
    {
        // data
        m_dataPtr = 0;
        m_dataMax = 0;
        m_lock    = 0;

        // sync
        SDL_AtomicSet(&m_captureIndex, 0);
        SDL_AtomicSet(&m_updateIndex,  0);
        SDL_AtomicSet(&m_screenIndex,  0);
        SDL_AtomicSet(&m_frameIndex,   0);
        SDL_AtomicSet(&m_frameClear,   0);
        SDL_AtomicSet(&m_frameOffset,  0);
        SDL_AtomicSet(&m_frameSamples, 0);
        SDL_AtomicSet(&m_frameSize,    10000 + SCOPEFUN_FRAME_HEADER);
        SDL_AtomicSet(&m_frameCount,   1);
        SDL_AtomicSet(&m_progress,     0);
        SDL_AtomicSet(&m_active,       1);
        SDL_AtomicSet(&m_threadCount, SCOPEFUN_MAX_BUFFERING);

        // frames
        m_frameLock.setCount(SCOPEFUN_MAX_BUFFERING);
        for(int i = 0; i < SCOPEFUN_MAX_BUFFERING; i++)
        { 
           SDL_AtomicSet(&m_frameLock[i].lock,   0); 
           SDL_AtomicSet(&m_frameLock[i].offset, 0);
           SDL_AtomicSet(&m_frameLock[i].index,  0);
        }
    }
public:
    int lock()
    {
       for (int i = 0; i < SCOPEFUN_MAX_BUFFERING; i++)
       {
          while (SDL_AtomicCAS(&m_frameLock[i].lock, 0, 8) == SDL_FALSE)
          {
             SDL_Delay(1);
          }
       }
       return 0;
    }
    int unlock()
    {
       for (int i = 0; i < SCOPEFUN_MAX_BUFFERING; i++)
       {
          while (SDL_AtomicCAS(&m_frameLock[i].lock, 8, 0) == SDL_FALSE)
          {
             SDL_Delay(1);
          }
       }
       return 0;
    }
    int lockCapture(uint id,uint bytesToWrite)
    {
        id = id % SCOPEFUN_MAX_BUFFERING;

        while(SDL_AtomicCAS(&m_frameLock[id].lock, 0, 1) == SDL_FALSE)
        {
           SDL_Delay(1);
        }

        return 0;
    }
    int unlockCapture(uint id,uint frameOffset,uint index)
    {
       id = id % SCOPEFUN_MAX_BUFFERING;

       SDL_AtomicSet(&m_frameLock[id].offset, frameOffset);
       SDL_AtomicSet(&m_frameLock[id].index,  index);

       while (SDL_AtomicCAS(&m_frameLock[id].lock, 1, 2) == SDL_FALSE)
       {
          SDL_Delay(1);
       }

       return 0;
    }
    int lockUpdate(uint id,uint& bytesToRead,uint& index)
    {
       id = id % SCOPEFUN_MAX_BUFFERING;

       while (SDL_AtomicCAS(&m_frameLock[id].lock, 2, 3) == SDL_FALSE)
       {
          SDL_Delay(1);
       }

       bytesToRead = SDL_AtomicGet(&m_frameLock[id].offset);
       index       = SDL_AtomicGet(&m_frameLock[id].index);
       return 1;
    }
    int unlockUpdate(uint id)
    {
       id = id % SCOPEFUN_MAX_BUFFERING;

       SDL_AtomicSet(&m_frameLock[id].offset,0);
       SDL_AtomicSet(&m_frameLock[id].index, 0);

       while (SDL_AtomicCAS(&m_frameLock[id].lock, 3, 4) == SDL_FALSE)
       {
          SDL_Delay(1);
       }
       return 0;
    }
    int lockScreen(uint id)
    {
       if( SDL_AtomicCAS(&m_frameLock[id % SCOPEFUN_MAX_BUFFERING].lock, 4, 5) == SDL_FALSE)
         return 0;
       return 1;
    }
    int unlockScreen(uint id)
    {
       while (SDL_AtomicCAS(&m_frameLock[id % SCOPEFUN_MAX_BUFFERING].lock, 5, 0) == SDL_FALSE)
       {
          SDL_Delay(1);
       }
       return 0;
    }
public:
    int getProgress() { return SDL_AtomicGet(&m_progress); }
    int isActive()    { return SDL_AtomicGet(&m_active);   }
    int disable()     { return SDL_AtomicSet(&m_active, 0); }
public:
    uint save(const char* path);
    uint load(const char* path);
};

class UndoRedo
{
public:
    SHardware m_hw;
    WndMain   m_wnd;
};

////////////////////////////////////////////////////////////////////////////////
//
// Osciloscope
//
////////////////////////////////////////////////////////////////////////////////
class OsciloscopeManager : public Manager, public RenderCallback
{
public:
    String              m_runScript;
    OsciloscopeCallback m_callback;
public:
    uint     renderId;
public:
    double  dtUpdate;
    double  dtRender;
public:
    int     threadIndex[MAX_THREAD];
public:
    byte*   ptrConvertToText;
    byte*   ptrHardwareCapture;
    byte*   ptrDisplay;
    byte*   ptrRunLengthDecode;
public:
    uint    sizeConvertToText;
    uint    sizeHardwareCapture;
    uint    sizeDisplay;
    uint    sizeRunLengthDecode;
public:
    SDL_atomic_t  bandWidth;
    SDL_atomic_t  oscExit;
public:
    SSimulate      sim;
public:
    OscContext*    ctx;
public:
    SDL_atomic_t   syncUI;
public:
    ScopeFunCaptureBuffer m_captureBuffer;
    SDisplay              m_displayBuffer;
public:
    SFx3        fx2;
    SFpga       fpga;
public:
    bool        serverActive;
    SDL_Thread* serverThread;
public:
    ThreadApi    thread;
    SDL_atomic_t threadCapture;
public:
    SDL_Thread*   pCaptureData;
    SDL_Thread*   pGenerateFrame;
    SDL_Thread*   pControlHardware;
    SDL_Thread*   aUpdateThread[MAX_THREAD];
public:
    bool          scrollThread;
    SDL_atomic_t  contextCreated;
public:
    SDL_Window*   sdlWindow;
    SDL_GLContext sdlContext;
    int           sdlX;
    int           sdlY;
    int           sdlW;
    int           sdlH;
public:
    OscFileThread fileThread;
public:
    float frameTime;
public:
    AutoCallibration     callibrate;
    OscSettingsInterface settings;
public:
    WndMain window;
    WndMain windowState[4];
    String  windowName[4];
    uint    windowSlot;
public:
    GrTexture* color;
    GrTexture* depth;
    GrTexture* aShadow[2];
public:
    GrShader* shadowLine3dShader;
    GrShader* shadowColorShader;
    GrShader* shadowCoolingShader;
public:
    float   mouseWheel;
    ularge  wheel;
public:
    Vector4 nearStart;
    Vector4 farStart;
    Vector4 nearEnd;
    Vector4 farEnd;
    Vector4 out0;
    Vector4 out1;
public:
    int   sliderMode;
    float sliderSize;
    float sliderMin;
    float sliderMax;
    float sliderRectX;
    float sliderRectY;
    float sliderRectW;
    float sliderRectH;
    float sliderPosition;
    int   insideSliderBox;
    int   insideSliderArea;
    int   openglFocus;
public:
    float fftAspectX;
    float fftAspectY;
    float oscAspectX;
    float oscAspectY;
public:
    float oscScaleX;
    float oscScaleY;
    float fftScaleX;
    float fftScaleY;
public:
    float xMin;
    float xMax;
    float yMin;
    float yMax;
public:
    OsciloscopeFrame       display;
    SDL_atomic_t           signalMode;
public:
    SDL_SpinLock           usbTransfer;
    SDL_SpinLock           uploadFirmwareLock;
    SDL_SpinLock           displayLock;
    SDL_SpinLock           captureLock;
public:
    bool                   renderSync;
    SDL_SpinLock           renderLock;
    WndMain                renderWindow;
    OsciloscopeRenderData  renderData;
    OscThreadLoop          threadLoop;
    OsciloscopeThreadData  captureData[MAX_THREAD];
    MeasureData            measureData[MAX_THREAD];
    OsciloscopeThreadData  captureTemp;
public:
    OsciloscopeFrame*      pTmpData;
    OsciloscopeFrame       tmpDisplay;
    Ring<OsciloscopeFrame> tmpHistory;
public:
    SDL_atomic_t           captureDataThreadActive;
    SDL_atomic_t           controlHardwareThreadActive;
    SDL_atomic_t           generateFrameThreadActive;
    SDL_atomic_t           updateThreadActive;
    OsciloscopeFrame       threadDisplay;
    Ring<CapturePacket>    threadHistory;
public:
    OsciloscopeCamera cameraOsc;
    OsciloscopeCamera cameraFFT;
    float             analogWindowSize;
    double            signalPosition;
    double            signalZoom;
public:
    OsciloscopeGrid grid;
public:
    Array<UndoRedo, SCOPEFUN_MAX_UNDO> m_hardwareUndo;
    Array<UndoRedo, SCOPEFUN_MAX_UNDO> m_hardwareRedo;
    SHardware                          m_hw;
    SDL_atomic_t                       m_undoRedoEnabled;
public:
    SDL_atomic_t clearRenderTarget;
    SDL_atomic_t clearThermal;
public:
    OsciloscopeManager();
public:
    void   setFrame(int frame);
    double getTriggerVoltagePerStep();
    double getTriggerVoltage();
public:
    int  saveToFile(const char* file);
    int  loadFromFile(const char* file);
    int  convertToText(const char* file);
public:
    int  start();
    int  update(float dt);
    void startThreads();
    void exitThreads();
    void renderMain(uint threadid);
    void renderThread(uint threadid, OsciloscopeThreadData& data, OsciloscopeThreadRenderer& renderer, OsciloscopeFFT& fft);
    void render() {};
    int  stop();
public:
    void getAnalogCount(SDisplay& frame);
    void onCallibrateFrameCaptured(SDisplay& frame, int version);
    void AutoCallibrate();
public:
    void oscCameraSetup(int enable);
    void fftCameraSetup(int enable);
public:
    uint max3dTesselation(uint value, WndMain& wnd);
public:
    void onApplicationInit();
    bool onApplicationIdle();
    void onResize(int width, int height, int oldWidth, int oldHeight);
public:
    void allocate();
    void deallocate();
public:
    void setThreadPriority(ThreadID id);
public:
    int onEvent(SDL_Event& event);
public:
    void startUserInterface();
    void stopUserInterface();
public:
    void clientUploadGenerator(SGenerator& generator);
    void clientUploadDisplay(SDisplay& display);
public:
    void setupControl(WndMain window);
public:
    SSimulate GetServerSim();
    void      transmitSim(SSimulate& sim);
    void      simOnOff(int value);
public:
    void clearEts(int value);
public:
    ushort getAttr(uint volt);
    ushort getGain(int channel, uint volt);
    ushort getVolt(int channel, ushort gain);
public:
    void transferData();
    int  transferUndo();
    int  transferRedo();
    int  isUndoActive();
    int  isRedoActive();
    void transferUI();
    void UndoRedoOnOff(int enable);
public:
    int Render();
};

SFContext* getCtx();
SHardware* getHw();

MANAGER_POINTER(Osciloscope);

#endif
////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
