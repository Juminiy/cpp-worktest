#pragma once
#ifndef _STL_LIB_ADV_HPP
#define _STL_LIB_ADV_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"
#include <utility>
#include <memory>
#include <iostream>
#include <numeric>
#include <cstdint>
#include <cassert>

#if __CC_VER__ == 2
#include <ext/numeric>
#endif 

#define __TP_PLUS_TRAITS__(__tp_1__, __tp_2__) \
        decltype(std::declval<__tp_1__ >() + \
                std::declval<__tp_2__ >() )

#define __CON_TP_TRAITS__(__con1_type__, __tp_1__, __con2_type__, __tp_2__) \
        __con1_type__< __TP_PLUS_TRAITS__(__tp_1__, __tp_2__) >


USE_NAMESPACE_ALAN



// template <typename _Tp_1, 
//             typename _Tp_2 >
// bool _type_equal(_Tp_1 _tp_1_val,
//                 _Tp_2 _tp_2_val )
// {
//     if (constexpr std::is_same_v(_tp_1_val, int) ||
//         constexpr std::is_same_v(_tp_2_val, int))
//     {
//         return true;
//     } else 
//     {
//         return false;
//     }
// }

// make no sense on clang
template < 
    template < typename > typename _Container_1, typename _Tp_1,
    template < typename > typename _Container_2, typename _Tp_2 >
std::enable_if_t< 
    _infer_container<_Container_1<_Tp_1 >, 
                    _Container_2<_Tp_2 > >::value, 
    __CON_TP_TRAITS__(_Container_1, _Tp_1, 
                    _Container_2, _Tp_2 ) >
_t_plus(const _Container_1<_Tp_1 > & __container_1,
        const _Container_2<_Tp_2 > & __container_2)
{
    auto _ret = 
        __CON_TP_TRAITS__(_Container_1, _Tp_1, 
                        _Container_2, _Tp_2 ) ();
    auto _iter_1t = __container_1.begin();
    auto _iter_1e = __container_1.end();
    auto _iter_2t = __container_2.begin();
    auto _iter_2e = __container_2.end();

    for(; _iter_1t != _iter_1e &&
            _iter_2t != _iter_2e;
        ++ _iter_1t, ++ _iter_2t)
        _ret.emplace_back(*_iter_1t + *_iter_2t);

    for(; _iter_1t != _iter_1e;
        ++ _iter_1t)
        _ret.emplace_back(*_iter_1t);
    
    for(; _iter_2t != _iter_2e;
        ++ _iter_2t)
        _ret.emplace_back(*_iter_2t);

    return _ret;
}


// partial specialization _t_plus
template <typename _Tp_1, typename _Tp_2,
        typename = typename 
        _enable_if_cond<_is_same_type<_Tp_1, _Tp_2 >::_value >::_value_type >
auto _t_plus_v2(_Tp_1 && __lhs, 
                _Tp_2 && __rhs)
-> decltype(std::move(__lhs) + 
            std::move(__rhs))
{
    return std::move(__lhs) + 
            std::move(__rhs);
}

END_NAMESPACE_ALAN

#endif

