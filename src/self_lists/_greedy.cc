#include <queue>
#include <vector>
#include <functional>

#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"
#include "../../include/_test_func_.hpp"

__DEF_NS__(Alan::Demos::Test::Func)

size_t MaxActivityCounts
(std::vector<std::vector <int> > &__acs)
{
    auto pq = 
        std::priority_queue<
            std::pair<int, int>, 
            std::vector<std::pair<int, int> >,
            std::greater<std::pair<int, int> >
        >();
    
    for(auto &ac : __acs)
        pq.push(std::make_pair(ac[1], ac[0]));
    
    auto __res = size_t(0);
    auto __prev = pq.top(); pq.pop();
    do
    {
        auto _pr = pq.top(); pq.pop();
        if(_pr.first >= __prev.second)
        {
            __prev = _pr;
            ++ __res;
        }
    } while (!pq.empty());
    
    return __res;
}

__END_NS__