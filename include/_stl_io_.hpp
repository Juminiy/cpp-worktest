#pragma once
#ifndef _STL_IO_HPP
#define _STL_IO_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <cstdio>
#include <cstdlib>

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
#include <tuple>
#include <type_traits>

#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#include <deque>
#include <vector>
#include <stack>
#include <queue>

// how to define a pair name 
// for example: 
// 1. _i32_str_pair -> std::pair<int, std::string >
// 2. _i64_ch_pair -> std::pair<long long, char >
// 3. _i32_ptr_wch_pair -> std::pair<int*, wchar_t > 
#define __DEF_PAIR__(__Tp1__, __Tp2__) \
        typedef std::pair<__Tp1__, __Tp2__> __Tp1__ ##_ ##__Tp2__ ##_ ##pair

#define __CLOSE_CXX_C_IO_SYNC 

typedef std::pair<std::string, std::string > ss_pair;
typedef std::pair<std::string, int> si_pair;
typedef std::pair<int, std::string> is_pair;

__DEF_NS__(Alan)

#if __cplusplus >= 201703L

template <typename _Tuple, size_t... _indices>
auto __rm_tuple_first_helper(const _Tuple & __tp_tuple, 
                            std::index_sequence<_indices...>)
{
    return std::make_tuple(std::get<_indices + 1>(__tp_tuple)...);
}

template <typename _Tp, typename... _Tps >
auto __rm_tuple_first(const std::tuple<_Tp, _Tps...> & __tp_tuple)
{
    return __rm_tuple_first_helper(__tp_tuple, std::index_sequence_for<_Tps...>());
}

// fold expression for tuple helper
template <typename _Tuple, size_t... _indices>
void __os_tuple_helper(std::ostream & __os, 
                    const _Tuple & __tp_tuple, 
                    std::index_sequence<_indices...>)
{
    (..., (__os << ", " << std::get<_indices>(__tp_tuple)));
}

template<typename _Tp, typename... _Tps >
struct _rm_tuple_first_types;

template<typename _Tp, typename... _Tps>
struct _rm_tuple_first_types<std::tuple<_Tp, _Tps... > > 
{
    using types = std::tuple<_Tps...>;
};

template<typename _Tuple>
using _rm_tuple_first_types_v = typename _rm_tuple_first_types<_Tuple>::types;

/// @brief overload std::tuple ostream
/// @tparam ..._Tp 
/// @param __os 
/// @param __tp_tuple 
/// @return 
template <typename... _Elements>
std::ostream& operator << (std::ostream &__os,
                            const std::tuple<_Elements...> &__tp_tuple)
{   
    __os << "[";
    // TODO: 
    // seperate first from another 
    // __os << std::get<0>(__tp_tuple);
    // auto _rm_first = __rm_tuple_first(__tp_tuple);
    __os_tuple_helper(__os, __tp_tuple, 
        std::index_sequence_for<_Elements...>());
    __os << "]";

    return __os;
}

#endif


/// @brief overload std::pair ostream
/// @tparam _Tp1 
/// @tparam _Tp2 
/// @param __os 
/// @param __tp_pair 
/// @return 
template <typename _Tp1, 
            typename _Tp2 >
std::ostream& operator << (std::ostream &__os, 
                            const std::pair<_Tp1, _Tp2 > &__tp_pair)
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
                            std::pair<_Tp1, _Tp2 > && __tp_pair)
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
                            std::pair<_Tp1, _Tp2 > &__tp_pair)
{
    __is >> __tp_pair.first;
    __is >> __tp_pair.second;
    return __is;
}



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

template < typename _Seq_Container, 
            typename _Istream >
void SeqIterInput(_Seq_Container &__container,
                    _Istream &__istream)
{   
    using __value_type_ = typename _Seq_Container::value_type;
    std::copy(std::istream_iterator<__value_type_>(__istream),
                std::istream_iterator<__value_type_>(),
                std::back_inserter(__container));
}

template <typename _Tp, 
            typename _Istream >
void SeqIterInput(_Tp * __container,
                    size_t n,
                    _Istream &__istream)
{
    std::copy(std::istream_iterator<_Tp>(__istream),
                std::istream_iterator<_Tp>(),
                __container);
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

template < typename _Asso_Container, 
            typename _Istream >
void AssoIterInput(_Asso_Container &__container,
                    _Istream &__istream)
{
    using __value_type_ = typename _Asso_Container::value_type;
    std::copy(std::istream_iterator<__value_type_>(__istream),
                std::istream_iterator<__value_type_>(),
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


/// @test fully passed
/// @brief 
/// @tparam _Tp 
/// @tparam _Container 
/// @tparam _Ostream 
/// @param __container 
/// @param __ostream 
/// @param __delimiter 
template <typename _Tp, 
            typename _Container, 
            typename _Ostream >
void IterOutput(const _Container &__container,
                _Ostream &__ostream,
                const char* __delimiter)
{
    std::copy(__container.cbegin(), __container.cend(),
                std::ostream_iterator< _Tp >
                    (__ostream, __delimiter)
            );
}

/// @test fully passed
/// @brief 
/// @tparam _Container 
/// @tparam _Ostream 
/// @param __container 
/// @param __ostream 
/// @param __delimiter 
template < typename _Container, 
            typename _Ostream >
void IterOutput(const _Container &__container,
                _Ostream &__ostream,
                const char* __delimiter)
{
    using __value_type_ = typename _Container::value_type;
    std::copy(__container.cbegin(), __container.cend(),
                std::ostream_iterator< __value_type_ >
                    (__ostream, __delimiter)
                );
}

template < typename _Tp, 
            typename _Ostream >
void IterOutput(_Tp * __base, _Ostream & __os, size_t __sz, const char * __delimiter = ",")
{
    std::copy(__base, __base + __sz, 
                std::ostream_iterator< _Tp >
                    (__os, __delimiter)
                );
}

/// @test fully passed
/// @brief 
// _Container must have const_iterator cbegin() and cend()
// _Container must hold the type _Tp element
// _Tp must overload operator << (ostream&)
/// @tparam _Tp 
/// @tparam _Container 
/// @param __container 
/// @param __delimiter 
template <typename _Tp,
            typename _Container >
void ConsoleIterOutput(const _Container &__container, 
                        const char* __delimiter = ", ")
{
    IterOutput(__container, std::cout, __delimiter);
    NEXT_LINE;
}

/// @test fully passed
/// @brief 
/// @tparam _Container 
/// @param __container 
/// @param __delimiter 
template < typename _Container >
void ConsoleIterOutput(const _Container &__container, 
                        const char* __delimiter = ", ")
{
    IterOutput(__container, std::cout, __delimiter);
    NEXT_LINE;
}


/// @test passed
/// @brief 
// Beauty Output 
// size = 0 -> [] '\n'
// size = 1 -> [ele0] '\n'
// size = 2 -> [ele0, ele1, ele2] '\n'
/// @tparam _Tp 
/// @tparam _Container 
/// @param __container 
/// @param __delimiter 
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

template < typename _Stack >
void ConsoleOutputStack(_Stack __stack)
{
    using __value_type = typename _Stack::value_type;
    using __deque_type = std::deque<typename _Stack::value_type>;

    auto __bottom_2_top = __deque_type();
    while(!__stack.empty())
    {
        __bottom_2_top.push_front(__stack.top());
        __stack.pop();
    }

    ConsoleBeautyOutput<__value_type, __deque_type>(__bottom_2_top);
}

template < typename _Queue >
void ConsoleOutputQueue(_Queue __queue)
{
    using __value_type = typename _Queue::value_type;
    using __deque_type = std::deque<typename _Queue::value_type>;

    auto __bottom_2_top = __deque_type();
    while(!__queue.empty())
    {
        __bottom_2_top.push_back(__queue.front());
        __queue.pop();
    }

    ConsoleBeautyOutput<__value_type, __deque_type>(__bottom_2_top);
}

/// @test fully passed
/// @brief 
/// @tparam _Container 
/// @param __container 
/// @param __delimiter 
template < typename _Container >
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
                std::ostream_iterator
                < typename _Container::value_type >
                    (std::cout, __delimiter));
        PRINT(*_eit);
    }

    PRINTLN("]");
}

/// @brief 
/// @tparam _Tp 
/// @param __container 
/// @param _sz 
/// @param __delimiter 
template < typename _Tp >
void ConsoleBeautyOutput(const _Tp * __container,
                        size_t _sz,
                        const char* __delimiter = ", ")
{
    PRINT("[");
    
    if (_sz == 1)
    {
        PRINT(*__container);
    } else if (_sz > 1)
    {
        auto _it = __container;
        auto _eit = __container + _sz - 1;
        
        std::copy(_it, _eit, 
                std::ostream_iterator
                < _Tp >
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


template < typename _Container >
void ConsoleBeautyOutputEmbedded1(const _Container &__container,
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
                std::ostream_iterator
                < typename _Container::value_type >
                    (std::cout, __delimiter));
        PRINT(*_eit);
    }

    PRINT("]");
}

template< typename _Container_Con >
void ConsoleBeautyOutputEmbedded2(const _Container_Con &__container_con,
                                    const char* __delimiter = ", ")
{
    PRINT("[");

    size_t _csz = __container_con.size();
    if (_csz == 1)
    {
        ConsoleBeautyOutputEmbedded1(*__container_con.cbegin());
    } else if (_csz > 1)
    {
        auto _it  = __container_con.begin();
        auto _eit = __container_con.begin();
        std::advance(_eit, _csz-1);
        for(; _it != _eit; ++_it)
            ConsoleBeautyOutputEmbedded1(*_it, __delimiter),
            PRINT(", ");
        ConsoleBeautyOutputEmbedded1(*_eit);
    }

    PRINTLN("]");
}

GEN_FUNC_COPY
int __i32_read()
{
    int x = 0, s = 0;
    char ch = getchar();
    while(!::isdigit(ch)) {
        if(ch == '-') s = -1;
        ch = getchar();
    }
    while(::isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }
    return s ? ~x+1 : x;
}


GEN_FUNC_COPY
long long __i64_read()
{   
    using ll = long long;
    ll x = 0ll, s = 0ll;
    char ch = getchar();
    while(!::isdigit(ch)) {
        if(ch == '-') s = -1;
        ch = getchar();
    }
    while(::isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }

    return s ? ~x+1 : x;
}

__END_NS__


#endif