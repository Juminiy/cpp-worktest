#pragma once 
#ifndef _SEQ_CONTAINER_HPP
#define _SEQ_CONTAINER_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <vector>
#include <deque>

#include <ostream>
#include <algorithm>
#include <iterator>
#include <functional>

void TestConstAndPointer();

void TestAutoBind();

void TestVector();

void TestVectorFunctor();

void TestValArray();

void TestVectorFunctor2();

void TestVectorFunc3();

void TestRingBuffer();

void TestAgainstVectorReverseWithNot();

void TestVigenereEncrypt();

static std::string inline genString(int const &_len)
{
    PSEUDORANDOM_DECL;
    std::string _dest;
    _dest.reserve(_len);
    for(int i=0;i<_len; ++i)
        _dest += _letter_xx[rand()%_letter_len];

    return _dest;
}

USE_NAMESPACE_ALAN

template <typename _Tp, 
            typename _Container = std::deque<_Tp> >
class 
#if (__CC_VER__ == 4)
_LIBCPP_TEMPLATE_VIS
#endif 
RingBuffer {
public:
    typedef _Tp                     value_type;
    typedef value_type&             reference;
    typedef const value_type&       const_reference;
    typedef value_type*             pointer;
    typedef const value_type*       const_pointer;

    typedef _Container              container_type;


    RingBuffer(std::vector<value_type> const & _vi)
    {
        for (auto & _e : _vi)
            ring.push_back(_e);
        cursor = nullptr;
    }
    ~RingBuffer()
    {
        ring.clear();
    }

    void print()
    {
        ConsoleIterOutput<_Tp, container_type > 
                            (ring, ", ");
    }

    void clockwise()
    {
        reference _back = ring.back();
        ring.pop_back();
        ring.push_front(_back);
    }

    void counterclockwise()
    {
        reference _front = ring.front();
        ring.pop_front();
        ring.push_back(_front);
    }

    value_type readAtCursor() const 
    {
        return ring.front();
    }

    void writeAtCursor(const_reference _val)
    {   
        ring.front() = _val;
    }

    [[__nodiscard__]] RingBuffer* operator++ ()
    {
        clockwise();
        return this;
    }

    [[__nodiscard__]] RingBuffer* operator-- ()
    {
        counterclockwise();
        return this;
    }

private: 
    pointer cursor;
    container_type ring;
    
};

END_NAMESPACE_ALAN

void TestConV2();

void TestCopySeq();
#endif 