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
/* const */ std::vector<std::vector<int > >::iterator __first,
/* const */ std::vector<std::vector<int > >::iterator __last,
const std::vector<size_t> & __sz_prefix,
const std::vector<std::vector<int > >::iterator __begin_of)
{   
    size_t __sz = __last - __first;
    if(__sz == 1)
        return;
    else if(__sz == 2)
    {
        auto __second = __first + 1;
        std::merge(__first->begin(), __first->end(),
                __second->begin(), __second->end(),
                __dest_it);
        return;
    } else if(__sz == 3)
    {// optimize by seq 3

    }
    auto __mid = __first + (__sz >> 1);
    auto first_index = __first - __begin_of;
    auto mid_index = __mid - __begin_of;
    size_t to_mid_elem_sz = 
        __sz_prefix[mid_index] - __sz_prefix[first_index];
    MergeSeqHelper(__dest_it, 
        __first, __mid, 
        __sz_prefix, __begin_of);
    MergeSeqHelper(__dest_it + to_mid_elem_sz, 
        __mid, __last, 
        __sz_prefix, __begin_of);
}

void MergeSeq2Seq
(std::vector<int> & __dest,
/* const */ std::vector<std::vector<int > > & __src,
const std::vector<size_t> &__sz_prefix) 
{ 
    MergeSeqHelper(__dest.begin(), 
        __src.begin(), __src.end(), 
        __sz_prefix, __src.begin());
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
    auto szv = __szv_(vv.size());
    for(size_t szi = 0; szi < vv.size(); ++ szi)
    {
        szv[szi] = vv[szi].size() + ((szi) ? szv[szi-1] : 0);
    }
    Alan::ConsoleBeautyOutput(szv);
    Alan::ConsoleBeautyOutputEmbedded2(vv);
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
    auto con1 = Alan::_Gen_Seq_Con<std::vector<int>, 1<<3 >(1, 1<<5);
    // std::sort(con1->begin(), con1->end());
    Alan::ConsoleBeautyOutput(*con1);
    InstantiatePatienceSort(*con1);
    Alan::ConsoleBeautyOutput(*con1);
}

__END_NS__