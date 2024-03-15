#include "_rand_lib_.hpp"
#include "_stl_lib_.hpp"
#include "_i_lib_.hpp"

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



void TestRandRDMT19937()
{   
    std::random_device _RD;
    std::mt19937 UNUSED _RNG(_RD());
    std::uniform_int_distribution<> UNUSED _uid_gen_int(0, 1<<16);

    auto i32_v = std::vector<int>(1<<4);
    // std::generate(i32_v.begin(), 
    //                 i32_v.end(), 
    //                 [_RNG, &_uid_gen_int]
    //                 () -> int
    //                 {return _uid_gen_int(_RNG);});
    ConsoleIterOutput<int > (i32_v);
    PRINTLN_DETAIL(std::to_string(sizeof(double long)));
}