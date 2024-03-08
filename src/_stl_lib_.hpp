#pragma once 
#ifndef _STL_LIB_HPP
#define _STL_LIB_HPP

#include <algorithm>
#include <iterator>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

// can not be used yet (can not be compiled!!!)
// _Container must have const_iterator cbegin() and cend()
// _Container must hold the type _Tp element
// _Tp must overload operator << (ostream&)
template <typename _Container, typename _Tp>
void ConsoleIterOutput(_Container __container, 
                        std::string const &_delimiter)
{
    std::copy(__container.cbegin(), 
                __container.cend(), 
                std::ostream_iterator<_Tp>(std::cout, 
                                            _delimiter)
            );
}

typedef std::pair<std::string, std::string> ss_pair;
typedef std::pair<std::string, int> si_pair;

#endif 