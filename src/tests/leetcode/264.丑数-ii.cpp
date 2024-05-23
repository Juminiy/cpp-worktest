/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        // 1 2 3 5 
        // 
        auto vi = std::vector<int>(n+1, 0);
        vi[1] = 1;
        int of1 = 1, of2 = 1, of3=1;
        for(int i = 2; i <=n; ++i){
            auto val1 = vi[of1]*2;
            auto val2 = vi[of2]*3;
            auto val3 = vi[of3]*5;
            vi[i] = std::min({val1,val2,val3});
            if(vi[i]==val1) of1++;
            if(vi[i]==val2) of2++;
            if(vi[i]==val3) of3++;
        }

        return vi[n];
    }
};
// @lc code=end

