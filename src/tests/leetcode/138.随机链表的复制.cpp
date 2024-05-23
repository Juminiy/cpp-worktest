/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
Node* copyRandomList(Node* head) {
    auto old2New = std::unordered_map<Node*, Node*>();
    Node *cur = nullptr, *newHead = nullptr;
    Node *trav = nullptr;

    auto __append_node_ = 
        [&cur, &newHead](Node * newNode) {
            if(cur != nullptr)
                cur->next = newNode;
            cur = newNode;

            if(newHead == nullptr)
                newHead = cur;
        };

    trav = head;
    while(trav != nullptr)
    {   
        auto newNode = new Node(trav->val);
        __append_node_(newNode);
        old2New[trav] = newNode;
        trav = trav->next;
    }

    trav = head;
    while(trav != nullptr)
    {
        if(trav->random != nullptr)
        {
            old2New[trav]->random = 
                old2New[trav->random];
        }
        trav = trav->next;
    }

    return newHead;
}

};
// @lc code=end

