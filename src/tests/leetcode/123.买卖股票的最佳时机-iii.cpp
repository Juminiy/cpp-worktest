/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max1 = 0, minS = 0x7fffffff;
        auto pi = std::priority_queue<int>();
        int preOf = 0x7fffffff, max2 = 0, preMin = 0x7fffffff; 
        for(int i =0;i<prices.size(); ++i)
        {
            minS = std::min(minS, prices[i]);
            max1 = std::max(max1, prices[i]-minS);
            if(prices[i] >= preOf)
            {
                
            } else 
            {
                int putOf = preOf - preMin;
                if(putOf > 0)
                    pi.push(putOf);
                preMin = 0x7fffffff;
            }
            preOf = prices[i];
            preMin = std::min(preMin, prices[i]);
        }
        if(preOf > preMin) {
            pi.push(preOf - preMin);
        }

        if(pi.size() >= 1){
            max2 += pi.top(); pi.pop();
        }
        if(pi.size() >= 1){
            max2 += pi.top();
        }
        return std::max(max2, max1);
    }
};
// @lc code=end

