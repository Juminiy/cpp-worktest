/*
 * @lc app=leetcode.cn id=2719 lang=cpp
 *
 * [2719] 统计整数数目
 */

// @lc code=start

class Solution {
public:
    int dp[2][23][401][2] = {};
    int minS, maxS;
    std::string n1; // N = 0
    std::string n2; // N = 1
    int _mod;
    
    #define U32 (unsigned int)
    #define I32_IN_RANGE(_x, _min, _max) \
            (U32(_x)-U32(_min) <= U32(_max)-U32(_min))

    int dfs(int N, int k, int sum, int b)
    {
        int LEN = ((!N) ? (n1.size()): (n2.size()));
        if(sum > maxS || sum + (LEN-k)*9 < minS)
            return 0;

        if(k == LEN)
            return 1;
 
        if (dp[N][k][sum][b])
            return dp[N][k][sum][b];

        int tot = 0;

        if(!b)
        {
            for(int di=0; di <= 9; ++di)
                tot = (tot + dfs(N, k+1, sum+di, 0)) % _mod;
        } else 
        {
            int bound = (!N) ? (n1[k]-'0') : (n2[k]-'0');
            for(int di=0; di <= bound; ++di)
               tot = (tot + dfs(N, k+1, sum+di, di == bound)) % _mod;
        }

        return dp[N][k][sum][b] = tot;
    }

    int count(std::string num1, std::string num2, int min_sum, int max_sum) 
    {
        this->n1 = std::move(num1);
        this->n2 = std::move(num2);
        minS = min_sum;
        maxS = max_sum;
        _mod = 1000000007;

        int sumn1 = 0;
        for(int i=0;i<n1.size();++i)
            sumn1 += n1[i]-'0';

        return I32_IN_RANGE(sumn1, minS, maxS) + 
                (dfs(1, 0, 0, 1) - dfs(0, 0, 0, 1) + _mod)%_mod;

    }
};

// @lc code=end

