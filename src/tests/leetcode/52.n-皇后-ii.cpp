/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int cnt,n;

    void dfs(int i, int col, int le, int ri){
        if(i == n){
            ++cnt;
            return;
        }
        int okOf = ((1<<n) - 1) & (~(col | le | ri));
        while(okOf){
            int j = okOf & (-okOf);
            okOf &= okOf-1;
            dfs(i+1, j|col, (j|le)<<1, (j|ri)>>1);
        }
    }

    int totalNQueens(int n) {
        cnt = 0;
        this->n = n;
        dfs(0, 0, 0, 0);
        return cnt;
    }
};
// @lc code=end

