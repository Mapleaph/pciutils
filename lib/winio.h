#ifndef WINIO_H
#define WINIO_H

#include "winio_nt.h"

bool _stdcall InitializeWinIo(void);
void _stdcall ShutdownWinIo(void);
PBYTE _stdcall MapPhysToLin(tagPhysStruct PhysStruct);
bool _stdcall UnmapPhysicalMemory(tagPhysStruct PhysStruct);
bool _stdcall GetPhysLong(PBYTE pbPhysAddr, PDWORD pdwPhysVal);
bool _stdcall SetPhysLong(PBYTE pbPhysAddr, DWORD dwPhysVal);
bool _stdcall GetPortVal(WORD wPortAddr, PDWORD pdwPortVal, BYTE bSize);
bool _stdcall SetPortVal(WORD wPortAddr, DWORD dwPortVal, BYTE bSize);

extern HANDLE hDriver;
extern bool IsWinIoInitialized;
extern bool g_Is64BitOS;

#endif
