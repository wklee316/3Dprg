#include <windows.h>
#include <stdio.h>
#include <tchar.h>

#define DIV 1073741824.0

#define WIDTH 7

void _tmain()
{
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    GlobalMemoryStatusEx(&statex);
    _tprintf(TEXT("There is  %*ld percent of memory in use.\n"),
        WIDTH, statex.dwMemoryLoad);
    _tprintf(TEXT("There are %*lf total GB of physical memory.\n"),
        WIDTH, statex.ullTotalPhys / DIV);
    _tprintf(TEXT("There are %*lf free  GB of physical memory.\n"),
        WIDTH, statex.ullAvailPhys / DIV);
}