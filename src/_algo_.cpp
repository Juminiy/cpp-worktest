#include "_algo_.hpp"
#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <iostream>
#include <iomanip>

#include <iterator>
#include <memory>

#include <vector>
#include <deque>


#include <algorithm>
#include <numeric>
#include <utility>


USE_NAMESPACE_ALAN

void TestAlgo()
{   
    PSEUDORANDOM_DECL;
    auto i32_v = std::vector<int>(1<<8);
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
        << "binary find 18 = " <<
        std::binary_search(i32_v.begin(),
                            i32_v.end(),
                            18) 
                << std::endl;


    #if (__ARCH_OS__ == 1)
        // std::shuffle(i32_v.begin(),
        //             i32_v.end(),
        //             [](const int &__index__){
        //                 return rand() % __index__;
        //             });
    #elif (__ARCH_OS__ == 1)
        std::random_shuffle(i32_v.begin(),
                            i32_v.end());
    #endif
    PRINTLN("shuffle ok ");
    

    _COLOR_START(_COLOR_GREEN);
    std::rotate(i32_v.begin(),
                i32_v.begin() + rand() % (1<<8), 
                i32_v.end());
    ConsoleIterOutput<int>(i32_v, ", ");
    _COLOR_RECOVER;
    PRINTLN("rotate ok ");
}

void TestIteratorAdapter()
{   

    std::istream_iterator<int>
        _is_it(std::cin);

    std::ostream_iterator<int> 
        _os_it(std::cout, " ");

    *_os_it = *_is_it;

    auto i32_v = std::vector<int>{1,2,3};
    auto bk_i32_v UNUSED = std::back_inserter<>(i32_v);
    // std::copy()

    // std::set_union()
}

END_NAMESPACE_ALAN