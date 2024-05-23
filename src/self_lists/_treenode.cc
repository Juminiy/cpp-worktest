#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_self_list_.hpp"

#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <deque>

__DEF_NS__(Alan::SelfList)

template < typename _Tp >
void __postorder_traverse
(__tree_node_<_Tp> * __tn, std::vector<_Tp > & __rv)
{
    if(!__tn)
        return;
    auto _tstk = std::stack<__tree_node_<_Tp> *>();
    _tstk.push(__tn);

    while(!_tstk.empty())
    {
        auto _cur_tmp = _tstk.top(); _tstk.pop();
        if(_cur_tmp)
        {
            if(_cur_tmp->__vis_)
            {
            __rv.push_back(_cur_tmp->__val_);
            }
            else
            {
                _cur_tmp->__vis_ = true;
                _tstk.push(_cur_tmp);
                _tstk.push(_cur_tmp->__right_);
                _tstk.push(_cur_tmp->__left_);
            }
        }

    }
}

template < typename _Tp >
void __postorder_traverse_v2
(__tree_node_<_Tp> * __tn, std::vector<_Tp> & __rv)
{
    using tstack_type = std::stack<__tree_node_<_Tp> *>;
    auto _tstk = tstack_type();
    auto _fstk = tstack_type();

    if(__tn != nullptr)
        _tstk.push(__tn);
    
    while(!_tstk.empty())
    {
        __tn = _tstk.top(); _tstk.pop();
        _fstk.push(__tn);
        if(__tn->__left_ != nullptr)
            _tstk.push(__tn->__left_);
        if(__tn->__right_ != nullptr)
            _tstk.push(__tn->__right_);
    }

    while(!_fstk.empty())
    {
        __tn = _fstk.top(); _fstk.pop();
        __rv.push_back(__tn->__val_);
    }
}

template < typename _Tp >
void __postorder_traverse_v3
(__tree_node_<_Tp> * __tn, std::vector<_Tp> & __rv)
{
    using tstack_type = std::stack<__tree_node_<_Tp> *>;
    auto _tstk = tstack_type();
    auto _fstk = tstack_type();

    while(__tn || !_tstk.empty())
    {
        while(__tn)
        {
        _fstk.push(__tn);
        _tstk.push(__tn);
        __tn = __tn->__right_;
        }
        
        if(!_tstk.empty())
        {
            __tn = _tstk.top(); _tstk.pop();
            __tn = __tn->__left_;
        }
    }

    while(!_fstk.empty())
    {
        __tn = _fstk.top(); _fstk.pop();
        __rv.push_back(__tn->__val_);
    }
}

template < typename _Tp >
void __preorder_traverse
(__tree_node_<_Tp> * __tn, std::vector<_Tp > & __rv)
{
    if(!__tn)
        return;
    auto _tstk = std::stack<__tree_node_<_Tp> *>();

    while(__tn || !_tstk.empty())
    {
        while(__tn)
        {
        __rv.push_back(__tn->__val_);
        _tstk.push(__tn);
        __tn = __tn->__left_;
        }
        
        if(!_tstk.empty())
        {
            __tn = _tstk.top(); _tstk.pop();
            __tn = __tn->__right_;
        }
    }
}

template < typename _Tp >
void __midorder_traverse
(__tree_node_<_Tp> * __tn, std::vector<_Tp > & __rv)
{
    if(!__tn)
        return;
    auto _tstk = std::stack<__tree_node_<_Tp> *>();

    while(__tn || !_tstk.empty())
    {
        while(__tn)
        {
        _tstk.push(__tn);
        __tn = __tn->__left_;
        }
        
        if(!_tstk.empty())
        {
            __tn = _tstk.top(); _tstk.pop();
            __rv.push_back(__tn->__val_);
            __tn = __tn->__right_;
        }
    }   

}

template < typename _Tp >
void __bfs_traverse
(__tree_node_<_Tp> * __tn, std::vector<_Tp > & __rv)
{
    if(!__tn)
        return;
    auto _tque = std::queue<__tree_node_<_Tp> *>();
    _tque.push(__tn);

    while(!_tque.empty())
    {
        __tn = _tque.front(); _tque.pop();
        if(__tn)
        {
            __rv.push_back(__tn->__val_);
            _tque.push(__tn->__left_);
            _tque.push(__tn->__right_);
        }
    }

}

__END_NS__


__USE_NS__(Alan::SelfList);
__DEF_NS__(Alan::SelfList::Test)

template < typename _Tp >
__tree_node_< _Tp >* __make_demo_tree()
{   
    /* 
        1
       / \
     2    3
    / \  / \
   4  5 6  7
    */
    using __i32_tn = __tree_node_<int >;
    auto _t6 = new __i32_tn(7);
    auto _t5 = new __i32_tn(6);
    auto _t4 = new __i32_tn(5);
    auto _t3 = new __i32_tn(4);
    auto _t2 = new __i32_tn(3, _t5, _t6);
    auto _t1 = new __i32_tn(2, _t3, _t4);
    auto _t = new __i32_tn(1, _t1, _t2);
    return _t;
}

void TestPostOrderTravV3()
{
    auto _t = __make_demo_tree<int >();
    auto _vi = std::vector<int >();
    _vi.reserve(1<<8);
    __postorder_traverse_v3<int>(_t, _vi);
    Alan::ConsoleBeautyOutput(_vi);
}

void TestPostOrderTravV2()
{
    auto _t = __make_demo_tree<int >();
    auto _vi = std::vector<int >();
    _vi.reserve(1<<8);
    __postorder_traverse_v2<int>(_t, _vi);
    Alan::ConsoleBeautyOutput(_vi);
}

void TestPostOrderTrav()
{
    auto _t = __make_demo_tree<int >();
    auto _vi = std::vector<int >();
    _vi.reserve(1<<8);
    __postorder_traverse(_t, _vi);
    // __preorder_traverse(_t, _vi);
    // __midorder_traverse(_t, _vi);
    // __bfs_traverse<int >(_t, _vi);
    Alan::ConsoleBeautyOutput(_vi);
}

__END_NS__


__DEF_NS__(Alan::SelfList::Inst)

std::vector<int> 
inorderTraversal(TreeNode* root) 
{
    auto vi = std::vector<int>();
    vi.reserve(101);
    __trav_tree_node_midorder_(root, vi);
    return vi;
}

void TestTreeNodeBuild()
{
    __log_tree_node_(__build_tree_node_of_pre_mid_(
        {3,9,20,15,7},
        {9,3,15,20,7}), SHOW_TREE_NODE_POST);
    
    __log_tree_node_(__build_tree_node_of_mid_post_(
        {9,3,15,20,7},
        {9,15,7,20,3}), SHOW_TREE_NODE_POST);
}

/* 
        1                     1
       / \                   / \
     2    3                 2   _
    / \  / \               / \ 
   4  5 6   7             4   5
*/ 
// bfs: 1 2 3 4 5 6 7    bfs: 1 2 4 5
// post: 4 5 2 6 7 3 1   post: 4 5 2 1
// mid: 4 2 5 1 6 3 7    mid: 4 2 5 1
// pre: 1 2 4 5 3 6 7    pre: 1 2 4 5
void TestTreeNodeBase()
{   
    auto t1 = __make_tree_node_bfs_({1,2,3,4,5,6,7});
    auto t2 = __make_tree_node_bfs_({1,2,_nav,4,5});
    auto t3 = __make_tree_node_bfs_({}, 8);

    #define __logvi Alan::ConsoleBeautyOutput(vi);
    auto vi = std::vector<int>(); 

    vi.clear(); __trav_tree_node_bfs_(t1,vi);__logvi
    vi.clear(); __trav_tree_node_bfs_(t2,vi);__logvi
    vi.clear(); __trav_tree_node_bfs_(t3,vi);__logvi

    vi.clear(); __trav_tree_node_postorder_(t1,vi);__logvi
    vi.clear(); __trav_tree_node_postorder_(t2,vi);__logvi
    vi.clear(); __trav_tree_node_postorder_(t3,vi);__logvi

    vi.clear(); __trav_tree_node_midorder_(t1,vi);__logvi
    vi.clear(); __trav_tree_node_midorder_(t2,vi);__logvi
    vi.clear(); __trav_tree_node_midorder_(t3,vi);__logvi

    vi.clear(); __trav_tree_node_preorder_(t1,vi);__logvi
    vi.clear(); __trav_tree_node_preorder_(t2,vi);__logvi
    vi.clear(); __trav_tree_node_preorder_(t3,vi);__logvi
}

TreeNode* __make_tree_node_(int val)
{
    if(val != _nav)
        return new TreeNode(val);
    else 
        return nullptr;
}

/* 
        1
       / \
     2    3
    / \  / \
   4  5 6   7
*/ 
// bfs: 1 2 3 4 5 6 7
TreeNode* __make_tree_node_bfs_(const std::vector<int> & __seq, size_t __msz)
{
    TreeNode * root = nullptr;
    auto tq = std::queue<TreeNode*>();

    #define __toend(__curi, __sz) \
            if(__curi == __sz) break

    #define __mktree(__expr, __sz) \
            do { \
                size_t curi = 0, sz = __sz; \
                TreeNode * curm =__make_tree_node_(__expr); __toend(curi, sz); \
                TreeNode *curl =nullptr, *curr =nullptr; \
                tq.push(curm);  root = curm; \
                do { \
                curm = tq.front(); \
                curl = __make_tree_node_(__expr); __toend(curi, sz); \
                curr = __make_tree_node_(__expr); __toend(curi, sz); \
                curm->left = curl, curm->right = curr, tq.pop(); \
                if(curl != nullptr) \
                    tq.push(curl); \
                if(curr != nullptr) \
                    tq.push(curr); \
                curl = nullptr, curr = nullptr; \
                }while(curi < sz); \
                if(curm != nullptr) \
                    curm->left = curl, curm->right = curr; \
            }while(0)

    if(__seq.size() > 0)
    {
        __mktree(__seq[curi++], __seq.size());
    } else if(__msz > 0) 
    {
        __mktree(curi++, __msz);
    }

    return root;
}

TreeNode* __make_tree_node_bfss_(const std::vector<std::vector<int>> & __sseq)
{
    return nullptr;
}

void __trav_tree_node_postorder_(TreeNode * __root, std::vector<int> & _vi)
{
    auto tstk = std::stack<TreeNode*>();
    auto fstk = std::stack<TreeNode*>();

    if(__root != nullptr)
        tstk.push(__root);
    
    while(!tstk.empty())
    {
        __root = tstk.top(); tstk.pop();
        fstk.push(__root);
        if(__root->left)
            tstk.push(__root->left);
        if(__root->right)
            tstk.push(__root->right);
    }

    while(!fstk.empty())
    {
        _vi.push_back(fstk.top()->val);
        fstk.pop();
    }
}

void __trav_tree_node_midorder_(TreeNode * __root, std::vector<int> & _vi)
{
    auto tstk = std::stack<TreeNode*>();

    while(__root !=nullptr || !tstk.empty())
    {
        while(__root != nullptr)
        {
            tstk.push(__root);
            __root = __root->left;
        }
        if(!tstk.empty())
        {
            __root = tstk.top(); tstk.pop();
            _vi.push_back(__root->val);
            __root = __root->right;
        }
    }

}

void __trav_tree_node_preorder_(TreeNode * __root, std::vector<int> & _vi)
{
    auto tstk = std::stack<TreeNode*>();

    while(__root !=nullptr || !tstk.empty())
    {
        while(__root != nullptr)
        {
            tstk.push(__root);
            _vi.push_back(__root->val);
            __root = __root->left;
        }
        if(!tstk.empty())
        {
            __root = tstk.top(); tstk.pop();
            __root = __root->right;
        }
    }
}

void __trav_tree_node_bfs_(TreeNode * __root, std::vector<int> & _vi)
{
    auto tq = std::queue<TreeNode*>();
    if(__root != nullptr)
        tq.push(__root);

    // _vi.reserve(_ssz);
    while(!tq.empty())
    {
        __root = tq.front(); tq.pop();
        _vi.push_back(__root->val);
        if(__root->left)
            tq.push(__root->left);
        if(__root->right)
            tq.push(__root->right);
    }
}

void __trav_tree_node_bfss_(TreeNode * __root, std::vector<std::vector<int>> & _vi)
{
    auto tq1 = std::queue<TreeNode*>();

    if(__root != nullptr)
        tq1.push(__root);
    
    while(!tq1.empty())
    {
        auto tq2 = std::queue<TreeNode*>();
        auto tvi = std::vector<int>();
        while(!tq1.empty())
        {
            __root = tq1.front(); tq1.pop();
            tvi.push_back(__root->val);
            if(__root->left)
                tq2.push(__root->left);
            if(__root->right)
                tq2.push(__root->right);
        }
        tq1 = std::move(tq2);
        _vi.push_back(std::move(tvi));
    }
}


void __log_tree_node_(TreeNode * tn, int smod)
{   
    auto vi = std::vector<int>();
    auto vvi UNUSED = std::vector<std::vector<int>>();
    switch (smod)
    {
    case SHOW_TREE_NODE_PRE:
        __trav_tree_node_preorder_(tn, vi);
        break;
    case SHOW_TREE_NODE_MID:
        __trav_tree_node_midorder_(tn, vi);
        break;
    case SHOW_TREE_NODE_POST:
        __trav_tree_node_postorder_(tn, vi);
        break;
    case SHOW_TREE_NODE_BFS:
        __trav_tree_node_bfs_(tn, vi);
        break;
    case SHOW_TREE_NODE_BFSS:

        break;
    }
    if(smod == SHOW_TREE_NODE_BFSS) {
        Alan::ConsoleBeautyOutputEmbedded2(vvi);
    } else if(I32_IN_RANGE(smod, SHOW_TREE_NODE_PRE, SHOW_TREE_NODE_BFS)) {
        Alan::ConsoleBeautyOutput(vi);
    }
}

/*  
        3
       / \ 
      9   20 
     / \ /  \ 
    _  _ 15  7
*/      

// 3,9,20,15,7
//   |
// 9,3,15,20,7

TreeNode* __pre_mid_seq_build_helper
(const std::vector<int> & pre_vec, size_t preL, size_t preR,
const std::vector<int> & mid_vec, size_t midL, size_t midR)
{
    if(preL > preR || preL == pre_vec.size() || midL == mid_vec.size())
        return nullptr;
    
    auto __root_ = new TreeNode(pre_vec[preL]);
    size_t __mdis_ = 
        std::find(mid_vec.begin()+midL, mid_vec.begin()+midR+1, pre_vec[preL]) 
            - mid_vec.begin();       // 1
    size_t __llen_ = __mdis_ - midL; // 1 - 0 = 1
    // size_t __rlen_ = midR - __mdis_; // 4 - 1 = 3

    __root_->left = __pre_mid_seq_build_helper
                    (pre_vec, preL+1, preL+1+__llen_-1, // _, 1, 1 
                    mid_vec, midL, midL+__llen_-1);     // _, 0, 0
    
    __root_->right = __pre_mid_seq_build_helper
                    (pre_vec, preL+1+__llen_, preR,     // _, 2, 4
                    mid_vec, __mdis_+1, midR);          // _, 2, 4
    
    return __root_;
}

TreeNode* __build_tree_node_of_pre_mid_
(const std::vector<int> & pre_vec, const std::vector<int> & mid_vec)
{
    return __pre_mid_seq_build_helper
            (pre_vec, 0, pre_vec.size()-1,
            mid_vec, 0, mid_vec.size()-1);

}

//   |
// 9,3,15,20,7

//           |
// 9,15,7,20,3
TreeNode* __mid_post_seq_build_helper
(const std::vector<int> & mid_vec, size_t midL, size_t midR,
const std::vector<int> & post_vec, size_t posL, size_t posR)
{
    // PRINT_DETAIL(midL),PRINT(", "),PRINT_DETAIL(midR),PRINT(", "),
    // PRINT_DETAIL(posL),PRINT(", "),PRINT_DETAIL(posR),PRINTLN("");
    size_t maxsz = mid_vec.size();
    if(posL > posR || 
        midL < 0 || posL == maxsz || 
        posL < 0 || posR == maxsz)
        return nullptr;

    auto __root_ = new TreeNode(post_vec[posR]);

    size_t __mdis_ = 
        std::find(mid_vec.begin()+midL, mid_vec.begin()+midR+1, post_vec[posR]) 
            - mid_vec.begin();       // 1
    size_t __llen_ = __mdis_ - midL; // 1 - 0 = 1
    // size_t __rlen_ = midR - __mdis_; 

    if(I32_IN_RANGE(midL+__llen_-1, midL, midR)&&
        I32_IN_RANGE(posL+__llen_-1, posL, posR))
    __root_->left = __mid_post_seq_build_helper
                    (mid_vec, midL, midL+__llen_-1,     // _, 0, 0 
                    post_vec, posL, posL+__llen_-1);    // _, 0, 0
    
    if(I32_IN_RANGE(__mdis_+1, midL, midR)&&
        I32_IN_RANGE(posL+__llen_, posL, posR))
    __root_->right = __mid_post_seq_build_helper
                    (mid_vec, __mdis_+1, midR,           // _, 2, 4
                    post_vec, posL+__llen_, posR-1);     // _, 1, 3
    
    return __root_;
}

TreeNode* __build_tree_node_of_mid_post_
(const std::vector<int> & mid_vec, const std::vector<int> & post_vec)
{
    return __mid_post_seq_build_helper
            (mid_vec, 0, mid_vec.size()-1,
            post_vec, 0, post_vec.size()-1);
}

__END_NS__


__DEF_NS__(Alan::SelfList::Inst::LikeOf)

Node* connect(Node* root)
{
    auto nq = std::queue<Node*>();
    #define __pushq_(__q_, __node_) \
            if(__node_ != nullptr) __q_.push(__node_)
    
    __pushq_(nq, root);
    while(!nq.empty())
    {
        auto tq = decltype(nq)();
        auto prev = decltype(root)(nullptr);
        while(!nq.empty())
        {
            auto tt = nq.front(); nq.pop();
            if(prev != nullptr)
                prev->next = tt;
            
            prev = tt;
            __pushq_(tq, tt->left);
            __pushq_(tq, tt->right);
        }
        nq = std::move(tq);
    }

    return root;
}

void TestLC116()
{
    auto tNode7 = new Node(7);
    auto tNode6 = new Node(6);
    auto tNode5 = new Node(5);
    auto tNode4 = new Node(4);
    auto tNode3 = new Node(3, tNode6, tNode7);
    auto tNode2 = new Node(2, tNode4, tNode5);
    auto tNode = new Node(1, tNode2, tNode3);
    connect(tNode);
}

__END_NS__