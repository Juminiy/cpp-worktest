/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    std::vector<std::vector<int>> res;
    // std::deque<int> cur;

    void dfsT(TreeNode* root, int target, std::vector<int> cur)
    {
        if(root == nullptr)
            return;
        if(!(root->left) && !(root->right) && root->val == target)
        {
            cur.push_back(root->val);
            res.emplace_back(cur);
        }

        if(root->left)
        {
            cur.push_back(root->val);
            dfsT(root->left, target-root->val,cur);
            cur.pop_back();
        }
        if(root->right)
        {
            cur.push_back(root->val);
            dfsT(root->right, target-root->val,cur);
            cur.pop_back();
        }
    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfsT(root, targetSum, {});
        return this->res;
    }
};
// @lc code=end

