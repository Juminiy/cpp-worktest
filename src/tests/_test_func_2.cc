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
#include <memory>
#include <any>

#include <cassert>
#include <cstdint>
#include <cstddef>
#include <cfloat>
#include <locale>
#include <codecvt>
#include <stdexcept>
#include <cstdint>
#include <cstddef>
#include <cfloat>

__USE_NS__(Alan);
__USE_NS__(Alan::Demos);
__DEF_NS__(Alan::Demos::Test::Func)

// example:
// 1 2 3
// 4.0 5.0 6.0
void TestADV()
{

    PRINTLN_DETAIL(Alan::_t_plus(1, 2.5));
    __USE_NS__(std::literals);
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
    PRINTLN_DETAIL((p1 == p1));
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
    Alan::Demos::_parr<int > pArr0(10);
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
    // // __USE_NS__(std::literals);
    __USE_NS__(Alan);

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
    __USE_NS__(Alan);
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

void TestCppCOrigin()
{
    int _i32_i = 1;

    // arithmetic
    PRINTLN_DETAIL((_i32_i += 10));
    PRINTLN_DETAIL((_i32_i -= 10));
    PRINTLN_DETAIL((_i32_i *= 10));
    PRINTLN_DETAIL((_i32_i /= 10));
    PRINTLN_DETAIL((_i32_i %= 10));

    // bit opt
    PRINTLN_DETAIL((_i32_i ^= 1));
    PRINTLN_DETAIL((_i32_i &= 1));
    PRINTLN_DETAIL((_i32_i |= 1));
    PRINTLN_DETAIL((_i32_i <<= 1));
    PRINTLN_DETAIL((_i32_i >>= 1));
}

void TestCppTid()
{
    __DEF_ALL_V2__(__type_id_h_, Alan::_Point_Loc<int >);
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h_>());
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h__const>());
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h__reference>());
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h__const_reference>());   
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h__r_reference>());
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h__pointer>());
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h__pointer_to_const>());
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h__const_pointer>());
    PRINTLN_DETAIL(Alan::__cpp_tid_<__type_id_h__const_pointer_to_const>());

    auto _u = 
        std::map<int, std::vector<Alan::_Point_Loc<__type_id_h_ > > >();
    PRINTLN_DETAIL(__V_TID_STR__(_u)); 
    // Alan::__cpp_tid_<decltype(_u)>() = 
    // auto __u = 
    // std::__1::map<int, 
    //             std::__1::vector<Alan::_Point_Loc<Alan::_Point_Loc<int>>, 
    //                             std::__1::allocator<Alan::_Point_Loc<Alan::_Point_Loc<int>>>>, 
    //             std::__1::less<int>, 
    //             std::__1::allocator<std::__1::pair<int const, 
    //                                             std::__1::vector<Alan::_Point_Loc<Alan::_Point_Loc<int>>, 
    //                                                             std::__1::allocator<Alan::_Point_Loc<Alan::_Point_Loc<int>>>>>>>();
    // PRINTLN_DETAIL(std::boolalpha << 
    //                ( std::is_same_v<decltype(_u), decltype(__u)> ));
}

void TestSmart_Pointer()
{   
    // // Alan::Demos::_Smart_ptr test failed
    // // using _a_m_t = std::string;
    // auto _u = Alan::Demos::_Smart_ptr
    //     (new std::string("original")); 
    // // bug obj1 if it is not free space allocate

    // auto _u_cp0 = _u;
    // auto _u_cp1 = _u;

    // PRINTLN_DETAIL(_u->c_str());
    // PRINTLN_DETAIL(_u_cp0->c_str());
    // PRINTLN_DETAIL(_u_cp1->c_str());

    // _u_cp1->append("_append_str");
    // PRINTLN_DETAIL(_u->c_str());
    // PRINTLN_DETAIL(_u_cp0->c_str());
    // PRINTLN_DETAIL(_u_cp1->c_str());

}

void TestMemory()
{
    auto m_ptr = 
        std::shared_ptr<std::string>(new std::string("original"));
    auto mptr_cp0 = m_ptr;
    auto mptr_cp1 = mptr_cp0;
    PRINTLN_DETAIL(m_ptr.use_count());
    mptr_cp0->append("_append_str");
    PRINTLN_DETAIL(mptr_cp1->c_str());
    PRINTLN_DETAIL(m_ptr.unique());
}

void TestPrettyFunc()
{
    PRINTLN_DETAIL(__func__);
    PRINTLN_DETAIL(__FUNCTION__);
    #if __CC_VER__ >= 2
        PRINTLN_DETAIL(__PRETTY_FUNCTION__);
    #elif __CC_VER__ == 1 
        PRINTLN_DETAIL(__FUNCSIG__);
    #endif
}

void TestClassOpCase()
{
    Alan::Demos::_a __a_val0(1);
    Alan::Demos::_a __a_val1;
    __a_val1 = __a_val0;
    PRINTLN_DETAIL(__a_val0);
    PRINTLN_DETAIL(__a_val1);
    // TODO: how to realize a singleton type 
    // with private and delete constructor 
    // link error 
    // _Singleton_type::getInst();   
}

void ioInt32(std::string const & _src){
    int _var = 0;
    char _left_over = 0;
    std::stringstream _ss(_src);
    _ss >> _var;
    if(_ss.fail())
        throw std::invalid_argument("input _src must be int");
    _ss >> _left_over;
    if(!_left_over ||
        Alan::_is_bs(_left_over))
        _COLOR_START(_COLOR_GREEN),
            PRINTLN_DETAIL(_var),
        _COLOR_RECOVER;
    else 
        throw std::invalid_argument("input _src is int but has additional vars");
}

void TestHandleException()
{
    try
    {   
        std::string _src;
        PRINTLN("Please input a int32:");
        HANDINPUT(_src);
        ioInt32(_src);
        // ioInt32("vv");
        // ioInt32("22");
    }
    catch(std::invalid_argument const & _ia)
    {
        _COLOR_START(_COLOR_RED),
            ERRLN(_ia.what());
        _COLOR_RECOVER;
    }
}

// scale the num
void TestGen1()
{
    using _con_type0 = std::vector<int >;
    using _con_type1 = std::deque<int >;
    using _con_type2 = std::list<int >;
    int _num_rg1 = 1 << 4;
    int _num_rg2 = 1 << 16;
    // const size_t _sz_about = 
    //     Alan::_Gen_INum(static_cast<size_t>(_num_rg1), 
    //                     static_cast<size_t>(_num_rg2));

    auto i32_v0 = 
        Alan::_Gen_Seq_Con<_con_type0, 1<<10 >(_num_rg1, _num_rg2);
    Alan::ConsoleBeautyOutput(*i32_v0);
    // Alan::ConsoleIterOutput(*i32_v0);

    auto i32_v1 = 
        Alan::_Gen_Seq_Con<_con_type1, 1<<10 >(_num_rg1, _num_rg2);
    Alan::ConsoleBeautyOutput(*i32_v1);
    // Alan::ConsoleIterOutput(*i32_v1);

    auto i32_v2 = 
        Alan::_Gen_Seq_Con<_con_type2, 1<<10 >(_num_rg1, _num_rg2);
    Alan::ConsoleBeautyOutput(*i32_v2);
    // Alan::ConsoleIterOutput(*i32_v2);
}

void TestGen2()
{
    PRINTLN_DETAIL(Alan::_Gen_INum(1, 2));
    PRINTLN_DETAIL(Alan::_Gen_RNum(1.5, 2.5));
    PRINTLN_DETAIL(*Alan::_Gen_Char_Con<std::string>());
}

void TestSpecType0()
{
    auto _type_str = 
        Alan::__cpp_tid_<size_t >();
    PRINTLN_DETAIL(_type_str);
    PRINTLN_DETAIL(Alan::_sfind_any(_type_str, 2, "double", "float"));
    PRINTLN_DETAIL(Alan::_sfind_any(_type_str, 3, "int", "long", "unsigned"));
    auto _bstemp_ = 
        Alan::CONST::_base_blank_space_();
    PRINTLN_DETAIL(std::all_of(_bstemp_.begin(), _bstemp_.end(), Alan::_is_bs));
}

void TestGen3()
{
    auto _base_charT_s_cstr = 
        Alan::CONST::_base_alpha_num_();
    size_t char_sz_single = 1 << 9;

    auto _ch_v0 = 
        Alan::_Gen_Char_Con(_base_charT_s_cstr, char_sz_single);
    auto _ch_v1 = 
        Alan::_Gen_Char_Con(_base_charT_s_cstr, char_sz_single);
    auto _ch_v2 = 
        Alan::_Gen_Char_Con(_base_charT_s_cstr, char_sz_single);
    auto _ch_v3 = 
        Alan::_Gen_Char_Con(_base_charT_s_cstr, char_sz_single);
    PRINTLN_DETAIL(*_ch_v0);
    PRINTLN_DETAIL(*_ch_v1);
    PRINTLN_DETAIL(*_ch_v2);
    PRINTLN_DETAIL(*_ch_v3);

    using _con_type0 UNUSED = std::vector<std::string >;
    using _con_type1 UNUSED = std::deque<std::string >;
    using _con_type2 UNUSED = std::list<std::string >;

    const int _con_size0 = 1<<12;
    const int _ele_size0 = 1<<3;
    const int _ele_size1 = 1<<9;
    auto _str_con_v0 = Alan::_Gen_Seq_Str_Con
                        < _con_size0, _con_type1 >
                        (_base_charT_s_cstr, _ele_size0, _ele_size1);
    auto _minmax_elpair = std::minmax_element(_str_con_v0->begin(), _str_con_v0->end(), 
                                            [](const std::string & _lhs, const std::string & _rhs) 
                                                -> bool {
                                                return _lhs.size() < _rhs.size();
                                            });
    PRINTLN("min = " 
                    << _minmax_elpair.first->size()
                    << ", max = "
                    << _minmax_elpair.second->size());
    // Alan::ConsoleBeautyOutput(*_str_con_v0);
}

void TestGenInteger()
{   
    // signed integer
    {
        auto i32_con = 
        Alan::_Gen_Seq_Con<std::vector<short>, 16>(INT16_MIN, INT16_MAX);
        _COLOR_START(_COLOR_BLUE);
            Alan::ConsoleBeautyOutput(*i32_con);
        _COLOR_END;
    }

    {
        auto i32_con = 
        Alan::_Gen_Seq_Con<std::deque<int>, 16>(INT32_MIN, INT32_MAX);
        _COLOR_START(_COLOR_YELLOW);
            Alan::ConsoleBeautyOutput(*i32_con);
        _COLOR_END;
    }

    {
        auto i32_con = 
        Alan::_Gen_Seq_Con<std::list<long>, 16>(INT32_MIN, INT32_MAX);
        _COLOR_START(_COLOR_CYAN);
            Alan::ConsoleBeautyOutput(*i32_con);
        _COLOR_END;
    }

    {
        auto i32_con = 
        Alan::_Gen_Seq_Con<std::vector<long long>, 16>(INT64_MIN, INT64_MAX);
        _COLOR_START(_COLOR_GREEN);
            Alan::ConsoleBeautyOutput(*i32_con);
        _COLOR_END;
    }

    // unsigned integer
    {
        auto i32_con = 
        Alan::_Gen_Seq_Con<std::vector<unsigned short>, 16>(0, UINT16_MAX);
        _COLOR_START(_COLOR_BLUE);
            Alan::ConsoleBeautyOutput(*i32_con);
        _COLOR_END;
    }

    {
        auto i32_con = 
        Alan::_Gen_Seq_Con<std::deque<unsigned int>, 16>(0, UINT32_MAX);
        _COLOR_START(_COLOR_YELLOW);
            Alan::ConsoleBeautyOutput(*i32_con);
        _COLOR_END;
    }

    {
        auto i32_con = 
        Alan::_Gen_Seq_Con<std::list<unsigned long>, 16>(0, UINT32_MAX);
        _COLOR_START(_COLOR_CYAN);
            Alan::ConsoleBeautyOutput(*i32_con);
        _COLOR_END;
    }

    {
        auto i32_con = 
        Alan::_Gen_Seq_Con<std::vector<unsigned long long>, 16>(0, UINT32_MAX);
        _COLOR_START(_COLOR_GREEN);
            Alan::ConsoleBeautyOutput(*i32_con);
        _COLOR_END;
    }
}

void TestGenFloat32Float64()
{   
    // vector
    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::vector<float>, float, 16>(-1, 0);
        _COLOR_START(_COLOR_BLUE);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }

    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::vector<double>, double, 16>(0, 1);
        _COLOR_START(_COLOR_YELLOW);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }

    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::vector<long double>, long double, 16>(-1, 1);
        _COLOR_START(_COLOR_CYAN);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }

    // deque
    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::deque<float>, float, 16>(-1, 0);
        _COLOR_START(_COLOR_BLUE);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }

    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::deque<double>, double, 16>(0, 1);
        _COLOR_START(_COLOR_YELLOW);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }

    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::deque<long double>, long double, 16>(-1, 1);
        _COLOR_START(_COLOR_CYAN);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }

    // list
    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::list<float>, float, 16>(-1, 0);
        _COLOR_START(_COLOR_BLUE);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }

    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::list<double>, double, 16>(0, 1);
        _COLOR_START(_COLOR_YELLOW);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }

    {
        auto f32_con = 
            Alan::_Gen_Seq_Con<std::list<long double>, long double, 16>(-1, 1);
        _COLOR_START(_COLOR_CYAN);
            Alan::ConsoleBeautyOutput(*f32_con);
        _COLOR_END;
    }
}

void TestGenStrv0()
{   
    auto _base_charT_s_cstr = 
        Alan::CONST::_base_alpha_num_();
    const int _sz_rg1 = 4;
    const int _sz_rg2 = 8;
    {
        auto str_con = 
            Alan::_Gen_Seq_Str_Con
                <std::vector<std::string>, 8>
                (_base_charT_s_cstr, _sz_rg1, _sz_rg2);
        _COLOR_START(_COLOR_CYAN);
            Alan::ConsoleBeautyOutput(*str_con);
        _COLOR_END;
    }

    {
        auto str_con = 
            Alan::_Gen_Seq_Str_Con
                <8, std::deque<std::string>>
                (_base_charT_s_cstr, _sz_rg1, _sz_rg2);
        _COLOR_START(_COLOR_GREEN);
            Alan::ConsoleBeautyOutput(*str_con);
        _COLOR_END;
    }

    {
        auto str_con = 
            Alan::_Gen_Seq_Str_Con
                <8, std::list<std::string>>
                (_base_charT_s_cstr, _sz_rg1, _sz_rg2);
        _COLOR_START(_COLOR_YELLOW);
            Alan::ConsoleBeautyOutput(*str_con);
        _COLOR_END;
    }
}

void TestUnicodev0()
{   
    // runtime error in msys2
    // std::locale::global(std::locale(""));

    // make no sense in msys2
    OUTPUTLN_DETAIL(std::wcout, L'\u4E01');

}

void TestGenBound()
{
    // Alan::ConsoleBeautyOutput(Alan::_Gen_Seq_Str_Con(Alan::CONST::, ));
    ConsoleBeautyOutput(*_Gen_Seq_Con<std::vector<int > >(1,5));
}

void TestGenerateFullv1()
{
    TestGen1();
    TestGen2();
    TestGen3();
    TestGenInteger();
    TestGenFloat32Float64();
    TestGenStrv0();
    TestGenBound();
}

void TestAll()
{   
    // TestBirthDayParadox();
    // TestUMap();
    // TestUSet();
    // TestIterator();
    // TestMapDiffer();
    // CountKeyWordsOccurences();
    // TestMultiContainer();
    // TestVectorFunctor();
    // TestVectorFunctor2();
    // TestVectorFunc3();
    // TestRingBuffer();
    // TestSSet();
    // TestRangeFind();
    // TestMatchingPrefix();
    // TestAlgo();
    // TestIteratorAdapter();
    // TestAssoContainerAlgo();
    // TestRemoveAlgo();
    // TestArbitraryAlgo();
    // Test_Tp_AVG();
    // Test_LB_UB();
    // TestTask();
    // TestFunc();
    // TestTask2();
    // TestNormalRand();
    // TestRandRDMT19937();
    // TestReadOnlyRBTree();
    // TestRRef();
    // TestKenoGame();
    // TestXorshift32();
    // TestHashTable();
    // TestPLoc();
    // TestADV();
    // TestScopeAway();
    // TestCon2By();
    // TestSeqLB_UB();
    // TestPLoc();
    // TestConstPointer();
    // TestConPlus();
    // TestBitwiseChange();
    // TestSZof();
    // #ifdef _LDB_
    //     TestLevelDB();
    // #endif 
    // TestTuple();
    // TestSTDAny();
    // TestTypeTrait();
    // TestOp0();
    // // TestOp2();
    // TestOp3();
    // TestResourceManagement();
    // TestTypeTraits();
    // TestFuncTraits();
    // TestPartrialSpec();
    // TestPLoc();
    // TestParSpec2();

    // TestConV2();
    // TestCopySeq();
    // TestCppCOrigin();
    // TestCppTid();
    // TestSmart_Pointer();
    // TestMemory();
    // TestPrettyFunc();
    // TestClassOpCase();
    // TestHandleException();
    // TestTask3();
    // TestTask4();
    // TestSpecType0();
    // TestUnicodev0();

    // TestGenerateFullv1();
    TestAllV3();
}

__END_NS__