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

int countNodes(TreeNode* root) {
    if(!root) return 0;
    int levelK = 0;
    auto lNode = root;
    while(lNode && lNode->left){
        lNode = lNode->left;
        levelK++;
    }
    int lBound = 1<<levelK, rBound = (1<<(levelK+1)) -1;
    
    auto nodeOf = [levelK](TreeNode *rt, int nodeK) -> bool {
        auto bitCnt = levelK;
        while(bitCnt && rt)
        {
            auto bitLR = nodeK & (1<<(bitCnt-1));
            if(!bitLR){
                rt = rt->left;
            } else {
                rt = rt->right;
            }
            bitCnt--;
        }
        return rt != nullptr;
    };

    while(lBound < rBound)
    {
        if(rBound-lBound == 1){
            if(nodeOf(root, rBound)) return rBound;
            if(nodeOf(root, lBound)) return lBound;
        }
        int midOf = ((rBound - lBound) >> 1) + lBound;
        if(nodeOf(root, midOf))
        {
            lBound = midOf;
        } else {
            rBound = midOf-1;
        }
    }
    return lBound;
}

};
// @lc code=end

