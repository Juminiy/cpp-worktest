/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
    auto numSet = std::unordered_map<int, size_t>();

    for(size_t i = 0; i < nums.size(); ++i)
        numSet.insert(std::make_pair(nums[i], i));

    for(size_t i = 0; i < nums.size(); ++i)
    {
        if(numSet.find(target-nums[i]) != numSet.end())
        {
            auto j = numSet[target-nums[i]];
            if ( i != j )
            return {static_cast<int>(i), static_cast<int>(j)}; 
        }
    }

    return {-1, -1};
}
};
// @lc code=end

