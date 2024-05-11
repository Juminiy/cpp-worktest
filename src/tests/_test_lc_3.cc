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


__USE_NS__(Alan::SelfList::Inst);
__DEF_NS__(Alan::Inst::LC)


bool is_valid_bst(TreeNode * cur, TreeNode * fa)
{
    return false;
}

bool isValidBST(TreeNode* root) {
    
    auto tstk = std::stack<TreeNode*>();
    long long prevVal = -2147483649;
    while(root !=nullptr || !tstk.empty())
    {
        while(root != nullptr)
        {
            tstk.push(root);
            root = root->left;
        }
        if(!tstk.empty())
        {
            root = tstk.top(); tstk.pop();
            if(root->val < prevVal)
                return false;
            else 
                prevVal = root->val;
            root = root->right;
        }
    }
    
    return true;
}

/*
    2       3
   / \     / \ 
  1   _   
*/

// 1(_ _)
// 2(1 _)
// 3(2, )

// [n n+1 n+2 n+count)
// 1 2 3 4
// 
// TreeNode* genTreeHelper
// (int n, int count, int maxn, std::unordered_multimap<int, TreeNode*> & htree)
// {
//     if(n<=0 || count <=0)
//         return nullptr;
//     else if(count == 1)
//         return new TreeNode(n);

//     for(int rootI = n; rootI < n+count; ++rootI)
//     {
//         genTreeHelper(1, rootI-1, maxn, htree);
//         genTreeHelper(rootI+1, maxn-rootI, maxn, htree);
//     }


// }

std::vector<TreeNode*> genTHelper(int start, int end){
    if(start > end)
        return { nullptr };
    
    auto tVec = std::vector<TreeNode*>();
    for(int i = start; i <= end; ++i)
    {
        auto lVec = genTHelper(start, i-1);
        auto rVec = genTHelper(i+1, end);

        tVec.reserve(lVec.size() * rVec.size());
        for(auto & lElem : lVec)
        {
            for(auto & rElem : rVec)
            {
                auto tElem = new TreeNode(i);
                tElem->left = lElem;
                tElem->right = rElem;
                tVec.emplace_back(tElem);
            }
        }

    }   

    return tVec;
}

std::vector<TreeNode*> generateTrees(int n) {
    return genTHelper(1, n);
}

void TestLC95()
{
    auto genTVec = generateTrees(4);
    for(auto tn : genTVec)
    {
        auto vi = std::vector<int>();
        __trav_tree_node_midorder_(tn, vi);
        Alan::ConsoleBeautyOutput(vi);
    }
}

int numTrees(int n) {
    int f[n+1] = {1,1};
    for(int i=2;i<=n;++i)
    {
        f[i] = 0;
        for(int j=0;j<=i-1;++j)
        {
        //  f[3] left = root(0) * right = root()
            f[i] += f[j] * f[i-j-1];
        }
    }
    return f[n];
}

void TestLC96()
{
    for(int i =1;i<=19;i++)
        PRINTLN_DETAIL(numTrees(i));
}

ListNode* insertionSortList(ListNode* head) {
    std::vector<int> vi;
    vi.reserve(5000);
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

// 1 2 3 4   slow = 
// 1 2 3 4 5
void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode * __dummy_ = new ListNode(-1, head);
    auto fast = __dummy_, slow = __dummy_, prev = __dummy_;

    #define __toend(__node_) \
            if(__node_ == nullptr) break
    int n = 0;
    while(fast != nullptr)
    {
        prev = slow;
        slow = slow->next; __toend(slow);
        fast = fast->next; __toend(fast); ++n;
        fast = fast->next; __toend(fast); ++n;
    }
    auto seg1 = head, seg2 = head;
    if(n%2 == 0)
    {
        prev->next = nullptr;
        seg2 = slow;
    } else 
    {
        seg2 = slow->next;
        slow->next = nullptr;
    }

    // rev seg2
    __reverse_list_node_(seg2);

    auto seg2Tail = seg2, seg1Tail = seg1;
    // merge seg1 seg2

    while(seg2Tail != nullptr)
    {
        auto elem2 = seg2Tail; 
        seg2Tail = seg2Tail->next; 
        elem2->next = nullptr;

        if(seg1Tail != nullptr)
        {
            elem2->next = seg1Tail->next;
            seg1Tail->next = elem2;
            seg1Tail = seg1Tail->next->next;
        }
    }
}

void TestLC143()
{   
{
    auto l1 = __make_list_node_({1, 2, 3, 4, 5});
    reorderList(l1);
    __log_list_node_(l1);
}
{
    auto l1 = __make_list_node_({1, 2, 3, 4});
    reorderList(l1);
    __log_list_node_(l1);
}
{
    auto l1 = __make_list_node_({1});
    reorderList(l1);
    __log_list_node_(l1);
}
{
    auto l1 = __make_list_node_({});
    reorderList(l1);
    __log_list_node_(l1);
}
}


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

void TestLC328()
{
    __log_list_node_(oddEvenList(__make_list_node_({})));
    __log_list_node_(oddEvenList(__make_list_node_({1})));
    __log_list_node_(oddEvenList(__make_list_node_({1,2})));
    __log_list_node_(oddEvenList(__make_list_node_({1,2,3})));
    __log_list_node_(oddEvenList(__make_list_node_({1,2,3,4})));
    __log_list_node_(oddEvenList(__make_list_node_({1,2,3,4,5})));
}

// null
// 1
// 1 2 3 4 slow = 3
// 1 2 3 4 5 slow = 3 
bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return true;
    auto __dummy_ = new ListNode(-1, head);
    auto slow = __dummy_, fast = __dummy_;
    ListNode *prev = nullptr;
    int n = 0;
    do {
        prev = slow;
        slow = slow->next; 
        fast = fast->next; if(fast == nullptr) break; ++ n;
        fast = fast->next; if(fast == nullptr) break; ++ n;
    }while(fast != nullptr);

    ListNode * seg1 = __dummy_->next, *seg2 = nullptr;
    if(n%2 == 0)
    {
        seg2 = slow;
        prev->next = nullptr;
    } else 
    {
        seg2 = slow->next;
        slow->next = nullptr;
    }
    __reverse_list_node_(seg2);

    while(seg1 != nullptr && seg2 != nullptr)
    {
        if(seg1->val != seg2->val)
            return false;
        seg1 = seg1->next;
        seg2 = seg2->next;
    }

    return true;
}

void TestLC234()
{
    PRINTLN(isPalindrome(__make_list_node_({})));
    PRINTLN(isPalindrome(__make_list_node_({1})));
    PRINTLN(isPalindrome(__make_list_node_({1,1,2,1})));
    PRINTLN(isPalindrome(__make_list_node_({1,2,3,4,5})));
    PRINTLN(isPalindrome(__make_list_node_({1,2,2,1})));
    PRINTLN(isPalindrome(__make_list_node_({1,2,3,2,1})));
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

    fast = __dummy_;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return fast;
}

void TestLC142()
{
    
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