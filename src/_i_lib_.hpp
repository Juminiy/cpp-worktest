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



// ONLY FOR Cross Platform and Protable
// istruction set architecture
#if defined(__x86_64__) || \
    defined(__x86_64) || \
    defined(__amd64__) || \
    defined(__amd64)
    #define __ISA_VER__ 64

#elif defined(__aarch64__)
    #define __ISA_VER__ 32

#elif defined(__arm__)
    #if defined(__ARM_ARCH_5T__)
        #define __ISA_VER__ 10
    #elif defined(__ARM_ARCH_7A__)
        #define __ISA_VER__ 9
    #else
        #define __ISA_VER__ 8
    #endif

#elif defined(__i386__)
    #define __ISA_VER__ 4

#elif defined(__powerpc64__)
    #define __ISA_VER__ 2

#elif defined(risc_v)
    #define __ISA_VER__ 1

#else
    #define __ISA_VER__ 0

#endif 


// operating system
#if defined(__unix__) || \
    defined(__unix) || \
    defined(unix)
    #define __OS_VER__ 8

#elif defined(__linux__)
    #define __OS_VER__ 4

#elif defined(__APPLE__) || \
        defined(__MACH__) || \
        defined(__MACOS__)
    #define __OS_VER__ 2

#elif defined(_WIN64) || \
        defined(WIN64) || \
        defined(_WIN32) || \
        defined(WIN32)
    #define __OS_VER__ 1

#else
    #define __OS_VER__ 0

#endif


// memory layout
#if defined(_LP64) || \
    defined(__LP64__) 
    #define __MEM_LAY__ 1
#endif 


// c/cxx compiler
#if defined(__GNUC__)
    #undef __CC_VER__
    #define __CC_VER__ 8
#endif 

#if defined(__clang__) || \
        defined(__llvm__)
    #undef __CC_VER__
    #define __CC_VER__ 4
#endif 

#if defined(__MINGW64__) || \
        defined(__MINGW32__) || \
        defined(__CYGWIN64__) || \
        defined(__CYGWIN__) || \
        defined(__MSYS__)
    #undef __CC_VER__
    #define __CC_VER__ 2
#endif 

#if defined(_MSC_VER)
    #undef __CC_VER__
    #define __CC_VER__ 1
#endif 

// c/cxx lib

#define __STRFY__(__expr_x__) #__expr_x__
#define __TOSTR__(__expr_x__) __STRFY__(__expr_x__)
#define __PORTABLE__ \
        __TOSTR__(__ISA_VER__) __TOSTR__(__OS_VER__) __TOSTR__(__CC_VER__)



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
// add va_list 
#define PRINT(_ct_)   std::cout << _ct_
#define PRINTLN(_ct_) PRINT(_ct_) << std::endl
#define PRINT_DETAIL(_ct_) std::cout << #_ct_ << " = " << _ct_
#define PRINTLN_DETAIL(_ct_) PRINT_DETAIL(_ct_) << std::endl
#define PRINT_VA(_ct_, ...) \
    do {\
        printf(_ct_ __VA_OPT__(,) __VA_ARGS__);\
    }while(0)
#define PRINTLN_VA(_ct_, ...) \
    do {\
        printf(_ct_ __VA_OPT__(,) __VA_ARGS__);\
        puts("");\
    }while(0)

#define PSEUDORANDOM_DECL               srand(static_cast<unsigned>(time(NULL)))
#define TILLNOW(_start_time_) (((float)(clock() - _start_time_))/CLOCKS_PER_SEC)

#define DECL_VAR(_type) _type var_##_type
#define DECL_FUN(_type, _func, _arg) _type fun_##_func##_type(_arg)

// need to do more error 
// __DATE__, __TIME__, __FILE__, __LINE__
// more easy to locate error
#define LOG_ERR(_err_info_, ...) \
        PRINTLN_VA("error_info = %s" \
                    "Date = %s" \
                    "Time = %s" \
                    "File = %s" \
                    "Line = %d", \
                    _err_info_ \
                    __VA_OPT__(,) \
                    __VA_ARGS__ )
#define LOGLN_ERR(_err_info_, ...) \
        PRINTLN_VA("error_info = %s\n" \
                    "Date = %s\n" \
                    "Time = %s\n" \
                    "File = %s\n" \
                    "Line = %d", \
                    _err_info_ \
                    __VA_OPT__(,) \
                    __VA_ARGS__ )


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

#if (__CC_VER__ == 8 || \
        __CC_VER__ == 2) 
    #undef __TYPE_OF__
    #define __TYPE_OF__(__x__) typeof(__x__)
#elif (__CC_VER__ == 4)
    #undef __TYPE_OF__
    #define __TYPE_OF__(__x__) __typeof__(__x__)
#endif 

// MATH UTILS DEFINE
#define MAX_Tt(_x, _y) ({ \
    __TYPE_OF__(_x) __x = (_x);  \
    __TYPE_OF__(_y) __y = (_y);  \
    __x > __y ? __x : __y;  \
})

#define MIN_Tt(_x, _y) ({ \
    __TYPE_OF__(_x) __x = (_x);  \
    __TYPE_OF__(_y) __y = (_y);  \
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