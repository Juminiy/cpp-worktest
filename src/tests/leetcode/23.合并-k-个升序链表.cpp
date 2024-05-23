/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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

namespace std {
template<>
    struct less<ListNode*> {
        bool operator()(ListNode* __lhs, ListNode* __rhs) const {
            return __lhs != nullptr && 
                    __rhs != nullptr && 
                    __lhs->val > __rhs->val;
        }
    };
};
class Solution {
public:

void __append_list_node_(ListNode * &__cur_, ListNode * &__next_)
{
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    __cur_ = __next_;
    __next_ = nullptr;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    auto pq = std::priority_queue<ListNode*>();
    for(auto __list : lists)
    {
        if(__list != nullptr)
            pq.push(std::move(__list));
    }
    ListNode * __cur_ = nullptr, * __head_ = nullptr;
    while(!pq.empty())
    {
        auto __top_ = pq.top(); pq.pop();
        auto __top_next_ = __top_->next;
        __append_list_node_(__cur_, __top_);
        if (__top_next_ != nullptr)
        {
            pq.push(__top_next_);
        }

        if(__head_ == nullptr) 
        {
            __head_ = __cur_;
        }
    }
    return __head_;

}
};
// @lc code=end

