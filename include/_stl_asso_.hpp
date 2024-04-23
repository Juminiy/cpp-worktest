#pragma once
#ifndef _STL_ASSO_HPP
#define _STL_ASSO_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>
#include <iomanip>

#include <iterator>
#include <utility>
#include <numeric>
#include <algorithm>
#include <chrono>

#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

__DEF_NS__(Alan)

// Associative Container:

template <typename _Tp, 
            typename _Asso_Container >
bool AssoFind(const _Asso_Container &__container, 
                const _Tp &__element_key)
{
    return __container.find(__element_key) 
            != __container.cend();
}

template <typename _Tp,
            typename _Asso_Container >
size_t AssoCount(const _Asso_Container &__container,
                    const _Tp &__element_key) 
{
    return __container.count(__element_key);
}

// (_min, _max)
// v00 -> v0
template <typename _Tp,
            typename _Asso_Ordered_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
AssoRange_v0(const _Asso_Ordered_Container &__container,
                const _Tp &_min_element_key, 
                const _Tp &_max_element_key)
{
    return std::make_pair(__container.upper_bound(_min_element_key),
                            __container.lower_bound(_max_element_key));
}

// (_min, _max]
// v01 -> v1
template <typename _Tp,
            typename _Asso_Ordered_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
AssoRange_v1(const _Asso_Ordered_Container &__container,
                const _Tp &_min_element_key, 
                const _Tp &_max_element_key)
{
    return std::make_pair(__container.upper_bound(_min_element_key),
                            __container.upper_bound(_max_element_key));
}

// [_min, _max)
// v10 -> v2
template <typename _Tp,
            typename _Asso_Ordered_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
AssoRange_v2(const _Asso_Ordered_Container &__container,
                const _Tp &_min_element_key, 
                const _Tp &_max_element_key)
{
    return std::make_pair(__container.lower_bound(_min_element_key),
                            __container.lower_bound(_max_element_key));
}

// [_min, _max]
// v11 -> v3
template <typename _Tp,
            typename _Asso_Ordered_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
AssoRange_v3(const _Asso_Ordered_Container &__container,
                const _Tp &_min_element_key, 
                const _Tp &_max_element_key)
{
    return std::make_pair(__container.lower_bound(_min_element_key),
                            __container.upper_bound(_max_element_key));
}

template <typename _Asso_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
Asso_Range_all(const _Asso_Container &__container)
{
    return std::make_pair(__container.cbegin(), 
                            __container.cend());
}


// Encapsulation of AssoContainer:


// TODO: encapsulate some < _Tp >associate containers 
// to restrict the operate

// can read only by .find
template <typename _Key, typename _Val, 
            typename _Asso_Container = std::map<_Key, _Val> >
class ReadOnlyRBTree
{
// learn from back_insert_iterator
// support Golang map[k]v like interface
public:
    typedef ReadOnlyRBTree _RORBTree;
    typedef ReadOnlyRBTree & _RORBTree_Ref;
    typedef _Asso_Container * _Container_Ptr;
    typedef _Asso_Container & _Container_Ref;

    ReadOnlyRBTree(){
        this->_container_ptr = 
            new _Asso_Container;
    }

    // parameter reference constructor
    // private member variable pointer receiver
    explicit ReadOnlyRBTree
    (_Container_Ref _container_ref) : 
        _container_ptr(std::addressof(_container_ref)){}
    
    explicit ReadOnlyRBTree
    (std::initializer_list<std::pair<_Key, _Val > > &__init_list)
    noexcept;


    // operator overload
    // value cannot be modified
    bool operator|(_Key _key) const {
        return this->get_exi(_key).second;
    }

    _Val operator[](_Key _key) const{
        return this->get_val(_key);
    }
    _RORBTree_Ref operator*()       {return *this;}
    _RORBTree_Ref operator++()      {return *this;}
    _RORBTree_Ref operator++(int)   {return *this;}

private:
    _Container_Ptr _container_ptr;

    // donot move original
    // donot modify by 
    // donot return value_reference or value_pointer 
    _Val get_val(_Key _key) const {
        auto _pair_it = 
            _container_ptr->find(_key);
        if ( _pair_it == 
            _container_ptr->cend())
            return _Val();
        else 
            return _pair_it->second;
    }

    std::pair<_Val, bool> get_exi(_Key _key) const {
        auto _pair_it = 
            _container_ptr->find(_key);
        if ( _pair_it == 
            _container_ptr->cend())
            return std::make_pair(_Val(), false);
        else 
            return std::make_pair(_pair_it->second, true);
    }
};

// to add more than one template 
// template in template or more 


// read operation can only by .find
// write operation can only by .insert
template <typename _Key, typename _Val, 
            typename _Asso_Container = std::map<_Key, _Val> >
class RWriteOnceRBTree : 
    public ReadOnlyRBTree<_Key, _Val, _Asso_Container>
{
// _RORBTree_Ref operator=(const _Asso_Container::value_type & __value)
};

// read operation can only by .find
// write operation can only by .operator[]
template <typename _Key, typename _Val, 
            typename _Asso_Container = std::map<_Key, _Val> >
class RWRBTree
{

};

// can read only by .find
template <typename _Key, typename _Val, 
            typename _Asso_Container = std::unordered_map<_Key, _Val > >
class ReadOnlyHashMap
{

};

// read operation can only by .find
// write operation can only by .insert
template <typename _Key, typename _Val, 
            typename _Asso_Container = std::unordered_map<_Key, _Val > >
class RWriteOnceHashMap
{

};

// read operation can only by .find
// write operation can only by .operator[]
template <typename _Key, typename _Val, 
            typename _Asso_Container = std::unordered_map<_Key, _Val > >
class RWHashMap
{

};

__END_NS__

#endif