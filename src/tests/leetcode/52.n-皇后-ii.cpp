/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
bool conflict(int i, int in, int j, int jn, int n){
    if(i == j || in & jn)
        return true;
    int x = 0, y = 0;
    while(x< n) {
        if(in & (1<<x)) break;
        ++x;
    }
    while(y< n) {
        if(jn & (1<<y)) break;
        ++y;
    }
    x = n-x-1;
    y = n-y-1;

    return i-x == j-y || i+x == j+y;

}

void dfsEQ(int i, int &cnt, int vi[12], int n)
{
    if(i == n)
    {
        ++cnt;
        return;
    }

    for(int j = 0; j < n; ++j){
        bool ok = true;
        for(int x = 0; x < i; ++x){
            if(conflict(i, 1<<j, x, vi[x], n))
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            vi[i] = 1<<j;
            dfsEQ(i+1, cnt, vi, n);
        }       
    }
}
    int totalNQueens(int n) {
        int cnt = 0;
        int vi[12];
        dfsEQ(0, cnt, vi, n);
        return cnt;
    }
};
// @lc code=end

