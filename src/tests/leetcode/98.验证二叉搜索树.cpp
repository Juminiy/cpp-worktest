/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
bool isValidBST(TreeNode* root) {
    
    auto tstk = std::stack<TreeNode*>();
    long long prevVal = -2147483649;
    while(root !=nullptr || !tstk.empty())
    {
        while(root != nullptr)
        {
            tstk.push(root);
            root = root->left;
        }
        if(!tstk.empty())
        {
            root = tstk.top(); tstk.pop();
            if(root->val <= prevVal)
                return false;
            else 
                prevVal = root->val;
            
            root = root->right;
        }
    }
    
    return true;
}
};
// @lc code=end

