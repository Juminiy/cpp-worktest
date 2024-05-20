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
    std::vector<std::vector<int>> vvi;
    std::vector<int> candi;
    int targ;

    void dfsv0(int le, int id, std::vector<int> vi)
    {
        if (le < 0 || id >= candi.size())
            return;
        if(le == 0)
        {
            vvi.push_back(vi);
            return;
        }

        if(le >= candi[id])
        {
            vi.push_back(candi[id]);
            dfsv0(le-candi[id], id, vi);
            vi.pop_back();
        }

        dfsv0(le, id+1, vi);

        // if(id + 1 == candi.size())
        //     return;

        // if(le >= candi[id+1])
        // {
        //     vi.push_back(candi[id+1]);
        //     dfsv0(le-candi[id+1], id+1, vi);
        // }
            
    }

    vector<vector<int>> combinationSum
        (vector<int>& candidates, int target) {
        this->candi = std::move(candidates);
        this->targ = target;

        dfsv0(target, 0, {});

        return vvi;
    }
};
// @lc code=end

