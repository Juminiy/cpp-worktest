#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_4.hpp"

#include <bitset>

__DEF_NS__(Alan::Demos::Test::Func)

void TestBitMani()
{
    [[maybe_unused]] std::bitset<32> _bs;
    PRINTLN_DETAIL(_bs);
    PRINTLN_DETAIL(sizeof(_bs));
}

__END_NS__