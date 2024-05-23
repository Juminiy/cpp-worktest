/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, minS = 0x7fffffff, maxS = 0;
        for(int i=0;i<prices.size(); ++i)
        {
            maxP += (prices[i] > minS) ? 
                prices[i] - minS : 0;
            minS = prices[i];
        }
        return maxP;
    }
};
// @lc code=end

