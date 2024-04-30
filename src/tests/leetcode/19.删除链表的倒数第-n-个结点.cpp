/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto __dummy_ = new ListNode(-1, head);
    auto __puppet_ = __dummy_, __stand_ = __dummy_;
    while(n--)
    {
        __puppet_ = __puppet_ -> next;
    }
    while(__puppet_ != nullptr &&
        __puppet_->next != nullptr)
    {
        __puppet_ = __puppet_ -> next;
        __stand_ = __stand_ -> next;
    }
    if (__stand_ != nullptr &&
        __stand_->next != nullptr)
        __stand_->next = __stand_->next->next;
    return __dummy_->next;
}

};
// @lc code=end

