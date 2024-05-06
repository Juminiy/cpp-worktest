/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
size_t __edit_distance_
(const std::string & __dest, const std::string & __src)
{
    using _sz_vec = std::vector<size_t>;
    auto __dl = __dest.size(), __sl = __src.size();
    auto __dis_ = 
        std::vector<_sz_vec>(__dl+1, _sz_vec(__sl+1, 0));
    for(size_t i = 0; i <= __dl; ++i)
    {
        for(size_t j = 0; j <= __sl; ++j)
        {
        if(i == 0 && j == 0) 
            __dis_[i][j] = 0;
        else if (i == 0 && j != 0)
            __dis_[i][j] = __dis_[i][j-1] + 1;
        else if (i != 0 && j == 0)
            __dis_[i][j] = __dis_[i-1][j] + 1;
        else
        {
            auto __replace_of = (__dest[i-1] == __src[j-1]) ? 
                __dis_[i-1][j-1] : __dis_[i-1][j-1] + 1;
            __dis_[i][j] = std::min({
                __dis_[i-1][j] + 1, 
                __dis_[i][j-1] + 1, 
                __replace_of
            });
        }
        }
    }
    return __dis_[__dl][__sl];
}
    int minDistance(string word1, string word2) {
        return static_cast<int>(__edit_distance_( word2, word1));
    }
};
// @lc code=end

