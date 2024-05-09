/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
    /*
        1 2 3 4
        5 1 2 3
        6 5 1 2
    */
    // 0,0 1,1 2,2 
    // 1,0 2,1 
    // 2,0 
    // 0,1 1,2 2,3
    // ...
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        size_t row = matrix.size(); if(row == 0) return false;
        size_t lin = matrix[0].size(); if(lin == 0) return false;

        auto check_rl = [&](int r, int l) -> bool {
            auto pivot = matrix[r][l];
            while(r<row && l < lin){
                if(pivot != matrix[r][l])
                    return false;
                ++r, ++l;
            }
            return true;
        };

        for(int r = 0; r < row; ++r)
        {
            if(!check_rl(r, 0))
                return false;
        }

        for(int l = 1; l < lin; ++l)
        {
            if(!check_rl(0, l))
                return false;
        }

        return true;
    }
};
// @lc code=end

