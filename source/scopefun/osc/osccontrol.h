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
#ifndef __OSC_CONTROL__
#define __OSC_CONTROL__

class OsciloscopeControlInterface
{
public:
    // default
    virtual void Default() = 0;
public:
    // set
    virtual void setAnalogSwitchBit(int bit, int value) = 0;
    virtual void setEts(int enable) = 0;
    virtual void setControl(uint control) = 0;
    virtual void setYRangeScaleA(uint voltage, float scale) = 0;
    virtual void setYRangeScaleA(uint gain, uint attr) = 0;
    virtual void setYPositionA(int pos) = 0;
    virtual void setYRangeScaleB(uint voltage, float scale) = 0;
    virtual void setYRangeScaleB(uint gain, uint attr) = 0;
    virtual void setYPositionB(int pos) = 0;
public:
    virtual void setTriggerSource(int source) = 0;
    virtual void setTriggerMode(int mode) = 0;
    virtual void setTriggerSlope(int mode) = 0;
    virtual void setTriggerReArm(bool on) = 0;
    virtual void setTriggerPre(float perc) = 0;
    virtual void setTriggerHis(int perc) = 0;
    virtual void setTriggerLevel(int perc) = 0;
public:
    virtual void setXRange(ishort range) = 0;
    virtual void setSampleSize(uint frameSize) = 0;
    virtual void setHoldoff(uint holdoff) = 0;
public:
    virtual void setDigitalStart(int start) = 0;
    virtual void setDigitalMode(int mode) = 0;
    virtual void setDigitalChannel(int channel) = 0;
    virtual void setDigitalDelay(DigitalStage stage, ushort delay) = 0;
    virtual void setDigitalMask(DigitalStage stage, DigitalBit bit, int value) = 0;
    virtual void setDigitalPattern(DigitalStage stage, DigitalBit bit, DigitalPattern pattern) = 0;
public:
    virtual void setGeneratorType0(GeneratorType type) = 0;
    virtual void setGeneratorOn0(int onoff) = 0;
    virtual void setGeneratorSlope0(int onoff) = 0;
    virtual void setGeneratorVoltage0(int volt) = 0;
    virtual void setGeneratorOffset0(int perc) = 0;
    virtual void setGeneratorFrequency0(float freq, float fs = 457142.81f) = 0;
    virtual void setGeneratorSquareDuty0(float perc) = 0;
public:
    virtual void setGeneratorType1(GeneratorType type) = 0;
    virtual void setGeneratorOn1(int onoff) = 0;
    virtual void setGeneratorSlope1(int onoff) = 0;
    virtual void setGeneratorVoltage1(int volt) = 0;
    virtual void setGeneratorOffset1(int perc) = 0;
    virtual void setGeneratorFrequency1(float freq, float fs = 457142.81f) = 0;
    virtual void setGeneratorSquareDuty1(float perc) = 0;
public:
    virtual void setDigitalVoltage(double volt) = 0;
    virtual void setDigitalInputOutput(int inout15, int inout7) = 0;
    virtual void setDigitalOutputBit(int bit, int onoff) = 0;
    virtual void setDigitalClockDivide(uint divider) = 0;
public:
    virtual void setAverage(int enable) = 0;
public:
    // get
    virtual ushort getAnalogSwitch() = 0;
    virtual int    getEts() = 0;
    virtual uint   getControl() = 0;
    virtual uint   getYRangeA() = 0;
    virtual float  getYScaleA() = 0;
    virtual int    getYPositionA() = 0;
    virtual uint   getYRangeB() = 0;
    virtual float  getYScaleB() = 0;
    virtual int    getYPositionB() = 0;
public:
    virtual ushort getTriggerSource() = 0;
    virtual ushort getTriggerMode() = 0;
    virtual ushort getTriggerSlope() = 0;
    virtual float  getTriggerPre() = 0;
    virtual int    getTriggerHis() = 0;
    virtual int    getTriggerLevel() = 0;
public:
    virtual uint   getSampleSize() = 0;
    virtual ishort getXRange() = 0;
    virtual uint   getHoldoff() = 0;
public:
    virtual int   getDigitalStart() = 0;
    virtual int   getDigitalMode() = 0;
    virtual int   getDigitalChannel() = 0;
public:
    virtual ushort         getDigitalDelay(DigitalStage stage) = 0;
    virtual int            getDigitalMask(DigitalStage stage, DigitalBit bit) = 0;
    virtual DigitalPattern getDigitalPattern(DigitalStage stage, DigitalBit bit) = 0;
public:
    virtual GeneratorType getGeneratorType0() = 0;
    virtual int           getGeneratorOn0() = 0;
    virtual int           getGeneratorSlope0() = 0;
    virtual int           getGeneratorVoltage0() = 0;
    virtual int           getGeneratorOffset0() = 0;
    virtual float         getGeneratorFrequency0(float fs = 457142.81f) = 0;
    virtual float         getGeneratorSquareDuty0() = 0;
public:
    virtual GeneratorType getGeneratorType1() = 0;
    virtual int           getGeneratorOn1() = 0;
    virtual int           getGeneratorSlope1() = 0;
    virtual int           getGeneratorVoltage1() = 0;
    virtual int           getGeneratorOffset1() = 0;
    virtual float         getGeneratorFrequency1(float fs = 457142.81f) = 0;
    virtual float         getGeneratorSquareDuty1() = 0;
public:
    virtual double getDigitalVoltage() = 0;
    virtual int    getDigitalInputOutput15() = 0;
    virtual int    getDigitalInputOutput7() = 0;
    virtual int    getDigitalOutputBit(int bit) = 0;
    virtual uint   getDigitalClockDivide() = 0;
public:
    virtual ushort getAttr(uint volt) = 0;
    virtual ushort getGain(int channel, uint volt) = 0;
public:
    virtual int getAverage() = 0;
};

////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeControl1
//
////////////////////////////////////////////////////////////////////////////////
#ifdef PLATFORM_WIN
    #pragma pack(push,1)
#endif

class OsciloscopeControl1 : public OsciloscopeControlInterface
{
public:
    ushort control;
    ushort vgaina;
    ushort vgainb;
    short  offseta;
    short  offsetb;
    ushort siggen;
    ushort trigger;
    ushort analogswitch;
    ushort triggerMode;
    ushort triggerSource;
    ushort triggerSlope;
    ishort triggerLevel;
    ushort triggerHis;
    ushort triggerPercent;
    ushort xRange;
    ushort sampleSize;
    ushort holdoffH;
    ushort holdoffL;
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
public:
    OsciloscopeControl1();
public:
    virtual void Default();
public:
    virtual void setAnalogSwitchBit(int bit, int value);
    virtual void setEts(int enable);
    virtual void setControl(uint control);
    virtual void setYRangeScaleA(uint voltage, float scale);
    virtual void setYRangeScaleA(uint gain, uint attr);
    virtual void setYPositionA(int pos);
    virtual void setYRangeScaleB(uint voltage, float scale);
    virtual void setYRangeScaleB(uint gain, uint attr);
    virtual void setYPositionB(int pos);
public:
    virtual void setTriggerSource(int source);
    virtual void setTriggerMode(int mode);
    virtual void setTriggerSlope(int mode);
    virtual void setTriggerReArm(bool on);
public:
    virtual void setTriggerPre(float perc);
    virtual void setTriggerHis(int perc);
    virtual void setTriggerLevel(int perc);
public:
    void setXRange(ishort range);
    void setSampleSize(uint frameSize);
    void setHoldoff(uint holdoff);
public:
    virtual void setDigitalStart(int start);
    virtual void setDigitalMode(int mode);
    virtual void setDigitalChannel(int channel);
public:
    virtual void setDigitalDelay(DigitalStage stage, ushort delay);
    virtual void setDigitalMask(DigitalStage stage, DigitalBit bit, int value);
    virtual void setDigitalPattern(DigitalStage stage, DigitalBit bit, DigitalPattern pattern);
public:
    virtual void setGeneratorType0(GeneratorType type);
    virtual void setGeneratorOn0(int onoff);
    virtual void setGeneratorSlope0(int onoff);
    virtual void setGeneratorVoltage0(int volt);
    virtual void setGeneratorOffset0(int perc);
    virtual void setGeneratorFrequency0(float freq, float fs = 457142.81f);
    virtual void setGeneratorSquareDuty0(float perc);
public:
    virtual void setGeneratorType1(GeneratorType type);
    virtual void setGeneratorOn1(int onoff);
    virtual void setGeneratorSlope1(int onoff);
    virtual void setGeneratorVoltage1(int volt);
    virtual void setGeneratorOffset1(int perc);
    virtual void setGeneratorFrequency1(float freq, float fs = 457142.81f);
    virtual void setGeneratorSquareDuty1(float perc);
public:
    virtual void setDigitalVoltage(double volt);
    virtual void setDigitalInputOutput(int inout15, int inout7);
    virtual void setDigitalOutputBit(int bit, int onoff);
    virtual void setDigitalClockDivide(uint divider);
public:
    virtual void setAverage(int enable) {};
public:
    virtual ushort getAnalogSwitch();
    virtual int   getEts();
    virtual uint  getControl();
    virtual uint  getYRangeA();
    virtual float getYScaleA();
    virtual int   getYPositionA();
public:
    virtual uint  getYRangeB();
    virtual float getYScaleB();
    virtual int   getYPositionB();
public:
    virtual ushort getTriggerSource();
    virtual ushort getTriggerMode();
    virtual ushort getTriggerSlope();
    virtual float  getTriggerPre();
    virtual int    getTriggerHis();
    virtual int    getTriggerLevel();
public:
    virtual uint   getSampleSize();
public:
    virtual ishort getXRange();
    virtual uint   getHoldoff();
public:
    virtual int   getDigitalStart();
    virtual int   getDigitalMode();
    virtual int   getDigitalChannel();
public:
    virtual ushort         getDigitalDelay(DigitalStage stage);
    virtual int            getDigitalMask(DigitalStage stage, DigitalBit bit);
    virtual DigitalPattern getDigitalPattern(DigitalStage stage, DigitalBit bit);
public:
    virtual GeneratorType getGeneratorType0();
    virtual int   getGeneratorOn0();
    virtual int   getGeneratorSlope0();
    virtual int   getGeneratorVoltage0();
    virtual int   getGeneratorOffset0();
    virtual float getGeneratorFrequency0(float fs = 457142.81f);
    virtual float getGeneratorSquareDuty0();
public:
    virtual GeneratorType getGeneratorType1();
    virtual int   getGeneratorOn1();
    virtual int   getGeneratorSlope1();
    virtual int   getGeneratorVoltage1();
    virtual int   getGeneratorOffset1();
    virtual float getGeneratorFrequency1(float fs = 457142.81f);
    virtual float getGeneratorSquareDuty1();
public:
    virtual double getDigitalVoltage();
    virtual int    getDigitalInputOutput15();
    virtual int    getDigitalInputOutput7();
    virtual int    getDigitalOutputBit(int bit);
    virtual uint   getDigitalClockDivide();
public:
    virtual ushort getAttr(uint volt);
    virtual ushort getGain(int channel, uint volt);
public:
    virtual int getAverage() {return 0;};
}
#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
    __attribute__((packed));
#else
    ;
#endif

#ifdef PLATFORM_WIN
    #pragma pack(pop)
#endif


////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeControl2
//
////////////////////////////////////////////////////////////////////////////////
#ifdef PLATFORM_WIN
    #pragma pack(push,1)
#endif

class OsciloscopeControl2 : public OsciloscopeControlInterface
{
public:
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
public:
    OsciloscopeControl2();
public:
    virtual void Default();
public:
    virtual void setAnalogSwitchBit(int bit, int value);
    virtual void setEts(int enable);
    virtual void setControl(uint control);
    virtual void setYRangeScaleA(uint voltage, float scale);
    virtual void setYRangeScaleA(uint gain, uint attr);
    virtual void setYPositionA(int pos);
    virtual void setYRangeScaleB(uint voltage, float scale);
    virtual void setYRangeScaleB(uint gain, uint attr);
    virtual void setYPositionB(int pos);
public:
    virtual void setTriggerSource(int source);
    virtual void setTriggerMode(int mode);
    virtual void setTriggerSlope(int mode);
    virtual void setTriggerReArm(bool on);
public:
    virtual void setTriggerPre(float perc);
    virtual void setTriggerHis(int perc);
    virtual void setTriggerLevel(int perc);
public:
    virtual void setXRange(ishort range);
    virtual void setSampleSize(uint frameSize);
    virtual void setHoldoff(uint holdoff);
public:
    virtual void setDigitalStart(int start);
    virtual void setDigitalMode(int mode);
    virtual void setDigitalChannel(int channel);
public:
    virtual void setDigitalDelay(DigitalStage stage, ushort delay);
    virtual void setDigitalMask(DigitalStage stage, DigitalBit bit, int value);
    virtual void setDigitalPattern(DigitalStage stage, DigitalBit bit, DigitalPattern pattern);
public:
    virtual void setGeneratorType0(GeneratorType type);
    virtual void setGeneratorOn0(int onoff);
    virtual void setGeneratorSlope0(int onoff);
    virtual void setGeneratorVoltage0(int volt);
    virtual void setGeneratorOffset0(int perc);
    virtual void setGeneratorFrequency0(float freq, float fs = 457142.81f);
    virtual void setGeneratorSquareDuty0(float perc);
public:
    virtual void setGeneratorType1(GeneratorType type);
    virtual void setGeneratorOn1(int onoff);
    virtual void setGeneratorSlope1(int onoff);
    virtual void setGeneratorVoltage1(int volt);
    virtual void setGeneratorOffset1(int perc);
    virtual void setGeneratorFrequency1(float freq, float fs = 457142.81f);
    virtual void setGeneratorSquareDuty1(float perc);
public:
    virtual void setDigitalVoltage(double volt);
    virtual void setDigitalInputOutput(int inout15, int inout7);
    virtual void setDigitalOutputBit(int bit, int onoff);
    virtual void setDigitalClockDivide(uint divider);
public:
    virtual void setAverage(int enable);
public:
    virtual ushort getAnalogSwitch();
    virtual int   getEts();
    virtual uint  getControl();
    virtual uint  getYRangeA();
    virtual float getYScaleA();
    virtual int   getYPositionA();
public:
    virtual uint  getYRangeB();
    virtual float getYScaleB();
    virtual int   getYPositionB();
public:
    virtual ushort getTriggerSource();
    virtual ushort getTriggerMode();
    virtual ushort getTriggerSlope();
    virtual float  getTriggerPre();
    virtual int    getTriggerHis();
    virtual int    getTriggerLevel();
public:
    virtual uint   getSampleSize();
public:
    virtual ishort getXRange();
    virtual uint   getHoldoff();
public:
    virtual int   getDigitalStart();
    virtual int   getDigitalMode();
    virtual int   getDigitalChannel();
public:
    virtual ushort         getDigitalDelay(DigitalStage stage);
    virtual int            getDigitalMask(DigitalStage stage, DigitalBit bit);
    virtual DigitalPattern getDigitalPattern(DigitalStage stage, DigitalBit bit);
public:
    virtual GeneratorType getGeneratorType0();
    virtual int   getGeneratorOn0();
    virtual int   getGeneratorSlope0();
    virtual int   getGeneratorVoltage0();
    virtual int   getGeneratorOffset0();
    virtual float getGeneratorFrequency0(float fs = 457142.81f);
    virtual float getGeneratorSquareDuty0();
public:
    virtual GeneratorType getGeneratorType1();
    virtual int   getGeneratorOn1();
    virtual int   getGeneratorSlope1();
    virtual int   getGeneratorVoltage1();
    virtual int   getGeneratorOffset1();
    virtual float getGeneratorFrequency1(float fs = 457142.81f);
    virtual float getGeneratorSquareDuty1();
public:
    virtual double getDigitalVoltage();
    virtual int    getDigitalInputOutput15();
    virtual int    getDigitalInputOutput7();
    virtual int    getDigitalOutputBit(int bit);
    virtual uint   getDigitalClockDivide();
public:
    virtual ushort getAttr(uint volt);
    virtual ushort getGain(int channel, uint volt);
public:
    virtual int getAverage();
}
#if defined(PLATFORM_LINUX) || defined(PLATFORM_MAC)
    __attribute__((packed));
#else
    ;
#endif

#ifdef PLATFORM_WIN
    #pragma pack(pop)
#endif

////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeMainControl
//
////////////////////////////////////////////////////////////////////////////////
class OsciloscopeMainControl : public OsciloscopeControlInterface
{
private:
    SHardware                    hw1;
    SHardware                    hw2;
    SDL_SpinLock                 lock;
    int                          version;
    OsciloscopeControlInterface* pControl;
public:
    OsciloscopeControl1          control1;
    OsciloscopeControl2          control2;
public:
    OsciloscopeMainControl();
public:
    void setVersion(int version);
    int  getVersion()
    {
        return version;
    };
public:
    void transferData();
public:
    void setWindow(WndMain& main);
public:
    // default
    virtual void Default();
public:
    // set
    virtual void setAnalogSwitchBit(int bit, int value);
    virtual void setEts(int enable);
    virtual void setControl(uint control);
    virtual void setYRangeScaleA(uint voltage, float scale);
    virtual void setYRangeScaleA(uint gain, uint attr);
    virtual void setYPositionA(int pos);
    virtual void setYRangeScaleB(uint voltage, float scale);
    virtual void setYRangeScaleB(uint gain, uint attr);
    virtual void setYPositionB(int pos);
public:
    virtual void setTriggerSource(int source);
    virtual void setTriggerMode(int mode);
    virtual void setTriggerSlope(int mode);
    virtual void setTriggerReArm(bool on);
    virtual void setTriggerPre(float perc);
    virtual void setTriggerHis(int perc);
    virtual void setTriggerLevel(int perc);
public:
    virtual void setXRange(ishort range);
    virtual void setSampleSize(uint frameSize);
    virtual void setHoldoff(uint holdoff);
public:
    virtual void setDigitalStart(int start);
    virtual void setDigitalMode(int mode);
    virtual void setDigitalChannel(int channel);
    virtual void setDigitalDelay(DigitalStage stage, ushort delay);
    virtual void setDigitalMask(DigitalStage stage, DigitalBit bit, int value);
    virtual void setDigitalPattern(DigitalStage stage, DigitalBit bit, DigitalPattern pattern);
public:
    virtual void setGeneratorType0(GeneratorType type);
    virtual void setGeneratorOn0(int onoff);
    virtual void setGeneratorSlope0(int onoff);
    virtual void setGeneratorVoltage0(int volt);
    virtual void setGeneratorOffset0(int perc);
    virtual void setGeneratorFrequency0(float freq, float fs = 457142.81f);
    virtual void setGeneratorSquareDuty0(float perc);
public:
    virtual void setGeneratorType1(GeneratorType type);
    virtual void setGeneratorOn1(int onoff);
    virtual void setGeneratorSlope1(int onoff);
    virtual void setGeneratorVoltage1(int volt);
    virtual void setGeneratorOffset1(int perc);
    virtual void setGeneratorFrequency1(float freq, float fs = 457142.81f);
    virtual void setGeneratorSquareDuty1(float perc);
public:
    virtual void setDigitalVoltage(double volt);
    virtual void setDigitalInputOutput(int inout15, int inout7);
    virtual void setDigitalOutputBit(int bit, int onoff);
    virtual void setDigitalClockDivide(uint divider);
public:
    virtual void setAverage(int enable);
public:
    // get
    virtual ushort getAnalogSwitch();
    virtual int   getEts();
    virtual uint  getControl();
    virtual uint  getYRangeA();
    virtual float getYScaleA();
    virtual int   getYPositionA();
    virtual uint  getYRangeB();
    virtual float getYScaleB();
    virtual int   getYPositionB();
public:
    virtual ushort getTriggerSource();
    virtual ushort getTriggerMode();
    virtual ushort getTriggerSlope();
    virtual float  getTriggerPre();
    virtual int    getTriggerHis();
    virtual int    getTriggerLevel();
public:
    virtual uint   getSampleSize();
    virtual ishort getXRange();
    virtual uint   getHoldoff();
public:
    virtual int   getDigitalStart();
    virtual int   getDigitalMode();
    virtual int   getDigitalChannel();
public:
    virtual ushort         getDigitalDelay(DigitalStage stage);
    virtual int            getDigitalMask(DigitalStage stage, DigitalBit bit);
    virtual DigitalPattern getDigitalPattern(DigitalStage stage, DigitalBit bit);
public:
    virtual GeneratorType getGeneratorType0();
    virtual int           getGeneratorOn0();
    virtual int           getGeneratorSlope0();
    virtual int           getGeneratorVoltage0();
    virtual int           getGeneratorOffset0();
    virtual float         getGeneratorFrequency0(float fs = 457142.81f);
    virtual float         getGeneratorSquareDuty0();
public:
    virtual GeneratorType getGeneratorType1();
    virtual int           getGeneratorOn1();
    virtual int           getGeneratorSlope1();
    virtual int           getGeneratorVoltage1();
    virtual int           getGeneratorOffset1();
    virtual float         getGeneratorFrequency1(float fs = 457142.81f);
    virtual float         getGeneratorSquareDuty1();
public:
    virtual double getDigitalVoltage();
    virtual int    getDigitalInputOutput15();
    virtual int    getDigitalInputOutput7();
    virtual int    getDigitalOutputBit(int bit);
    virtual uint   getDigitalClockDivide();
public:
    virtual int getAverage();
public:
    virtual ushort getAttr(uint volt);
    virtual ushort getGain(int channel, uint volt);
};


#endif
////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
