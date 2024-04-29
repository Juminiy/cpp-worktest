#include <queue>
#include <vector>
#include <functional>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* __make_list_node_(ListNode * __cur_, int __val_)
{
    auto __next_ = new ListNode(__val_);
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    return __next_;
}

void __log_list_node_(const ListNode * __head_)
{
    while(__head_ != nullptr)
    {
        std::cout << __head_->val << "->";
        __head_ = __head_->next;
    }
   std::cout << "nullptr\n";
}

// namespace std{
//     template<>
//     struct less<ListNode*> {
//         bool operator()(ListNode* __lhs, ListNode* __rhs) const {
//             return __lhs != nullptr && 
//                     __rhs != nullptr && 
//                     __lhs->val > __rhs->val;
//         }
//     };
// };

void __append_list_node_(ListNode * &__cur_, ListNode * &__next_)
{
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    __cur_ = __next_;
    __next_ = nullptr;
}

constexpr bool 
__comp_list_node(ListNode* __lhs, ListNode* __rhs)
noexcept
{
    return __lhs != nullptr && 
            __rhs != nullptr && 
            __lhs->val > __rhs->val;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    auto pq = 
        std::priority_queue<ListNode*>
            (std::less<ListNode>(__comp_list_node));
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

void TestLC23()
{
    auto lists = std::vector<ListNode *>();
    for(int i = 6; i < 17; i++){
        auto l2 = new ListNode(i);
        auto l1 = new ListNode(i >> 1, l2);
        lists.push_back(l1);
    }

    __log_list_node_(mergeKLists(lists));
    lists.clear();
    __log_list_node_(mergeKLists(lists));
    for(int i = 5; i < 18; i++){
        lists.push_back(nullptr);
    }
    __log_list_node_(mergeKLists(lists));
}



int main()
{
TestLC23();
return 0;
}