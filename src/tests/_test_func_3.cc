#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_point_loc_.hpp"

#include "../../include/_test_func_.hpp"
#include "../../include/_polym_.hpp"
#include "../../include/_sim_printer_.hpp"
#include "../../include/_intn_.hpp"
#include "../../include/_simd_.hpp"
#include "../../include/_self_list_.hpp"

#include <iostream>
#include <iomanip>

#include <queue>
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
#include <cstdlib>

// #include <linalg>

__USE_NS__(Alan);
__USE_NS__(Alan::Demos);
__USE_NS__(Alan::Demos::Test::LeetCode);
__USE_NS__(Alan::Demos::Test::Luogu);
__USE_NS__(Alan::SelfList);
__DEF_NS__(Alan::Demos::Test::Func)

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
ret_a_vec(size_t _sz = 4)
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
void FillingPrint(const Alan::Demos0::_Printer & _printer)
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

void TestIntN()
{
    Alan::_intn in("444");
    PRINTLN_DETAIL(in);
}

void TestVTable()
{
    Alan::Demos::_RBX * _rbx0 = new Alan::Demos::_mRBX;
    _rbx0->_fnx();

    auto mobj1 = 
        Alan::Demos::_mRBX(Alan::Demos::__pixelT_(0x22, 0x22, 0x22));
    auto mobj2 = mobj1;

    mobj1._fnx();
    mobj2._fnx();  
    // mobj1.inc_s0();
    // mobj1.showI();
    mobj1.doD();

}

void TestMoveForward()
{
    std::string _s("xxx");
    PRINTLN_DETAIL(Alan::__cpp_tid_<decltype(_s)>());
    PRINTLN_DETAIL(Alan::__cpp_tid_<decltype(std::move(_s))>());

    PRINTLN_DETAIL(Alan::__cpp_tid_<decltype(std::forward<std::string >(_s))>);
    PRINTLN_DETAIL(Alan::__cpp_tid_<decltype(std::forward<std::string &>(_s))>);
    PRINTLN_DETAIL(Alan::__cpp_tid_<decltype(std::forward<std::string &&>(_s))>);
    #ifdef DEBUG_MODE
        PRINTLN_DETAIL("uncancelled DEBUG_MODE");
    #endif

}

void TestPolyPtr()
{
    {
        auto _v1 = _Gen_Seq_Con<std::vector<int > >(1, 1<<10);
        auto _v2 = _Gen_Seq_Con<std::vector<int > >(1, 1<<10);
        ConsoleBeautyOutput(*_v1),
        ConsoleBeautyOutput(*_v2);
        appendSeq(*_v1, std::move(*_v2));
        appendSeq(*_v1, *_v2);
        ConsoleBeautyOutput(*_v1);
        ConsoleBeautyOutput(*_v2);
    }

    {
        auto _v1 = _Gen_Seq_Con<std::deque<int > >(1, 1<<10);
        auto _v2 = _Gen_Seq_Con<std::deque<int > >(1, 1<<10);
        ConsoleBeautyOutput(*_v1),
        ConsoleBeautyOutput(*_v2);
        appendSeq(*_v1, std::move(*_v2));
        appendSeq(*_v1, *_v2);
        ConsoleBeautyOutput(*_v1);
        ConsoleBeautyOutput(*_v2);
    }
}

void TestFnInvokeTime()
{
    auto _fn_dur UNUSED = 
        [] (auto && _fn, auto&&... _param_pack)
            -> auto
        {   
            // TODO: time duration
            std::forward<decltype(_fn)>(_fn)
                (std::forward<decltype(_param_pack)>(_param_pack)...);
            // cal
            return ;
        };
}

// 2^27B = 128MB
// 2^32B = 4GB
// 2^30B = 1GB
void TestISort()
{
    auto seq_ptr = 
        Alan::__unique_2_shared_(_Gen_Seq_Con<std::vector<int>, (1<<6) >(1<<2, 1<<8));
    
    // ConsoleBeautyOutput(*seq_ptr);
    // ConsoleBeautyOutput(*seq_ptr);

    using con_type = std::remove_reference_t<decltype(*seq_ptr)>;
    using iter_type = con_type::iterator;

    // auto seq1 = *seq_ptr;
    // auto seq2 = con_type(seq1);
    // auto seq3 = con_type(seq1);

    PRINTLN_DETAIL(Alan::__time_count_(std::sort<iter_type>, seq_ptr->begin(), seq_ptr->end()));
    // PRINTLN_DETAIL(Alan::__time_count_(Alan::Sort::QuickSort<con_type>, seq2));
    // PRINTLN_DETAIL(Alan::__time_count_(Alan::Sort::MergeSort<con_type>, seq3));
    // PRINTLN_DETAIL(Alan::__time_count_(::qsort, seq_ptr->begin(), seq_ptr->size(), sizeof(con_type::value_type),std::less<int>()));

    // ConsoleBeautyOutput(*seq_ptr);   
}

void TestRunCPU()

{
    PRINTLN_DETAIL(Alan::__loops_per_sec_(1));
    PRINTLN_DETAIL(Alan::__loops_per_sec_(2));
    PRINTLN_DETAIL(Alan::__loops_per_sec_(3));

}

void TestPQ()
{
    auto pq = std::priority_queue<int, std::vector<int >, std::greater<int> >();
    pq.push(1000);
    pq.push(1);
    pq.push(10);
    pq.push(20);
    pq.push(100);

    PRINTLN_DETAIL(pq.top());
    pq.pop();
}

void TestAllV3()
{
    TestFn01();
    TestSharedPtr();
    TestPolym0();
    TestMigrate();
    TestVectorRet();
    TestSimPrinter();
    TestConstructSptr();
    TestIntN();
    TestVTable();
    #if __OS_VER__ != 2
        Testvec256();
    #endif
    TestMoveForward();
    Alan::Demos::Test::Func::TestBitCastZeroExt2SignExt();
    TestPolyPtr();
    TestUBus();
    TestISort();
    Alan_Driver();
    TestRunCPU();
    TestPQ();
    
    /* TODO: need to test for problems */
    TestLambda2();
}

void TestAllHasArgv()
{
    TestAgainstVectorReverseWithNot();
    TestVigenereEncrypt();
    TestEmail();
    TestNFA();
    Test_Palindrome();
}

__END_NS__