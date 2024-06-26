#pragma once
#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <stack>
__DEF_NS__(Alan::SelfList)

template < typename _Tp >
class __tree_node_{
public:

    __DEF_ALL_V2__(__tn, __tree_node_);

    _Tp __val_;
    struct __tree_node_ * __left_;
    struct __tree_node_ * __right_;
    bool __vis_;
    struct __tree_node_ * __parent_;
    bool __color_;

    __tree_node_(_Tp __pval = _Tp(), 
            __tn_pointer __pleft = nullptr, __tn_pointer __pright = nullptr)
        : __val_(__pval),  __left_(__pleft), __right_(__pright),
            __vis_(false), __parent_(nullptr), __color_(false)
        { }
        // TODO: COMPILE ERROR
    // using _tnstk_type = std::stack<__tree_node_<_Tp> *>;
};

template < typename _Tp >
void __postorder_traverse
(__tree_node_<_Tp> * , std::vector<_Tp > & );

template < typename _Tp >
void __postorder_traverse_v2
(__tree_node_<_Tp> *, std::vector<_Tp> &);

template < typename _Tp >
void __postorder_traverse_v3
(__tree_node_<_Tp> * , std::vector<_Tp> & );

template < typename _Tp >
void __preorder_traverse
(__tree_node_<_Tp> * , std::vector<_Tp > & );

template < typename _Tp >
void __midorder_traverse
(__tree_node_<_Tp> * , std::vector<_Tp > & );

template < typename _Tp >
void __bfs_traverse
(__tree_node_<_Tp> * , std::vector<_Tp > & );

__END_NS__

__DEF_NS__(Alan::SelfList::Test)

void TestPostOrderTrav();
void TestPostOrderTravV2();
void TestPostOrderTravV3();

__END_NS__


__DEF_NS__(Alan::SelfList::Inst)
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    bool constexpr 
        operator < (const ListNode & __rhs)
        const noexcept;
};
bool __comp_list_node(ListNode * , ListNode * );
void __log_list_node_(const ListNode * );
ListNode* __make_list_node_(ListNode * , int );
ListNode* __make_list_node_(const std::vector<int> & );
void __append_list_node_(ListNode * & , ListNode * & );
void __append_list_node_(ListNode * & , int );
void __fpush_list_node_(ListNode * & , ListNode * & );
void __fpush_list_node_(ListNode * & , int );
void __swap_list_node_(ListNode * & , ListNode * & );
void __reverse_list_node_(ListNode * & );
ListNode* __bocchi_list_node_(ListNode * & );
size_t __len_list_node_(ListNode * );
ListNode* __get_nextn_list_node_(ListNode *, size_t );
void __insert_list_node_(ListNode * & , ListNode * & );

// lc functions
ListNode* mergeKLists(std::vector<ListNode*>& );
ListNode* addTwoNumbers(ListNode* , ListNode* );
ListNode* removeNthFromEnd(ListNode* , int );
ListNode* swapPairs(ListNode* );
ListNode* reverseKGroup(ListNode* , int );
ListNode* rotateRight(ListNode* , int );
ListNode* deleteDuplicates(ListNode* );
ListNode* deleteDuplicates_lc82(ListNode* );
ListNode* partition(ListNode* , int );
ListNode* reverseBetween(ListNode* , int , int );
__END_NS__

__DEF_NS__(Alan::Demos::Test::Func)
void TestRunCPU();
__END_NS__

__DEF_NS__(Alan::SelfList::Inst::Test)
void TestLC92();
void TestLC86();
void TestLC82();
void TestLC83();
void TestLC61();
void TestLC25();
void TestSwapLN();
void TestLC206();
void TestLC23();
void TestLC1143();
void TestLC2();
void TestLC19();
void TestLC24();
__END_NS__

__DEF_NS__(Alan::SelfList::Inst)

class __rb_tree_node_
{

};

class __avl_tree_node_
{

};

class __skip_list_node_
{

};

class __trie_node_
{

};

__END_NS__


__DEF_NS__(Alan::SelfList::Inst)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// not a value
#define _nav 0x7fffffff
#define _ssz 0xff

TreeNode* __make_tree_node_(int );
TreeNode* __make_tree_node_bfs_(const std::vector<int> &, size_t __msz = 7);
TreeNode* __make_tree_node_bfss_(const std::vector<std::vector<int>> &);
void __trav_tree_node_postorder_(TreeNode *, std::vector<int> &);
void __trav_tree_node_midorder_(TreeNode *, std::vector<int> &);
void __trav_tree_node_preorder_(TreeNode *, std::vector<int> &);
void __trav_tree_node_bfs_(TreeNode *, std::vector<int> &);
void __trav_tree_node_bfss_(TreeNode * , std::vector<std::vector<int>> & );

#define SHOW_TREE_NODE_PRE 0
#define SHOW_TREE_NODE_MID 1
#define SHOW_TREE_NODE_POST 2
#define SHOW_TREE_NODE_BFS 3
#define SHOW_TREE_NODE_BFSS 4
void __log_tree_node_(TreeNode *, int = SHOW_TREE_NODE_PRE);

TreeNode* __build_tree_node_of_pre_mid_(const std::vector<int> &, const std::vector<int> &);
TreeNode* __build_tree_node_of_mid_post_(const std::vector<int> &, const std::vector<int> &);

// lc function
std::vector<int> inorderTraversal(TreeNode* );

// local test
void TestTreeNodeBase();
void TestTreeNodeBuild();

__END_NS__

__DEF_NS__(Alan::SelfList::Inst::LikeOf)

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right)
        : val(_val), left(_left), right(_right), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


Node* connect(Node* root);

// lc of
void TestLC116();

__END_NS__