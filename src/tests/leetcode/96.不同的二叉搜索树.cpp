/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
   int numTrees(int n) {
    int f[22] = {1,1};
    for(int i=2;i<=n;++i)
    {
        f[i] = 0;
        for(int j=0;j<=i-1;++j)
        {
            f[i] += f[j] * f[i-j-1];
        }
    }
    return f[n];
}
};
// @lc code=end

