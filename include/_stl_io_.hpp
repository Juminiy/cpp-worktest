#pragma once
#ifndef _STL_IO_HPP
#define _STL_IO_HPP

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
#include <any>

#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

USE_NAMESPACE_ALAN


/// @bug make sense??? I can not be sure
/// @brief overload std::tuple ostream
/// @tparam ..._Tp 
/// @param __os 
/// @param __tp_tuple 
/// @return 
template <typename ..._Tp>
std::ostream& operator << (std::ostream &__os,
                            const std::tuple<_Tp...> &__tp_tuple)
{   
    size_t _tps_sz = 
        std::tuple_size<decltype(__tp_tuple)>::value;
    __os << "[" 
            << std::get<0>(__tp_tuple);
    for(size_t _tp_i = 1;
        _tp_i < _tps_sz;
        ++_tp_i)
        __os << ", "
                << std::get<_tp_i>(__tp_tuple);
    __os << "]";
    return __os;
}

// std::ostream& operator << (std::ostream & __os,
//                             const std::any & _any_val)
// {
//     __os << _any_val;
//     return __os;
// }


// TODO: 
// how to define a pair name 
// for example: 
// 1. _i32_str_pair -> std::pair<int, std::string >
// 2. _i64_ch_pair -> std::pair<long long, char >
// 3. _i32_ptr_wch_pair -> std::pair<int*, wchar_t > 
#define __TYPEDEF_STD_PAIR__(__Tp1__, __Tp2__) \
        typedef std::pair<__Tp1__, __Tp2__> __Tp1__ __Tp2__ pair

typedef std::pair<std::string, std::string > ss_pair;
typedef std::pair<std::string, int> si_pair;
typedef std::pair<int, std::string> is_pair;


/// @brief overload std::pair ostream
/// @tparam _Tp1 
/// @tparam _Tp2 
/// @param __os 
/// @param __tp_pair 
/// @return 
template <typename _Tp1, 
            typename _Tp2 >
std::ostream& operator << (std::ostream &__os, 
                            const std::pair<_Tp1, _Tp2 > 
                            &__tp_pair)
{
    __os << "[" 
            << __tp_pair.first 
            << ", " 
            << __tp_pair.second 
        << "]";
    return __os;
}

template <typename _Tp1, 
            typename _Tp2 >
std::ostream& operator << (std::ostream &__os, 
                            std::pair<_Tp1, _Tp2 > 
                            && __tp_pair)
{
    __os << "[" 
            << __tp_pair.first 
            << ", " 
            << __tp_pair.second 
        << "]";
    return __os;
}

template <typename _Tp1, 
            typename _Tp2 >
std::istream& operator >> (std::istream &__is, 
                            std::pair<_Tp1, _Tp2 > 
                            &__tp_pair)
{
    __is >> __tp_pair.first;
    __is >> __tp_pair.second;
    return __is;
}


// make no sense
// template pair_pair recursive
// template < typename _Tp1_1, typename _Tp1_2, 
//             typename _Tp2_1, typename _Tp2_2 > 
// std::ostream& operator << (std::ostream &__os,
//                             const std::pair<
//                                 std::pair<_Tp1_1, _Tp1_2 >, 
//                                 std::pair<_Tp2_1, _Tp2_2 > > 
//                                 &__tp_pair_4e)
// {
//     __os << "[" 
//             << __tp_pair_4e.first
//             << ", "
//             << __tp_pair_4e.second
//         << "]";
//     return __os;
// }

// make no sense
// partial specialization
// compile error 
// std::ostream& operator << (std::ostream &__os, 
//                             const std::pair <
//                                 std::pair<std::string, int >, 
//                                 std::pair<int, std::string > > 
//                                 &__tp_pair_4e_partial)
// {
//     __os << "["
//             << __tp_pair_4e_partial.first.first
//             << ", "
//             << __tp_pair_4e_partial.first.second
//             << "; "
//             << __tp_pair_4e_partial.second.first
//             << ", "
//             << __tp_pair_4e_partial.second.second
//         << "]";
//     return __os;
// }


// std::Container<_Tp > I/O:

// has not been tested
// _Tp must oveload:                            operator >> 
// _Seq_Container must have member function:    push_back()
// _Istream must allow:                         implicit type convertion
template <typename _Tp, 
            typename _Seq_Container, 
            typename _Istream >
void SeqIterInput(_Seq_Container &__container,
                    _Istream &__istream)
{
    std::copy(std::istream_iterator<_Tp>(__istream),
                std::istream_iterator<_Tp>(),
                std::back_inserter(__container));
}

// has not been tested
// _Tp must oveload:                            operator >> 
// _Seq_Container must have member function:    insert()
// _Istream must allow:                         implicit type convertion
template <typename _Tp, 
            typename _Asso_Container, 
            typename _Istream >
void AssoIterInput(_Asso_Container &__container,
                    _Istream &__istream)
{
    std::copy(std::istream_iterator<_Tp>(__istream),
                std::istream_iterator<_Tp>(),
                std::inserter(__container));
}



typedef std::ios_base& (*_AlignFunc) (std::ios_base&);

// inspired by and extended by
// https://stackoverflow.com/questions/405039/permanent-stdsetw
template < typename _Tp, 
            size_t _Width, 
            char _FillCT,
            _AlignFunc _AlignType >
class _FixedAlign
{
public:
    _FixedAlign(_Tp _elem_val) : 
                elem_val(_elem_val){} 

    template < typename _Tp_tp, 
                size_t _Width_wd, 
                char _FillCT_ct, 
                _AlignFunc _AlignType_type>
    friend std::ostream& 
        operator << (std::ostream & _os, 
                    const _FixedAlign< _Tp_tp, 
                                        _Width_wd,
                                        _FillCT_ct,
                                        _AlignType_type > & _fa)
    {
        _os << std::setfill(_FillCT_ct) 
            << std::setw(_Width_wd) 
            << _AlignType_type << _fa.elem_val;
        return _os ;
    }

private:
    _Tp elem_val;
};

// Template can not do, but Macro can do !!!
#define CONSOLE_FIXED_OUTPUT(__container__, __Tp__, \
    __fixed_sz__, __fill_ct__ , __align_func__, __delimiter__) \
    std::copy(__container__.cbegin(), __container__.cend(), \
                std::ostream_iterator< _FixedAlign <__Tp__, \
                                                    __fixed_sz__, \
                                                    __fill_ct__, \
                                                    __align_func__ > > \
                    (std::cout, __delimiter__)), \
    __CNEW_LINE__; 



template <typename _Tp, 
            typename _Container, 
            typename _Ostream >
void IterOutput(const _Container &__container,
                _Ostream &__ostream,
                const char* __delimiter)
{
    std::copy(__container.cbegin(),
                __container.cend(),
                std::ostream_iterator< _Tp >
                    (__ostream, __delimiter)
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
    NEXT_LINE;
}

// Beauty Output 
// size = 0 -> [] '\n'
// size = 1 -> [ele0] '\n'
// size = 2 -> [ele0, ele1, ele2] '\n'
template <typename _Tp,
            typename _Container >
void ConsoleBeautyOutput(const _Container &__container,
                            const char* __delimiter = ", ")
{
    PRINT("[");

    size_t _csz = __container.size();
    if (_csz == 1)
    {
        PRINT(*__container.cbegin());
    } else if (_csz > 1)
    {
        auto _it  = __container.begin();
        auto _eit = __container.begin();
        std::advance(_eit, _csz-1);

        std::copy(_it, _eit,
                std::ostream_iterator< _Tp >
                (std::cout, __delimiter));
        PRINT(*_eit);
    }

    PRINTLN("]");
}

// don't skip any a white space or any '\n', '\t', '\r'
template <typename _InputStream, typename _OutputStream >
void IterInputOutput(_InputStream &__input_stream,
                        _OutputStream &__output_stream)
{
    copy(std::istreambuf_iterator<char>(__input_stream),
            std::istreambuf_iterator<char>(),
            std::ostreambuf_iterator<char>(__output_stream));
}


template <typename _Iter_Pair >
void ConsoleIterOutputIterPairRange(const _Iter_Pair &_iter_pair)
{
    for(auto _it = _iter_pair.first;
            _it != _iter_pair.second;
            ++ _it)
        PRINT(*_it), PRINT(", ");
    PRINTLN("");
}

template <typename _Asso_Container>
void ConsoleOutputAsso(const _Asso_Container & __container)
{   
    using _container_type = _Asso_Container;
    using _iterator_type = typename _Asso_Container::const_iterator;
    using _iterator_pair_type = std::pair<_iterator_type, _iterator_type>;
    ConsoleIterOutputIterPairRange<_iterator_pair_type >(
        Asso_Range_all<_container_type, _iterator_type >(__container));
}

// following 4 overload is illegal
// std::ostream& operator<< 
// (std::ostream &_os, const char * const _cc_str)
// {
//     _os << std::string(_cc_str);
//     return _os;
// }

// std::ostream& operator<< 
// (std::ostream &_os, const char * _cc_str)
// {
//     _os << _cc_str ;
//     return _os;
// }

// std::ostream& operator<< 
// (std::ostream &_os, char * const _cc_str)
// {
//     _os << _cc_str ;
//     return _os;
// }

// std::ostream& operator<< 
// (std::ostream &_os, char * _cc_str)
// {
//     _os << _cc_str ;
//     return _os;
// }


END_NAMESPACE_ALAN


#endif