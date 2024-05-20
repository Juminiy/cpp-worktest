/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        auto vvi = std::vector<std::vector<int>>();

        auto sumOf = std::accumulate(candidates.begin(), candidates.end(), 0);
        if(sumOf < target) {
            return vvi;
        }

        for(int i =0;i<n;++i){
            if(candidates[i] >= target){
                n = i+1;
                break;
            }
        }
        candidates = std::vector<int>(candidates.begin(), candidates.begin()+n);
        // std::reverse(candidates.begin(), candidates.end());

        const long long of1 = 1;

        auto vs = std::set<std::vector<int>>();
        for(long long i =1; i < (of1<<static_cast<long long>(n)); ++i)
        {
            int dest = 0;
            auto vi = std::vector<int>();
            for(long long j = 0; j<n;++j){
                if(i & (of1<<static_cast<long long>(j))){
                    dest += candidates[j];
                    vi.push_back(candidates[j]);
                    if (dest > target) {
                        break;
                    }
                }
            }
            if (dest == target && vs.find(vi) == vs.end()){
                vs.insert(vi);
                vvi.push_back(std::move(vi));
            }
        }

        // for(auto it = vs.begin(); it != vs.end(); ++it)
        //     vvi.push_back(std::move(*it));

        return vvi;
    }
};
// @lc code=end

