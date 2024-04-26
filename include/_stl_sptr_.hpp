#pragma once
#ifndef _STL_SPTR_HPP
#define _STL_SPTR_HPP

#include "_i_lib_.hpp"

__DEF_NS__(Alan::Demos)

template < typename _Tp >
class _Smart_ptr  
{
public:
    __DEF_TPL__(_Tp);
    __DEF_ALL_V2__(sptr, _Smart_ptr);
    #define REF_CNT_INIT 1
    #define REF_CNT_ZERO 0

    explicit _Smart_ptr(pointer _rsc_ptr){
        this->__data = 
            new Intermediary(_rsc_ptr);
    }

    // TODO:
    // 1. new _Tp normal constructor to sptr
    // 2. new _Tp variable (...Args) constructor to sptr


    ~_Smart_ptr(){
        detach();
    }

    _Smart_ptr(sptr_const_reference __sptr_){
        attach(__sptr_.__data);
    }
    _Smart_ptr(sptr_r_reference __sptr_){
        attach(__sptr_.__data);
    }

    sptr_reference operator = 
    (sptr_const_reference __sptr_){
        if (this != &__sptr_)
        {
            detach();
            attach(__sptr_.__data);
        }
        return *this;
    }
    sptr_reference operator = 
    (sptr_r_reference __sptr_){
        if (this != &__sptr_)
        {
            detach();
            attach(__sptr_.__data);
        }
        return *this;
    }

    // TODO:
    // copy on write is not finished
    // do not wanna every non-const object 
    // function call to _cow() 
    // only when 1. non-const object (already make sure)
    //           2. non-const object.func(...) call
    reference operator *
    () {
        _cow();
        return *this->__data->__rsc;
    }
    const_reference operator *
    () const
    {
        return *this->__data->__rsc;
    }
    pointer operator -> 
    () {
        _cow();
        return this->__data->__rsc;
    }
    pointer_to_const operator -> 
    () const
    {
        return this->__data->__rsc;
    }

    pointer data
    () const 
    {
        return this->__data->__rsc;
    }
    size_type count
    () const 
    {
        return this->__data->__cnt;
    }
    bool unique() const 
    {
        return this->count() == 
                REF_CNT_INIT;
    }

    void reset(pointer _rsc_ptr)
    {
        detach();
        this->__data = 
            new Intermediary(_rsc_ptr);
    }

private:
    class Intermediary
    {   
    public:
        explicit Intermediary
            (pointer __rsc_ = nullptr,
            size_type __cnt_ = REF_CNT_INIT) 
            : __rsc(__rsc_), __cnt(__cnt_) { }
        pointer __rsc;
        size_type __cnt;
    };
    Intermediary * __data;
    void detach(){
        -- this->__data->__cnt;
        if(this->__data->__cnt ==
            REF_CNT_ZERO)
        {
            delete this->__data->__rsc;
            delete this->__data;
        }
    }
    void attach(Intermediary * __inter_data_){
        this->__data = __inter_data_;
        ++ this->__data->__cnt;
    }
    // when write to __rsc
    void _cow() {
        detach();
        // to make a deep copy on __rsc
        if (this->__data != nullptr && 
            this->__data->__rsc != nullptr && 
            !unique())
            this->__data = 
                new Intermediary(
                    new _Tp(*this->__data->__rsc)
                );
    }   

};

__END_NS__

__DEF_NS__(Alan)

template < typename _Tp >
GEN_FUNC_COPY
std::shared_ptr< _Tp >
__unique_2_shared_
(std::unique_ptr<_Tp> & __uptr_)
{
    return __uptr_ ? 
        std::shared_ptr<_Tp>(__uptr_.release()) :
        nullptr;
}


template < typename _Tp >
GEN_FUNC_COPY
std::shared_ptr< _Tp >
__unique_2_shared_
(std::unique_ptr<_Tp> && __uptr_)
{
    return __uptr_ ? 
        std::shared_ptr<_Tp>(__uptr_.release()) :
        nullptr;
}


__END_NS__

#endif