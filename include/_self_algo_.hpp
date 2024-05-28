#pragma once
#ifndef _SELF_ALGO_HPP
#define _SELF_ALGO_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <cstdlib>
#include <iostream>
#include <functional>

__DEF_NS__(Alan::SelfAlgo::Inst)

size_t __edit_distance_(const std::string &, const std::string &);
size_t __edit_distance_optv2(const std::string & , const std::string & );
std::vector<std::string> __get_edits_(const std::string &, const std::string &);

__END_NS__


__DEF_NS__(Alan::SelfAlgo::Inst)

typedef struct _point2d 
{
typedef unsigned long long _ull;
_ull x, y;
_point2d(_ull _x = 0, _ull _y = 0)
    : x(_x), y(_y) { }
double _dis(const _point2d & _pd)
{
return sqrt((x-_pd.x)*(x-_pd.x) + (y-_pd.y)*(y-_pd.y));
}
bool operator < (const _point2d & _pd)
    const noexcept
{
    return x < _pd.x || (x == _pd.x && y < _pd.y);
}
}_point2d;

typedef struct _p2d_and 
{
_point2d _ps, _pd;
_point2d::_ull _d2;
double _d;
}_p2d_and;

void p1257();

__END_NS__


__DEF_NS__(Alan::SelfAlgo::Inst::Test)

void TestLC72();

__END_NS__

__DEF_NS__(Alan::LC)

int evalRPN(std::vector<std::string>& );
void TestLC150();

__END_NS__

__DEF_NS__(Alan::SelfAlgo::Inst::Test)

void TestCOptLess();

void TestIntToken();

void TestMidExpr2RPN();

void TestRPN2MidExpr();

__END_NS__


__DEF_NS__(Alan::SelfAlgo::Inst)

// https://loj.ac/p/2153
class KOfN {
public:
    int n, k;
    int lineOfCnt; // n element, placeholder of 1,2,3,...n
    std::vector<int> lineLoc; // a line/row of placeholder
    std::vector<int> lineCnt;
    std::vector<std::vector<std::vector<int>>> dp; // countOf
    unsigned long long tot;

    KOfN() {
        lineLoc = std::vector<int>(1<<12, 0);
        lineCnt = std::vector<int>(1<<12, 0);
        dp = 
            std::vector<std::vector<std::vector<int>>>(
                12, 
                std::vector<std::vector<int>>(
                    1<<12, 
                    std::vector<int>(12*12, 0)));
    }

    void CalLineOfCnt();
    void CountOf();
    bool canNotPlace(int, int);
    void Run();

    friend std::istream&
        operator>> (std::istream& _is, KOfN & kOfN)
        {
            PRINT("Input N and K: ");
            _is >> kOfN.n >> kOfN.k;
            return _is;
        }

    friend std::ostream& 
        operator<< (std::ostream& _os, const KOfN & kOfN)
        {
            _os << "{ ";
            OUTPUT_DETAIL(_os, kOfN.lineOfCnt);
            OUTPUT(_os, ", Loc = [ ");
            // for(int i = 0; i < kOfN.lineOfCnt; ++i)
            //     OUTPUT(_os, kOfN.lineLoc[i]), 
            //     OUTPUT(_os, ", "[i == kOfN.lineOfCnt-1]);
            OUTPUT(_os, "]");
            _os << " }" << __LN__;
            return _os;
        }
};

void TestKOfN();
void TestXXX();
void TestEightQueens();
void TestExpr();

__END_NS__


__DEF_NS__(Alan::SelfAlgo::Copy)

class node {
public:
    int u{}, d{}, l{}, r{}; //上下左右
    int row{}, col{};   //具体坐标
    int s{};          //col节点数量
    int h{};          //row头节点
    int ans{};        //选了那些row

    node() = default;
};

class DLX {
public:
    int n{}, m{};
    int N{}, M{};
    int num{};
    int res{};
    std::vector<node> nodes;

    explicit DLX(int n) {
        this->N = n;
        this->n = N * N;//n * n列
        this->m = 6 * N;//6 * n行
        this->M = geiMaxSize();
        dance();
    }

    [[nodiscard]] int getRes() const {
        return res;
    }
    
    int geiMaxSize() const {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans += 4;
            }
        }
        return ans + m + 5;
    }

    void dance() {
        init();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int id = i * N + j + 1;
                Link(id, i + 1);//N
                Link(id, j + N + 1);//N
                Link(id, i + j + (2 * N) + 1);//2*N-1
                Link(id, (N - 1 + i - j) + (4 * N - 1) + 1);
            }
        }
        Dance(0);
    }

    void init() {
        nodes.assign(M, {});

        num = m + 1;
        for (int i = 0; i <= m; i++) {
            node &it = nodes[i];
            it.l = i - 1;
            it.r = i + 1;
            it.u = it.d = i;
        }
        nodes[0].l = m;
        nodes[m].r = 0;
    }

    void Link(int r, int c) {
        num++;
        node &row = nodes[r];
        node &col = nodes[c];
        node &nums = nodes[num];

        nums.row = r;
        nums.col = c;
        col.s++;

        // node[col.u] <-> nums <-> col
        nums.u = col.u;
        nodes[col.u].d = num;
        col.u = num;
        nums.d = c;

        if (row.h == 0) {
            row.h = nums.l = nums.r = num;
        } else {
            node &head = nodes[row.h];
            //node[head.l] <-> nums <-> head
            nums.l = head.l;
            nodes[head.l].r = num;
            head.l = num;
            nums.r = row.h;
        }
    }

    void Remove(int c) {
        node &col = nodes[c];
        // node[col.l] <-> node[col.r]
        nodes[col.l].r = col.r;
        nodes[col.r].l = col.l;

        //下右
        for (int i = col.d; i != c; i = nodes[i].d) {
            for (int j = nodes[i].r; j != i; j = nodes[j].r) {
                node &it = nodes[j];
                // node[it.u] <-> node[it.d]
                nodes[it.d].u = it.u;
                nodes[it.u].d = it.d;
                nodes[it.col].s--;
            }
        }
    }

    void Resume(int c) {
        // node[col.l] -> node[c] <- node[col.r]
        node &col = nodes[c];
        nodes[col.r].l = c;
        nodes[col.l].r = c;
        //上左
        for (int i = col.u; i != c; i = nodes[i].u) {
            for (int j = nodes[i].l; j != i; j = nodes[j].l) {
                node &it = nodes[j];
                // node[it.u] -> node[j] <- node[it.d]
                nodes[it.d].u = j;
                nodes[it.u].d = j;
                nodes[it.col].s++;
            }
        }
    }

    int Dance(int dep) { // NOLINT(*-no-recursion)
        if (nodes[0].r > N) {
            res++;
            return 1;
        }
        int c = nodes[0].r;
        for (int i = nodes[0].r; i <= 2 * N; i = nodes[i].r) {
            if (nodes[i].s == 0 || nodes[c].s == 0) {
                return 0;
            }
            if (nodes[i].s < nodes[c].s) {
                c = i;
            }
        }
        Remove(c);
        for (int i = nodes[c].d; i != c; i = nodes[i].d) {
            node &it = nodes[i];
            nodes[dep].ans = it.row;
            for (int j = nodes[i].r; j != i; j = nodes[j].r) {
                Remove(nodes[j].col);
            }
            Dance(dep + 1);
            for (int j = nodes[i].l; j != i; j = nodes[j].l) {
                Resume(nodes[j].col);
            }
        }
        Resume(c);
        return 0;
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        DLX solve(n);
        return solve.getRes();
    }
};

int tnq(int);
void TestDL();

__END_NS__


__DEF_NS__(Alan::SelfAlgo::Inst::DP::Digit)

void TestLC233();
void TestLC2719();

__END_NS__


__DEF_NS__(Alan::SelfAlgo::Inst::PBFS)

void TestPBFS();

__END_NS__


__DEF_NS__(Alan::SelfAlgo::Inst::DFSV)

void TestDFSV();

__END_NS__


__DEF_NS__(Alan::SelfList::Inst)

typedef int (*__bin_fn) (int, int);

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
#define MAXN_OF 100005
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

// template < typename _Tp >
// std::istream& 
//     operator >> (std::istream& __is, __seg_tree<_Tp> & _s) { 
//     // _s.a.push_back(0); // _s.a[0] is unused
//     // Alan::SeqIterInput(_s.a, __is);
//     // _s.szn = _s.a.size()-1;

//     __is >> _s.szn >> _s.szq;
//     _s.rid = 1, _s.start = 1, _s.end = _s.szn;
//     __is_arr(__is, _s.a, _s.start, _s.end);
//     _s.build(_s.rid, _s.start, _s.end);
//     return __is;
// }

// template < typename _Tp >
// std::ostream& 
//     operator << (std::ostream& __os, const __seg_tree<_Tp> & _s) {
//         __os_arr(__os, _s.a, _s.start, _s.end);
//         __os_arr(__os, _s.rg, _s.start, __pow2(_s.szn)-1);
//     return __os;
// }

void TestSegTree();

__END_NS__

#endif