/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        auto cur = node, prev = node;
        while(cur != nullptr && cur->next != nullptr)
        {
            prev = cur;
            auto next = cur->next;
            if(next != nullptr)
            {
                cur->val = next->val;
            }
            cur = next;
        }
        prev->next = nullptr;
    }
};
// @lc code=end

