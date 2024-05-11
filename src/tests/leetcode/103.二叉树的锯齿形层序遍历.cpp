/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
/*
        1               0 
       / \             / \ 
      2   3           2   4  
     / \ / \         / \ /  \ 
    4  _ _  5       1  _ 3  -1
                   / \  / \ / \ 
                  5  1 _  6 _  8
*/                                  
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        auto vvi = std::vector<std::vector<int>>();
        auto tq = std::queue<TreeNode*>();
        // auto tq2 = std::queue<TreeNode*>();
        #define __pushq(__q, __el) \
                if(__el != nullptr) __q.push(__el)

        // routine1
        __pushq(tq, root);
        // __pushq(tq2, root);
        bool lOf = true;
        
        while(!tq.empty())
        {
            auto vi = std::vector<int>();
            auto q = std::queue<TreeNode*>();
            // auto q2 = std::queue<TreeNode*>();
            while(!tq.empty())
            {
                root = tq.front(); tq.pop();
                // auto troot = tq2.front(); tq2.pop();
                vi.push_back(root->val);
                // if(lOf)
                // {
                //     __pushq(q, root->left);
                //     __pushq(q, root->right);
                // } else 
                // {
                //     __pushq(q, root->right);
                //     __pushq(q, root->left);
                // }
                // __pushq(q2, troot->left);
                // __pushq(q2, troot->right);  
                __pushq(q, root->left);
                __pushq(q, root->right);             
            }
            if(!lOf)
                std::reverse(vi.begin(), vi.end());
            vvi.push_back(std::move(vi));
            tq = std::move(q);
            // tq2 = std::move(q2);
            lOf = !lOf;
        }
        return vvi;
    }
};
// @lc code=end

