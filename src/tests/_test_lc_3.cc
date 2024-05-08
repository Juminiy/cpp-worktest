#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_3.hpp"

#include "../../include/_self_list_.hpp"

#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <deque>
#include <vector>

// 1 2 3 2 1
__USE_NS__(Alan::SelfList::Inst);
__DEF_NS__(Alan::Inst::LC)

bool isPalindrome(ListNode* head) {
    
    return false;
}

void TestLC234()
{
    isPalindrome(__make_list_node_({1,1,2,1}));
}

// eg.
// l = 20 c = 2
// slow walk 20 = 20, fast walk 40 = 20+10*2

// eg.
// l = 20, c = 3
// 2a = kc+a 
// slow walk 

// total = l + c 
// fast walk l+kc (k>=1)
// slow walk l
// TODO: need to solve: self thought
ListNode *detectCycle(ListNode *head) {
    auto __dummy_ = new ListNode(-1, head);
    ListNode *slow = __dummy_, *fast = __dummy_;

    #define __toend(__node_) \
            if(__node_ == nullptr) return nullptr

    int a = 0, c = 0;
    do {
        ++a;
        slow = slow->next; __toend(slow);
        fast = fast->next; __toend(fast); fast = fast->next; __toend(fast);
    } while (fast != slow);

    auto meet = slow;
    do {
        ++c;
        slow = slow->next;
    } while(slow != meet);
    
    return nullptr;
}

bool hasCycle(ListNode *head) {
    auto __dummy_ = new ListNode(-1, head);
    ListNode *slow = __dummy_, *fast = __dummy_;

    #define __toend(__node_) \
            if(__node_ == nullptr) return false

    do
    {
        slow = slow->next; __toend(slow);
        fast = fast->next; __toend(fast); fast = fast->next; __toend(fast);
    } while (fast != slow);
    
    return fast == slow;
}

Node* copyRandomList(Node* head) {
    auto old2New = std::unordered_map<Node*, Node*>();
    Node *cur = nullptr, *newHead = nullptr;
    Node *trav = nullptr;

    auto __append_node_ = 
        [&cur, &newHead](Node * newNode) {
            if(cur != nullptr)
                cur->next = newNode;
            cur = newNode;

            if(newHead == nullptr)
                newHead = cur;
        };

    trav = head;
    while(trav != nullptr)
    {   
        auto newNode = new Node(trav->val);
        __append_node_(newNode);
        old2New[trav] = newNode;
        trav = trav->next;
    }

    trav = head;
    while(trav != nullptr)
    {
        if(trav->random != nullptr)
        {
            old2New[trav]->random = 
                old2New[trav->random];
        }
        trav = trav->next;
    }

    return newHead;
}

int lengthOfLongestSubstring(std::string s) {
    auto loc = std::unordered_map<char, size_t>();
    size_t maxl = 0;
    auto pop_index = 
        [&loc](size_t index) 
        {
            for(auto it = loc.begin(); it != loc.end(); )
            {
            if(it->second <= index)
                it = loc.erase(it);
            else 
                ++it;
            } 
        };
    for(size_t i = 0; i < s.size(); ++ i )
    {
        if(loc.find(s[i]) != loc.end())
        {
            pop_index(loc[s[i]]);
        } 
        loc[s[i]] = i;
        maxl = std::max(maxl, loc.size());
    }

    return maxl;
}

/// @brief buggy
/// @param s 
/// @return 
int lengthOfLongestSubstring_v2(std::string s) {
    auto charEx = std::unordered_set<char>();
    size_t segl = 0, segr = 0, maxl = 0;
    size_t szs = s.size();
    while(segl < szs)
    {
        while(segr < szs && !charEx.count(s[segr]))
        {
            charEx.insert(s[segr]);
            ++segr;
        }
        maxl = std::max(maxl, segr-segl);
        segl = segr, segr++;
    }

    return static_cast<int>(maxl);
}

void TestLC3()
{
    PRINTLN(lengthOfLongestSubstring_v2("abcabcbb"));  // 3
    PRINTLN(lengthOfLongestSubstring_v2("bbbbb"));     // 1
    PRINTLN(lengthOfLongestSubstring_v2("pwwkew"));    // 3
    PRINTLN(lengthOfLongestSubstring_v2("dvdf"));      // 3
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    auto numSet = std::unordered_map<int, size_t>();

    for(size_t i = 0; i < nums.size(); ++i)
        numSet.insert(std::make_pair(nums[i], i));

    for(size_t i = 0; i < nums.size(); ++i)
    {
        if(numSet.find(target-nums[i]) != numSet.end())
        {
            auto j = numSet[target-nums[i]];
            if ( i != j )
            return {static_cast<int>(i), static_cast<int>(j)}; 
        }
    }

    return {-1, -1};
}

void TestLC1()
{   
    auto v1 = std::vector<int>{2, 7, 11, 15};
    Alan::ConsoleBeautyOutput(twoSum(v1, 9));
    auto v2 = std::vector<int>{3, 2, 4};
    Alan::ConsoleBeautyOutput(twoSum(v2, 6));
    auto v3 = std::vector<int>{3, 3};
    Alan::ConsoleBeautyOutput(twoSum(v3, 6));
}

void TestRunLC()
{
    auto fns = std::deque<TestLCFn>();
    fns.push_back(TestLC3); fns.pop_front(); 
    fns.push_back(TestLC1); 

    while(!fns.empty())
    {
        fns.front()();
        fns.pop_front();
    }
}
__END_NS__