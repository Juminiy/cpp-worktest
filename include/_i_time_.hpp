#pragma once
#ifndef _I_TIME_HPP
#define _I_TIME_HPP

#include "_i_lib_.hpp"
#include <chrono>

__DEF_NS__(Alan)

// Test CPU per second loops
GEN_FUNC_COPY
uint64_t 
__loops_per_sec_(uint32_t __secs_)
{
    using namespace std::chrono;
    auto _start = high_resolution_clock::now();
    auto _end = _start;
    auto _loops = uint64_t(0);
    while(duration_cast<seconds>(_end - _start).count()
            < __secs_)
    {
        ++ _loops;
        _end = high_resolution_clock::now();
    }
    return _loops;
}


__END_NS__

#endif