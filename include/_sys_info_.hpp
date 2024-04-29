#pragma once
#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#if (__CC_VER__ > 1)
    #include <unistd.h>
#elif (__CC_VER__ == 1)
    #include <windows.h>
#endif

__DEF_NS__(Alan::SysInfo)

GEN_FUNC_COPY
void LOGSysInfo()
{
    #if _OSVER != WinNT
        PRINTLN_DETAIL(getpagesize());
    #endif
}

__END_NS__