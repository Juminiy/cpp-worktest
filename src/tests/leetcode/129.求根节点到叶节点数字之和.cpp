/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int getTotal(TreeNode *root, int curNum)
    {
        if(!root)
            return 0;
        if(!(root->left) && !(root->right))
        {
            return curNum*10 + root->val;
        } 
        
        int lSum = getTotal(root->left, curNum*10+root->val);
        int rSum = getTotal(root->right, curNum*10+root->val);
        
        return lSum + rSum;
            
    }

    int sumNumbers(TreeNode* root) {
        return getTotal(root, 0);
    }
};
// @lc code=end

