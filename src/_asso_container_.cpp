#include "_i_lib_.hpp"
#include "_asso_container_.hpp"
#include "_ai_snake_game_.hpp"
#include "_stl_lib_.hpp"
#include "_stream_.hpp"

#include <ctime>
#include <cmath>
#include <cassert>

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


void TestIterator()
{
    PSEUDORANDOM_DECL
    std::set<int> i32_mus;
    for(int i = 0; i < 1<< 10; ++ i)
        i32_mus.insert(i >> 1),
        i32_mus.insert(i << 1);
    
    _COLOR_START(_COLOR_CYAN);
    PRINTLN("i32_mus size = "+std::to_string(i32_mus.size()));

    for (auto _sit = i32_mus.lower_bound(10),
                _eit = i32_mus.upper_bound(100); 
                _sit != _eit; 
                ++_sit)
        std:: cout << *_sit << std::endl;
    
    _COLOR_RECOVER;
}

void TestMapDiffer()
{   
    {
        std::map<std::string, std::string> _ssmp;
        _ssmp["C++"] = "Great";
        _ssmp["C++"] = "Alful";
    }

    {
        std::map<std::string, std::string> _ssmp;
        _ssmp.insert(ss_pair("C++", "Great"));
        auto [_it, succ] = _ssmp.insert(ss_pair("C++", "Alful"));
        if (succ)
            std::cout << "insert new " << _it->second << std::endl;
        else 
            std::cout << "failed insert " << std::endl;
    }
}

static bool inline is_space(char const & _ch)
{
    return _ch == ' ' || 
            _ch == '\r' || 
            _ch == '\t' || 
            _ch == '\n';
}

static bool inline is_delimiter(std::string const & _delimiter)
{
    return _delimiter == "," ||
            _delimiter == ";";
}

// trim string leading and ending space 
std::string trim_string(std::string const & __str)
{      
    int l_idx = -1, r_idx = __str.size();
    while(++l_idx < r_idx && 
            is_space(__str[l_idx]));

    while(0 <= --r_idx && 
            is_space(__str[r_idx]));

    return __str.substr(l_idx, r_idx+1);
}

std::vector<std::string> seperate_line(std::string const & __line)
{
    // seperate by space
    std::vector<std::string> strv;
    std::string _word;
    for(auto _ch : __line)
    {
        if(is_space(_ch))
        {
            if (_word.size())
                strv.push_back(_word);
            _word.clear();
        } else 
        {
            _word += _ch;
        }
    }
    return strv;
}

void CountKeyWordsOccurences()
{   
    std::map<std::string, int> _kw_cnt;
    {
        // keywords file input
        ASSERT_FILE("../test/static-file/CXX_keywords.txt");
        // insert keyword to <"keyword-spec", 0>
        std::string _line;
        while(*inputFile >> _line)
            _kw_cnt.insert(si_pair(trim_string(_line), 0));
    }


    {
        // source code file input 
        ASSERT_FILE("../test/static-file/Source_code.cpp");
        // when encounter ["keyword-spec"] ++
        std::string _line;
        while(*inputFile >> _line)
        {
            // auto _wds = seperate_line(_line);
            // for( auto &_wd : _wds)
            //     if (_kw_cnt.find(_wd) !=
            //         _kw_cnt.cend())
            //         _kw_cnt[_wd] ++;
            if (_kw_cnt.find(_line) != 
                _kw_cnt.cend())
                _kw_cnt[_line] ++;
        }
    }

    // print map result
    for(auto &_pr : _kw_cnt)
        std::cout << RED_STR(_pr.first) << " occurs " << _pr.second << " times" << std::endl;

}

void TestFlatAdapter()
{
    // compiler lib not support yet
}

void TestMultiContainer()
{
    std::multiset<int> mus_i32;

    for(int i = 0 ; i < 1 << 10; i ++)
        mus_i32.insert(i >> 1),
        mus_i32.insert(i >> 1);

    mus_i32.erase( 8 );
    _COLOR_START(_COLOR_RED);
    std::cout << mus_i32.count( 8 ) << std::endl;
    _COLOR_RECOVER;

}

END_NAMESPACE_ALAN
