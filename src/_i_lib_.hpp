#pragma once
#ifndef _I_LIB_HPP
#define _I_LIB_HPP

#ifdef __cplusplus
extern "C" {
#endif 
using namespace std;
#ifdef __cplusplus
}
#endif

#define UNUSED __attribute__((unused))
#define NORETURN __attribute__((noreturn))
#define CONSTRUCT __attribute__((constructor))
#define DESTRUCT __attribute__((destructor))

#define PRINTLN(x) std::cout << x << std::endl

#define RED_STR(str) ("\033[1;31m"+str+"\033[0m")
#define RED_I32(_i32) ("\033[1;31m"+std::to_string(_i32)+"\033[0m")

#define DECL_VAR(_type) _type var_##_type
#define DECL_FUN(_type, _func, _arg) _type fun_##_func##_type(_arg);

#define MAX_T(_x, _y) ((_x) > (_y) ? (_x) : (_y))
#define MIN_T(_x, _y) ((_x) < (_y) ? (_x) : (_y))


static inline int max_i32(int x, int y)
{
    return x > y ? x : y;
}

static inline double max_f64(double x, double y)
{
    return x > y ? x : y;
}


#include <string>

#include <stdio.h>
#include <ctype.h>
#include <getopt.h>


const string short_opts = "h?cwpgotyd:m:n:v0123456789";
static const struct option long_opts[] = {
    {"help", no_argument, NULL, 'h'},
    {"helps", no_argument, NULL, '?'},
    {"capitals", no_argument, NULL, 'c'},
    {"wchar", no_argument, NULL, 'w'},
    {"print", no_argument, NULL, 'p'},
    {"get", no_argument, NULL, 'g'},
    {"oss-test", no_argument, NULL, 'o'},
    {"draw-triangle", required_argument, NULL, 'd'},
    {"version", no_argument, NULL, 'v'},
    {"snake-game", no_argument, NULL, 'y'},
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

#define U32 (unsigned int)
#define I32_IN_RANGE(_x, _min, _max) (U32(_x)-U32(_min) <= U32(_max)-U32(_min))

typedef unsigned long long _ui_64;
typedef signed long long _si_64; 

#define SKP_NON_DIG(_ch) while (_ch < '0' || _ch > '9') _ch = getchar()
#define GET_RES_DIG(_res, _ch)  while (isdigit(_ch)) _res = (_res << 1) + (_res << 3) + (_ch - 48), _ch = getchar()


//     12345   
static inline _ui_64 u64_qread()
{
    char ch = getchar();
    _ui_64 res = 0;
    SKP_NON_DIG(ch);
    GET_RES_DIG(res, ch);
    return res;
}

//     -12345 |     12345
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

CONSTRUCT
static void inline call_main()
{
    printf("Hi, Worktest, Compile time: %s\n", __TIME__);
}

DESTRUCT
static void inline exit_main()
{
    printf("iH, Worktest, Exit time: %s\n", __TIME__);
}

#endif 