#pragma once 
#ifndef _TEST_FUNC_HPP
#define _TEST_FUNC_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include "_ai_snake_game_.hpp"
#include "_asso_container_.hpp"
#include "_seq_container_.hpp"
#include "_set_theory_.hpp"
#include "_algo_.hpp"
#include "_func_.hpp"
#include "_keno_game_.hpp"
#include "_level_db_.hpp"
#include "_sim_printer_.hpp"
#include "_nfa_.hpp"
#include "_dfa_.hpp"

#include <queue>
#include <vector>

#if (__CC_VER__ > 1)
    #include <unistd.h>
#elif (__CC_VER__ == 1)
    #include <windows.h>
#endif
#include <cstdarg>

__DEF_NS__(Alan::Demos)

#ifndef DEBUG_MODE
#define DEBUG_MODE
#endif
class _a {
public:
    explicit _a(int const & __el = 0) : _el(__el) {}
    _a(_a const & _a_val){
        #ifdef DEBUG_MODE
            PRINTLN("copy constructor");
        #endif 
        this->_el = _a_val._el;
    }
    _a(_a && _a_val){
        #ifdef DEBUG_MODE
            PRINTLN("move constructor");
        #endif 
        this->_el = std::move(_a_val._el);
    }

    _a& operator = (_a const & _a_val) {
        #ifdef DEBUG_MODE
            PRINTLN("copy assgin");
        #endif 
        if (this != &_a_val) [[likely]] {
            this->_el = _a_val._el;
        }
        return *this;
    }
    _a& operator = (_a && _a_val) {
        #ifdef DEBUG_MODE
            PRINTLN("move assign");
        #endif 
        if (this != &_a_val) [[likely]] {
            this->_el = std::move(_a_val._el);
        }
        return *this;
    }
    ~_a() {
        #ifdef DEBUG_MODE
            PRINTLN("destructor");
        #endif 
    }

    // _a& operator = (_a const & _a_val) {
    //     if (this != &_a_val){
    //         this->_el = _a_val._el;
    //     }
    //     return *this;
    // }
    // // to check what is happening???
    // _a(_a const & _a_val) {
    //     *this = _a_val;
    // }
    
    friend std::ostream& 
    operator << (std::ostream& __os, 
                _a const & _a_val)
    {
        __os << "(" 
            << _a_val._el 
            << ")";
        return __os;
    } 
private:
    int _el;
};


class _Singleton_type 
{
private:
    __DEF_ALL_V2__(_st, _Singleton_type);
    _Singleton_type();
    ~_Singleton_type();
    __DISALLOW_COPYING(_Singleton_type);
    static _st _instance;
public:
    static _st_reference
    getInst() 
    {      
        return _instance;
    }
};

// _Singleton_type::_instance = _Singleton_type();

template <typename _Tp, typename... _Args>
class _Tuple 
{
    // explicit _Tuple(const _Tp & _tval, _Args... & _args) 
    // noexcept
    // {

    // }

    // _Tp operator() (_Args... _args)
    // const 
    // {
    //     // return __fn.execute();
    // }


};


class _BatchPrinter :
    public Alan::Demos0::_Printer
{
public:
    void enqueueDocument(const std::string _doc)
    {
        this->_docs.emplace(_doc);
    }
    void printAllDocuments()
    {
        while(!this->_docs.empty())
        {
            this->printDocument(this->_docs.front());
            __tsleep_(0.5);
            this->_docs.pop();
        }
    }
    void batchEnqueueDocument(size_t _sz, ...)
    {
        va_list _val;
        va_start(_val, _sz);
        for(size_t _i = 0; _i < _sz; ++_i)
            this->_docs.emplace(va_arg(_val, const char *));
        va_end(_val);
    }
    void eventLoop(size_t _t)
    {
        while(_t --)
        {
            // enqueueDocument(*Alan::_Gen_Char_Con());
            batchEnqueueDocument(_t, 
                Alan::_Gen_Char_Con()->c_str(),
                Alan::_Gen_Char_Con()->c_str(),
                Alan::_Gen_Char_Con()->c_str(),
                Alan::_Gen_Char_Con()->c_str(),
                Alan::_Gen_Char_Con()->c_str()
            );
            printAllDocuments();
        }
    }
private:
    std::queue<std::string > _docs;
};

void FillingPrint(const Alan::Demos0::_Printer &);

template <typename _Tp>
using __grid_ = std::vector<std::vector<_Tp > > ;

struct __pixelT_ 
{
    // typedef struct __pixelT_ __pixel_T;
    __pixelT_(uint8_t _r = 0x0, uint8_t _g = 0x0, uint8_t _b = 0x0)
        : __r_(_r), __g_(_g), __b_(_b) { }

    __pixelT_(const __pixelT_ & __pT){
        this->__r_ = __pT.__r_;
        this->__g_ = __pT.__g_;
        this->__b_ = __pT.__b_;
    }

    __pixelT_& operator = (const __pixelT_ & __pT){
        if (this != &__pT) [[likely]]
        {
            this->__r_ = __pT.__r_;
            this->__g_ = __pT.__g_;
            this->__b_ = __pT.__b_;
        }
        return *this;
    }

    uint8_t __r_;
    uint8_t __g_;
    uint8_t __b_;
};


class _Document 
{
public:
    using grid_type = __grid_<__pixelT_>;
    virtual grid_type convertToPixelArray() const = 0;
    virtual int getPriority() const = 0;
    virtual char* getName() const = 0;
};


class _TextDocument
    : public _Document
{
public:
    _TextDocument(const char * _name = "text_doc_default_name",
                    int _prio = 0) 
        : __name_(__tstrdup_(_name)), __prio_(_prio) {}

    virtual grid_type convertToPixelArray()
    const override
    {
        return __grid_<__pixelT_>();
    }

    virtual int getPriority() 
    const override
    {
        return this->__prio_;
    }

    virtual char* getName() 
    const override
    {
        return this->__name_;
    }

    void setText(const std::string &);
    void setFont(const std::string &);
    void setSize(size_t);
private:
    char* __name_;
    int   __prio_;
};

class _RBX
{
public:
    explicit _RBX(const __pixelT_ & _s0 = __pixelT_(0xff, 0xff, 0xff), 
                const __pixelT_ & _s1 = __pixelT_(0x77, 0x77, 0x77))
        : __s0_(std::move(_s0)), __s1_(std::move(_s1)) { 
            _fn();
        }
    
    _RBX(_RBX & _rbx){
        this->__r0_ = std::move(_rbx.__r0_);
        this->__r1_ = std::move(_rbx.__r1_);
        this->__s0_ = std::move(_rbx.__s0_);
        this->__s1_ = std::move(_rbx.__s1_);
    }

    _RBX& operator = (_RBX & _rbx){
        if (this != &_rbx) [[likely]]
        {
            this->__r0_ = std::move(_rbx.__r0_);
            this->__r1_ = std::move(_rbx.__r1_);
            this->__s0_ = std::move(_rbx.__s0_);
            this->__s1_ = std::move(_rbx.__s1_);
        }
        return *this;
    }

    virtual ~_RBX() {
        PRINTLN("_RBX destructor");
    }

    virtual void _fn() 
    const noexcept
    {
        PRINTLN("_RBX");
    }

    void _fnx()
    {
        PRINTLN("nooverride");
    }
protected:
    __pixelT_ __r0_;
    __pixelT_ __r1_;
private:
    __pixelT_ UNUSED __s0_;
    __pixelT_ UNUSED __s1_;
    void inc_s0(){
        __s0_.__r_ += 0x01;
        __s0_.__g_ += 0x01;
        __s0_.__b_ += 0x01;
    }
};

class _uncopyable
{
public:
    void show(){
        PRINTLN("__uncopyable__");
    }
// if a derived class is uncopyable, 
// it show private derived from _uncopyable
// protected:
//     _uncopyable() { }
//     ~_uncopyable() { }
// private:
//     _uncopyable(const _uncopyable &);
//     _uncopyable& operator = (const _uncopyable &);
};

class _mRBX
    : public _RBX, private _uncopyable
{
public:
    ~_mRBX() {
        PRINTLN("_mRBX destructor");
    }
    explicit _mRBX(const __pixelT_ & _dup = __pixelT_(0x33, 0x33, 0x33)) 
        : _RBX(), __d0_(_dup), __d1_(_dup) { }

    _mRBX(_mRBX & __mrbx) 
        : _RBX(__mrbx) {
        this->__d0_ = std::move(__mrbx.__d0_);
        this->__d1_ = std::move(__mrbx.__d1_);
    }

    _mRBX& operator = (_mRBX & __mrbx){
        if (this != &__mrbx) [[likely]]
        {
            _RBX::operator = (__mrbx);
            this->__d0_ = std::move(__mrbx.__d0_);
            this->__d1_ = std::move(__mrbx.__d1_);
        }
        return *this;
    }

    virtual void _fn() 
    const noexcept override
    {
        PRINTLN("_mRBX");
    }

    void doD()
    {
        this->__r0_.__r_ = 0x01;
        this->__r0_.__g_ = 0x10;
        this->__r0_.__b_ = 0xff;
        show();
    }

private:
    __pixelT_ UNUSED __d0_;
    __pixelT_ UNUSED __d1_;
};

class _mtRBX
    : public _mRBX
{
public:
    ~_mtRBX(){
        PRINTLN("_mtRBX destructor");
    }

    void domD()
    {
        this->__r0_.__r_ = 0x33;
    }
};

class _nRBX
    : public _RBX
{
public:
    ~_nRBX(){
        PRINTLN("_nRBX destructor");
    }

    // do not recommend
    // void _fnx()
    // {
    //     PRINTLN("override");
    // }
};

__END_NS__


__DEF_NS__(Alan::Demos::Test::Func)

void TestReadWriteFile();

void TestBoolAlpha();

void TestReadLines();

void TestCinAteN();

void TestOSS();

int Capitals(int const &);

void TestHasHexLetters_3_version_pat(int const &);

void DrawTriangle(int const&);

void TestInRange(int const &);

void TestInRangeV2(int const &);

void TestReadOnlyRBTree();

void TestRRef();

void TestHashTable();

void TestADV();

void TestCon2By();

void TestSeqLB_UB();

void TestPLoc();

void TestConstPointer();

void TestConPlus();

void TestBitwiseChange();

void TestSZof();

void TestLevelDB();

void TestTuple();

void TestSTDAny();

void TestAll();

void TestAllV3();

void TestAllHasArgv();

void TestBitCastZeroExt2SignExt();

__END_NS__


__DEF_NS__(Alan::Demos::Test::LeetCode)

void TestUBus();

__END_NS__

#endif 