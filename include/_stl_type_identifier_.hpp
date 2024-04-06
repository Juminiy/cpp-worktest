#pragma once
#ifndef _TYPE_IDENTIFIER_HPP
#define _TYPE_IDENTIFIER_HPP

#include "_i_lib_.hpp"

#include <typeinfo>
#include <type_traits>
#include <string>
#if __CC_VER__ >= 4 && __has_include(<cxxabi.h>)
#include <cxxabi.h>
#include <cstdlib>
#endif

#define __TP_TID_STR__(__tp__) \
        Alan::__cpp_tid_<__tp__>()
#define __V_TID_STR__(__val__) \
        __TP_TID_STR__(decltype(__val__))

// identify a type to C++ internal/underlying type
USE_NAMESPACE_ALAN

// copy and change from 
// https://github.com/parallel101/course/blob/2d30da61b442008c003f69225e6feca20a4ca7df/stlseries/stl_map/experiment/cppdemangle.h
static inline std::string __cpp_tid_(const char *__name) {
#if __CC_VER__ >= 4 && __has_include(<cxxabi.h>)
    int _status;
    char *_ptr_nname = abi::__cxa_demangle(__name, 0, 0, &_status);
    std::string _dname = _ptr_nname ? _ptr_nname : __name;
    std::free(_ptr_nname);
#else
    std::string _dname = __name;
#endif
    return _dname;
}

static inline std::string __cpp_tid_(std::type_info const &__type_) {
    return __cpp_tid_(__type_.name());
}

template <class _Tp>
static inline std::string __cpp_tid_() {
    std::string _dname{__cpp_tid_(typeid(std::remove_cv_t<std::remove_reference_t<_Tp>>))};
    if (std::is_const_v<std::remove_reference_t<_Tp>>)
        _dname += " const";
    if (std::is_volatile_v<std::remove_reference_t<_Tp>>)
        _dname += " volatile";
    if (std::is_lvalue_reference_v<_Tp>)
        _dname += " &";
    if (std::is_rvalue_reference_v<_Tp>)
        _dname += " &&";
    return _dname;
}

END_NAMESPACE_ALAN

#endif