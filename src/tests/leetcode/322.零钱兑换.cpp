/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    auto _dp = vector<int>(amount+1, 0);
    for(int _ta = 1; _ta <= amount; ++_ta)
    {
        _dp[_ta] = 0x7ffff;
        for(auto _v : coins)
        {
            if(_v > _ta)
                continue;
            _dp[_ta] = std::min(_dp[_ta], _dp[_ta - _v]+1);
        }
    }
    return amount ? 
            (_dp[amount] == 0x7ffff ? 
                -1 : _dp[amount]) 
            : 0;
}
};
// @lc code=end

