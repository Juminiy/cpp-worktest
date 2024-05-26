#pragma once
#ifndef _STL_BIT_HPP
#define _STL_BIT_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <cassert>

__DEF_NS__(Alan)

#if (__CC_VER__ >= 2)

// binary __x read from left to right, the last bit(1):one location 
// return : 1, 2, 3, ...32, only if __x == 0 return 0
// 0X00001000 -> 13
// 0X000E0000 -> 18
// 0X00000000 -> 0
//                       | l| ll                    int|long|long long
#define __last_oloc(__x, __ll) __builtin_ffs ##__ll(__x)

// binary of __x prefix zero counts
// 0X00001000 -> 19
// 0X000E0000 -> 12
// 0X00000000 -> #UB
//                         |l|ll                    unsigned (int|long|long long)
#define __pref_zcount(__x, __ll) __builtin_clz ##__ll(__x) // count lead zero

// binary of __x suffix zero counts
// 0X00001000 -> 12
// 0X000E0000 -> 17
// 0X00000000 -> #UB
//                         | l| ll                    unsigned (int|long|long long)
#define __suff_zcount(__x, __ll) __builtin_ctz ##__ll(__x) // count tail zero

// binary of __x prefix sign counts
// 0X00001000 -> 19
// 0X000E0000 -> 12
// 0X00000000 -> #UB
//                         | l| ll                       int|long|long long
#define __pref_scount(__x, __ll) (__builtin_clrsb ##__ll(__x) + 1)

// binary __x bit(1):one counts
// 0X00001000 -> 1
// 0X000E0000 -> 3
// 0X00000000 -> 0
//                    | l| ll                         unsigned (int|long|long long)
#define __ocount(__x, __ll) __builtin_popcount ##__ll(__x)

// binary __x bit(1):one counts odd 
// 0X00001000 -> 1
// 0X000E0000 -> 1
// 0X00000000 -> 0
//                        | l| ll                       unsigned (int|long|long long)
#define __ocount_odd(__x, __ll) __builtin_parity ##__ll(__x)

#endif

// __x : (unsigned) int, long, long long
// __y : 0,1,2...63 | 0,1,2...31
// return: 0 | 1
#define __bit_get(__x, __y) ((__x >> __y) & 1)

// __x : (unsigned) int, long, long long
// __y : 0,1,2...63 | 0,1,2...31
// return: fn(x)
#define __bit_setz(__x, __y) (__x & ~(1 << __y))
#define __bit_seto(__x, __y) (__x | (1 << __y))
#define __bit_flip(__x, __y) (__x ^ (1 << __y))

#define __hamming_code(__x) __ocount(__x, )
#define __hamming_perm(__n, __var, __fn) \
        do{ \
            for (int i = 0; (1<<i)-1 <= __n; i++) { \
            for (int __var = (1<<i)-1, t; \
                __var <= __n; \
                t = __var+(__var&-__var), \
                __var = __var ? (t|((((t&-t)/(__var&-__var))>>1)-1)) : (__n+1)) { \
            __fn }} \
        }while(0)


// int32 max value
GEN_FUNC_COPY
int __i32_max_(int __x, int __y)
{
    return (__y & ((__x - __y) >> 31)) | 
            (__x & (~(__x - __y) >> 31));
}

// int32 min value
GEN_FUNC_COPY
int __i32_min_(int __x, int __y)
{
    return (__x & ((__x - __y) >> 31)) |
            (__y & (~(__x - __y) >> 31));
}

// int32 absolutely value
GEN_FUNC_COPY
int __i32_abs_(int __i)
{
    return (__i ^ (__i >> 31)) - (__i >> 31);
}

// int32 same sign
GEN_FUNC_COPY
bool __i32_same_sign_(int __x, int __y)
{
    assert(__x && __y);
    return (__x ^ __y) >= 0;
}

// equal to __x * ( 1 << __y)
GEN_FUNC_COPY
int __i32_mpow2_(int __x, int __y)
{
    assert(__y > -1 && __y < 32);
    return __x << __y;
}

// equal to __x / ( 1 << __y)
GEN_FUNC_COPY
int __i32_dpow2_(int __x, int __y)
{
    assert(__y > -1 && __y < 32);
    return __x >> __y;
}

// set of bit
#define __bit_itersection(__s, __t) (__s & __t)
#define __bit_union(__s, __t) (__s | __t)
#define __bit_complement(__s) (~__s)
#define __bit_diff(__s, __t) (__s & ~(__t))
#define __bit_sdiff(__s, __t) (__s ^ __t)

// numeric pow2
#define __mod_pow2(__x, __p) (__x & (__p - 1))
// __x > 0
#define __is_pow2(__x) (__x > 0 && !(__x & (__x - 1)))


__END_NS__

#endif