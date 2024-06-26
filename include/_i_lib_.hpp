#pragma once
#ifndef _I_LIB_HPP
#define _I_LIB_HPP

#ifdef __cplusplus
extern "C" {
// 1. can define namespace in header and source file
//	header: .h .hpp (.c[may be a joke])
//	source: .cc .cpp .tcc
#define __DEF_NS__(__ns__) \
        namespace __ns__ {
#define __END_NS__ }

// 2. can use namespace only in source file
// 	source: .cc .cpp .tcc
#define __USE_NS__(__ns__) \
        using namespace __ns__

#define __USE__(__idt__) \
        using __idt__

// 3. define Macro not include in their scopes
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

#elif defined(__riscv__) || \
        defined(__riscv) || \
        defined(_riscv) || \
        defined(__riscv32)
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


// thread model



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
// libstdc++11


// Macro evaluate expression
#define __STRFY__(__expr_x__) #__expr_x__
#define __TOSTR__(__expr_x__) __STRFY__(__expr_x__)
#define __PORTABLE__ \
        __TOSTR__(__ISA_VER__) __TOSTR__(__OS_VER__) __TOSTR__(__CC_VER__)



// GCC Macro attribute
#define UNUSED __attribute__((unused))
#define NORETURN __attribute__((noreturn))
#define CONSTRUCT __attribute__((constructor))
#define DESTRUCT __attribute__((destructor))

#ifdef __cplusplus

	#if __cplusplus >= 201103L
		// #define NORETURN [[noreturn]]
		#define CARRIES_DEP [[carries_dependency]]
	#endif

	#if __cplusplus >= 201402L
		#define DEPRECATED [[deprecated]]
		#define DEPRECATED_OF(__reason_of_) [[deprecated(__reason_of_)]]
	#endif

	#if __cplusplus >= 201703L
		#define FALLTHROUGH [[fallthrough]]
		#define CATCH_RETURN [[nodiscard]]
		#define CATCH_RETURN_OF(__reason_of_) [[nodiscard(__reason_of_)]]
		// #define UNUSED [[maybe_unused]]

	#endif 

	#if __cplusplus >= 202002L
		#define LIKELY [[likely]]
		#define UNLIKELY [[unlikely]]
		#define NO_UNIQUE_ADDRESS [[no_unique_address]]
		
	#endif 
#endif



// COLOR decleration
#define _COLOR_BLACK    0
#define _COLOR_RED      1
#define _COLOR_GREEN    2
#define _COLOR_YELLOW   3
#define _COLOR_BLUE     4
#define _COLOR_PURPLE   5
#define _COLOR_CYAN     6
#define _COLOR_WHITE    7

// color words
#define _COLOR_HEAD "\033[0;3"
#define _COLOR_TAIL "\033[0m"
#define _COLOR_CL(_cl_, _ct_) \
        (_COLOR_HEAD \
        __TOSTR__(_cl_)"m" + \
        std::string(_ct_) + \
        _COLOR_TAIL)
#define _COLOR_CL_VAR(_cl_, _ct_) \
        (_COLOR_HEAD + \
        std::string(_cl_) + \
        "m" + \
        std::string(_ct_) + \
        _COLOR_TAIL)
#define _BLACK(_ct_) \
        _COLOR_CL(_COLOR_BLACK, _ct_)
#define _RED(_ct_) \
        _COLOR_CL(_COLOR_RED, _ct_)
#define _GREEN(_ct_) \
        _COLOR_CL(_COLOR_GREEN, _ct_)
#define _YELLOW(_ct_) \
        _COLOR_CL(_COLOR_YELLOW, _ct_)
#define _BLUE(_ct_) \
        _COLOR_CL(_COLOR_BLUE, _ct_)
#define _PURPLE(_ct_) \
        _COLOR_CL(_COLOR_PURPLE, _ct_)
#define _CYAN(_ct_) \
        _COLOR_CL(_COLOR_CYAN, _ct_)
#define _WHITE(_ct_) \
        _COLOR_CL(_COLOR_WHITE, _ct_)
#define __CT_OF_CL_(_cl_, _ct_) \
        _COLOR_CL(_cl_, std::to_string(_ct_))

#define _COLOR_START(_cl_) \
        PRINT(_COLOR_HEAD \
        __TOSTR__(_cl_)"m")
#define _COLOR_END PRINT(_COLOR_TAIL)
#define _COLOR_RECOVER _COLOR_END



// PRINT and DECL 
// add va_list
#define __LN__ '\n'
#define __FLUSH_LN__ std::endl
#define INPUT(_is_, _ct_) \
        _is_ >> _ct_
#define OUTPUT(_os_, _ct_) \
        _os_ << _ct_
#define OUTPUTLN(_os_, _ct_) \
        OUTPUT(_os_, _ct_) << __LN__
#define OUTPUT_DETAIL(_os_, _ct_) \
        _os_ << #_ct_ << " = " << _ct_
#define OUTPUTLN_DETAIL(_os_, _ct_) \
        OUTPUT_DETAIL(_os_, _ct_) << __LN__
#define __ONEW_LINE__(_os_) \
        _os_ << __LN__
#define NEXT_LINE \
        __CNEW_LINE__

#define HANDINPUT(_ct_) \
        INPUT(std::cin, _ct_)
#define PRINT(_ct_) \
        OUTPUT(std::cout, _ct_)
#define PRINTLN(_ct_) \
        PRINT(_ct_) << __LN__
#define PRINT_DETAIL(_ct_) \
        OUTPUT_DETAIL(std::cout, _ct_)
#define PRINTLN_DETAIL(_ct_) \
        PRINT_DETAIL(_ct_) << __LN__
#define __CNEW_LINE__ \
        __ONEW_LINE__(std::cout)

// TODO:
//      1. show color while show string
//      2. must use last << _id, ignore front all
//      3. use opensource library fmt..., etc
#define OUTPUT_DETAIL_CL(__os__, __cl__, __ct__) \
        __os__ << #__ct__ << " = " << __cl__(__ct__)
#define OUTPUTLN_DETAIL_CL(__os__, __cl__, __ct__) \
        OUTPUT_DETAIL_CL(__os__, __cl__, __ct__) << __LN__
#define PRINT_DETAIL_CL(__cl__, __ct__) \
        OUTPUT_DETAIL_CL(std::cout, __cl__, __ct__)
#define PRINTLN_DETAIL_CL(__cl__, __ct__) \
        PRINT_DETAIL_CL(__cl__, __ct__) << __LN__

#define OUTPUT_USE2(__os__, _attr0, _attr1) \
        __os__._attr0, __os__._attr1;

#define ERR(_ct_) \
        OUTPUT(std::cerr, _ct_)
#define ERRLN(_ct_) \
        ERR(_ct_) << __LN__
#define ERR_DETAIL(_ct_) \
        OUTPUT_DETAIL(std::cerr, _ct_)
#define ERRLN_DETAIL(_ct_) \
        ERR_DETAIL(_ct_) << __LN__



#define PRINT_VA(_ct_, ...) \
    do {\
        printf(_ct_ __VA_OPT__(,) __VA_ARGS__);\
    }while(0)
#define PRINTLN_VA(_ct_, ...) \
    do {\
        printf(_ct_ __VA_OPT__(,) __VA_ARGS__);\
        puts("");\
    }while(0)

#define PSEUDORANDOM_DECL \
        srand(static_cast<unsigned>(time(NULL)))
#define TILLNOW(_start_time_) \
        ((static_cast<float>(clock() - _start_time_))/CLOCKS_PER_SEC)
#define TIME_BASED_SEED \
        std::chrono::system_clock \
        ::now().time_since_epoch() \
        .count()
#define __time_begin__ \
        __USE_NS__(std::chrono); \
        auto _start UNUSED = high_resolution_clock::now(); \
        auto _end UNUSED = _start;
#define __time_dur__ \
        _end = high_resolution_clock::now(); \
        duration_cast<milliseconds>(_end - _start).count();
#define __log_time_now__(__var__) \
        __USE_NS__(std::chrono); \
        auto _now = system_clock::now(); \
        auto _now_timet = system_clock::to_time_t(_now); \
        auto __var__ = std::put_time(std::localtime(&_now_timet), "%Y-%m-%d %H:%M:%S");

#define TSLEEP(__sec_) usleep(__sec_ * 1000000);

#define DECL_VAR(_type) _type var_##_type
#define DECL_FUN(_type, _func, _arg) \
        _type fun_##_func##_type(_arg)

#define GEN_FUNC_COPY \
        static inline
#define __VAR_GLB__ \
        static

#define __LOOP_GLB__(__cond__) \
        for(; __cond__ ;)
#define __LOOP_IF__(__cond__) \
        while(__cond__) {
#define __FI_POOL__ }
#define __LOOP_NIF__(__cond__) \
        while(!__cond__) {
#define __FIN_POOL__ }

#if (__CC_VER__ > 1)
    #include <unistd.h>
#elif (__CC_VER__ == 1)
    #include <windows.h>
#endif
#include <cstring>
#include <cstdlib>

GEN_FUNC_COPY
void __tsleep_(double __sec_)
{
    #if __CC_VER__ >= 4
        usleep(static_cast<int>(__sec_ * 1000000));
    #elif __CC_VER__ == 2
        sleep(__sec_);
    #endif 
}

GEN_FUNC_COPY
char * __tstrdup_(const char * __str_)
{
    #if __CC_VER__ >= 4
        return ::strdup(__str_);
    #elif __CC_VER__ == 2
        char *_dest = static_cast<char *>(malloc(::strlen(__str_) + 1));
        if(!_dest)
            return nullptr;
        ::strcpy(_dest, __str_);
        return _dest;
    #endif 
}


// need to do more error 
// __DATE__, __TIME__, __FILE__, __LINE__
// more easy to locate error
// function is: __func__, __FUNCTION__, 
// full signature is: __PRETTY_FUNCTION__
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
// 1. support for multiple levels(subopt)
// 2. support for multiple args

#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#if (__CC_VER__ > 1)
    #include <getopt.h>
    #include <unistd.h>
#elif (__CC_VER__ == 1)
    #include <windows.h>
#endif

#include <iostream>

// version 2.0 pretty is available and now used

char const * const short_opts = "vgna:l:";

const struct option long_opts[] = 
{
    {"version", no_argument, NULL, 'v' },
    {"game", no_argument, NULL, 'g' },
    {"no_arguments", no_argument, NULL, 'n' },
    {"arguments", required_argument, NULL, 'a' },
    {"level_db", required_argument, NULL, 'l' },//local_data_base(leveldb)
    {NULL, 0, NULL, 0}
};

GEN_FUNC_COPY
void OptUsageV2()
{
    PRINTLN("Usage:");
    PRINTLN("Option [-v] | [--version]");
    PRINTLN("Option [-g] | [--game]");
    PRINTLN("Option [-n] | [--no_arguments]");
    PRINTLN("Option [-a] | [--arguments](...args)");
    PRINTLN("Option [-l] | [--level_db] (...args)");
}

UNUSED GEN_FUNC_COPY
unsigned int opt_uint(char *val)
{
  char *end;
  errno = 0;
  unsigned long int x = ::strtoul(val, &end, 10);
  if (errno || end == val || (end && *end) )
    printf("Invalid numeric parameter: %s\n", val);
  if ((unsigned long int)(unsigned int) x != x)
    printf("Numeric parameter out of range: %s\n", val);
  return x;
}

// version 1.0 has been deprecated

// const std::string short_opts = "h?cwpgot:yd:m:n:v0123456789";

// static const struct option long_opts[] = {
//     {"help", no_argument, NULL, 'h'},
//     {"helps", no_argument, NULL, '?'},
//     {"capitals", no_argument, NULL, 'c'},
//     {"wchar", no_argument, NULL, 'w'},
//     {"print", no_argument, NULL, 'p'},
//     {"get", no_argument, NULL, 'g'},
//     {"oss-test", no_argument, NULL, 'o'},
//     {"stl-test", required_argument, NULL, 't'},
//     {"snake-game", no_argument, NULL, 'y'},
//     {"draw-triangle", required_argument, NULL, 'd'},
//     {"version", no_argument, NULL, 'v'},
//     {"read-write-file-test", no_argument, NULL, '0'},
//     {"boolalpha-test", no_argument, NULL, '1'},
//     {"read-lines-test", no_argument, NULL, '2'},
//     {"cin-ate-n-test", no_argument, NULL, '3'},
//     {"get-uint64-test", no_argument, NULL, '4'},
//     {"get-int64-test", no_argument, NULL, '5'},
//     {"multiple-type-oss", no_argument, NULL, '6'},
//     {NULL, 0, NULL, 0}
// };

// GEN_FUNC_COPY
// void OptUsage() 
// {
//     printf("Usage:\n");
//     printf("\tOption [-h] [-?] [--help] [--helps]\n");
//     printf("\tOption [-c] [--capitals]\n");
//     printf("\t\tOption [-w] [--wchar]\n");
//     printf("\t\tOption [-p] [--print]\n");
//     printf("\t\tOption [-g] [--get]\n");
//     printf("\tOption [-o] [--oss-test]\n");
//     printf("\tOption [-0] [--read-write-file-test]\n");
//     printf("\tOption [-1] [--boolalpha-test]\n");
//     printf("\tOption [-2] [--read-lines-test]\n");
//     printf("\tOption [-3] [--cin-ate-n-test]\n");
//     printf("\tOption [-4] [--get-uint64-test]\n");
//     printf("\tOption [-5] [--get-int64-test]\n");
//     printf("\tOption [-6] [--multiple-type-oss]\n");
// }

// void _main_v1_0(int argc, char *argv[], char *envp[]){
//     int case_num, prev_case_num;
//     int err_code = 0;
//     int test_round = 0;

//     while( (case_num = 
//                 getopt_long(argc, 
//                             argv, 
//                             short_opts.c_str(), 
//                             long_opts, 
//                             NULL)
//             ) >= 0)
//         switch (case_num)
//         {
//             case 'w': case 'p': case 'g':
//         prev_case_num = case_num;
//         break;

//             case 'c':
//         err_code = Capitals(prev_case_num);
//         break;

//             case 'o':
//         TestOSS();
//         break;

//             case 'd':
//         // example:
//         // optarg <_Tp = int> = 10 
//         DrawTriangle(opt_uint(optarg));
//         break;

//             case 'm':
//         // example:
//         // optarg <_Tp = int> = 10 
//         test_round = opt_uint(optarg);
//         TestInRange(test_round);
//         break;

//             case 'n':
//         // example:
//         // optarg <_Tp = int> = 10 
//         test_round = opt_uint(optarg);
//         TestInRange(test_round);
//         break;

//             case '0':
//         TestReadWriteFile();
//         break;

//             case '1':
//         TestBoolAlpha();
//         break;

//             case '2':
//         TestReadLines();
//         break;

//             case '3':
//         TestCinAteN();  
//         break;

//             case '4':
//         fprintf(stdout, "res: %llu\n", u64_qread());
//         fprintf(stdout, "res: %lld\n", i64_qread());
//         break;

//             case '5':
//         TestHasHexLetters_3_version_pat(1 << (rand() % 30) );
//         break;

//             case '6':
//         MultiTypesOSS("9527 8.8888888 Canada America c");
//         break;
        
//         // none parameter (argv)
//             case '7':
//         // Alan::TestBirthDayParadox();
//         // Alan::TestUMap();
//         // Alan::TestUSet();
//         // Alan::TestIterator();
//         // Alan::TestMapDiffer();
//         // Alan::CountKeyWordsOccurences();
//         // Alan::TestMultiContainer();
//         // TestVectorFunctor();
//         // TestVectorFunctor2();
//         // TestVectorFunc3();
//         // TestRingBuffer();
//         // Alan::TestSSet();
//         // Alan::TestRangeFind();
//         // Alan::TestMatchingPrefix();
//         // Alan::TestAlgo();
//         // Alan::TestIteratorAdapter();
//         // Alan::TestAssoContainerAlgo();
//         // Alan::TestRemoveAlgo();
//         // Alan::TestArbitraryAlgo();
//         // Alan::Test_Tp_AVG();
//         // TestRandRDMT19937();
//         // Alan::Test_LB_UB();
//         // Alan:: TestTask();
//         // Alan::TestFunc();
//         Alan::TestTask2();
//         break;
            
//         // parameter (argv)
//             case 't':
//         // TestAgainstVectorReverseWithNot();
//         // TestVigenereEncrypt();
//         // TestEmail();
//         // TestNFA();
//         Alan:: Test_Palindrome();
//         break;

//             case 'y':
//         TestAISnakeGame();
//         break;

//             case 'v':
//         printf("GCC info: %s\n", __VERSION__);
//         break;

//             case 'h': case '?': 
//         err_code = 2;
//         break;

//             default:
//         err_code = 1;
//         break;
//         }

//     if (err_code)
//     {
//         OptUsage();
//         exit(err_code);
//     }
// }



#if (__CC_VER__ >= 4)
    #undef __TYPE_OF__
    #define __TYPE_OF__(__x__) __typeof__(__x__)
#elif (__CC_VER__ == 8)
    #undef __TYPE_OF__
    #define __TYPE_OF__(__x__) typeof(__x__)
#endif 


// Type determine and extension
// use: 	__DEF_DCL__
// detail:	typedef __meta_type__##__xx_xx__ __alias_type__;
#define __DEF_ALL__(__alias_type__, __meta_type__) \
        typedef __meta_type__ __alias_type__ ; \
        __DEF_CONST__(__alias_type__); \
        __DEF_REF__(__alias_type__); \
        __DEF_CREF__(__alias_type__); \
        __DEF_RREF__(__alias_type__); \
        __DEF_PTR__(__alias_type__); \
        __DEF_CONST_PTR__(__alias_type__); \
        __DEF_PTR_TO_CONST__(__alias_type__); \
        __DEF_CONST_PTR_TO_CONST__(__alias_type__)

// after C++11 Standard
// use :	__DEF_DCL_V2__
// detail:	using __alias_type__ = __meta_type__##__xx_xx__;
#define __DEF_ALL_V2__(__alias_type__, __meta_type__) \
        using __alias_type__ = __meta_type__ ; \
        __DEF_CONST_V2__(__alias_type__); \
        __DEF_REF_V2__(__alias_type__); \
        __DEF_CREF_V2__(__alias_type__); \
        __DEF_RREF_V2__(__alias_type__); \
        __DEF_PTR_V2__(__alias_type__); \
        __DEF_CONST_PTR_V2__(__alias_type__); \
        __DEF_PTR_TO_CONST_V2__(__alias_type__); \
        __DEF_CONST_PTR_TO_CONST_V2__(__alias_type__)

#define __DEF_SHORT__(__alias_type__, __meta_type__) \
        using __alias_type__ = __meta_type__ ; \
        __DEF_CONST_V3__(__alias_type__); \
        __DEF_REF_V3__(__alias_type__); \
        __DEF_CREF_V3__(__alias_type__); \
        __DEF_RREF_V3__(__alias_type__); \
        __DEF_PTR_V3__(__alias_type__); \
        __DEF_CONST_PTR_V3__(__alias_type__); \
        __DEF_PTR_TO_CONST_V3__(__alias_type__); \
        __DEF_CONST_PTR_TO_CONST_V3__(__alias_type__)

// common typedecl
#define __CONST__(__type__) \
        __type__ const
#define __REF__(__type__) \
        __type__ &
#define __CONST_REF__(__type__) \
        __type__ const &

// __type__ is a int, double, char, class, it is rvalue reference
#define __RREF__(__type__) \
        __type__ &&
// __tp__ is a typename _Tp, it is a universal reference
#define __UREF__(__tp__) \
        __tp__ &&
#define __MV_RREF__(__rref__) \
        std::move(__rref__)

#define __PTR__(__type__) \
        __type__ *
#define __CONST_PTR__(__type__) \
        __type__ * const
#define __PTR_TO_CONST__(__type__) \
        __type__ const *
#define __CONST_PTR_TO_CONST__(__type__) \
        __type__ const * const

// template type _Tp define
#define __DEF_TPL__(__tp__) \
	using value_type = __tp__ ; \
	using const_type = __CONST__(__tp__); \
	using reference = __REF__(__tp__); \
	using const_reference = __CONST_REF__(__tp__); \
	using r_reference = __RREF__(__tp__); \
	using pointer = __PTR__(__tp__); \
	using const_pointer = __CONST_PTR__(__tp__); \
	using pointer_to_const = __PTR_TO_CONST__(__tp__); \
	using const_pointer_to_const = __CONST_PTR_TO_CONST__(__tp__); \
	__DEF_SZX__

#define __DEF_SZX__ \
	typedef size_t		size_type; \
      	typedef ptrdiff_t	difference_type

// v1
#define __DEF_DCL__(__wrap_type__, __meta_type__, __decl__) \
        typedef __wrap_type__ __meta_type__ ## __decl__

#define __DEF_CONST__(__type__) \
        __DEF_DCL__(__CONST__(__type__), __type__, _const)
#define __DEF_REF__(__type__) \
        __DEF_DCL__(__REF__(__type__), __type__, _reference)
#define __DEF_CREF__(__type__) \
        __DEF_DCL__(__CONST_REF__(__type__), __type__, _const_reference)
#define __DEF_RREF__(__type__) \
        __DEF_DCL__(__RREF__(__type__), __type__, _r_reference)
#define __DEF_PTR__(__type__) \
        __DEF_DCL__(__PTR__(__type__), __type__, _pointer)
#define __DEF_CONST_PTR__(__type__) \
        __DEF_DCL__(__CONST_PTR__(__type__), __type__, _const_pointer)
#define __DEF_PTR_TO_CONST__(__type__) \
        __DEF_DCL__(__PTR_TO_CONST__(__type__), __type__, _pointer_to_const)
#define __DEF_CONST_PTR_TO_CONST__(__type__) \
        __DEF_DCL__(__CONST_PTR_TO_CONST__(__type__), __type__, _const_pointer_to_const)

// v2
#define __DEF_DCL_V2__(__wrap_type__, __meta_type__, __decl__) \
        using __meta_type__ ## __decl__ = __wrap_type__

#define __DEF_CONST_V2__(__type__) \
        __DEF_DCL_V2__(__CONST__(__type__), __type__, _const)
#define __DEF_REF_V2__(__type__) \
        __DEF_DCL_V2__(__REF__(__type__), __type__, _reference)
#define __DEF_CREF_V2__(__type__) \
        __DEF_DCL_V2__(__CONST_REF__(__type__), __type__, _const_reference)
#define __DEF_RREF_V2__(__type__) \
        __DEF_DCL_V2__(__RREF__(__type__), __type__, _r_reference)
#define __DEF_PTR_V2__(__type__) \
        __DEF_DCL_V2__(__PTR__(__type__), __type__, _pointer)
#define __DEF_CONST_PTR_V2__(__type__) \
        __DEF_DCL_V2__(__CONST_PTR__(__type__), __type__, _const_pointer)
#define __DEF_PTR_TO_CONST_V2__(__type__) \
        __DEF_DCL_V2__(__PTR_TO_CONST__(__type__), __type__, _pointer_to_const)
#define __DEF_CONST_PTR_TO_CONST_V2__(__type__) \
        __DEF_DCL_V2__(__CONST_PTR_TO_CONST__(__type__), __type__, _const_pointer_to_const)

// v3
#define __DEF_DCL_V3__(__wrap_type__, __meta_type__, __decl__) \
        using __meta_type__ ## __decl__ = __wrap_type__

#define __DEF_CONST_V3__(__type__) \
        __DEF_DCL_V2__(__CONST__(__type__), __type__, c)
#define __DEF_REF_V3__(__type__) \
        __DEF_DCL_V2__(__REF__(__type__), __type__, r)
#define __DEF_CREF_V3__(__type__) \
        __DEF_DCL_V2__(__CONST_REF__(__type__), __type__, cr)
#define __DEF_RREF_V3__(__type__) \
        __DEF_DCL_V2__(__RREF__(__type__), __type__, rr)
#define __DEF_PTR_V3__(__type__) \
        __DEF_DCL_V2__(__PTR__(__type__), __type__, p)
#define __DEF_CONST_PTR_V3__(__type__) \
        __DEF_DCL_V2__(__CONST_PTR__(__type__), __type__, cp)
#define __DEF_PTR_TO_CONST_V3__(__type__) \
        __DEF_DCL_V2__(__PTR_TO_CONST__(__type__), __type__, pc)
#define __DEF_CONST_PTR_TO_CONST_V3__(__type__) \
        __DEF_DCL_V2__(__CONST_PTR_TO_CONST__(__type__), __type__, cpc)


#define __DISALLOW_COPYING(__def_type_) \
        private: \
        __def_type_(const __def_type_ &); \
        __def_type_& operator = (const __def_type_ &)

// construct to smart pointer by args...
#define __UPTR__(__type__, ...) std::make_unique<__type__>(__VA_ARGS__)
#define __SPTR__(__type__, ...) std::make_shared<__type__>(__VA_ARGS__)
// need to complete weak
#define __WPTR__(__type__, ...)

#define __DEF_UP_VAR__(__idt__, __type__, ...) \
        auto __idt__ = __UPTR__(__type__, __VA_ARGS__) 
#define __DEF_SP_VAR__(__idt__, __type__, ...) \
        auto __idt__ = __SPTR__(__type__, __VA_ARGS__)

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

#define MAX_Tp_t(_x, _y) ({ \
	decltype(_x) __x = (_x); \
	decltype(_y) __y = (_y); \
	__x > __y ? __x : __y; \
})

#define MIN_Tp_t(_x, _y) ({ \
	decltype(_x) __x = (_x); \
	decltype(_y) __y = (_y); \
	__x < __y ? __x : __y; \
})

#define I32_POWER2(_i32_) (1 << _i32_)
#define I32_POWER2_EQ(_i32_) \
        (_i32_ = I32_POWER2(_i32_))

#define I32_LSHIFT(_i32_, _bit_) \
        (_i32_ << _bit_) 
#define I32_LSHIFT_EQ(_i32_, _bit_) \
        (_i32_ = I32_LSHIFT(_i32_, _bit_)) 
#define I32_RSHIFT(_i32_, _bit_) \
        (_i32_ >> _bit_) 
#define I32_RSHIFT_EQ(_i32_, _bit_) \
        (_i32_ = I32_RSHIFT(_i32_, _bit_)) 

#define I32_MUL2(_i32_) I32_LSHIFT(_i32_, 1)
#define I32_MUL2_EQ(_i32_) \
        (_i32_ = I32_MUL2(_i32_))
#define I32_MUL8(_i32_) I32_LSHIFT(_i32_, 3)
#define I32_MUL8_EQ(_i32_) \
        (_i32_ = I32_MUL8(_i32_))
#define I32_MUL10(_i32_) \
        (I32_MUL2(_i32_) + I32_MUL8(_i32_))
#define I32_MUL10_EQ(_i32_) \
        (_i32_ = I32_MUL10(_i32_))

#define I32_CHARIN(_i32_, _ch_) \
        (_i32_ = (I32_MUL10(_i32_) + (_ch_ - '0')))

// tested
#define U32 (unsigned int)
#define I32_IN_RANGE(_x, _min, _max) \
        (U32(_x)-U32(_min) <= U32(_max)-U32(_min))
// tested
#define U8 (unsigned char)
#define I8_IN_RANGE(_x, _min, _max) \
        (U8(_x)-U8(_min) <= U8(_max)-U8(_min))

typedef unsigned long long _ui_64;
typedef signed long long _si_64; 

#define SKP_NON_DIG(_ch)    \
    while (!isdigit(_ch))   \
        _ch = getchar()

#define GET_RES_DIG(_res, _ch)  \
    while (isdigit(_ch))    \
        I32_CHARIN(_res, _ch), _ch = getchar()
 
GEN_FUNC_COPY
_ui_64 u64_qread()
{
    char ch = getchar();
    _ui_64 res = 0;
    SKP_NON_DIG(ch);
    GET_RES_DIG(res, ch);
    return res;
}

GEN_FUNC_COPY
_si_64 i64_qread()
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



#define INPUT_ERROR 0xff
#define ARGUS_ERROR 0xf1

#endif 