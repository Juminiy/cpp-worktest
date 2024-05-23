/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
   std::vector<TreeNode*> genTHelper(int start, int end){
    if(start > end)
        return { nullptr };
    
    auto tVec = std::vector<TreeNode*>();
    for(int i = start; i <= end; ++i)
    {
        auto lVec = genTHelper(start, i-1);
        auto rVec = genTHelper(i+1, end);

        tVec.reserve(lVec.size() * rVec.size());
        for(auto & lElem : lVec)
        {
            for(auto & rElem : rVec)
            {
                auto tElem = new TreeNode(i);
                tElem->left = lElem;
                tElem->right = rElem;
                tVec.emplace_back(tElem);
            }
        }

    }   

    return tVec;
}

std::vector<TreeNode*> generateTrees(int n) {
    return genTHelper(1, n);
}
using __se_tmap_ = std::multimap<std::pair<int,int>, TreeNode*>;

// void genTHelper
// (int start, int end, __se_tmap_ & tmap)
// {
//     if(start == end)
//     {
//         auto ssRange = std::pair<int,int>(start,start);
//         if(tmap.find(ssRange) == tmap.end())
//             tmap.insert(std::make_pair(std::make_pair(start,start), new TreeNode(start)));
//         return;
//     } else if ( start == 0 || end == 0 || start > end)
//         return;

//     // left is solved, right has not been solved
//     for(int rootVal = start; rootVal <= end; ++rootVal)
//     {
//         auto lRange = std::pair<int,int>(start, rootVal-1);
//         auto rRange = std::pair<int,int>(rootVal+1, end);
//         if(tmap.find(lRange) == tmap.end())
//             genTHelper(1, rootVal-1, tmap);
//         if(tmap.find(rRange) == tmap.end())
//             genTHelper(rootVal+1, end, tmap);

//         auto [lstart, lend] = tmap.equal_range(lRange);
//         auto [rstart, rend] = tmap.equal_range(rRange);

//         if(lstart == lend)
//         {
//             for(auto curr = rstart; curr != rend; ++curr)
//             {
//                 auto root = new TreeNode(rootVal);
//                 root->right = curr->second;
//                 tmap.insert(std::make_pair(std::make_pair(start, end), root));
//             }
//         } else if (rstart == rend)
//         {
//             for(auto curl = lstart; curl != lend; ++curl)
//             {
//                 auto root = new TreeNode(rootVal);
//                 root->left = curl->second;
//                 tmap.insert(std::make_pair(std::make_pair(start, end), root));
//             }
//         } else 
//         {
//             for(auto curl = lstart; curl != lend; ++curl)
//             {
//                 for(auto curr = rstart; curr != rend; ++curr)
//                 {
//                     auto root = new TreeNode(rootVal);
//                     root->left = curl->second;
//                     root->right = curr->second;
//                     tmap.insert(std::make_pair(std::make_pair(start, end), root));
//                 }
//             }
//         }   
//     }
// }

// std::vector<TreeNode*> generateTrees(int n) {
//     auto tmap = __se_tmap_();
//     // for(int i=1;i<=n;i++)
//     // {
//     //     tmap.insert(std::make_pair(std::make_pair(i, i), new TreeNode(i)));
//     // }

//     genTHelper(1, n, tmap);

//     auto [vi0, vi1] = tmap.equal_range(std::pair<int,int>(1,n));

//     auto vT = std::vector<TreeNode*>();
//     for(; vi0 != vi1; ++vi0)
//     {
//         vT.push_back(vi0->second);
//     }

//     return vT;

// }
};
// @lc code=end

