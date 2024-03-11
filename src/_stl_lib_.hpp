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
            typename _Ostream
            >
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
            typename _Container
            >
void ConsoleIterOutput(const _Container &__container, 
                        const char* __delimiter)
{
    IterOutput<_Tp, _Container, std::ostream >
                (__container, std::cout, __delimiter);
}

template <typename _InputFile, typename _OutputFile>
void FileIterOutput(const _InputFile &__input_file,
                    _OutputFile &__output_file)
{

}

typedef std::pair<std::string, std::string> ss_pair;
typedef std::pair<std::string, int> si_pair;


template <typename _Tp, 
            typename _Asso_Container>
bool AssoFind(const _Asso_Container &__container, 
                const _Tp &__element)
{
    return __container.find(__element) 
            != __container.cend();
}

template <typename _Tp,
            typename _Seq_Container>
bool SeqFind(const _Seq_Container &__container,
                const _Tp &__element)
{
    return std::find(__container.cbegin(), 
                        __container.cend(),
                        __element)
                != __container.cend(); 
}


#endif 