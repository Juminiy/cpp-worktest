#pragma once
#ifndef _POINT_LOC_HPP
#define _POINT_LOC_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"
#include "_stl_lib_adv_.hpp"

#include <utility>
#include <memory>
#include <iostream>
#include <numeric>
#include <cstdint>


#if __CC_VER__ == 2
#include <ext/numeric>
#endif 

#include <cassert>

USE_NAMESPACE_ALAN

template <typename _Tp >
class _Point_Loc
{
public:
    __DEF_ALL__(PLoc, _Point_Loc);

    _Point_Loc(PLoc_const_reference _rhs)
        : _x(_rhs._x), _y(_rhs._y), _z(_rhs._z) {
            ++ this->_inst_cnt;
        }
    _Point_Loc(PLoc_r_reference _rhs) 
        : _x(_rhs._x), _y(_rhs._y), _z(_rhs._z) {
            ++ this->_inst_cnt;
        }
    _Point_Loc(_Tp __x__, _Tp __y__, _Tp __z__)
        : _x(__x__), _y(__y__), _z(__z__)     {
            ++ this->_inst_cnt;
        }
    // _Tp value r_reference
    // _Point_Loc(_Tp &&__x, _Tp &&__y, _Tp &&__z)
    //     : _x(std::move(__x)),
    //         _y(std::move(__x)), 
    //         _z(std::move(__x))         {}
    _Point_Loc() 
        : _x(_Tp()), _y(_Tp()), _z(_Tp())   {
            ++ this->_inst_cnt;
        }
    ~_Point_Loc(){
        -- this->_inst_cnt;
    }

    // operator assign
    PLoc_reference operator=
    (PLoc_const_reference _p_loc)
    {
        this->_x = _p_loc._x;
        this->_y = _p_loc._y;
        this->_z = _p_loc._z;
        return *this;
    }
    PLoc_reference operator+=
    (PLoc_const_reference _p_loc)
    {
        this->_x += _p_loc._x;
        this->_y += _p_loc._y;
        this->_z += _p_loc._z;
        return *this;
    }
    PLoc_reference operator-=
    (PLoc_const_reference _p_loc)
    {
        this->_x -= _p_loc._x;
        this->_y -= _p_loc._y;
        this->_z -= _p_loc._z;
        return *this;
    }


    // template in template 
    // operator overload
    template < typename __Tp__ >
    auto operator+ 
    (const _Point_Loc<__Tp__ > & _rhs) const 
    {
        auto _p_loc = 
            _Point_Loc<__TP_PLUS_TRAITS__(_Tp, __Tp__) >();
        _p_loc._x = this->_x + _rhs.getX();
        _p_loc._y = this->_y + _rhs.getY();
        _p_loc._z = this->_z + _rhs.getZ();
        return _p_loc;
    }
    PLoc operator+
    (PLoc_const_reference _p_loc) const
    {
        auto _p_cp = _Point_Loc(_x, _y, _z);
        _p_cp._x += _p_loc._x;
        _p_cp._y += _p_loc._y;
        _p_cp._z += _p_loc._z;
        return _p_cp;
    }
    PLoc operator-
    (PLoc_const_reference _p_loc) const
    {
        auto _p_cp = _Point_Loc(_x, _y, _z);
        _p_cp._x -= _p_loc._x;
        _p_cp._y -= _p_loc._y;
        _p_cp._z -= _p_loc._z;
        return _p_cp;
    }

    bool operator==
    (PLoc_const_reference _p_loc) const 
    {
        return this->_x == _p_loc._x &&
                this->_y == _p_loc._y &&
                this->_z == _p_loc._z;
    }

    bool operator!=
    (PLoc_const_reference _p_loc) const 
    {
        return !(*this == _p_loc);
    }

    bool operator < 
    (PLoc_const_reference _rhs) const 
    {
        return this->_x < _rhs._x &&
            this->_y < _rhs._y &&
            this->_z < _rhs._z;
    }
    bool operator <= 
    (PLoc_const_reference _rhs) const 
    {
        return this->_x < _rhs._x &&
            this->_y < _rhs._y &&
            this->_z < _rhs._z;
    }
    bool operator >
    (PLoc_const_reference _rhs) const 
    {
        return this->_x < _rhs._x &&
            this->_y < _rhs._y &&
            this->_z < _rhs._z;
    }
    bool operator >=
    (PLoc_const_reference _rhs) const 
    {
        return this->_x < _rhs._x &&
            this->_y < _rhs._y &&
            this->_z < _rhs._z;
    }

    _Tp operator[]
    (const size_t & _axis) const 
    {
        assert(_axis >= _axis_x && 
                _axis <= _axis_z);
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
    (PLoc_const_reference _p_loc) const
    {
        return this->_x * _p_loc._x +
                this->_y * _p_loc._y +
                this->_z * _p_loc._z;
    }

    // point euclidean distance(p2p distance)
    _Tp operator^
    (PLoc_const_reference _p_loc) const
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

    _Tp getX() const { return this->_x; }
    _Tp getY() const { return this->_y; }
    _Tp getZ() const { return this->_z; }


    
private:
    _Tp _x, _y, _z;
    static _Tp _min_bound;
    static _Tp _max_bound;
    static uint64_t _inst_cnt;
public:
    static size_t _axis_x;
    static size_t _axis_y;
    static size_t _axis_z;
    static inline uint64_t getInstCnt(){
        return _inst_cnt;
    }

    // template <typename _Tp_ >
    friend std::istream& 
    operator >>(std::istream& _is, 
                PLoc_reference _p_loc)
    {
        INPUT(_is, _p_loc._x),
        INPUT(_is, _p_loc._y),
        INPUT(_is, _p_loc._z);
        return _is;
    }

    // template <typename _Tp_ >
    friend std::ostream& 
    operator <<(std::ostream& _os, 
                PLoc_const_reference _p_loc)
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
};

template <typename _Tp>
uint64_t _Point_Loc<_Tp>::_inst_cnt = 0;
template <typename _Tp>
uint64_t _Point_Loc<_Tp>::_axis_x = 0;
template <typename _Tp>
uint64_t _Point_Loc<_Tp>::_axis_y = 1;
template <typename _Tp>
uint64_t _Point_Loc<_Tp>::_axis_z = 2;

END_NAMESPACE_ALAN

#endif

