#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_.hpp"

#include <iostream>
#include <iomanip>

// __USE_NS__(Alan::Demos::Func);

void Alan::Demos::Test::Func::TestBitCastZeroExt2SignExt()
{
    // sign ext
    auto i8_v0 = (int8_t)0xff;
    auto u64_v0 = static_cast<uint64_t>(i8_v0);
    PRINTLN("static_cast");
    PRINTLN_DETAIL(std::showbase << std::hex << i8_v0);
    PRINTLN_DETAIL(std::showbase << std::hex << u64_v0);

    auto i8_ptr_v0 = &i8_v0;
    auto u64_ptr_v0 = reinterpret_cast<uint64_t*>(i8_ptr_v0);
    PRINTLN_DETAIL(std::showbase << std::hex << *i8_ptr_v0);
    PRINTLN_DETAIL(std::showbase << std::hex << *u64_ptr_v0);
}