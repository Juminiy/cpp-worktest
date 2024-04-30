#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_self_list_.hpp"

#include <vector>
#include <stack>
#include <queue>

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