/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
size_t __edit_distance_optv2
(const std::string & __dest, const std::string & __src)
{
    size_t dl = __dest.size(), sl = __src.size();
    size_t dp[dl+1][sl+1];
    for(size_t j = 0; j <= sl; ++j)
        dp[0][j] = j;
    for(size_t i = 0; i <= dl; ++i)
        dp[i][0] = i;
    for(size_t i = 1; i <= dl; ++i)
    {
    for(size_t j = 1; j <= sl; ++j)
    {
        auto __replace_of = (__dest[i-1] == __src[j-1]) ? 
                dp[i-1][j-1] : dp[i-1][j-1] + 1;
        dp[i][j] = std::min(
            __replace_of,
            std::min(
            dp[i-1][j] + 1, 
            dp[i][j-1] + 1
            )
        );
    }
    }
    
    return dp[dl][sl];
}
    int minDistance(string word1, string word2) {
        return static_cast<int>(__edit_distance_optv2(word1, word2));
    }
};
// @lc code=end

