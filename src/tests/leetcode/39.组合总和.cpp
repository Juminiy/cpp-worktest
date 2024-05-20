/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    // 2 3 5
    std::vector<std::vector<int>> vvi;
    int nOf;
    std::vector<int> candi;
    void dfs(std::vector<int> vi, int iOf, int tOf)
    {
        if(iOf == n)
            return;

        if (tOf == 0){
            vvi.push_back(std::move(vi));
            return ;
        }

        if()
        vi.push_back(candi[i]);
        dfs();


    }

    std::vector<std::vector<int>> 
    combinationSum(vector<int>& candidates, int target) {
        this->candi = std::move(candidates);

        return vvi;
    }
};
// @lc code=end

