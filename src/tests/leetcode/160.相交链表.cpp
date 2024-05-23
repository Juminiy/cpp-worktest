/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * lHead = headA, * sHead = headB;
        ListNode * a = headA, * b = headB;
        while( a != nullptr && b != nullptr)
        {
            a = a->next;
            b = b->next;
        }
        if(a != nullptr && b == nullptr)
        {
            lHead = headA; sHead = headB;
            while(a != nullptr)
            {
                a = a->next;
                lHead = lHead->next;
            }
        } else if(b != nullptr && a == nullptr)
        {
            lHead = headB; sHead = headA;
            while(b != nullptr)
            {
                b = b->next;
                lHead = lHead->next;
            }
        } 


    while(lHead != nullptr && 
        sHead != nullptr && 
        lHead != sHead)
    {
        lHead = lHead->next;
        sHead = sHead->next;
    }

    return lHead;
    }
};
// @lc code=end

