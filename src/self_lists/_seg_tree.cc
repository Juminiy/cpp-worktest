#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

#include <iostream>
#include <functional>

__DEF_NS__(Alan::SelfAlgo::Inst)

#define __imid(l, r) (((r-l)>>1) + l)
#define __pow2(x) (x << 1)
#define __stdis_arr(is, arr, s, t) \
        do{ \
            for(int __i = s; __i <=t; ++__i) \
                is >> arr[__i]; \
        } while(0)
#define __stdos_arr(os, arr, s, t) \
        do{ \
            for(int __i = s; __i <=t; ++__i) \
                os << arr[__i] << ",\n"[__i == t]; \
        } while(0)

// rid, [l, r]
int __seg_tree::build(int rid, int l, int r)
{
    if(l == r)
        return rg[rid] = ar[l];
    
    int m = __imid(l, r);
    int p = __pow2(rid);

    return rg[rid] = fn(
        rg[p] = build(p, l, m),
        rg[p+1] = build(p+1, m+1, r)
    );
}

// [l, r] from rid, [s, t]
int __seg_tree::query(int l, int r, int rid, int s, int t)
{
    if(l<=s && t<=r)
        return rg[rid];

    int m = __imid(s, t);
    int p = __pow2(rid);
    int v = 0;

    if(l <= m)
        v = fn(v, query(l, r, p, s, m));
    if(r > m)
        v = fn(v, query(l, r, p+1, m+1, t));
    
    return v;
}

// [l, r]
int __seg_tree::Query(int l, int r)
{
    return query(l, r, rid, sof, eof);
}

// [l, r] from rid, [s, t]
int __seg_tree::update(int, int, int, int, int)
{
    return 0;
}

std::ostream& 
    operator << (std::ostream & __os, const __seg_tree & st)
{
    __stdos_arr(__os, st.ar, st.sof, st.eof);
    __stdos_arr(__os, st.rg, st.rid, __pow2(st.szn)-1);
    return __os;
}

std::istream& 
    operator >> (std::istream & __is, __seg_tree & st)
{
    __is >> st.szn;
    st.rid = 1, st.sof = 1, st.eof = st.szn;
    __stdis_arr(__is, st.ar, st.sof, st.eof);
    st.build(st.rid, st.sof, st.eof);
    return __is;
}

void TestSegTree()
{
    __seg_tree st(
        [](int a, int b) -> int {
            return a + b;
        }
    );
    std::cin >> st;
    int q, l, r;
    while(std::cin >> q)
    {
        switch (q)
        {
        case 0:
            std::cout << st;
            break;
        
        case 1:
            std::cin >> l >> r;
            std::cout << st.Query(l, r) << '\n';
            break;
        
        default:
            return;
        }
    }
}

__END_NS__