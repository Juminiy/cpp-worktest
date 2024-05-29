#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define __midof(l, r) (((r - l) >> 1) + l)
#define __pow2(x) (x << 1)
#define __lid(x) (__pow2(x))
#define __rid(x) (__pow2(x) + 1)
#define __eq(x, y) (!(x ^ y))
#define __neq(x, y) (x ^ y)
#define __maxmum_rg(l, r, s, t) (l <= s && t <= r)
#define __reset(lval) ( lval = 0 )

#define __scan_arr(scanfn, arr, s, t) \
        do { \
            for(size_t i = s; i <= t; ++i) \
                arr[i] = scanfn(); \
        } while(0)

#define __print_arr(printfn, arr, s, t) \
        do { \
            for(size_t i = s; i <= t; ++i) \
                printfn("%lld", arr[i]), \
                putchar(",\n"[i == t]); \
        } while(0)

typedef long long ll;
typedef ll (*bin_fn_t) (ll, ll);

#define __gen_fn_copy static inline

__gen_fn_copy
size_t readszt()
{
    size_t sz = 0;
    char ch = getchar();
    while(!isdigit(ch)) {
        ch = getchar();
    }
    while(isdigit(ch)) {
        sz = (sz << 1) + (sz << 3) + (ch - 48);
        ch = getchar();
    }
    return sz;
}

__gen_fn_copy
ll readll() 
{
    bool s = false; ll x = 0; 
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') s = true;
        ch = getchar();
    }
    while(isdigit(ch)) {
        x = (x << 1) + (x << 3) + (ch - 48);
        ch = getchar();
    }
    return s ? ~x + 1 : x;
}

#define MAXSZ 10005
typedef struct segtree
{
    size_t nof, qof, sof, eof;
    size_t rtid, etid;

    ll arr[MAXSZ] = {0};
    ll rang[__pow2(MAXSZ)] = {0};
    ll tag[__pow2(MAXSZ)] = {0};

    bin_fn_t optfn, efffn;

    // typedef segtree* _st;

    void (*Build)(segtree*);
    ll (*build)(segtree*, size_t, size_t, size_t);
    ll (*Query)(segtree*, size_t, size_t);
    ll (*query)(segtree*, size_t, size_t, size_t, size_t, size_t);
    void (*Update)(segtree*, size_t, size_t, ll);
    void (*update)(segtree*, size_t, size_t, ll, size_t, size_t, size_t);

    // Build_t Bfn; build_t bfn;
    // Query_t Qfn; query_t qfn;
    // Update_t Ufn; update_t ufn;

} segtree;
typedef segtree* _st;

void Build(_st);
ll build(_st, size_t, size_t, size_t);
ll Query(_st, size_t, size_t);
ll query(_st, size_t, size_t, size_t, size_t, size_t);
void Update(_st, size_t, size_t, ll);
void update(_st, size_t, size_t, ll, size_t, size_t, size_t);

void Build(_st st)
{
    build(st, st->rtid, st->sof, st->eof);
}

ll build(_st st, size_t id, size_t l, size_t r)
{
    if(__eq(l, r))
        return st->rang[id] = st->arr[l];
    
    size_t m = __midof(l, r);
    size_t lid = __lid(id), rid = __rid(id);

    return st->rang[id] =
        (st->rang[lid] = build(st, lid, l, m)) +
        (st->rang[rid] = build(st, rid, m+1, r));
}

void Update(_st st, size_t l, size_t r, ll e)
{
    update(st, l, r, e, st->rtid, st->sof, st->eof);
}

void update(_st st, size_t l, size_t r, ll e, size_t id, size_t s, size_t t)
{
    if(__maxmum_rg(l, r, s, t))
    {
        st->rang[id] += (t - s + 1) * e;
        st->tag[id] += e;
        return;
    }

    size_t m = __midof(s, t);
    size_t lid = __lid(id), rid = __rid(id);

    if(st->tag[id] && __neq(s, t))
    {
        st->rang[lid] += (m - s + 1) * st->tag[id];
        st->rang[rid] += (t - m) * st->tag[id];
        st->tag[lid] += st->tag[id];
        st->tag[rid] += st->tag[id];
        __reset(st->tag[id]); 
    }

    if(l <= m)
        update(st, l, r, e, lid, s, m);
    if(r > m)
        update(st, l, r, e, rid, m+1, t);

    st->rang[id] = st->rang[lid] + st->rang[rid];
}

ll Query(_st st, size_t l, size_t r)
{
    return query(st, l, r, st->rtid, st->sof, st->eof);
}

ll query(_st st, size_t l, size_t r, size_t id, size_t s, size_t t)
{
    if(__maxmum_rg(l, r, s, t))
    {
        return st->rang[id];
    }

    size_t m = __midof(s, t);
    size_t lid = __lid(id), rid = __rid(id);
    ll v = 0;

    if(st->tag[id] && __neq(s, t))
    {
        st->rang[lid] += (m - s + 1) * st->tag[id];
        st->rang[rid] += (t - m) * st->tag[id];
        st->tag[lid] += st->tag[id];
        st->tag[rid] += st->tag[id];
        __reset(st->tag[id]); 
    }

    if(l <= m)
        v += query(st, l, r, lid, s, m);
    if(r > m)
        v += query(st, l, r, rid, m+1, t);

    return v;
}

int main()
{
    segtree st = segtree();
    st.nof = readszt();
    st.qof = readszt();
    st.sof = 1;
    st.eof = st.nof;
    st.rtid = 1;
    st.etid = __pow2(st.nof)-1;
    __scan_arr(readll, st.arr, st.sof, st.eof);
    st.Build = Build;
    st.Query = Query;
    st.Update = Update;

    st.Build(&st);

    while(st.qof --)
    {
        size_t queryM = readszt();
        size_t rangeL = readszt();
        size_t rangeR = readszt();
        
        switch (queryM)
        {
        case 0:
            __print_arr(printf, st.arr, st.sof, st.eof);
            __print_arr(printf, st.rang, st.rtid, st.etid);
            break;

        case 1:
            st.Update(&st, rangeL, rangeR, readll());
            break; 

        case 2:
            printf("%lld\n", st.Query(&st, rangeL, rangeR));
            break;

        default:
            break;
        }
    }


    return 0;
}

