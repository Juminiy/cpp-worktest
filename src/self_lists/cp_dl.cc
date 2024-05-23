#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

__USE_NS__(std);

__DEF_NS__(Alan::SelfAlgo::Copy)

int tnq(int n){
    auto sl = Solution();
    return sl.totalNQueens(n);
}

void TestDL(){
    int n = 0;
    std::cin >> n;
    auto tim = Alan::__time_count_(tnq, n);
    PRINTLN("time: " << tim << " ms");
}

__END_NS__