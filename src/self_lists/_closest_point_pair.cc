#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>

__DEF_NS__(Alan::SelfAlgo::Inst)

// 1.
// https://www.luogu.com.cn/problem/P1257 
// 10W 1e9 / 1s
// input:
// 3
// 1 1
// 1 2
// 2 2
// output: D
// 1.0000

void p1257()
{
    int n;
    std::cin>>n;
    _point2d pp[n+1];
    double _ans = 1e10+1;
    for(int i=0;i<n;i++)
        std::cin>>pp[i].x>>pp[i].y;
    std::sort(pp, pp+n);
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
        _ans = std::min(pp[i]._dis(pp[j]), _ans);
        }
    }
    std::cout 
        << std::fixed 
        << std::setprecision(4)
        << _ans << '\n';
}

// https://www.luogu.com.cn/problem/P1429
// 20W 1e9 / 1s
// input:
// 3
// 1 1
// 1 2
// 2 2
// output: D
// 1.0000


// https://www.luogu.com.cn/problem/P7883
// 40W -1e7~1e7 / 350ms
// input:
// 5
// 1 1
// 1 9
// 9 1
// 9 9
// 0 10
// output: D*D
// 2

__END_NS__

