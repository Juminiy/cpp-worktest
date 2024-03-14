#pragma once 
#ifndef _STL_LIB_HPP
#define _STL_LIB_HPP

#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>

#include <string>
#include <iterator>

#include <utility>
#include <numeric>
#include <algorithm>

#include <chrono>

#define TIME_BASED_SEED std::chrono::system_clock::now().time_since_epoch().count()


// _Tp must oveload:                            operator >> 
// _Seq_Container must have member function:    push_back()
// _Istream must allow:                         implicit type convertion
template <typename _Tp, 
            typename _Seq_Container, 
            typename _Istream >
void SeqIterInput(const _Seq_Container &__container,
                _Istream &__istream)
{
    std::copy(std::istream_iterator<_Tp>(__istream),
                std::istream_iterator<_Tp>(),
                std::back_inserter(__container));
}

// _Tp must oveload:                            operator >> 
// _Seq_Container must have member function:    insert()
// _Istream must allow:                         implicit type convertion
template <typename _Tp, 
            typename _Asso_Container, 
            typename _Istream >
void AssoIterInput(const _Asso_Container &__container,
                _Istream &__istream)
{
    std::copy(std::istream_iterator<_Tp>(__istream),
                std::istream_iterator<_Tp>(),
                std::inserter(__container));
}



template <typename _Tp, 
            typename _Container, 
            typename _Ostream >
void IterOutput(const _Container &__container,
                _Ostream &__ostream,
                const char* __delimiter)
{
    std::copy(__container.cbegin(),
                __container.cend(),
                std::ostream_iterator<_Tp>(__ostream,
                                            __delimiter)
                );
}

// _Container must have const_iterator cbegin() and cend()
// _Container must hold the type _Tp element
// _Tp must overload operator << (ostream&)
template <typename _Tp,
            typename _Container >
void ConsoleIterOutput(const _Container &__container, 
                        const char* __delimiter = ", ")
{
    IterOutput<_Tp, _Container, std::ostream >
                (__container, std::cout, __delimiter);
    std::cout << std::endl;
}

// Beauty Output 
// size = 0 -> [] '\n'
// size = 1 -> [ele0] '\n'
// size = 2 -> [ele0, ele1, ele2] '\n'
template <typename _Tp,
            typename _Container >
void ConsoleBeautyOutput(const _Container &__container,
                            const char* __delimiter)
{
    
}

// don't skip any a white space or any '\n', '\t', '\r'
template <typename _InputStream, typename _OutputStream >
void CompleteIterOutput(_InputStream &__input_stream,
                        _OutputStream &__output_stream)
{
    copy(std::istreambuf_iterator<char>(__input_stream),
            std::istreambuf_iterator<char>(),
            std::ostreambuf_iterator<char>(__output_stream));
}

typedef std::pair<std::string, std::string > ss_pair;
typedef std::pair<std::string, int> si_pair;


template <typename _Tp, 
            typename _Asso_Container >
bool AssoFind(const _Asso_Container &__container, 
                const _Tp &__element)
{
    return __container.find(__element) 
            != __container.cend();
}

template <typename _Tp,
            typename _Asso_Container >
size_t AssoCount(const _Asso_Container &__container,
                    const _Tp &__element) 
{
    return __container.count(__element);
}

// (_min, _max)
// v00 -> v0
template <typename _Tp,
            typename _Asso_Ordered_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
AssoRange_v0(const _Asso_Ordered_Container &__container,
                const _Tp &_min_element, 
                const _Tp &_max_element)
{
    return std::make_pair(__container.upper_bound(_min_element),
                            __container.lower_bound(_max_element));
}

// (_min, _max]
// v01 -> v1
template <typename _Tp,
            typename _Asso_Ordered_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
AssoRange_v1(const _Asso_Ordered_Container &__container,
                const _Tp &_min_element, 
                const _Tp &_max_element)
{
    return std::make_pair(__container.upper_bound(_min_element),
                            __container.upper_bound(_max_element));
}

// [_min, _max)
// v10 -> v2
template <typename _Tp,
            typename _Asso_Ordered_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
AssoRange_v2(const _Asso_Ordered_Container &__container,
                const _Tp &_min_element, 
                const _Tp &_max_element)
{
    return std::make_pair(__container.lower_bound(_min_element),
                            __container.lower_bound(_max_element));
}

// [_min, _max]
// v11 -> v3
template <typename _Tp,
            typename _Asso_Ordered_Container,
            typename _Asso_Iter >
std::pair<_Asso_Iter, _Asso_Iter >
AssoRange_v3(const _Asso_Ordered_Container &__container,
                const _Tp &_min_element, 
                const _Tp &_max_element)
{
    return std::make_pair(__container.lower_bound(_min_element),
                            __container.upper_bound(_max_element));
}


template <typename _Tp,
            typename _Seq_Container >
bool SeqFind(const _Seq_Container &__container,
                const _Tp &__element)
{
    return std::find(__container.cbegin(), 
                        __container.cend(),
                        __element)
                != __container.cend(); 
}



// _Tp must overload + 
template <typename _Tp,
            typename _Container >
_Tp _Sum(const _Container &__container,
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
        const _Tp __range_start,
        const _Tp __range_end,
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
_Tp _Avg(const _Container &__container,
            _Tp __init_val)
{
    return _Sum(__container, __init_val) /
            __container.size();
}

template <typename _Tp,
            typename _Container,
            typename _Iterator >
_Tp _Avg(_Container &__container,
            const _Tp __range_start,
            const _Tp __range_end,
            _Tp __init_val)
{
    std::pair<_Tp, std::pair<_Iterator, _Iterator > > res_pair = 
        _Sum<_Tp, _Container, _Iterator>
            (__container, __range_start, __range_end, __init_val);
    return (res_pair.first) / 
            (std::distance(res_pair.second.first, 
                            res_pair.second.second));
}




#endif 