#pragma once
#ifndef _STL_STR_LIB_HPP
#define _STL_STR_LIB_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <string>

__DEF_NS__(Alan)

/// @brief 
/// @tparam _Str_Tp 
/// @param __src 
/// @param __dest 
/// @return 
template <typename _Str_Tp_1 = std::string,
            typename _Str_Tp_2 = char *>
bool _sfind(const _Str_Tp_1 & __src, const _Str_Tp_2 & __dest)
{
    return __src.find(__dest) != _Str_Tp_1::npos;
}

// variable __dest

__END_NS__

#endif