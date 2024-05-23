#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

#include <iostream>
#include <queue>
#include <fstream>
#include <iomanip>

__DEF_NS__(Alan::SelfAlgo::Inst::DFSV)

class numv0 {
public:
    int vi[40] = {};
    int vis = 0; // 000000000 vis |= (1<<i)
    int n,m;
    void dfs(int level, int num, int total)
    {
        if(level > m) return;
        if(!total){
            for(int i=0;i<level;++i)
                std::cout << vi[i] << ",\n"[i == level-1];
            return;
        }
        
        for(int chs = num; chs <= total; ++chs)
        {
            vi[level] = chs;
        dfs(level+1, chs, total - chs);
        }
    }

    // 1 2 3
    void AHi(int level) {
        if(level >= n) {
            for(int i=0;i<level;++i) 
                std::cout << std::setw(5) << std::right << vi[i];
            std::cout << '\n';
            return;
        }
        // 001001000
        // 110111111
        for(int i=0;i<n;++i){
            if(!(vis & (1<<i))){
                vis |= (1<<i);
                vi[level] = i+1;
                AHi(level+1);
                vis &= (~(1<<i));
            }
        }
    }

};

void TestDFSV()
{
    numv0 num;
    std::cin >> num.n;
    num.AHi(0);
}

__END_NS__