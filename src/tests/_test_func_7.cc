#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_4.hpp"

#include <bitset>
#include <algorithm>
#include <limits.h>
#include <string>

__DEF_NS__(Alan::Demos::Test::Func)

void TestBitMani()
{
    [[maybe_unused]] std::bitset<32> _bs;
    PRINTLN_DETAIL(_bs);
    PRINTLN_DETAIL(sizeof(_bs));
}

__END_NS__

__DEF_NS__(Alan::Inst::LC::Race::LC358)

// p1

void TestProblem1()
{
    PRINTLN("LC358 P1:");
}

// p2

std::vector<bool> isArraySpecial
(std::vector<int>& nums, std::vector<std::vector<int>>& queries) 
{
    int n = nums.size();
    auto bi = std::vector<int>(n, 0);
    for(int i=1;i<n;++i)
    {
        if(nums[i-1]%2 != nums[i]%2)
        {
            bi[i] = bi[i-1] + 1;
        }
    }        

    // Alan::ConsoleBeautyOutput(bi);

    auto resB = std::vector<bool>(queries.size(), false);

    for(int i=0;i<queries.size();++i)
    {
        int zeroOf = queries[i][1] - queries[i][0];
        resB[i] = (zeroOf == 0) ? 1 :
            (bi[queries[i][1]] - bi[queries[i][0]] == 
                zeroOf);
        
    }

    return resB;
}

void TestProblem2()
{
    PRINTLN("LC358 P2:");
    {
        auto nums = std::vector<int>{3,4,1,2,6};
        auto queries = std::vector<std::vector<int>>{{0,4}};
        Alan::ConsoleBeautyOutput(isArraySpecial(nums,queries));
    }

    {
        auto nums = std::vector<int>{4,3,1,6};
        auto queries = std::vector<std::vector<int>>{{0,2},{2,3}};
        Alan::ConsoleBeautyOutput(isArraySpecial(nums,queries));
    }

    {
        auto nums = std::vector<int>{2,7,2};
        auto queries = std::vector<std::vector<int>>{{0,0},{1,2}};
        Alan::ConsoleBeautyOutput(isArraySpecial(nums,queries));
    }
}

// p3

long long sumDigitDifferences(std::vector<int>& nums) {
    long long res = 0;
    int n = nums.size();
    
    auto fnC = [](long long x) -> long long {
        return (x%2) ? (((x-1)>>1)*(x)) : ((x>>1)*(x-1));
    };
    
    long long nOf = fnC(n);

    int disz = 0;
    {
        auto strnums = std::to_string(nums[0]);
        disz = strnums.size();
    }

    // auto di = std::vector<std::vector<int>>(disz, std::vector<int>(10, 0));

    while(disz)
    {
        auto di = std::map<int, long long>();
        for(int i=0;i<n;++i)
        {
            di[nums[i]%10]++;
            nums[i] /= 10;
        }   
        res += nOf;
        for(auto pr : di)
        {
            res -= (fnC(pr.second));
        }
        disz --;
    }
    
    return res;        
}

void TestProblem3()
{
    PRINTLN("LC358 P3:");
    {
        auto vi = std::vector<int>{13,23,12};
        PRINTLN(sumDigitDifferences(vi));
    }
    {
        auto vi = std::vector<int>{10,10,10,10};
        PRINTLN(sumDigitDifferences(vi));
    }
}

// p4

class Solution {
public:
    int tot;
    int k;

    void dfsv1(int jump, int used, int i)
    {
        if (i > k-1)
            return;
        else if(i < 0)
            return;
        else if(i == k-1)
        {
            tot++;
            
        }

        dfsv1(jump+1, false, i+(1<<jump));
        if(!used)
        {
            dfsv1(jump, true, i-1);
        }
    }

    int waysToReachStair(int k) {
        tot = 0;
        dfsv1(0, 0, 0);
        return tot;
    }
};

void TestProblem4()
{
    PRINTLN("LC358 P4:");
    {
        Solution sOl1;
        PRINTLN(sOl1.waysToReachStair(0));
    }
    {
        
        Solution sOl1;
        PRINTLN(sOl1.waysToReachStair(1));
    }
}

__END_NS__


__DEF_NS__(Alan::Inst::LC::Race)

int findPermutationDifference(std::string s, std::string t) {
    auto m1 = std::map<char, int>();
    auto m2 = std::map<char, int>();

    for(int i = 0;i < s.size(); ++i){
        m1.insert(std::make_pair(s[i], i));
        m2.insert(std::make_pair(t[i], i));
    }

    int tot = 0;

    for(auto pr : m1)
    {
        tot += abs(pr.second-m2[pr.first]);
    }

    return tot;
}

void TestProblem1()
{
    PRINTLN("problem1");
    PRINTLN(findPermutationDifference("abcde", "edbac"));
    PRINTLN(findPermutationDifference("abc", "bac"));
}

int maximumEnergy(std::vector<int>& energy, int k) {
    int maxE = 0x80000000;
    int n = energy.size();
    auto resE = std::vector<int>(n,0);
    for(int i = n-1; i>=0;--i)
    {
        if(i+k < n){
            resE[i] += resE[i+k];
        }
        resE[i] += energy[i];
        maxE = std::max(maxE, resE[i]);
    }

    return maxE;
}

void TestProblem2()
{
    PRINTLN("problem2");
    auto vi0 = std::vector<int>{5,2,-10,-5,1};
    PRINTLN(maximumEnergy(vi0, 3));
    auto vi1 = std::vector<int>{-2,-3,-1};
    PRINTLN(maximumEnergy(vi1, 2));
}

int maxScore(std::vector<std::vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    auto dp = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

    int maxS = INT_MIN;
    int minS = INT_MIN;
    for(int j=1;j<n;++j){
        int curVal = grid[0][j]-grid[0][j-1]; minS = std::max(minS, curVal);
        dp[0][j] = (dp[0][j-1]>0)? dp[0][j-1]+curVal: curVal;
        maxS = std::max(dp[0][j], maxS);
    }
    for(int i =1; i<m;++i){
        int curVal = grid[i][0]-grid[i-1][0]; minS = std::max(minS, curVal);
        dp[i][0] = (dp[i-1][0]>0)? dp[i-1][0]+curVal: curVal; 
        maxS = std::max(dp[i][0], maxS);
    }

    for(int i = 1; i < m; ++ i)
    {
        for(int j = 1; j < n; ++ j)
        {
            int curVal1 = grid[i][j]-grid[i][j-1]; minS = std::max(minS, curVal1);
            int curVal2 = grid[i][j]-grid[i-1][j]; minS = std::max(minS, curVal2);
            int of1 = (dp[i][j-1]>0)? dp[i][j-1]+curVal1: curVal1;
            int of2 = (dp[i-1][j]>0)? dp[i-1][j]+curVal2: curVal2;
            dp[i][j] = std::max(of1, of2);
            maxS = std::max(dp[i][j], maxS);
        }
    }

    return (maxS == 0 || maxS == INT_MIN) ? minS : std::max(maxS,minS);
    // return maxS;
}

void TestProblem3()
{
    PRINTLN("problem3");
    // auto vvi = std::vector<std::vector<int>>{{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};
    // PRINTLN(maxScore(vvi));
    // auto vvi2 = std::vector<std::vector<int>>{{4,3,2},{3,2,1}};
    // PRINTLN(maxScore(vvi2));
    // auto vvi3 = std::vector<std::vector<int>>{{4,9},{5,2},{3,1}};
    // PRINTLN(maxScore(vvi3));
    auto vvi4 = std::vector<std::vector<int>>{{2,8},{1,4},{4,7},{3,1},{9,5}};
    PRINTLN(maxScore(vvi4));
}

std::vector<int> findPermutation(std::vector<int>& nums) {
    int n = nums.size();
    auto vi = std::vector<int>(n,0);
    for(int i=0;i<n;++i)
        vi[i] = i;
    int minS = 0x7fffffff;
    auto res = std::vector<int>(n,0);
    do{
        int curS = 0;
        for(int i=0;i<n;++i){
            curS += abs(vi[i]-nums[vi[(i+1)%n]]);
        }
        if(curS < minS){
            minS = curS;
            res = vi;
        }
    }while(std::next_permutation(vi.begin(), vi.end()));

    return res;
}

void TestProblem4()
{
    PRINTLN("problem4");
    auto vi = std::vector<int>{1,0,2};
    Alan::ConsoleBeautyOutput(findPermutation(vi));
    auto vi1 = std::vector<int>{0,2,1};
    Alan::ConsoleBeautyOutput(findPermutation(vi1));
}

void TestProblem5()
{
    PRINTLN("problem5");
}

__END_NS__