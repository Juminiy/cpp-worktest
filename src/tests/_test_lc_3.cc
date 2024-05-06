#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_3.hpp"

#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

__DEF_NS__(Alan::Inst::LC)

int lengthOfLongestSubstring(std::string s) {
    auto loc = std::unordered_map<char, size_t>();
    size_t curl = 0, maxl = 0;
    auto pop_index = 
        [&loc](size_t index) 
        {
            for(auto it = loc.begin(); it != loc.end(); )
            {
            if(it->second <= index)
                it = loc.erase(it);
            else 
                ++it;
            } 
        };
    for(size_t i = 0; i < s.size(); ++ i )
    {
        if(loc.find(s[i]) != loc.end())
        {
            pop_index(loc[s[i]]);
        } 
        loc[s[i]] = i;
        maxl = std::max(maxl, loc.size());
    }

    return maxl;
}

void TestLC3()
{
    PRINTLN(lengthOfLongestSubstring("abcabcbb"));  // 3
    PRINTLN(lengthOfLongestSubstring("bbbbb"));     // 1
    PRINTLN(lengthOfLongestSubstring("pwwkew"));    // 3
}

void TestRunLC()
{
    TestLC3();
}
__END_NS__