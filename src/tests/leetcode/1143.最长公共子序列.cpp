/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
int lcsmemdfs(
    const std::string & s, const std::string & t, 
std::vector<std::vector<int> > & _mem)
{
    size_t szs = s.size(), szt = t.size();
    if (szs == 0 || szt == 0)
    {
        return 0;
    } else if (_mem[szs-1][szt-1])
    {
        return _mem[szs-1][szt-1];
    }

    if(s[szs-1] == t[szt-1])
    {
        return _mem[szs-1][szt-1] =  
            lcsmemdfs(s.substr(0, szs-1), t.substr(0, szt-1), _mem) + 1;
    } else 
    {
        auto t0 = lcsmemdfs(s.substr(0, szs-1), t.substr(0, szt), _mem);
        auto t1 = lcsmemdfs(s.substr(0, szs), t.substr(0, szt-1), _mem);
        if (szs >= 1)
            _mem[szs-1][szt] = t0;
        if (szt >= 1)
            _mem[szs][szt-1] = t1;
        return std::max(t0, t1);
    }

}

int longestCommonSubsequence(std::string text1, std::string text2) {
    // return lcsdfs(text1, text2);
    auto vvi = std::vector<std::vector<int>>
        (text1.size(), std::vector<int>(text2.size(), 0));
    return lcsmemdfs(text1, text2, vvi);
}
};
// @lc code=end

