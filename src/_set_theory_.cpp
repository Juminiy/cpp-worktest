#include "_i_lib_.hpp"
#include "_set_theory_.hpp"

#include <vector>
#include <iostream>

#include <set>
#include <unordered_set>

#include <map>
#include <unordered_map>

USE_NAMESPACE_ALAN

void TestSSet()
{

    // why iterator constructor do not make any sense,
    // be sure to effect, but the private member _set_ disappear.
    auto _i32_s = SSet<int>(std::vector<int>{7, 77, 777, 7777, 77777});

    auto _i32_s2 = SSet<int> ();
    _i32_s2 += 100;

    _i32_s += 10;
    _i32_s += SSet<int>::container_type({1, 2, 3});
    _i32_s += _i32_s2;

    _COLOR_START(_COLOR_BLUE);
    PRINTLN_DETAIL(_i32_s);
    PRINTLN_DETAIL(_i32_s2);
    PRINTLN_DETAIL((_i32_s == _i32_s2));
    _COLOR_RECOVER;

    _i32_s2 = _i32_s;
    _COLOR_START(_COLOR_CYAN);
    PRINTLN_DETAIL(_i32_s);
    PRINTLN_DETAIL(_i32_s2);
    PRINTLN_DETAIL((_i32_s == _i32_s2));
    PRINTLN("After add _i32_s");
    _i32_s += 333;
    PRINTLN_DETAIL(_i32_s);
    PRINTLN_DETAIL(_i32_s2);
    PRINTLN_DETAIL((_i32_s == _i32_s2));


    PRINTLN_DETAIL(_i32_s.In(333));
    PRINTLN_DETAIL(_i32_s.In(555));
    _COLOR_RECOVER;

}

END_NAMESPACE_ALAN

