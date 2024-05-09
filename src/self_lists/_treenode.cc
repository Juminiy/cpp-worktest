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

__END_NS__