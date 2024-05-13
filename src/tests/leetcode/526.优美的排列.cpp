/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {
public:
    int countArrangement(int n) {
        auto f = std::vector<int>(1<<n);
        f[0] = 1;
        for(int i = 1; i < (1<<n); ++i){
            int num = __builtin_popcount(i);
            for(int j = 0; j < n; ++j){
                if(i & (1<<j) && 
                    (num % (j+1) == 0 ||  
                    (j+1) % num == 0))
                f[i] += f[i ^ (1<<j)];
            }
        }
        return f[(1<<n)-1];
    }
};
// @lc code=end

