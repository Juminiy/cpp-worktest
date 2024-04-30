#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_self_list_.hpp"

#include <vector>
#include <stack>
#include <queue>
#include <iostream>

__USE_NS__(Alan::SelfList);
__USE_NS__(Alan::SelfList::Inst);
__less_ps_type_pointer(ListNode)

__DEF_NS__(Alan::SelfList::Inst)

bool constexpr 
ListNode::operator < (const ListNode & __rhs)
    const noexcept
{
    return this->val > __rhs.val;
}

bool __comp_list_node(ListNode* __lhs, ListNode* __rhs)
{
    return __lhs != nullptr && 
            __rhs != nullptr && 
            __lhs->val > __rhs->val;
}

void __log_list_node_(const ListNode * __head_)
{
    while(__head_ != nullptr)
    {
        PRINT(__head_->val), PRINT("->");
        __head_ = __head_->next;
    }
    PRINTLN("nullptr");
}

ListNode* __make_list_node_(const std::vector<int> & vi)
{
    ListNode *__head_ = nullptr, *__cur_ = nullptr;

    for(auto __elem : vi)
    {
        __append_list_node_(__cur_, __elem);
        if (__head_ == nullptr)
        {
        __head_ = __cur_;
        }
    }

    return __head_;
}

ListNode* __make_list_node_(ListNode * __cur_, int __val_)
{
    auto __next_ = new ListNode(__val_);
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    return __next_;
}

void __append_list_node_(ListNode * &__cur_, ListNode * &__next_)
{
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    __cur_ = __next_;
    __next_ = nullptr;
}

void __append_list_node_(ListNode * &__cur_, int __val_)
{   
    auto __next_ = new ListNode(__val_);
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    __cur_ = __next_;
}

void __fpush_list_node_(ListNode * &__cur_, ListNode * &__prev_)
{
    if(__prev_ != nullptr)
    {
        __prev_->next = __cur_;
        __cur_ = __prev_;
    }
    __prev_ = nullptr;
}

void __fpush_list_node_(ListNode * &__cur_, int __val_)
{
    auto __prev_ = new ListNode(__val_);
    __prev_->next = __cur_;
    __cur_ = __prev_;
}

void __swap_list_node_(
    ListNode * & __dest_prev_, 
    ListNode * & __src_prev_)
{   
//  |destp  |dest    
    // 1 -> 2 -> ... 
//  |srcp   |src
    // 3 -> 4 -> ...
    assert( __dest_prev_ != nullptr && 
            __src_prev_ != nullptr);
    if(__dest_prev_ == __src_prev_)
        return;

    auto __dest_ = __dest_prev_->next;
    auto __src_ = __src_prev_->next;

    __dest_prev_->next = __src_;
    __src_prev_->next = __dest_;

    if(__dest_ != nullptr && 
        __src_ != nullptr)
    {
        auto __dest_next_ = __dest_->next;
        auto __src_next_ = __src_->next;
        __src_->next = __dest_next_;
        __dest_->next = __src_next_;
    }

}

void __swap_list_node_(ListNode * & __node_prev_)
{
    // 1->2->3-> ... 
    auto __node_ = __node_prev_->next;
    if(__node_ == nullptr ||
        __node_->next == nullptr)
        return;
    

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

// remove node next
ListNode* __bocchi_list_node_(ListNode * & __node_)
{
    if(__node_ != nullptr)
    {
        auto __node_next_ = __node_->next;
        __node_->next = nullptr;
        return __node_next_;
    }
    return nullptr;
}

__END_NS__