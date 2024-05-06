/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    auto cnt = size_t(0);
    auto __dummy_ = new ListNode(0x7fffff, head);
    auto __cur_ = __dummy_;
    ListNode * _seg_prev = nullptr, *_seg_old_end = nullptr;
    // find and cut 
    while(__cur_ != nullptr && cnt < right)
    {
        if(cnt == left-1)
            _seg_prev = __cur_;
        __cur_ = __cur_->next;
        ++ cnt;
    }
    auto _seg_old_begin = _seg_prev->next; _seg_old_end = __cur_;
    auto _seg_new_end = _seg_old_begin;
    auto _seg_next = _seg_old_end->next; _seg_old_end->next = nullptr;
    __reverse_list_node_(_seg_old_begin); // _seg_new_begin
    _seg_prev->next = _seg_old_begin;
    _seg_new_end->next = _seg_next;

    return __dummy_->next;
}
};
// @lc code=end

