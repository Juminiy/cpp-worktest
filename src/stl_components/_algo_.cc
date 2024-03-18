#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_algo_.hpp"
#include "../../include/_ai_snake_game_.hpp"



#include <cstdlib>
#include <cstring>
#include <cctype>


#include <iostream>
#include <iomanip>

#include <iterator>
#include <memory>

#include <vector>
#include <deque>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <algorithm>
#include <numeric>
#include <utility>
#include <chrono>
#include <random>


USE_NAMESPACE_ALAN

void TestAlgo()
{   
    PSEUDORANDOM_DECL;

    size_t i32_v_sz = rand() % (1<<8);

    auto i32_v = std::vector<int>(i32_v_sz);
    std::generate(i32_v.begin(),
                    i32_v.end(),
                    [](){return rand() % (1<<10);});
    PRINTLN("gen ok ");


    std::sort(i32_v.begin(),
                i32_v.end(),
                []
                (const int &__lhs__, 
                    const int & __rhs__) 
                    -> bool {
                    return __lhs__ > __rhs__;
                });
    ConsoleIterOutput<int>(i32_v, ", ");
    PRINTLN("sort ok ");

    std:: cout << std::boolalpha
        << "binary find random number = " <<
        std::binary_search(i32_v.begin(),
                            i32_v.end(),
                            rand()%(1<<16))
                << std::endl;


    #if (__CC_VER__ == 1<<2)
        std::shuffle(i32_v.begin(),
                        i32_v.end(),
                        std::default_random_engine(TIME_BASED_SEED));
    #elif (__CC_VER__ == 2)
        std::random_shuffle(i32_v.begin(),
                            i32_v.end());
    #endif
    ConsoleIterOutput<int>(i32_v, ", ");
    PRINTLN("shuffle ok ");
    

    _COLOR_START(_COLOR_GREEN);
    std::rotate(i32_v.begin(),
                i32_v.begin() + rand() % (i32_v_sz), 
                i32_v.end());
    ConsoleIterOutput<int>(i32_v, ", ");
    _COLOR_RECOVER;
    PRINTLN("rotate ok ");
}

void TestIteratorAdapter()
{   

    // std::istream_iterator<int>
    //     _is_it(std::cin);
    // std::ostream_iterator<int> 
    //     _os_it(std::cout, " ");
    // *_os_it = *_is_it;
    // {
    //     PSEUDORANDOM_DECL;
    //     std::vector<int> i32_dest, i32_src(1<<8);
    //     std::generate(i32_src.begin(), i32_src.end(),
    //                     rand);
    //     std::reverse_copy(i32_src.begin(), i32_src.end(),
    //                         std::back_inserter<>(i32_dest));
    //     // ConsoleIterOutput<int>(i32_dest, ", ");
    // }

    // {   
    //     auto i32_mus = std::multiset<int>();
    //     std::copy(std::istream_iterator<int>(std::cin),
    //                 std::istream_iterator<int>(),
    //                 std::inserter<>(i32_mus, i32_mus.begin()));
    //     // ConsoleIterOutput<int>(i32_mus, ", ");
    // }


    // conflict buffer with above ? how to solve that ? 
    // should flush buffer ? ios::flush()?
    {   
        pointT i32_i32_p;
        std::cin >> i32_i32_p;
        std::cout << i32_i32_p << std::endl;

        auto i32_v = std::vector<pointT>();
        i32_v.reserve(1<<8);
        auto cin_itr = std::istream_iterator<pointT>(std::cin);
        #if defined(__TYPE_OF__)
            __TYPE_OF__(cin_itr) cin_itr_end;
        #else 
            auto cin_itr_end = std::istream_iterator<pointT>();
        #endif 
        
        std::copy(cin_itr, cin_itr_end,
                    std::back_inserter<>(i32_v));
        ConsoleIterOutput<pointT>(i32_v, ", ");
    }
}

void TestAssoContainerAlgo()
{
    std::set<int > i32_s1, i32_s2;
    #if defined(__TYPE_OF__)
        __TYPE_OF__(i32_s1) i32_s_diff;
        __TYPE_OF__(i32_s1) i32_s_union;
        __TYPE_OF__(i32_s1) i32_s_inters;
    #else 
        std::set<int > i32_s_diff;
        std::set<int > i32_s_union;
        std::set<int > i32_s_inters;
    #endif 
    for(int i = 0; i < (1<<4); i++)
        i32_s1.insert(i << 1),
        i32_s2.insert(i >> 1);

    PRINTLN(_GREEN(std::string("s1")));
    ConsoleIterOutput<int> (i32_s1, ", ");
    PRINTLN(_GREEN(std::string("s2")));
    ConsoleIterOutput<int> (i32_s2, ", ");

    {   
        PRINTLN(_RED(std::string("s1 diffs s2")));
        std::set_difference(i32_s1.begin(), i32_s1.end(),
                            i32_s2.begin(), i32_s2.end(),
                            std::inserter(i32_s_diff, i32_s_diff.begin()));
        ConsoleIterOutput<int> (i32_s_diff, ", ");
    }

    {   
        PRINTLN(_YELLOW(std::string("s1 unions s2")));
        std::set_union(i32_s1.begin(), i32_s1.end(),
                        i32_s2.begin(), i32_s2.end(),
                        std::inserter(i32_s_union, i32_s_union.begin()));
        ConsoleIterOutput<int> (i32_s_union, ", ");
    }

    {   
        PRINTLN(_BLUE(std::string("s1 intersections s2")));
        std::set_intersection(i32_s1.begin(), i32_s1.end(),
                                i32_s2.begin(), i32_s2.end(),
                                std::inserter(i32_s_inters, i32_s_inters.begin()));
        ConsoleIterOutput<int> (i32_s_inters, ", ");
    }
    _COLOR_START(_COLOR_GREEN);
    
    PRINT_VA("%s\n", "va 1 parameter");
    _COLOR_START(_COLOR_RED);
    LOG_ERR("tag match error",
                __DATE__, __TIME__,
                __FILE__, __LINE__);
     _COLOR_RECOVER;
    _COLOR_RECOVER;

}


void TestRemoveAlgo()
{       
    PSEUDORANDOM_DECL;
    auto i32_v = std::vector<int >(1<<4);
    std::generate(i32_v.begin(),
                    i32_v.end(),
                    []() -> int
                    {
                        return rand() % (1<<5);
                    });
    
    PRINTLN("After gen");                
    std::copy(i32_v.begin(), i32_v.end(),
                std::back_inserter(i32_v));
    PRINTLN("After copy");
    _COLOR_START(_COLOR_GREEN);
    ConsoleIterOutput<int > (i32_v, ", ");


    i32_v.erase(std::remove_if(i32_v.begin(), i32_v.end(), 
                                [](const int &_i32) -> bool 
                                {
                                    return !(_i32 & (_i32 -1));
                                }), 
                i32_v.end());
    
    PRINTLN("After vi remove");
    _COLOR_START(_COLOR_BLUE);
    ConsoleIterOutput<int > (i32_v, ", ");
}

void TestArbitraryAlgo()
{
    std::string _s;
    _s.resize(1<<5);
    std::string char_sets(_letter_xx.substr(0, 52));
    std::generate(_s.begin(), _s.end(),
                    [char_sets]()-> char 
                    {
                        return char_sets[rand()%52];
                    });
    ConsoleIterOutput<char >(_s, ", ");

    std::transform(_s.begin(), _s.end(), 
                    _s.begin(), ::tolower);
    ConsoleIterOutput<char >(_s, ", ");
}

// 1. remove not alpha
// 2. all alpha to uppercase
// 3. is palindrome
bool Char_Palindrome(const std::string &_par)
{   
    std::string _par_cp(_par);
    _par_cp.erase(std::remove_if(_par_cp.begin(), _par_cp.end(), 
                                [](const char _ch) -> bool{
                                    return !isalpha(_ch);
                                }), 
                _par_cp.end());

    std::transform(_par_cp.begin(), _par_cp.end(),
                    _par_cp.begin(), ::toupper);

    return std::equal(_par_cp.begin(),
                        _par_cp.begin() + (_par_cp.size() >> 1),
                        _par_cp.rbegin());
}

// 1. split words by white space ' ' put them into vector<std::string> 
// 1. remove not alpha words
// 2. all words to uppercase
// 3. vector is palindrome
bool Word_Palindrome(const std::string &_par)
{   
    std::string _par_cp(_par);
    std::vector<std::string > str_v;
    size_t start_i = 0, last_i = 0;
    std::for_each(_par_cp.begin(), _par_cp.end(),
                    [&str_v, _par_cp,
                    &start_i, &last_i]
                    (const char &_ch){
                        last_i++;
                        if(_ch == ' ')
                        {   
                            auto _par_sub = _par_cp.substr(start_i, last_i-start_i-1);
                            if (std::find_if_not(_par_sub.begin(), _par_sub.end(), isalpha) 
                                == _par_sub.end())
                                std::transform(_par_sub.begin(), _par_sub.end(),
                                                _par_sub.begin(), ::toupper),
                                str_v.push_back(_par_sub);
                            start_i = last_i;
                        }
                    });
    ConsoleIterOutput<std::string > (str_v);
    return std::equal(str_v.begin(),
                        str_v.begin() + (str_v.size() >> 1),
                        str_v.rbegin());
}


// example: 
// 1. <_Tp = std::string > = AccbccA
// 2. <_Tp = std::string > = This is this
void Test_Palindrome()
{   
    _COLOR_START(_COLOR_BLUE);
    PRINTLN("char palindrome");
    std:: cout << std::boolalpha
                << Alan::Char_Palindrome(optarg) << std::endl;
    _COLOR_RECOVER;

    _COLOR_START(_COLOR_GREEN);
    PRINTLN("word palindrome");
    std:: cout << std::boolalpha
                << Alan::Word_Palindrome("wow THis is this wow ") << std::endl;
    std:: cout << std::boolalpha
                << Alan::Word_Palindrome("wow kaobei ss") << std::endl;
    _COLOR_RECOVER;
}


void Test_Tp_AVG()
{       

    PSEUDORANDOM_DECL;
    size_t i32_v_sz = rand() % (1<<8);

    auto i32_v = std::vector<int>(i32_v_sz);
    std::generate(i32_v.begin(),
                    i32_v.end(),
                    [](){return rand() % (1<<10);});
    PRINTLN("gen ok ");

    std::sort(i32_v.begin(), i32_v.end());
    PRINTLN("sort ok");

    ConsoleIterOutput<int >(i32_v);
    std:: cout << _Avg<int, 
                        std::vector<int >, 
                        std::vector<int >::iterator >
                    (i32_v, 8, 105, 0) 
                << std::endl;
}

void Test_LB_UB()
{
    auto i32_v = std::vector<int > {1, 2, 3, 4, 
                            5, 5, 5, 6, 6, 
                            77, 88, 99, 1000, 
                            1888, 10001};
    auto i32_vi = std::vector<int>
        {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};

    const size_t max_num_width = 
        std::to_string(*std::max_element(i32_v.begin(), i32_v.end(),
                            [](const int &_lhs, 
                                const int &_rhs) -> bool {
                                return std::to_string(_lhs).size() < 
                                        std::to_string(_rhs).size();
                            })).size();
    PRINTLN_DETAIL(max_num_width);

    PRINT("index: ");
    CONSOLE_FIXED_OUTPUT(i32_vi, int, 5, ' ', std::internal, ", ");
    PRINT("value: ");
    CONSOLE_FIXED_OUTPUT(i32_v, int, 5, ' ', std::internal, ", ");

    

    auto _is_it = std::istream_iterator<int> (std::cin);
    int dest = 0;
    while (dest != (1<<31)) {
        dest = *_is_it;
        PRINTLN_DETAIL(  
            std::to_string(std::distance(
                            i32_v.begin(),
                            std::lower_bound(i32_v.begin(), 
                                                i32_v.end(), 
                                                dest))));
        PRINTLN_DETAIL(
            std::to_string(std::distance(
                            i32_v.begin(),
                            std::upper_bound(i32_v.begin(), 
                                                i32_v.end(), 
                                                dest))));
        _is_it++;
    }
}



void TestTask()
{
    auto RemoveShortWords UNUSED = 
        [](std::vector<std::string > &_sv) 
        -> bool {
            _sv.erase(
                std::remove_if(_sv.begin(), _sv.end(), 
                                [](const std::string &_si) 
                                -> bool 
                                {return _si.size() <= 3;}), 
                _sv.end());
            return true;
        };

    auto _sv UNUSED = std::vector<std::string >
        {"qwe", "qwertyu", "Me First", "afsfasq", "afasfasg", 
        "qfqwfqwqwfw", "a", "", "Me First", "aa", "safs", "Me First", "Me First"};

    // PRINTLN("after gen");
    // ConsoleIterOutput<std::string>(_sv);

    // PRINTLN("after filter");
    // RemoveShortWords(_sv);
    // ConsoleIterOutput<std::string>(_sv);


    auto DistanceToOrigin UNUSED = 
        [](std::vector<double > &_pv)
        -> double  
        {
            return ::sqrt(
                std::inner_product(_pv.begin(), _pv.end(),
                                    _pv.begin(), 0.0));
        };

    auto _pv UNUSED = std::vector<double > {1, 2, 3, 4, 5, 6};
    // std::cout << std::setprecision(10) << DistanceToOrigin(_pv) << std::endl;

    auto BiasedSort UNUSED = 
        [](std::vector<std::string > &_sv, const std::string &_Se)
        -> bool 
        {
            std::stable_sort(_sv.begin(), _sv.end(),
                            [_Se](const std::string &_lhs, 
                                const std::string & _rhs) 
                            -> bool  
                            {   
                                if (_lhs == _Se)
                                    return true;
                                else if (_rhs == _Se)
                                    return false;
                                else 
                                    return _lhs < _rhs;                                
                            });
            return true; 
        };
    

    // BiasedSort(_sv, "Me First");
    // ConsoleIterOutput<std::string>(_sv);

    auto CriticsPick = 
        [](const std::map< std::string, double > &_movies,
            const int &_top_n)
        -> std::set< std::string > 
        {   
            auto _re_ms = std::multimap< double, std::string, std::greater<double > > ();
            int __top_n = _top_n;
            for(auto &_pr : _movies)
                _re_ms.insert(std::make_pair(_pr.second, _pr.first));

            // error is here
            // ConsoleIterOutput< std::pair<double , std::string> >(_re_ms); 
            // need to debug
            auto _res = std::set< std::string > ();
            for(auto &_pr : _re_ms)
            {
                std::cout << _pr << std::endl;
                if(__top_n--)
                    _res.insert(_pr.second);
                else 
                    break;
            }
                
            return _res;
        };

    auto _movies = std::map< std::string, double >();
    _movies["mskasw"] = 1.0, _movies["jrtjt"] = 1.0, _movies["xcz"] = 1.0;
    _movies["dgsq"] = 2.0, _movies["ndse"] = 2.0, _movies["wyq"] = 2.0;
    _movies["qwyye"] = 3.0, _movies["saaa"] = 3.0, _movies["faaa"] = 3.0;
    _movies["sfw"] = 4.0, _movies["xb"] = 4.0, _movies["sfwq"] = 4.0;
    _movies["mskasw"] = 5.0, _movies["jrtjt"] = 5.0, _movies["sawqqqqw"] = 5.0;
    _movies["dgsq"] = 6.0, _movies["xxxawq"] = 6.0, _movies["wyq"] = 6.0;
    _movies["mskwwqqqwwasw"] = 7.0, _movies["ssasdfaz"] = 7.0, _movies["sfaqqwqwrqr"] = 7.0;
    _movies["qw"] = 8.0, _movies["zqq"] = 8.0, _movies["wewqrqwcqw"] = 8.0;
    
    ConsoleIterOutput<std::string > ( CriticsPick(_movies, 10) );
}

END_NAMESPACE_ALAN