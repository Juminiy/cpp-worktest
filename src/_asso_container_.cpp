#include "_i_lib_.hpp"
#include "_asso_container_.hpp"
#include "_ai_snake_game_.hpp"
#include "_stl_lib_.hpp"

#include <ctime>

#include <cmath>
#include <string>
#include <iostream>

#include <functional>
#include <algorithm>
#include <iterator>

#include <queue>
#include <vector>

#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

USE_NAMESPACE_ALAN
typedef std::pair<int, std::string> i32_str;

void TestUMap()
{   
    std::priority_queue<int, 
                        std::vector<int>, 
                        std::greater<int>> bh;
    bh.push(1);
    // cout << bh.size() << endl;

    std::unordered_map<int, std::string > umis ;
    umis.insert(i32_str(1, "w"));
    std::map<int, std::string> mis;
    mis.insert(i32_str(1, "s"));
    std::multimap<int, std::string> mm;
    mm.insert(i32_str(1, "ss"));
    mm.insert(i32_str(1, "bb"));
    mm.insert(i32_str(1, "ss"));
    mm.insert(i32_str(1, "kk"));
    for(auto &_e_ UNUSED : mm)
        ;
        // std::cout << "[" << _e_.first << ", " << _e_.second << "]" << std::endl;

    std::set<int> i32S;
    i32S.insert(1);
    std::copy(i32S.cbegin(), 
                i32S.cend(), 
                std::ostream_iterator<int>(std::cout, "\n"));
    // ConsoleIterOutput<std::set<int>, int>(i32S, "\n");

}

void BirthdayParadox(int const &_sides)
{
    PSEUDORANDOM_DECL
    std::unordered_set<int> i32s;
    int _i32_cnt = 0;
    while(true)
    {
        int _gen_i32 = rand() % _sides;
        if (i32s.find(_gen_i32) != i32s.cend())
        {
            _i32_cnt = i32s.size();
            break;
        }
        i32s.insert(_gen_i32);
    }
    std::cout << "sides [" 
                << _sides 
                << "], "
                << "sqr ["
                << (sqrt(double(_sides))) 
                << "], "
                << "count ["  
                << _i32_cnt 
                << "]" 
                << std::endl;
}

void TestBirthDayParadox()
{
    PSEUDORANDOM_DECL
    int cnt = rand()%(1<<8);
    while(cnt--)
    {
        BirthdayParadox(rand() % (1<<16));
    }
}

void TestUSet()
{   
    PSEUDORANDOM_DECL
    std::set<pointT> pTS;
    for( int i = 0; i < 1<<10; ++i)
        pTS.insert(pointT(rand()% (1<<8) , rand()% (1<<16)));
    
    std::cout << "point set size = " 
                << pTS.size() 
                << std::endl 
                << "elem is " 
                << std::endl;
    std::copy(pTS.cbegin(),
                pTS.cend(),
                std::ostream_iterator <pointT>
                                (std::cout, 
                                "\n"));
}

END_NAMESPACE_ALAN
