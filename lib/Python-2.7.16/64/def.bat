echo off
echo Run this under visual studio 2017 command prompt. You need dumpbin.exe to genereate .def file.
echo You could also use pexports or expdef program to generate .def from dll.
echo You have to edit created .def file so that it will look like this:
echo LIBRARY python27.dll
echo EXPORTS
echo functionName1
echo functionName2
echo ... etc
echo on
dumpbin /EXPORTS python27.dll > python27.def
pause