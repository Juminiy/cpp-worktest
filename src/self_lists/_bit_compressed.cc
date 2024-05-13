#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

__DEF_NS__(Alan::SelfAlgo::Inst)

void KOfN::CalLineOfCnt()
{
    this->lineOfCnt = 1<<n;
    for(int mask = 0; mask < (1<<n); ++mask)
    {
        for(int i = 1; i < n; ++i)
        {
            if((mask & (1<<i)) && (mask & (1<<(i-1))))
            {
                this->lineOfCnt--; 
                break;
            }
        }
    }
}

void TestKOfN()
{
    auto kOfN = KOfN();
    for(;;){
    std::cin >> kOfN;
    if(kOfN.n < 0 || kOfN.n > 9)
        return;
    kOfN.CalLineOfCnt();
    PRINTLN_DETAIL(kOfN);
    }
    
}

__END_NS__