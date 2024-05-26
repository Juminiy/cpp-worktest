#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_test_func_3.hpp"

#include <queue>
#include <string>
#include <stack>

__DEF_NS__(Alan::Demos::Test::Func)

void TestConsoleIOStackQueue()
{
    auto _q1 = std::queue<int>();
    for(int i = 0; i < 10; i++)
        _q1.push(i);
    Alan::ConsoleOutputQueue(_q1);

    auto _s1 = std::stack<int>();
    for(int i = 0; i < 10; i++)
        _s1.push(i);
    Alan::ConsoleOutputStack(_s1);
}

void TestBuiltinFns()
{
    PRINTLN_DETAIL(__i32_abs_(-1));
    PRINTLN_DETAIL(__i32_abs_(1));
    PRINTLN_DETAIL(__i32_abs_(0));

    typedef int (*fn_pi2_ri1) (int, int);
    fn_pi2_ri1 fn_max = __i32_max_;
    fn_pi2_ri1 fn_min = __i32_min_;
    auto fn_ss = __i32_same_sign_;

    PRINTLN_DETAIL(fn_max(1, 2));
    PRINTLN_DETAIL(fn_max(-1, -2));
    PRINTLN_DETAIL(fn_max(-1, 2));
    PRINTLN_DETAIL(fn_max(1, -2));
    PRINTLN_DETAIL(fn_max(0, -1));
    PRINTLN_DETAIL(fn_max(1, 0));
    PRINTLN_DETAIL(fn_max(0, 0));

    PRINTLN_DETAIL(fn_min(1, 2));
    PRINTLN_DETAIL(fn_min(-1, -2));
    PRINTLN_DETAIL(fn_min(-1, 2));
    PRINTLN_DETAIL(fn_min(1, -2));
    PRINTLN_DETAIL(fn_min(0, -1));
    PRINTLN_DETAIL(fn_min(1, 0));
    PRINTLN_DETAIL(fn_min(0, 0));

    PRINTLN_DETAIL(fn_ss(1, 2));
    PRINTLN_DETAIL(fn_ss(-1, -2));
    PRINTLN_DETAIL(fn_ss(-1, 2));
    PRINTLN_DETAIL(fn_ss(1, -2));
    // PRINTLN_DETAIL(fn_ss(0, -1));
    // PRINTLN_DETAIL(fn_ss(1, 0));
    // PRINTLN_DETAIL(fn_ss(0, 0));

    PRINTLN_DETAIL(__i32_mpow2_(3, 5));
    PRINTLN_DETAIL(__i32_dpow2_(155, 3));

    #if (__CC_VER__ >= 2)

    PRINTLN_DETAIL(__last_oloc(0X00001000, ));
    PRINTLN_DETAIL(__last_oloc(0X000E0000, ));
    PRINTLN_DETAIL(__last_oloc(0X00000000, ));

    PRINTLN_DETAIL(__pref_zcount(0X00001000, ));
    PRINTLN_DETAIL(__pref_zcount(0X000E0000, ));
    // PRINTLN_DETAIL(__pref_zcount(0X00000000, ));

    PRINTLN_DETAIL(__suff_zcount(0X00001000, ));
    PRINTLN_DETAIL(__suff_zcount(0X000E0000, ));
    // PRINTLN_DETAIL(__suff_zcount(0X00000000, ));

    PRINTLN_DETAIL(__pref_scount(0X00001000, ));
    PRINTLN_DETAIL(__pref_scount(0X000E0000, ));
    // PRINTLN_DETAIL(__pref_scount(0X00000000, ));

    PRINTLN_DETAIL(__ocount(0X00001000, ));
    PRINTLN_DETAIL(__ocount(0X000E0000, ));
    PRINTLN_DETAIL(__ocount(0X00000000, ));

    PRINTLN_DETAIL(__ocount_odd(0X00001000, ));
    PRINTLN_DETAIL(__ocount_odd(0X000E0000, ));
    PRINTLN_DETAIL(__ocount_odd(0X00000000, ));

    #endif

    _COLOR_START(_COLOR_BLUE);
        __hamming_perm(0b00110011, _t, PRINTLN_DETAIL(_t););
    _COLOR_END;

}

__END_NS__