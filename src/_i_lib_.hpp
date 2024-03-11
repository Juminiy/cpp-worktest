#pragma once
#ifndef _I_LIB_HPP
#define _I_LIB_HPP

// Alan namespace
#ifdef __cplusplus
extern "C" {
#define USE_NAMESPACE_ALAN namespace Alan{
#define END_NAMESPACE_ALAN }
#endif 
#ifdef __cplusplus
}
#endif



// ATTRI
#define UNUSED __attribute__((unused))
#define NORETURN __attribute__((noreturn))
#define CONSTRUCT __attribute__((constructor))
#define DESTRUCT __attribute__((destructor))



// COLOR decleration
#define _COLOR_BLACK    "0"
#define _COLOR_RED      "1"
#define _COLOR_GREEN    "2"
#define _COLOR_YELLOW   "3"
#define _COLOR_BLUE     "4"
#define _COLOR_PURPLE   "5"
#define _COLOR_CYAN     "6"
#define _COLOR_WHITE    "7"

#define _COLOR_CL(_cl_, _ct_)       ("\033[0;3"+_cl_+_ct_+"\033[0m")
#define _BLACK(_ct_)                ("\033[0;30m"+_ct_+"\033[0m")
#define _RED(_ct_)                  ("\033[0;31m"+_ct_+"\033[0m") 
#define _GREEN(_ct_)                ("\033[0;32m"+_ct_+"\033[0m")
#define _YELLOW(_ct_)               ("\033[0;33m"+_ct_+"\033[0m")
#define _BLUE(_ct_)                 ("\033[0;34m"+_ct_+"\033[0m") 
#define _PURPLE(_ct_)               ("\033[0;35m"+_ct_+"\033[0m")
#define _CYAN(_ct_)                 ("\033[0;36m"+_ct_+"\033[0m") 
#define _WHITE(_ct_)                ("\033[0;37m"+_ct_+"\033[0m")

#define _COLOR_START(_cl_)          PRINT("\033[0;3"+std::string(_cl_)+"m")
#define _COLOR_RECOVER              PRINT("\033[0m")



// PRINT and DECL 
#define PRINT(_ct_)   std::cout << _ct_
#define PRINTLN(_ct_) PRINT(_ct_) << std::endl

#define PSEUDORANDOM_DECL               srand(static_cast<unsigned>(time(NULL)));
#define TILLNOW(_start_time_) (((float)(clock() - _start_time_))/CLOCKS_PER_SEC)

#define DECL_VAR(_type) _type var_##_type
#define DECL_FUN(_type, _func, _arg) _type fun_##_func##_type(_arg);

// need to do more error __DATE__ __FILE__ __LINE__ 
#define LOC_ERR(_err_info_) 



// getopt
#include <iostream>
#include <string>

#include <stdio.h>
#include <ctype.h>
#include <getopt.h>

const std::string short_opts = "h?cwpgot:yd:m:n:v0123456789";
static const struct option long_opts[] = {
    {"help", no_argument, NULL, 'h'},
    {"helps", no_argument, NULL, '?'},
    {"capitals", no_argument, NULL, 'c'},
    {"wchar", no_argument, NULL, 'w'},
    {"print", no_argument, NULL, 'p'},
    {"get", no_argument, NULL, 'g'},
    {"oss-test", no_argument, NULL, 'o'},
    {"stl-test", required_argument, NULL, 't'},
    {"snake-game", no_argument, NULL, 'y'},
    {"draw-triangle", required_argument, NULL, 'd'},
    {"version", no_argument, NULL, 'v'},
    {"read-write-file-test", no_argument, NULL, '0'},
    {"boolalpha-test", no_argument, NULL, '1'},
    {"read-lines-test", no_argument, NULL, '2'},
    {"cin-ate-n-test", no_argument, NULL, '3'},
    {"get-uint64-test", no_argument, NULL, '4'},
    {"get-int64-test", no_argument, NULL, '5'},
    {"multiple-type-oss", no_argument, NULL, '6'},
    {NULL, 0, NULL, 0}
};
static inline void OptUsage() 
{
    printf("Usage:\n");
    printf("\tOption [-h] [-?] [--help] [--helps]\n");
    printf("\tOption [-c] [--capitals]\n");
    printf("\t\tOption [-w] [--wchar]\n");
    printf("\t\tOption [-p] [--print]\n");
    printf("\t\tOption [-g] [--get]\n");
    printf("\tOption [-o] [--oss-test]\n");
    printf("\tOption [-0] [--read-write-file-test]\n");
    printf("\tOption [-1] [--boolalpha-test]\n");
    printf("\tOption [-2] [--read-lines-test]\n");
    printf("\tOption [-3] [--cin-ate-n-test]\n");
    printf("\tOption [-4] [--get-uint64-test]\n");
    printf("\tOption [-5] [--get-int64-test]\n");
    printf("\tOption [-6] [--multiple-type-oss]\n");
}

UNUSED
static unsigned int
opt_uint(char *val)
{
  char *end;
  errno = 0;
  unsigned long int x = strtoul(val, &end, 10);
  if (errno || end == val || (end && *end) )
    printf("Invalid numeric parameter: %s\n", val);
  if ((unsigned long int)(unsigned int) x != x)
    printf("Numeric parameter out of range: %s\n", val);
  return x;
}



// MATH UTILS DEFINE
#define MAX_Tt(_x, _y) ({ \
    typeof(_x) __x = (_x);  \
    typeof(_y) __y = (_y);  \
    __x > __y ? __x : __y;  \
})

#define MIN_Tt(_x, _y) ({ \
    typeof(_x) __x = (_x);  \
    typeof(_y) __y = (_y);  \
    __x < __y ? __x : __y;  \
})

#define I32_POWER2(_i32_) (1 << _i32_)
#define I32_POWER2_EQ(_i32_) (_i32_ = I32_POWER2(_i32_))

#define I32_LSHIFT(_i32_, _bit_) (_i32_ << _bit_) 
#define I32_LSHIFT_EQ(_i32_, _bit_) (_i32_ = I32_LSHIFT(_i32_, _bit_)) 
#define I32_RSHIFT(_i32_, _bit_) (_i32_ >> _bit_) 
#define I32_RSHIFT_EQ(_i32_, _bit_) (_i32_ = I32_RSHIFT(_i32_, _bit_)) 

#define I32_MUL2(_i32_) I32_LSHIFT(_i32_, 1)
#define I32_MUL2_EQ(_i32_) (_i32_ = I32_MUL2(_i32_))
#define I32_MUL8(_i32_) I32_LSHIFT(_i32_, 3)
#define I32_MUL8_EQ(_i32_) (_i32_ = I32_MUL8(_i32_))
#define I32_MUL10(_i32_)  (I32_MUL2(_i32_) + I32_MUL8(_i32_))
#define I32_MUL10_EQ(_i32_) (_i32_ = I32_MUL10(_i32_))

#define I32_CHARIN(_i32_, _ch_)  (_i32_ = (I32_MUL10(_i32_) + (_ch_ - '0')))

// non tested
#define U32 (unsigned int)
#define I32_IN_RANGE(_x, _min, _max) (U32(_x)-U32(_min) <= U32(_max)-U32(_min))
// non tested
#define U8 (unsigned char)
#define I8_IN_RANGE(_x, _min, _max) (U8(_x)-U8(_min) <= U8(_max)-U8(_min))

typedef unsigned long long _ui_64;
typedef signed long long _si_64; 

#define SKP_NON_DIG(_ch)    \
    while (!isdigit(_ch))   \
        _ch = getchar()

#define GET_RES_DIG(_res, _ch)  \
    while (isdigit(_ch))    \
        I32_CHARIN(_res, _ch), _ch = getchar()
 
static inline _ui_64 u64_qread()
{
    char ch = getchar();
    _ui_64 res = 0;
    SKP_NON_DIG(ch);
    GET_RES_DIG(res, ch);
    return res;
}

static inline _si_64 i64_qread()
{
    char ch = getchar();
    bool neg = false;
    _si_64 res = 0;
    while(ch < '0' || ch > '9')
    {
        if (ch == '-') neg = true;
        ch = getchar();
    }
    GET_RES_DIG(res, ch);
    return neg ? ~res+1 : res;
}

// random string generate
const std::string _letter_xx = "qweasdzxcrfvtgbyhnuiojklmp0987612345`-=[];',./~!@#$%+_)(*&^{}|<>?:";
const int _letter_len = 66;

#define INPUT_ERROR 0xff

#endif 