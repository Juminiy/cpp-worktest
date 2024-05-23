#include <cstdio>
#include <algorithm>

typedef struct vt
    {
        int v, t;
        vt(int _v = 0, int _t = 0) : v(_v), t(_t) { }
    } vt;

vt vti[150]; 
int val[150] = {0};   

/* 
70 3
71 100 val[70] = 0;
69 1   val[70] = val[1]+1 = 1
1 2    val[70] = val[69]+2 = 2
*/
// not ok!
int p1048()
{
    int M, T;
    
    scanf("%d%d", &T, &M);
    for(int i = 0; i < M; i++)
        scanf("%d%d", &vti[i].t, &vti[i].v);
    
    for(int m = 0; m < M; m++) 
    {
    for(int t = T; t >= vti[m].t; t--) 
        {
        val[t] = std::max(val[t-vti[m].t] + vti[m].v, val[t]);
        }
    }
    printf("%d\n", val[T]);
    return 0;
}

int main()
{ 
p1048(); 
return 0;
}