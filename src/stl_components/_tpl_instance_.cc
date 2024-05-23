#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_2.hpp"

#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <algorithm>

__USE_NS__(Alan::TypeDecl);
__DEF_NS__(Alan::Demos::Test::Func)

void MergeHeap2Seq(std::vector<int> & __dest,
                    std::priority_queue<int> & __src1, 
                    std::priority_queue<int> & __src2) 
{
    // keep __dest original state only append, do not bother it.
    __dest.reserve(__dest.size() + __src1.size() + __src2.size());
    __LOOP_GLB__(!__src1.empty() && !__src2.empty())
    {
        auto _e1 = __src1.top();
        auto _e2 = __src2.top();
        if(_e1 < _e2) 
        {
            __dest.push_back(_e1);
            __src1.pop();
        } else
        {
            __dest.push_back(_e2);
            __src2.pop();
        }
    }
    __LOOP_GLB__(!__src1.empty())
    {
        __dest.push_back(__src1.top());
        __src1.pop();
    }
    __LOOP_GLB__(!__src2.empty())
    {
        __dest.push_back(__src2.top());
        __src2.pop();
    }
}

void MergeSeqHelper
(std::vector<int>::iterator __dest_it,
std::vector<int>::iterator __tmp_dest_it,
/* const */ std::vector<std::vector<int > >::iterator __first,
/* const */ std::vector<std::vector<int > >::iterator __last,
const std::vector<size_t> & __sz_prefix,
const std::vector<std::vector<int > >::iterator __begin_of,
const std::vector<int >::iterator __end_of)
{   
    size_t __sz = __last - __first;

    // if(__sz == 3)
    // {// optimize by seq 3

    // } else 
    if(__sz == 2)
    {
        auto __second = __first + 1;
        std::merge(__first->begin(), __first->end(),
                    __second->begin(), __second->end(),
                    __tmp_dest_it);
        return;
    } else if (__sz == 1)
    {
        std::merge(__first->begin(), __first->end(), 
                    __end_of, __end_of, 
                    __tmp_dest_it);
        return;
    } else if (__sz == 0)
    {
        return;
    }

    auto __mid = __first + (__sz >> 1);
    auto first_index = __first - __begin_of;
    auto mid_index = __mid - __begin_of;
    auto last_index = __last - __begin_of;
    size_t to_mid_elem_sz = 
        __sz_prefix[mid_index] - __sz_prefix[first_index];
    size_t to_end_elem_sz = 
        __sz_prefix[last_index] - __sz_prefix[first_index];
    auto main_seq_mid = __dest_it + to_mid_elem_sz;
    auto main_seq_end = __dest_it + to_end_elem_sz;
    auto tmp_seq_mid = __tmp_dest_it + to_mid_elem_sz;
    auto tmp_seq_end = __tmp_dest_it + to_end_elem_sz;

    MergeSeqHelper(
        __dest_it, __tmp_dest_it,
        __first, __mid, 
        __sz_prefix, 
        __begin_of, 
        __end_of);
    MergeSeqHelper(
        main_seq_mid, tmp_seq_mid,
        __mid, __last, 
        __sz_prefix, 
        __begin_of, 
        __end_of);
    
    std::merge(
        __dest_it, main_seq_mid,
        main_seq_mid, main_seq_end,
        __tmp_dest_it
    );

    std::copy(__tmp_dest_it, tmp_seq_end, __dest_it);

}

void MergeSeq2Seq
(std::vector<int> & __dest,
/* const */ std::vector<std::vector<int > > & __src,
const std::vector<size_t> &__sz_prefix) 
{ 
    auto __tmp_dest = std::vector<int>(__dest.size());
    MergeSeqHelper(
        __dest.begin(), __tmp_dest.begin(),
        __src.begin(), __src.end(), 
        __sz_prefix, 
        __src.begin(), 
        __dest.end()
    );
}   


void InstantiatePatienceSort(std::vector<int> & __con)
{
    // 1. vec 
        // (1). div for vec<vec> 
        // (2). merge vec<vec> into vec
        //      metioned to reverse in seq
        //      metioned to reserve to seq
    __decl_type_emb__(int, i32, std::vector, v);
    __decl_type_emb__(__i32v_, i32v, std::vector, v);

    auto vvsz = Alan::Log2Up(__con.size());
    auto visz = __con.size() / vvsz; 

    auto vv = __i32vv_();
    vv.reserve(vvsz);

    auto push_elem = 
        [&] (int __elem_) -> bool 
        {
            for(auto & _vi : vv)
            {
                if(_vi.back() <= __elem_)
                {
                _vi.push_back(__elem_);
                return true;
                }
            }
            return false;
        };

    for(auto & __elem : __con)
    {
        if(!push_elem(__elem))
        {
            auto vi = __i32v_();
            vi.reserve(visz);
            vi.push_back(__elem);
            vv.push_back(std::move(vi));
        }
    }

    __decl_type_emb__(size_t, sz, std::vector, v);
    // size index >> 1
    auto szv = __szv_(vv.size()+1);
    for(size_t szi = 0; szi < vv.size(); ++ szi)
    {
        szv[szi] = vv[szi].size() + ((szi) ? szv[szi-1] : 0);
    }
    std::copy(szv.begin(), szv.begin()+vv.size(), szv.begin() + 1); szv[0] = 0;

    // Alan::ConsoleBeautyOutput(szv);
    // Alan::ConsoleBeautyOutputEmbedded2(vv);
    MergeSeq2Seq(__con, vv, szv);

}

bool operator < (std::priority_queue<int> & pq1,
                std::priority_queue<int> & pq2)
{
    return !pq1.empty() && !pq2.empty() && 
            pq1.top() < pq2.top();
}

void InstPSortOptimize()
{
    // 2. pq
        // (1). read from __con and div to pq<pq>
        // (2). merge pq<pq> into pq
        // (3). write pq into __con
        // pqpq and pq make no sense
    // __decl_type_emb__(int, i32, std::priority_queue, pq);
    // __decl_type_emb__(__i32pq_, i32pq, std::priority_queue, pq);
    // auto con = __i32pqpq_();

    // for(auto _elem : __con)
    // {

    // }
}

void TestPaSort()
{
    // __decl_type_emb__(int, i32, std::vector, v);
    auto con1 = Alan::_Gen_Seq_Con<std::vector<int>, 1<<8 >(1, 1<<10);
    
    // Alan::ConsoleBeautyOutput(*con1);
    auto seq1 = *con1;
    auto seq2 = decltype(seq1)(seq1);
    PRINTLN_DETAIL(Alan::__time_count_(InstantiatePatienceSort, seq1));
    // PRINTLN_DETAIL(Alan::__time_count_(Alan::Sort::QuickSort<decltype(seq1)>, seq1));
    PRINTLN_DETAIL(Alan::__time_count_(std::sort<decltype(seq2.begin())>, seq2.begin(), seq2.end()));
    
    // PRINTLN_DETAIL((seq1 == seq2));
    Alan::ConsoleBeautyOutput(seq1);
    Alan::ConsoleBeautyOutput(seq2);
    auto _diff2 = Alan::ShowDiff(seq1, seq2);
    _COLOR_START(_COLOR_GREEN);
    Alan::ConsoleBeautyOutput(_diff2.first);
    _COLOR_START(_COLOR_RED);
    Alan::ConsoleBeautyOutput(_diff2.second);
    _COLOR_START(_COLOR_CYAN);
    // Alan::ConsoleBeautyOutput(Alan::FindUnOrdered(seq1));
    PRINTLN("unordered seq size = " << Alan::FindUnOrdered(seq1).size());
    _COLOR_RECOVER;
    
}

__END_NS__