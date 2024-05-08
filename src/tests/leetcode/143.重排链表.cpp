/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    // 1 2 3 4   slow = 
// 1 2 3 4 5
void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode * __dummy_ = new ListNode(-1, head);
    auto fast = __dummy_, slow = __dummy_, prev = __dummy_;

    #define __toend(__node_) \
            if(__node_ == nullptr) break
    int n = 0;
    while(fast != nullptr)
    {
        prev = slow;
        slow = slow->next; __toend(slow);
        fast = fast->next; __toend(fast); ++n;
        fast = fast->next; __toend(fast); ++n;
    }
    auto seg1 = head, seg2 = head;
    if(n%2 == 0)
    {
        prev->next = nullptr;
        seg2 = slow;
    } else 
    {
        seg2 = slow->next;
        slow->next = nullptr;
    }

    // rev seg2
    __reverse_list_node_(seg2);

    auto seg2Tail = seg2, seg1Tail = seg1;
    // merge seg1 seg2

    while(seg2Tail != nullptr)
    {
        auto elem2 = seg2Tail; 
        seg2Tail = seg2Tail->next; 
        elem2->next = nullptr;

        if(seg1Tail != nullptr)
        {
            elem2->next = seg1Tail->next;
            seg1Tail->next = elem2;
            seg1Tail = seg1Tail->next->next;
        }
    }
}

};
// @lc code=end

