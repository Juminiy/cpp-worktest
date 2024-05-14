/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    std::vector<std::vector<string>> vss;
    int n,cnt;
    int vi[12];

int getY(int yOf){
    int y = 0;
    while(y< n)
    {
        if(yOf & (1<<y)) break;
        ++y;
    }
    return n-1-y;
}

bool conflict(int i, int in, int j, int jn){
    if(i == j || in & jn)
        return true;
    int x = getY(in), y = getY(jn);
    return i-x == j-y || i+x == j+y;

}

void dfsEQ(int i)
{
    if(i == n)
    {
        auto vs = std::vector<std::string>(n, std::string(n, '.'));
        for(int i=0;i<n;++i)
            vs[i][getY(vi[i])] = 'Q';
        vss.push_back(std::move(vs));
        return;
    }

    for(int j = 0; j < n; ++j){
        bool ok = true;
        for(int x = 0; x < i; ++x){
            if(conflict(i, 1<<j, x, vi[x]))
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            vi[i] = 1<<j;
            dfsEQ(i+1);
        }       
    }
}
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        dfsEQ(0);
        return vss;
    }
};
// @lc code=end

