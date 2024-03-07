#pragma once 
#ifndef _SEQ_CONTAINER_HPP
#define _SEQ_CONTAINER_HPP

#define USE_NAMESPACE_ALAN namespace Alan{
#define END_NAMESPACE_ALAN }

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

USE_NAMESPACE_ALAN

template <typename _Tp, typename _Con = std::deque<_Tp>>
class RingBuffer {
public:
    typedef _Tp value_type;
    typedef _Tp& reference;
    typedef const reference const_reference;
    typedef _Tp* pointer;
    typedef const pointer const_pointer;

    typedef _Con container_type;


    RingBuffer(std::vector<value_type> const & _vi)
    {
        for (auto & _e : _vi)
            ring.push_back(_e);
    }

    void print()
    {
        std::copy(ring.begin(),  
                ring.end(),
                std::ostream_iterator<int>(std::cout, ", "));
        PRINTLN("");
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

    [[nodiscard]] void operator++ ()
    {
        clockwise();
    }

    [[nodiscard]] void operator-- ()
    {
        counterclockwise();
    }

private: 
    pointer cursor;
    container_type ring;
    
};

END_NAMESPACE_ALAN

#endif 