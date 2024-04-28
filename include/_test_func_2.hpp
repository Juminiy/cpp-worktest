#pragma once
#ifndef _TEST_FUNC_2_HPP
#define _TEST_FUNC_2_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

__DEF_NS__(Alan::Demos::Test::Func)

typedef void (*TestFuncDeclType) ();

__VAR_GLB__
std::deque<TestFuncDeclType> __test_fn_queue_;

GEN_FUNC_COPY
void __init_test_fn_()
{
    __test_fn_queue_.shrink_to_fit();
}

void TestNoArgs();

void TestVaArgs();

#define PUSH_TASK(__fn_) __test_fn_queue_.push_back(__fn_)
#define RUN_TASKS() \
        while(!__test_fn_queue_.empty()) \
        { \
        __test_fn_queue_.front()(); \
        __test_fn_queue_.pop_front(); \
        }

__END_NS__

__DEF_NS__(Alan::Demos::Test::Func)

void TestPaSort();

__END_NS__

#endif