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

void TestXXX()
{
    auto kOfN = KOfN();
    std::cout << kOfN;
}

bool conflict(int i, int in, int j, int jn, int n){
    if(i == j || in & jn)
        return true;
    int x = 0, y = 0;
    while(x< n) {
        if(in & (1<<x)) break;
        ++x;
    }
    while(y< n) {
        if(jn & (1<<y)) break;
        ++y;
    }
    x = n-x-1;
    y = n-y-1;

    return i-x == j-y || i+x == j+y;

}

void dfsEQ(int i, int &cnt, int vi[20], int n)
{
    if(i == n)
    {
        ++cnt;
        return;
    }

    for(int j = 0; j < n; ++j){
        bool ok = true;
        for(int x = 0; x < i; ++x){
            if(conflict(i, 1<<j, x, vi[x], n))
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            vi[i] = 1<<j;
            dfsEQ(i+1, cnt, vi, n);
        }       
    }
}

// void dfsEQv2(int i, int &cnt, int col, int n)
// {
//     if(i == n)
//     {
//         ++cnt;
//         return;
//     }

//     for(int j = 0; j < n; ++j){
//         bool ok = true;
//         for(int x = 0; x < i; ++x){
//             if(conflict(i, 1<<j, x, vi[x], n))
//             {
//                 ok = false;
//                 break;
//             }
//         }
//         if(ok)
//         {
//             vi[i] = 1<<j;
//             dfsEQ(i+1, cnt, vi, n);
//         }       
//     }
// }

int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int count = 0;
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                count += solve(n, row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
            }
            return count;
        }
    }


void TestEightQueens()
{
    int n = 0, tot = 0;
    // int vi[20] = {0};
    std::cin >> n;
    auto tm = Alan::__time_count_(solve, n, 0, 0, 0, 0);
    PRINTLN("ans: " << tot);
    PRINTLN("time: " << tm << " ms");
}

__END_NS__