/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    auto __turn_ = __dummy_;
    
    while(__turn_ != nullptr)
    {
        auto _prev = __turn_;
        auto _pivot = _prev->val;
        auto _iter = _prev->next;
        while(_iter != nullptr && 
                _pivot == _iter->val)
        {
            _prev = _iter;
            _iter = _iter->next;
        }
        if(_prev->val == _pivot)
        {
        __turn_->next = _iter;
        }
        __turn_ = _iter;
    }

    return __dummy_->next;
}
};
// @lc code=end

