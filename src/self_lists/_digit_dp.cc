#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

#include <functional>

__DEF_NS__(Alan::SelfAlgo::Inst::DP::Digit)

using ll = long long;
using ull = unsigned long long;

int count_if(ll L, ll R, 
std::function<bool(int)> f1, 
std::function<bool(std::string)> f2,
int fn_index = 0)
{
    return 0;
}


class SolutionLC233 {
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
        //  3 * dp[3]           0:1, 1:10, 2:1,
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

void TestLC233()
{
    SolutionLC233 sl;
    PRINTLN(sl.countDigitOne(233));
    // 1 dp[2]
    // 0 dp[1]
    // 1 dp[1]
    // 2 dp[1]
}

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
                tot = (tot + dfs(N, k+1, sum+di, 0) % _mod);
        } else 
        {
            int bound = (!N) ? (n1[k]-'0') : (n2[k]-'0');
            for(int di=0; di <= bound; ++di)
               tot = (tot + dfs(N, k+1, sum+di, di == bound) % _mod);
        }

        return dp[N][k][sum][b] = (tot % _mod);
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
                dfs(1, 0, 0, 1) - dfs(0, 0, 0, 1);

    }
};

void TestLC2719()
{
    {
    Solution so;
    PRINTLN(so.count("4179205230", "7748704426", 8, 46));
    }

    {
    Solution so;
    PRINTLN(so.count("1", "12", 1, 8));
    }

    {
    Solution so;
    PRINTLN(so.count("1", "5", 1, 5));
    }

    // for(int i =-1; i <= 11;++i)
    //     PRINTLN( i<< ", "<< I32_IN_RANGE(i, 0, 10));

}

__END_NS__