#pragma once 
#ifndef _SET_THEORY_HPP
#define _SET_THEORY_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <string>
#include <istream>
#include <ostream>
#include <fstream>

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>


#include <set>
#include <unordered_set>

#include <map>
#include <unordered_map>

#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

__DEF_NS__(Alan)

// Single Set : Atom Operation
// _Tp must overload the operator == when default container 
// _Tp must overload the operator <  when set or multiset
// _Container  recommend std::unordered_set         or std::set
//      do not recommend std::unordered_multiset    or std::multiset
// in addition, stdlib asso_container set overloads: 
//              std::unordered_set      overloads opearator == !=
//              std::set                overloads operator == != < <= > >=
//              std::unordered_multiset overloads opearator == !=
//              std::multiset           overloads operator == != < <= > >=
// 

template <typename _Tp,
            typename _Container = std::unordered_set<_Tp> >
class SSet 
{
public:
    typedef SSet<_Tp>           _SSet;
    typedef SSet<_Tp>&          _SSet_reference;
    typedef const SSet<_Tp>&    _SSet_const_reference;
    typedef SSet<_Tp>*          _SSet_pointer;
    typedef const SSet<_Tp>*    _SSet_const_pointer;

    typedef _Container          container_type;
    typedef _Container&         container_reference;
    typedef _Container&&        container_rreference;
    typedef const _Container&   container_const_reference;
    typedef _Container*         container_pointer;
    typedef const _Container*   container_const_pointer;

    typedef _Tp                 value_type;
    typedef _Tp&                reference;
    typedef const _Tp&          const_reference;
    typedef _Tp*                pointer;
    typedef const _Tp*          const_pointer;


    explicit SSet() noexcept{
        #ifdef DEBUG_MODE
            PRINTLN("null construct");
        #endif 
    }
    SSet(_SSet_reference __sset__){
        #ifdef DEBUG_MODE
            PRINTLN("copy construct");
        #endif
        this->_set_ = __sset__._set_;
    }
    // SSet(container_reference __set__) : _set_(__set__){
    //     #ifdef DEBUG_MODE
    //         PRINTLN("container construct");
    //     #endif 
    // }

    // make no sense
    // has debug but no found any mistakes
    // iterator contruct
    template <class InputIterator>
    SSet(InputIterator _first, InputIterator _last){
        #ifdef DEBUG_MODE
            PRINTLN("iter construct");
        #endif 
        // make no effect
        this->a(container_type(_first, _last));
    }

    // sequential container construct
    SSet(const_pointer _raw_array, size_t __size){
        #ifdef DEBUG_MODE
            PRINTLN("raw_array construct");
        #endif 
        SSet(_raw_array, _raw_array + __size);
    }
    SSet(const std::deque<_Tp> &_deque_){
        #ifdef DEBUG_MODE
            PRINTLN("deque construct");
        #endif 
        SSet(_deque_.begin(), _deque_.end());
    }
    SSet(const std::forward_list<_Tp> &_forward_list_){
        #ifdef DEBUG_MODE
            PRINTLN("forward_list construct");
        #endif 
        SSet(_forward_list_.begin(), _forward_list_.end());
    }
    SSet(const std::list<_Tp> &_list_){
        #ifdef DEBUG_MODE
            PRINTLN("list construct");
        #endif 
        SSet(_list_.begin(), _list_.end());
    }
    SSet(const std::vector<_Tp> &_vector_){
        #ifdef DEBUG_MODE
            PRINTLN("vector construct");
        #endif 
        SSet(_vector_.begin(), _vector_.end());
    }


    // element operation
    bool In(const_reference _element) const{
        return AssoFind<_Tp>(this->_set_, _element);
    }
    bool NotIn(const_reference _element) const{
        return !AssoFind<_Tp>(this->_set_, _element);
    }

    // whether to std::move or copy is a problem
    // after std::move original object is set to null
    // assign
    _SSet_reference operator = (_SSet_const_reference __sset__){
        #ifdef DEBUG_MODE
            PRINTLN("operator SSet assgin");
        #endif 
        this->_set_.clear();
        this->_set_ = __sset__._set_;
        return *this;
    }
    _SSet_reference operator = (container_const_reference __set__){
        #ifdef DEBUG_MODE
            PRINTLN("operator container_type assgin");
        #endif 
        this->_set_.clear();
        this->_set_ = __set__;
        return *this;
    }
    _SSet_reference operator = (const_reference __element){
        #ifdef DEBUG_MODE
            PRINTLN("operator value_type assgin");
        #endif 
        this->_set_.clear();
        this->_set_.insert(__element);
        return *this;
    }

    // math operation
    _SSet_reference operator + (_SSet_const_reference __sset__) const{
        
    }
    _SSet_reference operator + (container_const_reference __set__) const{

    }
    _SSet_reference operator + (const_reference __element) const{

    }
    _SSet_reference operator += (_SSet_const_reference __sset__) {
        for(auto _element : __sset__._set_)
            this->_set_.insert(_element);
        return *this;
    }
    _SSet_reference operator += (container_const_reference __set__) {
        for(auto _element : __set__)
            this->_set_.insert(_element);
        return *this;
    }
    _SSet_reference operator += (const_reference __element) {
        this->_set_.insert(__element);
        return *this;
    }
    _SSet_reference operator - (_SSet_const_reference __sset__) const{
        
    }
    _SSet_reference operator - (container_const_reference __set__) const{

    }
    _SSet_reference operator - (const_reference __element) const{

    }
    _SSet_reference operator -= (_SSet_const_reference __sset__) {
        for(auto _element : __sset__._set_)
            this->_set_.erase(_element);
        return *this;
    }
    _SSet_reference operator -= (container_const_reference __set__) {
        for(auto _element : __set__)
            this->_set_.erase(_element);
        return *this;
    }
    _SSet_reference operator -= (const_reference __element) {
        this->_set_.erase(__element);
        return *this;
    }

    // operation between another 
    // Union
    _SSet_reference operator * (_SSet_const_reference) const;
    _SSet_reference operator * (container_const_reference) const;
    _SSet_reference operator * (const_reference) const;
    _SSet_reference operator *= (_SSet_const_reference);
    _SSet_reference operator *= (container_const_reference);
    _SSet_reference operator *= (const_reference);

    // Intersection
    _SSet_reference operator / (_SSet_const_reference) const;
    _SSet_reference operator / (container_const_reference) const;
    _SSet_reference operator / (const_reference) const;
    _SSet_reference operator /= (_SSet_const_reference);
    _SSet_reference operator /= (container_const_reference);
    _SSet_reference operator /= (const_reference);

    // Complement
    _SSet_reference operator % (_SSet_const_reference) const;
    _SSet_reference operator % (container_const_reference) const;
    _SSet_reference operator % (const_reference) const;
    _SSet_reference operator %= (_SSet_const_reference);
    _SSet_reference operator %= (container_const_reference);
    _SSet_reference operator %= (const_reference);

    // Power 
    std::unordered_set<_SSet> operator ^ (_SSet_const_reference UNUSED) const;
    std::unordered_set<_SSet> operator ^ (container_const_reference UNUSED) const;
    
    // only when container_type is (ordered) 
    //                             std::set<_Tp>
    //                             std::multiset<_Tp>
    // remove the largest element
    _SSet_reference operator ++ ();
    // remove the smallest element
    _SSet_reference operator -- ();

    // equal, not equal
    bool operator == (_SSet_const_reference __sset__) const{
        return this->_set_ == __sset__._set_;
    }
    bool operator == (container_const_reference __set__) const{
        return this->_set_ == __set__;
    }
    bool operator != (_SSet_const_reference __sset__) const{
        return this->_set_ != __sset__._set_;
    }
    bool operator != (container_const_reference __set__) const{
        return this->_set_ != __set__;
    }

    // this is real subset of that, restrict < 
    bool operator < (_SSet_const_reference) const;
    bool operator < (container_const_reference) const;
    // this is subset of that
    bool operator <= (_SSet_const_reference) const;
    bool operator <= (container_const_reference) const;
    // that is real subset of this, restrict >
    bool operator > (_SSet_const_reference) const;
    bool operator > (container_const_reference) const;
    // that is subset of this
    bool operator >= (_SSet_const_reference) const;
    bool operator >= (container_const_reference) const;

    // input, output
    template <typename __Tp__>
    friend std::istream& operator >> (std::istream &__is, 
                                        SSet<__Tp__> &__sset__){
        
        return __is;
    }
    template <typename __Tp__>
    friend std::ostream& operator << (std::ostream &__os, 
                                        const SSet<__Tp__> &__sset__) {
        ConsoleIterOutput<_Tp>(__sset__._set_, ", ");
        return __os;
    }
protected:
    container_type _set_;
    void a(container_rreference __set__) { this->_set_ = std::move(__set__); }
};


// Multiple Sets
// Use SSet as Atom Operation
template<typename _Tp,
            typename _Container = SSet<_Tp> >
class MSet
{
public:
    typedef _Container          container_type;
    typedef _Container&         container_reference;
    typedef const _Container&   container_const_reference;
    typedef _Tp                 value_type;
    typedef _Tp&                reference;
    typedef const _Tp&          const_reference;
    typedef _Tp*                pointer;
    typedef const _Tp*          const_pointer;

    explicit MSet();
    explicit MSet(const _Tp&);
    explicit MSet(container_const_reference);
    explicit MSet(const std::vector<container_type> &);

    // U
    container_type           MUnion() const;
    // I
    container_type           MIntersection() const;
private:
    std::vector<container_type>     m_sets;
};

__END_NS__


__DEF_NS__(Alan::Demos::Test::Func)

void TestSSet();

__END_NS__

#endif 