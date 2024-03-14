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
}