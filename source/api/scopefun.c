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
#include<core/purec/pureusb.h>
#include<core/purec/purec.h>
#include<api/scopefunapi.h>
#include<SDL.h>

#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#include<math.h>
#include<errno.h>
#include<locale.h>

/*--------------------------------------------------------------------------------
   helper
--------------------------------------------------------------------------------*/

#define PI                 3.14159265358979323846f
#define NUM_SAMPLES        10000
#define NUM_SAMPLESF       10000.f
#define MAXOSCVALUE        511.f

float fClamp(float a, float min, float max)
{
    if(a < min)
    {
        return min;
    }
    if(a > max)
    {
        return max;
    }
    return a;
}


double dClamp(double a, double min, double max)
{
    if(a < min)
    {
        return min;
    }
    if(a > max)
    {
        return max;
    }
    return a;
}

ularge lClamp(ularge a, ularge min, ularge max)
{
    if(a < min)
    {
        return min;
    }
    if(a > max)
    {
        return max;
    }
    return a;
}

ilarge ilClamp(ilarge a, ilarge min, ilarge max)
{
    if(a < min)
    {
        return min;
    }
    if(a > max)
    {
        return max;
    }
    return a;
}

int iClamp(int a, int min, int max)
{
    if(a < min)
    {
        return min;
    }
    if(a > max)
    {
        return max;
    }
    return a;
}

uint uMin(uint a, uint b)
{
    if(a < b) { return a; }
    else       { return b; }
}

uint uMax(uint a, uint b)
{
    if(a > b) { return a; }
    else       { return b; }
}


int iMin(int a, int b)
{
    if(a < b) { return a; }
    else       { return b; }
}

int iMax(int a, int b)
{
    if(a > b) { return a; }
    else       { return b; }
}


ularge lMin(ularge a, ularge b)
{
    if(a < b) { return a; }
    else       { return b; }
}

ularge lMax(ularge a, ularge b)
{
    if(a > b) { return a; }
    else       { return b; }
}

float rand_FloatRange(float a, float b)
{
    return (float)((b - a) * ((float)rand() / RAND_MAX)) + a;
}

ishort leadBitShift(ushort value)
{
    ishort isLeadBit = value & 0x200;
    if(isLeadBit)
    {
        return (value | 0xFE00);
        // return (~(value&(~0x200))) + 1;
    }
    return value;
}


ishort leadBitCompl(ushort value)
{
    ishort isLeadBit = value & 0x200;
    if(isLeadBit)
    {
        return (~(value & (~0x200))) + 1;
    }
    return value;
}

ushort raiseFlag16(ushort attr, ushort bits)
{
    return attr | bits;
}
ushort lowerFlag16(ushort attr, ushort bits)
{
    return attr & ~bits;
}

void togleFlag16(ushort attr, ushort bits)
{
    attr ^= bits;
}

ushort isFlag16(ushort attr, ushort bits)
{
    return attr & bits;
}
void bitFlag16(ushort attr, ushort bits, ushort value)
{
    attr ^= ((~value + 1) ^ attr) & bits;
}

uint apiMin(uint a, uint b)
{
    if(a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void apiLock(SFContext* ctx)
{
    if(SDL_AtomicGet((SDL_atomic_t*)&ctx->api.thread) > 0)
    {
        SDL_AtomicLock(&ctx->api.lock);
    }
    else
    {
        int debug = 1;
    }
}

void apiUnlock(SFContext* ctx)
{
    if(SDL_AtomicGet((SDL_atomic_t*)&ctx->api.thread) > 0)
    {
        SDL_AtomicUnlock(&ctx->api.lock);
    }
    else
    {
        int debug = 1;
    }
}

unsigned short endianByteSwap16(unsigned short value)
{
    unsigned short low  = (value & 0x00FF);
    unsigned short high = (value & 0xFF00);
    return (low << 8) | (high >> 8);
}

uint apiFrameSize(int version, char* headerPtr)
{
    SFrameHeader* header = (SFrameHeader*)headerPtr;
    uint sampleSize = ((uint)header->hardware.bytes[32 + 0] << 24) | ((uint)header->hardware.bytes[32 + 1] << 16) | ((uint)header->hardware.bytes[32 + 2] << 8) | ((uint)header->hardware.bytes[32 + 3] << 0);
    uint frameSize  = sampleSize * 4;
    if(frameSize % 1024 != 0)
    {
        frameSize = ((frameSize / 1024) + 1) * 1024;
    }
    frameSize += SCOPEFUN_FRAME_HEADER;
    return frameSize;
}

int apiResult(int ret)
{
    if(ret == 0)
    {
        return SCOPEFUN_SUCCESS;
    }
    return SCOPEFUN_FAILURE;
}

/*--------------------------------------------------------------------
   structures
---------------------------------------------------------------------*/

#define SCOPEFUN_CREATE_DELETE(name) \
    name* sfCreate##name()           { name* ptr = malloc(sizeof(name)); SDL_zerop(ptr); return ptr; } \
    void  sfDelete##name(name* ptr)  { free(ptr); }

SCOPEFUN_CREATE_DELETE(SFloat)
SCOPEFUN_CREATE_DELETE(SInt)
SCOPEFUN_CREATE_DELETE(SFContext)
SCOPEFUN_CREATE_DELETE(SDisplay)
SCOPEFUN_CREATE_DELETE(SSimulate)
SCOPEFUN_CREATE_DELETE(SUsb)
SCOPEFUN_CREATE_DELETE(SHardware)
SCOPEFUN_CREATE_DELETE(SFx3)
SCOPEFUN_CREATE_DELETE(SFpga)
SCOPEFUN_CREATE_DELETE(SGenerator)
SCOPEFUN_CREATE_DELETE(SEeprom)
SCOPEFUN_CREATE_DELETE(SFrameData)
SCOPEFUN_CREATE_DELETE(SFrameHeader)


/*--------------------------------------------------------------------
   Initialization
---------------------------------------------------------------------*/
SCOPEFUN_API int sfApiInit()
{
    usbFxxInit(0);
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfApiCreateContext(SFContext* ctx, int memory)
{
    cMemSet((char*)ctx, 0, sizeof(SFContext));
    apiLock(ctx);
    // frame
    ctx->frame.maxMemory = memory;
    cMemSet((char*)ctx->frame.data.data.bytes, 0, ctx->frame.maxMemory);
    // usb
    ctx->usb = cMalloc(sizeof(struct UsbContext));
    struct UsbContext* pCtx = (UsbContext*)ctx->usb;
    cMemSet((char*)pCtx, 0, sizeof(struct UsbContext));
    // version
    ctx->api.version = HARDWARE_VERSION;
    ctx->api.major   = 0;
    ctx->api.minor   = 0;
    // callback
    ctx->pCallback = 0;
    // function
    ctx->functionType = dfMedium;
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfApiDeleteContext(SFContext* ctx)
{
    // usb
    cFree((char*)ctx->usb);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfApiVersion(SFContext* ctx, SInt* version, SInt* major, SInt* minor)
{
    apiLock(ctx);
    version->value = ctx->api.version;
    major->value   = ctx->api.major;
    minor->value   = ctx->api.minor;
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfApiExit()
{
    socketExit();
    usbFxxExit(0);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfIsActive(SFContext* ctx)
{
    int active = 0;
    apiLock(ctx);
    active = ctx->api.active;
    apiUnlock(ctx);
    return active;
}
SCOPEFUN_API int sfIsThreadSafe(SFContext* ctx)
{
    int ts = 0;
    apiLock(ctx);
    ts = SDL_AtomicGet((SDL_atomic_t*)&ctx->api.thread);
    apiUnlock(ctx);
    return ts;
}

SCOPEFUN_API int sfSetThreadSafe(SFContext* ctx, int threadSafe)
{
    while(SDL_AtomicCAS((SDL_atomic_t*)&ctx->api.thread, 0, threadSafe) == SDL_FALSE)
    {
        cSleep(1);
    }
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfSetActive(SFContext* ctx, int active)
{
    apiLock(ctx);
    ctx->api.active = active;
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfSetTimeOut(SFContext* ctx, int timeout)
{
    apiLock(ctx);
    ctx->api.timeout = timeout;
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfGetTimeOut(SFContext* ctx, SInt* timeout)
{
    apiLock(ctx);
    timeout->value = ctx->api.timeout;
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}

/*--------------------------------------------------------------------
    hardware
---------------------------------------------------------------------*/
SCOPEFUN_API int sfHardwareOpen(SFContext* ctx, SUsb* cfg, int version)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        UsbGuid id;
        cMemCpy((char*)&id, (char*)&cfg->guid, sizeof(struct UsbGuid));
        usbDevice* deviceList[4] = { 0 };
        usbFxxGuidVidPid(pUsbCtx, id, cfg->idVendor, cfg->idProduct, cfg->idSerial);
        int ret = PUREUSB_SUCCESS;
        ret += usbFxxFreeList(pUsbCtx);
        ret += usbFxxFindList(pUsbCtx, deviceList, 4);
        ret += usbFxxOpenNormal(pUsbCtx, deviceList, 4);
        result = apiResult(ret);
        pUsbCtx->version = version;
    }
    apiUnlock(ctx);
    return result;
}

SCOPEFUN_API int sfHardwareReset(SFContext* ctx)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int ret = PUREUSB_FAILURE;
        ret = usbFx3Reset(pUsbCtx);
        result = apiResult(ret);
    }
    apiUnlock(ctx);
    return result;
}

SCOPEFUN_API int sfHardwareIsOpened(SFContext* ctx, SInt* open)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        open->value = usbFxxIsConnected(pUsbCtx);
        result = SCOPEFUN_SUCCESS;
    }
    if(SDL_AtomicGet((SDL_atomic_t*)&ctx->simulateOn) > 0)
    {
        open->value = 1;
        result = SCOPEFUN_SUCCESS;
    }
    apiUnlock(ctx);
    return result;
}
SCOPEFUN_API int sfHardwareConfig(SFContext* ctx, SHardware* hw)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int swap = 1;
        int transfered = 0;
        int ret = usbFxxTransferDataOut(pUsbCtx, 2, (char*)hw, sizeof(SHardware), swap, ctx->api.timeout, &transfered);
        result = apiResult(ret);
        if(ctx->pCallback)
        { ((SCallback*)ctx->pCallback)->onConfigure(hw); }
    }
    apiUnlock(ctx);
    return result;
}

SCOPEFUN_API int sfHardwareCapture(SFContext* ctx, SFrameData* buffer, int len, int offset, SInt* received)
{
    /* if(sfIsSimulate(ctx))
     {
         apiLock(ctx);
         int simLen = apiMin(len, ctx->frame.maxMemory);
         if( (ctx->frame.received + simLen) > ctx->frame.maxMemory)
         {
             simLen = ctx->frame.maxMemory - ctx->frame.received;
         }
         SDL_memcpy(&buffer->data.bytes[0], (byte*)&ctx->frame.data->data.bytes[0] + ctx->frame.received, simLen);
         ctx->frame.received += simLen;
         *received = simLen;
         apiUnlock(ctx);
         return SCOPEFUN_SUCCESS;
     }*/
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    uint size = apiMin(len, SCOPEFUN_FRAME_MEMORY);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int swap = 0;
        int ret = usbFxxTransferDataIn(pUsbCtx, 6, (byte*)&buffer->data.bytes[offset], size, swap, ctx->api.timeout, (int*)received);
        result = apiResult(ret);
    }
    apiUnlock(ctx);
    return result;
}

SCOPEFUN_API int sfHardwareUploadFx3(SFContext* ctx, SFx3* fx2)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int ret = usbFx3UploadFirmwareToFx3(pUsbCtx, fx2->data.bytes);
        result = apiResult(ret);
        cSleep(3000);
    }
    apiUnlock(ctx);
    return result;
}
SCOPEFUN_API int sfHardwareUploadFpga(SFContext* ctx, SFpga* fpga)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int ret = 0;
        char id[EEPROM_BYTE_COUNT] = { 0 };
        ret += usbFx3CheckFirmwareID(pUsbCtx, id);
        ret += usbFx3UploadFirmwareToFpga(pUsbCtx, (byte*)fpga->data.bytes, fpga->size, 0);
        result = apiResult(ret);
    }
    apiUnlock(ctx);
    return result;
}
SCOPEFUN_API int sfHardwareUploadGenerator(SFContext* ctx, SGenerator* gen)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int transfered = 0;
        int ret = usbFxxTransferDataOut(pUsbCtx, 4, (byte*)gen, sizeof(SGenerator), 0, ctx->api.timeout, &transfered);
        result = apiResult(ret);
    }
    apiUnlock(ctx);
    return result;
}
SCOPEFUN_API int sfHardwareEepromRead(SFContext* ctx, SEeprom* eeprom, int size, int adress)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int ret = usbFx3ReadEEPROM(pUsbCtx, (byte*)&eeprom->data.bytes[0], size, adress);
        result = apiResult(ret);
    }
    apiUnlock(ctx);
    return result;
}
SCOPEFUN_API int sfHardwareEepromReadFirmwareID(SFContext* ctx, SEeprom* eeprom, int size, int adress)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int ret = usbFx3ReadEEPROMFirmwareID(pUsbCtx, (byte*)&eeprom->data.bytes[0], SCOPEFUN_EEPROM_FIRMWARE_NAME_BYTES, adress);
        result = apiResult(ret);
    }
    apiUnlock(ctx);
    return result;
}
SCOPEFUN_API int sfHardwareEepromWrite(SFContext* ctx, SEeprom* eeprom, int size, int adress)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        int ret = usbFx3WriteEEPROM(pUsbCtx, (byte*)&eeprom->data.bytes[0], size, adress);
        result = apiResult(ret);
    }
    apiUnlock(ctx);
    return result;
}
SCOPEFUN_API int sfHardwareEepromErase(SFContext* ctx)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        UsbEEPROM eeprom;
        cMemSet((char*)&eeprom, 0, sizeof(struct UsbEEPROM));
        int ret = usbFx3WriteEEPROM(pUsbCtx, (byte*)&eeprom, sizeof(UsbEEPROM), 0);
        result = apiResult(ret);
    }
    apiUnlock(ctx);
    return result;
}
SCOPEFUN_API int sfHardwareClose(SFContext* ctx)
{
    int result = SCOPEFUN_FAILURE;
    apiLock(ctx);
    if(ctx->api.active > 0)
    {
        struct UsbContext* pUsbCtx = (struct UsbContext*)ctx->usb;
        usbFxxClose(pUsbCtx);
        result = SCOPEFUN_SUCCESS;
    }
    apiUnlock(ctx);
    return result;
}

/*--------------------------------------------------------------------
   simulate
---------------------------------------------------------------------*/

SCOPEFUN_API int sfIsSimulate(SFContext* ctx)
{
    int simulate = 0;
    apiLock(ctx);
    simulate = SDL_AtomicGet((SDL_atomic_t*)&ctx->simulateOn);
    apiUnlock(ctx);
    return simulate;
}

SCOPEFUN_API int sfSetSimulateData(SFContext* ctx, SSimulate* sim)
{
    apiLock(ctx);
    ctx->simulateData = *sim;
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetSimulateOnOff(SFContext* ctx, int on)
{
    apiLock(ctx);
    SDL_AtomicSet((SDL_atomic_t*)&ctx->simulateOn, on);
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfGetSimulateData(SFContext* ctx, SSimulate* data)
{
    apiLock(ctx);
    *data = ctx->simulateData;
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}

int softwareGenerator(int frameVersion, int frameHeader, int frameData, int framePacket, SFContext* ctx, SHardware* hw, SSimulate* sim, double timer)
{
    int frameSize = sfGetFrameSize(hw);
    SDL_memset(&ctx->frame.data.data.bytes[0], 0, apiMin(sizeof(SFrameData), frameSize));
    ctx->frame.received = 0;
    // header, channel0, channel1 and digital bits
    byte* packet = &ctx->frame.data.data.bytes[0];
    SFrameHeader* header = (SFrameHeader*)packet;
    uint  numSamples  = (uint)frameData / 4;
    float numSamplesF = (float)numSamples;
    // header
    SDL_memset(header, 0, frameHeader);
    // config
    SDL_memcpy(&header->hardware.bytes[0], hw, sizeof(SHardware));
    // magic
    header->magic.bytes[0] = 0xDD;
    header->magic.bytes[1] = 0xDD;
    header->magic.bytes[2] = 0xDD;
    header->magic.bytes[3] = 0xDD;
    // frameSize
    header->hardware.bytes[32 + 0] = (numSamples >> 24) & 0xff;
    header->hardware.bytes[32 + 1] = (numSamples >> 16) & 0xff;
    header->hardware.bytes[32 + 2] = (numSamples >> 8) & 0xff;
    header->hardware.bytes[32 + 3] = (numSamples >> 0) & 0xff;
    // ets
    header->etsDelay.bytes[0] = (byte)(rand() % 32);
    if(sim->etsActive > 0)
    {
        timer = 0;
    }
    // crc
    header->crc.bytes[0] = 0;
    // analog
    for(int i = 0; i < 2; i++)
    {
        // capture
        float captureTime = sim->time * numSamplesF;
        float captureVolt = 0;
        if(i == 0)
        {
            captureVolt = sim->voltage0;
        }
        if(i == 1)
        {
            captureVolt = sim->voltage1;
        }
        // generateTime
        float generateTime = 0;
        if(i == 0)
        {
            generateTime = (float)timer * sim->speed0;
        }
        if(i == 1)
        {
            generateTime = (float)timer * sim->speed1;
        }
        // peakToPeak
        float peakToPeak = 0;
        if(i == 0)
        {
            peakToPeak = sim->peakToPeak0;
        }
        if(i == 1)
        {
            peakToPeak = sim->peakToPeak1;
        }
        // peakToPeak
        ESimulateType type = stSin;
        if(i == 0)
        {
            type = sim->type0;
        }
        if(i == 1)
        {
            type = sim->type1;
        }
        // period
        float period = 0;
        if(i == 0)
        {
            period = sim->period0;
        }
        if(i == 1)
        {
            period = sim->period1;
        }
        // min/max peak
        float minpeak = -peakToPeak / 2.f;
        float maxpeak = peakToPeak / 2.f;
        // frame size
        float displayFrameSize = numSamplesF;
        // period
        period = period * numSamplesF / NUM_SAMPLESF;
        // generate
        srand((uint)SDL_GetPerformanceCounter());
        float value = 0;
        for(uint j = 0; j < numSamples; j++)
        {
            float sample = (float)j;
            switch(type)
            {
                case stSin:
                case stCos:
                    {
                        float  normalizedTime = sample / displayFrameSize + generateTime;
                        float  signaltime = (normalizedTime * captureTime);
                        float            t = (signaltime / period);
                        float    angle2Pi = 2.f * PI * t;
                        switch(type)
                        {
                            case stSin:
                                value = maxpeak * sinf(angle2Pi);
                                break;
                            case stCos:
                                value = maxpeak * cosf(angle2Pi);
                                break;
                            default:
                                break;
                        };
                    }
                    break;
                case stDec:
                case stInc:
                    {
                        float  normalizedTime = sample / displayFrameSize + generateTime;
                        float  normalizedPeriod = period / captureTime;
                        float mod = fmodf(normalizedTime, normalizedPeriod);
                        float div = mod / (normalizedPeriod);
                        switch(type)
                        {
                            case stInc:
                                value = div * peakToPeak + minpeak;
                                break;
                            case stDec:
                                value = (1.f - div) * peakToPeak + minpeak;
                                break;
                            default:
                                break;
                        };
                    }
                    break;
                case stConstant:
                    value = peakToPeak;
                    break;
                case stRandom:
                    value = rand_FloatRange(-1.f, 1.f) * (peakToPeak / 2.f);
                    break;
                case stSquare:
                    {
                        float  normalizedTime = sample / displayFrameSize + generateTime;
                        float  normalizedPeriod = period / captureTime;
                        float  time = fmodf(normalizedTime, 1.0f);
                        if(time < normalizedPeriod)
                        {
                            value = peakToPeak;
                        }
                        else
                        {
                            value = 0.f;
                        }
                    }
                    break;
                case stDelta:
                    {
                        float  normalizedTime = sample / displayFrameSize + generateTime;
                        float  normalizedPeriod = period / captureTime;
                        float  time = fmodf(normalizedTime, 1.0f);
                        float      t = time / normalizedPeriod / 2.f;
                        if(time < normalizedPeriod / 2.f)
                        {
                            value = 4.0f * t * peakToPeak;
                        }
                        else if(time < normalizedPeriod)
                        {
                            value = 4.0f * (0.5f - t) * peakToPeak;
                        }
                        else
                        {
                            value = 0.f;
                        }
                    }
                    break;
            };
            float normalized = value / (5.f * captureVolt);
            normalized = fClamp(normalized, -1.0f, 1.0f);
            ishort ival = (ishort)(normalized * MAXOSCVALUE);
            byte*  data = packet + frameHeader + j * 4;
            byte* byte0 = (byte*)(data + 0);
            byte* byte1 = (byte*)(data + 1);
            byte* byte2 = (byte*)(data + 2);
            byte* byte3 = (byte*)(data + 3);
            uint val = ival & 0x1FF;
            if(ival < 0)
            {
                val |= 0x200;
            }
            if(i == 0)
            {
                ishort shifted0 = (val >> 2);
                *byte0 = *byte0 | (byte)(shifted0);
                *byte1 = *byte1 | (byte)(val & 0x3);
                *byte1 = (*byte1 << 6);
            }
            if(i == 1)
            {
                ishort shifted1 = (val >> 4);
                *byte1 = *byte1 | (byte)(shifted1);
                *byte2 = *byte2 | (byte)(val & 0xF);
                *byte2 = (*byte2 << 4);
            }
        }
    }
    // digital
    srand((uint)SDL_GetPerformanceCounter());
    int r = rand();
    for(uint i = 0; i < numSamples; i++)
    {
        byte digital0 = (r + 0) % 2;
        byte digital1 = (r + 1) % 2;
        byte digital2 = (r + 2) % 2;
        byte digital3 = (r + 3) % 2;
        byte digital4 = (r + 4) % 2;
        byte digital5 = (r + 5) % 2;
        byte digital6 = (r + 6) % 2;
        byte digital7 = (r + 7) % 2;
        byte digital8 = (r + 8) % 2;
        byte digital9 = (r + 9) % 2;
        byte digital10 = (r + 10) % 2;
        byte digital11 = (r + 11) % 2;
        byte digital12 = (r + 12) % 2;
        byte digital13 = (r + 13) % 2;
        byte digital14 = (r + 14) % 2;
        byte digital15 = (r + 15) % 2;
        ushort bits = digital0 | (digital1 << 1) | (digital2 << 2) | (digital3 << 3) | (digital4 << 4) | (digital5 << 5) | (digital6 << 6) | (digital7 << 7);
        bits |= digital8 << 8 | (digital9 << 9) | (digital10 << 10) | (digital11 << 11) | (digital12 << 12) | (digital13 << 13) | (digital14 << 14) | (digital15 << 15);
        byte* byte0 = (byte*)(packet + frameHeader + i * 4 + 0);
        byte* byte1 = (byte*)(packet + frameHeader + i * 4 + 1);
        byte* byte2 = (byte*)(packet + frameHeader + i * 4 + 2);
        byte* byte3 = (byte*)(packet + frameHeader + i * 4 + 3);
        *byte2 = *byte2 | (byte)(bits >> 12);
        *byte3 = *byte3 | (byte)(bits >> 4);
    }
    return 0;
}

SCOPEFUN_API int sfSimulate(SFContext* ctx, SHardware* hw, SInt* received, SInt* frameSize, float time)
{
    apiLock(ctx);
    int simulate = SDL_AtomicGet((SDL_atomic_t*)&ctx->simulateOn);
    if(simulate > 0)
    {
        int numSamples       = sfGetNumSamples(hw);
        received->value      = sfGetFrameSize(hw);
        frameSize->value     = sfGetFrameSize(hw);;
        ctx->frame.received  = received->value;
        ctx->frame.frameSize = frameSize->value;
        softwareGenerator(HARDWARE_VERSION, SCOPEFUN_FRAME_HEADER, numSamples * 4, SCOPEFUN_FRAME_PACKET, ctx, hw, &ctx->simulateData, time);
    }
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}

/*--------------------------------------------------------------------
   Frame
---------------------------------------------------------------------*/
SCOPEFUN_API int sfFrameCapture(SFContext* ctx, SInt* received, SInt* frameSize)
{
    apiLock(ctx);

    // header
    if(ctx->frame.received < SCOPEFUN_FRAME_HEADER)
    {
        int transfered = 0;
        int  ret = sfHardwareCapture(ctx, &ctx->frame.data, SCOPEFUN_FRAME_HEADER, ctx->frame.received, (SInt*)&transfered);
        ctx->frame.received += transfered;
        ctx->frame.frameSize = SCOPEFUN_FRAME_HEADER;
    }
    // data
    if(ctx->frame.received >= SCOPEFUN_FRAME_HEADER)
    {
        SHardware hw = { 0 };
        sfGetHeaderHardware(ctx, (SFrameHeader*)&ctx->frame.data.data.bytes[0], &hw);
        ctx->frame.frameSize = sfGetFrameSize(&hw);
        int         transfered = 0;
        int frameLeftToReceive = (int)ctx->frame.frameSize - (int)ctx->frame.received;
        if(frameLeftToReceive > 0)
        {
            int  ret = sfHardwareCapture(ctx, &ctx->frame.data, frameLeftToReceive, ctx->frame.received, (SInt*)&transfered);
            ctx->frame.received += transfered;
        }
    }
    frameSize->value = ctx->frame.frameSize;
    received->value  = ctx->frame.received;
    // new frame ?
    if(ctx->frame.received == ctx->frame.frameSize)
    { ctx->frame.received = 0; }
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfFrameOutput(SFContext* ctx, SFrameData* buffer, int len)
{
    apiLock(ctx);
    SDL_memcpy(&buffer->data.bytes[0], &ctx->frame.data.data.bytes[0], iMin(ctx->frame.frameSize, len));
    apiUnlock(ctx);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfFrameDisplayFunction(SFContext* ctx, EFunctionType fun)
{
    ctx->functionType = fun;
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfFrameDisplayCallback(SFContext* ctx, SCallback* callback, void* userData)
{
    ctx->pCallback = callback;
    ctx->pUserData = userData;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int cDisplayFunction(SFContext* ctx,EFunctionType function, ushort channel0, ushort channel1, ushort digital)
{
    switch(function)
    {
        case dfMax:
            return uMin(channel0, channel1);
        case dfMin:
            return uMin(channel0, channel1);
        case dfMedium:
            return (channel0 + channel1) / 2;
        case dfAdd:
            return channel0 + channel1;
        case dfCh0SubCh1:
            return channel0 - channel1;
        case dfCh1SubCh0:
            return channel1 - channel0;
        case dfScript:
            if (ctx->pCallback)
            {
               ishort func = 0;
               ((SCallback*)ctx->pCallback)->onFunction(channel0, channel1, &func);
               return func;
            }
    }
    return 0;
}

SCOPEFUN_API int sfFrameDisplay(SFContext* ctx, SFrameData* buffer, int len, SDisplay* display, float displayPos, float displayZoom)
{
    // hardware
    SHardware hw = { 0 };
    sfGetHeaderHardware(ctx, (SFrameHeader*)&buffer->data.bytes[0], &hw);
    // samples
    uint numSamples = sfGetNumSamples(&hw);
    if(numSamples == 0) { return 1; }
    if(numSamples > SCOPEFUN_FRAME_DATA / 4) { return 1; }

    uint lenSamples = 0;
    if( len >= SCOPEFUN_FRAME_HEADER )
      lenSamples = (len - SCOPEFUN_FRAME_HEADER) / 4;

    // init display
    SDL_memset(display, 0, sizeof(SDisplay));
    display->samples = SCOPEFUN_DISPLAY;
    display->capture = numSamples;
    // frame size
    uint frameSize = sfGetFrameSize(&hw);
    if(frameSize > SCOPEFUN_FRAME_MEMORY) { return 1; }
    // ets
    sfGetHeaderEts((SFrameHeader*)&buffer->data.bytes[0], &display->ets);
    // attr
    ushort analogSwitch = sfGetAnalogSwitch(&hw);
    display->attr |= (analogSwitch & CHANNEL_ETS) ? daETS : 0;
    // resample
    double resamplePos = displayPos  + 0.5;
    double resampleMin = resamplePos - 0.5 * (double)displayZoom;
    double resampleMax = resamplePos + 0.5 * (double)displayZoom;
    // sample: min / max
    double dNumSamples     = numSamples;
    ilarge zoomSampleMin   = resampleMin * (dNumSamples - 1); // [0..n]
    ilarge zoomSampleMax   = resampleMax * (dNumSamples - 1); // [0..n]
    ilarge zoomSampleCnt   = ilClamp(zoomSampleMax - zoomSampleMin + 1, 0, numSamples - 1); // [0..n]
    // samples
    EFunctionType function = dfMedium;
    if(frameSize > 0 && numSamples > 0)
    {
        if(ctx->pCallback)
        { ((SCallback*)ctx->pCallback)->onFrame(buffer, len, &displayPos, &displayZoom, ctx->pUserData); }
        byte*          dataStart = &buffer->data.bytes[SCOPEFUN_FRAME_HEADER];
        ilarge      intervalCount = (SCOPEFUN_DISPLAY / 2);
        double dPointsPerInterval = zoomSampleCnt / (double)intervalCount;
        uint   lPointsPerInterval = (uint)SDL_ceil(dPointsPerInterval);
        if(lPointsPerInterval > 2)
        {
            for(ilarge i = 0; i < intervalCount; i++)
            {
                ishort  ch0Min = SCOPEFUN_MAX_VOLTAGE;
                ishort  ch0Max = SCOPEFUN_MIN_VOLTAGE;
                ishort  ch1Min = SCOPEFUN_MAX_VOLTAGE;
                ishort  ch1Max = SCOPEFUN_MIN_VOLTAGE;
                ishort  funMin = SCOPEFUN_MAX_VOLTAGE;
                ishort  funMax = SCOPEFUN_MIN_VOLTAGE;
                ushort  digMin = 0;
                ushort  digMax = 1;
                for(ilarge j = 0; j < lPointsPerInterval; j++)
                {
                    uint offset = 0;
                    ushort  ch0 = 0;
                    ushort  ch1 = 0;
                    ushort  dig = 0;
                    ularge index  = i * lPointsPerInterval + j;

                    if ((zoomSampleMin + index) > lenSamples)
                       break;

                    ularge sample = iClamp(zoomSampleMin + index, 0, numSamples - 1);
                    offset = sample * 4;
                    byte byte0 = *(dataStart + offset + 0);
                    byte byte1 = *(dataStart + offset + 1);
                    byte byte2 = *(dataStart + offset + 2);
                    byte byte3 = *(dataStart + offset + 3);
                    //ch0 |= byte0;
                    //ch0 = ch0 << 2;
                    //ch0 |= ((byte1 >> 6) & 0x3F);
                    //ch1 |= (byte1 & 0x3F);
                    //ch1 = ch1 << 4;
                    //ch1 |= ((byte2 >> 4) & 0xF);
                    //dig |= (byte2 & 0xF);
                    //dig = dig << 8;
                    //dig |= byte3;

                  /*  ishort ich0 = leadBitShift(ch0 & 0x000003FF);
                    ishort ich1 = leadBitShift(ch1 & 0x000003FF);*/

                     ishort ich0 = 0;
                     ishort ich1 = 0;

                    sfGetData((uint)byte0 | ((uint)byte1 << 8)| ((uint)byte2 << 16) | ((uint)byte3 << 24), &ich0, &ich1, &dig);

                    ishort fun = cDisplayFunction(ctx, ctx->functionType, ch0, ch1, dig);
                    if(ctx->pCallback)
                    { ((SCallback*)ctx->pCallback)->onSample(sample, &ich0, &ich1, &fun, &dig, &displayPos, &displayZoom, ctx->pUserData); }
                    ch0Min = iMin(ich0, ch0Min);
                    ch0Max = iMax(ich0, ch0Max);
                    ch1Min = iMin(ich1, ch1Min);
                    ch1Max = iMax(ich1, ch1Max);
                    digMin = iMin(dig, digMin);
                    digMax = iMax(dig, digMax);
                    funMin = cDisplayFunction(ctx,ctx->functionType, ch0Min, ch1Min, digMin);
                    funMax = cDisplayFunction(ctx,ctx->functionType, ch0Max, ch1Max, digMax);
                }
                // floats Min
                float fChannel0Min = fClamp((float)ch0Min / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                float fChannel1Min = fClamp((float)ch1Min / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                float fFunctionMin = fClamp((float)funMin / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                // floats Max
                float fChannel0Max = fClamp((float)ch0Max / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                float fChannel1Max = fClamp((float)ch1Max / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                float fFunctionMax = fClamp((float)funMax / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                // output :
                display->analog0.bytes[i * 2 + 0] = fChannel0Min;
                display->analog0.bytes[i * 2 + 1] = fChannel0Max;
                display->analog1.bytes[i * 2 + 0] = fChannel1Min;
                display->analog1.bytes[i * 2 + 1] = fChannel1Max;
                display->digital.bytes[i * 2 + 0] = digMin;
                display->digital.bytes[i * 2 + 1] = digMax;
                display->analogF.bytes[i * 2 + 0] = funMin;
                display->analogF.bytes[i * 2 + 1] = funMax;
            }
            if(ctx->pCallback)
            { ((SCallback*)ctx->pCallback)->onDisplay(display, &displayPos, &displayZoom, ctx->pUserData); }
        }
        else
        {
            for(ilarge i = 1; i <= zoomSampleCnt; i++)
            {
                if (i > lenSamples)
                  break;

                uint offset = 0;
                ushort  ch0 = 0;
                ushort  ch1 = 0;
                ushort  dig = 0;
                ilarge sample = iClamp(zoomSampleMin + i, 0, numSamples - 1);
                offset = sample * 4;
                byte byte0 = *(dataStart + offset + 0);
                byte byte1 = *(dataStart + offset + 1);
                byte byte2 = *(dataStart + offset + 2);
                byte byte3 = *(dataStart + offset + 3);
                //ch0 |= byte0;
                //ch0 = ch0 << 2;
                //ch0 |= ((byte1 >> 6) & 0x3F);
                //ch1 |= (byte1 & 0x3F);
                //ch1 = ch1 << 4;
                //ch1 |= ((byte2 >> 4) & 0xF);
                //dig |= (byte2 & 0xF);
                //dig = dig << 8;
                //dig |= byte3;
                // channels
               /* ishort channel0 = leadBitShift(ch0 & 0x000003FF);
                ishort channel1 = leadBitShift(ch1 & 0x000003FF);*/

                ishort channel0 = 0;
                ishort channel1 = 0;

                sfGetData((uint)byte0 | ((uint)byte1 << 8) | ((uint)byte2 << 16) | ((uint)byte3 << 24), &channel0, &channel1, &dig);

                ushort digital = dig;
                ushort function = cDisplayFunction(ctx,ctx->functionType, channel0, channel1, digital);
                if(ctx->pCallback)
                { ((SCallback*)ctx->pCallback)->onSample(sample, &channel0, &channel1, &function, &digital, &displayPos, &displayZoom, ctx->pUserData); }
                // floats
                float fChannel0 = fClamp((float)channel0 / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                float fChannel1 = fClamp((float)channel1 / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                float fFunction = fClamp((float)function / (float)SCOPEFUN_MAX_VOLTAGE, -1.f, 1.f);
                // start, end, count
                ularge start = sample > 0 ? sample - 1 : sample;
                ularge end = sample;
                // normalize
                double nStart  = (double)(start - zoomSampleMin) / (double)(zoomSampleCnt); // [0...1]
                double nEnd    = (double)(end - zoomSampleMin) / (double)(zoomSampleCnt); // [0...1]
                // index
                ularge iStart = SDL_floor(nStart * (double)(SCOPEFUN_DISPLAY - 1));
                ularge   iEnd = SDL_floor(nEnd * (double)(SCOPEFUN_DISPLAY - 1));
                // Output:
                // Display full interval not only single sample.
                // That is becouse we can zoom to single sample.
                for(ularge k = iStart; k <= iEnd; k++)
                {
                    int displayIndex = iClamp(k, 0, SCOPEFUN_DISPLAY - 1);
                    display->analog0.bytes[displayIndex] = fChannel0;
                    display->analog1.bytes[displayIndex] = fChannel1;
                    display->digital.bytes[displayIndex] = digital;
                    display->analogF.bytes[displayIndex] = function;
                }
            }
            if(ctx->pCallback)
            { ((SCallback*)ctx->pCallback)->onDisplay(display, &displayPos, &displayZoom, ctx->pUserData); }
        }
    }
    return SCOPEFUN_SUCCESS;
}

/*--------------------------------------------------------------------------------
   Header
--------------------------------------------------------------------------------*/
SCOPEFUN_API int sfGetHeader(SFContext* ctx, SFrameData* frame, SFrameHeader* header)
{
    SDL_memcpy(header, &frame->data.bytes[0], sizeof(SFrameHeader));
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfGetHeaderHardware(SFContext* ctx, SFrameHeader* header, SHardware* hw)
{
    SDL_memcpy(hw, &header->hardware.bytes[0], sizeof(SHardware));
    uint         count = sizeof(SHardware) / 2;
    ushort* swapBuffer = (ushort*)hw;
    for(int i = 0; i < count; i++)
    {
        swapBuffer[i] = cSwap16(&swapBuffer[i]);
    }
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfGetHeaderEts(SFrameHeader* header, uint* ets)
{
    *ets = header->etsDelay.bytes[7];
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfGetHeaderTemperature(SFrameHeader* header, SFloat* temperature)
{
    byte* ptr = (byte*)&header->magic.bytes[0];
    unsigned short adc0 = (ptr)[6] << 8;
    unsigned short adc1 = (ptr)[7];
    unsigned short adc = adc1 | adc0;
    temperature->value = (((float)adc * 503.975) / 4096.0) - 273.15;
    return SCOPEFUN_SUCCESS;
}

/*--------------------------------------------------------------------------------
  Hardware
--------------------------------------------------------------------------------*/
char* hardwareIds[] =
{
    "controlAddr",
    "controlData",
    "vgaina",
    "vgainb",
    "offseta",
    "offsetb",
    "analogswitch",
    "triggerMode",
    "triggerSource",
    "triggerSlope",
    "triggerLevel",
    "triggerHis",
    "triggerPercent",
    "xRange",
    "holdoffH",
    "holdoffL",
    "sampleSizeH",
    "sampleSizeL",
    "generatorType0",
    "generatorVoltage0",
    "generatorOffset0",
    "generatorDeltaH0",
    "generatorDeltaL0",
    "generatorSqueareDuty0",
    "generatorType1",
    "generatorVoltage1",
    "generatorOffset1",
    "generatorDeltaH1",
    "generatorDeltaL1",
    "generatorSqueareDuty1",
    "digitalPattern1a",
    "digitalPattern1b",
    "digitalMask1",
    "digitalPattern2a",
    "digitalPattern2b",
    "digitalMask2",
    "digitalPattern3a",
    "digitalPattern3b",
    "digitalMask3",
    "digitalPattern4a",
    "digitalPattern4b",
    "digitalMask4",
    "dt_delayMaxcnt1",
    "dt_delayMaxcnt2",
    "dt_delayMaxcnt3",
    "dt_delayMaxcnt4",
    "dt_control",
    "digitalVoltage",
    "digitalInputOutput",
    "digitalOutputBit",
    "digitalOutputMask",
    "digitalClkDivideH",
    "digitalClkDivideL",
    "average",
    "reserved2",
    "reserved3",
    "reserved4",
    "reserved5",
    "reserved6",
};

SCOPEFUN_API int sfHardwareWordCnt(int* cnt)
{
    *cnt = sizeof(hardwareIds) / sizeof(char*);
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfHardwareWordId(int index, SArrayString256* string)
{
    index = iMax(index, 0);
    index = iMin(index, sizeof(hardwareIds));
    SDL_memcpy(string->bytes, (void*)hardwareIds[index], SDL_strlen(hardwareIds[index]));
    return SCOPEFUN_SUCCESS;
}

/*--------------------------------------------------------------------------------
  Data
--------------------------------------------------------------------------------*/
ushort twos_complement(ushort input_value, ushort num_bits)
{
    ushort mask = 1 << (num_bits - 1);
    return -(input_value & mask) + (input_value & ~mask);
}

uint endianSwap123(uint value)
{
    uint v0 = (value & 0x000000FF);
    uint v1 = (value & 0x0000FF00);
    uint v2 = (value & 0x00FF0000);
    uint v3 = (value & 0xFF000000);
    return (v0 >> 24) | (v1 >> 4) | (v2 << 4) | (v3 << 24);
}

uint reverseBits(uint v)
{
    // Bit Twiddling Hacks
    uint r = v;
    int s = sizeof(v) * 8 - 1;
    for(v >>= 1; v; v >>= 1)
    {
        r <<= 1;
        r |= v & 1;
        s--;
    }
    r <<= s;
    return r;
}

uint rotateBits(uint x, uint n)
{
    uint r = (x << n) | (x >> (-n & 31));
    return r;
}

byte reverseByte(byte v)
{
    byte r = v & 1; // r will be reversed bits of v; first get LSB of v
    int s = sizeof(v) * 8 - 1; // extra shift needed at end
    for(v >>= 1; v; v >>= 1)
    {
        r <<= 1;
        r |= v & 1;
        s--;
    }
    r <<= s; // shift when v's highest bits are zero
    return r;
}

uint setBits(uint channel0, uint channel1, uint digital)
{
    // result
    uint r = 0;
    // input
    uint ch0 = channel0 & 0x03ff;
    uint ch1 = channel1 & 0x03ff;
    uint dig = digital  & 0x0fff;
    // ch 0
    byte  b0 = (ch0 & 0x00ff);
    byte  b1 = (ch0 & 0xff00) >> 8;
    byte  lo = (b0 & 0x03) << 6;
    byte  me = (b0 >> 2) & 0x3F;
    byte  hi = (b1 << 6) & 0xC0;
    uint uLo = lo;
    uLo <<= 8;
    uint uMe = me;
    uint uHi = hi;
    r |= (uLo | uMe | uHi);
    // ch 1
    b0 = (ch1 & 0x00ff);
    b1 = (ch1 & 0xff00) >> 8;
    lo = (b0 & 0x0f) << 4;
    me = (b0 >> 4) & 0x0F;
    hi = (b1 << 4) & 0x30;
    uLo = lo;
    uLo <<= 16;
    uMe = me;
    uMe <<= 8;
    uHi = hi;
    uHi <<= 8;
    r |= (uLo | uMe | uHi);
    // digital
    b0 = (dig & 0x00ff);
    b1 = (dig & 0xff00) >> 8;
    lo =  b0 & 0xff;
    hi =  b1 & 0x0f;
    uLo = lo;
    uLo <<= 24;
    uHi = hi;
    uHi <<= 16;
    r |= (uLo | uHi);
    return r;
    // ch 1
    //b0 = (ch1 & 0x00ff);
    //b1 = (ch1 & 0xff00) >> 8;
    //r0 = b1;
    //r1 = reverseByte(b0);
    //r2 = reverseByte(b0 & 0x03);
    //u0 = r0;
    //u1 = r1;
    //u2 = r2;
    //r = u0 | u1 | (u2 >> 8);
    // ch 1
    //r |= (channel0 & rotateBits(1 , 0)) >> 2;
    //r |= (channel0 & rotateBits(1 , 1)) >> 2;
    //r |= (channel0 & rotateBits(1 , 2)) >> 2;
    //r |= (channel0 & rotateBits(1 , 3)) >> 2;
    //r |= (channel0 & rotateBits(1 , 4)) >> 2;
    //r |= (channel0 & rotateBits(1 , 5)) >> 2;
    //r |= (channel0 & rotateBits(1 , 6)) >> 2;
    //r |= (channel0 & rotateBits(1 , 7)) >> 2;
    //r |= (channel0 & rotateBits(1 , 8)) >> 2;
    //r |= (channel0 & rotateBits(1 , 9)) >> 2;
    //// ch 1
    //r |= ((channel1 & rotateBits(1 , 0)) << 10);
    //r |= ((channel1 & rotateBits(1 , 1)) << 10);
    //r |= ((channel1 & rotateBits(1 , 2)) << 10);
    //r |= ((channel1 & rotateBits(1 , 3)) << 10);
    //r |= ((channel1 & rotateBits(1 , 4)) << 10);
    //r |= ((channel1 & rotateBits(1 , 5)) << 10);
    //r |= ((channel1 & rotateBits(1 , 6)) << 10);
    //r |= ((channel1 & rotateBits(1 , 7)) << 10);
    //r |= ((channel1 & rotateBits(1 , 8)) << 10);
    //r |= ((channel1 & rotateBits(1 , 9)) << 10);
    //
    //return r;
}

SCOPEFUN_API int sfSetData(byte* ptr, ishort channel0, ishort channel1, ushort digital)
{
    //uint ch0 = channel0 & 0x03ff;
    //uint ch1 = channel1 & 0x03ff;
    //uint dig = digital  & 0x0fff;
    //uint data = 0;
    //// ch0
    //byte loCh0 = (ch0 & 0xff)  << 6;
    //byte miCh0 = (ch0 & 0xff)  >> 2;
    //byte hiCh0 = (ch0 & 0x300) >> 8;
    //     data |= (loCh0 >> 8);
    //     data |= miCh0;
    //     data |= hiCh0;
    //// ch1
    //uint b0Ch1 =  ch1 & 0xff;
    //uint b1Ch1 = (ch1 & 0x300) >> 8;
    //     b0Ch1 = (b0Ch1 >> 12);
    //     b1Ch1 = (b1Ch1 >> 4);
    //     data |= b0Ch1;
    //     data |= b1Ch1;
    // dig
    //uint b0Dig =  dig & 0xff;
    //uint b1Dig = (dig & 0xF00) >> 8;
    //     data |= (b0Dig >> 24) | (b1Dig >> 16);
    uint data = setBits(channel0, channel1, digital);
    ishort iCh0 = 0;
    ishort iCh1 = 0;
    ushort iDig = 0;
    sfGetData(data, &iCh0, &iCh1, &iDig);
    *(uint*)ptr = data;
    return SCOPEFUN_SUCCESS;
}
SCOPEFUN_API int sfGetData(uint data, ishort* channel0, ishort* channel1, ushort* digital)
{
    byte* dataStart = (byte*)&data;
    ushort  ch0 = 0;
    ushort  ch1 = 0;
    ushort  dig = 0;
    byte byte0 = *(dataStart + 0);
    byte byte1 = *(dataStart + 1);
    byte byte2 = *(dataStart + 2);
    byte byte3 = *(dataStart + 3);
    ch0 |= byte0;
    ch0 = ch0 << 2;
    ch0 |= ((byte1 >> 6) & 0x3F);
    ch1 |= (byte1 & 0x3F);
    ch1 = ch1 << 4;
    ch1 |= ((byte2 >> 4) & 0xF);
    dig |= (byte2 & 0xF);
    dig  = dig << 8;
    dig |= byte3;
    *channel0 = leadBitShift(ch0 & 0x000003FF);
    *channel1 = leadBitShift(ch1 & 0x000003FF);
    *digital  = dig;
    return SCOPEFUN_SUCCESS;
}

/*--------------------------------------------------------------------------------
  Set
--------------------------------------------------------------------------------*/

SCOPEFUN_API int sfSetDefault(SHardware* hw)
{
    SDL_memset(hw, 0, sizeof(SHardware));
    hw->controlAddr = 0x000D;
    hw->controlData = CONTROLL2_NORMAL;
    hw->vgaina = 0xff25;
    hw->vgainb = 0xff25;
    hw->sampleSizeH = 0;
    hw->sampleSizeL = SCOPEFUN_DISPLAY;
    sfSetXRange(hw, 1);
    sfSetGeneratorType0(hw, GENERATOR_SIN);
    sfSetGeneratorVoltage0(hw, 1);
    sfSetGeneratorFrequency0(hw, 50.f, 457142.81f);
    sfSetGeneratorType1(hw, GENERATOR_SIN);
    sfSetGeneratorFrequency1(hw, 50.f, 457142.81f);
    sfSetGeneratorVoltage1(hw, 1);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetFrameSize(SHardware*  hw, uint  frameSize)
{
    uint   dataSize = frameSize - SCOPEFUN_FRAME_HEADER;
    uint numSamples = dataSize / 4;
    hw->sampleSizeL =         numSamples & 0x0000ffff;
    hw->sampleSizeH = (numSamples >> 16) & 0x0000ffff;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetNumSamples(SHardware* hw, uint  numSamples)
{
    hw->sampleSizeL = numSamples & 0x0000ffff;
    hw->sampleSizeH = (numSamples >> 16) & 0x0000ffff;
    return SCOPEFUN_SUCCESS;
}


SCOPEFUN_API int sfSetAnalogSwitchBit(SHardware* hw, int bit, int value)
{
    hw->analogswitch ^= ((~value + 1) ^ hw->analogswitch) & bit;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetEts(SHardware* hw, int enable)
{
    if(enable) { hw->analogswitch = raiseFlag16(hw->analogswitch, CHANNEL_ETS); }
    else        { hw->analogswitch = lowerFlag16(hw->analogswitch, CHANNEL_ETS); }
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetYRangeScaleA(SHardware* hw, ushort attr, ushort gain)
{
    if(attr) { hw->analogswitch = raiseFlag16(hw->analogswitch, CHANNEL_ATTR_A); }
    else      { hw->analogswitch = lowerFlag16(hw->analogswitch, CHANNEL_ATTR_A); }
    hw->vgaina = gain;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetYPositionA(SHardware* hw, int pos)
{
    pos = iMin(pos,  1500);
    pos = iMax(pos, -1500);
    hw->offseta = pos;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetYRangeScaleB(SHardware* hw, ushort attr, ushort gain)
{
    if(attr) { hw->analogswitch = raiseFlag16(hw->analogswitch, CHANNEL_ATTR_B); }
    else      { hw->analogswitch = lowerFlag16(hw->analogswitch, CHANNEL_ATTR_B); }
    hw->vgainb = gain;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetYPositionB(SHardware* hw, int pos)
{
    pos = iMin(pos,  1500);
    pos = iMax(pos, -1500);
    hw->offsetb = pos;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetXRange(SHardware* hw, ishort range)
{
    // 2ns is interleaved
    if(range == 0) { hw->analogswitch = raiseFlag16(hw->analogswitch, CHANNEL_INTERLEAVE); }
    else            { hw->analogswitch = lowerFlag16(hw->analogswitch, CHANNEL_INTERLEAVE); }
    hw->xRange = range;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetControl(SHardware* hw, uint selected)
{
    switch(selected)
    {
        case 0:
            hw->controlData = CONTROLL2_NORMAL;
            break;
        case 1:
            hw->controlData = CONTROLL2_TEST;
            break;
        case 3:
            hw->controlData = CONTROLL2_RESET;
            break;
    };
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetSampleSize(SHardware* hw, uint value)
{
    value = uMin(value, (SCOPEFUN_FRAME_DATA / 4));
    uint size = 4 * (value / 4);
    value = uMax(256U, size);
    hw->sampleSizeH = (value >> 16) & 0xFFFF;
    hw->sampleSizeL = (value & 0xFFFF);
    return SCOPEFUN_SUCCESS;
}


SCOPEFUN_API int  sfSetTriggerSource(SHardware* hw, int value)
{
    hw->triggerSource = value;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetTriggerReArm(SHardware* hw, int on)
{
    ushort mask = (1 << 2);
    if(on)
    {
        hw->triggerMode = hw->triggerMode | mask;
    }
    else
    {
        hw->triggerMode = hw->triggerMode & ~mask;
    }
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetTriggerMode(SHardware* hw, int value)
{
    hw->triggerMode = value;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetTriggerSlope(SHardware* hw, int value)
{
    hw->triggerSlope = value;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetTriggerPre(SHardware* hw, float perc)
{
    uint numSamples = (((uint)hw->sampleSizeH) << 16) | (uint)hw->sampleSizeL;
    hw->triggerPercent = (perc / 100.f) * (float)(numSamples - 1) / 2048;
    hw->triggerPercent = 4 * (hw->triggerPercent / 4);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetTriggerHis(SHardware* hw, int perc)
{
    hw->triggerHis = perc;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetTriggerLevel(SHardware* hw, int perc)
{
    hw->triggerLevel = perc;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetHoldoff(SHardware* hw, uint holdoff)
{
    hw->holdoffH = (holdoff & 0xFFFF0000) >> 16;
    hw->holdoffL = holdoff & 0x0000FFFF;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetAverage(SHardware* hw, int enable)
{
    hw->average = enable;
    return SCOPEFUN_SUCCESS;
}

/*--------------------------------------------------------------------------------
   generator 0
--------------------------------------------------------------------------------*/

SCOPEFUN_API int sfSetGeneratorType0(SHardware* hw, ushort type)
{
    uint mask = 1 << 8;
    if(hw->generatorType0 & mask)
    {
        hw->generatorType0 = type | mask;
    }
    else
    {
        hw->generatorType0 = type;
    }
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetGeneratorOn0(SHardware* hw, int onoff)
{
    uint mask = 1 << 8;
    if(onoff)
    {
        hw->generatorType0 = hw->generatorType0 | mask;
    }
    else
    {
        hw->generatorType0 = hw->generatorType0 & ~mask;
    }
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetGeneratorSlope0(SHardware* hw, int onoff)
{
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetGeneratorVoltage0(SHardware* hw, int volt)
{
    uint voltage = volt;
    uint mask = 1 << 12;
    if(hw->generatorVoltage0 & mask)
    {
        hw->generatorVoltage0 = voltage | mask;
    }
    else
    {
        hw->generatorVoltage0 = voltage;
    }
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetGeneratorOffset0(SHardware* hw, int perc)
{
    hw->generatorOffset0 = perc;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetGeneratorFrequency0(SHardware* hw, float freq, float fs)
{
    double delta = 0;
    uint mask = (1 << 8);
    mask = ~mask;
    uint type = hw->generatorType0 & mask;
    switch(type)
    {
        case GENERATOR_CUSTOM:
        case GENERATOR_SIN:
        case GENERATOR_COS:
        case GENERATOR_TRIANGLE:
        case GENERATOR_RAMP_UP:
        case GENERATOR_RAMP_DOWN:
        case GENERATOR_SQUARE:
        case GENERATOR_DELTA:
        case GENERATOR_DC:
        case GENERATOR_NOISE:
            delta = 65536.0 * (double)freq / (double)fs;
            break;
    };
    uint gDelta = (uint)(delta * 131071.0);
    hw->generatorDeltaH0 = (gDelta & 0xFFFF0000) >> 16;
    hw->generatorDeltaL0 = gDelta & 0x0000FFFF;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetGeneratorSquareDuty0(SHardware* hw, float perc)
{
    hw->generatorSqueareDuty0 = perc * 2047.0 / 100.0;
    return SCOPEFUN_SUCCESS;
}

/*--------------------------------------------------------------------------------
   generator 1
--------------------------------------------------------------------------------*/

SCOPEFUN_API int  sfSetGeneratorType1(SHardware* hw, ushort type)
{
    uint mask = 1 << 8;
    if(hw->generatorType1 & mask)
    {
        hw->generatorType1 = type | mask;
    }
    else
    {
        hw->generatorType1 = type;
    }
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetGeneratorOn1(SHardware* hw, int onoff)
{
    uint mask = 1 << 8;
    if(onoff)
    {
        hw->generatorType1 = hw->generatorType1 | mask;
    }
    else
    {
        hw->generatorType1 = hw->generatorType1 & ~mask;
    }
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetGeneratorSlope1(SHardware* hw, int onoff)
{
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetGeneratorVoltage1(SHardware* hw, int volt)
{
    uint voltage = volt;
    uint mask = 1 << 12;
    if(hw->generatorVoltage1 & mask)
    {
        hw->generatorVoltage1 = voltage | mask;
    }
    else
    {
        hw->generatorVoltage1 = voltage;
    }
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetGeneratorOffset1(SHardware* hw, int perc)
{
    hw->generatorOffset1 = perc;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetGeneratorFrequency1(SHardware* hw, float freq, float fs)
{
    double delta = 0;
    uint mask = (1 << 8);
    mask = ~mask;
    uint type = hw->generatorType1 & mask;
    switch(type)
    {
        case GENERATOR_CUSTOM:
        case GENERATOR_SIN:
        case GENERATOR_COS:
        case GENERATOR_TRIANGLE:
        case GENERATOR_RAMP_UP:
        case GENERATOR_RAMP_DOWN:
        case GENERATOR_SQUARE:
        case GENERATOR_DELTA:
        case GENERATOR_DC:
        case GENERATOR_NOISE:
            delta = 65536.0 * (double)freq / (double)fs;
            break;
    };
    //
    uint gDelta = (uint)(delta * 131071.0);
    hw->generatorDeltaH1 = (gDelta & 0xFFFF0000) >> 16;
    hw->generatorDeltaL1 = gDelta & 0x0000FFFF;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetGeneratorSquareDuty1(SHardware* hw, float perc)
{
    hw->generatorSqueareDuty1 = perc * 2047.0 / 100.0;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetDigitalVoltage(SHardware* hw, double volt, double kDigital)
{
    double Vmin = 1.25 * ((0.0 / kDigital) + 1.0);
    double Vmax = 1.25 * ((255.0 / kDigital) + 1.0);
    double dVolt = dClamp((double)volt, Vmin, Vmax);
    hw->digitalVoltage = (ushort)(((dVolt / 1.25) - 1.0) * kDigital);
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetDigitalInputOutput(SHardware* hw, int inout15, int inout7)
{
    // 00 = OUT, OUT
    // 01 = OUT, IN
    // 10 = IN, OUT
    // 11 = IN, IN
    hw->digitalInputOutput = (inout15 << 1) | inout7;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetDigitalOutputBit(SHardware* hw, int bit, int onoff)
{
    ushort output = 0;
    ishort mask   = 0;
    output = hw->digitalOutputBit;
    mask   = hw->digitalOutputMask;
    if(onoff == 0 || onoff == 1)
    {
        bitFlag16(output, BIT(bit), onoff);
        bitFlag16(mask, BIT(bit), 1);
    }
    else if(onoff == 2)
    {
        bitFlag16(output, BIT(bit), onoff);
        bitFlag16(mask, BIT(bit), 0);
    }
    hw->digitalOutputBit = output;
    hw->digitalOutputMask = mask;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetDigitalClockDivide(SHardware* hw, uint divider)
{
    hw->digitalClkDivideH = (divider & 0xFFFF0000) >> 16;
    hw->digitalClkDivideL =  divider & 0x0000FFFF;
    return SCOPEFUN_SUCCESS;
}


/*--------------------------------------------------------------------------------
   digital
--------------------------------------------------------------------------------*/

SCOPEFUN_API int sfSetDigitalStart(SHardware* hw, int start)
{
    ushort   startBits = start;
    ushort controlBits = hw->dt_control;
    bitFlag16(controlBits, 1 << 8, isFlag16(startBits, 1));
    bitFlag16(controlBits, 1 << 9, isFlag16(startBits, 2));
    hw->dt_control = controlBits;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetDigitalMode(SHardware* hw, int mode)
{
    ushort   modeBits = mode;
    ushort controlBits = hw->dt_control;
    bitFlag16(controlBits, 1 << 4, isFlag16(modeBits, 1));
    hw->dt_control = controlBits;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetDigitalChannel(SHardware* hw, int channel)
{
    ushort channelBits = channel;
    ushort controlBits = hw->dt_control;
    bitFlag16(controlBits, 1 << 0, isFlag16(channelBits, 1));
    bitFlag16(controlBits, 1 << 1, isFlag16(channelBits, 2));
    bitFlag16(controlBits, 1 << 2, isFlag16(channelBits, 4));
    bitFlag16(controlBits, 1 << 3, isFlag16(channelBits, 8));
    hw->dt_control = controlBits;
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetDigitalDelay(SHardware* hw, uint stage, ushort delay)
{
    switch(stage)
    {
        case DIGITAL_STAGE_0:
            hw->dt_delayMaxcnt1 = delay;
            break;
        case DIGITAL_STAGE_1:
            hw->dt_delayMaxcnt2 = delay;
            break;
        case DIGITAL_STAGE_2:
            hw->dt_delayMaxcnt3 = delay;
            break;
        case DIGITAL_STAGE_3:
            hw->dt_delayMaxcnt4 = delay;
            break;
        default:
            return SCOPEFUN_FAILURE;
    };
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int  sfSetDigitalMask(SHardware* hw, uint stage, uint bit, int value)
{
    ushort mask = 0;
    switch(stage)
    {
        case DIGITAL_STAGE_0:
            mask = hw->digitalMask1;
            break;
        case DIGITAL_STAGE_1:
            mask = hw->digitalMask2;
            break;
        case DIGITAL_STAGE_2:
            mask = hw->digitalMask3;
            break;
        case DIGITAL_STAGE_3:
            mask = hw->digitalMask4;
            break;
        default:
            return SCOPEFUN_FAILURE;
    };
    if(value) { raiseFlag16(mask, BIT(bit)); }
    else       { lowerFlag16(mask, BIT(bit)); }
    switch(stage)
    {
        case DIGITAL_STAGE_0:
            hw->digitalMask1 = mask;
            break;
        case DIGITAL_STAGE_1:
            hw->digitalMask2 = mask;
            break;
        case DIGITAL_STAGE_2:
            hw->digitalMask3 = mask;
            break;
        case DIGITAL_STAGE_3:
            hw->digitalMask4 = mask;
            break;
        default:
            return SCOPEFUN_FAILURE;
    };
    return SCOPEFUN_SUCCESS;
}

SCOPEFUN_API int sfSetDigitalPattern(SHardware* hw, ushort stage, ushort bit, ushort pattern)
{
    ushort patternA = 0;
    ushort patternB = 0;
    switch(stage)
    {
        case 0:
            patternA = hw->digitalPattern1a;
            patternB = hw->digitalPattern1b;
            break;
        case 1:
            patternA = hw->digitalPattern2a;
            patternB = hw->digitalPattern2b;
            break;
        case 2:
            patternA = hw->digitalPattern3a;
            patternB = hw->digitalPattern3b;
            break;
        case 3:
            patternA = hw->digitalPattern4a;
            patternB = hw->digitalPattern4b;
            break;
        default:
            return SCOPEFUN_FAILURE;
    };
    switch(pattern)
    {
        case DIGITAL_PATTERN_0: // 00
            lowerFlag16(patternA, BIT(bit));
            lowerFlag16(patternB, BIT(bit));
            break;
        case DIGITAL_PATTERN_1: // 11
            raiseFlag16(patternA, BIT(bit));
            raiseFlag16(patternB, BIT(bit));
            break;
        case DIGITAL_PATTERN_RISING: // 01
            lowerFlag16(patternA, BIT(bit));
            raiseFlag16(patternB, BIT(bit));
            break;
        case DIGITAL_PATTERN_FALLING: // 10
            raiseFlag16(patternA, BIT(bit));
            lowerFlag16(patternB, BIT(bit));
            break;
        default:
            return SCOPEFUN_FAILURE;
    };
    switch(stage)
    {
        case 0:
            hw->digitalPattern1a = patternA;
            hw->digitalPattern1b = patternB;
            break;
        case 1:
            hw->digitalPattern2a = patternA;
            hw->digitalPattern2b = patternB;
            break;
        case 2:
            hw->digitalPattern3a = patternA;
            hw->digitalPattern3b = patternB;
            break;
        case 3:
            hw->digitalPattern4a = patternA;
            hw->digitalPattern4b = patternB;
            break;
        default:
            return SCOPEFUN_FAILURE;
    };
    return SCOPEFUN_SUCCESS;
}


/*--------------------------------------------------------------------------------
   Get
--------------------------------------------------------------------------------*/

SCOPEFUN_API uint sfGetFrameSize(SHardware*  hw)
{
    uint numSamples = (((uint)hw->sampleSizeH) << 16) | (uint)hw->sampleSizeL;
    uint   dataSize = numSamples * 4;
    if(dataSize % 1024 != 0)
    { dataSize = ((dataSize / 1024) + 1) * 1024; }
    uint  frameSize = dataSize + SCOPEFUN_FRAME_HEADER;
    return frameSize;
}

SCOPEFUN_API uint sfGetNumSamples(SHardware* hw)
{
    uint numSamples = (((uint)hw->sampleSizeH) << 16) | (uint)hw->sampleSizeL;
    return numSamples;
}

SCOPEFUN_API ushort sfGetAnalogSwitch(SHardware* hw)
{
    return hw->analogswitch;
}

SCOPEFUN_API int sfGetEts(SHardware* hw)
{
    ushort tmp = hw->analogswitch;
    return isFlag16(tmp, CHANNEL_ETS);
}

SCOPEFUN_API uint sfGetControl(SHardware* hw)
{
    switch(hw->controlData)
    {
        case CONTROLL2_NORMAL:
            return 0;
        case CONTROLL2_TEST:
            return 1;
        case CONTROLL2_RESET:
            return 3;
    };
    return 0;
}

SCOPEFUN_API uint sfGetYGainA(SHardware* hw)
{
    return hw->vgaina;
}

SCOPEFUN_API float sfGetYScaleA(SHardware* hw)
{
    return 0.f;
}
SCOPEFUN_API int sfGetYPositionA(SHardware* hw)
{
    if(hw->offseta > 1500) { return -(int)(65536 - hw->offseta); }
    return (int)hw->offseta;
}

SCOPEFUN_API uint sfGetYGainB(SHardware* hw)
{
    return hw->vgainb;
}
SCOPEFUN_API float sfGetYScaleB(SHardware* hw)
{
    return 0.f;
}
SCOPEFUN_API int sfGetYPositionB(SHardware* hw)
{
    if(hw->offsetb > 1500) { return - (int)(65536 - hw->offsetb); }
    return (int)hw->offsetb;
}

SCOPEFUN_API ushort sfGetTriggerSource(SHardware* hw)
{
    return hw->triggerSource;
}

SCOPEFUN_API ushort sfGetTriggerMode(SHardware* hw)
{
    return hw->triggerMode;
}

SCOPEFUN_API ushort sfGetTriggerSlope(SHardware* hw)
{
    return hw->triggerSlope;
}

SCOPEFUN_API float sfGetTriggerPre(SHardware* hw)
{
    uint lo = hw->sampleSizeL;
    uint hi = hw->sampleSizeH;
    uint sampleSize = lo | (hi << 16);
    return 100.f * ((float)(hw->triggerPercent * 4) / (float)(sampleSize - 1));
}

SCOPEFUN_API int sfGetTriggerHis(SHardware* hw)
{
    return hw->triggerHis;
}

SCOPEFUN_API int sfGetTriggerLevel(SHardware* hw)
{
    return hw->triggerLevel;
}

SCOPEFUN_API ishort sfGetXRange(SHardware* hw)
{
    return hw->xRange;
}

SCOPEFUN_API uint sfGetSampleSize(SHardware* hw)
{
    uint lo = hw->sampleSizeL;
    uint hi = hw->sampleSizeH;
    uint sampleSize = lo | (hi << 16);
    return sampleSize;
}

SCOPEFUN_API uint sfGetHoldoff(SHardware* hw)
{
    uint holdOffInt = (uint)hw->holdoffL | ((uint)hw->holdoffH << 16);
    return holdOffInt;
}

SCOPEFUN_API int sfGetDigitalStart(SHardware* hw)
{
    return (hw->dt_control & 0x300) >> 8;
}

SCOPEFUN_API int sfGetDigitalMode(SHardware* hw)
{
    return (hw->dt_control & 0x10) >> 4;
}

SCOPEFUN_API int sfGetDigitalChannel(SHardware* hw)
{
    return hw->dt_control & 0xF;
}

SCOPEFUN_API ushort sfGetDigitalDelay(SHardware* hw, ushort stage)
{
    switch(stage)
    {
        case DIGITAL_STAGE_0:
            return hw->dt_delayMaxcnt1;
        case DIGITAL_STAGE_1:
            return hw->dt_delayMaxcnt2;
        case DIGITAL_STAGE_2:
            return hw->dt_delayMaxcnt3;
        case DIGITAL_STAGE_3:
            return hw->dt_delayMaxcnt4;
        default:
            return SCOPEFUN_FAILURE;
    };
}

SCOPEFUN_API int sfGetDigitalMask(SHardware* hw, ushort stage, ushort bit)
{
    ushort mask = 0;
    switch(stage)
    {
        case DIGITAL_STAGE_0:
            mask = hw->digitalMask1;
            break;
        case DIGITAL_STAGE_1:
            mask = hw->digitalMask2;
            break;
        case DIGITAL_STAGE_2:
            mask = hw->digitalMask3;
            break;
        case DIGITAL_STAGE_3:
            mask = hw->digitalMask4;
            break;
        default:
            return SCOPEFUN_FAILURE;
    };
    return isFlag16(mask, BIT(bit));
}

SCOPEFUN_API ushort sfGetDigitalPattern(SHardware* hw, ushort stage, ushort bit)
{
    ushort patternA = 0;
    ushort patternB = 0;
    switch(stage)
    {
        case 0:
            patternA = hw->digitalPattern1a;
            patternB = hw->digitalPattern1b;
            break;
        case 1:
            patternA = hw->digitalPattern2a;
            patternB = hw->digitalPattern2b;
            break;
        case 2:
            patternA = hw->digitalPattern3a;
            patternB = hw->digitalPattern3b;
            break;
        case 3:
            patternA = hw->digitalPattern4a;
            patternB = hw->digitalPattern4b;
            break;
        default:
            return SCOPEFUN_FAILURE;
    };
    int bitA = isFlag16(patternA, BIT(bit));
    int bitB = isFlag16(patternB, BIT(bit));
    if(bitA &&  bitB)
    {
        return DIGITAL_PATTERN_1;
    }
    if(!bitA && !bitB)
    {
        return DIGITAL_PATTERN_0;
    }
    if(!bitA &&  bitB)
    {
        return DIGITAL_PATTERN_RISING;
    }
    if(bitA && !bitB)
    {
        return DIGITAL_PATTERN_FALLING;
    }
    return DIGITAL_PATTERN_1;
}

/*--------------------------------------------------------------------------------
   generator 0
--------------------------------------------------------------------------------*/

SCOPEFUN_API ushort sfGetGeneratorType0(SHardware* hw)
{
    uint mask = 1 << 8;
    if(hw->generatorType0 & mask)
    {
        return (ushort)(hw->generatorType0 & ~mask);
    }
    else
    {
        return (ushort)(hw->generatorType0);
    }
}

SCOPEFUN_API int sfGetGeneratorOn0(SHardware* hw)
{
    uint mask = 1 << 8;
    if(hw->generatorType0 & mask)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

SCOPEFUN_API int sfGetGeneratorSlope0(SHardware* hw)
{
    return 0;
}

SCOPEFUN_API int sfGetGeneratorVoltage0(SHardware* hw)
{
    uint mask = 1 << 12;
    if(hw->generatorVoltage0 & mask)
    {
        return hw->generatorVoltage0 & ~mask;
    }
    else
    {
        return hw->generatorVoltage0;
    }
}

SCOPEFUN_API int sfGetGeneratorOffset0(SHardware* hw)
{
    return hw->generatorOffset0;
}

SCOPEFUN_API float sfGetGeneratorFrequency0(SHardware* hw, float fs)
{
    uint gDelta = (uint)(hw->generatorDeltaL0) | (uint)(hw->generatorDeltaH0 << 16);
    double delta = (double)(gDelta / 1048575.0);
    return (float)delta * (double)(fs) / 8188.0;
}

SCOPEFUN_API float sfGetGeneratorSquareDuty0(SHardware* hw)
{
    return 100.0 * (float)(hw->generatorSqueareDuty0) / 2047;
}

/*--------------------------------------------------------------------------------
   generator 1
--------------------------------------------------------------------------------*/

SCOPEFUN_API ushort sfGetGeneratorType1(SHardware* hw)
{
    uint mask = 1 << 8;
    if(hw->generatorType1 & mask)
    {
        return (ushort)(hw->generatorType1 & ~mask);
    }
    else
    {
        return (ushort)(hw->generatorType1);
    }
}

SCOPEFUN_API int sfGetGeneratorOn1(SHardware* hw)
{
    uint mask = 1 << 8;
    if(hw->generatorType1 & mask)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

SCOPEFUN_API int sfGetGeneratorSlope1(SHardware* hw)
{
    return 0;
}

SCOPEFUN_API int sfGetGeneratorVoltage1(SHardware* hw)
{
    uint mask = 1 << 12;
    if(hw->generatorVoltage1 & mask)
    {
        return hw->generatorVoltage1 & ~mask;
    }
    else
    {
        return hw->generatorVoltage1;
    }
}

SCOPEFUN_API int sfGetGeneratorOffset1(SHardware* hw)
{
    return hw->generatorOffset1;
}

SCOPEFUN_API float sfGetGeneratorFrequency1(SHardware* hw, float fs)
{
    uint gDelta = (uint)(hw->generatorDeltaL1) | (uint)(hw->generatorDeltaH1 << 16);
    double delta = (double)(gDelta / 1048575.0);
    return (float)(delta * (double)(fs) / 8188.0);
}

SCOPEFUN_API float sfGetGeneratorSquareDuty1(SHardware* hw)
{
    return 100.0 * (float)(hw->generatorSqueareDuty1) / 2047;
}

/*--------------------------------------------------------------------------------
   digial
--------------------------------------------------------------------------------*/

SCOPEFUN_API double sfGetDigitalVoltage(SHardware* hw, double kDigital)
{
    double Vmin = 1.25 * ((0.0 / kDigital) + 1.0);
    double Vmax = 1.25 * ((255.0 / kDigital) + 1.0);
    double voltage = 1.25 * (((double)(hw->digitalVoltage) / kDigital) + 1.0);
    return dClamp(voltage, Vmin, Vmax);
}

SCOPEFUN_API int sfGetDigitalInputOutput15(SHardware* hw)
{
    return (hw->digitalInputOutput >> 1) & 0x1;
}

SCOPEFUN_API int sfGetDigitalInputOutput7(SHardware* hw)
{
    return hw->digitalInputOutput & 0x1;
}

SCOPEFUN_API int sfGetDigitalOutputBit(SHardware* hw, int bit)
{
    ushort bits = 0;
    bits = hw->digitalOutputBit;
    return isFlag16(bits, BIT(bit));
}

SCOPEFUN_API uint sfGetDigitalClockDivide(SHardware* hw)
{
    return (uint)(hw->digitalClkDivideL) | (uint)(hw->digitalClkDivideH << 16);
}

SCOPEFUN_API int sfGetAverage(SHardware* hw)
{
    return hw->average;
}
