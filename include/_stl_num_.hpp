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

__DEF_NS__(Alan)

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
// universal reference
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
// std::enable_if_t< 
//     _infer_num_type<_Tp>::value, 
//     _Tp >
_Tp Sqrt(const _Tp & _num)
{
    return sqrt(static_cast<double>(_num));
}

template <typename _Tp_1,
            typename _Tp_2 = double>
_Tp_1 Power(const _Tp_1 & _num,
            const _Tp_2 & _pow)
{
    return pow(static_cast<double>(_num), _pow);
}

// TODO: logn int version

__END_NS__

__DEF_NS__(Alan::Demos)

template <typename _Tp>
class _parr
{
public:
    _parr(__CONST_REF__(_Tp) _sz)
    {
        this->sz = _sz;
                    // only for Test
        this->elems = new _Tp[_sz];
    }   
    __PTR__(_Tp) data()
    {
        return this->elems;
    }
    __PTR_TO_CONST__(_Tp) data() const
    {
        return this->elems;
    }
private:
    _Tp *elems;
    size_t sz;
};

__END_NS__

#endif 