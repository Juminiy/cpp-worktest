/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution {
public:
    int atMostNGivenDigitSet
        (std::vector<std::string>& digits, int n) {
        
        int tot = 0;
        auto dp = std::vector<int>(10, 1);
        auto lf = std::vector<int>(10, 0);
        auto ef = std::vector<int>(10, 0);
        int ds = digits.size();
        
        for(int i=1;i<=10;++i)
        {   
            for(auto &sl : digits)
            {   
                int diOf = sl[0]-'0';
                if(diOf == i)
                    ef[i] = 1;
                else if (diOf < i)
                    lf[i] += 1;
                else 
                    break;
            }
        }

        // auto dn = std::vector<int>(10, 0);
        std::string strn = std::to_string(n);
        // 1000000000 

        int nszOf = strn.size();
        for(int i =1; i < nszOf; ++i)
        {
            dp[i] = dp[i-1] * ds;
            tot += dp[i];
        }

        for (int di = 0; di < nszOf; ++di)
        {   
            int diOf = strn[di] - '0';
            tot += lf[diOf] * dp[nszOf-di-1];
            if(ef[diOf] == 0)
            {
                break;
            } 
        }


        return tot;

    }

};
// @lc code=end

