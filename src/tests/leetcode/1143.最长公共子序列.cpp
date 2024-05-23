/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence
(std::string text1, std::string text2) {
    auto vvi = std::vector<std::vector<int>>
        (text1.size(), std::vector<int>(text2.size(), 0));
    for(size_t i = 0; i < vvi.size(); ++i)
    {
        for(size_t j = 0; j < vvi[i].size(); ++j)
        {
        if(text1[i] == text2[j]){
            vvi[i][j] = (i && j) ? vvi[i-1][j-1] + 1 : 1;
        } else{
            vvi[i][j] = std::max(
                i ? vvi[i-1][j] : 0, 
                j ? vvi[i][j-1] : 0
            );
        } 

        }
    }
    return vvi[text1.size()-1][text2.size()-1];
}
};
// @lc code=end

