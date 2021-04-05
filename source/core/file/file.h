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
#ifndef __CORE__FILE__
    #define __CORE__FILE__

    int   fileLoadString(const char* fileName, char** string, ilarge* stringSize);
    int   fileSaveString(const char* fileName, const char* string);

    int   fileLoad(const char* fileName, char** buffer,   ilarge* bufferSize);
    int   fileSize(const char* fileName, ilarge* bufferSize);
    int   fileLoadPtr(const char* fileName, char* buffer, ilarge* bufferSize);
    int   fileSave(const char* fileName, char*  buffer, ilarge bufferSize);

    int   fileFree(char* memory);

#endif
////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
