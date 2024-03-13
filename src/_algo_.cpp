#include "_algo_.hpp"
#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

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
                    [](const int &__index__){
                        return rand() % __index__;
                    });
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
    PSEUDORANDOM_DECL;
    std::vector<int> i32_dest, i32_src(1<<8);
    std::generate(i32_src.begin(), i32_src.end(),
                    rand);
    std::reverse_copy(i32_src.begin(), i32_src.end(),
                        std::back_inserter<>(i32_dest));
    ConsoleIterOutput<int>(i32_dest, ", ");
    // std::set_union()
}

void TestAssoContainerAlgo()
{
    std::set<int > i32_s1, i32_s2;
    #if (__CC_VER__ >= 4)
        typeof(i32_s1) i32_s_diff;
        typeof(i32_s1) i32_s_union;
        typeof(i32_s1) i32_s_inters;
    #else 
        std::set<int > i32_s_diff;
        std::set<int > i32_s_union;
        std::set<int > i32_s_inters;
    #endif 
    for(int i = 0; i < (1<<4); i++)
        i32_s1.insert(i << 1),
        i32_s2.insert(i >> 1);

    {   
        PRINTLN(_RED(std::string("diffs")));
        std::set_difference(i32_s1.begin(), i32_s1.end(),
                            i32_s2.begin(), i32_s2.end(),
                            std::inserter(i32_s_diff, i32_s_diff.begin()));
        ConsoleIterOutput<int> (i32_s_diff, ", ");
    }

    {   
        PRINTLN(_YELLOW(std::string("unions")));
        std::set_union(i32_s1.begin(), i32_s1.end(),
                        i32_s2.begin(), i32_s2.end(),
                        std::inserter(i32_s_union, i32_s_union.begin()));
        ConsoleIterOutput<int> (i32_s_union, ", ");
    }

    {   
        PRINTLN(_BLUE(std::string("intersections")));
        std::set_intersection(i32_s1.begin(), i32_s1.end(),
                                i32_s2.begin(), i32_s2.end(),
                                std::inserter(i32_s_inters, i32_s_inters.begin()));
        ConsoleIterOutput<int> (i32_s_inters, ", ");
    }

}

END_NAMESPACE_ALAN