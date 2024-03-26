#pragma once
#ifndef _STL_LIB_ADV_HPP
#define _STL_LIB_ADV_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"
#include <utility>
// #include <type_traits>
#include <memory>
#include <iostream>
#include <numeric>


#if __CC_VER__ == 2
#include <ext/numeric>
#endif 

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

    _Tp getX() const { return this->_x; }
    _Tp getY() const { return this->_y; }
    _Tp getZ() const { return this->_z; }


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



template < 
    template < typename > 
        typename _Container_1, typename _Tp_1,
    template < typename > 
        typename _Container_2, typename _Tp_2 >
std::enable_if_t< 
    _infer_container<_Container_1<_Tp_1 >, 
                    _Container_2<_Tp_2 > >::value, 
    __CON_TP_TRAITS__(_Container_1, _Tp_1, 
                    _Container_2, _Tp_2 ) >
_t_plus(const _Container_1<_Tp_1 > & __container_1,
                const _Container_2<_Tp_2 > & __container_2)
{
    auto _ret = 
        __CON_TP_TRAITS__(_Container_1, _Tp_1, 
                        _Container_2, _Tp_2 ) ();
    auto _iter_1t = __container_1.begin();
    auto _iter_1e = __container_1.end();
    auto _iter_2t = __container_2.begin();
    auto _iter_2e = __container_2.end();

    for(; _iter_1t != _iter_1e &&
            _iter_2t != _iter_2e;
        ++ _iter_1t, ++ _iter_2t)
        // TODO: how to define whether a < class > 
        // has a function member???
        _ret.emplace_back(*_iter_1t + *_iter_2t);

    for(; _iter_1t != _iter_1e;
        ++ _iter_1t)
        _ret.emplace_back(*_iter_1t);
    
    for(; _iter_2t != _iter_2e;
        ++ _iter_2t)
        _ret.emplace_back(*_iter_2t);

    return _ret;
}



// template <typename _Tp_1, 
//             typename _Tp_2 >
// bool _type_equal(_Tp_1 _tp_1_val,
//                 _Tp_2 _tp_2_val )
// {
//     if (constexpr std::is_same_v(_tp_1_val, int) ||
//         constexpr std::is_same_v(_tp_2_val, int))
//     {
//         return true;
//     } else 
//     {
//         return false;
//     }
// }


END_NAMESPACE_ALAN

#endif

