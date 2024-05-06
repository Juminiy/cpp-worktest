/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
void __append_list_node_(ListNode * &__cur_, ListNode * &__next_)
{
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    __cur_ = __next_;
    __next_ = nullptr;
}
    ListNode* partition(ListNode* head, int x) {
    ListNode * __lt_head_ = nullptr, * __lt_ = nullptr;
    ListNode * __ge_head_ = nullptr, * __ge_ = nullptr;
    auto __cur_ = head;

    while(__cur_ != nullptr)
    {
        auto _next = __cur_->next;
        __cur_->next = nullptr;
        if(__cur_->val < x)
        {
        __append_list_node_(__lt_, __cur_);
        if(__lt_head_ == nullptr)
            __lt_head_ = __lt_;
        } else 
        {
        __append_list_node_(__ge_, __cur_);
        if(__ge_head_ == nullptr)
            __ge_head_ = __ge_;
        }
        __cur_ = _next;
    }
    if(__lt_ != nullptr)
        __lt_->next = __ge_head_;

    return __lt_head_ != nullptr ? __lt_head_ : __ge_head_;
}
};
// @lc code=end

