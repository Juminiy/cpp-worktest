#pragma once
#ifndef _STL_LIB_ADV_HPP
#define _STL_LIB_ADV_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <utility>
#include <memory>
#include <iostream>
#include <numeric>

#include <cassert>
#include <cstdint>
#include <cstdbool>

#if __CC_VER__ == 2
#include <ext/numeric>
#endif 

#define __TP_PLUS_TRAITS__(__tp_1__, __tp_2__) \
        decltype(std::declval<__tp_1__ >() + \
                std::declval<__tp_2__ >() )

#define __CON_TP_TRAITS__(__con1_type__, __tp_1__, __con2_type__, __tp_2__) \
        __con1_type__< __TP_PLUS_TRAITS__(__tp_1__, __tp_2__) >

#define __INST_OF_TP__(__tp__) \
        std::declval<__tp__>()

__DEF_NS__(Alan)

// meta function 
// map self to self 
template <bool _bool_value >
struct _bool_type {
	static constexpr bool _value = _bool_value;
};

// template meta struct
template <typename _Tp, typename _Up >
struct _is_same_type 
: _bool_type<false> { };

// template meta struct
// template partial specialization
template <typename _Tp >
struct _is_same_type<_Tp, _Tp >
: _bool_type<true> { };


template <bool _Cond, typename _Tp = void >
struct _enable_if_cond { };

template <typename _Tp >
struct _enable_if_cond<true, _Tp >{
	using _value_type = _Tp ;
};


template < typename _Fn,
    std::enable_if_t< 
        std::is_void_v<std::invoke_result_t<_Fn > >,
        int > = 0 
>
void _Call_Fn(_Fn __fn)
{
    __fn();
    PRINTLN_DETAIL("__fn() return void");
}

template < typename _Fn, 
    std::enable_if_t< 
        !std::is_void_v<std::invoke_result_t<_Fn > >,
        int > = 0
>
void _Call_Fn(_Fn __fn)
{
    auto _r_val = __fn();
    PRINTLN_DETAIL("__fn() return " 
                    << _r_val );
}

template <typename _Fn, typename = void >
std::enable_if_t<
        std::is_void_v<std::invoke_result_t<_Fn > >, // __INST_OF_TP__(_Fn)()
        void >
_assume_func_return_type(_Fn __fn)
{
    __fn();
}

template <typename _Fn, typename _Ret_Tp >
std::enable_if_t<
        !std::is_void_v<std::invoke_result_t<_Fn > >, // __INST_OF_TP__(_Fn)()
        _Ret_Tp >
_assume_func_return_type(_Fn __fn)
{
    return __fn();
}


// // infer value_type 

// // unfinished
// // infer char, int, double
// // normal version
// template< typename, typename = std::void_t< > >
// struct _infer_num_type
// : std::false_type {	};

// // partial specialization
// template< typename _num_type >
// struct _infer_num_type
// < _num_type, 
// 	std::void_t<typename __num_type,
// 				decltype(  ) > >
// : std::true_type {	};



// infer meta function exists 

// can cook from std::vector -> std::__is_allocator

// in std::container<_Tp > by
// iterator begin() or end() 
// normal version
template< typename, typename, typename = std::void_t< > >
struct _infer_container 
: std::false_type {	}; 

// partial specialization
template < typename _con1_type, 
            typename _con2_type >
struct _infer_container
<_con1_type, _con2_type, 
    std::void_t<typename _con1_type::iterator,
                typename _con2_type::iterator,
                decltype( __INST_OF_TP__(_con1_type).begin(),
                        __INST_OF_TP__(_con2_type).begin() ) > >
: std::true_type { };



// template < typename, typename = std::void_t< > >
// struct _fn_return_type_bool
// : std::false_type { };

// template < typename _Fn >
// struct _fn_return_type_bool <_Fn, 
//         std::void_t< decltype( std::is_same_v<std::invoke_result_t<_Fn >, bool> ) > >
// : std::true_type { };


// normal version
template <typename, typename = std::void_t< > >
struct _has_operator_less_overload 
: std::false_type { };

// partial specialization
// assume or infer <typename _Tp > instance whether can call operator<() ?
template <typename _Tp >
struct _has_operator_less_overload<_Tp, 
        std::void_t< decltype(__INST_OF_TP__(_Tp).operator< 
                                    (__INST_OF_TP__(_Tp))) > >
: std::true_type { };

// TODO: how to support two operator overload?
// ( (support memeber function operator < ) ||
//      (support free function operator < ) ) &&
// (return_type is bool)
// 

// template <typename _Tp >
// struct _has_operator_less_overload<_Tp, 
//         std::void_t< decltype(operator< (__INST_OF_TP__(_Tp),
//                                         __INST_OF_TP__(_Tp))) > >
// : std::true_type { };


class _op_v0 { };
class _op_v1 { };
class _op_v2 { };
class _op_v3 { };

/// @brief fully specialization
template <>
struct _has_operator_less_overload<_op_v0 > 
: std::false_type { };

/// @brief fully specialization
template <>
struct _has_operator_less_overload<_op_v1 > 
: std::false_type { };

/// @brief fully specialization
template <>
struct _has_operator_less_overload<_op_v2 > 
: std::true_type { };

/// @brief fully specialization
template <>
struct _has_operator_less_overload<_op_v3 > 
: std::true_type { };


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
// universal reference
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

__END_NS__

#endif

