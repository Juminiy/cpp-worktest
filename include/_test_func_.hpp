#pragma once 
#ifndef _TEST_FUNC_HPP
#define _TEST_FUNC_HPP

#include "_ai_snake_game_.hpp"
#include "_asso_container_.hpp"
#include "_seq_container_.hpp"
#include "_set_theory_.hpp"
#include "_algo_.hpp"
#include "_func_.hpp"
#include "_keno_game_.hpp"
#include "_level_db_.hpp"

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

class _a {
public:
    explicit _a(int const & __el) : _el(__el) {}
    _a& operator = (_a const & _a_val) {
        if (this != &_a_val){
            this->_el = _a_val._el;
        }
        return *this;
    }
    // to check what is happening???
    _a(_a const & _a_val) {
        *this = _a_val;
    }
    ~_a() {}
    friend std::ostream& 
    operator << (std::ostream& __os, 
                _a const _a_val)
    {
        __os << "[" 
            << _a_val._el 
            << "]";
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
#endif 