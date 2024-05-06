/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
void __fpush_list_node_(ListNode * &__cur_, ListNode * &__prev_)
{
    if(__prev_ != nullptr)
    {
        __prev_->next = __cur_;
        __cur_ = __prev_;
    }
    __prev_ = nullptr;
}
void __reverse_list_node_(ListNode * & __head_)
{
    ListNode* __dummy_ = nullptr;
    auto __next_ = __head_;

    while(__next_ != nullptr)
    {
        __next_ = __head_->next;
        __fpush_list_node_(__dummy_, __head_);
        __head_ = __next_;
    }

    __head_ = __dummy_;
}
size_t __len_list_node_(ListNode * __head_)
{
    auto __len_ = size_t(0);
    while(__head_ != nullptr) 
    {
        ++ __len_;
        __head_ = __head_->next;
    }
    return __len_;
}

ListNode* __get_nextn_list_node_(ListNode * __head_, size_t __sz_)
{
    // __sz_ must <= __head_
    while(__head_ != nullptr && __sz_ > 0)
    {
        __head_ = __head_->next;
        -- __sz_;
    }
    return __head_;
}
    ListNode* rotateRight(ListNode* head, int k) {
    auto __len_ = __len_list_node_(head);
    if(__len_ == 0 || k == 0 || k == __len_ )
        return head;
    k %= __len_;
    auto __dummy_ = new ListNode(-1, head);

    auto seg1_old_head = __dummy_->next; 
    auto seg1_old_tail = __get_nextn_list_node_(__dummy_, __len_ - k);
    auto seg1_new_tail = seg1_old_head;
    auto seg2_old_head = seg1_old_tail->next;
    seg1_old_tail->next = nullptr;
    __reverse_list_node_(seg1_old_head); // seg1_new_head
    __reverse_list_node_(seg2_old_head); // seg2_new_head
    seg1_new_tail->next = seg2_old_head;
    __reverse_list_node_(seg1_old_head); // new_head

    return seg1_old_head;
}
};
// @lc code=end

