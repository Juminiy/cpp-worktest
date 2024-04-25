#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_.hpp"

#include <vector>
#include <queue>
#include <functional>
#include <cmath>

__DEF_NS__(Alan::Demos::Test::Func)

void MergeHeap2Seq(std::vector<int> & __dest,
                    std::priority_queue<int> & __src1, 
                    std::priority_queue<int> & __src2) 
{
    // keep __dest original state only append, do not bother it.
    size_t _o_size = __dest.size();
    __dest.reserve(_o_size + __src1.size() + __src2.size());
    __LOOP_GLB__(!__src1.empty() && !__src2.empty())
    {
        auto _e1 = __src1.top();
        auto _e2 = __src2.top();
        if(_e1 < _e2) 
        {
            __dest.push_back(_e1);
            __src1.pop();
        } else if (_e1 > _e2)
        {
            __dest.push_back(_e2);
            __src2.pop();
        } else 
        {
            __dest.push_back(_e1);
            __dest.push_back(_e2);
            __src1.pop();
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

void MergeSeq2SeqByIter(std::vector<int > & __dest,
    std::vector<std::vector<int > >::const_iterator __first,
    std::vector<std::vector<int > >::const_iterator __last)
{
    
}

void MergeSeq2Seq(std::vector<int > & __dest, 
    const std::vector<std::vector<int > > & __src)
{
    auto _mid = __src.size();

}

void InstatancePatienceSort(std::vector<int > & __container)
{
    // using pq_type = std::priority_queue<int>;
    using vi_type = std::vector<int >;
    // 1. vector of pq
    auto vpq = std::vector<vi_type>();
    
    // vpq.reserve(static_cast<int>(std::log2(static_cast<double>(__container.size()))));
    auto _push_to_vpq =
        [&vpq] (int _elem) 
            -> bool 
        {
            for(auto &_pqi : vpq)
            {

            }
            return false;
        };
    for(auto &_elem : __container)
    {
        // if vpq is empty or not find any fit 
        // then push a new_pq into vpq
        // if ()
        // {

        // }
    }

    // 2. pq of pq
    // using pqpq_type = std::priority_queue<pq_type>;
    // auto pqpq = pqpq_type();
    

}

void TestPaSort()
{

}

__END_NS__