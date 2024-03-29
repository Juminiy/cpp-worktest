#pragma once 
#ifndef _STL_LIB_HPP
#define _STL_LIB_HPP

#include "_i_lib_.hpp"
#include "_stl_io_.hpp"
#include "_stl_seq_.hpp"
#include "_stl_asso_.hpp"
#include "_stl_num_.hpp"

#include <utility>

#define __TP_PLUS_TRAITS__(__tp_1__, __tp_2__) \
        decltype(std::declval<__tp_1__ >() + \
                std::declval<__tp_2__ >() )

#define __CON_TP_TRAITS__(__con1_type__, __tp_1__, __con2_type__, __tp_2__) \
        __con1_type__< __TP_PLUS_TRAITS__(__tp_1__, __tp_2__) >


USE_NAMESPACE_ALAN


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

// in std::container<_Tp > by
// iterator begin() or end() 
// normal version
template< typename, typename, typename = std::void_t< > >
struct _infer_container 
: std::false_type {  };  

// partial specialization
template < typename _con1_type, 
            typename _con2_type >
struct _infer_container
<_con1_type, _con2_type, 
    std::void_t<typename _con1_type::iterator,
                typename _con2_type::iterator,
                decltype( std::declval<_con1_type>().begin(),
                        std::declval<_con2_type>().begin() ) > >
: std::true_type {  };



// TODO: how to define whether a < class > 
// has a function member???


END_NAMESPACE_ALAN

#endif