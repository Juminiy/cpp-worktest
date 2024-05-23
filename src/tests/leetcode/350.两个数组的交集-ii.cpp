/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    using vi = std::vector<int>;
    using bs = std::bitset<1001>;
    using mii = std::map<int, int>;

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        auto viOf = vi();
        auto mi1Of = mii();
        auto mi2Of = mii();
        // size_t sz1 = nums1.size(), sz2 = nums2.size();
        // size_t i1 = 0, i2 = 0;
        for(auto el : nums1)
            mi1Of[el]++;
        for(auto el : nums2)
            mi2Of[el]++;
        for(auto pr : mi1Of)
        {
            auto el = pr.first;
            auto miTM = std::min(mi1Of[el], mi2Of[el]);
            while(miTM--)
                viOf.push_back(el);
        }
            
        return viOf;
    }
};
// @lc code=end

