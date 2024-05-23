/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    // 1->2->3->4->5
ListNode* oddEvenList(ListNode* head) {
    // ListNode * __dummy_ = new ListNode(-1, head);
    ListNode * cur = head, * prev = nullptr;
    // int n = 0;
    ListNode * seg2Head = nullptr, *seg2Cur = nullptr;
    while(cur != nullptr)
    {
        auto odd = cur->next;
        if(odd != nullptr)
        {   
            cur->next = odd->next;
            odd->next = nullptr;
            
            if(seg2Cur != nullptr)
                seg2Cur->next = odd;
            seg2Cur = odd;
            if(seg2Head == nullptr)
                seg2Head = seg2Cur;
        }
        prev = cur;
        cur = cur->next;
    }
    if(prev != nullptr)
        prev->next = seg2Head;

    return head;
}
};
// @lc code=end

