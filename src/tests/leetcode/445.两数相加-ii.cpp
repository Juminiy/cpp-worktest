/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    void __append_list_node_(ListNode * &__cur_, int __val_)
{   
    auto __next_ = new ListNode(__val_);
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    __cur_ = __next_;
}
    ListNode* addTwoNumbersrev(ListNode* l1, ListNode* l2) {
    int _remain = 0, _cal = 0;
    int _l1val = 0, _l2val = 0;
    ListNode * __head_ = nullptr, * __cur_ = nullptr;
    while(l1 != nullptr || l2 != nullptr || _remain > 0)
    {   
        _l1val = (l1 != nullptr) ? l1->val : 0;
        _l2val = (l2 != nullptr) ? l2->val : 0;
        _cal = _remain + _l1val + _l2val;
        __append_list_node_(__cur_, _cal%10);
        _remain = _cal/10;

        l1 = (l1 != nullptr) ? l1->next : l1;
        l2 = (l2 != nullptr) ? l2->next : l2;

        __head_ = (__head_ == nullptr) ? __cur_ : __head_;
    }
    return __head_;
}  
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        __reverse_list_node_(l1);
        __reverse_list_node_(l2);

        auto _sum = addTwoNumbersrev(l1, l2);

        __reverse_list_node_(_sum);
        return _sum;
    }
};
// @lc code=end

