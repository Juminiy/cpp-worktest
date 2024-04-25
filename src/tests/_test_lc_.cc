#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_.hpp"

#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>
#include <utility>

__USE__(std::vector);
__USE__(std::deque);
__USE_NS__(std);

__DEF_NS__(Alan::Demos::Test::LeetCode)

typedef void (*TestFuncDeclType) ();
using _vi32_type = std::vector<int>;

// 0 -> 1
// 1 -> A(10,1) = 10 -> 10
// 2 -> 10 * 9 - 9 = 81 -> 91
// 3 -> 10 * 9 * 8 - 9 * 8 = 648 -> 739
int countNumbersWithUniqueDigits(int n) {
    long long dp[10] = {1, 10, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int _i = 2; _i <= n; ++ _i)
    {
        dp[_i] = 9;
        for(int _t = 9; _t > (9-_i+1); --_t)
            dp[_i] *= _t;
        dp[_i] += dp[_i-1];
    }
    return dp[n];
}

void TestLC357Local()
{
    for(int i = 0; i <= 8; i++)
        PRINTLN( "fn(" << i << ") = " << countNumbersWithUniqueDigits(i));
}

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

void TestLC322Local()
{   
    vector<int> v1{1,2,5};
    PRINTLN_DETAIL(coinChange(v1, 11));
    vector<int> v2{2};
    PRINTLN_DETAIL(coinChange(v2, 3));
    vector<int> v3{1};
    PRINTLN_DETAIL(coinChange(v3, 0));
}

int lengthOfLIS(vector<int>& nums) {
    // O(N*N)
    // auto _dp = std::vector<int>(nums.size(), 1);
    // for (size_t _em = 0; _em < nums.size(); ++ _em)
    // {
    //     for (size_t _eem = 0; _eem < _em; ++ _eem)
    //     {
    //         _dp[_em] = nums[_em] > nums[_eem] ? 
    //             std::max(_dp[_em], _dp[_eem]+1) :
    //             _dp[_em];
    //     }
    // }
    // return _dp.back();

    
    auto _lstk = std::vector<int>();
    for(size_t _em = 0; _em < nums.size(); ++ _em)
    {   
        // case _lstk empty
        if (_lstk.empty() || nums[_em] > _lstk.back())
        {    
            _lstk.push_back(nums[_em]);
            continue;
        } else if ( nums[_em] == _lstk.back())
        {
            continue;
        }
        auto _liter = 
            std::lower_bound(_lstk.begin(), _lstk.end(), nums[_em]);
        *_liter = nums[_em];
    }
    
    return _lstk.size();
    
}

void TestLC300Local()
{
    using v32_type = std::vector<int>;
    auto v1 = v32_type{10,9,2,5,3,7,101,18};
    PRINTLN_DETAIL(lengthOfLIS(v1));
    auto v2 = v32_type{0,1,0,3,2,3};
    PRINTLN_DETAIL(lengthOfLIS(v2));
    auto v3 = v32_type{7,7,7,7,7,7,7};
    PRINTLN_DETAIL(lengthOfLIS(v3));
    auto v4 = v32_type{4,10,4,3,8,9}; 
    // 4 10
    PRINTLN_DETAIL(lengthOfLIS(v4));
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    auto _comp_less = 
        [] (const vector<int> & _e1, const vector<int> & _e2)
            -> bool 
        {   
            if(_e1[0] == _e2[0])
                return _e1[1] > _e2[1];
            return _e1[0] < _e2[0];
        };
    auto _ev_less = 
        [] (const vector<int> & _e1, const vector<int> & _e2)
            -> bool 
        {   
            return _e1[1] < _e2[1];
        };
    auto _sstk_m_fn = 
        [&envelopes, &_ev_less] (auto && _comp_fn) -> int 
    {
    std::sort(envelopes.begin(), envelopes.end(), std::forward<decltype(_comp_fn)>(_comp_fn));
    #ifdef DEBUG_MODE
        Alan::ConsoleBeautyOutputEmbedded2(envelopes);
    #endif
    auto _lstk = std::vector<std::vector<int > >();
    for(size_t _i = 0; _i < envelopes.size(); ++ _i)
    {   
        if (_lstk.empty() || _ev_less(_lstk.back(), envelopes[_i]))
        {    
            _lstk.push_back(envelopes[_i]);
            continue;
        }
        auto _liter = 
            std::lower_bound(_lstk.begin(), _lstk.end(), envelopes[_i], _ev_less);
        *_liter = envelopes[_i];
        #ifdef DEBUG_MODE
            Alan::ConsoleBeautyOutputEmbedded2(_lstk); 
        #endif
    }

    return _lstk.size();
    };
    
    return _sstk_m_fn(_comp_less);
}


void TestLC354Local()
{
    // [[5,4],[6,4],[6,7],[2,3]]
    auto v1 = std::vector<_vi32_type>{{5,4}, {6,4}, {6,7}, {2,3}};
    PRINTLN(maxEnvelopes(v1));
    // {2,3}, {5,4}, {6,4}, {6,7}

    // [[1,1],[1,1],[1,1]]
    auto v2 = std::vector<_vi32_type>{{1,1}, {1,1}, {1,1}};
    PRINTLN(maxEnvelopes(v2));
    
    // [[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
    auto v3 = std::vector<_vi32_type>{
        {2,100}, {3,200}, {4,300}, 
        {5, 500}, {5, 400}, {5,250}, 
        {6,370}, {6,360}, {7,380}};
    PRINTLN(maxEnvelopes(v3));

    // [[46,89],[50,53],[52,68],[72,45],[77,81]]
    auto v4 = std::vector<_vi32_type>{
        {46,89}, {50,53}, {52,68}, 
        {72,45}, {77,81}};
    PRINTLN(maxEnvelopes(v4));
}

int minDistance(std::string w1, std::string w2) {
    
    return -1;
}

void TestLC72Local()
{
    // 输入：word1 = "horse", word2 = "ros"
    // 输出：3
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')

    // 输入：word1 = "intention", word2 = "execution"
    // 输出：5
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')
}

// 2 1 3 
// 7 6 5
// 13 13 14
int minFallingPathSum(vector<vector<int>>& matrix) {
    size_t _szn = matrix.size(), _szm = matrix[0].size();
    int val = 0x7fffffff;
    for(size_t _i = 0; _i < _szn; ++_i)
    {
        for(size_t _j = 0; _j < _szm; ++_j)
        {   
            if (_i)
            {
                auto _n0 = _j > 0 ? matrix[_i-1][_j-1] : int(0x7fffffff);
                auto _n1 = matrix[_i-1][_j];
                auto _n2 = _j < _szm-1 ? matrix[_i-1][_j+1] : int(0x7fffffff);
                matrix[_i][_j] += std::min({_n0, _n1, _n2});
            }
            
            if(_i == _szn - 1)
                val = std::min(val, matrix[_i][_j]);
        }
    }
    return val;
}

void TestLC931Local()
{   
    using vv_type = vector<vector<int>>;
    auto v1 = vv_type{{2,1,3},{6,5,4},{7,8,9}};
    //[[2,1,3],[6,5,4],[7,8,9]]
    PRINTLN_DETAIL(minFallingPathSum(v1));
    auto v2 = vv_type{{-19,57},{-40,-5}};
    // [[-19,57],[-40,-5]
    PRINTLN_DETAIL(minFallingPathSum(v2));

    // [48]
    auto v3 = vv_type{{48}};
    PRINTLN_DETAIL(minFallingPathSum(v3));
}

/*
  b a b g b a g
b 0 0 0 0 0 0 0
a 
b
g
b
a
g
*/
int numDistinct(string s, string t) {


    
    // rbacccrbac
    // rbac
// 1.  rbac
// 2.  rba c
// 3.  rba  c
// 4.  rba      c
// 5.  rb      ac
// 6.  r      bac
// 7.        rbac

    // rabbbit
    // rabbit
    // rabb it
    // rab bit
    // ra bbit

    // babgbag 
    // bag
    // 
    // ba g
    // ba    g
    // b    ag
    //   b  ag
    //     bag
    // i in (0,n) -> dp[:i]<presub[t]> * dp[i:]<postsub[t]>
    // idea1 以t的下标i分界, t[:i]在s的j之前有几个 * t[i:]在s的j之后有几个 会重复
    // idea2 以t的下标i分界, t[:i]固定, 找t[i:]在s的个数, g未出现过 ag肯定不出现 
    
    // rabcuuvxzssuruxx
    // rus
    // r   u    s
    // r   u     s
    // r    u   s
    // r    u    s
    // r          u   0
    // r            u 0
    //             ru 0
    // 从实际的用例 构造出抽象的形式
    // 1. 状态转移
    // 2. 边界
    // 3. 结果集

    size_t _szs = s.size(), _szt = t.size();
    if(_szt > _szs)
        return 0;
    // subq[i][j][0] // t[:i] -> 
    // subq[i][j][1] // t[i:] -> 
    using u64_t = unsigned long long;
    u64_t subq[_szt+1][_szs+1][2];
    u64_t tot = 0;
    auto _mod = static_cast<u64_t>(1e9+7);
    for(size_t _i = 0; _i < _szt; ++ _i)
    {
        for(size_t _j = 0; _j < _szs; ++ _j)
        {
            if(s[_j] == t[_j]){
                subq[_i][_j][0] = subq[_i][_j][0];
                subq[_i][_j][1] = subq[_i][_j][1];
            }
            tot += (subq[_i][_j][0] * (subq[_i][_szt-1][1] - subq[_i][_j][1])) % _mod;
        }
    }
    return tot;
}

void TestUBus()
{
    auto _fn_v = deque<TestFuncDeclType>();
    // _fn_v.push_back(TestLC357Local);
    // _fn_v.push_back(TestLC322Local);
    // _fn_v.push_back(TestLC300Local);
    // _fn_v.push_back(TestLC354Local);
    // _fn_v.push_back(TestLC72Local);
    _fn_v.push_back(TestLC931Local);
    // async run
    __LOOP_GLB__(!_fn_v.empty())
    {
        _fn_v.front()();
        _fn_v.pop_front();
    }
}

__END_NS__