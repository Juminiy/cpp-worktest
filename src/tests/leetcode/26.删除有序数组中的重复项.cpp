/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int __i32_abs_(int __i)
{
    return (__i ^ (__i >> 31)) - (__i >> 31);
}
    int removeDuplicates(std::vector<int>& nums) {
        int p = 0, q = 1;
        while(q < nums.size()){
            if(nums[p] != nums[q]){
                nums[p+1] = nums[q];
                p++;
            }
            q++;
        }
        return p+1;
    }
};
// @lc code=end

