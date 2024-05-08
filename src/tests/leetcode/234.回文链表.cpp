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
    if(head == nullptr || head->next == nullptr)
        return true;
    auto __dummy_ = new ListNode(-1, head);
    auto slow = __dummy_, fast = __dummy_;
    ListNode *prev = nullptr;
    int n = 0;
    do {
        prev = slow;
        slow = slow->next; 
        fast = fast->next; if(fast == nullptr) break; ++ n;
        fast = fast->next; if(fast == nullptr) break; ++ n;
    }while(fast != nullptr);

    ListNode * seg1 = __dummy_->next, *seg2 = nullptr;
    if(n%2 == 0)
    {
        seg2 = slow;
        prev->next = nullptr;
    } else 
    {
        seg2 = slow->next;
        slow->next = nullptr;
    }
    __reverse_list_node_(seg2);

    while(seg1 != nullptr && seg2 != nullptr)
    {
        if(seg1->val != seg2->val)
            return false;
        seg1 = seg1->next;
        seg2 = seg2->next;
    }

    return true;
}

};
// @lc code=end

