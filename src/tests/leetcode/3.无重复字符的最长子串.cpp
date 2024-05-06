/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
int lengthOfLongestSubstring_v2(std::string s) {
    auto charEx = std::unordered_set<char>();
    size_t segl = 0, segr = 0, maxl = 0;
    size_t szs = s.size();
    while(segl < szs)
    {
        while(segr < szs && !charEx.count(s[segr]))
        {
            charEx.insert(s[segr]);
            ++segr;
        }
        maxl = std::max(maxl, segr-segl);
        segl = segr, segr++;
    }

    return static_cast<int>(maxl);
}

int lengthOfLongestSubstring(std::string s) {
    return lengthOfLongestSubstring_v2(s);
}

};
// @lc code=end

