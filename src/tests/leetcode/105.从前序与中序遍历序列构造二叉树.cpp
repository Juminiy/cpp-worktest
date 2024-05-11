/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
TreeNode* __pre_mid_seq_build_helper
(const std::vector<int> & pre_vec, size_t preL, size_t preR,
const std::vector<int> & mid_vec, size_t midL, size_t midR)
{
    if(preL > preR || preL == pre_vec.size() || midL == mid_vec.size())
        return nullptr;
    
    auto __root_ = new TreeNode(pre_vec[preL]);
    size_t __mdis_ = 
        std::find(mid_vec.begin()+midL, mid_vec.begin()+midR+1, pre_vec[preL]) 
            - mid_vec.begin();       // 1
    size_t __llen_ = __mdis_ - midL; // 1 - 0 = 1
    // size_t __rlen_ = midR - __mdis_; // 4 - 1 = 3

    __root_->left = __pre_mid_seq_build_helper
                    (pre_vec, preL+1, preL+1+__llen_-1, // _, 1, 1 
                    mid_vec, midL, midL+__llen_-1);     // _, 0, 0
    
    __root_->right = __pre_mid_seq_build_helper
                    (pre_vec, preL+1+__llen_, preR,     // _, 2, 4
                    mid_vec, __mdis_+1, midR);          // _, 2, 4
    
    return __root_;
}

TreeNode* __build_tree_node_of_pre_mid_
(const std::vector<int> & pre_vec, const std::vector<int> & mid_vec)
{
    return __pre_mid_seq_build_helper
            (pre_vec, 0, pre_vec.size()-1,
            mid_vec, 0, mid_vec.size()-1);

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return __build_tree_node_of_pre_mid_(preorder, inorder);
    }
};
// @lc code=end

