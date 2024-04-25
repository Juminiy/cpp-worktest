/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
    size_t _szn = matrix.size(), _szm = matrix[0].size();
    int val = 0x7fffffff;
    for(size_t _i = 0; _i < _szn; ++_i)
    {
        for(size_t _j = 0; _j < _szm; ++_j)
        {   
            if (_i)
            {
                auto _n0 = _j > 0 ? matrix[_i-1][_j-1] : int(0x7fffffff);
                auto _n1 = matrix[_i-1][_j];
                auto _n2 = _j < _szm-1 ? matrix[_i-1][_j+1] : int(0x7fffffff);
                matrix[_i][_j] += std::min({_n0, _n1, _n2});
            }
            
            if(_i == _szn - 1)
                val = std::min(val, matrix[_i][_j]);
        }
    }
    return val;
}
};
// @lc code=end

