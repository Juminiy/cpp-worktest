#pragma once
#ifndef _STL_LIB_ADV_HPP
#define _STL_LIB_ADV_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"
#include <utility>
#include <memory>
#include <iostream>

USE_NAMESPACE_ALAN

template <typename _Tp >
class _Point_Loc
{
public:
    // typedef _Point_Loc<_Tp > _PLoc;
    // typedef _Point_Loc<_Tp >& _PLoc_reference;
    // typedef const _Point_Loc<_Tp >& _PLoc_const_reference;

    _Point_Loc(_Point_Loc & _p_loc){
        this->_x = _p_loc._x;
        this->_y = _p_loc._y;
        this->_z = _p_loc._z;
    }
    _Point_Loc(_Tp __x__, _Tp __y__, _Tp __z__)
        : _x(__x__), _y(__y__), _z(__z__)     {}
    // _Point_Loc(_Tp &&__x, _Tp &&__y, _Tp &&__z)
    //     : _x(std::move(__x)),
    //         _y(std::move(__x)), 
    //         _z(std::move(__x))         {}
    _Point_Loc() 
        : _x(_Tp()), _y(_Tp()), _z(_Tp())   {}
    
    // default
    _Point_Loc& operator+
    (const _Point_Loc & _p_loc)
    {
        this->_x += _p_loc._x;
        this->_y += _p_loc._y;
        this->_z += _p_loc._z;
        return *this;
    }

    _Point_Loc operator+
    (const _Point_Loc & _p_loc) const
    {
        auto _p_cp = _Point_Loc(_x, _y, _z);
        _p_cp._x += _p_loc._x;
        _p_cp._y += _p_loc._y;
        _p_cp._z += _p_loc._z;
        return _p_cp;
    }

    // default
    _Point_Loc& operator-
    (const _Point_Loc & _p_loc)
    {
        this->_x -= _p_loc._x;
        this->_y -= _p_loc._y;
        this->_z -= _p_loc._z;
        return *this;
    }

    _Point_Loc operator-
    (const _Point_Loc & _p_loc) const
    {
        auto _p_cp = _Point_Loc(_x, _y, _z);
        _p_cp._x -= _p_loc._x;
        _p_cp._y -= _p_loc._y;
        _p_cp._z -= _p_loc._z;
        return _p_cp;
    }
    
    // template <typename _Tp_ >
    friend std::istream& 
    operator >>(std::istream& _is, 
                _Point_Loc & _p_loc)
    {
        INPUT(_is, _p_loc._x),
        INPUT(_is, _p_loc._y),
        INPUT(_is, _p_loc._z);
        return _is;
    }

    // template <typename _Tp_ >
    friend std::ostream& 
    operator <<(std::ostream& _os, 
                const _Point_Loc & _p_loc)
    {
        OUTPUT(_os, "("),
        OUTPUT(_os, _p_loc._x),
        OUTPUT(_os, ", "),
        OUTPUT(_os, _p_loc._y),
        OUTPUT(_os, ", "),
        OUTPUT(_os, _p_loc._z),
        OUTPUT(_os, ")");
        return _os;
    }
private:
    _Tp _x, _y, _z;
};


template <typename _Tp_1,
            typename _Tp_2 >
auto _t_plus(_Tp_1 & __lhs, 
                _Tp_2 & __rhs)
-> decltype(__lhs + __rhs)
{
    return __lhs + __rhs;
}

template <typename _Tp_1,
            typename _Tp_2 >
auto _t_plus(_Tp_1 && __lhs, 
                _Tp_2 && __rhs)
-> decltype(std::move(__lhs) + 
            std::move(__rhs))
{
    return std::move(__lhs) + 
            std::move(__rhs);
}


END_NAMESPACE_ALAN

#endif

