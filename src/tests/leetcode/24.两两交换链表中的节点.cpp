/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
    auto __dummy_ = new ListNode(-1, head);
    auto __prev_ = __dummy_;
    int cnt = 2;
    do{
        // seg [start, end]
        auto __start_ = __prev_->next;
        auto __end_ = __prev_;
        while(cnt && __end_ != nullptr)
        {
            __end_ = __end_->next;
            --cnt;
        }
        if(cnt > 0 || __end_ == nullptr)
        {
            break;
        }

        auto segrv_end = __prev_->next; 
        if(__prev_ != nullptr)
            __prev_->next = nullptr;
        auto end_next = __end_->next; 
        if(__end_ != nullptr)
            __end_->next = nullptr;
        __reverse_list_node_(__start_);
        __prev_->next = __start_;
        segrv_end->next = end_next;
        __prev_ = segrv_end;
        cnt = 2;
    }while(__prev_ != nullptr);

    return __dummy_->next;
}
};
// @lc code=end

