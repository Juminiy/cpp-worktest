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



void TestUBus()
{
    auto _fn_v = deque<TestFuncDeclType>();
    // _fn_v.push_back(TestLC357Local);
    // _fn_v.push_back(TestLC322Local);
    // _fn_v.push_back(TestLC300Local);
    _fn_v.push_back(TestLC354Local);
    // async run
    __LOOP_GLB__(!_fn_v.empty())
    {
        _fn_v.front()();
        _fn_v.pop_front();
    }
}

__END_NS__