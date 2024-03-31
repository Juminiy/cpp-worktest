#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_stream_.hpp"
#include "../../include/_seq_container_.hpp"
#include "../../include/_asso_container_.hpp"
#include "../../include/_ai_snake_game_.hpp"



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

#include <memory>


USE_NAMESPACE_ALAN

typedef std::unordered_map<int, std::string > um_i32_str;
typedef um_i32_str::value_type _i32_str_pr ;

void TestUMap()
{   
    std::priority_queue<int, 
                        std::vector<int>, 
                        std::greater<int>> bh;
    bh.push(1);
    PRINTLN(bh.size());

    std::unordered_map<int, std::string > umis ;
    
    umis.insert(_i32_str_pr(1, "w"));
    // TODO: overload std::pair<_Tp1, _Tp2 >
    // ConsoleIterOutput<_i32_str_pr >(umis);

    std::map<int, std::string> mis;
    mis.insert(_i32_str_pr(1, "s"));

    std::multimap<int, std::string> mm;
    mm.insert(_i32_str_pr(1, "ss"));
    mm.insert(_i32_str_pr(1, "bb"));
    mm.insert(_i32_str_pr(1, "ss"));
    mm.insert(_i32_str_pr(1, "kk"));
    
    std::set<int> i32S;
    i32S.insert(1);
    ConsoleIterOutput<int>(i32S);

}

void BirthdayParadox(int const &_sides, const int &_times = 2)
{
    PSEUDORANDOM_DECL;
    std::unordered_multiset<int> i32s;
    int _i32_cnt = 0;
    while(true)
    {
        int _gen_i32 = rand() % _sides;
        if (AssoCount<>(i32s, _gen_i32) == 
            size_t (_times - 1))
        {
            _i32_cnt = i32s.size();
            break;
        }
        i32s.insert(_gen_i32);
    }
    std::cout << "sides [" 
                << _sides 
                << "], occurs ["
                << _times 
                << "] times, "
                << "expects ["
                << (pow(float(_sides), float(1.0/_times))) 
                << "], "
                << "counts ["  
                << _i32_cnt 
                << "]" 
                << std::endl;
}

void TestBirthDayParadox()
{
    PSEUDORANDOM_DECL;
    {
        int cnt = rand()%(1<<8);
        PRINTLN_DETAIL("occurs 2 times");
        while(cnt--)
        {
            BirthdayParadox(rand() % (1<<16));
        }
    }

    {
        int cnt = rand()%(1<<8);
        PRINTLN_DETAIL("occurs 3 times");
        while(cnt--)
        {
            BirthdayParadox(rand() % (1<<16), 3);
        }
    }
}

void TestUSet()
{   
    PSEUDORANDOM_DECL;
    std::set<pointT> pTS;
    for( int i = 0; i < 1<<10; ++i)
        pTS.insert(pointT(rand()% (1<<8) , rand()% (1<<16)));
    
    std::cout << "point set size = " 
                << pTS.size() 
                << std::endl 
                << "elem is " 
                << std::endl;
    ConsoleBeautyOutput<pointT>(pTS);
}


void TestIterator()
{
    PSEUDORANDOM_DECL;
    std::set<int> i32_mus;
    for(int i = 0; i < 1<< 10; ++ i)
        i32_mus.insert(i >> 1),
        i32_mus.insert(i << 1);
    
    _COLOR_START(_COLOR_CYAN);
    PRINTLN("i32_mus size = "+std::to_string(i32_mus.size()));

    #define _val_type decltype(i32_mus)::value_type
    #define _con_type decltype(i32_mus)
    #define _iter_type decltype(i32_mus)::iterator
    Alan::ConsoleIterOutputIterPairRange(
        Alan::AssoRange_v3<_val_type, _con_type, _iter_type>
            (i32_mus, 10, 100)
    );
    
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

UNUSED
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
        ASSERT_FILE(ConFilePath(CXX_keywords.txt));
        // insert keyword to <"keyword-spec", 0>
        std::string _line;
        while(*inputFile >> _line)
            _kw_cnt.insert(si_pair(trim_string(_line), 0));
    }


    {
        // source code file input 
        ASSERT_FILE(ConFilePath(Source_code.cpp));
        // when encounter ["keyword-spec"] ++
        std::string _line;
        while(*inputFile >> _line)
        {
            // auto _wds = seperate_line(_line);
            // for( auto &_wd : _wds)
            //     if (_kw_cnt.find(_wd) !=
            //         _kw_cnt.cend())
            //         _kw_cnt[_wd] ++;
            if (AssoFind<>(_kw_cnt, _line))
                _kw_cnt[_line] ++;
        }
    }

    // print map result
    for(auto &_pr : _kw_cnt)
        std::cout << _RED(_pr.first) 
                    << " occurs " 
                    << _pr.second 
                    << " times" 
                    << std::endl;

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

void TestRangeFind()
{
    std::multiset<int> mus_i32;
    for(int i = 0 ; i < 1 << 10; i ++)
        mus_i32.insert(i >> 1),
        mus_i32.insert(i >> 1);

    {
        auto _it_rg = AssoRange_v0<int, 
                                std::multiset<int>, 
                                std::multiset<int>::iterator >
                            (mus_i32, 10, 20);
        PRINT("Assert 11, "), PRINTLN("Assert 19");
        PRINT_DETAIL(*_it_rg.first), PRINTLN_DETAIL(*--_it_rg.second);
    }
    

    {
        auto _it_rg = AssoRange_v1<int, 
                                std::multiset<int>, 
                                std::multiset<int>::iterator >
                            (mus_i32, 10, 20);
        PRINT("Assert 11, "), PRINTLN("Assert 20");
        PRINT_DETAIL(*_it_rg.first), PRINTLN_DETAIL(*--_it_rg.second);
    }

    {
        auto _it_rg = AssoRange_v2<int, 
                                std::multiset<int>, 
                                std::multiset<int>::iterator >
                            (mus_i32, 10, 20);
        PRINT("Assert 10, "), PRINTLN("Assert 19");
        PRINT_DETAIL(*_it_rg.first), PRINTLN_DETAIL(*--_it_rg.second);
    }

    {
        auto _it_rg = AssoRange_v3<int, 
                                std::multiset<int>, 
                                std::multiset<int>::iterator >
                            (mus_i32, 10, 20);
        PRINT("Assert 10, "), PRINTLN("Assert 20");
        PRINT_DETAIL(*_it_rg.first), PRINTLN_DETAIL(*--_it_rg.second);
    }
}

typedef std::map<std::string, std::string > _SS_Map;
typedef std::map<std::string, std::string > & _SS_Map_reference;
typedef const std::map<std::string, std::string > & _SS_Map_const_reference;

typedef std::multimap<std::string, std::string> _SS_MMap;
typedef std::multimap<std::string, std::string> & _SS_MMap_reference;
typedef const std::multimap<std::string, std::string> & _SS_MMap_const_reference;


typedef std::map<std::string, int > _SI_Map;
typedef std::map<std::string, int > & _SI_Map_referecne;
typedef const std::map<std::string, int > & _SI_Map_const_reference;

_SI_Map_referecne
_NumberDuplicateEntries(_SS_Map_const_reference _ss_map)
{   

    auto _ss_val_cnt = 
        std::make_shared<_SI_Map>(_SI_Map());
    for(auto _it = _ss_map.begin();
                _it != _ss_map.end();
                ++ _it)
        ++ (*_ss_val_cnt)[_it->second];

    return *_ss_val_cnt;
}

_SS_MMap_reference
_InvertMap(_SS_Map_const_reference _ss_map)
{
    auto _ss_mul_map = 
        std::make_shared<_SS_MMap>(_SS_MMap());
    for(auto _it = _ss_map.begin();
                _it != _ss_map.end();
                ++ _it)
        _ss_mul_map->insert(std::make_pair(_it->second,
                                            _it->first));

    return *_ss_mul_map;
}

// all r in _ss_one, all s in _ss_two
// if _ss_one[r] = s &
//      _ss_two[s] = t 
// then _Compose(one, two) -> _ss_res[r] = t 
_SS_Map_reference
_ComposeMap(_SS_Map_const_reference _ss_one, 
            _SS_Map_const_reference _ss_two)
{
    auto _ss_res = 
        std::make_shared<_SS_Map>(_SS_Map());
    for(auto _o_it = _ss_one.begin(), 
                _t_it = _ss_two.end();
            _o_it != _ss_one.end();
            ++ _o_it)
    {   
        _t_it = _ss_two.find(_o_it->second);
        if(_t_it != _ss_two.cend())
            _ss_res->insert(
                ss_pair(_o_it->first, 
                _t_it->second));
    }

    return *_ss_res;
}

void _PrintMatchingPrefixes(const std::set<std::string > &_s_s,
                            const std::string &_s)
{
    auto _contain_prefix = 
        [_s]
        (const std::string &_dest)
        -> bool {
            if (_dest.size() < _s.size())
                return false;
            return !_s.compare(_dest.substr(0, _s.size()));
        };
    bool _matching = false;
    for(auto &_it_s : _s_s)
    {
        if(_contain_prefix(_it_s))
        {
            _matching = true;
            PRINT(_RED(_it_s.substr(0, _s.size()))), 
            PRINTLN(_RED(_it_s.substr(_s.size(), _it_s.size())));
        } else
        {
            if(_matching)
                break;
        }
    }
}

void TestMatchingPrefix()
{   
    PSEUDORANDOM_DECL;
    std::set <std::string > _s_s;
    std::string _s = genString(1<<3); 
    PRINTLN(_BLUE(_s));
    for(int i = 0; i < (1<<8) ; ++i)
        _s_s.insert(_s ),
        _s_s.insert(_s + genString(1<<3)),
        _s_s.insert(genString(1<<3) + _s),
        _s_s.insert(genString(1<<3) + _s + genString(1<<3)),
        _s_s.insert(genString(1<<4) + _s + genString(1<<4));
    PRINTLN(_CYAN("_s_s.size() = " + 
                    std::to_string(_s_s.size())));
    _PrintMatchingPrefixes(_s_s, _s);

}

END_NAMESPACE_ALAN
