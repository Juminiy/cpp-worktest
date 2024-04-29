#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_self_list_.hpp"

#include <queue>
#include <vector>
#include <functional>
#include <fstream>

#include <cassert>

__USE_NS__(Alan::SelfList::Inst);

bool constexpr 
ListNode::operator < (const ListNode & __rhs)
    const noexcept
{
    return this->val > __rhs.val;
}

__less_ps_type_pointer(ListNode);

__DEF_NS__(Alan::SelfList::Inst)

// bool __comp_list_node(ListNode* __lhs, ListNode* __rhs)
// {
//     return __lhs != nullptr && 
//             __rhs != nullptr && 
//             __lhs->val > __rhs->val;
// }

// ListNode* __make_list_node_(ListNode * __cur_, int __val_)
// {
//     auto __next_ = new ListNode(__val_);
//     if(__cur_ != nullptr)
//     {
//         __cur_->next = __next_;
//     }
//     return __next_;
// }

void __append_list_node_(ListNode * &__cur_, ListNode * &__next_)
{
    if(__cur_ != nullptr)
    {
        __cur_->next = __next_;
    }
    __cur_ = __next_;
    __next_ = nullptr;
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
}

__END_NS__

#include <string>
#include <algorithm>

__DEF_NS__(Alan::SelfList::Inst::Test)

int lcsdfs(const std::string & s, const std::string & t)
{
    size_t szs = s.size(), szt = t.size();
    if (szs == 0 || szt == 0)
    {
        return 0;
    } else if(szs == 1 && szt == 1)
    {
        return static_cast<int>(s[0] == t[0]);
    }

    if(s[szs-1] == t[szt-1])
    {
        return lcsdfs(s.substr(0, szs-1), t.substr(0, szt-1)) + 1;
    } else 
    {
        return std::max(
            lcsdfs(s.substr(0, szs-1), t.substr(0, szt)),
            lcsdfs(s.substr(0, szs), t.substr(0, szt-1))
        );
    }

}

int lcsmemdfs(
    const std::string & s, const std::string & t, 
std::vector<std::vector<int> > & _mem)
{
    size_t szs = s.size(), szt = t.size();
    if (szs == 0 || szt == 0)
    {
        return 0;
    } 
    if (_mem[szs-1][szt-1])
    {
        return _mem[szs-1][szt-1];
    }

    if(s[szs-1] == t[szt-1])
    {
        return _mem[szs-1][szt-1] =  
            lcsmemdfs(s.substr(0, szs-1), t.substr(0, szt-1), _mem) + 1;
    } else 
    {
        auto t0 = lcsmemdfs(s.substr(0, szs-1), t.substr(0, szt), _mem);
        auto t1 = lcsmemdfs(s.substr(0, szs), t.substr(0, szt-1), _mem);
        if (szs >= 2)
            _mem[szs-2][szt-1] = t0;
        if (szt >= 2)
            _mem[szs-1][szt-2] = t1;
        return std::max(t0, t1);
    }

}

// int longestCommonSubsequence(std::string text1, std::string text2) {
//     // return lcsdfs(text1, text2);
//     auto vvi = std::vector<std::vector<int>>
//         (text1.size(), std::vector<int>(text2.size(), 0));
//     return lcsmemdfs(text1, text2, vvi);
// }

int longestCommonSubsequencev1(std::string text1, std::string text2) {
    return lcsdfs(text1, text2);
}

int longestCommonSubsequencev2(std::string text1, std::string text2) {
    auto vvi = std::vector<std::vector<int>>
        (text1.size(), std::vector<int>(text2.size(), 0));
    return lcsmemdfs(text1, text2, vvi);
}

int longestCommonSubsequence
(std::string text1, std::string text2) {
    auto vvi = std::vector<std::vector<int>>
        (text1.size(), std::vector<int>(text2.size(), 0));
    for(size_t i = 0; i < vvi.size(); ++i)
    {
        for(size_t j = 0; j < vvi[i].size(); ++j)
        {
        if(text1[i] == text2[j]){
            vvi[i][j] = (i && j) ? vvi[i-1][j-1] + 1 : 1;
        } else{
            vvi[i][j] = std::max(
                i ? vvi[i-1][j] : 0, 
                j ? vvi[i][j-1] : 0
            );
        } 

        }
    }
    return vvi[text1.size()-1][text2.size()-1];
}

void TestLC1143()
{
    auto ofs = std::fstream("test/static-file/lc1143_example.txt");
    auto _s1 = std::string();
    auto _s2 = std::string();
    ofs >> _s1 >> _s2;
    if (ofs.fail())
    {
        _COLOR_START(_COLOR_RED);
        ERRLN("file stream error");
        _COLOR_RECOVER;
        assert(0);
    } else 
    {
        _COLOR_START(_COLOR_CYAN);
        PRINTLN("read string data from file");
        _COLOR_RECOVER;
    }
    // PRINTLN_DETAIL(Alan::__time_count_(
    //     longestCommonSubsequencev1, 
    //     _s1,
    //     _s2));
    PRINTLN_DETAIL(Alan::__time_count_(
        longestCommonSubsequencev2, 
        _s1,
        _s2));
    PRINTLN_DETAIL(Alan::__time_count_(
        longestCommonSubsequence, 
        _s1,
        _s2));
}

__END_NS__