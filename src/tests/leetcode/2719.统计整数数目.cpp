/*
 * @lc app=leetcode.cn id=2719 lang=cpp
 *
 * [2719] 统计整数数目
 */

// @lc code=start
class Solution {
public:
    #define in_range(x, a, b) (a<=x && x<=b)
    std::string n1, n2;
    int mins, maxs;
    int mod;
    int dp[2][23][401][2] = {};

    int dfs(int N, int k, int num, int b)
    {   
        int LEN = (!N) ? (n1.size()) : (n2.size());

        if(num > maxs || num + (LEN-k)*9 < mins)
            return 0;
        
        if(k == LEN)
            return 1;
        
        if(dp[N][k][num][b])
            return dp[N][k][num][b];
        
        int tot = 0;

        if(!b){
            for(int di = 0; di <= 9; ++di)
                tot = (tot + dfs(N, k+1, num+di, 0))%mod;
        } else{
            int bound = (!N) ? (n1[k]-'0') : (n2[k]-'0');
            for(int di = 0; di <= bound; ++di)
                tot = (tot + dfs(N, k+1, num+di, di == bound))%mod;
        }

        return dp[N][k][num][b] = tot;
    }

    int count(string num1, string num2, int min_sum, int max_sum) 
    {
        this->n1 = std::move(num1);
        this->n2 = std::move(num2);
        this->mins = min_sum;
        this->maxs = max_sum;
        this->mod = static_cast<int>(1e9+7);

        int tot1 = 0;
        for(int i =0;i<n1.size();++i)
            tot1 += (n1[i]-'0');

        return (dfs(1, 0, 0, 1) - dfs(0, 0, 0, 1) + mod)%mod + in_range(tot1, mins, maxs);
    }
};
// @lc code=end

