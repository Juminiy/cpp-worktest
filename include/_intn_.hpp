#pragma once
#ifndef _INTN_HPP
#define _INTN_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <iostream>

__DEF_NS__(Alan)

__DEF_NS__(CONST)

using _i64 = signed long long;
using _u64 = unsigned long long;

enum 
{
    CPU_BIT_8 = 8,
    CPU_BIT_16 = 16,
    CPU_BIT_32 = 32,
    CPU_BIT_64 = 64,
    CPU_BIT_128 = 128,
    BASE_2 = 2,
    BASE_8 = 8,
    BASE_10 = 10,
    BASE_16 = 16
};

const size_t _bits_cpu_hold = CPU_BIT_64;
const size_t _base_man_read = BASE_10;

__END_NS__

// def _intn _n(20);
// 1. impl 1 << _n = 1 << 20 & log(_n) ~ 
// 2. impl arithmatic operator overload
// 3. impl signed and unsigned
// 4. impl int64 * _intn
class _intn 
{
public:
    explicit _intn(size_t _base = Alan::CONST::_base_man_read) 
    noexcept 
        : __bit_(Alan::CONST::_bits_cpu_hold), __base_(_base) { 
            __sign_ = true;
            __u64_ = 0;
        }
    
    explicit _intn(std::string & _numv2) 
    noexcept
        : __bit_(), __base_()
    {
        __num_v2_ = std::move(_numv2);
    }

    explicit _intn(const char * _num)
    noexcept 
        : __bit_(), __base_()
    {
        __num_v2_ = _num;
    }


protected:
    const size_t __bit_; 
    const size_t __base_;
    
    std::string  __num_v2_;
    //              true  +
    //              false -
    bool            __sign_;
    union {
        Alan::CONST::_u64 __u64_;
        Alan::CONST::_i64 __i64_;
    };

    typedef struct __chars_{
        char *       __num_;
        size_t       __len_;
    } __chars_;
    // union {
    //     __char_ptr __num_;
    //     std::string __num_v2_;
    // };
private:
    static const size_t _default_bits = Alan::CONST::_bits_cpu_hold;
    static const size_t _default_base = Alan::CONST::_base_man_read;
public:
    friend std::ostream& 
        operator << (std::ostream & __os, const _intn & _num) 
        noexcept
    {
        if (_num.__bit_ <= Alan::CONST::_bits_cpu_hold)
            __os << _num.__i64_;
        else 
            __os << _num.__num_v2_;
        
        return __os;
    }
};

class _int128 
    : public _intn
{

private:
    static const size_t __spec_bit_ = 128;
};

__END_NS__

#endif