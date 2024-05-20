/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

// @lc code=start
class Solution {
public:
    int tot ;
    std::string numOf;

    int dfs(int i)
    {   
        int di = numOf[i] - '0';
        if (i == numOf.size()-1)
        {
            return numsOf[i] == 1;
        } else if(i == 0)
        {
            return (di+1) * dfs(i+1);
        } else 
        {
            int xOf = dfs(i+1);
            return di == 0 ? xOf : (di+2)*xOf;
        }
    }

    int countDigitOne(int n) {
        auto dp = std::vector<int>(10, 0);
        dp[1] = 1;

        auto strn = std::to_string(n);
        int szn = strn.size();
        tot = 1;
        for(int i=2;i<szn;++i)
        {
            dp[i] = dp[i-1] * 9 + 10;
            tot += dp[i];
        }

        numOf = std::move(strn);
        dfs(0);
        // auto dpt = std::vector<int>(10, 0);
        // for(int i=1;i<szn;++i)
        // {
        //     dpt[i] = dpt[i-1]+dp[i];
        // }

        // for(int i=0; i < szn; ++i)
        // {
        //     int di = strn[i]-'0';
        //     int dOf = dp[szn-1-i];
        //     if (i == 0)
        //     {
        //         tot += di*dOf;
        //     } else 
        //     {
        //     if(di > 0)
        //         tot += (di+1)*dOf;
        //     else 
        //         tot += dOf;
        //     }
    
        // }

        return n >= 1 ? tot : 0;
    }
};
// @lc code=end

