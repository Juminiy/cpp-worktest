#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_point_loc_.hpp"

#include "../../include/_test_func_.hpp"

#include <iostream>
#include <iomanip>

#include <vector>
#include <deque>
#include <map>

#include <utility>
#include <algorithm>
#include <type_traits>
#include <memory>
#include <functional>

#include <cassert>
#include <any>
#include <cstdint>
#include <cstddef>
#include <cfloat>

// func_ptr do not use const & parameter 
bool _str_sz_less_than
(std::string _str, size_t _sz) 
{
    return _str.size() < _sz;
}

void TestAllV3()
{
    // function converter 
    // lambda do not use const & parameter
    // auto _str_sz_less_than = 
    //     [](std::string _str, size_t _sz) 
    //         -> bool 
    //     {
    //         return _str.size() < _sz;
    //     };
    auto _wrap_fn UNUSED = 
        std::function<bool (const std::string &, size_t)>(_str_sz_less_than);
    auto _str_con = 
        Alan::_Gen_Seq_Str_Con
        <std::vector<std::string >>
        (Alan::CONST::_digit, 1, 10);
    Alan::ConsoleBeautyOutput(*_str_con);
    PRINTLN_DETAIL(std::count_if(_str_con->begin(), _str_con->end(), 
                                Alan::Demos::_comp_str_sz(5))
                );
    PRINTLN_DETAIL(std::count_if(_str_con->begin(), _str_con->end(), 
                                std::bind2nd(std::ptr_fun(_str_sz_less_than), 5))
                );
    std::transform(_str_con->begin(), _str_con->end(), 
                    _str_con->begin(), 
                    std::bind2nd(std::plus<std::string >(), std::string("Alan")));
    Alan::ConsoleBeautyOutput(*_str_con);
}

