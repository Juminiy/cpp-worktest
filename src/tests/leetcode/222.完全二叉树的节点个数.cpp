/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
// binOf, mathCal
/*  
        1
       / \ 
      2   3 
     / \ / \ 
    4  5 6  _

*/
    int countNodes(TreeNode* root) {
        int kOf = 0;
        if (root)
            ++kOf;
        while(root)
        {
            if(root->left == nullptr)
            {
                ++kOf;
                break;
            } else if(root->right == nullptr)
            {   
                ++kOf;
                break;
            } else 
            {
                ++kOf;
                root = root->right;
            }
        }
    }
};
// @lc code=end

