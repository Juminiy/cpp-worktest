#pragma once
#ifndef _STL_STR_LIB_HPP
#define _STL_STR_LIB_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <string>
#include <cstdarg>
#include <cstring>
#include <cctype>

__DEF_NS__(Alan)

/// @brief 
/// @tparam _Str_Tp 
/// @param __src 
/// @param __dest 
/// @return 
template <typename _Str_Tp_1 = std::string,
            typename _Str_Tp_2 = char *>
static inline bool 
_sfind(const _Str_Tp_1 & __src, const _Str_Tp_2 & __dest)
{
    return __src.find(__dest) != _Str_Tp_1::npos;
}

// variable __dest
static inline bool 
_sfind_any
(const std::string &__src, const size_t &__sz, ...)
{
    ::va_list _val;
    va_start(_val, __sz);
    for (size_t _i = 0; _i < __sz; ++_i)
        if(__src.find(va_arg(_val, const char*)) != 
            std::string::npos)
            return true;
    va_end(_val);
    return false;
}

static inline bool 
_sfind_all
(const std::string &__src, const size_t &__sz, ...)
{
    ::va_list _val;
    va_start(_val, __sz);
    for (size_t _i = 0; _i < __sz; ++_i)
        if(__src.find(va_arg(_val, const char*)) == 
            std::string::npos)
            return false;
    va_end(_val);
    return true;
}

static inline bool
_is_bs(char _ch)
{
    return ::isblank(_ch) ||
            ::isspace(_ch);
}

__DEF_NS__(CONST)
// reference from: https://cplusplus.com/reference/cctype/
// only ASCII Code
const char * const _digit = "0129384756";
const char * const _lowal = "abcdefghijklmnopqrstuvwxyz";
const char * const _uppal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char * const _sign_ = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
const char * const __bs__ = "\t\f\v\n\r ";
__END_NS__



__END_NS__

#endif