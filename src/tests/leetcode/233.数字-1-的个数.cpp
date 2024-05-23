/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    using ll = long long;
    ll pow10[15] = {};
    ll dp[15] = {};
    std::string dn;

    int countDigitOne(int n) {
        dn = std::to_string(n);
        pow10[0] = 1;
        int tot = 0;
        for(int i =1; i <= dn.size(); ++i)
            pow10[i] = pow10[i-1] * 10ll,       // 10 100 1000  
            dp[i] = dp[i-1] * 10ll + pow10[i-1];  // 1 20  300

        for(int i = 0; i < dn.size(); ++i)
            tot += dp[i];                       // 1 21 321
        
        // 12345
        // 1

        // 54321                
        // 4 * dp[4]            0,1,2,3
        //  3 * dp[3]           
        //   2 * dp[2]          
        //     
        for(int i = 0; i < dn.size(); ++i)
        {
            tot += (dn[i]-'0'+9) * dp[dn.size()-i-1];
            tot += (!i) ? 0 : dp[dn.size()-i-1];
        }

        return tot + (dn[dn.size()-1] != '0');
    }
};
// @lc code=end

