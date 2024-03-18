#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_func_.hpp"



#include <functional>

#include <vector>

#include <map>
#include <unordered_map>

USE_NAMESPACE_ALAN

typedef int (*subFunc) (const int &, const int &);

int subFuncImpl (const int & _lhs, 
                    const int & _rhs)
{
    return _lhs - _rhs;
}

void TestFunc()
{
    auto cals = std::unordered_map
                    <std::string, calBinOpt >();
    
    cals.insert(calBinPair("add", 
                [](const int &_lhs, const int &_rhs)-> int 
                {
                    return _lhs + _rhs;
                }));
    cals["sub"] = subFuncImpl;
    subFunc subFuncV2 = 
    [](const int & _lhs, const int & _rhs) -> int {
        return _lhs - _rhs;    
    };
    cals["sub_v2"] = subFuncV2;

    if (AssoFind(cals, "add"))
        PRINTLN_DETAIL(std::to_string(cals["add"](10, 20)));
    if (AssoFind(cals, "sub"))
        PRINTLN_DETAIL(std::to_string(cals["sub"](-99, -999)));
    if (AssoFind(cals, "sub_v2"))
        PRINTLN_DETAIL(std::to_string(cals["sub_v2"](33, 77)));
    if (AssoFind(cals, "none"))
        PRINTLN_DETAIL(std::to_string(cals["none"](10, 20)));

}

void TestTask2()
{   
    // typedef std::vector<int > i32_v;
    typedef std::vector<int>::iterator i32_v_it;
    typedef std::vector<int>::value_type i32_v_v;
    auto _count_eq_ele 
        = [](i32_v_it _begin, i32_v_it _end, const i32_v_v _ele ) -> i32_v_v
        {
            return std::count_if(_begin, _end, [_ele](const i32_v_v _e) -> bool
                                                        { return _ele == _e;  } );
        };
    auto i32_vi = std::vector< int >{1, 2, 3, 4, 5, 5, 5, 6, 7};
    PRINTLN(std::to_string(_count_eq_ele(i32_vi.begin(), i32_vi.end(), 5)));
}

END_NAMESPACE_ALAN