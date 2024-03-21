#pragma once 
#ifndef _RAND_LIB_HPP
#define _RAND_LIB_HPP

#include <numeric>
#include <random>

#include <cstdlib>
#include <cmath>
#include <cctype>

#include <vector>
#include <algorithm>

#include <numeric>
#include <utility>
#include <chrono>

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
    std::generate(__first, __last,
                    [&_Rand_Dev_AO, &_Uid_Gen_Num_Tp]
                    () -> _Num_Tp
                    {
                        return _Uid_Gen_Num_Tp(_Rand_Dev_AO);
                    });
}

// PreAlloced container scoped value
template <typename _Num_Tp, 
            typename _Container >
inline
// #if (__CC_VER__ >= 4)
// _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// #endif
void _Con_Gen_Num
(_Container &__container, 
    _Num_Tp const &__range_1, _Num_Tp const &__range_2)
{
    _Iter_Gen_Num(__container.begin(), __container.end(), 
                __range_1, __range_2);
}

// Not PreAllocated container
// template <typename _Num_Tp, 
//             typename _Container >
// inline
// #if (__CC_VER__ >= 4)
// _LIBCPP_INLINE_VISIBILITY _LIBCPP_CONSTEXPR_SINCE_CXX20
// #endif
// void _Gen_Num
// (_Container __container, 
//     _Num_Tp const &__range_1, _Num_Tp const &__range_2)
// {
//     _Gen_Num(__container.begin(), __container.end(), 
//                 __range_1, __range_2);
// }

void TestNormalRand();
void TestRandRDMT19937();


#endif 