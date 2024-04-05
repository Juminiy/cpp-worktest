#pragma once 
#ifndef _RAND_LIB_HPP
#define _RAND_LIB_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

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

USE_NAMESPACE_ALAN
// TODO: 
// generate random data for Batch Test
// 1. random number < integer, float >: 
//  (1). < char, short, int, long long, ui32, ui64 >
//  (1). < float, double, [double long] >
// 2. random string < char, wchar_t >
//  (1). fixed length, random length
//  (2). legalcy __xxx__
//      (  i). legalcy name(_A-Za-z0-9)
//      ( ii). legalcy alpha(A-Za-z)
//      (iii). legalcy all chars( in ascci table )
// 3. random container < seq_container, asso_container >
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
        UNUSED _Uid_Gen_Num_Tp(_Num_Range_1, _Num_Range_2);

#define __RD_LAMBDA__ \
        [&_Rand_Dev_AO, &_Uid_Gen_Num_Tp] \
        () -> _Num_Tp \
        { return _Uid_Gen_Num_Tp(_Rand_Dev_AO); } 

// single value
template <typename _Num_Tp >
// #if (__CC_VER__ >= 4)
// _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// #endifma
_Num_Tp _Gen_Num
(_Num_Tp const &__range_1, _Num_Tp const &__range_2)
{
    __RD_NUM__(_Num_Tp, __range_1, __range_2);
    return _Uid_Gen_Num_Tp(_Rand_Dev_AO);
}

// Iterator scoped value
template <typename _Num_Tp, 
            typename _ForwardIterator >
inline
// #if (__CC_VER__ >= 4)
// _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// #endif
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
// #if (__CC_VER__ >= 4)
// _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// #endif
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

END_NAMESPACE_ALAN

void TestNormalRand();
void TestRandRDMT19937();
void TestXorshift32();

#endif 