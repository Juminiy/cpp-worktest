/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
    auto __dummy_ = new ListNode(0x8fff, head);
    
    auto __prev_ = __dummy_;
    auto __turn_ = __prev_->next;
    while(__turn_ != nullptr)
    {
        auto pivotVal = __turn_->val;
        auto cnt = size_t(0);
        do{
        __turn_ = __turn_->next;
        ++ cnt;
        } while (__turn_ != nullptr && __turn_->val == pivotVal);
        if(cnt > 1)
        {
            __prev_->next = __turn_;
        } else 
        {
            __prev_ = __prev_->next;
        }
    }

    return __dummy_->next;
}
};
// @lc code=end

