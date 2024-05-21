/*
 * @lc app=leetcode.cn id=2719 lang=cpp
 *
 * [2719] 统计整数数目
 */

// @lc code=start
class Solution {
public:
    #define U32 (unsigned int)
    #define I32_IN_RANGE(_x, _min, _max) \
        (U32(_x)-U32(_min) <= U32(_max)-U32(_min))


    int dp[23][401][2];
    std::string num1, num2;
    int minS, maxS;
    
    int rec()
    {
        long long tot1 = dfs(1, num1[0]-'0', 1);
        for(int di0 = num1[0]-'0'-1; di0 >= 0; --di0)
        {
            tot1 += dfs(1, di0, 0);
        }
        int tot = 0;
        for(int sum = minS; sum <= maxS; ++sum)
            tot += (dp[num1.size()][sum][0] + dp[num1.size()][sum][1]);
        
        return tot;
    }

    int dfs(int k, int sum, int b)
    {
        if(dp[k][sum][b])
            return dp[k][sum][b];
        if(k == num1.size())
        {
            return I32_IN_RANGE(sum, minS, maxS);
        }

        if(b == 0)
        {
            for(int di = 0; di <= 9; ++di)
                dp[k][sum][0] += dfs(k+1, sum+di, 0);
        } else 
        {
            for(int di = num1[k]-'0'; di >= 0; --di)
                dp[k][sum][1] += dfs(k+1, sum+di, 1);
        }
        
        return dp[k][sum][b];
    }


    int stat()
    {
        
    }

    int count(string num1, string num2, int min_sum, int max_sum) 
    {
        minS = min_sum, maxS = max_sum;
        this->num1 = std::move(num1);
        this->num2 = std::move(num2);

    }
};
// @lc code=end

