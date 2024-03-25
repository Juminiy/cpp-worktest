#pragma once
#ifndef _STL_LIB_ADV_HPP
#define _STL_LIB_ADV_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"
#include <utility>
#include <memory>
#include <iostream>
#include <numeric>
#include <ext/numeric>

#include <cassert>

USE_NAMESPACE_ALAN

template <typename _Tp >
class _Point_Loc
{
public:
    static _Tp _min_bound;
    static _Tp _max_bound;
    // typedef _Point_Loc _PLoc;
    // typedef _Point_Loc& _PLoc_reference;
    // typedef const _Point_Loc& _PLoc_const_reference;

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
    
    // operator assign
    _Point_Loc operator=
    (_Point_Loc & _p_loc)
    {
        this->_x = _p_loc._x;
        this->_y = _p_loc._y;
        this->_z = _p_loc._z;
    }

    _Point_Loc& operator+=
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

    _Point_Loc& operator-=
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

    bool operator==
    (const _Point_Loc & _p_loc) const 
    {
        return this->_x == _p_loc._x &&
                this->_y == _p_loc._y &&
                this->_z == _p_loc._z;
    }

    bool operator!=
    (const _Point_Loc & _p_loc) const 
    {
        return !(*this == _p_loc);
    }

    _Tp operator[]
    (const size_t & _axis) const 
    {
        assert(_axis >= 0 && _axis <= 2);
        // static_assert(_axis >= 0 && _axis <= 2);
        switch (_axis)
        {
        case 0:
            return this->_x;
        case 1:
            return this->_y;
        case 2:
            return this->_z;
        default:
            return _Tp();
        }
    }
    
    // inner product
    _Tp operator*
    (const _Point_Loc & _p_loc) const
    {
        return this->_x * _p_loc._x +
                this->_y * _p_loc._y +
                this->_z * _p_loc._z;
    }

    // point euclidean distance
    _Tp operator^
    (const _Point_Loc & _p_loc) const
    {
        // return (this->_x - _p_loc._x) *
        //         (this->_x - _p_loc._x) +
        //         (this->_y - _p_loc._y) *
        //         (this->_y - _p_loc._y) +
        //         (this->_z - _p_loc._z) *
        //         (this->_z - _p_loc._z);
        return Sqrt<_Tp >
                (Power<_Tp >(this->_x - _p_loc._x , 2) + 
                    Power<_Tp >(this->_y - _p_loc._y , 2) + 
                    Power<_Tp >(this->_z - _p_loc._z , 2));
    }

    std::string to_string() const
    {
        auto _str = std::string();
        _str += "(";
        _str += std::to_string(_x);
        _str += ", ";
        _str += std::to_string(_y);
        _str += ", ";
        _str += std::to_string(_z);
        _str += ")";
        return _str;
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



END_NAMESPACE_ALAN

#endif

