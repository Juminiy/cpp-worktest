#include "_i_lib_.hpp"
#include "_asso_container_.hpp"


#include <string>
#include <iostream>

#include <functional>
#include <algorithm>
#include <iterator>

#include <queue>
#include <vector>

#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

namespace Alan {
typedef std::pair<int, std::string> i32_str;

void TestUMap()
{   
    std::priority_queue<int, std::vector<int>, std::greater<int>> bh;
    bh.push(1);
    // cout << bh.size() << endl;
    std::unordered_map<int, std::string > umis ;
    umis.insert(i32_str(1, "w"));
    std::map<int, std::string> mis;
    mis.insert(i32_str(1, "s"));
    std::multimap<int, std::string> mm;
    mm.insert(i32_str(1, "ss"));
    mm.insert(i32_str(1, "bb"));
    mm.insert(i32_str(1, "ss"));
    mm.insert(i32_str(1, "kk"));
    for(auto &_e_ UNUSED : mm)
        ;
        // std::cout << "[" << _e_.first << ", " << _e_.second << "]" << std::endl;

    std::set<int> i32S;
    i32S.insert(1);
    std::copy(i32S.begin(), 
                i32S.end(), 
                std::ostream_iterator<int>(std::cout, "\n"));

}
};
