#pragma once 
#ifndef _STL_LIB_HPP
#define _STL_LIB_HPP

#include <algorithm>
#include <iterator>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>


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
                        const char* __delimiter)
{
    IterOutput<_Tp, _Container, std::ostream >
                (__container, std::cout, __delimiter);
}

// Beauty Output 
// [] '\n'
// [ele0] '\n'
// [ele0, ele1, ele2] '\n'
template <typename _Tp,
            typename _Container >
void ConsoleBeautyOutput(const _Container &__container,
                            const char* __delimiter)
{
    
}

template <typename _InputFile, typename _OutputFile >
void FileIterOutput(const _InputFile &__input_file,
                    _OutputFile &__output_file)
{

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


#endif 