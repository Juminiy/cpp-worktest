#include "_algo_.hpp"
#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"
#include "_ai_snake_game_.hpp"

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
        __TYPE_OF__(cin_itr) cin_itr_end;
        std::copy(cin_itr, cin_itr_end,
                    std::back_inserter<>(i32_v));
        ConsoleIterOutput<pointT>(i32_v, ", ");
    }
}

void TestAssoContainerAlgo()
{
    std::set<int > i32_s1, i32_s2;
    #if (__CC_VER__ > 1)
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

END_NAMESPACE_ALAN