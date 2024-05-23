#pragma once 
#ifndef _RAND_LIB_HPP
#define _RAND_LIB_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"
#include "_stl_str_lib_.hpp"

#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstdint>
#include <cassert>
#include <cstring>

#include <list>
#include <deque>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <utility>
#include <chrono>
#include <memory>

__DEF_NS__(Alan)
// TODO: finished(50%)
// generate random data for Batch Test
// 1. random number < integer, float >:                         ok
//  (1). < char, short, int, long long, ui16, ui32, ui64 >      ok
//  (1). < float, double, [double long] >                       ok
// 2. random string < char, wchar_t, char16_t, char32_t >       char: ok, wchar_t: no, char16_t: no, char32_t: no
//  (1). fixed length, random length                            ok
//  (2). legalcy __xxx__                                        ok
//      (     i). legalcy name(_A-Za-z0-9)                      ok
//      (    ii). legalcy alphanum(A-Za-z0-9)                   ok
//      (   iii). legalcy alpha(A-Za-z)                         ok
//      (  iiii). legalcy num(0-9)                              ok
//      ( iiiii). legalcy all chars( in ascci table )           ok
//      (iiiiii). legalcy w_chart, unicode char_t and more...   no
// 3. random container < seq_container >, < asso_container >
//  (1). Sequential Container 
//      (  i). std::vector< _Tp >                               ok
//      ( ii). std::deque< _Tp >                                ok
//      (iii). std::list< _Tp >                                 ok
//  (2). Associative Container 
//      (i). std::unordered_multimap<_Tp1, _Tp2>
//      (ii). std::unordered_multiset< _Tp >
//      (iii). std::multimap<_Tp1, _Tp2>
//      (iiii). std::multiset< _Tp >
//      (iiiii). std::unordered_map<_Tp1, _Tp2> 
//      (iiiiii). std::unordered_set< _Tp > 
//      (iiiiiii). std::map<_Tp1, _Tp2> 
//      (iiiiiiii). std::set< _Tp > 
//  (3). Tp = integer, float, string include in (1, 2)
// 4. gen by std::construct(std::forward(_args...)) ...         more to explore

#define __RD_X_NUM__(__g_tp_, __num_tp_, __num_rg1_, __num_rg2_) \
        std::random_device _Rand_Dev; \
        std::mt19937       _Rand_Gen(_Rand_Dev()); \
        std::uniform_ ##__g_tp_ ##_distribution<__num_tp_ > \
            UNUSED _Uid_Gen_Dev(__num_rg1_, __num_rg2_)

#define __RD_I_NUM__(__num_tp_, __num_rg1_, __num_rg2_) \
        __RD_X_NUM__(int, __num_tp_, __num_rg1_, __num_rg2_)

#define __RD_R_NUM__(__num_tp_, __num_rg1_, __num_rg2_) \
        __RD_X_NUM__(real, __num_tp_, __num_rg1_, __num_rg2_)

#define __RD_I_LAM__(__num_tp_) \
        [&_Rand_Gen, &_Uid_Gen_Dev] \
        () -> __num_tp_ \
        { return _Uid_Gen_Dev(_Rand_Gen); }

// gen single value
template <typename _Num_Tp >
GEN_FUNC_COPY
_Num_Tp _Gen_INum
(_Num_Tp __range_1, _Num_Tp __range_2)
{
    __RD_I_NUM__(_Num_Tp, __range_1, __range_2);
    return _Uid_Gen_Dev(_Rand_Gen);
}

template <typename _Num_Tp >
GEN_FUNC_COPY
_Num_Tp _Gen_RNum
(_Num_Tp __range_1, _Num_Tp __range_2)
{
    __RD_R_NUM__(_Num_Tp, __range_1, __range_2);
    return _Uid_Gen_Dev(_Rand_Gen);
}

//                               TODO:
/// @brief default gen int-like, next try to gen int-like, float-like
/// @tparam _Num_Tp 
/// @param __range_1 
/// @param __range_2 
/// @return 
template <typename _Num_Tp >
GEN_FUNC_COPY
_Num_Tp _Gen_Num
(_Num_Tp __range_1, _Num_Tp __range_2)
{
    return _Gen_INum(__range_1, __range_2);
}

// template <typename _Num_Tp >
// GEN_FUNC_COPY _Num_Tp _Gen_Num
// (_Num_Tp const &__range_1, _Num_Tp const &__range_2)
// {   
//     const std::string _num_tp_str 
//         = Alan::__cpp_tid_<_Num_Tp>();
//     #ifdef DEBUG_MODE
//         PRINTLN_DETAIL("["<<_num_tp_str<<"]");
//     #endif 
//     if (_sfind_any(_num_tp_str, 3, "long", "int", "unsigned"))
//     {
//         __RD_I_NUM__(_Num_Tp, __range_1, __range_2);
//         return _Uid_Gen_Dev(_Rand_Gen);
//     } else if (_sfind_any(_num_tp_str, 2, "double", "float"))
//     {
//         __RD_R_NUM__(_Num_Tp, __range_1, __range_2);
//         return _Uid_Gen_Dev(_Rand_Gen);
//     }
//     else 
//     {
//         _COLOR_START(_COLOR_RED);
//             ERRLN("SFINAE error occurs!");
//         _COLOR_RECOVER;
//         assert(0);
//     }
// }

// Iterator scoped value
template <typename _Num_Tp, 
            typename _ForwardIterator >
GEN_FUNC_COPY
void _Iter_Gen_INum
(_ForwardIterator __first, _ForwardIterator __last, 
    _Num_Tp __range_1, _Num_Tp __range_2)
{
    __RD_I_NUM__(_Num_Tp, __range_1, __range_2);
    std::generate(__first, __last, __RD_I_LAM__(_Num_Tp));
}

template <typename _Num_Tp, 
            typename _ForwardIterator >
GEN_FUNC_COPY
void _Iter_Gen_RNum
(_ForwardIterator __first, _ForwardIterator __last, 
    _Num_Tp __range_1, _Num_Tp __range_2)
{
    __RD_R_NUM__(_Num_Tp, __range_1, __range_2);
    std::generate(__first, __last, __RD_I_LAM__(_Num_Tp));
}

/// @brief mixed above two 
/// @tparam _Num_Tp 
/// @tparam _ForwardIterator 
/// @param __first 
/// @param __last 
/// @param __range_1 
/// @param __range_2 
template <typename _Num_Tp, 
            typename _ForwardIterator >
GEN_FUNC_COPY
void _Iter_Gen_Num
(_ForwardIterator __first, _ForwardIterator __last, 
    _Num_Tp __range_1, _Num_Tp __range_2)
{
    _Iter_Gen_INum(__first, __last, __range_1, __range_2);
}

const size_t _con_default_tsz = 1 << 3;
const size_t _con_default_lsz = 1 << 10;

// PreAlloced sequential container scoped value
template <typename _Num_Tp, 
            typename _Container >
GEN_FUNC_COPY
void _Seq_Con_Fil_Gen_Num
(_Container &__container, 
    _Num_Tp __range_1, _Num_Tp __range_2)
{
    _Iter_Gen_Num(__container.begin(), __container.end(), 
                __range_1, __range_2);
}

// Not PreAllocated container
// ##use (back_inserter + reserve) upperdays, 
// ##but this idea was deprecated in 2024.3.22
// use .resize more efficient
// has changed in 2024.3.23
template <typename _Num_Tp, 
            typename _Container >
GEN_FUNC_COPY
// #if (__CC_VER__ >= 4)
// _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// #endif
void _Seq_Con_Ins_Gen_Num
(_Container &__container, size_t __gen_count,
    _Num_Tp __range_1, _Num_Tp __range_2)
{
    __RD_I_NUM__(_Num_Tp, __range_1, __range_2);
    __container.reserve(__gen_count);
    std::generate_n(std::back_inserter(__container), 
                    __gen_count, __RD_I_LAM__(_Num_Tp));
}

// in default range __range_1, __range_2 
// 1. directly generate and return a std::unique_ptr<container_type<_Tp > >
template < typename _Seq_Container, 
            size_t _sz = _con_default_tsz >
std::unique_ptr<_Seq_Container>
_Gen_Seq_Con
(typename _Seq_Container::value_type __range_1, 
typename _Seq_Container::value_type __range_2)
{
    // auto _seq_con_ptr =
    //     std::unique_ptr<_Seq_Container>
    //     (new _Seq_Container(_sz));
    auto _seq_con_ptr =
        std::make_unique<_Seq_Container>(_sz);
    _Iter_Gen_Num(_seq_con_ptr->begin(), _seq_con_ptr->end(),
                    __range_1, __range_2);
    return _seq_con_ptr;
}

template < typename _Seq_Container, 
            typename _Num_Tp,
            size_t _sz = _con_default_tsz >
std::unique_ptr<_Seq_Container>
_Gen_Seq_Con
(typename _Seq_Container::value_type __range_1, 
typename _Seq_Container::value_type __range_2)
{
    // auto _seq_con_ptr =
    //     std::unique_ptr<_Seq_Container>
    //     (new _Seq_Container(_sz));
    auto _seq_con_ptr =
        std::make_unique<_Seq_Container>(_sz);
    _Iter_Gen_RNum(_seq_con_ptr->begin(), _seq_con_ptr->end(),
                    __range_1, __range_2);
    return _seq_con_ptr;
}

const char * const _default_base_chars = "abcdefghijklmnopqrstuvwxyz";

/// @brief 
/// @tparam _Char_Container 
/// @param __base_chars_ 
/// @param __sz 
/// @return 
template < typename _Char_Container = std::string >
std::unique_ptr<_Char_Container>
_Gen_Char_Con
(__CONST_PTR_TO_CONST__(typename _Char_Container::value_type) __base_chars_ = _default_base_chars, 
    size_t __sz = _con_default_tsz)
{   
    assert(::strlen(__base_chars_));
    // auto _char_con_ptr = 
    //     std::unique_ptr<_Char_Container>
    //     (new _Char_Container());
    auto _char_con_ptr = 
        std::make_unique<_Char_Container>();
    _char_con_ptr->reserve(__sz);

    // TODO:
    // optimize with std::generate
    __RD_I_NUM__(size_t, 0, ::strlen(__base_chars_)-1);
    for(size_t _i = 0; _i < __sz; ++_i)
        _char_con_ptr->operator+=(__base_chars_[_Uid_Gen_Dev(_Rand_Gen)]);
    
    // resize(__sz); + std::transform();
    return _char_con_ptr;
}

template < typename _Char_Container = std::string >
std::unique_ptr<_Char_Container>
_Gen_Char_Con
(const _Char_Container & __base_con_, size_t __sz)
{
    assert(__base_con_.size());
    // auto _char_con_ptr = 
    //     std::unique_ptr<_Char_Container>
    //     (new _Char_Container());
    auto _char_con_ptr = 
        std::make_unique<_Char_Container>();
    _char_con_ptr->reserve(__sz);

    // TODO:
    // optimize with std::generate
    __RD_I_NUM__(size_t, 0, __base_con_.size()-1);
    for(size_t _i = 0; _i < __sz; ++_i)
        _char_con_ptr->operator+=(__base_con_[_Uid_Gen_Dev(_Rand_Gen)]);
    
    // resize(__sz); + std::transform();
    return _char_con_ptr;
}

// partial specializtion
// std::vector<str_type>
template< typename _Seq_Str_Container, 
            size_t _sz  = (1<<3) >
std::unique_ptr<_Seq_Str_Container>
_Gen_Seq_Str_Con
(__CONST_PTR_TO_CONST__(typename _Seq_Str_Container::value_type::value_type) __base_chars_, 
size_t _str_sz_rg1, size_t _str_sz_rg2)
{   
    using _ele_str_type = typename _Seq_Str_Container::value_type;
    // auto _seq_str_con_ptr = 
    //     std::unique_ptr<_Seq_Str_Container>
    //     (new _Seq_Str_Container());
    auto _seq_str_con_ptr = 
        std::make_unique<_Seq_Str_Container>();
    _seq_str_con_ptr->reserve(_sz);

    __RD_I_NUM__(size_t, _str_sz_rg1, _str_sz_rg2);
    for(size_t _i = 0; _i < _sz; ++_i)
    {   
        // TODO:
        // optimize with std::generate
        auto _char_con_ptr = 
            _Gen_Char_Con<_ele_str_type>(__base_chars_, _Uid_Gen_Dev(_Rand_Gen)); 
                                                        // ignore the case: size = 0
        _seq_str_con_ptr->push_back(std::move(*_char_con_ptr.release()));
    }

    return _seq_str_con_ptr;
}

template< typename _Seq_Str_Container, 
            size_t _sz  = (1<<3) >
std::unique_ptr<_Seq_Str_Container>
_Gen_Seq_Str_Con
(const typename _Seq_Str_Container::value_type & __base_con_, 
size_t _str_sz_rg1, size_t _str_sz_rg2)
{   
    using _ele_str_type = typename _Seq_Str_Container::value_type;
    // auto _seq_str_con_ptr = 
    //     std::unique_ptr<_Seq_Str_Container>
    //     (new _Seq_Str_Container());
    auto _seq_str_con_ptr = 
        std::make_unique<_Seq_Str_Container>();
    _seq_str_con_ptr->reserve(_sz);

    __RD_I_NUM__(size_t, _str_sz_rg1, _str_sz_rg2);
    for(size_t _i = 0; _i < _sz; ++_i)
    {   
        // TODO:
        // optimize with std::generate
        auto _char_con_ptr = 
            _Gen_Char_Con<_ele_str_type>(__base_con_, _Uid_Gen_Dev(_Rand_Gen)); 
                                                        // ignore the case: size = 0
        _seq_str_con_ptr->push_back(std::move(*_char_con_ptr.release()));
    }

    return _seq_str_con_ptr;
}

// partial specializtion
// std::list<str_type>
// std::deque<str_type>
template< size_t _sz,
            typename _Seq_Str_Container >
std::unique_ptr<_Seq_Str_Container>
_Gen_Seq_Str_Con
(__CONST_PTR_TO_CONST__(typename _Seq_Str_Container::value_type::value_type) __base_chars_, 
size_t _str_sz_rg1, size_t _str_sz_rg2)
{   
    using _ele_str_type = typename _Seq_Str_Container::value_type;
    // auto _seq_str_con_ptr = 
    //     std::unique_ptr<_Seq_Str_Container>
    //     (new _Seq_Str_Container());
    auto _seq_str_con_ptr = 
        std::make_unique<_Seq_Str_Container>();

    __RD_I_NUM__(size_t, _str_sz_rg1, _str_sz_rg2);
    for(size_t _i = 0; _i < _sz; ++_i)
    {
        auto _char_con_ptr = 
            _Gen_Char_Con<_ele_str_type>(__base_chars_, _Uid_Gen_Dev(_Rand_Gen)); 
                                                        // ignore the case: size = 0
        _seq_str_con_ptr->push_back(std::move(*_char_con_ptr.release()));
    }

    return _seq_str_con_ptr;
}

// overload
template< size_t _sz,
            typename _Seq_Str_Container >
std::unique_ptr<_Seq_Str_Container>
_Gen_Seq_Str_Con
(const typename _Seq_Str_Container::value_type & __base_con_, 
size_t _str_sz_rg1, size_t _str_sz_rg2)
{   
    using _ele_str_type = typename _Seq_Str_Container::value_type;
    // auto _seq_str_con_ptr = 
    //     std::unique_ptr<_Seq_Str_Container>
    //     (new _Seq_Str_Container());
    auto _seq_str_con_ptr = 
        std::make_unique<_Seq_Str_Container>();

    __RD_I_NUM__(size_t, _str_sz_rg1, _str_sz_rg2);
    for(size_t _i = 0; _i < _sz; ++_i)
    {
        auto _char_con_ptr = 
            _Gen_Char_Con<_ele_str_type>(__base_con_, _Uid_Gen_Dev(_Rand_Gen)); 
                                                        // ignore the case: size = 0
        _seq_str_con_ptr->push_back(std::move(*_char_con_ptr.release()));
    }

    return _seq_str_con_ptr;
}



// TODO: the most ideal state, compiled time reflection, random it by constructor
// TODO: 
// gen arbitrary data from _Tp
// std::declval<_Tp>().gen_data()

// 1. use _Container<_Tp >
// 2. use _Tp<_Meta_Tp ... >
// 3. use enable_if <> ??? 
// template <typename _Tp, 
//             typename _Container,
//             typename _Meta_Tp ... >
// GEN_FUNC_COPY
// // #if (__CC_VER__ >= 4)
// // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// // #endif
// void _Seq_Con_Ins_Gen_Arbitrary
// (_Container &__container, size_t __gen_count)
// {
//     __RD_I_NUM__(_Num_Tp, __range_1, __range_2);
//     std::generate_n(std::back_inserter(__container), 
//                     __gen_count, __RD_I_LAM__(_Num_Tp)));
// }



// design interface for std::mt19937
// xorshift (more efficient, in game)
class _xorshift32_gen
{
public:
    using result_type = uint32_t;

    explicit 
    _xorshift32_gen
    (uint32_t const &_x_v)
    noexcept 
        : _xv(_x_v){}
    
    constexpr 
    uint32_t 
    operator() 
    () noexcept
    {
        uint32_t _t = _xv;
        _t ^= _t << 13;
	    _t ^= _t >> 17;
	    _t ^= _t << 5;
        return _xv = _t;
    }

    GEN_FUNC_COPY constexpr 
    uint32_t 
    min() noexcept 
    { return 0x1; }

    GEN_FUNC_COPY constexpr 
    uint32_t 
    max() noexcept 
    { return UINT32_MAX; }

private:
    uint32_t _xv;

};



// TODO: more effective
// wangshash (use to gen parallelly)
class _wangshash_gen
{
public:

};



// we have a self defined class, the class must have a method
// which is named gen_data()
// our _rand_lib_ must call the class gen_data() to insert into class container 
// 

__END_NS__

__DEF_NS__(Alan::Demos::Test::Func)

void TestNormalRand();
void TestRandRDMT19937();
void TestXorshift32();

__END_NS__

#endif 