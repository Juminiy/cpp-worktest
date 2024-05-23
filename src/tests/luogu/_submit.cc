#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>

int main()
{ 
    int n, M, T;
    std::cin >> n >> M >> T;
    typedef struct cons {
    int m, t;
    } cons;
    cons cs[n+1];
    int dp[M+1][T+1] = {0};
    for(int i=0;i<n;i++)
        std::cin >> cs[i].m >> cs[i].t;
    for(int i=0;i<n;i++)
        for(int m = M; m >= cs[i].m; --m)
        for(int t = T; t >= cs[i].t; --t)
        dp[m][t] = std::max({dp[m][t], dp[m-cs[i].m][t-cs[i].t]+1});
    std::cout << dp[M][T];
    return 0;
}