#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_func_.hpp"


#include <vector>
#include <map>
#include <unordered_map>

#include <functional>
#include <cstdarg>

#if __CC_VER__ == 2
#include <vadefs.h>
#endif 

using namespace Alan;

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

template <size_t _Sz = (1<<2)>
bool _std_string_sz_less
(std::string const & _str)
noexcept
{
    return _str.size() < _Sz;
}

class _comp_str_sz 
{
public:
    explicit _comp_str_sz
    (const size_t __sz = (1<<2))
        : _sz(__sz) { }
    bool operator() 
    (const std::string & _str) 
    const noexcept 
    {
        return _str.size() < _sz;
    }
private:
    const size_t _sz;
};

typedef double (*_fn_d2d)(double); 

void _takein_fn(_fn_d2d _fn)
{
    PRINTLN_DETAIL(_fn(10));
}

/// @brief variable template parameter
/// @tparam _UnrayFunction 
/// @tparam ..._Args 
/// @param _fn 
/// @param ..._args 
template <typename _UnrayFunction, 
            typename... _Args>
void _Takein_Fn(_UnrayFunction _fn, _Args... _args)
{
    PRINTLN_DETAIL(_fn(_args...));
}


/// @brief variable parameter use ::va_list 
/// @param _sz 
/// @param  
void _sum_args_list(size_t _sz, ...)
{   
    ::va_list _val;
    double _tot = 0;
    va_start(_val, _sz);
    for(size_t _i = 0; _i < _sz; ++_i)
        _tot += va_arg(_val, double);
    va_end(_val);

    PRINTLN_DETAIL(_tot);
}

void TestTask3()
{   
    auto _str_v = 
        std::vector<std::string>
        {"vivid", "k", "mo", "f",
        "dur", "A", "miqqqq", "saq"};
    PRINTLN_DETAIL (std::count_if(
        _str_v.begin(), _str_v.end(),
        _std_string_sz_less<3>
    ));

    PRINTLN_DETAIL (std::count_if(
        _str_v.begin(), _str_v.end(),
        _std_string_sz_less
    ));

    // auto _cmp_sz_0 = 
    //     _comp_str_sz(3);
    PRINTLN_DETAIL (std::count_if(
        _str_v.begin(), _str_v.end(),
        // _cmp_sz_0
        _comp_str_sz(3)
    ));

    // auto _cmp_sz_1 = 
    //     _comp_str_sz();
    PRINTLN_DETAIL (std::count_if(
        _str_v.begin(), _str_v.end(),
        // _cmp_sz_1
        _comp_str_sz()
    ));

    auto _lambda_fn = 
        [](double const _par )
            ->double
        { return _par * 2.5; };
    _takein_fn(_lambda_fn);
    _Takein_Fn(_lambda_fn, 10);

    _sum_args_list(5, 2.5, 3.5, 4.5, 5.5, 7.8);

}