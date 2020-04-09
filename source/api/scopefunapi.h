////////////////////////////////////////////////////////////////////////////////
//    ScopeFun Oscilloscope ( http://www.scopefun.com )
//    Copyright (C) 2016 - 2019 David Košenina
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
#ifndef SCOPEFUN_API_HEADER
#define SCOPEFUN_API_HEADER

/*----------------------------------------
      ScopeFun API - Types
----------------------------------------*/
typedef unsigned char      byte;
typedef short              ishort;
typedef unsigned short     ushort;
typedef int                iint;
typedef unsigned int       uint;
typedef long long          ilarge;
typedef unsigned long long ularge;

/*----------------------------------------
   version
----------------------------------------*/
#define HARDWARE_VERSION 2

/*----------------------------------------
   bit
----------------------------------------*/
#define BIT(index) (1<<index)

/*----------------------------------------
   Control
-----------------------------------------*/
enum AnalogFunction
{
   ANALOG_FUNCTION_MEDIUM = 0,
   ANALOG_FUNCTION_SUB_CH0_CH1,
   ANALOG_FUNCTION_SUB_CH1_CH0,
   ANALOG_FUNCTION_ADD,
   ANALOG_FUNCTION_MIN,
   ANALOG_FUNCTION_MAX,
   ANALOG_FUNCTION_CUSTOM,
   ANALOG_FUNCTION_UPLOADED,
};

enum AnalogFlag
{
   CHANNEL_ATTR_B = BIT(0),
   CHANNEL_ATTR_A = BIT(1),
   CHANNEL_B_GROUND = BIT(2),
   CHANNEL_A_GROUND = BIT(3),
   CHANNEL_B_ACDC = BIT(4),
   CHANNEL_A_ACDC = BIT(5),
   CHANNEL_INTERLEAVE = BIT(6),
   CHANNEL_ETS = BIT(7),
};

enum GeneratorType
{
   GENERATOR_CUSTOM,
   GENERATOR_SIN,
   GENERATOR_COS,
   GENERATOR_TRIANGLE,
   GENERATOR_RAMP_UP,
   GENERATOR_RAMP_DOWN,
   GENERATOR_SQUARE,
   GENERATOR_DELTA,
   GENERATOR_DC,
   GENERATOR_NOISE,
};

enum ControllType1
{
   CONTROLL1_SHUTDOWN = 0x0000,
   CONTROLL1_RESET = 0x0A5A,
   CONTROLL1_TEST = 0x0640,
   CONTROLL1_WAKEUP = 0x0003,
   CONTROLL1_NORMAL = 0x0600,
};

enum ControllType2
{
   CONTROLL2_NORMAL = 0x0000,
   CONTROLL2_TEST = 0x0002,
   CONTROLL2_RESET = 0x0004,
};

enum CallibrateFreq
{
   CALLIBRATE_1K,
   CALLIBRATE_5K,
   CALLIBRATE_10K,
   CALLIBRATE_100K,
   CALLIBRATE_200K,
   CALLIBRATE_500K,
   CALLIBRATE_1M,
   CALLIBRATE_2M,
};

enum DigitalPattern
{
   DIGITAL_PATTERN_0,
   DIGITAL_PATTERN_1,
   DIGITAL_PATTERN_RISING,
   DIGITAL_PATTERN_FALLING,
};

enum DigitalStage
{
   DIGITAL_STAGE_0,
   DIGITAL_STAGE_1,
   DIGITAL_STAGE_2,
   DIGITAL_STAGE_3,
};

enum DigitalBit
{
   DIGITAL_BIT_0,
   DIGITAL_BIT_1,
   DIGITAL_BIT_2,
   DIGITAL_BIT_3,
   DIGITAL_BIT_4,
   DIGITAL_BIT_5,
   DIGITAL_BIT_6,
   DIGITAL_BIT_7,
   DIGITAL_BIT_8,
   DIGITAL_BIT_9,
   DIGITAL_BIT_10,
   DIGITAL_BIT_11,
   DIGITAL_BIT_12,
   DIGITAL_BIT_13,
   DIGITAL_BIT_14,
   DIGITAL_BIT_15,
};


/*----------------------------------------

      ScopeFun API - Frame Constants

----------------------------------------*/
#define SCOPEFUN_FRAME_HEADER                  (1024)
#define SCOPEFUN_FRAME_DATA           (512*1000*1000)
#define SCOPEFUN_FRAME_PACKET             (1024*1024)
#define SCOPEFUN_FRAME_DATA           (512*1000*1000)
#define SCOPEFUN_FRAME_MEMORY         (512*1024*1024)
#define SCOPEFUN_FRAME_PACKET             (1024*1024)

/*----------------------------------------

      ScopeFun API - Constants

----------------------------------------*/
#define SCOPEFUN_MAX_VOLTAGE                (+511)
#define SCOPEFUN_MIN_VOLTAGE                (-511)
#define SCOPEFUN_DISPLAY                    10000
#define SCOPEFUN_FIRMWARE_FX3               16384
#define SCOPEFUN_FIRMWARE_FPGA              (4*1024*1024)
#define SCOPEFUN_EEPROM_BYTES               (256*1024)
#define SCOPEFUN_EEPROM_FIRMWARE_NAME_BYTES (16)
#define SCOPEFUN_GENERATOR                  32768

/*----------------------------------------

      ScopeFun API - Errors

----------------------------------------*/
#define SCOPEFUN_SUCCESS                0
#define SCOPEFUN_FAILURE               -1

/*----------------------------------------

    ScopeFun API - Array

----------------------------------------*/
#define SCOPEFUN_ARRAY_SWIG(type,size)             \
    %extend{                                     \
        int __len__() const { return size; }      \
        type __getitem__(int i)                   \
        {                                         \
            return self->bytes[i];                 \
        }                                         \
        void __setitem__(int i,type v)            \
        {                                         \
            self->bytes[i] = v;                    \
        }                                         \
    }                                            \

#ifdef SWIG
#define SCOPEFUN_ARRAY(name,type,size)                                                                             \
    typedef struct {                                                                                                   \
        type bytes[size];                                                                                               \
        SCOPEFUN_ARRAY_SWIG(type,size)                                                                                  \
    }name;                                                                                                             \
    %typemap(memberin) type bytes[size]                                                                                \
    {                                                                                                                  \
        memcpy($1, $input, size);                                                                                       \
    }                                                                                                                  \
    %typemap(in) name* buffer(name *tmp)                                                                               \
    {                                                                                                                  \
        if ((SWIG_ConvertPtr($input, (void **)tmp, $1_descriptor, SWIG_POINTER_EXCEPTION | SWIG_POINTER_DISOWN)) == -1) \
            return NULL;                                                                                                 \
        $1 = &tmp;                                                                                                      \
    }                                                                                                                  \
    %typemap(argout) name*                                                                                             \
    {                                                                                                                  \
        %append_output(SWIG_NewPointerObj(%as_voidptr($1), $1_descriptor, SWIG_POINTER_OWN));                           \
    }
#else
#define SCOPEFUN_ARRAY(name,type,size)          \
    typedef struct {                                \
        type bytes[size];                            \
    }name;
#endif

/*----------------------------------------

   ScopeFun API - Structures

----------------------------------------*/
typedef enum _EDisplayFunction
{
   dfMax,
   dfMin,
   dfMedium,
   dfAdd,
   dfCh0SubCh1,
   dfCh1SubCh0,
   dfCustomScript,
} EDisplayFunction;

/*----------------------------------------
   SConfiguration
----------------------------------------*/
typedef struct
{
   uint timeCapture;
   uint voltageCh0;
   uint voltageCh1;
   uint triggerPos;
   uint triggerHis;
   uint triggerPre;

   EDisplayFunction displayFunction;
   // todo ...
} SConfiguration;

/*----------------------------------------
SHardware
----------------------------------------*/
typedef struct
{
    ushort controlAddr;
    ushort controlData;
    ushort vgaina;
    ushort vgainb;
    ushort offseta;
    ushort offsetb;
    ushort analogswitch;
    ushort triggerMode;
    ushort triggerSource;
    ushort triggerSlope;
    short  triggerLevel;
    ushort triggerHis;
    ushort triggerPercent;
    ushort xRange;
    ushort holdoffH;
    ushort holdoffL;
    ushort sampleSizeH;
    ushort sampleSizeL;
    ushort generatorType0;
    ushort generatorVoltage0;
    short  generatorOffset0;
    ushort generatorDeltaH0;
    ushort generatorDeltaL0;
    ushort generatorSqueareDuty0;
    ushort generatorType1;
    ushort generatorVoltage1;
    short  generatorOffset1;
    ushort generatorDeltaH1;
    ushort generatorDeltaL1;
    ushort generatorSqueareDuty1;
    ushort digitalPattern1a;
    ushort digitalPattern1b;
    ushort digitalMask1;
    ushort digitalPattern2a;
    ushort digitalPattern2b;
    ushort digitalMask2;
    ushort digitalPattern3a;
    ushort digitalPattern3b;
    ushort digitalMask3;
    ushort digitalPattern4a;
    ushort digitalPattern4b;
    ushort digitalMask4;
    ushort dt_delayMaxcnt1;
    ushort dt_delayMaxcnt2;
    ushort dt_delayMaxcnt3;
    ushort dt_delayMaxcnt4;
    ushort dt_control;
    ushort digitalVoltage;
    ushort digitalInputOutput;
    ushort digitalOutputBit;
    ushort digitalOutputMask;
    ushort digitalClkDivideH;
    ushort digitalClkDivideL;
    ushort average;
    uint   reserved2;
    uint   reserved3;
    uint   reserved4;
    uint   reserved5;
    uint   reserved6;
} SHardware;

/*----------------------------------------
   SFrameHeader
----------------------------------------*/
SCOPEFUN_ARRAY(SArrayMagic,             byte,    4);
SCOPEFUN_ARRAY(SArrayETS,               byte,    1);
SCOPEFUN_ARRAY(SArrayPaddingBefore,     byte,   251);
SCOPEFUN_ARRAY(SArrayHardware,          byte,   128);
SCOPEFUN_ARRAY(SArrayPaddingAfter,      byte,   639);
SCOPEFUN_ARRAY(SArrayCrc,               byte,     1);
typedef struct
{
    SArrayMagic          magic;
    SArrayETS            etsDelay;
    SArrayPaddingBefore  paddBefore;
    SArrayHardware       hardware;
    SArrayPaddingAfter   paddAfter;
    SArrayCrc            crc;
} SFrameHeader;

/*----------------------------------------
   SFrameData
----------------------------------------*/
SCOPEFUN_ARRAY(SArrayFrameData, byte, SCOPEFUN_FRAME_MEMORY);
typedef struct
{
    SArrayFrameData data;
} SFrameData;

/*----------------------------------------
   SEEPROM
----------------------------------------*/
SCOPEFUN_ARRAY(SArrayEEPROM, byte, SCOPEFUN_EEPROM_BYTES);
typedef struct
{
    SArrayEEPROM data;
} SEeprom;

/*----------------------------------------
   SGUID
----------------------------------------*/
typedef struct
{
    uint    data1;
    ushort  data2;
    ushort  data3;
    byte    data4[8];
} SGUID;

/*----------------------------------------
   SFx2
----------------------------------------*/
SCOPEFUN_ARRAY(SArrayFx3, byte, SCOPEFUN_FIRMWARE_FX3);
typedef struct
{
    uint      size;
    SArrayFx3 data;
} SFx3;

/*----------------------------------------
   SFpga
----------------------------------------*/
SCOPEFUN_ARRAY(SArrayFpga, byte, SCOPEFUN_FIRMWARE_FPGA);
typedef struct
{
    uint       size;
    SArrayFpga data;
} SFpga;

/*----------------------------------------
   SGenerator
----------------------------------------*/

/*----------------------------------------
   ESimulateType
----------------------------------------*/
SCOPEFUN_ARRAY(SArrayGeneratorAnalog0, ishort, SCOPEFUN_GENERATOR);
SCOPEFUN_ARRAY(SArrayGeneratorAnalog1, ishort, SCOPEFUN_GENERATOR);
SCOPEFUN_ARRAY(SArrayGeneratorDigital, ushort, SCOPEFUN_GENERATOR);
typedef struct
{
    SArrayGeneratorAnalog0 analog0;
    SArrayGeneratorAnalog1 analog1;
    SArrayGeneratorDigital digital;
} SGenerator;

/*----------------------------------------
   ESimulateType
----------------------------------------*/
typedef enum _ESimulateType
{
    stSin,
    stCos,
    stInc,
    stDec,
    stConstant,
    stRandom,
    stSquare,
    stDelta,
} ESimulateType;

/*----------------------------------------
   SSimulate
----------------------------------------*/
typedef struct
{
    byte                    active0;
    byte                    active1;
    ESimulateType           type0;
    ESimulateType           type1;
    float                   period0;
    float                   period1;
    float                   peakToPeak0;
    float                   peakToPeak1;
    float                   avery0;
    float                   avery1;
    float                   speed0;
    float                   speed1;
    uint                    etsIndex;
    uint                    etsActive;
    uint                    etsMax;
    float                   time;
    float                   voltage0;
    float                   voltage1;
} SSimulate;


/*----------------------------------------
   SUsb
----------------------------------------*/
typedef struct
{
    uint         idVendor;
    uint         idProduct;
    uint         idSerial;
    uint         timeoutEp2;
    uint         timeoutEp4;
    uint         timeoutEp6;
    uint         xferSize;
    SGUID        guid;
} SUsb;

/*----------------------------------------
   SDisplay
----------------------------------------*/
SCOPEFUN_ARRAY(SArrayDisplayAnalog0, float,  SCOPEFUN_DISPLAY);
SCOPEFUN_ARRAY(SArrayDisplayAnalog1, float,  SCOPEFUN_DISPLAY);
SCOPEFUN_ARRAY(SArrayDisplayAnalogF, float,  SCOPEFUN_DISPLAY);
SCOPEFUN_ARRAY(SArrayDisplayDigital, ushort, SCOPEFUN_DISPLAY);
typedef struct
{
    SArrayDisplayAnalog0 analog0;
    SArrayDisplayAnalog1 analog1;
    SArrayDisplayAnalogF analogF;
    SArrayDisplayDigital digital;
} SDisplay;

/*----------------------------------------

ScopeFun API - Context

----------------------------------------*/
typedef struct { int value; } SAtomic;
typedef int SSpinLock;

typedef struct
{
    SAtomic           on;
    SSimulate         data;
    uint              active;
} SCtxSimulate;

typedef struct
{
    uint              maxMemory;
    SFrameData*       data;
    uint              received;
    uint              frameSize;
} SCtxFrame;

typedef struct
{
    SDisplay          data;
} SCtxDisplay;

typedef struct
{
    uint              version;
    uint              major;
    uint              minor;
    uint              active;
    SAtomic           thread;
    SSpinLock         lock;
    uint              timeout;
} SCtxApi;

typedef struct
{
    SCtxApi           api;
    SCtxSimulate      simulate;
    SCtxFrame         frame;
    SConfiguration    configuration;
    byte*             usb;
} SFContext;

/*----------------------------------------

   ScopeFun API - Functions

----------------------------------------*/

/*----------------------------------------
   defines
----------------------------------------*/
#define SCOPEFUN_CREATE(name) extern name* sfCreate##name();
#define SCOPEFUN_DELETE(name) extern void  sfDelete##name(name* INPUT);

/*----------------------------------------
   create
----------------------------------------*/
SCOPEFUN_CREATE(SFContext)
SCOPEFUN_CREATE(SDisplay)
SCOPEFUN_CREATE(SSimulate)
SCOPEFUN_CREATE(SUsb)
SCOPEFUN_CREATE(SHardware)
SCOPEFUN_CREATE(SConfiguration)
SCOPEFUN_CREATE(SFx3)
SCOPEFUN_CREATE(SFpga)
SCOPEFUN_CREATE(SGenerator)
SCOPEFUN_CREATE(SEeprom)

extern SFrameData* sfCreateSFrameData(SFContext* ctx, int memory);

/*----------------------------------------
   delete
----------------------------------------*/
SCOPEFUN_DELETE(SFContext)
SCOPEFUN_DELETE(SDisplay)
SCOPEFUN_DELETE(SSimulate)
SCOPEFUN_DELETE(SFrameData)
SCOPEFUN_DELETE(SUsb)
SCOPEFUN_DELETE(SHardware)
SCOPEFUN_DELETE(SConfiguration)
SCOPEFUN_DELETE(SFrameData)
SCOPEFUN_DELETE(SFx3)
SCOPEFUN_DELETE(SFpga)
SCOPEFUN_DELETE(SGenerator)
SCOPEFUN_DELETE(SEeprom)

#ifdef SWIG

    #define SCOPEFUN_API extern

    /*----------------------------------------
      API
    ----------------------------------------*/
    SCOPEFUN_API int sfApiInit();
    SCOPEFUN_API int sfApiCreateContext(SFContext* INOUT, int INPUT);
    SCOPEFUN_API int sfApiDeleteContext(SFContext* INPUT);
    SCOPEFUN_API int sfApiVersion(SFContext* INPUT, int* OUTPUT, int* OUTPUT, int* OUTPUT);
    SCOPEFUN_API int sfSetActive(SFContext* INPUT, int INPUT);
    SCOPEFUN_API int sfIsActive(SFContext* INPUT);
    SCOPEFUN_API int sfSetThreadSafe(SFContext* INPUT, int INPUT);
    SCOPEFUN_API int sfIsThreadSafe(SFContext* INPUT);
    SCOPEFUN_API int sfSetTimeOut(SFContext* INPUT, int INPUT);
    SCOPEFUN_API int sfGetTimeOut(SFContext* INPUT, int* OUTPUT);
    SCOPEFUN_API int sfApiExit();


    /*----------------------------------------
      Hardware
    ----------------------------------------*/
    SCOPEFUN_API int sfHardwareOpen(SFContext* INPUT, SUsb* INPUT, int INPUT);
    SCOPEFUN_API int sfHardwareIsOpened(SFContext* INPUT, int* OUTPUT);
    SCOPEFUN_API int sfHardwareReset(SFContext* INPUT);
    SCOPEFUN_API int sfHardwareConfig(SFContext* INPUT, SHardware2* INPUT);
    SCOPEFUN_API int sfHardwareCapture(SFContext* INPUT, SFrameData* INOUT, int INPUT, int* OUTPUT, int INPUT);
    SCOPEFUN_API int sfHardwareUploadFx3(SFContext* INPUT, SFx2* INPUT);
    SCOPEFUN_API int sfHardwareUploadFpga(SFContext* INPUT, SFpga* INPUT);
    SCOPEFUN_API int sfHardwareUploadGenerator(SFContext* INPUT, SGenerator* INPUT);
    SCOPEFUN_API int sfHardwareEepromRead(SFContext* INPUT, SEeprom* INOUT, int INPUT, int INPUT);
    SCOPEFUN_API int sfHardwareEepromReadFirmwareID(SFContext* INPUT, SEeprom* INOUT, int INPUT, int INPUT);
    SCOPEFUN_API int sfHardwareEepromWrite(SFContext* INPUT, SEeprom* INPUT, int INPUT, int INPUT);
    SCOPEFUN_API int sfHardwareEepromErase(SFContext* INPUT);
    SCOPEFUN_API int sfHardwareClose(SFContext* INPUT);

    /*----------------------------------------
     Frame
   ----------------------------------------*/
    SCOPEFUN_API int sfFrameCapture(SFContext* INPUT, SFrameData* INOUT, int INPUT, int* OUTPUT);
    SCOPEFUN_API int sfFrameDisplay(SFContext* INPUT, SFrameData* INOUT, int INPUT, int INPUT, SDisplay* INOUT);

    /*----------------------------------------
      Transformations
    ----------------------------------------*/
    SCOPEFUN_API int sfTransformFrameToHeader(SFContext* INPUT, SFrameData* INOUT, SFrameHeader* INOUT);
    SCOPEFUN_API int sfTransformHeaderToHardware(SFContext* INPUT, SFrameHeader* INOUT, SHardware* INOUT);
    SCOPEFUN_API int sfTransformHardwareToConfiguration(SFContext* INPUT, SHardware* INOUT, SConfiguration* INOUT);
    SCOPEFUN_API int sfTransformConfigurationToHardware(SFContext* INPUT, SConfiguration* INOUT, SHardware* INOUT);

    /*----------------------------------------
     Get Configuration
    ----------------------------------------*/
    SCOPEFUN_API int sfGetFrameSize(SHardware*  INPUT, uint* OUTPUT);
    SCOPEFUN_API int sfGetNumSamples(SHardware* INPUT, uint* OUTPUT);

    /*----------------------------------------
       Set Configuration
    ----------------------------------------*/
    SCOPEFUN_API int sfSetFrameSize(SHardware*  INPUT, uint  INPUT);
    SCOPEFUN_API int sfSetNumSamples(SHardware* INPUT, uint  INPUT);

    /*----------------------------------------
      Header
    ----------------------------------------*/
    SCOPEFUN_API int sfHeaderEts( SFrameHeader* INPUT, uint* OUTPUT);
    SCOPEFUN_API int sfHeaderTemperature(SFrameHeader* INPUT, float* OUTPUT);

    /*----------------------------------------
      Simulate
    ----------------------------------------*/
    SCOPEFUN_API int sfIsSimulate(SFContext* INPUT);
    SCOPEFUN_API int sfSetSimulateData(SFContext* INPUT, SSimulate* INPUT);
    SCOPEFUN_API int sfSetSimulateOnOff(SFContext* INPUT, int INPUT);
    SCOPEFUN_API int sfGetSimulateData(SFContext* INPUT, SSimulate* INOUT);
    SCOPEFUN_API int sfSimulate(SFContext* INPUT, double INPUT);

#else

    #ifdef SCOPEFUN_API_STATIC
        #define SCOPEFUN_API extern
    #else
        #ifdef SCOPEFUN_API_EXPORT
            #if defined(PLATFORM_LINUX ) || defined(PLATFORM_MINGW) || defined(PLATFORM_MAC)
                #define SCOPEFUN_API  __attribute__((visibility("default")))
            #else
                #define SCOPEFUN_API _declspec(dllexport)
            #endif
        #else
            #if defined(PLATFORM_LINUX ) || defined(PLATFORM_MINGW) || defined(PLATFORM_MAC) || defined(PLATFORM_WIN)
                #define SCOPEFUN_API
            #else
                #define SCOPEFUN_API _declspec(dllimport)
            #endif
        #endif
    #endif

    /*----------------------------------------
      API
    ----------------------------------------*/
    SCOPEFUN_API int sfApiInit();
    SCOPEFUN_API int sfApiCreateContext(SFContext* ctx, int maxMemory);
    SCOPEFUN_API int sfApiDeleteContext(SFContext* ctx);
    SCOPEFUN_API int sfApiVersion(SFContext* ctx, int* version, int* major, int* minor);
    SCOPEFUN_API int sfSetThreadSafe(SFContext* ctx, int threadSafe);
    SCOPEFUN_API int sfIsThreadSafe(SFContext* ctx);
    SCOPEFUN_API int sfSetActive(SFContext* ctx,  int  active);
    SCOPEFUN_API int sfIsActive(SFContext* ctx);
    SCOPEFUN_API int sfSetTimeOut(SFContext* ctx, int  timeout);
    SCOPEFUN_API int sfGetTimeOut(SFContext* ctx, int* timeout);
    SCOPEFUN_API int sfApiExit();

    /*----------------------------------------
      Hardware
    ----------------------------------------*/
    SCOPEFUN_API int sfHardwareOpen(SFContext* ctx, SUsb* usb, int version);
    SCOPEFUN_API int sfHardwareReset(SFContext* ctx);
    SCOPEFUN_API int sfHardwareIsOpened(SFContext* ctx, int* open);
    SCOPEFUN_API int sfHardwareConfig(SFContext* ctx, SHardware* hw);
    SCOPEFUN_API int sfHardwareCapture(SFContext* ctx, SFrameData* buffer, int len, int offset, int* received);
    SCOPEFUN_API int sfHardwareCaptureOff(SFContext* ctx);
    SCOPEFUN_API int sfHardwareUploadFx3(SFContext* ctx, SFx3* fx2);
    SCOPEFUN_API int sfHardwareUploadFpga(SFContext* ctx, SFpga* fpgs);
    SCOPEFUN_API int sfHardwareUploadGenerator(SFContext* ctx, SGenerator* gen);
    SCOPEFUN_API int sfHardwareEepromRead(SFContext* ctx, SEeprom* eeprom, int size, int adrees);
    SCOPEFUN_API int sfHardwareEepromReadFirmwareID(SFContext* ctx, SEeprom* eeprom, int size, int adrees);
    SCOPEFUN_API int sfHardwareEepromWrite(SFContext* ctx, SEeprom* eeprom, int size, int adress);
    SCOPEFUN_API int sfHardwareEepromErase(SFContext* ctx);
    SCOPEFUN_API int sfHardwareClose(SFContext* ctx);

    /*----------------------------------------
      Frame
    ----------------------------------------*/
    SCOPEFUN_API int sfFrameCapture(SFContext* ctx,  SFrameData* buffer, int len, int* received);
    SCOPEFUN_API int sfFrameDisplay(SFContext* ctx,  SFrameData* buffer, int len, int received, SDisplay* display);
   
    /*----------------------------------------
      Transformations
    ----------------------------------------*/
    SCOPEFUN_API int sfTransformFrameToHeader(SFContext* ctx, SFrameData* frame, SFrameHeader* header);
    SCOPEFUN_API int sfTransformHeaderToHardware(SFContext* ctx, SFrameHeader* header, SHardware* hw);
    SCOPEFUN_API int sfTransformHardwareToConfiguration(SFContext* ctx, SHardware* hw, SConfiguration* cfg);
    SCOPEFUN_API int sfTransformConfigurationToHardware(SFContext* ctx, SConfiguration* cfg, SHardware* hw);

    /*----------------------------------------
       Get Configuration
    ----------------------------------------*/
    SCOPEFUN_API int sfGetFrameSize(SHardware*  hw, uint* frameSize);
    SCOPEFUN_API int sfGetNumSamples(SHardware* hw, uint* numSamples);

    /*----------------------------------------
       Set Configuration
    ----------------------------------------*/
    SCOPEFUN_API int sfSetFrameSize(SHardware*  hw, uint  frameSize);
    SCOPEFUN_API int sfSetNumSamples(SHardware* hw, uint  numSamples);

    /*----------------------------------------
      Header
    ----------------------------------------*/
    SCOPEFUN_API int sfHeaderEts( SFrameHeader* header,uint* ets);
    SCOPEFUN_API int sfHeaderTemperature(SFrameHeader* header,float* temperature);

    /*----------------------------------------
      Simulate
    ----------------------------------------*/
    SCOPEFUN_API int sfIsSimulate(SFContext* ctx);
    SCOPEFUN_API int sfSetSimulateData(SFContext* ctx, SSimulate* sim);
    SCOPEFUN_API int sfGetSimulateData(SFContext* ctx, SSimulate* sim);
    SCOPEFUN_API int sfSetSimulateOnOff(SFContext* ctx, int on);
    SCOPEFUN_API int sfSimulate(SFContext* ctx, double time);
#endif

/*----------------------------------------
  http://www.ScopeFun.com
----------------------------------------*/
#endif
