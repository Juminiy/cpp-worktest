#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_ai_snake_game_.hpp"
#include "../../include/_rand_lib_.hpp"



#include <numeric>
#include <random>

#include <cstdlib>
#include <cmath>
#include <cctype>

#include <vector>
#include <set>
#include <algorithm>

#include <numeric>
#include <utility>
#include <chrono>


void TestNormalRand()
{
    PSEUDORANDOM_DECL;
    for(int pse_num = 0xff; 
        pse_num; 
        pse_num = ::rand() % (1<<8))
    {
        PRINTLN_DETAIL(pse_num);
        GamePause(500000);
    }
}

void TestRandRDMT19937()
{   
    auto i32_v = std::vector<int>(1<<4);
    Alan::_Gen_Num(1, 2);
    Alan::_Seq_Con_Fil_Gen_Num<int > (i32_v, 1<<4, 1<<10);    

    // i32_v.resize();

    _COLOR_START(_COLOR_BLUE);
    Alan::ConsoleIterOutput<int > (i32_v);
    _COLOR_RECOVER;
    
    // PRINTLN_DETAIL(std::to_string(sizeof(double long)));
}

void TestXorshift32()
{
    auto _x = Alan::_xorshift32_gen(0x114514ff);
    std::uniform_int_distribution<int > _uid(1, 1<<10);

    std::set<int > _s;
    for(int _gen_by_xor = 0x01; ;
            _gen_by_xor = _uid(_x))
        if(!Alan::AssoFind<>(_s, _gen_by_xor))
            _s.insert(_gen_by_xor),
            PRINTLN_DETAIL(_gen_by_xor),
            GamePause(500000);
        else
            break;
    PRINTLN_DETAIL("conflict after " 
                    << _s.size()
                    << " times");
}