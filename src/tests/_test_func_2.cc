#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_stl_lib_adv_.hpp"
#include "../../include/_rand_lib_.hpp"

#include "../../include/_test_func_.hpp"

#include <iostream>
#include <vector>
#include <deque>
#include <cassert>
#include <utility>

// example:
// 1 2 3
// 4.0 5.0 6.0
void TestADV()
{
    PRINTLN_DETAIL(Alan::_t_plus(1, 2.5));
    using namespace std::literals;
    PRINTLN_DETAIL(Alan::_t_plus("to"s, "wa"s));
    PRINTLN_DETAIL(Alan::_t_plus(Alan::_Point_Loc<int >(0xff, 0x88, 0x11), 
                                Alan::_Point_Loc<int >(1, 2, 3)));

    Alan::_Point_Loc <double >_pa;
    Alan::_Point_Loc <int >_pb;
    std::cin >> _pa >> _pb;
    PRINTLN_DETAIL(Alan::_t_plus(_pa, _pb));
    PRINTLN_DETAIL(Alan::_t_plus("su7", 1));
}

void TestCon2By()
{   
    {
        auto i32_v = std::vector<int >();
        Alan::_Seq_Con_Ins_Gen_Num(i32_v, 0, 0, 1<<10);
        // Alan::ConsoleIterOutput<int >(i32_v);
        Alan::ConsoleBeautyOutput<int >(i32_v);
    }

    {
        auto i32_v = std::vector<int >();
        Alan::_Seq_Con_Ins_Gen_Num(i32_v, 1, 0, 1<<10);
        // Alan::ConsoleIterOutput<int >(i32_v);
        Alan::ConsoleBeautyOutput<int >(i32_v);
    }

    {
        auto i32_v = std::vector<int >();
        Alan::_Seq_Con_Ins_Gen_Num(i32_v, 1<<1, 0, 1<<10);
        // Alan::ConsoleIterOutput<int >(i32_v);
        Alan::ConsoleBeautyOutput<int >(i32_v);
    }

    {
        auto i32_v = std::vector<int >();
        Alan::_Seq_Con_Ins_Gen_Num(i32_v, 1<<2, 0, 1<<10);
        // Alan::ConsoleIterOutput<int >(i32_v);
        Alan::ConsoleBeautyOutput<int >(i32_v);
    }
}

void TestSeqLB_UB()
{
    auto i32_v = 
        std::vector<int >{32, 32, 64, 64};
    Alan::_Seq_Con_Ins_Gen_Num
        (i32_v, 1<<4, 0, 1<<8);
    Alan::_Seq_Con_Dup(i32_v, 1);
    Alan::_Seq_Con_Sort<int >(i32_v);
    
    #define _con_type std::vector<int >
    #define _val_type std::vector<int >::value_type
    #define _iter_type std::vector<int >::iterator

    _COLOR_START(_COLOR_BLUE);
        Alan::ConsoleBeautyOutput<_val_type > (i32_v);
    _COLOR_RECOVER;


    _COLOR_START(_COLOR_CYAN);
        Alan::ConsoleIterOutputIterPair(
            Alan::SeqRange_v0<_val_type, _con_type, _iter_type>
                (i32_v, 1<<5, 1<<6));
    _COLOR_RECOVER;

    _COLOR_START(_COLOR_YELLOW);
        Alan::ConsoleIterOutputIterPair(
            Alan::SeqRange_v1<_val_type, _con_type, _iter_type>
                (i32_v, 1<<5, 1<<6));
    _COLOR_RECOVER;

    _COLOR_START(_COLOR_GREEN);
        Alan::ConsoleIterOutputIterPair(
            Alan::SeqRange_v2<_val_type, _con_type, _iter_type>
                (i32_v, 1<<5, 1<<6));
    _COLOR_RECOVER;

    _COLOR_START(_COLOR_PURPLE);
        Alan::ConsoleIterOutputIterPair(
            Alan::SeqRange_v3<_val_type, _con_type, _iter_type>
                (i32_v, 1<<5, 1<<6));
    _COLOR_RECOVER;
}

// example:
// 1 2 3 
// 4 5 6
void TestPLoc()
{
    Alan::_Point_Loc<double > p1;
    Alan::_Point_Loc<double > p2;
    Alan::_Point_Loc<double > UNUSED p3;
    std::cin >> p1 >> p2;
    PRINTLN_DETAIL(p1[0]);
    PRINTLN_DETAIL(p1[1]);
    PRINTLN_DETAIL(p1[2]);
    // PRINTLN_DETAIL(p1[3]);
    PRINTLN_DETAIL(p1);
    PRINTLN_DETAIL((p1 == p2));
    PRINTLN_DETAIL((p1 != p2));
    PRINTLN_DETAIL(p1 + p2);
    PRINTLN_DETAIL(p1 * p2);
    PRINTLN_DETAIL((p1 ^ p2));
    PRINTLN_DETAIL(p1.to_string());
}

void TestConstPointer()
{
    char const * const _c_l_s = "Hello, Wase!";
    PRINTLN(_c_l_s);

    auto _tsvc = 
        [](const std::vector<int > &i32_v)->bool {
            for( std::vector<int >::const_iterator
                    _it = i32_v.begin();
                    _it != i32_v.end();
                    ++ _it)
                PRINT(*_it), PRINT(", ");
            return true;
        };
    _tsvc(std::vector<int >{1 , 2});
}

void TestConPlus()
{
    typedef std::vector<int > _con_type_1;
    typedef std::deque<double > _con_type_2;
    typedef _con_type_1::value_type _val_tp1;
    typedef _con_type_2::value_type _val_tp2;

    _con_type_1 con1 = {1, 2, 3, 4};
    _con_type_2 con2 = {6.0, 9.8, 7.9, 6.2, 8.3};
    // subsitution failure is not an error 
    // resulting compile failure !!!
    Alan::ConsoleBeautyOutput
        < __TP_PLUS_TRAITS__(_val_tp1, _val_tp2) >
        (Alan::_t_plus(con1, con2));
}