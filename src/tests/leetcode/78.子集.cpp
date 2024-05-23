/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        auto vvi = std::vector<std::vector<int>>();
        vvi.reserve(1<<n);
        for(int i =0; i < (1<<n); ++i){
            auto vi = std::vector<int>();
            for(int j = 0; j < n; ++j){
                if(i & (1<<j)){
                    vi.push_back(nums[j]);
                }
            }    
            vvi.push_back(std::move(vi));
        }
        return vvi;
    }
};
// @lc code=end

