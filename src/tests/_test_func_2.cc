#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_adv_.hpp"

#include "../../include/_test_func_.hpp"

void TestADV()
{
    PRINTLN_DETAIL(Alan::_t_plus(1, 2.5));
    using namespace std::literals;
    PRINTLN_DETAIL(Alan::_t_plus("to"s, "wa"s));
    PRINTLN_DETAIL(Alan::_t_plus(Alan::_Point_Loc<int >(1, 2, 3), 
                    Alan::_Point_Loc<int >(1, 2, 3)));
}