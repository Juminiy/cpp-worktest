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

#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <utility>
#include <chrono>
#include <memory>

__DEF_NS__(Alan)
// TODO: 
// generate random data for Batch Test
// 1. random number < integer, float >: 
//  (1). < char, short, int, long long, ui32, ui64 >
//  (1). < float, double, [double long] >
// 2. random string < char, wchar_t, char16_t, char32_t >
//  (1). fixed length, random length
//  (2). legalcy __xxx__
//      (     i). legalcy name(_A-Za-z0-9)
//      (    ii). legalcy alphanum(A-Za-z0-9)
//      (   iii). legalcy alpha(A-Za-z)
//      (  iiii). legalcy num(0-9)
//      ( iiiii). legalcy all chars( in ascci table )
//      (iiiiii). legalcy w_chart, unicode char_t and more...
// 3. random container < seq_container >, < asso_container >
//  (1). Sequential Container 
//      (  i). std::vector< _Tp >
//      ( ii). std::deque< _Tp >
//      (iii). std::list< _Tp >
//  (2). Associative Container 
//      (i). std::unordered_multimap<_Tp1, _Tp2>
//      (ii). std::unordered_multiset< _Tp >
//      (iii). std::multimap<_Tp1, _Tp2>
//      (iiii). std::multiset< _Tp >
//      (iiiii). std::unordered_map<_Tp1, _Tp2> 
//      (iiiiii). std::unordered_set< _Tp > 
//      (iiiiiii). std::map<_Tp1, _Tp2> 
//      (iiiiiiii). std::set< _Tp > 
//  (2). Tp = integer, float, string include in (1, 2)


// Macro to define required Rand_Member
#define __RD_NUM__(_Num_Tp, _Num_Range_1, _Num_Range_2) \
        std::random_device _Rand_Dev_AO; \
        std::mt19937       _Rand_Num_Ge; \
        std::uniform_int_distribution<_Num_Tp > \
            UNUSED _Uid_Gen_Num_Tp(_Num_Range_1, _Num_Range_2)

#define __RD_LAMBDA__ \
        [&_Rand_Dev_AO, &_Uid_Gen_Num_Tp] \
        () -> _Num_Tp \
        { return _Uid_Gen_Num_Tp(_Rand_Dev_AO); }

#define __RD_X_NUM__(__g_tp_, __num_tp_, __num_rg1_, __num_rg2_) \
        std::random_device _Rand_Dev_AO; \
        std::mt19937       _Rand_Num_Ge; \
        std::uniform_ ##__g_tp_ ##_distribution<__num_tp_ > \
            UNUSED _Uid_Gen_Num_Tp(__num_rg1_, __num_rg2_)

#define __RD_I_NUM__(__num_tp_, __num_rg1_, __num_rg2_) \
        __RD_X_NUM__(int, __num_tp_, __num_rg1_, __num_rg2_)

#define __RD_R_NUM__(__num_tp_, __num_rg1_, __num_rg2_) \
        __RD_X_NUM__(real, __num_tp_, __num_rg1_, __num_rg2_)

// single value
// template <typename _Num_Tp >
// _Num_Tp _Gen_Num
// (_Num_Tp const &__range_1, _Num_Tp const &__range_2)
// {
//     __RD_NUM__(_Num_Tp, __range_1, __range_2);
//     return _Uid_Gen_Num_Tp(_Rand_Dev_AO);
// }

// gen single value
template <typename _Num_Tp >
_Num_Tp _Gen_Num
(_Num_Tp const &__range_1, _Num_Tp const &__range_2)
{   
    const std::string _num_tp_str 
        = Alan::__cpp_tid_<_Num_Tp>();
    if (_sfind(_num_tp_str, "double") ||
        _sfind(_num_tp_str, "float"))
    {
        __RD_R_NUM__(_Num_Tp, __range_1, __range_2);
        return _Uid_Gen_Num_Tp(_Rand_Dev_AO);
    }
    else if (_sfind(_num_tp_str, "long") ||
            _sfind(_num_tp_str, "int") ||
            _sfind(_num_tp_str, "unsigned"))
    {
        __RD_I_NUM__(_Num_Tp, __range_1, __range_2);
        return _Uid_Gen_Num_Tp(_Rand_Dev_AO);
    }
    else 
    {
        _COLOR_START(_COLOR_RED);
            ERRLN("SFINAE error occurs!");
        _COLOR_RECOVER;
        return _Num_Tp();
    }
}

// Iterator scoped value
template <typename _Num_Tp, 
            typename _ForwardIterator >
inline
void _Iter_Gen_Num
(_ForwardIterator __first, _ForwardIterator __last, 
    _Num_Tp const &__range_1, _Num_Tp const &__range_2)
{
    __RD_NUM__(_Num_Tp, __range_1, __range_2);
    std::generate(__first, __last, __RD_LAMBDA__);
}

// PreAlloced sequential container scoped value
template <typename _Num_Tp, 
            typename _Container >
inline
void _Seq_Con_Fil_Gen_Num
(_Container &__container, 
    _Num_Tp const &__range_1, _Num_Tp const &__range_2)
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
inline
// #if (__CC_VER__ >= 4)
// _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// #endif
void _Seq_Con_Ins_Gen_Num
(_Container &__container, size_t const &__gen_count,
    _Num_Tp const &__range_1, _Num_Tp const &__range_2)
{
    __RD_NUM__(_Num_Tp, __range_1, __range_2);
    std::generate_n(std::back_inserter(__container), 
                    __gen_count, __RD_LAMBDA__);
}

// TODO: 
// gen arbitrary data from _Tp
// std::declval<_Tp>().gen_data()

// 1. use _Container<_Tp >
// 2. use _Tp<_Meta_Tp ... >
// 3. use enable_if <> ??? 
// template <typename _Tp, 
//             typename _Container,
//             typename _Meta_Tp ... >
// inline
// // #if (__CC_VER__ >= 4)
// // _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// // #endif
// void _Seq_Con_Ins_Gen_Arbitrary
// (_Container &__container, size_t const &__gen_count)
// {
//     __RD_NUM__(_Num_Tp, __range_1, __range_2);
//     std::generate_n(std::back_inserter(__container), 
//                     __gen_count, __RD_LAMBDA__);
// }

// TODO:
// in default range __range_1, __range_2 
// 1. directly generate and return a std::unique_ptr<container_type<_Tp > >
template < typename _Seq_Container, 
            size_t _sz = (1<<5)>
std::unique_ptr<_Seq_Container>
_Gen_Seq_Con
(typename _Seq_Container::value_type __range_1, 
typename _Seq_Container::value_type __range_2)
{
    auto _seq_con_ptr =
        std::unique_ptr<_Seq_Container>
        (new _Seq_Container(_sz));
    _Iter_Gen_Num(_seq_con_ptr->begin(), _seq_con_ptr->end(),
                    __range_1, __range_2);
    return _seq_con_ptr;
}

// 2. generate random std::string

// 3. generate random container_type<std::string >

// 4. mix 1 with 3



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

    static constexpr 
    uint32_t 
    min() noexcept 
    { return 0x1; }

    static constexpr 
    uint32_t 
    max() noexcept 
    { return UINT32_MAX; }

private:
    uint32_t _xv;

};



// TODO: more effective
// wangshash (use to gen parallelly)
class _wangshash_gen_num
{
public:

};



// we have a self defined class, the class must have a method
// which is named gen_data()
// our _rand_lib_ must call the class gen_data() to insert into class container 
// 

__END_NS__

void TestNormalRand();
void TestRandRDMT19937();
void TestXorshift32();

#endif 