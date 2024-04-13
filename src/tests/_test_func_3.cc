#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_point_loc_.hpp"

#include "../../include/_test_func_.hpp"
#include "../../include/_polym_.hpp"
#include "../../include/_sim_printer_.hpp"

#include <iostream>
#include <iomanip>

#include <vector>
#include <deque>
#include <map>
#include <string>

#include <utility>
#include <algorithm>
#include <type_traits>
#include <memory>
#include <functional>

#include <cassert>
#include <any>
#include <cstdint>
#include <cstddef>
#include <cfloat>

// func_ptr do not use const & parameter 
bool _str_sz_less_than
(std::string _str, size_t _sz) 
{
    return _str.size() < _sz;
}

void TestFn01()
{
    // function converter 
    // lambda do not use const & parameter
    // auto _str_sz_less_than = 
    //     [](std::string _str, size_t _sz) 
    //         -> bool 
    //     {
    //         return _str.size() < _sz;
    //     };
    auto _wrap_fn UNUSED = 
        std::function<bool (const std::string &, size_t)>(_str_sz_less_than);
    auto _str_con = 
        Alan::_Gen_Seq_Str_Con
        <std::vector<std::string >>
        (Alan::CONST::_digit, 1, 10);
    Alan::ConsoleBeautyOutput(*_str_con);
    PRINTLN_DETAIL(std::count_if(_str_con->begin(), _str_con->end(), 
                                Alan::Demos::_comp_str_sz(5))
                );
    #if __cplusplus < 201103L
    PRINTLN_DETAIL(std::count_if(_str_con->begin(), _str_con->end(), 
                                std::bind2nd(std::ptr_fun(_str_sz_less_than), 5))
                );
    std::transform(_str_con->begin(), _str_con->end(), 
                    _str_con->begin(), 
                    std::bind2nd(std::plus<std::string >(), std::string("Alan")));
    #endif 
    if(_str_con)
        Alan::ConsoleBeautyOutput(*_str_con);
}

void TestSharedPtr()
{
    auto _i32_ptr = 
        std::shared_ptr<int>(new int);
    
    auto _i32_ptr1 = _i32_ptr;
    auto _i32_ptr2 = _i32_ptr1;

    *_i32_ptr1 = 0x09;

    PRINTLN_DETAIL(_i32_ptr);
    PRINTLN_DETAIL(_i32_ptr1);
    PRINTLN_DETAIL(_i32_ptr2);

}

void TestMigrate()
{
    _COLOR_START(_COLOR_BLUE);
        PRINTLN("migrate ok0");
        PRINTLN(_CYAN("migrate ok1"));
    _COLOR_END;

    __USE_NS__(Alan);

    __DEF_PAIR__(int, int);
    int_int_pair iip_ = 
        std::make_pair(0xff, 0x11);
    PRINTLN_DETAIL(iip_);

    auto _iiit = 
        std::make_tuple(1, 2, 3, 4);
    PRINTLN_DETAIL(_iiit);  
}


std::vector<Alan::Demos::_a > 
ret_a_vec(size_t const _sz = 4)
{   
    auto _a_vec = 
        std::vector<Alan::Demos::_a>(); 
    _a_vec.reserve(_sz);
    for(size_t _i = 0; _i < _sz; ++_i)
        // _a_vec.push_back(Alan::Demos::_a(_i));
        _a_vec.emplace_back(_i);
    return _a_vec;
}

void TestVectorRet()
{
    auto _temp_con = ret_a_vec(10);
    Alan::ConsoleBeautyOutput(_temp_con);
}

// __USE_NS__(Alan::Demos);
void Alan::Demos::FillingPrint(const Alan::Demos0::_Printer & _printer)
{
    _printer.printDocument("Colmz");
}

void TestSimPrinter()
{
    auto _printer = Alan::Demos0::_Printer();
    _printer.setColor("3");
    _printer.printDocument("LYY Alan YYDS");

    PRINTLN("-------------------------------");
    auto _bp = Alan::Demos::_BatchPrinter();
    // Alan::Demos::FillingPrint(_bp);
    _bp.eventLoop(10); 

    Alan::Demos::_Document * my_doc = 
        new Alan::Demos::_TextDocument;
    _printer.setColor("5");
    _printer.printDocument(my_doc->getName()); 
}

void TestConstructSptr()
{
    __DEF_UP_VAR__(i32, int, 10);
    __DEF_SP_VAR__(f64p, Alan::_Point_Loc<double>, 3.4, 4.5, 2.3);

    PRINTLN_DETAIL(*i32);
    PRINTLN_DETAIL(*f64p);

    Alan::Demos::_RBX * _rbx0 = new Alan::Demos::_RBX;
    _rbx0->_fn();
    Alan::Demos::_RBX * _rbx1 = new Alan::Demos::_mRBX;
    _rbx1->_fn();
    Alan::Demos::_RBX * _rbx2 = new Alan::Demos::_nRBX; 
    _rbx2->_fn();
    // _rbx2->_fnx();

    Alan::Demos::_RBX * _rbx3 = new Alan::Demos::_mtRBX; 
    _rbx3->_fn();

    delete _rbx0, 
    delete _rbx1,
    delete _rbx2,
    delete _rbx3;

    // PRINTLN_DETAIL(Alan::__cpp_tid_<int>()); 
}

// #include <bits/stdc++.h>
void TestAllV3()
{
    // TestFn01();
    // TestSharedPtr();
    // TestPolym0();
    // TestMigrate();
    // TestVectorRet();
    // TestSimPrinter();
    TestConstructSptr();
}

