#include <cstdlib>
#include <iostream>
#include <functional>
#include <cstring>
#include <cstdio>

#define GEN_FUNC_COPY static inline

GEN_FUNC_COPY
int __i32_read()
{
    int x = 0, s = 0;
    char ch = getchar();
    while(!::isdigit(ch)) {
        if(ch == '-') s = -1;
        ch = getchar();
    }
    while(::isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }
    return s ? ~x+1 : x;
}


GEN_FUNC_COPY
long long __i64_read()
{   
    using ll = long long;
    ll x = 0ll, s = 0ll;
    char ch = getchar();
    while(!::isdigit(ch)) {
        if(ch == '-') s = -1;
        ch = getchar();
    }
    while(::isdigit(ch)){
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }

    return s ? ~x+1 : x;
}

#define __imid(l, r) (((r-l)>>1) + l)
#define __pow2(x) (x << 1)
#define __maxmum_rg(l, r, s, t) (l <= s && t <= r)
#define __ieq(x, y) ((x ^ y) == 0)
#define __ineq(x, y) ((x ^ y) != 0)

#define __is_arr(is, arr, a, b) \
        do { \
            for(int i=a;i<=b;++i) \
                arr[i] = __i64_read(); \
        } while(0)

#define __os_arr(os, arr, a, b) \
        do { \
            for(int i = a; i <= b; ++i) \
                os << arr[i] << ",\n"[i == b]; \
        } while(0)

template < typename _Tp >
class __seg_tree {
private:
#define MAXN_OF 1000005
    _Tp rg[(MAXN_OF<<1)+1] = {};
    _Tp tg[(MAXN_OF<<1)+1] = {};
    _Tp a[MAXN_OF] = {};
    //  >=0    1    szn   1
    int szn, start, end, rid;    
    //  >=0
    int szq;

    using __bin_fn_t = std::function<_Tp(_Tp, _Tp)>;
    __bin_fn_t bfn; // range build function
    __bin_fn_t efn; // update and modify effect function

public:
    static _Tp sum_fn(_Tp a, _Tp b) { return a + b; }
    static _Tp min_fn(_Tp a, _Tp b) { return std::min(a, b); }
    static _Tp max_fn(_Tp a, _Tp b) { return std::max(a, b); }

    explicit __seg_tree(__bin_fn_t _bfn, __bin_fn_t _efn)
        : bfn(_bfn), efn(_efn) { }

    // id, [l, r]
    _Tp build(int, int, int);

    // [l, r] e
    void Update(int, int, _Tp);

    // [l, r] range modify effect e | in id, [s, t] 
    void update(int, int, _Tp, int, int, int);
    
    // [l, r]
    _Tp Query(int, int);

    // [l, r] query in [s, t] 
    // confirm l<=r && s<=t
    _Tp query(int, int, int, int, int);

    int GetSZQ() {
        return szq;
    }

    friend std::istream& 
        operator >> (std::istream& __is, __seg_tree<_Tp> & _s) {
        __is >> _s.szn >> _s.szq;
        _s.rid = 1, _s.start = 1, _s.end = _s.szn;
        __is_arr(__is, _s.a, _s.start, _s.end);
        _s.build(_s.rid, _s.start, _s.end);
        return __is;
    }
    
    friend std::ostream& 
        operator << (std::ostream& __os, const __seg_tree<_Tp> & _s) {
        __os_arr(__os, _s.a, _s.start, _s.end);
        __os_arr(__os, _s.rg, _s.start, __pow2(_s.szn)-1);
        return __os;
    }

};

// [l, r]
template < typename _Tp >
_Tp __seg_tree<_Tp>::build(int id, int l, int r) {
    if (l == r)
        return rg[id] = a[l];
    
    int m = __imid(l, r);
    int p = __pow2(id);
    return rg[id] = bfn(
        rg[p] = build(p, l, m),
        rg[p+1] = build(p+1, m+1, r)
    );      
}

template < typename _Tp >
void __seg_tree<_Tp>::Update(int l, int r, _Tp e) {
    update(l, r, e, rid, start, end);
}

// [l, r] range add val
template < typename _Tp >
void __seg_tree<_Tp>::update(int l, int r, _Tp e, int id, int s, int t) {
    if(__maxmum_rg(l, r, s, t)) {
        rg[id] += (t - s + 1) * e;
        tg[id] += e;
        return;
    }

    int m = __imid(s, t);
    int p = __pow2(id);
    if(tg[id] && __ineq(s, t)) {
        rg[p] += (m - s + 1) * tg[id], rg[p+1] += (t - m) * tg[id];
        tg[p] += tg[id], tg[p+1] += tg[id];
        tg[id] = 0; // reset
    }

    if(l <= m)
        update(l, r, e, p, s, m);
    if(r > m)
        update(l, r, e, p+1, m+1, t);
    
    rg[id] = bfn(rg[p], rg[p+1]);
} 

template < typename _Tp >
_Tp __seg_tree<_Tp>::Query(int l, int r) {
    return query(l, r, rid, start, end);
}

// [l, r] query in [s, t] 
// confirm l<=r && s<=t
template < typename _Tp >
_Tp __seg_tree<_Tp>::query(int l, int r, int id, int s, int t) {
    if(__maxmum_rg(l, r, s, t))
        return rg[id];
        
    int m = __imid(s, t);
    int p = id<<1;
    if(tg[id]) {
        rg[p] += (m - s + 1) * tg[id], rg[p+1] += (t - m) * tg[id];
        tg[p] += tg[id], tg[p+1] += tg[id];
        tg[id] = 0; // reset
    }

    _Tp v{};
    if(l <= m)
        v = bfn(v, query(l, r, p, s, m));
    if(r > m)
        v = bfn(v, query(l, r, p+1, m+1, t));

    return v;
}

void TestSegTree()
{   
    using ll = long long;
    __seg_tree<ll> st(__seg_tree<ll>::sum_fn, __seg_tree<ll>::sum_fn);
    std::cin >> st;
    // std::cout << st;
    int szq = st.GetSZQ(), q, l, r; 
    while(szq--) 
    { 
        q = __i32_read(), l = __i32_read(), r = __i32_read();  
        switch (q)
        {
        case 1:
            st.Update(l, r, __i64_read());
            break;

        case 2:
            std::cout << st.Query(l, r) << '\n'; 
            break; 
        }
    } 

}

int main()
{
    TestSegTree();
    return 0;
}