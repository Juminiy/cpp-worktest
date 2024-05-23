#pragma once
#ifndef _POINT_LOC_HPP
#define _POINT_LOC_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <utility>
#include <memory>
#include <iostream>
#include <numeric>
#include <cstdint>
#include <cstddef>

#if __CC_VER__ == 2
#include <ext/numeric>
#endif 

#include <cassert>

__DEF_NS__(Alan)

// TODO:
// 
// 1. template _Tp constraint
//  (1). _Tp must overload < 
//  (2). when calculate _Point_Loc distance 
//      _Tp must be int_type, real_type
// 2. member variable constraint
// 3. member function constraint
// 4. ...

#ifdef DEBUG_MODE
#undef DEBUG_MODE
#endif
template <typename _Tp >
class _Point_Loc
{
public:
    // _Point_Loc typedef Macro
    __DEF_TPL__(_Tp);
    __DEF_ALL_V2__(PLoc, _Point_Loc);

    // _Point_Loc constructor
    // (0)
    explicit _Point_Loc(
            _Tp __x__ = _Tp(), 
            _Tp __y__ = _Tp(), 
            _Tp __z__ = _Tp())
        : _x(__x__), _y(__y__), _z(__z__)     {
            #ifdef DEBUG_MODE
                PRINTLN("args constructor");
            #endif 
            ++ this->_inst_cnt;
        }
    // conflict with above (0)
    // _Point_Loc() 
    //     : _x(_Tp()), _y(_Tp()), _z(_Tp())   {
    //         ++ this->_inst_cnt;
    //     }
    
    // _Tp value r_reference???
    // invalid with above (2)
    // 2024.04.19 _Tp &&: universal reference 
    //                      not rvalue reference
    // _Point_Loc(_Tp &&__x, _Tp &&__y, _Tp &&__z)
    //     : _x(std::move(__x)),
    //         _y(std::move(__x)), 
    //         _z(std::move(__x))         {}

    // _Point_Loc destructor
    ~_Point_Loc(){
        #ifdef DEBUG_MODE
            PRINTLN("destructor");
        #endif 
        -- this->_inst_cnt;
    }
    

    // (1)
    // const reference parameter, constructor
    // do not use const_reference, or will conflict 
    //                      with move constructor(2)
    // call example:
    // _val has a name, is lvalue
    // auto _cpy0 = _val;
    // auto _cpy1(_val);
    // but fact that reference parameter occur compile error
    // _Point_Loc(PLoc_reference _rhs)
    //     : _x(_rhs._x), _y(_rhs._y), _z(_rhs._z) {
    //         #ifdef DEBUG_MODE
    //             PRINTLN("copy constructor");
    //         #endif 
    //         ++ this->_inst_cnt;
    //     }
    _Point_Loc(PLoc_const_reference _rhs)
        : _x(_rhs._x), _y(_rhs._y), _z(_rhs._z) {
            #ifdef DEBUG_MODE
                PRINTLN("const copy constructor");
            #endif 
            ++ this->_inst_cnt;
        }
    // (2)
    // rvalue reference parameter, constructor
    // call example:
    // 1. move semantic and destructor
    //  f32p_vec.push_back(decltype(f32_p1)(1.0, 2.3, 4.5));
    // 2. inplace constructor and move semantic and destructor
    //  f32p_vec.emplace_back(1.0, 2.3, 4.5); 
    _Point_Loc(PLoc_r_reference _rhs)
        : _x(_Tp()), _y(_Tp()), _z(_Tp()) {
            #ifdef DEBUG_MODE
                PRINTLN("move constructor");
            #endif 
            _swap(*this, _rhs);
            ++ this->_inst_cnt;
        }
    
    // operator assign
    // value parameter, operator assign
    // replace following two version
    // call example:
    // ???
    // PLoc_reference operator =
    // (PLoc _rhs)
    // {
    //     #ifdef DEBUG_MODE
    //         PRINTLN("operator assign");
    //     #endif 
    //     _swap(*this, _rhs);
    //     return *this;
    // }
    // const reference parameter, operator assign
    PLoc_reference operator =
    (PLoc_const_reference _rhs)
    {   
        if (this != &_rhs){
            this->_x = _rhs._x;
            this->_y = _rhs._y;
            this->_z = _rhs._z;
        }
        return *this;
    }
    // rvalue reference parameter, operator assign
    PLoc_reference operator =
    (PLoc_r_reference _rhs)
    {   
        if (this != &_rhs){
            this->_x = _rhs._x;
            this->_y = _rhs._y;
            this->_z = _rhs._z;
        }
        return *this;
    }

    PLoc_reference operator +=
    (PLoc_const_reference _rhs)
    {
        this->_x += _rhs._x;
        this->_y += _rhs._y;
        this->_z += _rhs._z;
        return *this;
    }
    PLoc_reference operator -=
    (PLoc_const_reference _rhs)
    {
        this->_x -= _rhs._x;
        this->_y -= _rhs._y;
        this->_z -= _rhs._z;
        return *this;
    }
    // scale by const_type
    PLoc_reference operator *=
    (const_type _scale)
    {
        this->_x *= _scale;
        this->_y *= _scale;
        this->_z *= _scale;
        return *this;
    }
    PLoc_reference operator /=
    (const_type _scale)
    {   
        assert(_scale != _Tp());
        this->_x /= _scale;
        this->_y /= _scale;
        this->_z /= _scale;
        return *this;
    }
    PLoc_reference operator %=
    (const_type _scale)
    {
        assert(_scale != _Tp());
        this->_x %= _scale;
        this->_y %= _scale;
        this->_z %= _scale;
        return *this;
    }


    // inner product
    _Tp operator *
    (PLoc_const_reference _rhs) const
    {
        return this->_x * _rhs._x +
                this->_y * _rhs._y +
                this->_z * _rhs._z;
    }
    // point euclidean distance(p2p distance)
    _Tp operator ^
    (PLoc_const_reference _rhs) const
    {
        // return (this->_x - _rhs._x) *
        //         (this->_x - _rhs._x) +
        //         (this->_y - _rhs._y) *
        //         (this->_y - _rhs._y) +
        //         (this->_z - _rhs._z) *
        //         (this->_z - _rhs._z);
        return Sqrt<_Tp >
                (Power<_Tp >(this->_x - _rhs._x , 2) + 
                    Power<_Tp >(this->_y - _rhs._y , 2) + 
                    Power<_Tp >(this->_z - _rhs._z , 2));
    }
    
    // increment/decrement operator
    PLoc_reference operator ++
    () const 
    {
        // operate *this ...
        return *this;
    }
    PLoc_const operator ++
    (int) const 
    {   
        auto _p_loc = *this;
        // operate *this ...
        return _p_loc;
    }
    PLoc_reference operator --
    () const 
    {
        // operate *this ...
        return *this;
    }
    PLoc_const operator --
    (int) const 
    {   
        auto _p_loc = *this;
        // operate *this ...
        return _p_loc;
    }

    // dereference
    PLoc_reference operator *
    () const
    {
        return *this;
    }

    // member selection by -> 
    PLoc_pointer operator ->
    () const 
    {
        return *this;
    }

    // member selection by [axis]
    reference operator [] 
    (const size_t & _axis) 
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
        default:
            return this->_z;
        }
    }
    const_reference operator [] 
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
        default:
            return this->_z;
        }
    }


    // comparation operator 
    // when use STL oly define < is ok
    // otherwise define all six comparation
    // some case low efficiency, good idea 
    // to overload operator == explicit
    bool operator < 
    (PLoc_const_reference _rhs) const 
    {
        return (this->_x < _rhs._x &&
                this->_y < _rhs._y &&
                this->_z < _rhs._z) 
                || (this->_micro_sum() < 
                    _rhs._micro_sum());
    }
    bool operator == 
    (PLoc_const_reference _rhs) const 
    {
        return (this == &_rhs) || 
                (this->_x == _rhs._x &&
                this->_y == _rhs._y && 
                this->_z == _rhs._z);
    }
    bool operator <= 
    (PLoc_const_reference _rhs) const 
    {
        return *this < _rhs ||
                *this == _rhs;
    }
    bool operator != 
    (PLoc_const_reference _rhs) const 
    {
        return !(*this == _rhs);
    }
    bool operator > 
    (PLoc_const_reference _rhs) const 
    {
        return _rhs < *this;
    }
    bool operator >= 
    (PLoc_const_reference _rhs) const 
    {
        return *this > _rhs ||
                *this == _rhs;
    }

    // function call operator
    void operator ()
    () const 
    {
        // do something ....
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

    _Tp getX() const 
    { return this->_x; }
    _Tp getY() const 
    { return this->_y; }
    _Tp getZ() const 
    { return this->_z; }

    void setX(r_reference __x__) 
    { this->_x = __MV_RREF__(__x__); }
    void setY(r_reference __y__) 
    { this->_y = __MV_RREF__(__y__); }
    void setZ(r_reference __z__) 
    { this->_z = __MV_RREF__(__z__); }


private:
    _Tp _x, _y, _z;
    // when initial _min_bound and _max_bound 
    // _Tp must int_type, real_type
    static const _Tp _min_bound;
    static const _Tp _max_bound;
    static size_t _inst_cnt;
    _Tp _micro_sum() const {
        return _x + _y + _z;
    }
    
    GEN_FUNC_COPY
    void _swap
    (PLoc_reference _lhs, PLoc_reference _rhs)
    noexcept {
        std::swap(_lhs._x, _rhs._x);
        std::swap(_lhs._y, _rhs._y);
        std::swap(_lhs._z, _rhs._z);
    }


public:
    static const size_t _axis_x;
    static const size_t _axis_y;
    static const size_t _axis_z;

    GEN_FUNC_COPY
    size_t getInstCnt(){
        return _inst_cnt;
    }

    // template <typename _Tp_ >
    friend std::istream& 
    operator >> (std::istream& _is, 
                PLoc_reference _rhs)
    {
        INPUT(_is, _rhs._x),
        INPUT(_is, _rhs._y),
        INPUT(_is, _rhs._z);
        return _is;
    }

    // template <typename _Tp_ >
    friend std::ostream& 
    operator << (std::ostream& _os, 
                PLoc_const_reference _rhs)
    {
        OUTPUT(_os, "("),
        OUTPUT(_os, _rhs._x),
        OUTPUT(_os, ", "),
        OUTPUT(_os, _rhs._y),
        OUTPUT(_os, ", "),
        OUTPUT(_os, _rhs._z),
        OUTPUT(_os, ")");
        return _os;
    }
    
    // math operator overload
    PLoc_const operator +
    () const
    {
        return PLoc(+this->_x, 
                    +this->_y, 
                    +this->_z);
    }
    PLoc_const operator +
    (PLoc_const_reference _rhs) const
    {
        auto _p_cp = *this;
        _p_cp += _rhs;
        return _p_cp;
    }
    // different templates version
    template < typename __Tp__ >
    auto 
    operator +
    (const _Point_Loc<__Tp__ > & _rhs) const 
    -> const _Point_Loc<__TP_PLUS_TRAITS__(_Tp, __Tp__) >
    {
        auto _ploc = 
            _Point_Loc<__TP_PLUS_TRAITS__(_Tp, __Tp__) >();
        _ploc.setX(this->_x + _rhs.getX());
        _ploc.setY(this->_y + _rhs.getY());
        _ploc.setZ(this->_z + _rhs.getZ());
        return _ploc;
    }
    PLoc_const operator -
    () const 
    {
        return PLoc(-this->_x, 
                    -this->_y, 
                    -this->_z);
    }
    PLoc_const operator -
    (PLoc_const_reference _rhs) const
    {
        auto _p_cp = *this;
        _p_cp -= _rhs;
        return _p_cp;
    }
    template < typename __Tp__ >
    auto 
    operator -
    (const _Point_Loc<__Tp__ > & _rhs) const 
    -> const _Point_Loc<__TP_PLUS_TRAITS__(_Tp, __Tp__) >
    {
        auto _ploc = 
            _Point_Loc<__TP_PLUS_TRAITS__(_Tp, __Tp__) >();
        _ploc.setX(this->_x - _rhs.getX());
        _ploc.setY(this->_y - _rhs.getY());
        _ploc.setZ(this->_z - _rhs.getZ());
        return _ploc;
    }

    // scale point by const_type
    PLoc_const operator *
    (const_type _scale) const
    {
        auto _p_cp = *this;
        _p_cp *= _scale;
        return _p_cp;
    }
    PLoc_const operator /
    (const_type _scale) const
    {
        auto _p_cp = *this;
        _p_cp /= _scale;
        return _p_cp;
    }
    PLoc_const operator %
    (const_type _scale) const
    {
        auto _p_cp = *this;
        _p_cp %= _scale;
        return _p_cp;
    }


};

template <typename _Tp>
size_t _Point_Loc<_Tp>::_inst_cnt(0);
template <typename _Tp>
const size_t _Point_Loc<_Tp>::_axis_x(0);
template <typename _Tp>
const size_t _Point_Loc<_Tp>::_axis_y(1);
template <typename _Tp>
const size_t _Point_Loc<_Tp>::_axis_z(2);

template<typename _Tp >
const _Point_Loc<_Tp >
operator * 
(const _Tp _scale, const _Point_Loc<_Tp > & _rhs)
{
    auto _p_loc = _rhs;
    _p_loc *= _scale;
    return _p_loc;
}

__END_NS__

#endif

