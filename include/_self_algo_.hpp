#pragma once
#ifndef _SELF_ALGO_HPP
#define _SELF_ALGO_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

__DEF_NS__(Alan::SelfAlgo::Inst)

size_t __edit_distance_(const std::string &, const std::string &);

__END_NS__

__DEF_NS__(Alan::SelfAlgo::Inst::Test)

void TestLC72();

__END_NS__

#endif