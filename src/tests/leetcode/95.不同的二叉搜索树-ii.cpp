/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   std::vector<TreeNode*> genTHelper(int start, int end){
    if(start > end)
        return { nullptr };
    
    auto tVec = std::vector<TreeNode*>();
    for(int i = start; i <= end; ++i)
    {
        auto lVec = genTHelper(start, i-1);
        auto rVec = genTHelper(i+1, end);

        tVec.reserve(lVec.size() * rVec.size());
        for(auto & lElem : lVec)
        {
            for(auto & rElem : rVec)
            {
                auto tElem = new TreeNode(i);
                tElem->left = lElem;
                tElem->right = rElem;
                tVec.emplace_back(tElem);
            }
        }

    }   

    return tVec;
}

std::vector<TreeNode*> generateTrees(int n) {
    return genTHelper(1, n);
}
};
// @lc code=end

