/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    // 1 3 5 7 
    // 2 4 6 8 10

    // 1 2 3 4 9 10 
    // 5 6 7 8

    // 3 2 -> all[2] 
    // 3 3 -> static_cast<double>(all[2]+all[3])/2;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t sz1=nums1.size(), sz2=nums2.size();
        
    }   
};
// @lc code=end

