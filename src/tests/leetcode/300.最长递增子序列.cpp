/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto _lstk = std::vector<int>();
    for(size_t _em = 0; _em < nums.size(); ++ _em)
    {   
        // case _lstk empty
        if (_lstk.empty() || nums[_em] > _lstk.back())
        {    
            _lstk.push_back(nums[_em]);
            continue;
        } else if ( nums[_em] == _lstk.back())
        {
            continue;
        }
        auto _liter = 
            std::lower_bound(_lstk.begin(), _lstk.end(), nums[_em]);
        *_liter = nums[_em];
    }
    
    return _lstk.size();
    }
};
// @lc code=end

