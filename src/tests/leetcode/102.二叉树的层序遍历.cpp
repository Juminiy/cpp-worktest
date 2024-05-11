/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        auto vvi = std::vector<std::vector<int>>();
        auto tq = std::queue<TreeNode*>();
        if(root != nullptr)
            tq.push(root);
        while(!tq.empty())
        {
            auto vi = std::vector<int>();
            auto q = std::queue<TreeNode*>();
            while(!tq.empty())
            {
                root = tq.front(); tq.pop();
                vi.push_back(root->val);
                if(root->left != nullptr)
                    q.push(root->left);
                if(root->right != nullptr)
                    q.push(root->right);
            }
            vvi.push_back(std::move(vi));
            tq = std::move(q);
        }
        return vvi;
    }
};
// @lc code=end

