#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>

typedef struct _point2d 
{
    typedef unsigned long long _ull;
    _ull x, y;

    _point2d(_ull _x = 0, _ull _y = 0)
        : x(_x), y(_y) { }

    double _dis(const _point2d & _pd) 
        const noexcept{
        return sqrt((x-_pd.x)*(x-_pd.x) + (y-_pd.y)*(y-_pd.y));
    }

    bool operator < (const _point2d & _pd)
        const noexcept{
        return x < _pd.x || (x == _pd.x && y < _pd.y);
    }
}_point2d;


bool _p2dcmpy(const _point2d & _ps, const _point2d & _pd)
{
    return _ps.y < _pd.y;
}


typedef struct _p2d_ans 
{
    _point2d _ps, _pd;
    _point2d::_ull _d2;
    double _d;
    _p2d_ans() : _d(1e20+1) { }

    void _upd(const _point2d & p1, const _point2d & p2)
        noexcept{
        _d = std::min(p1._dis(p2), _d);
    }

}_p2d_and;

void p1257();

void _rec(int l, int r, _point2d *pp, _p2d_ans &ans)
{
    if(r-l <= 3)
    {
    for(int i=l;i<=r;++i)
        for(int j=i+1;j<=r;++j)
            ans._upd(pp[i], pp[j]);
    std::sort(pp+l, pp+r+1, _p2dcmpy);
    return;
    }

    int m = (l+r)>>1;
    _rec(l, m, pp, ans), _rec(m+1, r, pp, ans);
    std::inplace_merge(pp+l, pp+m+1, pp+r+1, _p2dcmpy);
    int mx = pp[m].x;

    // merge A1 | A2 -> B -> C
    _point2d pt[r-l+1]; int ptsz = 0;
    for(int i=l; i <= r; ++i)
        if(abs(mx-pp[i].x) < ans._d)
        {
            for(int j=ptsz-1; j >= 0 && pp[i].y - pt[j].y < ans._d; --j)
                ans._upd(pp[i], pt[j]);
            pt[ptsz++] = pp[i];
        }
    
}

void p1257()
{
    int n;
    std::cin>>n;
    _point2d pp[n];
    _p2d_ans _ans;
    for(int i=0;i<n;i++)
        std::cin>>pp[i].x>>pp[i].y;
    std::sort(pp, pp+n);
    // for(int i=0;i<n;++i)
    // {
    //     for(int j=i+1;j<n;++j)
    //     {
    //     _ans = std::min(pp[i]._dis(pp[j]), _ans);
    //     }
    // }
    _rec(0, n-1, pp, _ans);

    std::cout 
        << std::fixed 
        << std::setprecision(4)
        << _ans._d << '\n';
}

int main()
{
    p1257();
    return 0;
}