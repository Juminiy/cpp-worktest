#include "../../include/_i_lib_.hpp"

#include "../../include/_stream_.hpp"
#include "../../include/_test_func_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_ai_snake_game_.hpp"

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <tuple>

using namespace std::literals;

std::string testLocalLayout();
void testLocalCppTypeLayout();

void TestReadWriteFile()
{
    std::string fileContent;
    ReadFile(ConFilePath(input.txt), 
                fileContent);
    RewriteFile(ConFilePath(output.txt), 
                fileContent);
}

void TestBoolAlpha()
{   
    testLocalCppTypeLayout();
}

void TestReadLines()
{
    ReadForStdout(ConFilePath(input.txt));
}

void TestCinAteN()
{
    std::string str3;
    // case 1.
    // cin >> str3;
    // cout << str3 << endl;
    // getline(cin, str3);
    // cout << str3 << endl;
    
    // case 2.
    std::getline(std::cin, str3, '\n');
    std::cout << str3 ;
}

void TestOSS()
{
    // string _str_;
    // getline(cin, _str_);
    // PrintOSS(_str_);
    std::cout << Type2String<int>(GetTypeValue<int>()) << std::endl;
    std::cout << Type2String<double>(GetTypeValue<double>()) << std::endl;
    std::cout << std::boolalpha << Type2String<bool>(GetTypeValue<bool>()) << std::endl;
}

// data from https://textlists.info/geography/countries-and-capitals-of-the-world/
int Capitals(int const &case_num)
{
    auto capitalsPtr = std::unique_ptr<std::map<std::string, std::string> >
        ( new std::map<std::string, std::string> );
    auto capitals = *(capitalsPtr.get());
    GetWorldCapitals(ConFilePath(world-capital.txt), 
                        capitals);
    std::string country;

    switch( case_num )
    {
        case 'w':
    fprintf(stdout, "%ld\n", sizeof('-'));
    break;
        case 'p':
    PrintWorldCapitals(capitals, 1 << 3);
    break;
        case 'g':
    
    while(std::getline(std::cin, country))
    {   
        if (!country.compare("q") ||
            !country.compare("quit") ||
            !country.compare("exit") )
            break;
        country = replaceAllWhiteSpace(country);
        std::cout << "Country: " << _RED(country) 
                << "'s Capital: " << _RED(capitals[country]) << std::endl;
    }
    break;
        default:
    return 1;
    }
    return 0;
}

void testLocalCppTypeLayout()
{
    
    std::ostringstream oss;
    std::string destArch = std::string(__PORTABLE__);
    OUTPUTLN(oss, "sizeof builtin type:");
    OUTPUTLN_DETAIL(oss, sizeof(bool));
    OUTPUTLN_DETAIL(oss, sizeof(char));
    OUTPUTLN_DETAIL(oss, sizeof(short));
    OUTPUTLN_DETAIL(oss, sizeof(int));
    OUTPUTLN_DETAIL(oss, sizeof(long));
    OUTPUTLN_DETAIL(oss, sizeof(long long));
    OUTPUTLN_DETAIL(oss, sizeof(float));
    OUTPUTLN_DETAIL(oss, sizeof(double));
    OUTPUTLN_DETAIL(oss, sizeof(long double));
    OUTPUTLN_DETAIL(oss, sizeof(nullptr_t));

    OUTPUTLN(oss, "sizeof some constexpr value:");
    OUTPUTLN_DETAIL(oss, sizeof(NULL));
    OUTPUTLN_DETAIL(oss, sizeof(nullptr));
    OUTPUTLN_DETAIL(oss, sizeof(true));
    OUTPUTLN_DETAIL(oss, sizeof(false));

    OUTPUTLN(oss, "sizeof ext type:");
    OUTPUTLN_DETAIL(oss, sizeof(char16_t));
    OUTPUTLN_DETAIL(oss, sizeof(char32_t));
    OUTPUTLN_DETAIL(oss, sizeof(wchar_t));
    OUTPUTLN_DETAIL(oss, sizeof(int8_t));
    OUTPUTLN_DETAIL(oss, sizeof(int16_t));
    OUTPUTLN_DETAIL(oss, sizeof(int32_t));
    OUTPUTLN_DETAIL(oss, sizeof(int64_t));
    OUTPUTLN_DETAIL(oss, sizeof(uint8_t));
    OUTPUTLN_DETAIL(oss, sizeof(uint16_t));
    OUTPUTLN_DETAIL(oss, sizeof(uint32_t));
    OUTPUTLN_DETAIL(oss, sizeof(uint64_t));

    OUTPUTLN_DETAIL(oss, sizeof(size_t));
    OUTPUTLN_DETAIL(oss, sizeof(ssize_t));
    OUTPUTLN_DETAIL(oss, sizeof(off_t));
    OUTPUTLN_DETAIL(oss, sizeof(ptrdiff_t));

    OUTPUTLN_DETAIL(oss, sizeof(intptr_t));
    OUTPUTLN_DETAIL(oss, sizeof(uintptr_t));
    OUTPUTLN_DETAIL(oss, sizeof(intmax_t));
    OUTPUTLN_DETAIL(oss, sizeof(uintmax_t));

    OUTPUTLN(oss, "local machine layout :"""
                    << testLocalLayout() );
    
    std::string oss_str = oss.str();
    AppendFile(ConFilePath(type-info) "." + destArch + "." "txt", oss_str);
    oss_str.clear();
    destArch.clear();
    oss.clear();
}

/*
Model 	Layout	int	    long	pointer	    arch:OS
LP32	2/4/4	2B	    4B	    4B	        Win16
ILP32	4/4/4	4B	    4B	    4B	        Win32 API/Unix/Linux/MacOS
LLP64	4/4/8	4B	    4B	    8B	        x86_64/arm64:Win32 API
LP64	4/8/8	4B	    8B	    8B	        Unix/Linux/MacOS
ILP64	8/8/8	8B	    8B	    8B	        very rare(:UNICOS on Cray)
*/
std::string testLocalLayout()
{
    size_t _int_ = sizeof(int);
    size_t _long_ = sizeof(long);
    size_t _pointer_ = sizeof(NULL);

    if (_int_ == 2 && _long_ == 4 && _pointer_ == 4)
    {
        return "Model[LP32], arch:OS[Win16]";
    }
    else if (_int_ == 4 && _long_ == 4 && _pointer_ == 4)
    {
        return "Model[ILP32], arch:OS[Win32 API/Unix/Linux/MacOS]";
    }
    else if (_int_ == 4 && _long_ == 4 && _pointer_ == 8)
    {
        return "Model[LLP64], arch:OS[x86_64/arm64:Win32 API]";
    }
    else if (_int_ == 4 && _long_ == 8 && _pointer_ == 8)
    {
        return "Model[LP64], arch:OS[Win64/Unix/Linux/MacOS]";
    }
    else if (_int_ == 8 && _long_ == 8 && _pointer_ == 8)
    {
        return "Model[ILP64], arch:OS[very rare(:UNICOS on Cray)]";
    }
    else
    {
        return "Model[unknown], arch:OS[unknown]";
    }
    
}


void TestHasHexLetters_3_version_pat(int const &_round)
{
    int _round_ = _round;
    int _count_ = 0;
    while(_round_ --)
    {
        int _rand_ = rand();
        bool _t_res_bits_ =  HasHexLetters_bits_version(_rand_);
        bool _t_res_bits_2 = HasHexLetters(_rand_);
        bool _t_res_loop_ = HasHexLetters_loop_version(_rand_);
        bool _t_res_ss_ = HasHexLetters_ss_functor_version(_rand_);
        std::cout << "bits(" << _rand_ << ") = " << _t_res_bits_ << ", " 
                << "bitsv2(" << _rand_ << ") = " << _t_res_bits_2 << ", "
                << "loop(" << _rand_ << ") = " << _t_res_loop_ << ", "
                << "ss(" << _rand_ << ") = " << _t_res_ss_ << std::endl;
        if (_t_res_bits_ !=
            _t_res_loop_ ||
            _t_res_bits_2 != 
            _t_res_loop_ || 
            _t_res_ss_ != 
            _t_res_loop_)
            printf("un_eq _num_ = %x\n", _rand_), 
            ++_count_;
    }
    std::cout << "not ok count = " << _count_ << ", total count = " << _round << std::endl;
    std::cout.precision(4);
    std::cout << "not pass rate = "<< ((double)_count_ / (double)_round) * 100<< "%" << std::endl;
}

void DrawTriangle(int const& _n)
{   
    for (int i = 0; i < _n; ++i)
    {
        // 2i+1 
        for (int j = 0; j < (_n << 1) - 1; ++j)
        {
            if (j < _n - i - 1 || j > _n + i - 1)
                std::cout << " ";
            else
                std::cout << "#";
        }
        puts("");
    }
}

void TestInRange(int const &_round)
{   
    int _round_ = _round;
    int _count UNUSED = 0;
    while(_round_ --)
    {
        int _rand = rand() % (1<<30);
        if(I32_IN_RANGE(_rand, 0, (1<<30) - 1))
            ++_count;
    }
        
}

void TestInRangeV2(int const &_round)
{   
    int _round_ = _round;
    int _count UNUSED = 0;
    while(_round_ --)
    {
        int _rand = rand()% (1<<30);
        if (_rand >= 0 && _rand <= (1<<30) - 1)
            ++_count;
    }
}

void TestReadOnlyRBTree()
{
    auto str_i32_map = 
        std::map<std::string, int >();
    str_i32_map["vivi"s] = 1;
    str_i32_map["kaka"s] = 2;
    str_i32_map["lolo"s] = 3;
    auto um_map UNUSED = 
        Alan::ReadOnlyRBTree<std::string, int >(
            str_i32_map
        );
    // PRINTLN_DETAIL(um_map["vivi"]);
    // PRINTLN_DETAIL(um_map["kaka"]);
    // PRINTLN_DETAIL(um_map["lolo"]);

    // PRINTLN_DETAIL(um_map["mama"]);
    // PRINTLN_DETAIL(um_map["dada"]);
    // PRINTLN_DETAIL(um_map["nono"]);


    auto str_p32_map =
        std::map<std::string, pointT>();
    str_p32_map["m10"s] = pointT(0, -1);
    str_p32_map["m11"s] = pointT(1, 0);
    str_p32_map["m12"s] = pointT(0, 1);
    str_p32_map["m13"s] = pointT(-1, 0);
    auto sp_map = 
        Alan::ReadOnlyRBTree<std::string, pointT >(
            str_p32_map
        );
    
    PRINTLN_DETAIL(sp_map["m10"]);
    PRINTLN_DETAIL(sp_map["m11"]);
    PRINTLN_DETAIL(sp_map["m12"]);
    PRINTLN_DETAIL(sp_map["m13"]);

    PRINTLN_DETAIL(sp_map["m20"]);
    PRINTLN_DETAIL(sp_map["m21"]);
    PRINTLN_DETAIL(sp_map["m22"]);
    PRINTLN_DETAIL(sp_map["m23"]);


    PRINTLN_DETAIL(std::boolalpha <<(sp_map | "m10"));
    PRINTLN_DETAIL(std::boolalpha <<(sp_map | "m11"));
    PRINTLN_DETAIL(std::boolalpha <<(sp_map | "m12"));
    PRINTLN_DETAIL(std::boolalpha <<(sp_map | "m13"));

    PRINTLN_DETAIL(std::boolalpha <<(sp_map | "m20"));
    PRINTLN_DETAIL(std::boolalpha <<(sp_map | "m21"));
    PRINTLN_DETAIL(std::boolalpha <<(sp_map | "m22"));
    PRINTLN_DETAIL(std::boolalpha <<(sp_map | "m23"));

}


void TestRRef()
{
    auto i32_v = 
        std::vector<int >();

    i32_v.emplace_back(10);
    i32_v.push_back(10);

    Alan::ConsoleIterOutput<int >(i32_v);
}

void TestTuple()
{
    std::tuple<long long, long long, double, double > 
        f256(0xff, 0x11, 1.25f, 1.25f);

    PRINTLN_DETAIL(std::get<2>(f256));
    // PRINTLN_DETAIL(f256);
}