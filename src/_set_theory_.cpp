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
    
    auto _i32_s = SSet<int>(std::vector<int>{1,2,3,4,5,5,5,6,6,7});

    _COLOR_START(_COLOR_BLUE);
    std::cout << _i32_s << std::endl;
    _COLOR_RECOVER;

}

END_NAMESPACE_ALAN

