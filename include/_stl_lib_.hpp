#pragma once 
#ifndef _STL_LIB_HPP
#define _STL_LIB_HPP

#include "_i_lib_.hpp"
#include "_stl_io_.hpp"
#include "_stl_seq_.hpp"
#include "_stl_asso_.hpp"
#include "_stl_num_.hpp"

#include <utility>
#include <cstdbool>
#include <cstdint>


USE_NAMESPACE_ALAN

// meta function 
// map self to self 
template <bool _bool_value >
struct _bool_type {
	static constexpr bool _value = _bool_value;
};

// template meta struct
template <typename _Tp, typename _Up >
struct _is_same_type 
: _bool_type<false> { };

// template meta struct
// template partial specialization
template <typename _Tp >
struct _is_same_type<_Tp, _Tp >
: _bool_type<true> { };


template <bool _Cond, typename _Tp = void >
struct _enable_if_cond { };

template <typename _Tp >
struct _enable_if_cond<true, _Tp >{
	using _value_type = _Tp ;
};



// // infer value_type 

// // unfinished
// // infer char, int, double
// // normal version
// template< typename, typename = std::void_t< > >
// struct _infer_num_type
// : std::false_type {	};

// // partial specialization
// template< typename _num_type >
// struct _infer_num_type
// < _num_type, 
// 	std::void_t<typename __num_type,
// 				decltype(  ) > >
// : std::true_type {	};



// infer meta function exists 

// can cook from std::vector -> std::__is_allocator

// in std::container<_Tp > by
// iterator begin() or end() 
// normal version
template< typename, typename, typename = std::void_t< > >
struct _infer_container 
: std::false_type {	}; 

// partial specialization
template < typename _con1_type, 
            typename _con2_type >
struct _infer_container
<_con1_type, _con2_type, 
    std::void_t<typename _con1_type::iterator,
                typename _con2_type::iterator,
                decltype( std::declval<_con1_type>().begin(),
                        std::declval<_con2_type>().begin() ) > >
: std::true_type { };



// TODO: how to define whether a < class > 
// has a function member???


END_NAMESPACE_ALAN

#endif