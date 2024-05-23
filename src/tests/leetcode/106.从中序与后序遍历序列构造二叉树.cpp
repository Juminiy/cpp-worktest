/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
#define U32 (unsigned int)
#define I32_IN_RANGE(_x, _min, _max) \
        (U32(_x)-U32(_min) <= U32(_max)-U32(_min))
TreeNode* __mid_post_seq_build_helper
(const std::vector<int> & mid_vec, size_t midL, size_t midR,
const std::vector<int> & post_vec, size_t posL, size_t posR)
{
    // PRINT_DETAIL(midL),PRINT(", "),PRINT_DETAIL(midR),PRINT(", "),
    // PRINT_DETAIL(posL),PRINT(", "),PRINT_DETAIL(posR),PRINTLN("");
    // size_t maxsz = mid_vec.size();
    // if(posL > posR || 
    //     midL < 0 || posL == maxsz || 
    //     posL < 0 || posR == maxsz)
    //     return nullptr;

    auto __root_ = new TreeNode(post_vec[posR]);

    size_t __mdis_ = 
        std::find(mid_vec.begin()+midL, mid_vec.begin()+midR+1, post_vec[posR]) 
            - mid_vec.begin();       // 1
    size_t __llen_ = __mdis_ - midL; // 1 - 0 = 1
    // size_t __rlen_ = midR - __mdis_; 

    if(I32_IN_RANGE(midL+__llen_-1, midL, midR)&&
        I32_IN_RANGE(posL+__llen_-1, posL, posR))
    __root_->left = __mid_post_seq_build_helper
                    (mid_vec, midL, midL+__llen_-1,     // _, 0, 0 
                    post_vec, posL, posL+__llen_-1);    // _, 0, 0
    
    if(I32_IN_RANGE(__mdis_+1, midL, midR)&&
        I32_IN_RANGE(posL+__llen_, posL, posR))
    __root_->right = __mid_post_seq_build_helper
                    (mid_vec, __mdis_+1, midR,           // _, 2, 4
                    post_vec, posL+__llen_, posR-1);     // _, 1, 3
    
    return __root_;
}

TreeNode* __build_tree_node_of_mid_post_
(const std::vector<int> & mid_vec, const std::vector<int> & post_vec)
{
    return __mid_post_seq_build_helper
            (mid_vec, 0, mid_vec.size()-1,
            post_vec, 0, post_vec.size()-1);
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return __build_tree_node_of_mid_post_(inorder, postorder);
    }
};
// @lc code=end

