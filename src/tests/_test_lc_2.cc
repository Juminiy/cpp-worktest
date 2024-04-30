#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_self_list_.hpp"

#include <queue>
#include <vector>
#include <functional>
#include <fstream>

#include <cassert>

__DEF_NS__(Alan::SelfList::Inst)

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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int _remain = 0, _cal = 0;
    int _l1val = 0, _l2val = 0;
    ListNode * __head_ = nullptr, * __cur_ = nullptr;
    while(l1 != nullptr || l2 != nullptr || _remain > 0)
    {   
        _l1val = (l1 != nullptr) ? l1->val : 0;
        _l2val = (l2 != nullptr) ? l2->val : 0;
        _cal = _remain + _l1val + _l2val;
        __append_list_node_(__cur_, _cal%10);
        _remain = _cal/10;

        l1 = (l1 != nullptr) ? l1->next : l1;
        l2 = (l2 != nullptr) ? l2->next : l2;

        __head_ = (__head_ == nullptr) ? __cur_ : __head_;
    }
    return __head_;
}   

// -1 1 2 3 4 5
//      |     |
//        |    
ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto __dummy_ = new ListNode(-1, head);
    auto __puppet_ = __dummy_, __stand_ = __dummy_;
    while(n--)
    {
        __puppet_ = __puppet_ -> next;
    }
    while(__puppet_ != nullptr &&
        __puppet_->next != nullptr)
    {
        __puppet_ = __puppet_ -> next;
        __stand_ = __stand_ -> next;
    }
    if (__stand_ != nullptr &&
        __stand_->next != nullptr)
        __stand_->next = __stand_->next->next;
    return __dummy_->next;
}

// -1 1 2 3 4 5
// -1->1->2->3->4->5->6->7->8
//     |     |end_next
ListNode* swapPairs(ListNode* head) {
    auto __dummy_ = new ListNode(-1, head);
    auto __prev_ = __dummy_;
    int cnt = 2;
    do{
        // seg [start, end]
        auto __start_ = __prev_->next;
        auto __end_ = __prev_;
        while(cnt && __end_ != nullptr)
        {
            __end_ = __end_->next;
            --cnt;
        }
        if(cnt > 0)
        {
            break;
        }

        auto segrv_end = __prev_->next; __prev_->next = nullptr;
        auto end_next = __end_->next; __end_->next = nullptr;
        __reverse_list_node_(__start_);
        __prev_->next = __start_;
        segrv_end->next = end_next;
        __prev_ = segrv_end;
        cnt = 2;
    }while(__prev_ != nullptr);

    return __dummy_->next;
}

ListNode* reverseList(ListNode* head) {
    __reverse_list_node_(head);
    return head;
}

__END_NS__

__USE_NS__(Alan::SelfList::Inst);
__DEF_NS__(Alan::SelfList::Inst::Test)

void TestSwapLN()
{
    // {
    //     auto ln = __make_list_node_(std::vector<int>{1, 2, 3, 4});
    //     __swap_list_node_(ln, ln->next);
    //     __log_list_node_(ln);
    // }
    {
        auto ln = __make_list_node_(std::vector<int>{1, 2, 3, 4});
        __swap_list_node_(ln, ln->next->next);
        __log_list_node_(ln);
    }
}

void TestLC206()
{
    // 1 2 3 4 -> 4 3 2 1
    __log_list_node_(
        reverseList(__make_list_node_(std::vector<int>{1, 2, 3, 4}))
    );

    // nullptr -> nullptr
    __log_list_node_(
        reverseList(nullptr)
    );

    // 1 -> 1
    __log_list_node_(
        reverseList(__make_list_node_(std::vector<int>{1}))
    );

    // 1 2 3 -> 3 2 1
    __log_list_node_(
        reverseList(__make_list_node_(std::vector<int>{1, 2, 3}))
    );
}

void TestLC24()
{
    // 1 2 3 4 -> 2 1 4 3
    __log_list_node_(
        swapPairs(__make_list_node_(std::vector<int>{1, 2, 3, 4}))
    );

    // nullptr -> nullptr
    __log_list_node_(
        swapPairs(nullptr)
    );

    // 1 2 3 -> 2 1 3
    __log_list_node_(
        swapPairs(__make_list_node_(std::vector<int>{1, 2, 3}))
    );

    // 1 -> 1
    __log_list_node_(
        swapPairs(__make_list_node_(std::vector<int>{1}))
    );

    
}

void TestLC19()
{
    __log_list_node_(
        removeNthFromEnd(nullptr, 0)
    );

    __log_list_node_(
        removeNthFromEnd(__make_list_node_(
            std::vector<int>{1}), 
            1)
    );

    __log_list_node_(
        removeNthFromEnd(__make_list_node_(
            std::vector<int>{1,2,3,4,5}), 
            2)
    );
}

void TestLC2()
{
    // 1 2 3
    // 9 7 5
    __log_list_node_(addTwoNumbers(
        __make_list_node_(std::vector<int>{1, 2, 3}),
        __make_list_node_(std::vector<int>{9, 7, 5})
    ));

    // 9 9 9 9 9 9 9
    // 9 9 9 
    __log_list_node_(addTwoNumbers(
        __make_list_node_(std::vector<int>{9,9,9,9,9,9,9}),
        __make_list_node_(std::vector<int>{9,9,9})
    ));

    __log_list_node_(addTwoNumbers(
        __make_list_node_(std::vector<int>{0}),
        __make_list_node_(std::vector<int>{0})
    ));
}

__END_NS__

#include <string>
#include <algorithm>

__USE_NS__(Alan::SelfList::Inst);
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