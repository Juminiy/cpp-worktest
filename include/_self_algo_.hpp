#pragma once
#ifndef _SELF_ALGO_HPP
#define _SELF_ALGO_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

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

#endif