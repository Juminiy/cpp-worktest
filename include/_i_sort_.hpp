#pragma once
#ifndef _I_SORT_HPP
#define _I_SORT_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <algorithm>
__DEF_NS__(Alan::Sort)

template < typename _Container >
GEN_FUNC_COPY
void InsertionSort(_Container & __container)
{
    size_t __move_times_ = 0;
    for(size_t _i = 1; _i < __container.size(); ++ _i)
    {
        auto _sentinel = __container[_i];
        size_t _index = _i - 1;
        while(_index >= 0 && _sentinel < __container[_index])
        {   
            __container[_index+1] = __container[_index]; __move_times_++;
            -- _index;
        }
        __container[_index+1] = _sentinel;  __move_times_++;
        // #ifdef DEBUG_MODE
        //     Alan::ConsoleBeautyOutput(__container); 
        // #endif
    }
    PRINTLN_DETAIL(__move_times_);
}

// 8 10 1 4 21 | 2221 311 0 2 1
// 
template < typename _Iter >
GEN_FUNC_COPY
void MergeSortHelper(_Iter __dest_first, _Iter __dest_last, 
                    _Iter __src_first)
{
    if(__dest_first == __dest_last)
        return;
    
    size_t __sz = __dest_last - __dest_first;
    auto __dest_mid = __dest_first + (__sz >> 1);
    // PRINT_DETAIL(__sz), PRINT(", "),
    // PRINT_DETAIL(*__dest_first), PRINT(", "),
    // PRINTLN_DETAIL(*__dest_last);

    MergeSortHelper(__dest_first, __dest_mid, 
                    __src_first);
    MergeSortHelper(__dest_mid, __dest_last, 
                    __src_first + (__sz >> 1));

    std::merge(__dest_first, __dest_mid, 
                __dest_mid, __dest_last, 
                __src_first);
    
    std::copy(__src_first, __src_first+__sz, 
                __dest_first);
}

template < typename _Container >
GEN_FUNC_COPY
void MergeSort(_Container & __container)
{
    auto __helper_con = _Container(__container.size());
    MergeSortHelper(__container.begin(), __container.end(), 
                    __helper_con.begin());
}



// sequential merge sort

__END_NS__

#endif