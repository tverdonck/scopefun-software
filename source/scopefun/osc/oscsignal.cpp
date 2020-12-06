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
#include<ScopeFun/ScopeFun.h>

extern "C" ishort leadBitShift(ushort value);
extern "C" ishort leadBitCompl(ushort value);


uint ScopeFunCaptureBuffer::save(const char* path)
{
   SDL_AtomicSet(&m_active,1);

   FORMAT_BUFFER();

   // .sf
   FORMAT("%s", path);
   SDL_RWops* sfFile = SDL_RWFromFile(formatBuffer,"w+b");
   int frameCount = SDL_AtomicGet(&m_frameCount);
   FORMAT("----scopefun----\n", frameCount);
   SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);

   // structures
   SFContext*             ctx       = sfCreateSFContext();
   SFrameData*     frameData        = sfCreateSFrameData();
   SFrameHeader*   frameHeader      = sfCreateSFrameHeader();
   SHardware*      frameHardware    = sfCreateSHardware();
   uint            frameEts         = 0;
   SFloat          frameTemperature = { 0.0 };
   
   // context
   sfApiCreateContext(ctx,SCOPEFUN_FRAME_MEMORY);

   // info
   int   frameIndex = SDL_AtomicGet(&m_frameIndex);
   int   frameSize  = SDL_AtomicGet(&m_frameSize);
   ularge  framePos = frameIndex * frameSize;

   // copy header
   SDL_memcpy(frameData->data.bytes, &m_dataPtr[framePos], frameSize);

   // get
   sfGetHeader(ctx, frameData, frameHeader);
   sfGetHeaderHardware(ctx, frameHeader, frameHardware);
   sfGetHeaderEts(frameHeader, &frameEts);
   sfGetHeaderTemperature(frameHeader, &frameTemperature);

   // frame
   FORMAT("frame.index,%d\n", frameIndex);
   SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);
   FORMAT("frame.size,%d\n", frameSize);
   SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);
   int sampleCount = sfGetNumSamples(getHw());
   FORMAT("frame.samples,%d\n", sfGetNumSamples(frameHardware));
   SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);

   // header
   FORMAT("header.magic,%08x\n", *(uint*)&frameHeader->magic.bytes[0] );
   SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);
   FORMAT("header.etsDelay,%d\n", *(char*)&frameHeader->etsDelay.bytes[0]);
   SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);
   FORMAT("header.crc,%02x\n", (unsigned char)(unsigned char*)&frameHeader->crc.bytes[0]);
   SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);

   // hardware
   int cnt = 0;
   sfHardwareWordCnt(&cnt);
   for (int j=0; j < cnt; j++)
   {
      SArrayString256 stringId = { 0 };
      sfHardwareWordId(j, &stringId);
      ushort* ptr = (ushort*)&frameHardware->controlAddr;
      FORMAT("hardware.%s,%04x\n", (char*)stringId.bytes, ptr[j]);
      SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);
   }

   FORMAT("sample.ch0[-512...511],sample.ch1[-512...511],sample.digital[0x000...0xfff]\n");
   SDL_RWwrite(sfFile, &formatBuffer, SDL_strlen(formatBuffer), 1);
   if (sampleCount)
   {
      int textSampleBytes = 16;
      int textSampleCount = 64 * 1024;
      char* stringArray = (char*)pMemory->allocate(textSampleBytes * textSampleCount);
      int loop   = sampleCount / textSampleCount;
      int modulo = sampleCount % textSampleCount;
      for (int j = 0; j < loop + 1; j++)
      {
         SDL_AtomicSet(&m_progress, 100 * j / (loop+1));
         if (SDL_AtomicGet(&m_active) == 0)
            break;
         int kMax = textSampleCount;
         if (j == loop) kMax = modulo;
         char* stringStart = (char*)stringArray;
         SDL_memset(stringStart, 0, textSampleBytes * textSampleCount);
         for (int k = 0; k < kMax; k++)
         {
            if (SDL_AtomicGet(&m_active) == 0)
               break;
            ishort ch0 = 0;
            ishort ch1 = 0;
            ushort dig = 0;
            ularge offset = framePos + SCOPEFUN_FRAME_HEADER + (j * textSampleCount + k)*4;
            uint     data = *(uint*)&m_dataPtr[offset];
            sfGetData(data, &ch0, &ch1, &dig);
            macroString(stringStart, textSampleBytes, "%d,%d,%04x\n", ch0, ch1, dig);
            stringStart += SDL_strlen(stringStart);
         }
         SDL_RWwrite(sfFile, stringArray, SDL_strlen(stringArray), 1 );
      }
      pMemory->free(stringArray);
   }
   SDL_RWclose(sfFile);
   SDL_AtomicSet(&m_active, 0);

   return 0;
}

uint ScopeFunCaptureBuffer::load(const char* path)
{
   SDL_AtomicSet(&m_active, 1);

   lock( SDL_AtomicGet(&m_frameIndex) );

   FORMAT_BUFFER();

   // .sf
   FORMAT("%s", path);
   SDL_RWops* sfFile = SDL_RWFromFile(formatBuffer, "r+b");
   Sint64 fileSize = SDL_RWsize(sfFile);

   // header
   int    textheaderBytes = FORMAT_BUFFER_SIZE;
   int    textheaderCount = 67;
   char*     lineMem = (char*)pMemory->allocate(textheaderBytes*textheaderCount);
   SDL_memset(lineMem, 0, textheaderBytes*textheaderCount);
   SDL_RWread(sfFile, lineMem, textheaderBytes*textheaderCount, 1);

   // load header line by line
   char*                             lineArray = lineMem;
   char    headerArray[67][FORMAT_BUFFER_SIZE] = { 0 };
   ularge                           headerSize = 0;
   for (int l = 0; l < textheaderCount; l++)
   {
      for (int ch = 0; ch < FORMAT_BUFFER_SIZE; ch++)
      {
         headerSize++;
         headerArray[l][ch] = *lineArray; lineArray++;
         if (headerArray[l][ch] == '\n')
            break;
      }
   }

   // seek to end of header where samples start
   SDL_RWseek(sfFile, headerSize, RW_SEEK_SET );
   pMemory->free(lineMem);

   // framePos, spaceLeft
   ularge framePos  = SDL_AtomicGet(&m_frameIndex)*SDL_AtomicGet(&m_frameSize);
   ularge spaceLeft = m_dataMax - framePos;

   // parse header
   SFrameHeader* frameHeader   = (SFrameHeader*)&m_dataPtr[framePos];
   SHardware*    frameHardware = (SHardware*)&frameHeader->hardware.bytes[0];
  
   // "frame.index,%d\n"
   int frameIndex = 0;
   SDL_sscanf(&headerArray[1][0], "frame.index,%d\n", &frameIndex);
  
   // "frame.size,%d\n"
   int frameSize = 0;
   SDL_sscanf(&headerArray[2][0], "frame.size,%d\n", &frameSize);
   
   // "frame.samples,%d\n"
   int frameSamples = 0;
   SDL_sscanf(&headerArray[3][0], "frame.samples,%d\n", &frameSamples);
 
   // "header.magic,%c%c%c%c\n"
   uint magic = 0;
   SDL_sscanf(&headerArray[4][0], "header.magic,%08x\n", &magic);
   *(uint*)&frameHeader->magic.bytes[0] = magic;

   // "header.etsDelay,%c\n"
   int etsDelay = 0;
   SDL_sscanf(&headerArray[5][0], "header.etsDelay,%02x\n", &etsDelay);
   frameHeader->etsDelay.bytes[0] = etsDelay;

   // "header.crc,%c\n"
   int crc = 0;
   SDL_sscanf(&headerArray[6][0], "header.crc,%d\n", &crc);
   frameHeader->crc.bytes[0] = crc;

   // hardware
   int cnt = 0;
   sfHardwareWordCnt(&cnt);
   for (int i = 0; i < cnt; i++)
   {
      SArrayString256 stringId = {0};
      sfHardwareWordId(i, &stringId);

      FORMAT("hardware.%s,%%04x\n", stringId.bytes);
      uint hex = 0;
      SDL_sscanf(&headerArray[i+7][0], formatBuffer, &hex);

      ushort* ptr = (ushort*)&frameHardware->controlAddr;
      ptr[i] = cSwap16((ushort*)&hex);
   }

   // samples
   ularge fileTextSize    = min( fileSize - headerSize, spaceLeft );
   byte*  memorySamples   = &m_dataPtr[framePos];
          memorySamples  += SCOPEFUN_FRAME_HEADER;
   int    textSampleBytes = 16;
   int    textSampleCount = 64*1024;
   Sint64 textAllocated   = textSampleBytes * textSampleCount;
   char*  textArray       = (char*)pMemory->allocate(textAllocated);
   Sint64 textLoop        = fileTextSize / textAllocated;
   Sint64 textModulo      = fileTextSize % textAllocated;
   for (int i = 0; i < textLoop + 1; i++)
   {
      SDL_AtomicSet(&m_progress, 100 * i / (textLoop + 1));
      if (SDL_AtomicGet(&m_active) == 0)
         break;

      int textSize = textAllocated;
      if (i == textLoop) textSize = textModulo;

      SDL_RWread(sfFile, textArray, textSize, 1);
      for (int i = 0; i < textSize;)
      {
         char sampleBuffer[16] = { 0 };
         for (int k = 0; k < 16; k++)
         {
            sampleBuffer[k] = textArray[i]; i++;
            if (sampleBuffer[k] == '\n')
               break;
         }
         int    ch0 = 0;
         int    ch1 = 0;
         uint   dig = 0;
         SDL_sscanf(sampleBuffer, "%d,%d,%04x\n", &ch0, &ch1, &dig);
         sfSetData(memorySamples, ch0, ch1, dig);
         memorySamples += 4;
      }
   }
   SDL_RWclose(sfFile);
 
   SDL_AtomicSet(&m_frameSize, frameSize);

   unlock( SDL_AtomicGet(&m_frameIndex) );
   SDL_AtomicSet(&m_active, 0);
   return 0;
}


/*
////////////////////////////////////////////////////////////////////////////////
//
// CaptureInterface
//
////////////////////////////////////////////////////////////////////////////////
void CaptureInterface::freeInterfaceMemory()
{
    pMemory->free((void*)ringFrame.getData());
    pMemory->free((void*)ringPacket.getData());
}

uint CaptureInterface::allocateFrame(ularge mem, uint packetSize)
{
    ularge countFrame = (mem / packetSize);
    ularge bytesFrame = countFrame * sizeof(CaptureFrame);
    CaptureFrame* pDataFrame = (CaptureFrame*)pMemory->allocate(bytesFrame);
    ringFrame.init(pDataFrame, countFrame);
    return 0;
}

uint CaptureInterface::allocatePacket(ularge mem, uint packetSize)
{
    ularge countPacket = (mem / packetSize);
    ularge bytesPacket = countPacket * sizeof(PacketData);
    PacketData* pDataPacket = (PacketData*)pMemory->allocate(bytesPacket);
    ringPacket.init(pDataPacket, countPacket);
    return 0;
}

uint CaptureInterface::intersect(ularge start, ularge end, ularge i0, ularge i1)
{
    if(start < i0 && end < i0)
    {
        return 0;
    }
    if(start > i0 && start > i1)
    {
        return 0;
    }
    return 1;
}

uint CaptureInterface::overlap(ularge start, ularge end, ularge i0, ularge i1)
{
    if(intersect(start, end, i0, i1))
    {
        return 1;
    }
    else
    {
        if(end > memoryCurrent)
        {
            return intersect(0, end % memoryCurrent, i0, i1);
        }
        if(i1  > memoryCurrent)
        {
            return intersect(start, end, 0, i1 % memoryCurrent);
        }
    }
    return 0;
}

void CaptureInterface::incRead(ularge start, ularge size)
{
}

uint CaptureInterface::writePacket(CapturePacket& packet, uint isHeader)
{
    // memory
    PacketData* lastPacket = ringPacket.peek(ringPacket.getLast());
    ularge offsetWrite = (lastPacket->offset + lastPacket->size);
    if(offsetWrite + packet.size > memoryCurrent)
    {
        offsetWrite = 0;
    }
    // read
    if(ringPacket.isFull())
    {
        PacketData      remove;
        PacketData* readPacket = ringPacket.peek(ringPacket.getRead());
        // frame
        if(readPacket->flag.is(PACKET_USED))
        {
            CaptureFrame frame;
            ringFrame.read(frame);
        }
        // packets
        while(readPacket->flag.is(PACKET_USED))
        {
            // packet
            readPacket->flag.clear();
            ringPacket.read(remove);
            readPacket = ringPacket.peek(ringPacket.getRead());
            if(readPacket->flag.is(PACKET_HEADER))
            {
                break;
            }
        }
    }
    // packet
    PacketData data;
    data.size     = packet.size;
    data.offset   = offsetWrite;
    data.flag.raise(PACKET_USED);
    data.flag.raise(isHeader ? PACKET_HEADER : 0);
    ringPacket.write(data);
    write(offsetWrite, (byte*)packet.data, packet.size);
    return 0;
}

uint CaptureInterface::readPacket(CapturePacket& elem)
{
    if(!ringPacket.isEmpty())
    {
        PacketData data;
        ringPacket.read(data);
        elem.size = data.size;
        read(data.offset, (byte*)elem.data, data.size);
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
// CaptureMemory
//
////////////////////////////////////////////////////////////////////////////////
uint CaptureMemory::init(byte* mem, ularge size, uint packetSize)
{
    data = (char*)mem;
    memoryMax = memoryCurrent = size;
    allocateFrame(size, packetSize);
    allocatePacket(size, packetSize);
    return 0;
}

void CaptureMemory::freePacketMemory()
{
    pMemory->free(data);
}

uint CaptureMemory::resize(ularge iframe, ularge isize)
{
    // nothing to resize !
    return 0;
}

uint CaptureMemory::save(const char* path, uint& progress, uint& active)
{
    lock();
    int version = 0;
    int frameHeader = 0;
    int frameData = 0;
    int framePacket = 0;
    pOsciloscope->thread.getFrame(&version, &frameHeader, &frameData, &framePacket);
    CaptureHeader header;
    header.hwVersion    = version;
    header.hwHeader     = frameHeader;
    header.hwData       = frameData;
    header.hwPacket     = framePacket;
    header.frameStart   = ringFrame.getStart();
    header.frameCount   = ringFrame.getCount();
    header.frameSize    = ringFrame.getSize();
    header.packetStart  = ringPacket.getStart();
    header.packetCount  = ringPacket.getCount();
    header.packetSize   = ringPacket.getSize();
    // write
    SDL_RWops* ctxWrite = SDL_RWFromFile(path, "w+b");
    // header
    SDL_RWwrite(ctxWrite, &header, sizeof(CaptureHeader), 1);
    // frame
    for(int i = 0; i < header.frameSize; i++)
    {
        progress = (i * 100) / header.frameSize;
        active = 1;
        SDL_RWwrite(ctxWrite, ringFrame.getData() + i, sizeof(CaptureFrame), 1);
    }
    // packet
    for(int i = 0; i < header.packetSize; i++)
    {
        progress = (i * 100) / header.packetSize;
        active = 1;
        SDL_RWwrite(ctxWrite, ringPacket.getData() + i, sizeof(PacketData), 1);
    }
    // data
    Ring<PacketData> readRing = ringPacket;
    uint count = readRing.getCount();
    for(uint i = 0; i < count; i++)
    {
        progress = (i * 100) / count;
        active = 1;
        PacketData packet;
        readRing.read(packet);
        ularge ret = SDL_RWwrite(ctxWrite, (void*)(data + packet.offset), packet.size, 1);
        if(ret != 1)
        {
            int debug = 1;
        }
    }
    // close
    SDL_RWclose(ctxWrite);
    unlock();
    return 0;
}

uint CaptureMemory::load(const char* path, uint& progress, uint& active)
{
    lock();
    int version = 0;
    int frameHeader = 0;
    int frameData = 0;
    int framePacket = 0;
    pOsciloscope->thread.getFrame(&version, &frameHeader, &frameData, &framePacket);
    // offset
    CaptureHeader header;
    SDL_RWops* ctxRead = SDL_RWFromFile(path, "rb");
    SDL_RWread(ctxRead, &header, sizeof(CaptureHeader), 1);
    if(header.hwVersion != version ||
       header.hwHeader != frameHeader ||
       header.hwData != frameData ||
       header.hwPacket != framePacket)
    {
        FORMAT_BUFFER();
        FORMAT(" version is %d but %d expected \n header is %d but %d expected \n data is %d but %d expected \n packet is %d but %d expected \n", header.hwVersion, version, header.hwHeader, frameHeader, header.hwData, frameData, header.hwPacket, framePacket);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "File header is incompatible.", formatBuffer, 0);
        unlock();
        return 1;
    }
    // reallocate frame memory
    CaptureFrame* framePtr = (CaptureFrame*)pMemory->reallocate((void*)ringFrame.getData(), header.frameSize * sizeof(CaptureFrame));
    ringFrame.init(framePtr, header.frameSize);
    ringFrame.setStart(header.frameStart);
    ringFrame.setCount(header.frameCount);
    // load frame
    for(int i = 0; i < header.frameSize; i++)
    {
        progress = (i * 100) / header.frameSize;
        active = 1;
        SDL_RWread(ctxRead, (void*)(framePtr + i), sizeof(CaptureFrame), 1);
    }
    // reallocate packet memory
    PacketData* packetPtr = (PacketData*)pMemory->reallocate((void*)ringPacket.getData(), header.packetSize * sizeof(PacketData));
    ringPacket.init(packetPtr, header.packetSize);
    ringPacket.setStart(header.packetStart);
    ringPacket.setCount(header.packetCount);
    // load packet
    for(int i = 0; i < header.packetSize; i++)
    {
        progress = (i * 100) / header.packetSize;
        active = 1;
        SDL_RWread(ctxRead, (void*)(packetPtr + i), sizeof(PacketData), 1);
    }
    // count, start
    ringFrame.setStart(header.frameStart);
    ringFrame.setCount(header.frameCount);
    ringPacket.setStart(header.packetStart);
    ringPacket.setCount(header.packetCount);
    // data
    Ring<PacketData> readRing = ringPacket;
    uint memoryCount = readRing.getCount();
    for(uint i = 0; i < memoryCount; i++)
    {
        progress = (i * 100) / memoryCount;
        active   = 1;
        PacketData packet;
        readRing.read(packet);
        ularge ret = SDL_RWread(ctxRead, (void*)(data + packet.offset), packet.size, 1);
        if(ret != 1)
        {
            int debug = 1;
        }
    }
    // close
    SDL_RWclose(ctxRead);
    unlock();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
// CaptureSSD
//
////////////////////////////////////////////////////////////////////////////////
uint CaptureSSD::init(const char* file, ularge size, uint packetSize)
{
    fileName = file;
    memoryMax = memoryCurrent = size;
    ctx = SDL_RWFromFile(file, "w+");
    if(ctx)
    {
        SDL_RWclose(ctx);
    }
    allocateFrame(size, packetSize);
    allocatePacket(size, packetSize);
    return 0;
}

uint CaptureSSD::resize(ularge memory, ularge reserved)
{
    lock();
    ularge countPacket = memory / sizeof(CapturePacket);
    ularge countFrame  = countPacket / 2;
    ularge packetSize = countPacket * sizeof(PacketData);
    ularge frameSize  = countFrame *  sizeof(CaptureFrame);
    packetSize = max<ularge>((ularge)sizeof(PacketData) * 1000, packetSize);
    frameSize  = max<ularge>((ularge)sizeof(CaptureFrame) * 1000, frameSize);
    // frame
    CaptureFrame* pDataFrame = (CaptureFrame*)pMemory->reallocate((void*)ringFrame.getData(), frameSize);
    ringFrame.init(pDataFrame, countFrame);
    ringFrame.setCount(min<uint>(ringFrame.getCount(), countFrame));
    // packet
    PacketData* pDataPacket = (PacketData*)pMemory->reallocate((void*)ringPacket.getData(), packetSize);
    ringPacket.init(pDataPacket, countPacket);
    ringPacket.setCount(min<uint>(ringFrame.getCount(), countPacket));
    unlock();
    return 0;
}

uint CaptureSSD::save(const char* path, uint& progress, uint& active)
{
    lock();
    int version = 0;
    int frameHeader = 0;
    int frameData = 0;
    int framePacket = 0;
    pOsciloscope->thread.getFrame(&version, &frameHeader, &frameData, &framePacket);
    CaptureHeader header;
    header.hwVersion   = version;
    header.hwHeader    = frameHeader;
    header.hwData      = frameData;
    header.hwPacket    = framePacket;
    header.frameStart  = ringFrame.getStart();
    header.frameCount  = ringFrame.getCount();
    header.frameSize   = ringFrame.getSize();
    header.packetStart = ringPacket.getStart();
    header.packetCount = ringPacket.getCount();
    header.packetSize  = ringPacket.getSize();
    // write
    ctxWrite = SDL_RWFromFile(path, "w+b");
    // header
    SDL_RWwrite(ctxWrite, &header, sizeof(CaptureHeader), 1);
    // frame
    for(int i = 0; i < header.frameSize; i++)
    {
        progress = (i * 100) / header.frameSize;
        active   = 1;
        SDL_RWwrite(ctxWrite, ringFrame.getData() + i, sizeof(CaptureFrame), 1);
    }
    // packet
    for(int i = 0; i < header.packetSize; i++)
    {
        progress = (i * 100) / header.packetSize;
        active = 1;
        SDL_RWwrite(ctxWrite, ringPacket.getData() + i, sizeof(PacketData), 1);
    }
    // offset
    SDL_RWops* ctxRead = SDL_RWFromFile(fileName.asChar(), "rb");
    SDL_RWseek(ctxRead, sizeof(CaptureHeader), RW_SEEK_SET);
    SDL_RWseek(ctxRead, header.frameSize * sizeof(CaptureFrame), RW_SEEK_CUR);
    // data
    Ring<PacketData> readPacket = ringPacket;
    for(int i = 0; i < header.packetCount; i++)
    {
        progress = (i * 100) / header.packetCount;
        active   = 1;
        PacketData packet;
        readPacket.read(packet);
        SDL_RWread(ctxRead,   &transferPacket, packet.size, 1);
        SDL_RWwrite(ctxWrite, &transferPacket, packet.size, 1);
    }
    // close
    SDL_RWclose(ctxRead);
    SDL_RWclose(ctxWrite);
    unlock();
    return 0;
}

uint CaptureSSD::load(const char* path, uint& progress, uint& active)
{
    lock();
    int version = 0;
    int frameHeader = 0;
    int frameData = 0;
    int framePacket = 0;
    pOsciloscope->thread.getFrame(&version, &frameHeader, &frameData, &framePacket);
    // offset
    CaptureHeader header;
    SDL_RWops* ctxRead = SDL_RWFromFile(path, "rb");
    SDL_RWread(ctxRead, &header, sizeof(CaptureHeader), 1);
    if(header.hwVersion != version ||
       header.hwHeader != frameHeader ||
       header.hwData != frameData ||
       header.hwPacket != framePacket)
    {
        FORMAT_BUFFER();
        FORMAT(" version is %d but %d expected \n header is %d but %d expected \n data is %d but %d expected \n packet is %d but %d expected \n", header.hwVersion, version, header.hwHeader, frameHeader, header.hwData, frameData, header.hwPacket, framePacket);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "File header is incompatible.", formatBuffer, 0);
        unlock();
        return 1;
    }
    // reallocate frame memory
    CaptureFrame* framePtr = (CaptureFrame*)pMemory->reallocate((void*)ringFrame.getData(), header.frameSize * sizeof(CaptureFrame));
    ringFrame.init(framePtr, header.frameSize);
    ringFrame.setStart(header.frameStart);
    ringFrame.setCount(header.frameCount);
    // reallocate packet memory
    PacketData* packetPtr = (PacketData*)pMemory->reallocate((void*)ringPacket.getData(), header.packetSize * sizeof(PacketData));
    ringPacket.init(packetPtr, header.packetSize);
    ringPacket.setStart(header.packetStart);
    ringPacket.setCount(header.packetCount);
    // frame
    for(int i = 0; i < header.frameSize; i++)
    {
        progress = (i * 100) / header.frameSize;
        active   = 1;
        SDL_RWread(ctxRead, (void*)(framePtr + i), sizeof(CaptureFrame), 1);
    }
    // packet
    for(int i = 0; i < header.packetSize; i++)
    {
        progress = (i * 100) / header.packetSize;
        active = 1;
        SDL_RWread(ctxRead, (void*)(packetPtr + i), sizeof(PacketData), 1);
    }
    // count, start
    ringFrame.setStart(header.frameStart);
    ringFrame.setCount(header.frameCount);
    ringPacket.setStart(header.packetStart);
    ringPacket.setCount(header.packetCount);
    // write memory.ssd cache data
    // seek
    SDL_RWops* ctxWrite = SDL_RWFromFile(fileName.asChar(), "r+b");
    // header
    SDL_RWwrite(ctxWrite, &header, sizeof(CaptureHeader), 1);
    // frame
    for(int i = 0; i < header.frameSize; i++)
    {
        progress = (i * 100) / header.frameSize;
        active = 1;
        SDL_RWwrite(ctxWrite, ringFrame.getData() + i, sizeof(CaptureFrame), 1);
    }
    // packet
    for(int i = 0; i < header.packetSize; i++)
    {
        progress = (i * 100) / header.packetSize;
        active = 1;
        SDL_RWwrite(ctxWrite, ringPacket.getData() + i, sizeof(PacketData), 1);
    }
    // data
    Ring<PacketData> readPacket = ringPacket;
    for(int i = 0; i < header.packetCount; i++)
    {
        progress = (i * 100) / header.packetCount;
        active   = 1;
        PacketData packet;
        readPacket.read(packet);
        SDL_RWread(ctxRead, &transferPacket, packet.size, 1);
        SDL_RWwrite(ctxWrite, &transferPacket, packet.size, 1);
    }
    // close
    SDL_RWclose(ctxRead);
    SDL_RWclose(ctxWrite);
    unlock();
    return 0;
}

uint CaptureSSD::openWrite()
{
    ctxWrite = SDL_RWFromFile(fileName.asChar(), "r+b");
    return 0;
}

uint CaptureSSD::openRead()
{
    ctxRead = SDL_RWFromFile(fileName.asChar(), "rb");
    return 0;
}

uint CaptureSSD::write(ularge pos, byte* buffer, ularge size)
{
    SDL_RWseek(ctxWrite, sizeof(CaptureHeader) + ringFrame.getSize()*sizeof(CaptureFrame) + ringPacket.getSize()*sizeof(PacketData) + pos, RW_SEEK_SET);
    SDL_RWwrite(ctxWrite, buffer, size, 1);
    return 0;
}

uint CaptureSSD::read(ularge pos, byte* buffer, ularge size)
{
    SDL_RWseek(ctxRead, sizeof(CaptureHeader) + ringFrame.getSize()*sizeof(CaptureFrame) + ringPacket.getSize()*sizeof(PacketData) + pos, RW_SEEK_SET);
    SDL_RWread(ctxRead, buffer, size, 1);
    return 0;
}

uint CaptureSSD::closeWrite()
{
    SDL_RWclose(ctxWrite);
    ctxWrite = 0;
    return 0;
}

uint CaptureSSD::closeRead()
{
    SDL_RWclose(ctxRead);
    ctxRead = 0;
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
// CaptureBuffer
//
////////////////////////////////////////////////////////////////////////////////
/*
CaptureBuffer::CaptureBuffer(byte* buff1, uint size1, byte* buff2, uint size2)
{
    displayPtr       = buff1;
    displaySize      = size1;
    displayRead      = 0;
    displayFrameSize = 0;
    rldPtr           = buff2;
    rldSize          = size2;
    rldWritten       = 0;
    rldStart         = 0;
    SDL_memset(&syncHeader1, 0, sizeof(SFrameHeader1));
    SDL_memset(&syncHeader2, 0, sizeof(SFrameHeader2));
    SDL_AtomicSet(&lastFrame, 0);
    SDL_AtomicSet(&drawState, DRAWSTATE_DRAW);
    SDL_AtomicSet(&drawFrame, 0);
}

void CaptureBuffer::clear()
{
    displayRead      = 0;
    displayFrameSize = 0;
    history->lock();
    history->ringFrame.clear();
    history->ringPacket.clear();
    history->unlock();
}

uint CaptureBuffer::getFrameSize(byte* buffer, uint version, uint headerSize, uint data, uint packet)
{
    uint frameSize = 0;
    if(version == 1)
    {
        SFrameHeader1* header = (SFrameHeader1*)buffer;
        if(header->magic.bytes[0] == 0xDD && header->magic.bytes[1] == 0xDD)
        {
            frameSize = (uint)(data + headerSize);
        }
    }
    else
    {
        SFrameHeader2* header = (SFrameHeader2*)buffer;
        if(header->magic.bytes[0] == 0xDD && header->magic.bytes[1] == 0xDD)
        {
            uint     byte0 = header->hardware.bytes[32 + 0];
            uint     byte1 = header->hardware.bytes[32 + 1];
            uint     byte2 = header->hardware.bytes[32 + 2];
            uint     byte3 = header->hardware.bytes[32 + 3];
            uint sampleSize = (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3;
            frameSize = sampleSize * 4 + sizeof(SFrameHeader2);
        }
    }
    if(frameSize % 512 != 0)
    {
        frameSize = ((frameSize / 512) + 1) * 512;
    }
    return frameSize;
}


uint CaptureBuffer::getFrameSamples(byte* buffer, uint version, uint header, uint data, uint packet)
{
    uint frameSamples = 0;
    if(version == 1)
    {
        SFrameHeader1* header = (SFrameHeader1*)buffer;
        if(header->magic.bytes[0] == 0xDD && header->magic.bytes[1] == 0xDD)
        {
            frameSamples = (uint)(data / 6);
        }
    }
    else
    {
        SFrameHeader2* header = (SFrameHeader2*)buffer;
        if(header->magic.bytes[0] == 0xDD && header->magic.bytes[1] == 0xDD)
        {
            uint     byte0 = header->hardware.bytes[32 + 0];
            uint     byte1 = header->hardware.bytes[32 + 1];
            uint     byte2 = header->hardware.bytes[32 + 2];
            uint     byte3 = header->hardware.bytes[32 + 3];
            frameSamples = (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3;
        }
    }
    return frameSamples;
}

uint CaptureBuffer::getFrameDataSize(byte* buffer, uint version, uint header, uint data, uint packet)
{
    uint   frameDataSize = 0;
    uint    frameSamples = getFrameSamples(buffer, version, header, data, packet);
    if(version == 1)
    {
        frameDataSize = 6 * frameSamples;
    }
    else
    {
        frameDataSize = 4 * frameSamples;
        if(frameDataSize % 1024 != 0)
        {
            frameDataSize = ((frameDataSize / 1024) + 1) * 1024;
        }
    }
    return frameDataSize;
}

uint CaptureBuffer::getOneSampleBytes(uint version)
{
    if(version == 1)
    {
        return 6;
    }
    if(version == 2)
    {
        return 4;
    }
    return 1;
}

uint CaptureBuffer::getCompression(byte* buffer)
{
    return 0;
}

SFrameHeader1 CaptureBuffer::getHeader1(byte* buffer, uint size)
{
    SFrameHeader1 header = { 0 };
    // size
    if(size < (uint)SCOPEFUN_FRAME_1_HEADER)
    {
        return header;
    }
    // magic
    if(buffer[0] != 0xDD && buffer[1] != 0xDD)
    {
        return header;
    }
    // copy
    SDL_memcpy(&header, buffer, min((uint)SCOPEFUN_FRAME_1_HEADER, size));
    // return
    return header;
}


SFrameHeader2 CaptureBuffer::getHeader2(byte* buffer, uint size)
{
    SFrameHeader2 header = { 0 };
    if(buffer == 0)
    {
        int debug = 1;
    }
    // size
    if(size < (uint)SCOPEFUN_FRAME_2_HEADER)
    {
        return header;
    }
    // magic
    if(buffer[0] != 0xDD && buffer[1] != 0xDD)
    {
        return header;
    }
    // copy
    uint copySize = min((uint)SCOPEFUN_FRAME_2_HEADER, size);
    SDL_memcpy(&header, buffer, copySize);
    // return
    return header;
}

uint CaptureBuffer::uncompressNew()
{
    // new decoding
    rldWritten = 0;
    rldStart = 0;
    while(SDL_AtomicGet(&drawState) != DRAWSTATE_DRAW)
    { SDL_Delay(1); }
    history->lock();
    CaptureFrame captureFrame;
    captureFrame.packetStart = history->ringPacket.getWrite();
    int nextWrite = history->ringFrame.getWrite();
    SDL_AtomicSet(&lastFrame, nextWrite);
    SDL_AtomicSet(&drawFrame, nextWrite);
    SDL_AtomicSet(&drawState, DRAWSTATE_FILL);
    history->ringFrame.write(captureFrame);
    history->unlock();
    return 0;
}

uint CaptureBuffer::uncompress(byte* buffer, uint received, uint transfered, uint version, uint headerSize, uint data, uint packet, bool isHeader)
{
    // compression
    uint compressionType = getCompression(buffer);
    // where we left previously ?
    rldStart   = 0;
    rldWritten = 0;
    // uncompress data
    if(compressionType > 0 && received >= uint(headerSize) && version == 2)
    {
        // rle uncompress
        byte* compressedStart = buffer;
        uint  compressedSize  = transfered;
        for(uint i = 0; i < compressedSize; i++)
        {
            byte repeat = compressedStart[i];
            if(repeat > 128)
            {
                uint count = 128 - repeat;
                for(uint j = 0; j < count; j++)
                {
                    uint index = i + j + 1;
                    if(index < compressedSize)
                    {
                        if(rldWritten < rldSize)
                        {
                            rldPtr[rldWritten] = compressedStart[index];
                            rldWritten++;
                        }
                    }
                }
            }
            else
            {
                uint count = repeat;
                uint  index = i + 1;
                if(index < compressedSize)
                {
                    byte value = compressedStart[index];
                    for(uint j = 0; j < count; j++)
                    {
                        if(rldWritten < rldSize)
                        {
                            rldPtr[rldWritten] = value;
                            rldWritten++;
                        }
                    }
                }
            }
        }
    }
    else
    {
        // transfered
        rldWritten += transfered;
        // safety
        rldWritten = min(rldWritten, rldSize);
        // not compressed
        SDL_memcpy(&rldPtr[0], buffer, rldWritten);
    }
    return 0;
}
*/


// uint CaptureBuffer::display(OsciloscopeFrame& frame, int version, int headerSize, int dataSize, int packetSize)
// {
    //OsciloscopeCamera camera   = pOsciloscope->cameraOsc;
    //double signalZoom          = pOsciloscope->signalZoom;
    //double signalPosition      = pOsciloscope->signalPosition;
    //double signalMin           = -0.5 / signalZoom;
    //double signalMax           =  0.5 / signalZoom;
    //double signalDelta         = signalMax - signalMin;
    //double signalPosNormalized = 1.0 - (signalPosition + signalMax) / signalDelta;
    //int extraEdgeSamples  = 2;
    //ularge      captureStart = 0;
    //ularge       captureFreq = 0;
    //// samples
    //uint frameSamples = getFrameSamples(displayPtr, version, headerSize, dataSize, packetSize);
    //uint oneSampleBytes = getOneSampleBytes(version);
    //// samples
    //if(frameSamples > 0 && displayRead > uint(headerSize))
    //{
    //    // data
    //    byte* dataStart = displayPtr + uint(headerSize);
    //    uint  dataBytes = displayRead - uint(headerSize);
    //    frameSamples += extraEdgeSamples;
    //    // increment
    //    double   dSamples = double(frameSamples) * signalZoom;
    //    double   cameraIncrement = dSamples / double(NUM_SAMPLES);
    //    int    sampleStart = 0;
    //    int    sampleEnd = frameSamples;
    //    double signalOffset = 0.0;
    //    // visibility
    //    uint visibility = 1;
    //    uint signalHide = 0;
    //    if(visibility)
    //    {
    //        if(pOsciloscope->window.fftDigital.is(VIEW_SELECT_OSC_3D))
    //        {
    //            signalPosNormalized = 0.5;
    //            signalZoom = 1.0;
    //        }
    //        // cameraSampleSize
    //        int sampleFull = ceil(double(dSamples));
    //        int sampleHalf = ceil(double(sampleFull) / 2);
    //        sampleHalf = max(1, sampleHalf);
    //        int sampleCenter = double(frameSamples) * signalPosNormalized;
    //        signalOffset = (signalPosNormalized - (double(sampleCenter) / double(frameSamples))) / signalZoom;
    //        // start
    //        sampleStart = sampleCenter - sampleHalf;
    //        if(sampleStart < 0)
    //        {
    //            sampleCenter = sampleCenter + (-sampleStart);
    //            sampleStart = 0;
    //        }
    //        sampleStart = clamp<int>(sampleStart, 0, frameSamples);
    //        // end
    //        sampleEnd = sampleCenter + sampleHalf;
    //        sampleEnd = clamp<int>(sampleEnd, 0, frameSamples);
    //    }
    //    // count
    //    uint sampleCount = sampleEnd - sampleStart;
    //    sampleCount = clamp<uint>(sampleCount, 0, frameSamples);
    //    // safety, this must be last becouse of zoom
    //    sampleStart = clamp<int>(sampleStart, 0, frameSamples);
    //    // clear frame
    //    frame.clear();
    //    // must always start rendering at the sample, so extra edge samples are needed
    //    float sampleDelta = 1.0f / max<float>(1.0, (sampleCount));
    //    frame.edgeOffset = signalOffset;
    //    frame.edgeSample = extraEdgeSamples;
    //    // samples loop
    //    ishort minCh0 = 512; // todo: change with new firmware
    //    ishort minCh1 = 512;
    //    ishort maxCh0 = -512;
    //    ishort maxCh1 = -512;
    //    ishort digital = 0;
    //    byte attribute = 0;
    //    double inc = 0.f;
    //    for(uint i = sampleStart; i < (sampleStart + sampleCount);)
    //    {
    //        uint offset = 0;
    //        ushort ch0 = 0;
    //        ushort ch1 = 0;
    //        ushort dig = 0;
    //        if(version == 1)
    //        {
    //            offset = i * 6;
    //            ch0 = *(ushort*)(dataStart + offset + 0);
    //            ch1 = *(ushort*)(dataStart + offset + 2);
    //            dig = *(ushort*)(dataStart + offset + 4);
    //        }
    //        if(version == 2)
    //        {
    //            offset = i * 4;
    //            byte byte0 = *(dataStart + offset + 0);
    //            byte byte1 = *(dataStart + offset + 1);
    //            byte byte2 = *(dataStart + offset + 2);
    //            byte byte3 = *(dataStart + offset + 3);
    //            ch0 |= byte0;
    //            ch0 = ch0 << 2;
    //            ch0 |= ((byte1 >> 6) & 0x3F);
    //            ch1 |= (byte1 & 0x3F);
    //            ch1 = ch1 << 4;
    //            ch1 |= ((byte2 >> 4) & 0xF);
    //            dig |= (byte2 & 0xF);
    //            dig = dig << 8;
    //            dig |= byte3;
    //        }
    //        // attribute
    //        if(version == 1)
    //        {
    //            if(ch0 & 0x8000)
    //            {
    //                attribute |= FRAME_ATTRIBUTE_HIDE_SIGNAL;
    //            }
    //            if(ch0 & 0x4000)
    //            {
    //                attribute |= FRAME_ATTRIBUTE_TRIGGERED_LED;
    //            }
    //            if(ch0 & 0x2000)
    //            {
    //                attribute |= FRAME_ATTRIBUTE_ROLL_DISPLAY;
    //            }
    //        }
    //        // channels
    //        ishort singedShort0 = leadBitShift(ch0 & 0x000003FF);
    //        ishort singedShort1 = leadBitShift(ch1 & 0x000003FF);
    //        // analog
    //        minCh0 = min(minCh0, singedShort0);
    //        maxCh0 = max(maxCh0, singedShort0);
    //        minCh1 = min(minCh1, singedShort1);
    //        maxCh1 = max(maxCh1, singedShort1);
    //        // digital
    //        digital = digital | dig; // todo: user interface function choice
    //        // display sample ?
    //        bool display = false;
    //        if(cameraIncrement < 1.0)
    //        {
    //            display = true;
    //            i++;
    //        }
    //        if(cameraIncrement >= 1.0)
    //        {
    //            uint iInc = uint(cameraIncrement);
    //            if(i % iInc == 0)
    //            {
    //                display = true;
    //                i += iInc;
    //            }
    //            else
    //            {
    //                i++;
    //            }
    //        }
    //        if(display)
    //        {
    //            // mix / max -> value
    //            ishort value0 = 0;
    //            ishort value1 = 0;
    //            if(-minCh0 > maxCh0)
    //            {
    //                value0 = minCh0;
    //            }
    //            else
    //            {
    //                value0 = maxCh0;
    //            }
    //            if(-minCh1 > maxCh1)
    //            {
    //                value1 = minCh1;
    //            }
    //            else
    //            {
    //                value1 = maxCh1;
    //            }
    //            // analog
    //            if(frame.analog[0].getCount() < NUM_SAMPLES)
    //            {
    //                frame.analog[0].pushBack(value0);
    //            }
    //            if(frame.analog[1].getCount() < NUM_SAMPLES)
    //            {
    //                frame.analog[1].pushBack(value1);
    //            }
    //            // attribute
    //            if(frame.attr.getCount() < NUM_SAMPLES)
    //            {
    //                frame.attr.pushBack(attribute);
    //            }
    //            // digital
    //            if(frame.digital.getCount() < NUM_SAMPLES)
    //            {
    //                frame.digital.pushBack(digital);
    //            }
    //            minCh0 = 512; // todo: change with new firmware
    //            minCh1 = 512;
    //            maxCh0 = -512;
    //            maxCh1 = -512;
    //            digital = 0;
    //            attribute = 0;
    //        }
    //    }
    //    // ets & trigger
    //    int index = clamp<int>(pOsciloscope->settings.getHardware()->fpgaEtsIndex, 0, headerSize);
    //    frame.ets = (displayPtr)[index];
    //    // temperature
    //    unsigned short adc0 = (displayPtr)[6] << 8;
    //    unsigned short adc1 = (displayPtr)[7];
    //    unsigned short adc = adc1 | adc0;
    //    float temperature = ((float(adc) * 503.975) / 4096) - 273.15;
    //    frame.debug.setCount(2464);
    //    frame.debug[0] = 0;
    //    frame.debug[1] = temperature;
    //    for(int i = 0; i < 62; i++)
    //    {
    //        frame.debug[i + 2] = displayPtr[i + 8];
    //    }
    //    // trigger
    //    frame.triggerTime = *(ularge*)(displayPtr + 2);
    //    if(frame.triggerTime == 0)
    //    {
    //        frame.firstFrame = SDL_GetPerformanceCounter();
    //        frame.utc = ::time(0);
    //    }
    //    frame.thisFrame = SDL_GetPerformanceCounter();
    //    // captureTime
    //    frame.captureTime = double(frame.thisFrame - captureStart) / double(captureFreq);
    //    return 1;
    //}
   // return 0;
//}

/*
uint CaptureBuffer::captureFrameLast()
{
    return SDL_AtomicGet(&drawFrame);
}

uint CaptureBuffer::captureFrameCount()
{
    uint frameCount = history->ringFrame.getCount();
    return frameCount;
}

uint CaptureBuffer::captureFrameSize()
{
    uint frameSize = history->ringFrame.getSize();
    return frameSize;
}

uint CaptureBuffer::captureFrame(CaptureFrame& frame, uint index)
{
    history->lock();
    if(!history->ringFrame.isEmpty())
    {
        Ring<CaptureFrame> tmpRing = history->ringFrame;
        frame = *tmpRing.peek(index);
    }
    history->unlock();
    return 0;
}
*/

////////////////////////////////////////////////////////////////////////////////
//
// OsciloscopeFrame
//
////////////////////////////////////////////////////////////////////////////////
OsciloscopeFrame::OsciloscopeFrame()
{
    SDL_zero(*this);
}

ishort OsciloscopeFrame::getAnalogShort(uint channel, uint sample)
{
    uint count = analog[channel].getCount();
    if(!count)
    {
        return 0;
    }
    uint      idx = clamp<uint>(sample, 0, count - 1);
    ishort ivalue = analog[channel][idx];
    return ivalue;
}

float OsciloscopeFrame::getAnalog(uint channel, uint sample)
{
    uint count = analog[channel].getCount();
    if(!count)
    {
        return 0.f;
    }
    int       idx = clamp<uint>(sample, 0, count - 1);
    ishort ivalue = analog[channel][idx];
    float  fvalue = float(ivalue) / MAXOSCVALUE;
    return clamp(fvalue, -1.f, 1.f);
}

double OsciloscopeFrame::getAnalogDouble(uint channel, uint sample)
{
    uint count = analog[channel].getCount();
    if(!count)
    {
        return 0.0;
    }
    int       idx = clamp<uint>(sample, 0, count - 1);
    ishort ivalue = analog[channel][idx];
    double  fvalue = double(ivalue) / double(MAXOSCVALUE);
    return clamp(fvalue, -1.0, 1.0);
}

ishort OsciloscopeFrame::getDigital(uint channel, uint sample)
{
    uint count = digital.getCount();
    if(!count)
    {
        return 0;
    }
    int       idx = clamp<uint>(sample, 0, count - 1);
    ishort ivalue = digital[idx];
    ishort    bit = (ivalue >> channel) & 0x0001;
    return bit;
}

ushort OsciloscopeFrame::getDigitalChannels(uint sample)
{
    uint count = digital.getCount();
    if(!count)
    {
        return 0;
    }
    int       idx = clamp<uint>(sample, 0, count - 1);
    ushort value = digital[idx];
    return value;
}

float rand_FloatRange(float a, float b)
{
    return ((b - a) * ((float)rand() / RAND_MAX)) + a;
}

void OsciloscopeFrame::generate(double dt, uint amount, double captureStart, double captureFreq)
{
    if(pOsciloscope->signalMode != SIGNAL_MODE_SIMULATE)
    {
        return;
    }
    deltaTime[0] += dt;
    deltaTime[1] += dt;
    //////////////////////////////////////////////////
    // ets
    //////////////////////////////////////////////////
    ets = rand() % pOsciloscope->settings.getHardware()->fpgaEtsCount;
    //////////////////////////////////////////////////
    // analog
    //////////////////////////////////////////////////
    for(int i = 0; i < 2; i++)
    {
        // on/off
        if(pOsciloscope->window.softwareGenerator.channel[i].onOff == 0)
        {
            continue;
        }
        // capture
        float captureTime = pOsciloscope->window.horizontal.Capture * float(NUM_SAMPLES);
        float captureVolt = 0;
        if(i == 0)
        {
            captureVolt = pOsciloscope->window.channel01.Capture;
        }
        if(i == 1)
        {
            captureVolt = pOsciloscope->window.channel02.Capture;
        }
        // channels
        SoftwareGeneratorChannel* pGenerate = 0;
        if(i == 0)
        {
            pGenerate = &pOsciloscope->window.softwareGenerator.channel[0];
        }
        if(i == 1)
        {
            pGenerate = &pOsciloscope->window.softwareGenerator.channel[1];
        }
        GenerateType type       = pGenerate->type;
        float        period     = pGenerate->period;
        float        peaktopeak = pGenerate->peakToPeak;
        float        speed      = pGenerate->speed;
        // generate only on specified time
        if(deltaTime[i] < pGenerate->every)
        {
            continue;
        }
        if(!pOsciloscope->window.horizontal.ETS)
        {
            generateTime[i] += deltaTime[i] * speed;
        }
        deltaTime[i] = 0;
        // min/max peak
        float minpeak = -peaktopeak / 2.f;
        float maxpeak = peaktopeak / 2.f;
        // frame size
        float displayFrameSize = float(NUM_SAMPLES);
        // generate
        srand((uint)SDL_GetPerformanceCounter());
        float value = 0;
        for(uint j = 0; j < amount; j++)
        {
            switch(type)
            {
                case GENERATE_SINUS:
                case GENERATE_COSINUS:
                    {
                        float  normalizedTime = float(j) / float(displayFrameSize) + float(generateTime[i]);
                        float  signaltime  = (normalizedTime * captureTime);
                        float            t = (signaltime / period);
                        float    angle2Pi  = 2.f * PI * (t);
                        switch(type)
                        {
                            case GENERATE_SINUS   :
                                value = maxpeak * sinf(angle2Pi);
                                break;
                            case GENERATE_COSINUS :
                                value = maxpeak * cosf(angle2Pi);
                                break;
                            default:
                                break;
                        };
                    }
                    break;
                case GENERATE_DECREMENT:
                case GENERATE_INCREMENT:
                    {
                        float  normalizedTime   = float(j) / float(displayFrameSize) + float(generateTime[i]);
                        float  normalizedPeriod = period / captureTime;
                        double input            = normalizedPeriod;
                        float mod               = (float)modf(normalizedTime, &input);
                        float div               = mod / (normalizedPeriod);
                        switch(type)
                        {
                            case GENERATE_INCREMENT :
                                value = div * peaktopeak + minpeak;
                                break;
                            case GENERATE_DECREMENT :
                                value = (1.f - div) * peaktopeak + minpeak;
                                break;
                            default:
                                break;
                        };
                    }
                    break;
                case GENERATE_CONSTANT:
                    value = peaktopeak;
                    break;
                case GENERATE_RADOM:
                    value = rand_FloatRange(-1.f, 1.f) * (peaktopeak / 2.f);
                    break;
                case GENERATE_SQUARE:
                    {
                        float  normalizedTime = float(j) / float(displayFrameSize) + generateTime[i];
                        float  normalizedPeriod = period / captureTime;
                        float  time = fmod(normalizedTime, 1.0f);
                        if(time < normalizedPeriod)
                        {
                            value = peaktopeak;
                        }
                        else
                        {
                            value = 0.f;
                        }
                    }
                    break;
                case GENERATE_DELTA:
                    {
                        float  normalizedTime = float(j) / float(displayFrameSize) + generateTime[i];
                        float  normalizedPeriod = period / captureTime;
                        float  time = fmod(normalizedTime, 1.0f);
                        float      t = time / normalizedPeriod / 2;
                        if(time < normalizedPeriod / 2)
                        {
                            value = 4.0 * t * peaktopeak;
                        }
                        else if(time < normalizedPeriod)
                        {
                            value = 4.0 * (0.5f - t) * peaktopeak;
                        }
                        else
                        {
                            value = 0.f;
                        }
                    }
                    break;
            };
            float normalized = float(value) / (5.f * float(captureVolt));
            normalized = clamp<float>(normalized, -1.0, 1.0);
            ishort val = (ishort)(float(normalized) * MAXOSCVALUE);
            if(analog[i].getCount() < NUM_SAMPLES)
            {
                analog[i].pushBack(val);
            }
        }
    }
    //////////////////////////////////////////////////
    // digital
    //////////////////////////////////////////////////
    srand((uint)SDL_GetPerformanceCounter());
    for(uint i = 0; i < amount; i++)
    {
        byte digital0 = rand() % 2;
        byte digital1 = rand() % 2;
        byte digital2 = rand() % 2;
        byte digital3 = rand() % 2;
        byte digital4 = rand() % 2;
        byte digital5 = rand() % 2;
        byte digital6 = rand() % 2;
        byte digital7 = rand() % 2;
        byte digital8 = rand() % 2;
        byte digital9 = rand() % 2;
        byte digital10 = rand() % 2;
        byte digital11 = rand() % 2;
        byte digital12 = rand() % 2;
        byte digital13 = rand() % 2;
        byte digital14 = rand() % 2;
        byte digital15 = rand() % 2;
        ushort bits   = digital0 | (digital1 << 1) | (digital2 << 2) | (digital3 << 3) | (digital4 << 4) | (digital5 << 5) | (digital6 << 6) | (digital7 << 7);
        bits  |= digital8 << 8 | (digital9 << 9) | (digital10 << 10) | (digital11 << 11) | (digital12 << 12) | (digital13 << 13) | (digital14 << 14) | (digital15 << 15);
        if(digital.getCount() < NUM_SAMPLES)
        {
            digital.pushBack(bits);
        }
    }
    // attrobutes
    for(uint i = 0; i < amount; i++)
    {
        attr.pushBack(0);
    }
    // debug
    debug.clear();
    for(uint i = 0; i < 416; i++)
    {
        debug.pushBack(rand() % 256);
    }
    triggerTime = 0;
    time(&utc);
    thisFrame   = firstFrame = SDL_GetPerformanceCounter();
    captureTime = double(SDL_GetPerformanceCounter() - captureStart) / double(captureFreq);
}

////////////////////////////////////////////////////////////////
//
// time
//
////////////////////////////////////////////////////////////////
void OsciloscopeFrame::getTime(char* buffer, int size)
{
    FORMAT_BUFFER();
    struct tm* local  = localtime((time_t*)&utc);
    if(local)
    {
        ularge     offset = (this->thisFrame - this->firstFrame) + this->triggerTime;
        FORMAT("%d|%d|%d - %d|%d|%d - %llu", (local->tm_year + 1900), (local->tm_mon + 1), (local->tm_mday), (local->tm_hour + 1), (local->tm_min + 1), (local->tm_sec + 1), offset);
    }
    else
    {
        FORMAT("%s", "triggerTime zero missing!");
    }
    memcpy(buffer, formatBuffer, min(size, FORMAT_BUFFER_SIZE));
}

////////////////////////////////////////////////////////////////
//
// header  - 2464 bytes
// data    - 60000 bytes
//
////////////////////////////////////////////////////////////////
bool OsciloscopeFrame::captureHeader(byte* src, uint size, ularge captureStart, ularge captureFreq)
{
    // src
    if(!src)
    {
        return false;
    }
    // size
    if(size < CAPTURE_BUFFER_HEADER)
    {
        return false;
    }
    // debug
    debug.clear();
    for(uint i = 0; i < CAPTURE_BUFFER_HEADER; i++)
    {
        debug.pushBack(src[i]);
    }
    // magic DDDD
    ushort header = *(ushort*)src;
    if(header != 56797)
    {
        return false;
    }
    // ets
    int index = clamp<int>(pOsciloscope->settings.getHardware()->fpgaEtsIndex, 0, debug.getCount() - 1);
    ets = debug[index];
    // trigger
    triggerTime = *(ularge*)(src + 2);
    if(triggerTime == 0)
    {
        firstFrame = SDL_GetPerformanceCounter();
        utc        = ::time(0);
    }
    thisFrame = SDL_GetPerformanceCounter();
    // captureTime
    captureTime = double(thisFrame - captureStart) / double(captureFreq);
    return true;
}

bool OsciloscopeFrame::captureData(byte* src, uint& pos, uint size)
{
    // src
    if(!src)
    {
        return false;
    }
    byte* shortBuffer = src  + pos;
    uint   numBytes   = size - pos;
    uint numSamples   = numBytes / 6;
    for(uint i = 0; i < numSamples; i++)
    {
        // raw data
        ushort short0 = *(ushort*)&shortBuffer[0];
        ushort short1 = *(ushort*)&shortBuffer[2];
        ushort short2 = *(ushort*)&shortBuffer[4];
        shortBuffer += 6;
        // attribute
        byte attribute = 0;
        if(short0 & 0x8000)
        {
            attribute |= FRAME_ATTRIBUTE_HIDE_SIGNAL;
        }
        if(short0 & 0x4000)
        {
            attribute |= FRAME_ATTRIBUTE_TRIGGERED_LED;
        }
        if(short0 & 0x2000)
        {
            attribute |= FRAME_ATTRIBUTE_ROLL_DISPLAY;
        }
        if(attr.getCount() < NUM_SAMPLES)
        {
            attr.pushBack(attribute);
        }
        // analog
        ishort singedShort0 = leadBitShift(short0 & 0x000003FF);
        ishort singedShort1 = leadBitShift(short1 & 0x000003FF);
        if(analog[0].getCount() < NUM_SAMPLES)
        {
            analog[0].pushBack(singedShort0);
        }
        if(analog[1].getCount() < NUM_SAMPLES)
        {
            analog[1].pushBack(singedShort1);
        }
        // digital
        if(digital.getCount() < NUM_SAMPLES)
        {
            digital.pushBack(short2);
        }
    }
    pos += numSamples * 6;
    uint endByte = pos + (size - pos);
    if(endByte / 6 == NUM_SAMPLES)
    {
        return true;
    }
    return false;
}

int OsciloscopeFrame::isFull()
{
    int numSamples = int(NUM_SAMPLES); //pOsciloscope->control.frameSize;
    if(analog[0].getCount() >= numSamples)
    {
        return 1;
    }
    if(analog[1].getCount() >= numSamples)
    {
        return 1;
    }
    if(digital.getCount()   >= numSamples)
    {
        return 1;
    }
    return 0;
}

void OsciloscopeFrame::clear()
{
    analog[0].clear();
    analog[1].clear();
    digital.clear();
    attr.clear();
}

///////////////////////////////////////////////////////////////////////////
//
// parser
//
///////////////////////////////////////////////////////////////////////////

double OscToken::evaluate(double par1, double par2)
{
    switch(type)
    {
        case tAdd:
            return par1 + par2;
        case tSub:
            return par1 - par2;
        case tMul:
            return par1 * par2;
        case tDiv:
            return par1 / par2;
        case tMod:
            return (double)((int)par1 % max<int>(1, (int)par2));
        case tMin:
            return min<double>(par1, par2);
        case tMax:
            return max<double>(par1, par2);
    };
    return 0;
}

double OscToken::evaluate(double par)
{
    switch(type)
    {
        case tSin:
            return sin(par);
        case tCos:
            return cos(par);
    };
    return 0;
}

void OsciloscopeFunction::parse()
{
    int precedence[tLast] =
    {
        2, // tAdd
        2, // tSub
        3, // tMul
        3, // tDiv
        3, // tMod
        3, // tMin
        3, // tMax
        3, // tSin
        3, // tCos
        1, // tCh0
        1, // tCh1
        1, // tNumber
        1, // tDouble
        1, // tLeft
        1, // tRight
        0, // tSeparator
    };
    postfix.setCount(0);
    Array<OscToken, 128> stack;
    for(int i = 0; i < tokens.getCount(); i++)
    {
        OscToken token = tokens[i];
        switch(token.type)
        {
            case tSeperator:
                break;
            case tCh0:
            case tCh1:
            case tNumber:
            case tDouble:
                {
                    postfix.pushBack(token);
                }
                break;
            case tLeft:
                {
                    stack.pushBack(token);
                }
                break;
            case tRight:
                {
                    OscToken top = stack.last();
                    stack.popBack();
                    while(top.type != tLeft)
                    {
                        postfix.pushBack(top);
                        top = stack.last();
                        stack.popBack();
                    }
                }
                break;
            default:
                {
                    while(stack.getCount() && precedence[stack.last().type] >= precedence[token.type])
                    {
                        postfix.pushBack(stack.last());
                        stack.popBack();
                    }
                    stack.pushBack(token);
                }
                break;
        };
    };
    while(stack.getCount())
    {
        postfix.pushBack(stack.last());
        stack.popBack();
    }
}

void OsciloscopeFunction::tokenize(String in)
{
    String input;
    int len = 0;
    for(int i = 0; i < in.getLength(); i++)
    {
        if(in[i] == '0' ||
           in[i] == '1' ||
           in[i] == '2' ||
           in[i] == '3' ||
           in[i] == '4' ||
           in[i] == '5' ||
           in[i] == '6' ||
           in[i] == '7' ||
           in[i] == '8' ||
           in[i] == '9' ||
           in[i] == '+' ||
           in[i] == '-' ||
           in[i] == '*' ||
           in[i] == '/' ||
           in[i] == '%' ||
           in[i] == ' ' ||
           in[i] == ',' ||
           in[i] == '.' ||
           in[i] == 'm' ||
           in[i] == 'i' ||
           in[i] == 'n' ||
           in[i] == 'm' ||
           in[i] == 'a' ||
           in[i] == 'x' ||
           in[i] == 's' ||
           in[i] == 'i' ||
           in[i] == 'n' ||
           in[i] == 'c' ||
           in[i] == 'o' ||
           in[i] == 's' ||
           in[i] == '(' ||
           in[i] == ')' ||
           in[i] == 'c' ||
           in[i] == 'h' ||
           in[i] == '0' ||
           in[i] == 'c' ||
           in[i] == 'h' ||
           in[i] == '1')
        {
            input.setLength(i + 1);
            input[i] = in[i];
        }
    }
    tokens.setCount(0);
    // tokenize
    OscToken token;
    String   number;
    int     i = 0;
    while(i < input.getLength())
    {
        // number
        {
            number.setLength(0);
            token.type = tLast;
            while(i < input.getLength() && (input[i] == '0' ||
                                            input[i] == '1' ||
                                            input[i] == '2' ||
                                            input[i] == '3' ||
                                            input[i] == '4' ||
                                            input[i] == '5' ||
                                            input[i] == '6' ||
                                            input[i] == '7' ||
                                            input[i] == '8' ||
                                            input[i] == '9' ||
                                            input[i] == '.'))
            {
                if(input[i] == '.')
                {
                    token.type = tDouble;
                }
                else if(token.type == tLast)
                {
                    token.type = tNumber;
                }
                number.insert(number.getLength(), input[i]);
                i++;
            }
            if(token.type == tNumber)
            {
                token.value = atoi(number.asChar());
                tokens.pushBack(token);
                continue;
            }
            if(token.type == tDouble)
            {
                token.value = atof(number.asChar());
                tokens.pushBack(token);
                continue;
            }
        }
        // operators
        if(input[i] == '+')
        {
            token.type = tAdd;
            tokens.pushBack(token);
            i++;
            continue;
        }
        if(input[i] == '-')
        {
            token.type = tSub;
            tokens.pushBack(token);
            i++;
            continue;
        }
        if(input[i] == '*')
        {
            token.type = tMul;
            tokens.pushBack(token);
            i++;
            continue;
        }
        if(input[i] == '/')
        {
            token.type = tDiv;
            tokens.pushBack(token);
            i++;
            continue;
        }
        if(input[i] == '%')
        {
            token.type = tMod;
            tokens.pushBack(token);
            i++;
            continue;
        }
        // brace
        if(input[i] == '(')
        {
            token.type = tLeft;
            tokens.pushBack(token);
            i++;
            continue;
        }
        if(input[i] == ')')
        {
            token.type = tRight;
            tokens.pushBack(token);
            i++;
            continue;
        }
        // separator
        if(input[i] == ',' || input[i] == ' ')
        {
            token.type = tSeperator;
            tokens.pushBack(token);
            i++;
            continue;
        }
        // functions
        if(i + 2 < input.getLength())
        {
            int pos = 0;
            // functions
            pos = input.pos("sin", i);
            if(pos == i)
            {
                token.type = tSin;
                tokens.pushBack(token);
                i += 3;
                continue;
            }
            pos = input.pos("cos", i);
            if(pos == i)
            {
                token.type = tCos;
                tokens.pushBack(token);
                i += 3;
                continue;
            }
            pos = input.pos("min", i);
            if(pos == i)
            {
                token.type = tMin;
                tokens.pushBack(token);
                i += 3;
                continue;
            }
            pos = input.pos("max", i);
            if(pos == i)
            {
                token.type = tMax;
                tokens.pushBack(token);
                i += 3;
                continue;
            }
            // channel
            pos = input.pos("ch0", i);
            if(pos == i)
            {
                token.type = tCh0;
                tokens.pushBack(token);
                i += 3;
                continue;
            }
            pos = input.pos("ch1", i);
            if(pos == i)
            {
                token.type = tCh1;
                tokens.pushBack(token);
                i += 3;
                continue;
            }
        }
        // safety, just in case
        i++;
    }
}

double OsciloscopeFunction::evaluate(double ch0, double ch1)
{
    for(int i = 0; i < postfix.getCount(); i++)
    {
        if(postfix[i].type == tCh0)
        {
            postfix[i].value = ch0;
        }
        if(postfix[i].type == tCh1)
        {
            postfix[i].value = ch1;
        }
    }
    stack.setCount(0);
    for(int i = 0; i < postfix.getCount(); i++)
    {
        OscToken token = postfix[i];
        switch(token.type)
        {
            case tCh0:
            case tCh1:
            case tNumber:
            case tDouble:
                stack.pushBack(token.value);
                break;
            case tSin:
            case tCos:
                {
                    double result = 0;
                    if(stack.getCount() >= 1)
                    {
                        double    par = stack.last();
                        stack.popBack();
                        result = token.evaluate(par);
                    }
                    stack.pushBack(result);
                }
                break;
            default:
                {
                    double result = 0;
                    if(stack.getCount() >= 2)
                    {
                        double   par1 = stack.last();
                        stack.popBack();
                        double   par2 = stack.last();
                        stack.popBack();
                        result = token.evaluate(par1, par2);
                    }
                    stack.pushBack(result);
                }
        };
    }
    return stack.last();
}

extern "C"
{
   #include "api/scopefunapi_wrap_lua.c"
}

int LuaOnPrint(lua_State *L)
{
   if (!L) return 0;

   const char* str = lua_tostring(L, -1);
   lua_getglobal(L, "ScriptPointer");
   OsciloscopeScript* pScript = (OsciloscopeScript*)lua_touserdata(L, -1);
   pScript->LuaPrint(str);
   lua_pop(L, 2);
   return 0;
}


int LuaOnError(lua_State *L)
{
   if (!L) return 0;

   const char* str = lua_tostring(L, -1);
   lua_getglobal(L, "ScriptPointer");
   OsciloscopeScript* pScript = (OsciloscopeScript*)lua_touserdata(L, -1);
   pScript->LuaError(str);
   return 0;
}


int LuaOnFrame(lua_State *L, SFrameData* data, int len, float* pos, float* zoom, void* user)
{
   if (!L) return 0;

   // push function
   if (lua_getglobal(L, "onFrame") == LUA_TFUNCTION)
   {
      // push parameters
      SWIG_Lua_NewPointerObj(L, data, SWIGTYPE_p_SFrameData, 0);
      lua_pushinteger(L, len);

      // execute
      if (lua_pcall(L, 2, 2, 0) != LUA_OK)
      {
         LuaOnError(L);
      }
      else
      {
         // pop parameters
         SWIG_Lua_ConvertPtr(L, -2, (void**)&data, SWIGTYPE_p_SFrameData, 0);
         lua_pop(L, 1);

         // cleanup
         lua_pop(L, 1);
      }
   }
   return 0;
}

int LuaOnSample(lua_State *L, int sample, ishort* ch0, ishort* ch1, ishort* fun,ushort* dig, float* pos, float* zoom, void* user)
{
   if (!L) return 0;

   // push function
   if (lua_getglobal(L, "onSample") == LUA_TFUNCTION)
   {
      // push parameters
      lua_pushinteger(L, sample);
      lua_pushinteger(L, *ch0);
      lua_pushinteger(L, *ch1);
      lua_pushinteger(L, *fun);
      lua_pushinteger(L, *dig);

      // execute
      if (lua_pcall(L, 5, 5, 0) != LUA_OK)
      {
         LuaOnError(L);
      }
      else
      {
         // pop parameters
         sample = lua_tointeger(L, -5);
         *ch0 = lua_tointeger(L, -4);
         *ch1 = lua_tointeger(L, -3);
         *fun = lua_tointeger(L, -2);
         *dig = lua_tointeger(L, -1);
         lua_pop(L, 5);
      }
   }
   return 0;
}

int LuaOnDisplay(lua_State *L, SDisplay* data, float* pos, float* zoom, void* user)
{
   if (!L) return 0;

   // push function
   if (lua_getglobal(L, "onDisplay") == LUA_TFUNCTION)
   {
      // push parameters
      SWIG_Lua_NewPointerObj(L, data, SWIGTYPE_p_SDisplay, 0);

      // execute
      if (lua_pcall(L, 1, 1, 0) != LUA_OK)
      {
         LuaOnError(L);
      }
      else
      {
         // pop parameters
         SWIG_Lua_ConvertPtr(L, -1, (void**)&data, SWIGTYPE_p_SDisplay, 0);
         lua_pop(L, 1);
      }
   }
   return 0;
}

int LuaOnConfigure(lua_State *L, SHardware* hw)
{
   if (!L) return 0;

   // push function
   if (lua_getglobal(L, "onConfigure") == LUA_TFUNCTION)
   {
      // push parameters
      SWIG_Lua_NewPointerObj(L, hw, SWIGTYPE_p_SHardware, 0);

      // execute
      if (lua_pcall(L, 1, 1, 0) != LUA_OK)
      {
         LuaOnError(L);
      }
      else
      {
         // pop parameters
         SWIG_Lua_ConvertPtr(L, -1, (void**)&hw, SWIGTYPE_p_SHardware, 0);
         lua_pop(L, 1);
      }
   }
   return 0;
}

int LuaOnInit(lua_State *L, SFContext* ctx)
{
   if (!L) return 0;

   // push function
   if (lua_getglobal(L, "onInit") == LUA_TFUNCTION)
   {
      // push parameters
      SWIG_Lua_NewPointerObj(L, ctx, SWIGTYPE_p_SFContext, 0);

      // execute
      if (lua_pcall(L, 1, 1, 0) != LUA_OK)
      {
         LuaOnError(L);
      }
      else
      {
         // pop parameters
         SWIG_Lua_ConvertPtr(L, -1, (void**)&ctx, SWIGTYPE_p_SFContext, 0);
         lua_pop(L, 1);
      }
   }
 
   return 0;
}
OsciloscopeScript::OsciloscopeScript(int index)
{
   m_arrayIdx = index;
   m_spinLock = 0;
   SDL_AtomicSet(&m_locking,1);
   m_userData = 0;
   m_luaState = 0;
   SDL_memset(m_luaPrint, 0, SCOPEFUN_LUA_BUFFER);
   SDL_memset(m_luaPrint, 0, SCOPEFUN_LUA_ERROR);
}
int OsciloscopeScript::OnFrame(SFrameData* data, int len, float* pos, float* zoom, void* user)
{
   int ret = 0;
   SDL_AtomicLock(&m_spinLock);
         ret = LuaOnFrame(m_luaState, data, len, pos, zoom, user);
   SDL_AtomicUnlock(&m_spinLock);
   return ret;
}
int OsciloscopeScript::OnSample(int sample, ishort* ch0, ishort* ch1, ishort* fun, ushort* dig, float* pos, float* zoom, void* user)
{
   int ret = 0;
   SDL_AtomicLock(&m_spinLock);
         ret = LuaOnSample(m_luaState, sample, ch0, ch1, fun,dig, pos, zoom, user);
   SDL_AtomicUnlock(&m_spinLock);
   return ret;
}
int OsciloscopeScript::OnDisplay(SDisplay* data, float* pos, float* zoom, void* user)
{
   int ret = 0;
   SDL_AtomicLock(&m_spinLock);
         ret = LuaOnDisplay(m_luaState, data, pos, zoom, user);
   SDL_AtomicUnlock(&m_spinLock);
   return ret;
}
int OsciloscopeScript::OnConfigure(SHardware* hw)
{
   int ret = 0;
   if( SDL_AtomicGet(&m_locking) == 1) 
      SDL_AtomicLock(&m_spinLock);
         ret = LuaOnConfigure(m_luaState, hw);
   if (SDL_AtomicGet(&m_locking) == 1)  
      SDL_AtomicUnlock(&m_spinLock);
   return ret;
}
int OsciloscopeScript::OnInit(SFContext* ctx)
{
   int ret = 0;
   SDL_AtomicSet(&m_locking,0);
      ret = LuaOnInit(m_luaState,ctx);
   SDL_AtomicSet(&m_locking,1);
   return ret;
}

int OsciloscopeScript::LuaPrint(const char* str)
{
   if( str )
      SDL_strlcat(m_luaPrint, str, SCOPEFUN_LUA_BUFFER);
   return 0;
}


int OsciloscopeScript::LuaError(const char* str)
{
   LuaPrint(str);
   lua_close(m_luaState);
   m_luaState = 0;
   return 0;
}

int OsciloscopeScript::CppPrint(const char* str)
{
   SDL_AtomicLock(&m_spinLock);
      SDL_strlcat(m_luaPrint, str, SCOPEFUN_LUA_BUFFER);
   SDL_AtomicUnlock(&m_spinLock);
   return 0;
}

int OsciloscopeScript::Load(String fileName)
{
   m_fileName = fileName;
   return 0;
}

int OsciloscopeScript::Run()
{
   if (m_luaState) 
      return 1;

   const char* redirect = "\r\n"
      "print_stdout = print\r\n"
      "\r\n"
      "print = function(...)\r\n"
      "  local arg = { ... }\r\n"
      "  for i, v in ipairs(arg) do\r\n"
      "    LuaPrint(v)\r\n"
      "  end\r\n"
      "end\r\n";

   SDL_AtomicLock(&m_spinLock);
      m_luaState = luaL_newstate();
      luaopen_base(m_luaState);
      luaL_openlibs(m_luaState);
      luaopen_ScopeFun(m_luaState);
      lua_pushlightuserdata(m_luaState, this);
      lua_setglobal(m_luaState, "ScriptPointer");
      lua_register(m_luaState, "LuaPrint", LuaOnPrint);
      luaL_dostring(m_luaState, redirect);
      int ret = luaL_dofile(m_luaState, m_fileName.asChar());
      if (ret == LUA_OK)
      { 
         LuaPrint("script loaded: ");
         LuaPrint(m_fileName.asChar());
         LuaPrint("\n");

         // OnInit
         ret = OnInit(getCtx());
      }
      else
      {
         LuaOnError(m_luaState);
      }
   SDL_AtomicUnlock(&m_spinLock);
   return ret;
}

int OsciloscopeScript::Reload()
{
   Stop();
   Run();
   return 0;
}

int OsciloscopeScript::Stop()
{
   if (!m_luaState) return 1;

   SDL_AtomicLock(&m_spinLock);
      lua_close(m_luaState);
      m_luaState = 0;
   SDL_AtomicUnlock(&m_spinLock);
   return 0;
}

void OsciloscopeScript::SetUserData(void* user)
{
   m_userData = user;
}

void* OsciloscopeScript::GetUserData()
{
   return m_userData;
}

int OsciloscopeScript::GetArrayIdx()
{
   return m_arrayIdx;
}

void OsciloscopeScript::ClrPrint()
{
   SDL_AtomicLock(&m_spinLock);
      SDL_memset(m_luaPrint,0,SCOPEFUN_LUA_BUFFER);
   SDL_AtomicUnlock(&m_spinLock);
}

const char* OsciloscopeScript::GetPrint()
{
   return m_luaPrint;
}


int callFrame(SFrameData* data, int len, float* pos, float* zoom, void* user)
{
   for (int i = 0; i < pOsciloscope->m_callback.Count(); i++)
      pOsciloscope->m_callback.Get(i)->OnFrame(data, len, pos, zoom, user);
   return 0;
}

int callSample(int sample, ishort* ch0, ishort* ch1, ishort* fun,ushort* dig, float* pos, float* zoom, void* user)
{
   for (int i = 0; i < pOsciloscope->m_callback.Count(); i++)
      pOsciloscope->m_callback.Get(i)->OnSample(sample, ch0, ch1, fun, dig, pos, zoom, user);
   return 0;
}
int callDisplay(SDisplay* data, float* pos, float* zoom, void* user)
{
   for (int i = 0; i < pOsciloscope->m_callback.Count(); i++)
      pOsciloscope->m_callback.Get(i)->OnDisplay(data, pos, zoom, user);
   return 0;
}
int callConfigure(SHardware* hw)
{
   for (int i = 0; i < pOsciloscope->m_callback.Count(); i++)
      pOsciloscope->m_callback.Get(i)->OnConfigure(hw);
   return 0;
}
int callInit(SFContext* ctx)
{
   for (int i = 0; i < pOsciloscope->m_callback.Count(); i++)
      pOsciloscope->m_callback.Get(i)->OnInit(ctx);
   return 0;
}


OsciloscopeCallback::OsciloscopeCallback()
{
   m_callback.onInit      = callInit;
   m_callback.onFrame     = callFrame;
   m_callback.onSample    = callSample;
   m_callback.onDisplay   = callDisplay;
   m_callback.onConfigure = callConfigure;
}

int OsciloscopeCallback::Add(String fileName)
{
   if (m_script.getCount() < SCOPEFUN_MAX_SCRIPT)
   {
      OsciloscopeScript* script = new OsciloscopeScript(m_script.getCount());
      script->Load(fileName);
      m_script.pushBack(script);
      return 0;
   }
   return 1;
}

int OsciloscopeCallback::Clear()
{
   for (int i = 0; i < m_script.getCount(); i++)
      delete m_script[i];
   m_script.clear();
   return 0;
}

int OsciloscopeCallback::Count()
{
   return m_script.getCount();
}

OsciloscopeScript* OsciloscopeCallback::Get(int i)
{
   if (m_script.getCount() > i)
      return m_script[i];
   return 0;
}

SCallback* OsciloscopeCallback::Ptr()
{
   return &m_callback;
}

////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
