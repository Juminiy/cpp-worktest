/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac" -> true
        // s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc" -> false 

        bv[i][j] = 
        int m = s1.size(), n = s2.size();
        auto bv = std::vector<std::vector<bool>>(m, std::vector<bool>(n, false));
        for(int i = 0;i < m; ++i){
            for(int j =0; j < n;++j){
                if()
            }
        }
        return bv[m-1][n-1];
    }
};
// @lc code=end

