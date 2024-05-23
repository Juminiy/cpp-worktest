/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
size_t __len_list_node_(ListNode * __head_)
{
    auto __len_ = size_t(0);
    while(__head_ != nullptr) 
    {
        ++ __len_;
        __head_ = __head_->next;
    }
    return __len_;
}
    // 3/5 -> 1 1 1 0 0
    // 10/3 -> 4 3 3
    // 20/3 -> 7 7 6
    // 20/7 -> 3 3 3 3 3 3 2

    // 1 2 3 4 5 6 7 8 9 10 
    // | | | |
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        size_t lLen = __len_list_node_(head);
        size_t segLen = lLen / k, segRem = lLen % k;
        auto vl = std::vector<ListNode *>(k, nullptr);
        size_t szvl = 0;
        auto cur = head;
        while(head != nullptr)
        {
            auto curLen = segLen;
            if(segRem > 0)
            {
                ++curLen, --segRem;
            }
            auto curHead = head, curTail = head;
            while(curTail != nullptr && curLen > 1)
            {
                curTail = curTail->next;
                --curLen;
            }
            if (curTail != nullptr)
            {
                head = curTail->next;
                curTail->next = nullptr;
                vl[szvl ++] = curHead;
            } else 
            {
                head = nullptr;
            }
            
        }

        return vl;
    }
};
// @lc code=end

