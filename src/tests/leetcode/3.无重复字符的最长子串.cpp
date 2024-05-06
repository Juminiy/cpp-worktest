/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
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

};
// @lc code=end

