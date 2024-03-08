#include "_i_lib_.hpp"
#include "_seq_container_.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>

#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <iterator>
#include <functional>

// sequential container
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <forward_list>
#include <valarray>

// sequential container adapter
#include <stack>
#include <queue>



void TestConstAndPointer()
{   
    const int I32_INIT = 88888888;
    const int I32_CHNG = 99999999;
    int i32 = 0;
    // 
    {
        i32 = I32_INIT;
        const int * const_ptr = &i32;
        // *const_ptr = I32_CHNG;
        const_ptr ++;
        printf("i32 = %d\n*ptr = %d\n", i32, *const_ptr);
    }


    {
        i32 = I32_INIT;
        int* const int_const_ptr = &i32;    
        *int_const_ptr = I32_CHNG;
        // int_const_ptr ++;
        printf("i32 = %d\n*ptr = %d\n", i32, *int_const_ptr);
    }
    

    {
        i32 = I32_INIT;
        const int * const const_int_const_ptr = &i32;
        // *const_int_const_ptr = I32_CHNG;
        // const_int_const_ptr ++;
        printf("i32 = %d\n*ptr = %d\n", i32, *const_int_const_ptr);
    }
}

void TestAutoBind()
{
    auto i32_i32_i32 = std::make_pair(1, std::make_pair<int,int>(1, 2));
    auto [i32_0, i32_12] = i32_i32_i32;
    auto [i32_1,i32_2] = i32_12;
    
    PRINTLN(std::to_string(i32_0));
    PRINTLN(std::to_string(i32_1));
    PRINTLN(std::to_string(i32_2));
}

void TestVector()
{
    std::vector<std::vector<int>> vi32_2d;
    vi32_2d.push_back({1,2,3});
    vi32_2d.push_back({4,5,6});
    vi32_2d.push_back({7,8,9});
    for (auto &vi32 : vi32_2d)
    {
        for (auto &i32 : vi32)
        {
            printf("%d ", i32);
        }
        printf("\n");
    }    
    std::vector<int> vi32;
    vi32.push_back(1);
    for (auto &i32 : vi32)
    {
        printf("%d ", i32);
    }   
}

void TestVectorFunctor()
{
    std::vector<int> vi32(1<<5);
    generate(vi32.begin(), 
                vi32.end(), 
                rand);
    sort(vi32.begin(), 
            vi32.end(), 
            std::less<int>());

    copy(vi32.cbegin(), 
            vi32.cend(), 
            std::ostream_iterator<int>(std::cout, "\n"));

    std::ofstream out("../test/static-file/num_gen_sort.txt", 
                        std::ios::out);
    copy(vi32.cbegin(), 
            vi32.cend(), 
            std::ostream_iterator<int>(out, "\n"));

    std::ifstream in("../test/static-file/num_gen_sort.txt", 
                        std::ios::in);
    copy(std::istreambuf_iterator<char>(in), 
            std::istreambuf_iterator<char>(), 
            std::ostreambuf_iterator<char>(std::cout));
}

void TestValArray()
{
    std::valarray<int> vay{1, 2, 3, 4, 5};
    std::cout << vay.sum() << std::endl;

    std::vector<int> vay_pup;
    vay_pup.push_back(1);
    vay_pup.emplace_back(2);
}

void TestVectorFunctor2()
{       
    PSEUDORANDOM_DECL
    std::vector<int> _vi(1<<8);
    std::fill(_vi.begin(), 
                _vi.end(), 
                rand()%(1<<4));
    std::copy(_vi.cbegin(),
                _vi.cend(),
                std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;
    int _i32_cmp = rand()%10;
    std::cout << _i32_cmp 
                << " in vector occurs "
                << std::count_if(_vi.cbegin(),
                                    _vi.cend(),
                                    [&](int const &_i32){
                                        return _i32 == _i32_cmp;
                                    }) 
                << " times."
                << std::endl;
}


void TestVectorFunc3()
{   
    // 4 4 
    // 4 1
    // 8 
    typedef struct ele0
    {
        int a,b,c;
        char si;
        struct ele0* next_e;
        ele0(int _a, 
                int _b, 
                int _c, 
                char _si, 
                struct ele0* _next_e): 
                    a(_a), 
                    b(_b), 
                    c(_c), 
                    si(_si), 
                    next_e(_next_e){}
        void print(){
            printf("[%p, %d, %d, %d, %c, %p]", (void*)this, a, b, c, si, (void*)next_e);
        }
    } ele0;
    std::vector<ele0> _ev;
    ele0 _e0(1, 2, 3, 'c', NULL);
    _ev.push_back(_e0);
    _ev.emplace_back(_e0);
    _ev.emplace_back(_e0);

    for(auto &_e_ UNUSED : _ev)
        _e_.print(), putchar(',');
    

    {
        PRINTLN("\nsomething changed\n");
        _e0.a = 999;
        _e0.c = 'a';
        _e0.next_e = &_e0;
    }   

    std::reverse(_ev.begin(), 
                    _ev.end());

    // _ev.size();
    _ev.erase(_ev.begin());

    for(auto &_e_ UNUSED : _ev)
        _e_.print(), putchar(',');
    

    std::deque<int> dq_i32;
    for(int i=0;i<1<<6; ++i)
        dq_i32.push_back(i);

    PRINTLN(std::to_string(dq_i32.size()));
}

void TestRingBuffer()
{
    _COLOR_START(_COLOR_BLUE);
    Alan::RingBuffer<int> _ring(std::vector<int>{1,2,3,4,5,6,7,8,9,10});
    _ring.print();
    PRINTLN("something changed");
    // _ring++;
    _ring.print();
    PRINTLN("something changed");
    // _ring--;
    _ring.print();
    _COLOR_RECOVER;
}

static std::string inline genString(int const &_len)
{
    PSEUDORANDOM_DECL
    std::string _dest;
    _dest.reserve(_len);
    for(int i=0;i<_len; ++i)
        _dest += _letter_xx[rand()%_letter_len];

    return _dest;
}

void TestAgainstVectorReverseWithNot()
{   
    PSEUDORANDOM_DECL

    int MAX_SZ_T = 0;
    int MAX_SZ_S = 0;
    // parse arg
    {
        bool _first = true;
        for(long unsigned int i = 0; i < strlen(optarg); ++i )
        {
            char argi = optarg[i];
            if ( argi == ',')
            {
                _first = false;
                continue;
            }else if ( isdigit(argi) )
            {
                if (_first)
                {
                    MAX_SZ_T = I32_MUL10(MAX_SZ_T) + (argi - '0');
                } else 
                {
                    MAX_SZ_S = I32_MUL10(MAX_SZ_S) + (argi - '0');
                }
            }
        }
        if (!I32_IN_RANGE(MAX_SZ_T, 0, 24))
            MAX_SZ_T = 1 << 16;
        else 
            I32_LSHIFT(MAX_SZ_T);
        if (!I32_IN_RANGE(MAX_SZ_T, 0, 16))
            MAX_SZ_S = 1 << 8;
        else 
            I32_LSHIFT(MAX_SZ_S);
    }

    // reserved
    {
        std::vector<std::string> _v1;
        clock_t _s = clock();
        _v1.reserve(MAX_SZ_T);
        for(int i=0;i< MAX_SZ_T; ++i)    
            _v1.push_back(genString(rand()%MAX_SZ_S));
        _COLOR_START(_COLOR_BLUE);
        std::cout << "    reserved " 
                    << MAX_SZ_T << "*" 
                    << MAX_SZ_S << " cost " 
                    << TILLNOW(_s) 
                    << " seconds" << std::endl;
        _COLOR_RECOVER;
        _v1.clear();
    }
    
    // not reserved
    {
        std::deque<std::string> _v2;
        clock_t _s = clock();
        for(int i=0;i< MAX_SZ_T; ++i )    
            _v2.push_back(genString(rand()%MAX_SZ_S));
        _COLOR_START(_COLOR_PURPLE);
        std::cout << "not reserved " 
                    << MAX_SZ_T 
                    << "*" << MAX_SZ_S 
                    << " cost " 
                    << TILLNOW(_s) 
                    << " seconds" << std::endl;
        _COLOR_RECOVER;
        _v2.clear();
    }
}

std::string VigenereEncrypt(std::string const & _en, 
                                std::vector<int> const &_sa)
{   
    std::string _encrypted;
    _encrypted.reserve(_en.size());
    int char_CT = 256;
    Alan::RingBuffer<int> _salt(_sa);
    for(auto &_ch : _en)
    {
        _encrypted.push_back((_salt.readAtCursor() + _ch) % char_CT);
        _salt.clockwise();
    }

    return _encrypted;
}   

// xxx;1,2,3,4
void TestVigenereEncrypt()
{   
    // std:: cout << VigenereEncrypt("sss", std::vector<int>()) << std::endl;
    // return ;
    std::string _en;
    std::vector<int> _sa;
    bool _en_fi = false;
    int cur_sai = 0;
    for(unsigned long int i = 0; i < strlen(optarg); ++i )
    {
        char argi = optarg[i];
        if(argi == 'L')
        {
            _en_fi = true;
            continue;
        } 
        if (!_en_fi){
            _en += argi;
        } else {
            if (argi == ',')
            {
                _sa.push_back(cur_sai);
                cur_sai = 0;
            } else if (isdigit(argi))
            {
                I32_CHARIN(cur_sai, argi);
            } else {
                std::cerr << "err input" << std::endl;
                exit(130);
            }
        }
    }
    if (cur_sai)
        _sa.push_back(cur_sai);
    
    
    _COLOR_START(_COLOR_CYAN);
    //VigenereEncrypt(_en, _sa) segment-fault
    std::string _res = VigenereEncrypt(_en, _sa);
    std:: cout << "encrypted <" 
                    << _en << "> = <" 
                    << _res << ">" 
                    << std::endl; 
    _COLOR_RECOVER; 
}

void TestForwardList()
{
    std::forward_list<int> i32_fl;
    // i32_fl.
}