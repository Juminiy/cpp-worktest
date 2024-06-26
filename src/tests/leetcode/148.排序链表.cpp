/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
std::vector<int> vi;
    vi.reserve(50000);
    auto cur = head;
    while(cur != nullptr)
    {
    vi.push_back(cur->val);
    cur = cur->next;
    }

    std::sort(vi.begin(), vi.end());

    cur = head;
    size_t i = 0;
    while(cur != nullptr)
    {
        cur->val = vi[i++];
        cur = cur->next;
    }

    return head;
    }
};
// @lc code=end

