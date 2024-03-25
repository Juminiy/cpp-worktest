#pragma once
#ifndef _STL_NUM_HPP
#define _STL_NUM_STL

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>
#include <iomanip>

#include <iterator>
#include <utility>
#include <numeric>
#include <algorithm>
#include <chrono>

#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <cmath>

USE_NAMESPACE_ALAN

template <typename _Tp_1,
            typename _Tp_2 >
auto _t_plus(_Tp_1 & __lhs, 
                _Tp_2 & __rhs)
-> decltype(__lhs + __rhs)
{
    return __lhs + __rhs;
}

template <typename _Tp_1,
            typename _Tp_2 >
auto _t_plus(const _Tp_1 & __lhs,
                const _Tp_2 & __rhs)
-> decltype(__lhs + __rhs)
{
    return __lhs + __rhs;
}

// compiler will default choose
// more efficiency
template <typename _Tp_1,
            typename _Tp_2 >
auto _t_plus(_Tp_1 && __lhs, 
                _Tp_2 && __rhs)
-> decltype(std::move(__lhs) + 
            std::move(__rhs))
{
    return std::move(__lhs) + 
            std::move(__rhs);
}



template <typename _Tp >
_Tp Sqrt(const _Tp & _num)
{
    return sqrt(double(_num));
}

template <typename _Tp_1,
            typename _Tp_2 = double>
_Tp_1 Power(const _Tp_1 & _num,
            const _Tp_2 & _pow)
{
    return pow(double(_num), _pow);
}

END_NAMESPACE_ALAN

#endif 