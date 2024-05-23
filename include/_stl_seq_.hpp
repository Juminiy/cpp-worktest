#pragma once
#ifndef _STL_SEQ_HPP
#define _STL_SEQ_HPP

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

// Sequential Container:

template <typename _Tp,
            typename _Seq_Container >
bool SeqFind(_Seq_Container &__container,
                const _Tp &__element)
{
    return std::find(__container.begin(),
                        __container.end(),
                        __element)
            != __container.cend(); 
}

// (_min, _max)
// v00 -> v0
template <typename _Tp,
            typename _Seq_Ordered_Container,
            typename _Seq_Iter >
std::pair<_Seq_Iter, _Seq_Iter >
SeqRange_v0(_Seq_Ordered_Container &__container,
            const _Tp &_min_element,
            const _Tp &_max_element)
{
    return std::make_pair(
            std::upper_bound(__container.begin(), 
                            __container.end(), 
                            _min_element),
            std::lower_bound(__container.begin(), 
                            __container.end(), 
                            _max_element));
}

// (_min, _max]
// v01 -> v1
template <typename _Tp,
            typename _Seq_Ordered_Container,
            typename _Seq_Iter >
std::pair<_Seq_Iter, _Seq_Iter >
SeqRange_v1(_Seq_Ordered_Container &__container,
            const _Tp &_min_element,
            const _Tp &_max_element)
{
    return std::make_pair(
            std::upper_bound(__container.begin(), 
                            __container.end(), 
                            _min_element),
            std::upper_bound(__container.begin(), 
                            __container.end(), 
                            _max_element));
}

// [_min, _max)
// v10 -> v2
template <typename _Tp,
            typename _Seq_Ordered_Container,
            typename _Seq_Iter >
std::pair<_Seq_Iter, _Seq_Iter >
SeqRange_v2(_Seq_Ordered_Container &__container,
            const _Tp &_min_element,
            const _Tp &_max_element)
{
    return std::make_pair(
            std::lower_bound(__container.begin(),
                            __container.end(),
                            _min_element),
            std::lower_bound(__container.begin(),
                            __container.end(),
                            _max_element));
}

// [_min, _max]
// v11 -> v3
template <typename _Tp,
            typename _Seq_Ordered_Container,
            typename _Seq_Iter >
std::pair<_Seq_Iter, _Seq_Iter >
SeqRange_v3(_Seq_Ordered_Container &__container,
            const _Tp &_min_element,
            const _Tp &_max_element)
{
    return std::make_pair(
            std::lower_bound(__container.begin(),
                            __container.end(),
                            _min_element),
            std::upper_bound(__container.begin(), 
                            __container.end(), 
                            _max_element));
}   

/// @brief duplicates all of the @param __container for @param __dup_time times 
/// @tparam _Container 
/// @param __container 
/// @param __dup_time 
template < typename _Container >
void _Seq_Con_Dup(_Container &__container, 
                    size_t __dup_time)
{
    for(size_t _dup_t = 0;
        _dup_t < __dup_time;
        ++ _dup_t)
        std::copy(__container.begin(), __container.end(),
                    std::back_inserter(__container));
}

// seq sort
template < typename _Tp,
            typename _Container,
            typename _Compare = std::less<_Tp > >
void _Seq_Con_Sort(_Container &__container, 
                    const _Compare &_comp = std::less<_Tp >() )
{
    std::sort(__container.begin(), __container.end(),
                _comp);
}

// copy to if nullptr
template < typename _Tp >
void _Seq_Deep_Copy_Pointer(__PTR_TO_CONST__(_Tp) __src, 
                            __PTR__(__PTR__(_Tp)) __dest,
                            size_t __sz)
{
    if (__src == nullptr ||
        __dest == nullptr ||
        __sz == 0)
        return;
    // why assign/allocate fail in caller side?
    if (*__dest == nullptr) 
        // TODO: 
        // use smart pointer 
        // ? how to convert raw to smart
        *__dest = new _Tp[__sz];
    std::copy(__src, __src+__sz, *__dest);
}

// Numeric

// _Tp must overload + 
template <typename _Tp,
            typename _Container >
_Tp _Sum(_Container &__container,
            _Tp __init_val)
{
    return std::accumulate(__container.begin(),    
                            __container.end(),
                            __init_val);
}

// [_start, _end)
template <typename _Tp, 
            typename _Container,
            typename _Iterator >
std::pair<_Tp, std::pair<_Iterator , _Iterator > >
_Sum(_Container &__container,
        const _Tp &__range_start,
        const _Tp &__range_end,
        _Tp __init_val)
{       
    std::pair<_Iterator, _Iterator > _it_rg = std::make_pair(
                    std::lower_bound(__container.begin(), __container.end(), 
                                        __range_start),
                    std::lower_bound(__container.begin(), __container.end(), 
                                        __range_end));
    return std::make_pair(std::accumulate(
                            _it_rg.first,
                            _it_rg.second,
                            __init_val), 
                        _it_rg);
}

// _Tp must overload operator + and operator /
template <typename _Tp,
            typename _Container >
_Tp _Avg(_Container &__container,
            _Tp __init_val)
{
    return _Sum(__container, __init_val) /
            __container.size();
}

template <typename _Tp,
            typename _Container,
            typename _Iterator >
_Tp _Avg(_Container &__container,
            const _Tp &__range_start,
            const _Tp &__range_end,
            _Tp __init_val)
{
    std::pair<_Tp, std::pair<_Iterator, _Iterator > > res_pair = 
        _Sum<_Tp, _Container, _Iterator>
            (__container, __range_start, __range_end, __init_val);
    return (res_pair.first) / 
            (std::distance(res_pair.second.first, 
                            res_pair.second.second));
}

template <typename _Tp>
GEN_FUNC_COPY
void appendSeq(std::vector<_Tp> & __dest, 
                const std::vector<_Tp> & __src)
{
    if(__src.empty())
        return ;
    __dest.reserve(__dest.size() + __src.size());
    __dest.insert(__dest.end(), __src.begin(), __src.end());
}

template <typename _Tp>
GEN_FUNC_COPY
void appendSeq(std::vector<_Tp> & __dest, 
                std::vector<_Tp> && __src)
{
    if(__src.empty())
        return ;
    if(__dest.empty())
    { 
        __dest.swap(__src);
        return ; 
    }
    __dest.reserve(__dest.size() + __src.size());
    __dest.insert(__dest.end(), 
        std::make_move_iterator(__src.begin()), 
        std::make_move_iterator(__src.end()));
    __src.clear();
}

template <typename _Seq_Container>
GEN_FUNC_COPY
void appendSeq(_Seq_Container & __dest, 
                const _Seq_Container & __src)
{
    if(__src.empty())
        return ;
    // __dest.reserve(__dest.size() + __src.size());
    __dest.insert(__dest.end(), __src.begin(), __src.end());
}

template <typename _Seq_Container>
GEN_FUNC_COPY
void appendSeq(_Seq_Container & __dest, 
                _Seq_Container && __src)
{
    if(__src.empty())
        return ;
    if(__dest.empty())
    { 
        __dest.swap(__src);
        return ; 
    }
    // __dest.reserve(__dest.size() + __src.size());
    __dest.insert(__dest.end(), 
        std::make_move_iterator(__src.begin()), 
        std::make_move_iterator(__src.end()));
    __src.clear();
}

/// sequential container
template < typename _Container >
GEN_FUNC_COPY
void PatienceSort(_Container & __container)
{
    
}



template < typename _Container1, typename _Container2 >
GEN_FUNC_COPY
std::pair<std::set<typename _Container1::value_type>,
            std::set<typename _Container2::value_type> >
ShowDiff
(const _Container1 & __container1,
const _Container2 & __container2)
{
    using _set_type = 
        std::set<typename _Container1::value_type>;
    auto _set1 = _set_type();
    auto _set2 = _set_type();

    for(auto __elem : __container1)
    {
        _set1.insert(__elem);
    }

    for(auto __elem : __container2)
    {
        _set2.insert(__elem);
    }

    auto _set1_diff_set2 = _set_type();
    auto _set2_diff_set1 = _set_type();

    std::set_difference(
        _set1.begin(), _set1.end(), 
        _set2.begin(), _set2.end(),
        std::inserter(_set1_diff_set2, _set1_diff_set2.end())
    );
    std::set_difference(
        _set2.begin(), _set2.end(),
        _set1.begin(), _set1.end(),
        std::inserter(_set2_diff_set1, _set2_diff_set1.end())
    );

    return std::make_pair(
        _set1_diff_set2,
        _set2_diff_set1
    );
}

template < typename _Container >
std::vector<size_t> 
FindUnOrdered( const _Container & __container )
{
    if(__container.size() <= 1)
        return std::vector<size_t>();
    auto __pivot = __container[0];
    auto __index = std::vector<size_t>();
    __index.reserve(__container.size() >> 2);
    for(size_t _idx = 0; _idx < __container.size(); ++ _idx)
    {
        auto __elem = __container[_idx];
        if( __elem < __pivot)
        {
            __index.push_back(_idx);
        }
        __pivot = std::move(__elem);
    }

    return __index;
}

template < typename _Container >
size_t 
UniqueVector2(_Container & __container)
{
    auto vset = std::set<typename _Container::value_type>();

    for(auto vi : __container)
    {
        if(vset.find(vi) == vset.end())
            vset.insert(vi);
    }
    
    return vset.size();
}

__END_NS__


#endif