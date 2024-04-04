#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_point_loc_.hpp"

#include "../../include/_test_func_.hpp"

#include <iostream>
#include <iomanip>

#include <vector>
#include <deque>
#include <map>

#include <utility>
#include <algorithm>
#include <type_traits>

#include <cassert>
#include <any>
#include <cstdint>
#include <cstddef>
#include <cfloat>


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
    _COLOR_START(_COLOR_BLUE);
        // decltype( Alan::_t_plus(1, 2.5) );
        // PRINTLN_DETAIL();
        PRINTLN(Alan::_Point_Loc<int >::getInstCnt());
    _COLOR_RECOVER;

    Alan::_Point_Loc <double > UNUSED _pa;
    Alan::_Point_Loc <double > UNUSED _pb;
    Alan::_Point_Loc <double > UNUSED _pc;
    // std::cin >> _pa >> _pb;
    // PRINTLN_DETAIL(Alan::_t_plus(_pa, _pb));
    // PRINTLN_DETAIL(Alan::_t_plus("su7", 1));
    Alan::_Point_Loc <int > UNUSED _pi0;
    Alan::_Point_Loc <int > UNUSED _pi1;
    _COLOR_START(_COLOR_BLUE);
        // decltype( Alan::_t_plus(1, 2.5) );
        // PRINTLN_DETAIL();
        PRINTLN(Alan::_Point_Loc<double >::getInstCnt());
        PRINTLN(Alan::_Point_Loc<int >::getInstCnt());
    _COLOR_RECOVER;

    auto _f64_pl_vec = 
        std::vector<Alan::_Point_Loc<double > >();

    typedef std::vector<Alan::_Point_Loc<double > > _con_type;
    typedef _con_type::value_type _val_type;

    _f64_pl_vec.emplace_back(1.5, 2.5, 3.5);
    _f64_pl_vec.emplace_back(0.3, 0.6, 0.74);
    _f64_pl_vec.emplace_back(1.5, 2.5, 3.5);
    _f64_pl_vec.emplace_back(0.3, 0.6, 0.74);
    _f64_pl_vec.emplace_back(9.5, 11.5, 2.5);
    _f64_pl_vec.emplace_back(0.32, 0.61, 4.74);

    Alan::_Seq_Con_Sort<_val_type >(_f64_pl_vec);
    Alan::ConsoleBeautyOutput<_val_type >(_f64_pl_vec);
}

void TestScopeAway()
{
    _COLOR_START(_COLOR_BLUE);
        // decltype( Alan::_t_plus(1, 2.5) );
        // PRINTLN_DETAIL();
        PRINTLN(Alan::_Point_Loc<double >::getInstCnt());
        PRINTLN(Alan::_Point_Loc<int >::getInstCnt());
        PRINTLN(Alan::_Point_Loc<uint32_t >::getInstCnt());
    _COLOR_RECOVER;
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
        Alan::ConsoleIterOutputIterPairRange(
            Alan::SeqRange_v0<_val_type, _con_type, _iter_type>
                (i32_v, 1<<5, 1<<6));
    _COLOR_RECOVER;

    _COLOR_START(_COLOR_YELLOW);
        Alan::ConsoleIterOutputIterPairRange(
            Alan::SeqRange_v1<_val_type, _con_type, _iter_type>
                (i32_v, 1<<5, 1<<6));
    _COLOR_RECOVER;

    _COLOR_START(_COLOR_GREEN);
        Alan::ConsoleIterOutputIterPairRange(
            Alan::SeqRange_v2<_val_type, _con_type, _iter_type>
                (i32_v, 1<<5, 1<<6));
    _COLOR_RECOVER;

    _COLOR_START(_COLOR_PURPLE);
        Alan::ConsoleIterOutputIterPairRange(
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
    PRINTLN("console input double 3d point p1 and p2:");
    // INPUT(std::cin , p1 >> p2);
    PRINTLN_DETAIL(p1[Alan::_Point_Loc<double >::_axis_x]);
    PRINTLN_DETAIL(p1[Alan::_Point_Loc<double >::_axis_y]);
    PRINTLN_DETAIL(p1[Alan::_Point_Loc<double >::_axis_z]);
    // PRINTLN_DETAIL(p1[3]); // assert error 
    PRINTLN_DETAIL(p1);
    PRINTLN_DETAIL((p1 == p2));
    PRINTLN_DETAIL((p1 != p2));
    PRINTLN_DETAIL((p1 < p2));
    PRINTLN_DETAIL(p1 + p2);
    PRINTLN_DETAIL(p1 * p2);
    PRINTLN_DETAIL((p1 ^ p2));
    PRINTLN_DETAIL((p1 += p2));
    PRINTLN_DETAIL((p1 -= p2));
    PRINTLN_DETAIL(p1.to_string());
    PRINTLN("------------------------------");
    Alan::_Point_Loc<int32_t > i32_p0(3, 5, 7);
    Alan::_Point_Loc<double_t > f64_p0(11, 13, 17);
    // PRINTLN("console input i32 3d point p1 and f64 3d p2:");
    // INPUT(std::cin, i32_p0 >> f64_p0);
    // PRINTLN_DETAIL((i32_p0 + f64_p0         
                    // )); // const value is legal
                    // = Alan::_Point_Loc<double_t >(1.0, 2.0, 3.0) )); // non-const value is illegal
    
    // auto _max_p1_p2 = MAX_Tp_t(p1, p2);
    // auto _min_p1_p2 = MIN_Tp_t(p1, p2);
    // PRINTLN_DETAIL(_max_p1_p2);
    // PRINTLN_DETAIL(_min_p1_p2);
    _COLOR_START(_COLOR_CYAN);
        PRINTLN_DETAIL(i32_p0);
        PRINTLN_DETAIL(f64_p0);
        PRINTLN_DETAIL(f64_p0 * 5);
        PRINTLN_DETAIL(f64_p0 / 3);
        PRINTLN_DETAIL(f64_p0 * 0);
        PRINTLN_DETAIL(10.2 * f64_p0); 
        // PRINTLN_DETAIL(i32_p0 / 0); // assert failed 
        // PRINTLN("Please input z axis of point f64_p0");
        // HANDINPUT(f64_p0[2]);
        PRINTLN_DETAIL(f64_p0);
        PRINTLN(f64_p0.operator<(Alan::_Point_Loc<double>(1, 2, 3)));
        PRINTLN_DETAIL(std::boolalpha << 
             (Alan::_has_operator_less_overload<decltype(f64_p0)>::value));
        class _my_cls_no_opt_less {};
        PRINTLN_DETAIL(std::boolalpha << 
             (Alan::_has_operator_less_overload<_my_cls_no_opt_less>::value));
    _COLOR_RECOVER;
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
    typedef std::vector<int >       UNUSED _con_type_1;
    typedef std::deque<double >     UNUSED _con_type_2;
    typedef _con_type_1::value_type UNUSED _val_tp1;
    typedef _con_type_2::value_type UNUSED _val_tp2;

    // here clang claims about substitution failuire:
    // so I think, substitution failuire is an error(SFIAE)
    #if (__CC_VER__ != 4)
        _con_type_1 con1 = {1, 2, 3, 4};
        _con_type_2 con2 = {6.0, 9.8, 7.9, 6.2, 8.3};
        // subsitution failure is not an error 
        // resulting compile failure !!!
        Alan::ConsoleBeautyOutput
            < __TP_PLUS_TRAITS__(_val_tp1, _val_tp2) >
            (Alan::_t_plus(con1, con2));
    #endif
}

void TestBitwiseChange()
{
    Alan::_parr<int > pArr0(10);
    auto pArr0_data = pArr0.data();
    pArr0_data[3] = 5;
    for(size_t _i=0; _i < 10; ++_i)
        PRINTLN_DETAIL(pArr0_data[_i]);
    
    PRINTLN_DETAIL(pArr0.data()[3]);
}

void TestSZof()
{
    _COLOR_START(_COLOR_PURPLE);
        PRINTLN_DETAIL(sizeof(Alan::_Point_Loc<double >));
        // PRINTLN_DETAIL(sizeof(Alan::_Point_Loc<double >::_min_bound));
        // PRINTLN_DETAIL(sizeof(Alan::_Point_Loc<double >::_max_bound));
    _COLOR_RECOVER;
    // // make no sense 
    // // using namespace std::literals;
    using namespace Alan;

    // PRINTLN_DETAIL(std::make_pair 
    //                     (std::make_pair("key", 1), 
    //                     std::make_pair(2, "value")));


    // make no sense
    // why ? _algo_.cc:466 make effect
    // but here not 
    // PRINTLN(std::pair(std::string("key"), 1));
    // auto _re_ms = 
    //     std::multimap< double, std::string, std::greater<double > > ();
    // for (auto &_pr : _re_ms)
    //     PRINTLN(_pr);

    // PRINTLN_DETAIL(*_smap.begin());
    
    // PRINTLN_DETAIL(std::make_pair(std::string("key"), 1)
    // PRINTLN_DETAIL(std::make_pair(2, std::string("val")));

    typedef std::pair <
        std::pair <
            std::pair <std::string, int>, 
            std::pair <int, int > >,
        std::pair <
            std::pair <double, double >,
            std::pair <unsigned int, std::string> > >
        sipiipddpusp_pair;

    sipiipddpusp_pair _bagabaga;
    PRINTLN("please input: string,3int,2double,uint,string");
    HANDINPUT(_bagabaga);
    _COLOR_START(_COLOR_BLUE);
        PRINTLN_DETAIL(_bagabaga);
    _COLOR_RECOVER;
}

// tested failure
void TestSTDAny()
{
    // auto any_vec = 
    //     std::vector<std::any>();

    // any_vec.push_back(1);
    // any_vec.push_back("dot");
    // any_vec.push_back('c');

    // Alan::ConsoleBeautyOutput<std::any >(any_vec);
}

void TestOp0()
{
    auto i32_mp = std::map<int, int>();
    i32_mp[0];
    using namespace Alan;
    Alan::ConsoleOutputAsso
        <decltype(i32_mp)>
        (i32_mp);
    // for(auto _mit = i32_mp.begin();
    //     _mit != i32_mp.end();
    //     ++ _mit)
    //     PRINT(*_mit), PRINT(", ");
    #define OPT_ORION_INC 1
    #define OPT_ORION_DEC -1
    class Orion {
    public:
        Orion(const int _oc = 0): _opt_code(_oc){}
        void inc() { ++_opt_code; }
        void dec() { --_opt_code; }
        int get() const { return _opt_code; }
    private:
        int _opt_code;
    };
    class Altair {
    public:
        Altair(Orion * _ptr): _orion_ptr(_ptr) {}
        void OptOrion(const int _opt_type) const {
            switch (_opt_type)
            {
            case OPT_ORION_INC:
                this->_orion_ptr->inc();
                break;
            case OPT_ORION_DEC:
                this->_orion_ptr->inc();
                break;
            default:
                OUTPUT(std::cerr, "opt_type error");
                break;
            }
        }
        void ShowOrion() const {
            PRINTLN(this->_orion_ptr->get());
        }
    private:
        Orion * const _orion_ptr;
    };
    auto _orion_ptr = std::make_shared<Orion>(1);
    auto _altar_obj = Altair(&(*_orion_ptr));
    _altar_obj.ShowOrion();
    _altar_obj.OptOrion(OPT_ORION_INC);
    _altar_obj.ShowOrion();

    _COLOR_START(_COLOR_BLUE);
    class _num0 {
    public:
        _num0(const int __i32 = 0) : _i32(__i32) {}
        int get() const {
            return _i32;
        }
    private:
        int _i32;
    };
    class _num1 {
    public:
        _num1(const _num0 & _n0 = _num0()) : _i32(_n0.get()) {}
        // _num1(const int __i32) : _i32(__i32) {}
        int get() const {
            return _i32;
        }
    private:
        int _i32;
    };
    class _num2 {

    };
    _num0 _n0 = 100;
    PRINTLN(_n0.get());
    _num1 _n1; //= 11; // illegal
    PRINTLN(_n1.get());
}

void TestTypeTrait()
{
    PRINTLN(std::boolalpha << 
                (Alan::_is_same_type<int, const int >::_value));
    PRINTLN(std::boolalpha << 
                (Alan::_is_same_type<double, const double >::_value));
    PRINTLN(std::boolalpha << 
                (Alan::_is_same_type<int const *, const int * >::_value));
    PRINTLN(std::boolalpha << 
                (Alan::_is_same_type<int const *, int * const >::_value));
    
    PRINTLN(Alan::_t_plus_v2(1.0, 2.4));
}

void TestOp2()
{
    unsigned long long _i64_num = 0;
    _COLOR_START(_COLOR_CYAN);
        do {
            // std::cin.dec;
            // _i64_num = std::cin.get();
            // TODO:
            // how to realize a buffer safety unsigned long long ?
            // std::cin >> std::dec >> _i64_num;
            // std::cin.sync();
            // PRINTLN(_i64_num);
        }while(_i64_num);
    _COLOR_RECOVER;
}

void TestOp3()
{
    // auto i32_p3 = 
    //     Alan::_Point_Loc<int >(3, 3, 3);
    // auto f32_p0 = 
    //     Alan::_Point_Loc<float >(4.0, 5.0, 6.0);
    
    // auto f32_p0cpy = f32_p0;
    // auto f32_p0cpy2(f32_p0);

    // PRINTLN(i32_p3);
    // PRINTLN(i32_p3.getInstCnt());
    // PRINTLN(f32_p0);
    // PRINTLN(f32_p0cpy);
    // PRINTLN(f32_p0cpy2);

    // args
    auto f64_p1(Alan::_Point_Loc(9.5, 10.5, 11.5));
    // args
    auto f64_p2 = Alan::_Point_Loc(1.2, 2.2, 3.3);
    // PRINTLN(f64_p1);
    // PRINTLN(f64_p2);

    _COLOR_START(_COLOR_BLUE); 
    auto f32p_vec = 
        std::vector<decltype(f64_p1)>();
    f32p_vec.reserve(1<<4);
    
    // copy 
    // after reserve: copy 
    // reference parameter : compile error 
    // const_reference parameter : compile ok, run ok
    f32p_vec.push_back(f64_p1);
    // copy + copy + des
    // after reserve: copy
    // reference parameter : compile error 
    // const_reference parameter : compile ok, run ok
    f32p_vec.push_back(f64_p2);

    // args + move + copy + copy + des + des + des
    // after reserve: args + move + des
    f32p_vec.push_back(decltype(f64_p1)(1.0, 2.3, 4.5));
    // args 
    // after reserve: args
    f32p_vec.emplace_back(1.0, 2.3, 4.5);
    _COLOR_RECOVER;

    Alan::ConsoleBeautyOutput<decltype(f64_p1)>
        (f32p_vec);
    PRINTLN_DETAIL(f64_p1.getInstCnt());
}

void TestResourceManagement()
{
    auto i32_v = 
        std::vector<int >();
    auto cap_mp = 
        std::multimap<int, int >();
    PRINTLN("size start, size end, or 0 to exit");
    for(int i = 0; i < (1<<16); ++i)
        i32_v.push_back(i),
        cap_mp.insert(std::make_pair(
            i32_v.capacity(),
            i32_v.size()
        ));
        // cap_mp[i32_v.capacity()]
        //     = i32_v.size();
    
    // Setp by step debug on lldb
    // gdb on windows is silly
    int _qr_cap = 0;
    while(HANDINPUT(_qr_cap)&& 
            _qr_cap)
    {
        auto se_pr = 
            cap_mp.equal_range(_qr_cap);
        for(auto _it = se_pr.first;
            _it != se_pr.second;
            ++ _it)
            PRINT(_it->second), PRINT(" ");
        PRINTLN("");
    }
}

void TestTypeTraits()
{
    // PRINTLN_DETAIL(std::boolalpha 
    //     << (std::is_same_v<int, int >));
    // PRINTLN_DETAIL(std::boolalpha 
    //     << (std::is_same_v<int, double >));
    // PRINTLN_DETAIL(std::boolalpha 
    //     << (std::is_same_v<int, Alan::_Point_Loc<int > >));
    // PRINTLN_DETAIL(std::boolalpha 
    //     << (std::is_same_v<Alan::_Point_Loc<double >, 
    //                         Alan::_Point_Loc<int > >));
    // PRINTLN_DETAIL(std::boolalpha 
    //     << (std::is_same_v<Alan::_Point_Loc<int >, 
    //                         Alan::_Point_Loc<int > >));

    using _i_want_meta_type = Alan::_Point_Loc<int >;

    PRINTLN_DETAIL(std::boolalpha
        << (std::is_same_v<_i_want_meta_type, 
                            std::decay_t<__CONST__(_i_want_meta_type) > >)); //true

    PRINTLN_DETAIL(std::boolalpha
        << (std::is_same_v<_i_want_meta_type, 
                            std::decay_t<__REF__(_i_want_meta_type) > >)); //true

    PRINTLN_DETAIL(std::boolalpha
        << (std::is_same_v<_i_want_meta_type, 
                            std::decay_t<__CONST_REF__(_i_want_meta_type) > >)); //true

    PRINTLN_DETAIL(std::boolalpha
        << (std::is_same_v<_i_want_meta_type, 
                            std::decay_t<__RREF__(_i_want_meta_type) > >)); //true                
    
    PRINTLN_DETAIL(std::boolalpha
        << (std::is_same_v<_i_want_meta_type, 
                            std::decay_t<__PTR__(_i_want_meta_type) > >)); //false
    
    PRINTLN_DETAIL(std::boolalpha
        << (std::is_same_v<_i_want_meta_type , 
                            std::decay_t<__CONST_PTR__(_i_want_meta_type)> >)); //false

    PRINTLN_DETAIL(std::boolalpha
        << (std::is_same_v<_i_want_meta_type , 
                            std::decay_t<__PTR_TO_CONST__(_i_want_meta_type) > >)); //false
    
    PRINTLN_DETAIL(std::boolalpha
        << (std::is_same_v<_i_want_meta_type , 
                            std::decay_t<__CONST_PTR_TO_CONST__(_i_want_meta_type) > >)); //false

}

void TestFuncTraits()
{
    auto _fn = 
        [](const int & _lhs,
            const int &_rhs) 
            -> int {
            auto _val = _lhs + _rhs;
            PRINTLN_DETAIL(_val);
            return _val;
        };
    std::invoke(_fn, 1, 2);
}

void TestPartrialSpec()
{
    PRINTLN_DETAIL (std::boolalpha
            << Alan::_has_operator_less_overload<int >::value);
    
    PRINTLN_DETAIL (std::boolalpha
            << Alan::_has_operator_less_overload<Alan::_op_v0 >::value);

    PRINTLN_DETAIL (std::boolalpha
            << Alan::_has_operator_less_overload<Alan::_op_v1 >::value);
    
    PRINTLN_DETAIL (std::boolalpha
            << Alan::_has_operator_less_overload<Alan::_op_v2 >::value);
    
    PRINTLN_DETAIL (std::boolalpha
            << Alan::_has_operator_less_overload<Alan::_op_v3 >::value);
}

void TestParSpec2()
{
    auto _fn_ret_int = []() -> int { PRINTLN("invoke lambda ret int"); return 0; };
    auto _fn_ret_void = []() -> void { PRINTLN("invoke lambda ret void"); return; };
    // PRINTLN_DETAIL(std::boolalpha 
    //     << (Alan::_fn_return_type_bool<decltype(_fn_ret_int)>::value));
    // PRINTLN_DETAIL(std::boolalpha 
    //     << (Alan::_fn_return_type_bool<decltype(_fn_ret_void)>::value));
    Alan::_assume_func_return_type<decltype(_fn_ret_int), int >(_fn_ret_int);
    Alan::_assume_func_return_type<decltype(_fn_ret_void)>(_fn_ret_void);
}

void TestAll()
{
    TestBirthDayParadox();
    TestUMap();
    TestUSet();
    TestIterator();
    TestMapDiffer();
    CountKeyWordsOccurences();
    TestMultiContainer();
    TestVectorFunctor();
    TestVectorFunctor2();
    TestVectorFunc3();
    TestRingBuffer();
    TestSSet();
    TestRangeFind();
    TestMatchingPrefix();
    TestAlgo();
    TestIteratorAdapter();
    TestAssoContainerAlgo();
    TestRemoveAlgo();
    TestArbitraryAlgo();
    Test_Tp_AVG();
    Test_LB_UB();
    TestTask();
    TestFunc();
    TestTask2();
    TestNormalRand();
    TestRandRDMT19937();
    TestReadOnlyRBTree();
    TestRRef();
    TestKenoGame();
    TestXorshift32();
    TestHashTable();
    TestPLoc();
    TestADV();
    TestScopeAway();
    TestCon2By();
    TestSeqLB_UB();
    TestPLoc();
    TestConstPointer();
    TestConPlus();
    TestBitwiseChange();
    TestSZof();
    #ifdef _LDB_
        TestLevelDB();
    #endif 
    TestTuple();
    TestSTDAny();
    TestTypeTrait();
    TestOp0();
    // TestOp2();
    TestOp3();
    TestResourceManagement();
    TestTypeTraits();
    TestFuncTraits();
    TestPartrialSpec();
    TestPLoc();
    TestParSpec2();
}

