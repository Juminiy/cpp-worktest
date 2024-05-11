/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int getH(TreeNode* root){
        if(root == nullptr)
            return 0;
        return std::max(getH(root->left), getH(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isBalanced(root->left) && 
                isBalanced(root->right) &&
                std::abs( getH(root->left) - getH(root->right) ) <= 1;
    }
};
// @lc code=end

