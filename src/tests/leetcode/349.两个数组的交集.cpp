/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    using vi = std::vector<int>;
    using bs = std::bitset<1001>;
    vi intersection(vi& nums1, vi& nums2) {
        auto viOf = vi();
        auto biOf = bs();
        auto miOf = bs();
        size_t sz1 = nums1.size(), sz2 = nums2.size();
        size_t i1 = 0, i2 = 0;
        // while(i1 < sz1 && i2 < sz2)
        //     biOf[nums1[i1++]] = 1,
        //     biOf[nums2[i2++]] = 1;
        while(i1 < sz1)
            biOf[nums1[i1++]] = 1;
        while(i2 < sz2)
        {
            if(biOf[nums2[i2]] && !miOf[nums2[i2]])
                miOf[nums2[i2]] = 1,
                viOf.push_back(nums2[i2]);
            i2++;
        }
            

        
        // for(int i = 0; i < 1001; ++i)
        //     if(biOf[i])
        //         viOf.push_back(i);
            
        return viOf;
    }
};
// @lc code=end

