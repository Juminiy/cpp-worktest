#pragma once
#ifndef _STL_STR_LIB_HPP
#define _STL_STR_LIB_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <string>
#include <memory>

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
GEN_FUNC_COPY bool 
_sfind(const _Str_Tp_1 & __src, const _Str_Tp_2 & __dest)
{
    return __src.find(__dest) != _Str_Tp_1::npos;
}

// variable __dest
GEN_FUNC_COPY bool 
_sfind_any
(const std::string &__src, const size_t __sz, ...)
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

GEN_FUNC_COPY bool 
_sfind_all
(const std::string &__src, const size_t __sz, ...)
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

GEN_FUNC_COPY bool
_is_bs(char _ch)
{
    return ::isblank(_ch) ||
            ::isspace(_ch);
}

__DEF_NS__(CONST)

// reference from: https://cplusplus.com/reference/cctype/
// only ASCII Code
__CONST_PTR_TO_CONST__(char) _digit = "0129384756";                         // size = 10
__CONST_PTR_TO_CONST__(char) _lowal = "abcdefghijklmnopqrstuvwxyz";         // size = 26
__CONST_PTR_TO_CONST__(char) _uppal = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";         // size = 26
__CONST_PTR_TO_CONST__(char) _sign_ = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"; // size = 32
__CONST_PTR_TO_CONST__(char) __bs__ = "\t\f\v\n\r ";                        // size = 6

#define CONST_CHARS_RET_TYPE \
        std::string
        // __CONST_PTR_TO_CONST__(char) 

GEN_FUNC_COPY
CONST_CHARS_RET_TYPE
_base_num_()
{
    return std::string(_digit);
}

GEN_FUNC_COPY
CONST_CHARS_RET_TYPE
_base_alpha_()
{
    auto _temp_str = std::string();
    _temp_str += _lowal;
    _temp_str += _uppal;
    return _temp_str;
}

GEN_FUNC_COPY
CONST_CHARS_RET_TYPE
_base_alpha_num_()
{
    auto _temp_str = std::string();
    _temp_str += _lowal;
    _temp_str += _uppal;
    _temp_str += _digit;
    return _temp_str;
}

GEN_FUNC_COPY
CONST_CHARS_RET_TYPE
_base_legal_ident_()
{
    auto _temp_str = std::string("_");
    _temp_str += _lowal;
    _temp_str += _uppal;
    _temp_str += _digit;
    return _temp_str;
}


GEN_FUNC_COPY
CONST_CHARS_RET_TYPE
_base_blank_space_()
{
    return std::string(__bs__);
}

GEN_FUNC_COPY
CONST_CHARS_RET_TYPE 
_base_sign_()
{
    return std::string(_sign_);
}

__END_NS__

__END_NS__

#endif