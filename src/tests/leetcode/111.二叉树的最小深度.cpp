/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {

    auto tq = std::queue<std::pair<TreeNode*, int>>();
    if(root != nullptr)
    {
        tq.push(std::make_pair(root, 1));
    }
        
    
    // _vi.reserve(_ssz);
    while(!tq.empty())
    {
        auto rt = tq.front(); tq.pop();
        if(rt.first->left==nullptr && rt.first->right == nullptr)
            return rt.second;
        if(rt.first->left)
            tq.push(std::make_pair(rt.first->left, rt.second+1));
        if(rt.first->right)
            tq.push(std::make_pair(rt.first->right, rt.second+1));
    }

    return 0;
    }
};
// @lc code=end

