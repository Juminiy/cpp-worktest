#pragma once 
#ifndef _SET_THEORY_HPP
#define _SET_THEORY_HPP

#include "_i_lib_.hpp"
#include "_set_theory_.hpp"
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

USE_NAMESPACE_ALAN

// Single Set
// Atom Operation
// _Tp must overload the operator == 
// extends unordered_set or set, do not recommand multiset
template <typename _Tp,
            typename _Container = std::unordered_set<_Tp> >
class SSet 
{
public:
    typedef _Container          container_type;
    typedef _Container&         container_reference;
    typedef const _Container&   const_container_reference;
    typedef _Tp                 value_type;
    typedef _Tp&                reference;
    typedef const _Tp&          const_reference;
    typedef _Tp*                pointer;
    typedef const _Tp*          const_pointer;

    SSet(){
        #ifdef DEBUG_MODE
            PRINTLN("null construct");
        #endif 
    }
    SSet(const_container_reference __set__){
        #ifdef DEBUG_MODE
            PRINTLN("copy construct");
        #endif 
        this->_set_ = std::move(__set__);
    }

    // iterator contruct
    template <class InputIterator>
    SSet(InputIterator _first, InputIterator _last){
        #ifdef DEBUG_MODE
            PRINTLN("iter construct");
        #endif 
        this->_set_ = container_type(_first, _last);
    }

    // sequential container construct
    // explicit SSet(const std::array<_Tp> &_array_){
    //     SSet(_array_.begin(), _array_.end());
    // }
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
        return AssoFind<_Tp>(_set_, _element);
    }
    bool NotIn(const _Tp&_element) const{
        return !AssoFind<_Tp>(_set_, _element);
    }

    // assign
    container_type operator = (const SSet &__sset__){
        #ifdef DEBUG_MODE
            PRINTLN("operator SSet assgin");
        #endif 
        _set_.clear();
        _set_ = std::move(__sset__._set_);
    }
    container_type operator = (const_container_reference __set__){
        #ifdef DEBUG_MODE
            PRINTLN("operator container_type assgin");
        #endif 
        _set_.clear();
        _set_ = std::move(__set__);
    }
    container_type operator = (const_reference __element){
        #ifdef DEBUG_MODE
            PRINTLN("operator value_type assgin");
        #endif 
        _set_.clear();
        _set_.insert(__element);
    }
    container_type operator + (const_container_reference) const;
    container_type operator + (const _Tp&) const;
    container_type operator += (const_container_reference);
    container_type operator += (const _Tp&);
    container_type operator - (const_container_reference) const;
    container_type operator - (const _Tp&) const;
    container_type operator -= (const_container_reference);
    container_type operator -= (const _Tp&);

    // operation between another 
    // Union
    container_type operator * (const_container_reference) const;
    container_type operator * (const_reference) const;
    container_type operator *= (const_container_reference);
    container_type operator *= (const_reference);

    // Intersection
    container_type operator / (const_container_reference) const;
    container_type operator / (const_reference) const;
    container_type operator /= (const_container_reference);
    container_type operator /= (const_reference);

    // Complement
    container_type operator % (const_container_reference) const;
    container_type operator % (const_reference) const;
    container_type operator %= (const_container_reference);
    container_type operator %= (const_reference);

    // power 
    std::unordered_set<container_type> operator ^ (const_container_reference UNUSED) const;
    
    // only when container_type is (ordered) std::set<_Tp>
    // remove the largest element
    container_type operator ++ ();
    // remove the smallest element
    container_type operator -- ();

    // equal, not equal
    bool operator == (const_container_reference) const;
    bool operator != (const_container_reference) const;

    // this is real subset of that, restrict < 
    bool operator < (const_container_reference) const;
    // this is subset of that
    bool operator <= (const_container_reference) const;
    // that is real subset of this, restrict >
    bool operator > (const_container_reference) const;
    // that is subset of this
    bool operator >= (const_container_reference) const;

    // input, output
    friend std::ifstream& operator >> (std::ifstream &__ifs,
                                        const SSet &__sset__) ;
    friend std::istream& operator >> (std::istream &__is, 
                                        const SSet &__sset__) ;
    friend std::ofstream& operator << (std::ofstream &__ofs, 
                                        const SSet &__sset__) ;
    friend std::ostream& operator << (std::ostream &__os, 
                                        const SSet &__sset__) {
        ConsoleIterOutput<_Tp>(__sset__._set_, "\n");
        return __os;
    }
private:
    container_type _set_;
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
    typedef const _Container&   const_container_reference;
    typedef _Tp                 value_type;
    typedef _Tp&                reference;
    typedef const _Tp&          const_reference;
    typedef _Tp*                pointer;
    typedef const _Tp*          const_pointer;

    explicit MSet();
    explicit MSet(const _Tp&);
    explicit MSet(const_container_reference);
    explicit MSet(const std::vector<container_type> &);

    // U
    container_type           MUnion() const;
    // 
    container_type           MIntersection() const;
private:
    std::vector<container_type>     m_sets;
};

void TestSSet();

END_NAMESPACE_ALAN

#endif 