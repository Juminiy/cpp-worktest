/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
std::string longestPalindrome(std::string s) {
    int n = s.size();
    int ansL = 0, ansR = 0;
    for(int i = 1; i < n; ++i)
    {
        // midOf
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r]){
            if(r-l > ansR-ansL){
                ansL = l, ansR = r;
            }
            l--,r++;
        }
        // sameOf
        l = i-1, r = i;
        while(l >= 0 && r < n && s[l] == s[r]){
            if(r-l > ansR-ansL){
                ansL = l, ansR = r;
            }
            l--,r++;
        }
    }
    return s.substr(ansL, ansR-ansL+1);
}
};
// @lc code=end

