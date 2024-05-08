/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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

bool isPalindrome(ListNode* head) {
    auto ori = head;
    __reverse_list_node_(head);
    while(ori != nullptr)
    {
        if(ori->val != head->val) 
            return false;
        ori = ori->next;
        head = head->next;
    }
    return true;
}
};
// @lc code=end

