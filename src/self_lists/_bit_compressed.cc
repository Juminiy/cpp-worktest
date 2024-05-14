#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

__DEF_NS__(Alan::SelfAlgo::Inst)

void KOfN::CalLineOfCnt()
{
    this->lineOfCnt = 0;
    for(int mask = 0; mask < (1<<n); ++mask)
    {
        auto ok = true;
        for(int i = 1; i < n; ++i)
        {
            if((mask & (1<<i)) && (mask & (1<<(i-1))))
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            this->lineLoc[this->lineOfCnt] = mask;
            this->lineCnt[this->lineOfCnt] = __builtin_popcount(mask);
            ++ this->lineOfCnt;
        }
    }
}

bool KOfN::canNotPlace(int i, int j)
{
    return (lineLoc[i]&lineLoc[j]) ||
            ((lineLoc[i]<<1)&lineLoc[j])||
            (lineLoc[i]&(lineLoc[j]<<1));
}

/*
    101010
    010101
    001010
*/
void KOfN::CountOf()
{
    for(int i = 0; i < lineOfCnt; ++i)
        dp[0][i][lineCnt[i]] = 1;

    for(int line = 1; line < n; ++line)
        for(int i = 0; i < lineOfCnt; ++i)
        for(int j = 0; j < lineOfCnt; ++j)
        if(canNotPlace(i, j))
            continue;
        else
            for(int l = lineCnt[i]; l <= k; ++l)
                dp[line][i][l] += dp[line-1][j][l-lineCnt[i]];
    
    tot = 0;
    for(int i = 0; i < lineOfCnt; ++i)
        tot += dp[n-1][i][k];
}

void KOfN::Run()
{
    CalLineOfCnt();
    CountOf();
}

void TestKOfN()
{
    auto kOfN = KOfN();
    // for(;;){
    // std::cin >> kOfN; 
    // if(kOfN.n < 0 || kOfN.n > 15)
    //     return;
    // kOfN.CalLineOfCnt();
    // PRINTLN_DETAIL(kOfN);
    // }
    std::cin >> kOfN;
    kOfN.Run();
    std::cout << kOfN.tot;
}

__END_NS__