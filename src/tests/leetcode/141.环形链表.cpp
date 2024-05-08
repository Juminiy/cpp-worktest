/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
    auto __dummy_ = new ListNode(-1, head);
    ListNode *slow = __dummy_, *fast = __dummy_;

    #define __toend(__node_) \
            if(__node_ == nullptr) return false

    do
    {
        slow = slow->next; __toend(slow);
        fast = fast->next; __toend(fast); fast = fast->next; __toend(fast);
    } while (fast != slow);
    
    return fast == slow;
}
};
// @lc code=end

