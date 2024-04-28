#pragma once
#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

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
};

template < typename _Tp >
void __postorder_traverse
(__tree_node_<_Tp> * , std::vector<_Tp > & );

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