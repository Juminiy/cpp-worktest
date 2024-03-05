#include "_seq_container_.hpp"
#include "_i_lib_.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>

// sequential container
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <forward_list>

// sequential container adapter
#include <stack>
#include <queue>

#include <iterator>


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
    
    PRINTLN((i32_0));
    PRINTLN((i32_1));
    PRINTLN((i32_2));
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
    generate(vi32.begin(), vi32.end(), rand);
    sort(vi32.begin(), vi32.end(), std::less<int>());
    copy(vi32.begin(), vi32.end(), std::ostream_iterator<int>(std::cout, "\n"));
    ofstream out("../test/static-file/num_gen_sort.txt", ios::out);
    copy(vi32.begin(), vi32.end(), std::ostream_iterator<int>(out, "\n"));
    ifstream in("../test/static-file/num_gen_sort.txt", ios::in);
    copy(istreambuf_iterator<char>(in), 
            istreambuf_iterator<char>(), 
            ostreambuf_iterator<char>(cout));
}