/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
void __trav_tree_node_midorder_(TreeNode * __root, std::vector<int> & _vi)
{
    auto tstk = std::stack<TreeNode*>();

    while(__root !=nullptr || !tstk.empty())
    {
        while(__root != nullptr)
        {
            tstk.push(__root);
            __root = __root->left;
        }
        if(!tstk.empty())
        {
            __root = tstk.top(); tstk.pop();
            _vi.push_back(__root->val);
            __root = __root->right;
        }
    }

}
    std::vector<int> 
inorderTraversal(TreeNode* root) 
{
    auto vi = std::vector<int>();
    vi.reserve(101);
    __trav_tree_node_midorder_(root, vi);
    return vi;
}
};
// @lc code=end

