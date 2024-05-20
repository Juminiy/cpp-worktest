/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, minOf = 0x7fffffff;
        for(int i =0;i<prices.size();++i)
        {
            minOf = std::min(prices[i], minOf);
            maxP = std::max(prices[i]-minOf, maxP);
        }
        return maxP;
    }
};
// @lc code=end

