/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
Node* connect(Node* root)
{
    auto nq = std::queue<Node*>();
    #define __pushq_(__q_, __node_) \
            if(__node_ != nullptr) __q_.push(__node_)
    
    __pushq_(nq, root);
    while(!nq.empty())
    {
        auto tq = decltype(nq)();
        auto prev = decltype(root)(nullptr);
        while(!nq.empty())
        {
            auto tt = nq.front(); nq.pop();
            if(prev != nullptr)
                prev->next = tt;
            
            prev = tt;
            __pushq_(tq, tt->left);
            __pushq_(tq, tt->right);
        }
        nq = std::move(tq);
    }

    return root;
}
};
// @lc code=end

